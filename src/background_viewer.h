#ifndef TRTLE_QT_BACKGROUND_MAP_HPP
#define TRTLE_QT_BACKGROUND_MAP_HPP
#include <cstdint>
#include <QOpenGLFunctions>
#include <QOpenGLWindow>

class GameBoy;
class QImage;

class BackgroundMap : public QOpenGLWindow, private QOpenGLFunctions {
public:
    BackgroundMap(GameBoy * const gameboy);
    ~BackgroundMap();

    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

private:
    GameBoy * const gameboy;
    uint8_t * const backgroundData;
    QImage * const backgroundTexture;
    size_t backgroundTextureX;
    size_t backgroundTextureY;
    size_t resolutionScaleFactor;
};

#endif /* !TRTLE_QT_BACKGROUND_MAP_HPP */
