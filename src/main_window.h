#ifndef TRTLE_QT_MAIN_WINDOW_HPP
#define TRTLE_QT_MAIN_WINDOW_HPP

#include <cstdint>
#include <QMainWindow>
#include <QString>

class BackgroundViewer;
class GameBoy;
class QTimer;
class TextureRenderWidget;
class TilesetViewer;

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
public:
    MainWindow();
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    BackgroundViewer * backgroundViewer;
    bool skipBootrom;
    GameBoy * gameboy;
    QString previousPath;
    QTimer * updateTimer;
    TextureRenderWidget * const renderWidget;
    TilesetViewer * tilesetViewer;
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

    void disableFullscreen();
    void onActionBackgroundViewer();
    void onActionFullscreen();
    void onActionLoadRom();
    void onActionReset();
    void onActionSkipBootrom(bool toggled);
    void onActionTilesetViewer();
    void onUpdateTimerTimeout();
};

#endif /* !TRTLE_QT_MAIN_WINDOW_HPP */
