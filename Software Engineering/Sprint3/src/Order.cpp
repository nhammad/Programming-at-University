#include "Order.h"

Order::Order() {}


Order::Order(int newgId, int newOrderId, int newOrderedInWeek, int newShippedInWeek, int newNumberOfBeers, Player *newReceiver) : PlayerEvent(newgId, newReceiver, newNumberOfBeers)
{
    orderedInWeek = newOrderedInWeek;
    shippedInWeek = newShippedInWeek;
}

int Order::getOrderId() const
{
    return orderId;
}

void Order::setOrderId(int orderId)
{
    Order::orderId = orderId;
}

int Order::getOrderedInWeek() const
{
    return orderedInWeek;
}

void Order::setOrderedInWeek(int orderedInWeek)
{
    Order::orderedInWeek = orderedInWeek;
}

int Order::getShippedInWeek() const
{
    return shippedInWeek;
}

void Order::setShippedInWeek(int shippedInWeek)
{
    Order::shippedInWeek = shippedInWeek;
}

// Additonal methods
void Order::executeOrder()
{
    // TODO
    //we increase the inventory of  the player by the number of crates ordered
}