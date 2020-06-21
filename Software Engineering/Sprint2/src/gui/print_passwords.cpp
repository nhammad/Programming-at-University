#include "print_passwords.h"
#include "ui_print_passwords.h"

Print_passwords::Print_passwords(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Print_passwords)
{
    ui->setupUi(this);
}

Print_passwords::~Print_passwords()
{
    delete ui;
}
