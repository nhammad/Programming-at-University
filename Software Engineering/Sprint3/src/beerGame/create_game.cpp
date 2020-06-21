#include "create_game.h"
#include "ui_create_game.h"
#include <QMessageBox>
#include <QIntValidator>

create_game::create_game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::create_game)
{
    ui->setupUi(this);
}

create_game::~create_game()
{
    delete ui;
}

void create_game::on_pushButton_clicked()
{
    //    QRegExpValidator* rxv = new QRegExpValidator(QRegExp("\\d*"), this);
    //    ui->lineEdit_gamenum->setValidator(rxv);
    //    int gamenumx = ui->lineEdit_gamenum->text().toInt();

        int gamenum = ui->spinBox->value();
        //QString gamenumstr = QString::number(gamenum);
        if(gamenum > 0)
        {
            QMessageBox::information(this, "Login", QString::number(gamenum) + " Game(s) created with default settings!");
            hide();
        }
        else
        {
            QMessageBox::warning(this, "Login", "Invalid Number! Enter a number between 1-99");
        }
}
