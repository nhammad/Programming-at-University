#include "playerScreen.h"
#include "ui_playerScreen.h"
#include <QMessageBox>

tryWindow::tryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tryWindow)
{
    ui->setupUi(this);
    ui->stackedWidget_2->setCurrentIndex(0);
}

tryWindow::~tryWindow()
{
    delete ui;
}



void tryWindow::on_pl_login_clicked()
{
    QString Game_no = ui->lineEdit_Gno->text();
    int role = 0;
    if(ui->factory_but->isChecked()){role = 1;}
    else if(ui->dist_but->isChecked()){role = 2;}
    else if(ui->wholes_but->isChecked()){role = 3;}
    else if(ui->retailer_but->isChecked()){role = 4;}


    if(Game_no == "1" && role==1)
    {
        ui->stackedWidget_2->setCurrentIndex(1);
        QMessageBox::information(this, "Login", "Factory");
    }
    else if(Game_no == "1" && role==2)
    {
        ui->stackedWidget_2->setCurrentIndex(2);
         QMessageBox::information(this, "Login", "Distributor");
    }
    else if(Game_no == "1" && role==3)
    {
        ui->stackedWidget_2->setCurrentIndex(3);
         QMessageBox::information(this, "Login", "Wholesaler");
    }
    else if(Game_no == "1" && role==4)
    {
        ui->stackedWidget_2->setCurrentIndex(4);
         QMessageBox::information(this, "Login", "Retailer");
    }
    else
    {
        QMessageBox::warning(this, "Login", "Incorrect Information, enter the game number assigned to you");
    }
}


int init_order_f = 72;
int init_total_f = 100;
int init_order_d = 0;
int init_total_d = 4;
int init_order_w = 0;
int init_total_w = 4;
int init_order_r = 5;
int init_total_r = 10;

void tryWindow::on_orderButton_clicked()
{

//    QString textnum = ui->label_273->text();
//    conv = textnum.toInt();
    int ordernum = ui->spinBox->value();
    if(ordernum > 0)
    {
        QMessageBox::information(this, "Login", QString::number(ordernum) + " Order(s) placed");
        QString newval = QString::number(init_order_f+ordernum);
        QString newtotal = QString::number(init_total_f+ordernum);
        ui->label_273->setText(newval);
        ui->label_275->setText(newtotal);
        init_order_f = init_order_f+ordernum;
        init_total_f = init_total_f+ordernum;

    }
    else
    {
        QMessageBox::warning(this, "Login", "Invalid Number! Enter a number greater than 0");
    }
}

void tryWindow::on_orderButton_3_clicked()
{
    int ordernum = ui->spinBox_2->value();
    if(ordernum > 0)
    {
        QMessageBox::information(this, "Login", QString::number(ordernum) + " Order(s) placed");
        QString newval = QString::number(init_order_d+ordernum);
        QString newtotal = QString::number(init_total_d+ordernum);
        ui->label_383->setText(newval);
        ui->label_385->setText(newtotal);
        init_order_d = init_order_d+ordernum;
        init_total_d = init_total_d+ordernum;

    }
    else
    {
        QMessageBox::warning(this, "Login", "Invalid Number! Enter a number greater than 0");
    }
}

void tryWindow::on_orderButton_4_clicked()
{
    int ordernum = ui->spinBox_3->value();
    if(ordernum > 0)
    {
        QMessageBox::information(this, "Login", QString::number(ordernum) + " Order(s) placed");
        QString newval = QString::number(init_order_w+ordernum);
        QString newtotal = QString::number(init_total_w+ordernum);
        ui->label_467->setText(newval);
        ui->label_469->setText(newtotal);
        init_order_w = init_order_w+ordernum;
        init_total_w = init_total_w+ordernum;

    }
    else
    {
        QMessageBox::warning(this, "Login", "Invalid Number! Enter a number greater than 0");
    }
}

void tryWindow::on_orderButton_5_clicked()
{
    int ordernum_r = ui->spinBox_4->value();
    if(ordernum_r > 0)
    {
        QMessageBox::information(this, "Login", QString::number(ordernum_r) + " Order(s) placed");
        QString newval_r = QString::number(init_order_r+ordernum_r);
        QString newtotal_r = QString::number(init_total_r+ordernum_r);
        ui->label_565->setText(newval_r);
        ui->label_557->setText(newtotal_r);
        init_order_r = init_order_r+ordernum_r;
        init_total_r = init_total_r+ordernum_r;

    }
    else
    {
        QMessageBox::warning(this, "Login", "Invalid Number! Enter a number greater than 0");
    }
}
