#include "tileset_viewer.h"

#include <QPainter>

#include "gameboy.h"

TilesetViewer::TilesetViewer(GameBoy * const gameboy) 
    : gameboy(gameboy)
    , tilesetData(new uint8_t[GameBoy::TilesetDataLength]())
    , tilesetTexture(
        new QImage(
            GameBoy::TilesetWidthInPixels,
            GameBoy::TilesetHeightInPixels,
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
        GameBoy::TilesetWidthInPixels * resolutionScaleFactor,
        GameBoy::TilesetHeightInPixels * resolutionScaleFactor
    );
}

TilesetViewer::~TilesetViewer() {
    delete tilesetData;
    delete tilesetTexture;
}

void TilesetViewer::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void TilesetViewer::resizeGL(int width, int height) {
    int widthDiv = width / GameBoy::TilesetWidthInPixels;
    int heightDiv = height / GameBoy::TilesetHeightInPixels;

    resolutionScaleFactor = widthDiv > heightDiv ? heightDiv : widthDiv;
    if (resolutionScaleFactor == 0) resolutionScaleFactor = 1;

    tilesetTextureX = width / 2 - GameBoy::TilesetWidthInPixels * resolutionScaleFactor / 2;
    tilesetTextureY = height / 2 - GameBoy::TilesetHeightInPixels * resolutionScaleFactor / 2;
}

static uint8_t getColor(uint8_t pixelValue) {
    switch (pixelValue) {
        case 0: return 0xF5;
        case 1: return 0xAA;
        case 2: return 0x55;
        case 3: return 0x00;
    }
}

void TilesetViewer::paintGL() {
    uint8_t * tilesetTextureData = tilesetTexture->bits();
    gameboy->getTilesetData(tilesetData, GameBoy::TilesetDataLength);
    for (size_t i = 0; i < GameBoy::TilesetDataLength; i++) tilesetTextureData[i] = getColor(tilesetData[i]);

    QPainter p(this);
    p.drawImage(
        tilesetTextureX,
        tilesetTextureY,
        tilesetTexture->scaled(
            GameBoy::TilesetWidthInPixels * resolutionScaleFactor,
            GameBoy::TilesetHeightInPixels * resolutionScaleFactor
        )
    );

    update();
}
