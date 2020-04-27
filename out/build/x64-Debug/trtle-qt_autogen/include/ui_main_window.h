/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTilesetViewer;
    QAction *actionBackgroundViewer;
    QAction *actionLoadFile;
    QAction *actionFullscreen;
    QAction *actionReset;
    QAction *actionOAMViewer;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuDebug;
    QMenu *menuOptions;

    void setupUi(QMainWindow *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(481, 462);
        actionTilesetViewer = new QAction(main_window);
        actionTilesetViewer->setObjectName(QString::fromUtf8("actionTilesetViewer"));
        actionTilesetViewer->setCheckable(true);
        actionTilesetViewer->setEnabled(true);
        actionBackgroundViewer = new QAction(main_window);
        actionBackgroundViewer->setObjectName(QString::fromUtf8("actionBackgroundViewer"));
        actionBackgroundViewer->setCheckable(true);
        actionLoadFile = new QAction(main_window);
        actionLoadFile->setObjectName(QString::fromUtf8("actionLoadFile"));
        actionLoadFile->setShortcutVisibleInContextMenu(true);
        actionFullscreen = new QAction(main_window);
        actionFullscreen->setObjectName(QString::fromUtf8("actionFullscreen"));
        actionReset = new QAction(main_window);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionOAMViewer = new QAction(main_window);
        actionOAMViewer->setObjectName(QString::fromUtf8("actionOAMViewer"));
        centralwidget = new QWidget(main_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(160, 144));
        centralwidget->setSizeIncrement(QSize(480, 432));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setMinimumSize(QSize(160, 144));
        openGLWidget->setSizeIncrement(QSize(160, 144));
        openGLWidget->setBaseSize(QSize(480, 432));

        verticalLayout->addWidget(openGLWidget);

        main_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(main_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 481, 21));
        menubar->setInputMethodHints(Qt::ImhNone);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuDebug = new QMenu(menubar);
        menuDebug->setObjectName(QString::fromUtf8("menuDebug"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        main_window->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuDebug->menuAction());
        menuFile->addAction(actionLoadFile);
        menuFile->addAction(actionReset);
        menuDebug->addAction(actionTilesetViewer);
        menuDebug->addAction(actionBackgroundViewer);
        menuDebug->addAction(actionOAMViewer);
        menuOptions->addAction(actionFullscreen);

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QMainWindow *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("MainWindow", "trtle", nullptr));
        actionTilesetViewer->setText(QCoreApplication::translate("MainWindow", "Tileset Viewer", nullptr));
        actionBackgroundViewer->setText(QCoreApplication::translate("MainWindow", "Background Viewer", nullptr));
        actionLoadFile->setText(QCoreApplication::translate("MainWindow", "Load Rom", nullptr));
#if QT_CONFIG(shortcut)
        actionLoadFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFullscreen->setText(QCoreApplication::translate("MainWindow", "Fullscreen", nullptr));
#if QT_CONFIG(shortcut)
        actionFullscreen->setShortcut(QCoreApplication::translate("MainWindow", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionOAMViewer->setText(QCoreApplication::translate("MainWindow", "OAM Viewer", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&Emulation", nullptr));
        menuDebug->setTitle(QCoreApplication::translate("MainWindow", "&Tools", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
