#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <QDialog>
#include "create_game.h"

namespace Ui {
class Instructor;
}

class Instructor : public QDialog
{
    Q_OBJECT

public:
    explicit Instructor(QWidget *parent = 0);
    ~Instructor();
    void showGamesStatus();
    int createGame();
    //QVector createGames(int numberOfGames);
    void setInstrEmail(QString instrEmail);
    QString getInstrEmail();
    void setInstrPassword(QString instrPassword);
    QString getInstrPassword();
    void setInstrID(int instrId);
    int getInstrID();

private slots:
    void on_pushButton_SignIn_clicked();

    void on_pushButton_Signup_clicked();

private:
    Ui::Instructor *ui;
    Create_Game * create_game ;
    int instrId;
    QString instrPassword;

};

#endif // INSTRUCTOR_H
