#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::executeOrdersForCurrentWeek() {
    // TODO - implement Game::executeOrdersForCurrentWeek
    throw "Not yet implemented";
}

void Game::updatePlayerInventories() {
    // TODO - implement Game::updatePlayerInventories
    throw "Not yet implemented";
}

void Game::advanceWeek() {
    // TODO - implement Game::advanceWeek
    throw "Not yet implemented";
}

void Game::addOrder(Orders order) {
    // TODO - implement Game::addOrder
    throw "Not yet implemented";
}

void Game::setWeeksToBePlayed(int w) {
    this->weeksToBePlayed = w;
}

void Game::setInfoCode(int code) {
    this->infoCode = code;
}

void Game::setStartingInventory(int si) {
    this->startingInventory = si;
}

void Game::setBackorderCost(double cost) {
    this->backorderCost = cost;
}

void Game::setHoldingCost(double hc) {
    this->holdingCost = hc;
}

QVector<QString> Game::generatePasswords() {
    // TODO - implement Game::generatePasswords
    throw "Not yet implemented";
}

int Game::getCurrentWeek() {
    return this->currentWeek;
}

void Game::setCurrentWeek(int week) {
    this->currentWeek = week;
}

int Game::getWeeksToBePlayed() {
    return this->weeksToBePlayed;
}

int Game::getInfoCode() {
    return this->infoCode;
}

int Game::getStartingInventory() {
    return this->startingInventory;
}

double Game::getBackorderCost() {
    return this->backorderCost;
}

double Game::getHoldingCost() {
    return this->holdingCost;
}

QVector<int> Game::getOrdersToBeExecuted() {
    return this->ordersToBeExecuted;
}
