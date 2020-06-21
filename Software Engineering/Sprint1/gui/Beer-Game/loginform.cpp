#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Login Screen");
}

LoginForm::~LoginForm()
{

    delete ui;
}
