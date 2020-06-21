#include "info_sharing.h"
#include "ui_info_sharing.h"

info_sharing::info_sharing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info_sharing)
{
    ui->setupUi(this);
}

info_sharing::~info_sharing()
{
    delete ui;
}
