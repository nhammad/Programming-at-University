#include "instructorwelcome.h"
#include "ui_instructorwelcome.h"
#include "instructorscreen.h"
//#include "create_game.h"
#include <QMessageBox>

InstructorWelcome::InstructorWelcome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructorWelcome)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}


InstructorWelcome::~InstructorWelcome()
{
    delete ui;
}



void InstructorWelcome::on_gen_pword_clicked()
{

    instructorScreen = new InstructorScreen;
    instructorScreen->show();

}


void InstructorWelcome::on_game_create_clicked()
{
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

void InstructorWelcome::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
