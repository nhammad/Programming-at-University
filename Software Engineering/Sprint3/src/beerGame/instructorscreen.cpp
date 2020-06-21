#include "instructorscreen.h"
#include "ui_instructorscreen.h"
#include <random>
#include <string>

InstructorScreen::InstructorScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InstructorScreen)
{
    ui->setupUi(this);
}

InstructorScreen::~InstructorScreen()
{
    delete ui;
}

std::string random_string(std::string::size_type length)
{
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

void InstructorScreen::on_pushButton_clicked()
{
//    std::vector<std::string> p = Game::generatePasswords();
    ui->fact_pword->setText(QString::fromStdString(random_string(8)));
    ui->dist_pword->setText(QString::fromStdString(random_string(8)));
    ui->whole_pword->setText(QString::fromStdString(random_string(8)));
    ui->retail_pword->setText(QString::fromStdString(random_string(8)));
}
