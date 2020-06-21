#include "playerlogin.h"
#include "ui_playerlogin.h"
#include <QMessageBox>
#include "playerScreen.h"

PlayerLogin::PlayerLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayerLogin)
{
    ui->setupUi(this);
}

PlayerLogin::~PlayerLogin()
{
    delete ui;
}


void PlayerLogin::on_lineEdit_password_2_returnPressed()
{
    QString username = ui->lineEdit_username_2->text();
    QString password = ui->lineEdit_password_2->text();

    if (username == "player" && password == "18")
    {
        QMessageBox::information(this, "Success", "Login successful!");
        hide();
        playerScreen = new tryWindow(this);
        playerScreen->show();
    }
    else
    {
        QMessageBox::warning(this,"Error","Incorrect Login Information");
    }

}

void PlayerLogin::on_pushButton_login_2_clicked()
{
    QString username = ui->lineEdit_username_2->text();
    QString password = ui->lineEdit_password_2->text();

    if (username == "player" && password == "18")
    {
        QMessageBox::information(this, "Success", "Login successful!");
        hide();
        playerScreen = new tryWindow(this);
        playerScreen->show();
    }
    else
    {
        QMessageBox::warning(this,"Error","Incorrect Login Information");
    }

}


