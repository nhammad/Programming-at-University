/**
* \class Player
* \author nhammad
* \date 17.03.2020
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>  
using namespace std;

/**
* This class represents one of the four possible players: 
* Manufacturer, Distributor, Wholesaler, or Retailer.
*/

class Player
{

    int PId;
    int role;
    int inventory;
    int backorder;
    float cost;
    int orderPlaced;
    int demand;



public:
    Player();
    void order(int numberOfBeers, Player &from);
    void ship(int numberOfBeers, Player &to);
    int decreaseInventory(int numOfBeers);
    int increaseInventory(int numOfBeers);
    bool recieveShipment(int orderId);
    void setPId(int newPId);
    void setRole(int newRole);
    void setInventory(int newInventory);
    void setBackorder(int newBackorder);
    void setCost(float newCost);
    void setOrderPlaced(int newOrderPlaced);
    void setDemand(int newDemand);
    int getPId();
    int getRole();
    int getBackorder();
    float getCost();
    int getInventory();
    int getDemand();
    int getOrderPlaced();
   
};




#endif
