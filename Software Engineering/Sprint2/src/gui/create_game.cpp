/**
* @file create_game.cpp
*
*/
#include "create_game.h"
#include "ui_create_game.h"
#include <QMessageBox>


Create_Game::Create_Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create_Game)
{
    ui->setupUi(this);
}

Create_Game::~Create_Game()
{
    delete ui;
}

void Create_Game::on_commandLinkButton_clicked()
{
    hide();
    instructors_dashboard = new Instructors_dashboard(this);
    instructors_dashboard->show();

}

/**
* @brief For push button
*/
void Create_Game::on_pushButton_5_clicked()
{
     QString institute_name = ui->lineEdit_Name0fInstitute->text();
     QString game_password = ui->lineEdit_GamePassword->text();

     if(institute_name != "" && game_password != "")
     {
          //QMessageBox::information(this, tr("Create"), tr("%1 Games created").arg(no_of_weeks));
     }

}

void Create_Game::on_spinBox_NoofWeeks_editingFinished()
{

}

