#ifndef TRTLE_QT_EMULATION_DISPLAY_HPP
#define TRTLE_QT_EMULATION_DISPLAY_HPP
#include <cstdint>
#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QTimer>

class GameBoy;
class QImage;
class QKeyEvent;

class EmulationDisplay : public QOpenGLWindow, private QOpenGLFunctions {
public:
    EmulationDisplay(GameBoy* const gameboy);
    ~EmulationDisplay();

    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

protected:
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    GameBoy * const gameboy;
    uint8_t * const displayData;
    QImage * const displayTexture;
    size_t displayTextureX;
    size_t displayTextureY;
    size_t resolutionScaleFactor;

    QTimer * updateTimer;

    bool a = false;
    bool b = false;
    bool start = false;
    bool select = false;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    void updateGameBoy();
};

#endif /* !TRTLE_QT_EMULATION_DISPLAY_HPP */
