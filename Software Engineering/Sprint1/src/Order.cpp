#include <iostream>
#include "Order.h"
using namespace std;

/**
* Sends beer units from one player to another.
*/
void Order::executeOrder()
{
    //For future sprints:
    //Player1.order() & Player2.ship()
}


/**
* Set the id for an order.
* @param newOrderId The order Id
*/
void Order::setOrderId(const int newOrderId)
{
     orderId = newOrderId;
}

/**
* Set the id for a Game.
* @param newGId The order Id
*/
void Order::setGId(int newGId)
{
     GId = newGId;
}


/**
* Set the Id of the Player who delivers the order.
* @param newFromPlayerId Id of the Player who delivers the order.
*/
void Order::setFromPlayerId(int newFromPlayerId)
{
     fromPlayerId = newFromPlayerId;
}

/**
* Set the Id of the Player who recieves/places the order.
* @param newToPlayerId Id of the Player who recieves/places the order.
*/
void Order::setToPlayerId(int newToPlayerId)
{
     toPlayerId = newToPlayerId;
}


/**
* Set the Week Number when the order was placed.
* @param newOrderedInWeek Week Number when the order was placed.
*/
void Order::setOrderedInWeek(int newOrderedInWeek)
{
     orderedInWeek = newOrderedInWeek;
}

/**
* Set the Week Number when the order was shipped.
* @param newShippedInWeek Week Number when the order was shipped.
*/
void Order::setShippedInWeek(int newShippedInWeek)
{
     shippedInWeek = newShippedInWeek;
}

/**
* Set the Quantity of beer units in the order.
* @param newNumberOfBeers Quantity of beer units in the order.
*/
void Order::setNumberOfBeers(int newNumberOfBeers)
{
    numberOfBeers = newNumberOfBeers;
}

/**
* Returns the Order Id.
*/

int Order::getOrderId()
{
    return orderId;
}

/**
* Returns the Game Id.
*/

int Order::getGId()
{
    return GId;
}

/**
* Returns the Player Id who delivers the order.
*/

int Order::getFromPlayerId()
{
    return fromPlayerId;
}

/**
* Returns the Player Id who places the order.
*/

int Order::getToPlayerId()
{
    return toPlayerId;
}

/**
* Returns the Week number when the order was placed.
*/
int Order::getOrderedInWeek()
{
    return orderedInWeek;
}


/**
* Returns the Week number when the order was shipped.
*/
int Order::getShippedInWeek()
{
    return shippedInWeek;
}

/**
* Returns the quantity of beer units in the order.
*/
int Order::getNumberOfBeers()
{
    return numberOfBeers;
}