#include <iostream>
#include "Player.h"
using namespace std;


/**
* Default Constructor to initialize a Player with default values
* for inventory, backorder, demand, and cost.
*/

Player::Player()
{
    inventory = 12;
    backorder = 0;
    demand = 0;
    cost = 0;
}

/**
* Order beers from another player and add them into own inventory.
* @param numberOfBeers Number of beers that are ordered by the player
* @param from The Player who has to deliver the order
*/

void Player::order(const int numberOfBeers, Player &from)
{
    from.decreaseInventory(numberOfBeers);
    increaseInventory(numberOfBeers);
}

/**
* Ship beers from own inventory to another player's inventory.
* @param numberOfBeers Number of beers that are to be shipped to another player.
* @param to The Player who will receive the shipment
*/

void Player::ship(const int numberOfBeers, Player &to)
{
    to.increaseInventory(numberOfBeers);
    decreaseInventory(numberOfBeers);
}



/**
* Decrease number of beers present in the inventory currently.
* Used in other methods like .order() and .ship().
* @param numOfBeers Number of beers that are to be subtracted from the inventory.
*/

int Player::decreaseInventory(const int numOfBeers)
{
    inventory = inventory - numOfBeers;
    return inventory;
}

/**
* Increase number of beers present in the inventory currently.
* @param numOfBeers Number of beers that are to be added in the inventory.
*/

int Player::increaseInventory(const int numOfBeers)
{
    inventory = inventory + numOfBeers;
    return inventory;
}


/**
* Recieves Shipment of the placed order and adds into the inventory.
* @param orderId Id of the Order Placed for which shipment is to be recieved.
*/

bool Player::recieveShipment(const int orderId)
{
    //instead of using this, we're just using order() and ship() for now.
}

/**
* Set a value for how many beers are present in the inventory.
* @param newInventory Number of beers that are present in the inventory.
*/

void Player::setInventory(const int newInventory)
{
    inventory = newInventory;
}

/**
* Set a value for the cost of each beer unit.
* @param newCost Cost set for each unit.
*/

void Player :: setCost(const float newCost) 
{
    cost = newCost;    
}

/**
* Set an ID value to distinuguish between players .
* @param newPId Id assigned to a player.
*/

void Player::setPId(const int newPId)
{
     PId = newPId;
}

/**
* Set a Role to distinuguish between players. It could be 
* Manufacturer, Distributor, Wholesaler, or Retailer.
* @param newRole Role of the player.
*/

void Player::setRole(const int newRole)
{
     role = newRole;
}

/**
* Set the value for demand i.e how much beer is still needed.
* @param newDemand Number of beer units that are still needed.
*/

void Player::setDemand(const int newDemand)
{
    demand = newDemand;
}

/**
* Set the backorder value, which indicates how much a player is lagging behind.
* @param newBackorder Value of backorder.
*/
void Player::setBackorder(const int newBackorder)
{
     backorder = newBackorder;
}

/**
* Set the quantity of beer units which are to be ordered. 
* @param newOrderPlaced Quantity of beer units to be ordered.
*/
void Player::setOrderPlaced(const int newOrderPlaced)
{
     orderPlaced = newOrderPlaced;
}

/**
* Returns the Player Id.
*/

int Player::getPId()
{
    return PId;
}

/**
* Returns the Player role (eg: Retailer, Manufacturer, Wholesaler or Distributor).
*/

int Player::getRole()
{
    return role;
}

/**
* Returns the value of current backorder of a player.
*/

int Player::getBackorder()
{
    return backorder;
}

/**
* Returns the value of current cost of a player.
*/

float Player::getCost()
{
    return cost;
}

/**
* Returns the amount of beer units currently present in player's inventory.
*/

int Player::getInventory()
{
    return inventory;
}

/**
* Returns the value of beer demand for each player.
*/

int Player::getDemand()
{
    return demand;
}

/**
* Returns the value of beer units ordered by the player.
*/

int Player::getOrderPlaced()
{
    return orderPlaced;
}


