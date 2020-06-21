#include "players_playing.h"
#include "ui_players_playing.h"

Players_playing::Players_playing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Players_playing)
{
    ui->setupUi(this);
}

Players_playing::~Players_playing()
{
    delete ui;
}
