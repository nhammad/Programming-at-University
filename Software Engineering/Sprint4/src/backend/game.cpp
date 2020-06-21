#include <map>
#include <vector>
#include <ctime>
#include <QtSql>
#include "game.h"
#include "player.h"
#include<iostream>

Game::Game()
{
}

Game::Game(int instrId)
{
    this->gId = instrId * 10;
    this->instrId = instrId;
}

Game::Game(int instrId, double backlogCost, double holdingCost, int orderDelay, int totalWeeks, int startInventory, int factoryDelay)
{
    this->gId = instrId * 10;
    this->instrId = instrId;
    this->backorderCost = backlogCost;
    this->holdingCost = holdingCost;
    this->orderDelay = orderDelay;
    this->weeksToBePlayed = totalWeeks;
    this->startingInventory = startInventory;
    this->factoryDelay = factoryDelay;
}

void Game::startGame()
{
    //Orders and Shipments for Week 1 and Week 2

    for (int i = 0; i < 2; i++)
    {
        int uniqueId = (i + 1) * 10;

        ordersToBeExecuted[i].push_back(Order(getUpstream(CONSUMER), uniqueId, 4, 1));

        for (int player = 1; player < 5; player++)
        {
            uniqueId = (i + 1) * 10 + player;
            if (player != FACTORY)
            {
                ordersToBeExecuted[i].push_back(Order(getUpstream(player), uniqueId, 4, 1));
                shipmentsToBeExecuted[i].push_back(Shipment(getDownstream(player), uniqueId, 4, 1));
            }
            else
            {
                shipmentsToBeExecuted[i].push_back(Shipment(getUpstream(player), uniqueId, 4, 1));
                shipmentsToBeExecuted[i].push_back(Shipment(getDownstream(player), uniqueId, 4, 1));
            }
        }
    }

    currentWeek++;
    executeWeekTransactions();
}

void Game::executeWeekTransactions()
{
    executeOrdersForCurrentWeek();
    executeShipmentsForCurrentWeek();
}

void Game::executeOrdersForCurrentWeek()
{
    for (Order order : ordersToBeExecuted[currentWeek - 1])
    {
        order.executeEvent();
    }
}

void Game::executeShipmentsForCurrentWeek()
{
    for (Shipment shipment : shipmentsToBeExecuted[currentWeek - 1])
    {
        shipment.executeEvent();
    }
}

int Game::getConsumerDemandForWeek()
{
    return consumerDemandPerWeek[currentWeek - 1];
}

void Game::advanceWeek()
{
    currentWeek++;
    totalOrdersInWeek = 0;
    totalShipmentsInWeek = 0;

    executeWeekTransactions();
    weekAdvanced = true;
    //return currentWeek;
}

void Game::addOrder(Order order)
{
    totalOrdersInWeek++;
    ordersToBeExecuted[order.getOrderedInWeek() - 1].push_back(order);
    if (totalOrdersInWeek == nPlayers - 1 && totalShipmentsInWeek == nPlayers)
    {
        advanceWeek();
    }
};

void Game::addShipment(Shipment shipment)
{
    totalShipmentsInWeek++;
    shipmentsToBeExecuted[shipment.getOrderedInWeek() - 1].push_back(shipment);

    if (totalOrdersInWeek == nPlayers - 1 && totalShipmentsInWeek == nPlayers)
    {
        advanceWeek();
    }
};

void Game::addPlayer(Player *player)
{
    (players).push_back(player);
}

Player *Game::getDownstream(int role)
{
    if (role == CONSUMER)
    {
        return (players)[role];
    }
    else
    {
        return (players)[role - 1];
    }
}

Player *Game::getUpstream(int role)
{
    if (role == FACTORY)
    {
        return (players)[role];
    }
    else
    {
        return (players)[role + 1];
    }
}

std::vector<std::string> Game::generatePasswords()
{
    srand(time(0));
    const char alphanum[] =
    "0123456789"
    "!@#$%^&*"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;
    std::vector<std::string> passwords;
    for (int player =0 ; player < nPlayers; player++ ){
        std::string password;
        for (int i = 0 ; i <15 ; i++){
            password.push_back(alphanum[rand() % stringLength]);
        }
        passwords.push_back(password);
    }
    return passwords;
}

