/**
* \class Order
* \author nhammad
* \date 17.03.2020
*/

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
using namespace std;


/**
* This class represents an Order placed by one of the players.
*/

class Order
{
    int orderId;
    int GId;
    int fromPlayerId;
    int toPlayerId;
    int orderedInWeek;
    int shippedInWeek;
    int numberOfBeers;

public:
    void executeOrder();
    void setOrderId(int newOrderId);
    void setGId(int newGId);
    void setFromPlayerId(int newFromPlayerId);
    void setToPlayerId(int newToPlayerId);
    void setOrderedInWeek(int newOrderedInWeek);
    void setShippedInWeek(int newShippedInWeek);
    void setNumberOfBeers(int newNumberOfBeers);
    int getOrderId();
    int getGId();
    int getFromPlayerId();
    int getToPlayerId();
    int getOrderedInWeek();
    int getShippedInWeek();
    int getNumberOfBeers();

};





#endif