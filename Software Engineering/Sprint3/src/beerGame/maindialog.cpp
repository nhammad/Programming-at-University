#include "maindialog.h"
#include "ui_maindialog.h"
//#include "playerscreen.h"
#include "playerScreen.h"
#include "instructorwelcome.h"

MainDialog::MainDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}



void MainDialog::on_demoScreen_pushButton_clicked()
{
    hide();
    playerScreen = new tryWindow(this);
    playerScreen->show();
}


void MainDialog::on_demoScreen_pushButton_2_clicked()
{
    hide();
    instructorScreen = new InstructorWelcome(this);
    instructorScreen->show();
}
