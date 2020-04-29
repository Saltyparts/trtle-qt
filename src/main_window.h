#ifndef TRTLE_QT_MAIN_WINDOW_HPP
#define TRTLE_QT_MAIN_WINDOW_HPP

#include <cstdint>
#include <QMainWindow>
#include <QString>

class GameBoy;
class QTimer;
class TextureRenderWidget;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
public:
    MainWindow();
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    GameBoy * gameboy;
    QTimer * updateTimer;
    TextureRenderWidget * const renderWidget;
    Ui::MainWindow * const ui;
    uint8_t * const textureColorCodes;

    bool a = false;
    bool b = false;
    bool start = false;
    bool select = false;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    void findCartridge();
    void boot(QString cartridgeFileName);
    void updateGameBoy();
};

#endif /* !TRTLE_QT_MAIN_WINDOW_HPP */
