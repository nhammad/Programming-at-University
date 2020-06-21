#include "instructor.h"
#include "ui_instructor.h"
#include <QMessageBox>


Instructor::Instructor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instructor)
{
    ui->setupUi(this);
}

Instructor::~Instructor()
{
    delete ui;
}

void Instructor::on_pushButton_SignIn_clicked()
{
    QString userName = ui->label_username->text();
    QString password = ui->label_password->text();

    if(userName == "" && password == "")
    {
        QMessageBox::warning(this, "SignIn", "Username or password Incorrect");
    }else{
        hide();
        create_game = new Create_Game(this);
        create_game->show();
    }
}

void Instructor::on_pushButton_Signup_clicked()
{
    QString firstName = ui->label_firstName->text();
    QString lastName = ui->label_lastname->text();
    QString userName = ui->label_username_2->text();
    QString email = ui->label_email->text();
    QString password = ui->label_password_2->text();

    if(userName == "" && password == "" && firstName == "" && lastName == "" && email == "")
    {
        QMessageBox::warning(this, "SignIn", "field empty");
    }

}
