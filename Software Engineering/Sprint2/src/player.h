/**
* @file player.h
* @brief This header file contains the functionalities of the player.
*
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "iostream"

class Game;

class Player {

private:
	int pId;
  int role;
  int inventory;
  int backorder;
	int incomingOrder;
	int incomingShipment;
	int outgoingShipment;
	double cost;
	double totalCost;
	bool orderReceived;
	bool shipmentReceived;
	bool orderPlaced;
	bool shipmentPlaced;
  int demand;
	Game* game;


public:
    Player();
    void placeOrder(int numberOfBeers );
    void placeShipment(int numberOfBeers);
    int receiveOrder();
    int receiveShipment();
    int getAvailableShipment(int demand);
    int decreaseInventory(int numberOfBeers);
    int increaseInventory(int numberOfBeers);

    //setters
    void setPId(int pId);
    void setRole(int role);
    void setInventory(int inventory);
    void setBackorder(int backorder);
    void setCost(double cost);
    void setDemand(int demand);
    void setIncomingOrder(int incomingOrder);
    void setIncomingShipment(int incomingShipment);
    void setOutgoingShipment(int outgoingShipment);
    void setTotalCost(double totalcost);
    void setOrderReceived(bool value);
    void setShipmentReceived(bool value);
    void setOrderPlaced(bool value);
    void setShipmentPlaced(bool value);
    void setGame(Game* g);

    //getters
    int getPId();
    int getRole();
    int getInventory();
    int getBackorder();
    double getCost();
    int getDemand();
    int getIncomingOrder();
    int getIncomingShipment();
    int getOutgoingShipment();
    int getTotalCost();
    bool getOrderReceived();
    bool getShipmentReceived();
    bool getOrderPlaced();
    bool getShipmentPlaced();
    Game* getGame() const;
};

#endif
