/**
* @file instructors_dashboard.cpp
*
*/
#include "instructors_dashboard.h"
#include "ui_instructors_dashboard.h"

#include "game.h"

Instructors_dashboard::Instructors_dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instructors_dashboard)
{
    ui->setupUi(this);
}

/**
* @brief Destructor
*/
Instructors_dashboard::~Instructors_dashboard()
{
    delete ui;
}

/**
* @brief For the push button
*/

void Instructors_dashboard::on_pushButton_clicked()
{

}

void Instructors_dashboard::on_pushButton_2_clicked()
{

}

