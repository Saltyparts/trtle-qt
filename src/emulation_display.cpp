#include "emulation_display.h"

#include <QKeyEvent>
#include <QPainter>

#include "gameboy.h"

namespace trtle {
    extern "C" {
#include <trtle/trtle.h>
    }
}

EmulationDisplay::EmulationDisplay(GameBoy* const gameboy)
    : gameboy(gameboy)
    , displayData(new uint8_t[GameBoy::DisplayDataLength])
    , displayTexture(
        new QImage(
            GameBoy::DisplayWidthInPixels,
            GameBoy::DisplayHeightInPixels,
            QImage::Format::Format_Grayscale8
        )
    ) {



    resolutionScaleFactor = 3;
    resize(
        GameBoy::DisplayWidthInPixels * resolutionScaleFactor,
        GameBoy::DisplayHeightInPixels * resolutionScaleFactor
    );
    displayTextureX = GameBoy::DisplayWidthInPixels * resolutionScaleFactor / 2 -
        GameBoy::DisplayWidthInPixels * resolutionScaleFactor / 2;
    displayTextureY = GameBoy::DisplayHeightInPixels * resolutionScaleFactor / 2 -
        GameBoy::DisplayHeightInPixels * resolutionScaleFactor / 2;

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &EmulationDisplay::updateGameBoy);
    updateTimer->start(1000 / 59.64); // TODO: figure out why there's desync
}

EmulationDisplay::~EmulationDisplay() {
    delete displayData;
    delete displayTexture;
    delete updateTimer;
}

void EmulationDisplay::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void EmulationDisplay::resizeGL(int width, int height) {
    int widthDiv = width / GameBoy::DisplayWidthInPixels;
    int heightDiv = height / GameBoy::DisplayHeightInPixels;

    resolutionScaleFactor = widthDiv > heightDiv ? heightDiv : widthDiv;
    if (resolutionScaleFactor == 0) resolutionScaleFactor = 1;

    displayTextureX = width / 2 - GameBoy::DisplayWidthInPixels * resolutionScaleFactor / 2;
    displayTextureY = height / 2 - GameBoy::DisplayHeightInPixels * resolutionScaleFactor / 2;
}

static uint8_t getColor(uint8_t pixelValue) {
    switch (pixelValue) {
        case 0: return 0xF8;
        case 1: return 0xAA;
        case 2: return 0x55;
        case 3: return 0x00;
        case 4: return 0xFF;
    }
}

void EmulationDisplay::paintGL() {
    QPainter p(this);
    p.drawImage(
        displayTextureX,
        displayTextureY,
        displayTexture->scaled(
            GameBoy::DisplayWidthInPixels * resolutionScaleFactor,
            GameBoy::DisplayHeightInPixels * resolutionScaleFactor
        )
    );

    update();
}

enum InputBits {
    RightOrA    = 0b00000001,
    LeftOrB     = 0b00000010,
    UpOrSelect  = 0b00000100,
    DownOrStart = 0b00001000,
    Directions  = 0b00010000,
    Buttons     = 0b00100000
};

void EmulationDisplay::keyPressEvent(QKeyEvent * event) {
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

void EmulationDisplay::keyReleaseEvent(QKeyEvent * event) {
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

void EmulationDisplay::updateGameBoy() {
    gameboy->updateToVBlank(a, b, start, select, up, down, left, right);

    uint8_t* displayTextureData = displayTexture->bits();
    gameboy->getDisplayData(displayData, GameBoy::DisplayDataLength);
    for (size_t i = 0; i < GameBoy::DisplayDataLength; i++) displayTextureData[i] = getColor(displayData[i]);
}
