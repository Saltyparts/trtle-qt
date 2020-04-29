#include "main_window.h"

#include <QFileDialog>
#include <QKeyEvent>
#include <QTimer>

#include "gameboy.h"
#include "texture_render_widget.h"
#include "ui_main_window.h"

MainWindow::MainWindow() 
    : gameboy(new GameBoy())
    , updateTimer(new QTimer())
    , renderWidget(new TextureRenderWidget(GameBoy::DisplayWidthInPixels, GameBoy::DisplayHeightInPixels, QImage::Format::Format_Grayscale8, this))
    , ui(new Ui::MainWindow())
    , textureColorCodes(new uint8_t[GameBoy::DisplayWidthInPixels * GameBoy::DisplayHeightInPixels]())
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(renderWidget);

    connect(ui->actionLoadFile, &QAction::triggered, this, &MainWindow::findCartridge);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateGameBoy);
}

MainWindow::~MainWindow() {
    delete ui;
    // TODO: confirm that the parent deletes the render widget
    delete gameboy;
    delete updateTimer;
}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    switch (event->key()) {
        case Qt::Key_Up: up = true; break;
        case Qt::Key_Down: down = true; break;
        case Qt::Key_Left: left = true; break;
        case Qt::Key_Right: right = true; break;
        case Qt::Key_X: a = true; break;
        case Qt::Key_Z: b = true; break;
        case Qt::Key_Return: start = true; break;
        case Qt::Key_Backspace: select = true; break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent * event) {
    switch (event->key()) {
        case Qt::Key_Up: up = false; break;
        case Qt::Key_Down: down = false; break;
        case Qt::Key_Left: left = false; break;
        case Qt::Key_Right: right = false; break;
        case Qt::Key_X: a = false; break;
        case Qt::Key_Z: b = false; break;
        case Qt::Key_Return: start = false; break;
        case Qt::Key_Backspace: select = false; break;
    }
}

static uint8_t getColor(uint8_t pixelValue) {
    switch (pixelValue) {
        case 0: return 0xF5;
        case 1: return 0xAA;
        case 2: return 0x55;
        case 3: return 0x00;
    }
}

void MainWindow::findCartridge() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
        "/home",
        tr("GameBoy Rom Files (*.gb *.gbc *.bin)"));
    if (fileName == nullptr) return;
    boot(fileName);
}

void MainWindow::boot(QString cartridgeFileName) {
    gameboy->insertCartridge(cartridgeFileName.toStdString().c_str());
    gameboy->initialize(false);
    updateTimer->start(1000 / 59.64); // TODO: figure out why there's desync
}

void MainWindow::updateGameBoy() {
    gameboy->updateToVBlank(a, b, start, select, up, down, left, right);

    uchar * renderTextureData = renderWidget->getTextureBits();
    gameboy->getDisplayData(textureColorCodes, GameBoy::DisplayDataLength);
    for (size_t i = 0; i < GameBoy::DisplayDataLength; i++) renderTextureData[i] = getColor(textureColorCodes[i]);
}
