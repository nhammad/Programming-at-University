/**
* @file create_game.h
*
*/
#ifndef CREATE_GAME_H
#define CREATE_GAME_H

#include <QDialog>
#include "instructors_dashboard.h"

/**
* @class Create_Game
* @brief Screen where Instructor creates games
*/
namespace Ui {
class Create_Game;
}

class Create_Game : public QDialog
{
    Q_OBJECT

public:
    explicit Create_Game(QWidget *parent = 0);
    ~Create_Game();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_5_clicked();

    void on_spinBox_NoofWeeks_editingFinished();

private:
    Ui::Create_Game *ui;
    Instructors_dashboard * instructors_dashboard;
};

#endif // CREATE_GAME_H
