#include "roleplayer.h"
#include "ui_roleplayer.h"

rolePlayer::rolePlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rolePlayer)
{
    ui->setupUi(this);
    this->setWindowTitle("Player Role");
}

rolePlayer::~rolePlayer()
{
    delete ui;
}
