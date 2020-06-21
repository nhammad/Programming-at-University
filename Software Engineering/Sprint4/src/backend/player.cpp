#include <string>
#include <vector>
#include <iostream>
#include "game.h"
#include "player.h"
#include "order.h"
#include "shipment.h"

#include "../frontend/playerdialog.h"
// #include "ui_playerdialog.h"

Player::Player(Game *game, int role)
{
    this->pId = game->getGId() + role;
    this->game = game;
    this->role = role;
    this->inventory = game->getStartingInventory();
}

void Player::setUi(Ui::PlayerDialog *ui)
{
    this->playerui = ui;
}

// Updates the Ui of the player dialog
void Player::updatePlayerUi()
{
    //Setting the player Id in player dialog
    playerui->player_pId->setNum(pId);
    playerui->player_order->setEnabled(true);
    playerui->incomingOrder->setNum(demand);
    playerui->week->setNum(game->getCurrentWeek());

    totalCost += (double) game->getBackOrderCost() * (double) backOrder + (double) game->getHoldingCost() * (double) inventory ;
    playerui->totalCost->setNum(totalCost);

    // current
    playerui->inventory->setNum(inventory);
    playerui->backLog->setNum(backOrder);

    // set outgoing and incoming  shipments
    increaseInventory(incomingShipment);

    if(role != CONSUMER)
        outgoingShipment = getAvailableShipment(demand);

    playerui->outgoingShipment->setNum(outgoingShipment);
    playerui->incomingShipment->setNum(incomingShipment);

    // display inventory after transactions
    playerui->inventoryAfter->setNum(inventory);
    playerui->backlogAfter->setNum(backOrder);

    if(role == CONSUMER) {
        playerui->player_order->setEnabled(false);
        playerui->order_amount->setText(QString::number(game->getConsumerDemandForWeek()));
          placeOrder(game->getConsumerDemandForWeek());
          // The consumer is shipping 0 to itself
          placeShipment(0);
    }
}

void Player::placeOrder(int numberOfBeers)
{
    //Adding the nnumber of beers to order history
    orderHistory.push_back(numberOfBeers);
    int EventWeek = game->getOrderDelay() + game->getCurrentWeek();
    if(role == FACTORY){
        // We add a shipment if the player is a factory
        EventWeek = game->getFactoryDelay()*2 +game->getCurrentWeek();
        game->addShipment(Shipment (game->getUpstream(role), getUniqueOrderId(), numberOfBeers, EventWeek));
    }else{
        game->addOrder(Order (game->getUpstream(role), getUniqueOrderId(), numberOfBeers, EventWeek));
    }
    orderReceived = false;
}

void Player::placeShipment(int numberOfBeers)
{
    int EventWeek = game->getOrderDelay() + game->getCurrentWeek();
    if(role != CONSUMER){
        game->addShipment(Shipment (game->getDownstream(role), getUniqueOrderId(), numberOfBeers, EventWeek));
    }
    shipmentReceived= false;
}



int Player::getAvailableShipment(int numberOfBeers)
{
    int preceding = inventory;
    int currentlyNeeded = backOrder + numberOfBeers;
    decreaseInventory(currentlyNeeded);
    int outgoing = (preceding - inventory);
    outgoingShipmentHistory.push_back(outgoing);
    return outgoing;
}

void Player::receiveShipment(int numberOfBeers)
{
    incomingShipment = numberOfBeers;
    incomingShipmentHistory.push_back(incomingShipment);
    shipmentReceived = true;
    inventory += numberOfBeers;

    if((orderReceived && shipmentReceived) || role == CONSUMER) {
        updatePlayerUi();
    }
}

void Player::receiveOrder(int numberOfBeers)
{
    demand = numberOfBeers;
    incomingOrder = demand;
    orderReceived = true;

    if(orderReceived && shipmentReceived) {
        updatePlayerUi();
    }
}

void Player::decreaseInventory(int numberOfBeers)
{
    inventory -= numberOfBeers;
    if(inventory <0){
        backOrder = std::abs(inventory);
        inventory = 0;
    }
    //return inventory;
}

void Player::increaseInventory(int numberOfBeers)
{
    inventory += numberOfBeers;
    //return inventory;
}

int Player::getUniqueOrderId()
{
    int uinqueId = (game->getCurrentWeek() + game->getOrderDelay())*10 + (this->role);
    return uinqueId;
}

std::vector<int> Player::getOutgoingShipmentHistory() const
{
    return outgoingShipmentHistory;
}

void Player::setOutgoingShipmentHistory(const std::vector<int> &value)
{
    outgoingShipmentHistory = value;
}

std::vector<int> Player::getIncomingShipmentHistory() const
{
    return incomingShipmentHistory;
}

void Player::setIncomingShipmentHistory(const std::vector<int> &value)
{
    incomingShipmentHistory = value;
}

std::vector<int> Player::getOrderHistory() const
{
    return orderHistory;
}

void Player::setOrderHistory(const std::vector<int> &value)
{
    orderHistory = value;
}


Game *Player::getGame() const
{
    return game;
}

void Player::setGame(Game *value)
{
    game = value;
}

Ui::PlayerDialog *Player::getPlayerui() const
{
    return playerui;
}

void Player::setPlayerui(Ui::PlayerDialog *value)
{
    playerui = value;
}

int Player::getPId() const
{
    return pId;
}

void Player::setPId(int value)
{
    pId = value;
}

int Player::getRole() const
{
    return role;
}

void Player::setRole(int value)
{
    role = value;
}

int Player::getInventory() const
{
    return inventory;
}

void Player::setInventory(int value)
{
    inventory = value;
}

int Player::getBackOrder() const
{
    return backOrder;
}

void Player::setBackOrder(int value)
{
    backOrder = value;
}

int Player::getIncomingOrder() const
{
    return incomingOrder;
}

void Player::setIncomingOrder(int value)
{
    incomingOrder = value;
}

int Player::getIncomingShipment() const
{
    return incomingShipment;
}

void Player::setIncomingShipment(int value)
{
    incomingShipment = value;
}


int Player::getOutgoingShipment() const
{
    return outgoingShipment;
}

void Player::setOutgoingShipment(int value)
{
    outgoingShipment = value;
}

int Player::getDemand() const
{
    return demand;
}

void Player::setDemand(int value)
{
    demand = value;
}

double Player::getCost() const
{
    return cost;
}

void Player::setCost(double value)
{
    cost = value;
}

double Player::getTotalCost() const
{
    return totalCost;
}

void Player::setTotalCost(double value)
{
    totalCost = value;
}

bool Player::isOrderReceived() const
{
    return orderReceived;
}

void Player::setOrderReceived(bool value)
{
    orderReceived = value;
}

bool Player::isShipmentReceived() const
{
    return shipmentReceived;
}

void Player::setShipmentReceived(bool value)
{
    shipmentReceived = value;
}

bool Player::isOrderPlaced() const
{
    return orderPlaced;
}

void Player::setOrderPlaced(bool value)
{
    orderPlaced = value;
}

bool Player::isShipmentPlaced() const
{
    return shipmentPlaced;
}

void Player::setShipmentPlaced(bool value)
{
    shipmentPlaced = value;
}

