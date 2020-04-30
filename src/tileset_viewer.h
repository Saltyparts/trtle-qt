#ifndef TRTLE_QT_TILESET_MAP_HPP
#define TRTLE_QT_TILESET_MAP_HPP
#include <cstdint>
#include <QOpenGLFunctions>
#include <QOpenGLWindow>

class GameBoy;
class QImage;

class TilesetViewer : public QOpenGLWindow, private QOpenGLFunctions {
public:
    TilesetViewer(GameBoy * const gameboy);
    ~TilesetViewer();

    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

private:
    GameBoy * const gameboy;
    uint8_t * const tilesetData;
    QImage * const tilesetTexture;
    size_t tilesetTextureX;
    size_t tilesetTextureY;
    size_t resolutionScaleFactor;
};

#endif /* !TRTLE_QT_TILESET_MAP_HPP */
