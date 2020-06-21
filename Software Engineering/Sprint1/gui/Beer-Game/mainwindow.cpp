#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Beer Game");

    //add picture
    QPixmap logoPic("../Beer-Game/images/logo2.png");
    ui->logo->setPixmap(logoPic);

    //resize screen size
    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
