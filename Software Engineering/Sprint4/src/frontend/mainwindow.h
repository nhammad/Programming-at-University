/** 
 *  @file   mainwindow.h
 *  @brief  This is the main window of the game that pops up initially.
 ***************************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

#include "instructordialog.h"
#include "playerdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/// @brief Class for setting the main window/login window of Beer Game

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief Construct a main window.
    /// @param parent  The parent ui for the class
    MainWindow(QWidget *parent = nullptr);
    
    /// Default destructor 
    ~MainWindow();

private slots:
    /// @brief Login button for player/instructor login to their interface
    void on_pushButton_Login_clicked();
    /// @brief Quick demo button for quick feature guide
    void on_youtube_btn_clicked();

    void on_pushButton_clicked();

private:
    /// @brief The ui of the main window
    Ui::MainWindow *ui;
    /// @brief The pointer to the instructor dialog
    InstructorDialog *secDialog;
    /// @brief The pointer to the player dialog
    PlayerDialog *myplayer;
    /// @brief The pointer to a web engine
    QWebEngineView *m_view;
};
#endif // MAINWINDOW_H
