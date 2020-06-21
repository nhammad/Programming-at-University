#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "playerlogin.h"
#include "instructorLogin.h"

LoginScreen::LoginScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}



void LoginScreen::on_player_pushButton_clicked()
{
    //bring up a playerLogin screen
    hide();
    playerLogin = new PlayerLogin(this);
    playerLogin->show();

}

void LoginScreen::on_instructor_pushButton_clicked()
{
    hide();
    instructorLogin = new MainWindow(this);
    instructorLogin->show();

}
