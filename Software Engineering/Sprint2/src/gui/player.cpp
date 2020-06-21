
#include "player.h"
#include "ui_player.h"

player::player(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::player)
{
    ui->setupUi(this);
    QFont f( "Arial", 10, QFont::Bold);
}

player::~player()
{
    delete ui;
}

//void player::order(int numberOfBeers, player from) {
//    // TODO - implement Player::order
//    throw "Not yet implemented";
//}

//void player::ship(int numberOfBeers, player from) {
//    // TODO - implement Player::ship
//    throw "Not yet implemented";
//}

//void player::decreaseInventory(int numberOfBeers) {
//    // TODO - implement Player::decreaseInventory
//    throw "Not yet implemented";
//}

//void player::increaseInventory(int numberOfBeers) {
//    // TODO - implement Player::increaseInventory
//    throw "Not yet implemented";
//}

int player::getBackorder() {
    return this->backorder;
}

int player::getCost() {
    // TODO - implement Player::getCost
    throw "Not yet implemented";
}

int player::getInventory() {
    return this->inventory;
}

void player::setBackorder(int backorder) {
    this->backorder = backorder;
}

//void player::setCost(int cost) {
//    // TODO - implement Player::setCost
//    throw "Not yet implemented";
//}

void player::setInventory(int inventory) {
    this->inventory = inventory;
}

void player::setDemand(int demand) {
    this->demand = demand;
}

int player::getDemand() {
    return this->demand;
}

//void player::setOrder(int order) {
//    //this->order = order;
//}

//int player::getOrder() {
//    //return this->order;
//}

void player::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void player::on_pushButton_SignIn_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}
