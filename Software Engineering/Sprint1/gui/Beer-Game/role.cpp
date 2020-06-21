#include "role.h"
#include "ui_role.h"

Role::Role(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Role)
{
    ui->setupUi(this);
    this->setWindowTitle("Role");
    QPixmap instructorPic("../Beer-Game/images/instructor.png");
    ui->instructor->setPixmap(instructorPic);
    QPixmap playerPic("../Beer-Game/images/player2.png");
    ui->player->setPixmap(playerPic);
}

Role::~Role()
{
    delete ui;
}
