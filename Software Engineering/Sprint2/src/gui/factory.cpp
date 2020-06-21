#include "factory.h"
#include "ui_factory.h"

Factory::Factory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Factory)
{
    ui->setupUi(this);
}

Factory::~Factory()
{
    delete ui;
}

void Factory::produce(int numberOfBeers) {
    // TODO - implement Factory::produce
    throw "Not yet implemented";
}
