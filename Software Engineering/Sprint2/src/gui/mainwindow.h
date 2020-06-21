/**
* @file mainwindow.h
*
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "instructor.h"
#include "player.h"

/**
* @class MainWindow
* @brief Creates the Main Window.
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Instructor * instructor;
    player * Player;
};

#endif // MAINWINDOW_H
