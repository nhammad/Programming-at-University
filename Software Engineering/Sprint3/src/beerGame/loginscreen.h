#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>
#include "playerlogin.h"
#include "instructorLogin.h"


namespace Ui {
class LoginScreen;
}

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:

    void on_player_pushButton_clicked();

    void on_instructor_pushButton_clicked();

private:
    Ui::LoginScreen *ui;
    PlayerLogin* playerLogin;
    MainWindow*  instructorLogin;
};

#endif // LOGINSCREEN_H
