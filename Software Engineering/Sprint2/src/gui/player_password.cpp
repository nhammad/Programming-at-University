#include "player_password.h"
#include "ui_player_password.h"

Player_password::Player_password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Player_password)
{
    ui->setupUi(this);
}

Player_password::~Player_password()
{
    delete ui;
}
