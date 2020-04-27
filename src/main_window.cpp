#include "main_window.h"

#include "gameboy.h"


MainWindow::MainWindow() : ui(new Ui::MainWindow()), gameboy(new GameBoy()) {
    QSurfaceFormat format;
    format.setDepthBufferSize(0);
    format.setStencilBufferSize(0);
    format.setSwapInterval(0);
    ui->openGLWidget->setFormat(format);
}

MainWindow::~MainWindow() {
    delete ui;
    delete gameboy;
}

void MainWindow::setupUI() {
    ui->setupUi(this);
}
