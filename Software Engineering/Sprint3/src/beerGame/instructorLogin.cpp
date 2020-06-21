#include "instructorLogin.h"
#include "ui_instructorLogin.h"
#include <QMessageBox>
#include "instructorwelcome.h"
//#include "../src/game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "Ins" && password == "18")
    {
        QMessageBox::information(this, "Success", "Login successful!");
        hide();
        instructorWelcome = new InstructorWelcome(this);
        instructorWelcome->show();
    }
    else
    {
        QMessageBox::warning(this,"Error","Incorrect Login Information");
    }
}

void MainWindow::on_lineEdit_password_returnPressed()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "Ins" && password == "18"){
        QMessageBox::information(this, "Success", "Login successful!");
        hide();
        instructorWelcome = new InstructorWelcome(this);
        instructorWelcome->show();

    }else {
        QMessageBox::warning(this,"Error", "Incorrect Login Information");
    }
}

