#include "background_viewer.h"

#include <QPainter>

#include "gameboy.h"

BackgroundMap::BackgroundMap(GameBoy * const gameboy)
    : gameboy(gameboy)
    , backgroundData(new uint8_t[GameBoy::BackgroundDataLength]())
    , backgroundTexture(
        new QImage(
            GameBoy::BackgroundWidthInPixels,
            GameBoy::BackgroundHeightInPixels,
            QImage::Format::Format_Grayscale8
        )
    ) {

    QSurfaceFormat format;
    format.setDepthBufferSize(0);
    format.setStencilBufferSize(0);
    format.setSwapInterval(0);
    setFormat(format);

    resolutionScaleFactor = 1;
    resize(
        GameBoy::BackgroundWidthInPixels * resolutionScaleFactor,
        GameBoy::BackgroundHeightInPixels * resolutionScaleFactor
    );
    backgroundTextureX = GameBoy::BackgroundWidthInPixels * resolutionScaleFactor / 2 -
        GameBoy::BackgroundWidthInPixels * resolutionScaleFactor / 2;
    backgroundTextureY = GameBoy::BackgroundHeightInPixels * resolutionScaleFactor / 2 -
        GameBoy::BackgroundHeightInPixels * resolutionScaleFactor / 2;
}

BackgroundMap::~BackgroundMap() {
    delete backgroundData;
    delete backgroundTexture;
}

void BackgroundMap::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void BackgroundMap::resizeGL(int width, int height) {
    int widthDiv = width / GameBoy::BackgroundWidthInPixels;
    int heightDiv = height / GameBoy::BackgroundHeightInPixels;

    resolutionScaleFactor = widthDiv > heightDiv ? heightDiv : widthDiv;
    if (resolutionScaleFactor == 0) resolutionScaleFactor = 1;

    backgroundTextureX = width / 2 - GameBoy::BackgroundWidthInPixels * resolutionScaleFactor / 2;
    backgroundTextureY = height / 2 - GameBoy::BackgroundHeightInPixels * resolutionScaleFactor / 2;
}

static uint8_t getColor(uint8_t pixelValue) {
    switch (pixelValue) {
        case 0: return 0xF5;
        case 1: return 0xAA;
        case 2: return 0x55;
        case 3: return 0x00;
    }
}

void BackgroundMap::paintGL() {
    uint8_t * backgroundTextureData = backgroundTexture->bits();
    gameboy->getBackgroundData(backgroundData, GameBoy::BackgroundDataLength);
    for (size_t i = 0; i < GameBoy::BackgroundDataLength; i++) backgroundTextureData[i] = getColor(backgroundData[i]);

    QPainter p(this);
    p.drawImage(
        backgroundTextureX,
        backgroundTextureY,
        backgroundTexture->scaled(
            GameBoy::BackgroundWidthInPixels * resolutionScaleFactor,
            GameBoy::BackgroundHeightInPixels * resolutionScaleFactor
        )
    );

    update();
}
