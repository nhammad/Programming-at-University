#include "instructordialog.h"
#include "ui_instructordialog.h"

#include "../backend/game.h"
#include "../backend/player.h"
#include "playerdialog.h"
#include "../backend/instructor.h"

#include <QDoubleValidator>
#include <QIntValidator>
#include <QPixmap>

InstructorDialog::InstructorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InstructorDialog)
{
    this->parent = parent;
    ui->setupUi(this);

    // Setting the Instructor Image
    QPixmap user(":/resources/images/user.png");
    ui->label_user->setPixmap(user.scaled(190,170, Qt::KeepAspectRatio));

    // Disable the start server btn
    ui->startServer->setEnabled(false);

    // Creating a Instructor
    Instructor* instructor = new Instructor();
    this->instructor = instructor;

    this->instructor->setUi(this->ui);
    this->instructor->setParent(parent);

    //Setting the Instruction Details
    this->instructor->setInstrId(1);
    this->instructor->setInstrEmail("instructor@beergame.de");
    this->instructor->setInstrPassword("jacobs");

    //Set Up UI for the instructor
    ui->instructor_backlogCost->setValidator(new QDoubleValidator(0, 100, 2, this));
    ui->instructor_holdingCost->setValidator(new QDoubleValidator(0, 100, 2, this));
    ui->instructor_orderDelay->setValidator(new QIntValidator(1,100,this));
    ui->instructor_totalWeeks->setValidator(new QIntValidator(1,80,this));
    ui->instructor_startInventory->setValidator(new QIntValidator(1,1000,this));
    ui->instructor_factoryDelay->setValidator(new QIntValidator(1,100,this));
    updateInstructorUI();
}

InstructorDialog::~InstructorDialog()
{
    delete ui;
}

void InstructorDialog::updateInstructorUI()
{
    ui->instructor_id->setNum(this->instructor->getInstrId());
}


void InstructorDialog::on_createGame_clicked()
{
    this->instructor->createGame();
    this->hide();
}

void InstructorDialog::on_ins_exitbtn_clicked()
{
    this->close();
}
