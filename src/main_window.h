#ifndef TRTLE_QT_MAIN_WINDOW_HPP
#define TRTLE_QT_MAIN_WINDOW_HPP

#include <QMainWindow>
#include <QTimer>

#include "background_viewer.h"
#include "ui_main_window.h"
#include "tileset_viewer.h"

class GameBoy;
class Ui::MainWindow;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

    void setupUI();

private:
    Ui::MainWindow * ui;
    GameBoy * gameboy;
};

#endif /* !TRTLE_QT_MAIN_WINDOW_HPP */