bool Game::gameReadyToStart()
{
    if (pFactId != 0 && pDistributorId != 0 && pWholesalerId != 0 && pRetailerId != 0)
    {
        return true;
    }
    return false;
}

unsigned int Game::getGId() const
{
    return gId;
}

void Game::setGId(unsigned int value)
{
    gId = value;
}

unsigned int Game::getInstrId() const
{
    return instrId;
}

void Game::setInstrId(unsigned int value)
{
    instrId = value;
}

unsigned int Game::getPFactId() const
{
    return pFactId;
}

void Game::setPFactId(unsigned int value)
{
    pFactId = value;
}

unsigned int Game::getPDistributorId() const
{
    return pDistributorId;
}

void Game::setPDistributorId(unsigned int value)
{
    pDistributorId = value;
}

unsigned int Game::getPWholesalerId() const
{
    return pWholesalerId;
}

void Game::setPWholesalerId(unsigned int value)
{
    pWholesalerId = value;
}

unsigned int Game::getPRetailerId() const
{
    return pRetailerId;
}

void Game::setPRetailerId(unsigned int value)
{
    pRetailerId = value;
}

std::map<int, std::vector<Order>> Game::getOrdersToBeExecuted() const
{
    return ordersToBeExecuted;
}

void Game::setOrdersToBeExecuted(const std::map<int, std::vector<Order>> &value)
{
    ordersToBeExecuted = value;
}

std::map<int, std::vector<Shipment>> Game::getShipmentsToBeExecuted() const
{
    return shipmentsToBeExecuted;
}

void Game::setShipmentsToBeExecuted(const std::map<int, std::vector<Shipment>> &value)
{
    shipmentsToBeExecuted = value;
}

std::vector<Player *> Game::getPlayers() const
{
    return players;
}

void Game::setPlayers(const std::vector<Player *> &value)
{
    players = value;
}

std::vector<int> Game::getConsumerDemandPerWeek() const
{
    return consumerDemandPerWeek;
}

void Game::setConsumerDemandPerWeek(const std::vector<int> &value)
{
    consumerDemandPerWeek = value;
}

int Game::getOrderDelay() const
{
    return orderDelay;
}

void Game::setOrderDelay(int value)
{
    orderDelay = value;
}

int Game::getShipmentDelay() const
{
    return shipmentDelay;
}

void Game::setShipmentDelay(int value)
{
    shipmentDelay = value;
}

double Game::getHoldingCost() const
{
    return holdingCost;
}

void Game::setHoldingCost(double value)
{
    holdingCost = value;
}

double Game::getBackOrderCost() const
{
    return backorderCost;
}

void Game::setBackOrderCost(double value)
{
    backorderCost = value;
}

int Game::getStartingInventory() const
{
    return startingInventory;
}

void Game::setStartingInventory(int value)
{
    startingInventory = value;
}

int Game::getWeeksToBePlayed() const
{
    return weeksToBePlayed;
}

void Game::setWeeksToBePlayed(int value)
{
    weeksToBePlayed = value;
}

int Game::getCurrentWeek() const
{
    return currentWeek;
}

void Game::setCurrentWeek(int value)
{
    currentWeek = value;
}

int Game::getInfoCode() const
{
    return infoCode;
}

bool Game::getWeekAdvanced() const
{
    return weekAdvanced;
}

void Game::setInfoCode(int value)
{
    infoCode = value;
}

int Game::getFactoryDelay() const
{
    return factoryDelay;
}

void Game::setFactoryDelay(int value)
{
    factoryDelay = value;
}

int Game::getNOrdersReceived() const
{
    return totalOrdersInWeek;
}

void Game::setNOrdersReceived(int value)
{
    totalOrdersInWeek = value;
}

int Game::getNShipmentsReceived() const
{
    return totalShipmentsInWeek;
}

void Game::setNShipmentsReceived(int value)
{
    totalShipmentsInWeek = value;
}

int Game::getNPlayers() const
{
    return nPlayers;
}

void Game::setNPlayers(int value)
{
    nPlayers = value;
}


void Game::setTotalOrdersInWeek(unsigned int value){
    totalOrdersInWeek = value;
}

void Game::setTotalShipmentsInWeek(unsigned int value){
    totalShipmentsInWeek = value;
}