#include "main_window.h"

#include <QFileDialog>
#include <QKeyEvent>
#include <QTimer>

#include "background_viewer.h"
#include "gameboy.h"
#include "texture_render_widget.h"
#include "tileset_viewer.h"
#include "ui_main_window.h"

MainWindow::MainWindow()
    : backgroundViewer(nullptr)
    , skipBootrom(false)
    , gameboy(new GameBoy())
    , renderWidget(new TextureRenderWidget(GameBoy::DisplayWidthInPixels, GameBoy::DisplayHeightInPixels, QImage::Format::Format_Grayscale8, this))
    , textureColorCodes(new uint8_t[GameBoy::DisplayWidthInPixels * GameBoy::DisplayHeightInPixels]())
    , tilesetViewer(nullptr)
    , ui(new Ui::MainWindow())
    , updateTimer(new QTimer())
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(renderWidget);

    connect(ui->actionBackgroundViewer, &QAction::triggered, this, &MainWindow::onActionBackgroundViewer);
    connect(ui->actionFullscreen, &QAction::triggered, this, &MainWindow::onActionFullscreen);
    connect(ui->actionLoadFile, &QAction::triggered, this, &MainWindow::onActionLoadRom);
    connect(ui->actionReset, &QAction::triggered, this, &MainWindow::onActionReset);
    connect(ui->actionSkipBootrom, &QAction::toggled, this, &MainWindow::onActionSkipBootrom);
    connect(ui->actionTilesetViewer, &QAction::triggered, this, &MainWindow::onActionTilesetViewer);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::onUpdateTimerTimeout);
}

MainWindow::~MainWindow() {
    delete backgroundViewer;
    // TODO: confirm that the parent deletes the render widget
    delete gameboy;
    delete ui;
    delete updateTimer;
}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    switch (event->key()) {
        case Qt::Key_F11: {
            if (!ui->menubar->isVisible()) {
                disableFullscreen();
            }
        } break;
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

void MainWindow::disableFullscreen() {
    ui->menubar->setVisible(true);
    showNormal();
}

void MainWindow::onActionBackgroundViewer() {
    if (backgroundViewer == nullptr) {
        backgroundViewer = new BackgroundViewer(gameboy);
        backgroundViewer->show();
    }
    else {
        delete backgroundViewer;
        backgroundViewer = nullptr;
    }
}

void MainWindow::onActionFullscreen() {
    ui->menubar->setVisible(false);
    showFullScreen();
}

void MainWindow::onActionLoadRom() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
        "/home",
        tr("GameBoy ROM File (*.gb *.gbc *.bin)"));
    if (fileName == nullptr) return;

    gameboy->insertCartridge(fileName.toStdString().c_str());
    gameboy->initialize(skipBootrom);
    updateTimer->start(1000 / 59.64); // TODO: figure out why there's desync
}

void MainWindow::onActionReset() {
    if (!gameboy->cartridgeInserted()) return;
    gameboy->initialize(skipBootrom);
    updateTimer->start(1000 / 59.64); // TODO: figure out why there's desync
}

void MainWindow::onActionSkipBootrom(bool toggled) {
    skipBootrom = toggled;
}

void MainWindow::onActionTilesetViewer() {
    if (tilesetViewer == nullptr) {
        tilesetViewer = new TilesetViewer(gameboy);
        tilesetViewer->show();
    }
    else {
        delete tilesetViewer;
        tilesetViewer = nullptr;
    }
}

void MainWindow::onUpdateTimerTimeout() {
    gameboy->updateToVBlank(a, b, start, select, up, down, left, right);

    uchar * renderTextureData = renderWidget->getTextureBits();
    gameboy->getDisplayData(textureColorCodes, GameBoy::DisplayDataLength);
    for (size_t i = 0; i < GameBoy::DisplayDataLength; i++) renderTextureData[i] = getColor(textureColorCodes[i]);
}
