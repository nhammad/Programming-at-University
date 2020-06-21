/**
* @file mainwindow.cpp
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/new.jpg");
    //QPixmap pix("../gui/img/new.jpg");
    ui->label_pic->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    instructor = new Instructor(this);
    instructor->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Player = new player(this);
    Player->show();
}
