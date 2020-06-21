

#include "Player.h"
#include "Game.h"
#include <iostream>
#include "Order.h"

Player::Player()
{
}

Player::Player(int nId, int nRole, Game *nGame)
{
    pId = nId;
    role = nRole;
    game = nGame;
}

Player::~Player()
{
}

void Player::placeOrder(int numberOfBeers)
{
    //incomingShipment = numberOfBeers;
    //game->addOrder(this->role, numberOfBeers);
    setOrderPlaced(true);
    
}

void Player::placeShipment(int numberOfBeers)
{
    //outgoingShipment = numberOfBeers;
    game->addShipment(this->role, numberOfBeers);
    decreaseInventory(numberOfBeers);

}


int Player::getAvailableShipment(int demand) {

    int availableShipment;
    
    if (demand > getInventory()){
        availableShipment = getInventory();
        return availableShipment;
    }
    else{
        return demand;
    }
}


/** @brief decreaseInventory: Decrement inventory by numberOfBeers.
 *  @param numberOfBeers
 *  @return inventory
 */

int Player::decreaseInventory(int numberOfBeers)
{
    setInventory(getInventory() - numberOfBeers);
    return getInventory();
}

/** @brief increaseInventory: Increment inventory by numberOfBeers
 *
 *  @param numberOfBeers
 *  @return inventory
 */

int Player::increaseInventory(int numberOfBeers)
{
    setInventory(getInventory() + numberOfBeers);
    return getInventory();
}

void Player::receiveShipment(int orderId)
{
    shipmentReceived = true;
}

void Player::receiveOrder(int orderedBeers)
{
    orderReceived = true;
    setIncomingOrder(orderedBeers);
}



int Player::factoryProduce(int numberOfBeers){
    inventory += numberOfBeers;
    return inventory;
}

int Player::getBackorder() const
{
    return backorder;
}

void Player::setBackorder(int numberOfBeers)
{
    backorder = numberOfBeers;
}

double Player::getCost() const
{
    return cost;
}

void Player::setCost(double nCost)
{
    cost = nCost;
}

int Player::getInventory() const
{
    return inventory;
}

void Player::setInventory(int numberOfBeers)
{
    inventory = numberOfBeers;
}

int Player::getPId() const
{
    return pId;
}

void Player::setPId(int nId)
{
    pId = nId;
}

int Player::getRole() const
{
    return role;
}

void Player::setRole(int nRole)
{
    role = nRole;
}

bool Player::getOrderPlaced() const
{
    return orderPlaced;
}

void Player::setOrderPlaced(bool nOrderPlaced)
{
    orderPlaced = nOrderPlaced;
}

int Player::getDemand()
{
    return demand;
}

void Player::setDemand(int nDemand)
{
    demand = nDemand;
}

bool Player::getShipmentPlaced() const
{
    return shipmentPlaced;
}

void Player::setShipmentPlaced(bool nPlaced)
{
    shipmentPlaced = nPlaced;
}

bool Player::getShipmentReceived() const
{
    return shipmentReceived;
}

void Player::setShipmentReceived(bool nReceived)
{
    shipmentReceived = nReceived;
}

bool Player::getOrderReceived() const
{
    return orderReceived;
}

void Player::setOrderReceived(bool nReceived)
{
    orderReceived = nReceived;
}

double Player::getTotalCost() const
{
    return totalCost;
}

void Player::setTotalCost(double nTotalCost)
{
    totalCost = nTotalCost;
}

int Player::getOutgoingShipment() const
{
    return outgoingShipment;
}

void Player::setOutgoingShipment(int nOutgoing)
{
    outgoingShipment = nOutgoing;
}

int Player::getIncomingShipment() const
{
    return incomingShipment;
}

void Player::setIncomingShipment(int nIncoming)
{
    incomingShipment = nIncoming;
}

int Player::getIncomingOrder() const
{
    return incomingOrder;
}

void Player::setIncomingOrder(int nOrder)
{
    incomingOrder = nOrder;
}

Game *Player::getGame() const
{
    return game;
}

void Player::setGame(Game *nGame)
{
    game = nGame;
}
