#ifndef PLAYERLOGIN_H
#define PLAYERLOGIN_H

#include <QMainWindow>
#include "playerScreen.h"

namespace Ui {
class PlayerLogin;
}

class PlayerLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayerLogin(QWidget *parent = nullptr);
    ~PlayerLogin();

private slots:
    void on_lineEdit_password_2_returnPressed();

    void on_pushButton_login_2_clicked();

private:
    Ui::PlayerLogin *ui;
    tryWindow *playerScreen;
};

#endif // PLAYERLOGIN_H
