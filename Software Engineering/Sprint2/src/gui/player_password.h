#ifndef PLAYER_PASSWORD_H
#define PLAYER_PASSWORD_H

#include <QDialog>

namespace Ui {
class Player_password;
}

class Player_password : public QDialog
{
    Q_OBJECT

public:
    explicit Player_password(QWidget *parent = 0);
    ~Player_password();

private:
    Ui::Player_password *ui;
};

#endif // PLAYER_PASSWORD_H
