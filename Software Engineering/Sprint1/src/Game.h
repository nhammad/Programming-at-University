/**
* \class Game
* \author Dorrab Khan 
* \date 17.03.2020
*/


#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Order.h"

using namespace std;

/**
* This class represents a Game which is created by an Instructor and played 
* by multiple Players.
*/


class Game {

private:					    	    
	int gID;    		    		            // game ID
	int instrID;			                    // isntructor ID
    int pFactID;                                // player factory ID
    int pDistributorID;                         // player distributor ID
    int pWholesalerID;                          // player wholesaler ID
    int pRetailerID;                            // player retailer ID
    map<int, Order> ordersToBeExecuted;         // vector of pending orders
    vector<int> demandPerWeek;                  // vector of demand pattern
    int orderTimeDelay;                         // delay in orders
    double holdingCost;                         // cost of holding inventory
    double backorderCost;                       // cost of being in backorder
    int startingInventory;                      // starting inventory
    int weeksToBePlayed;                        // weeks to play
    int currentWeek;                            // current week in game
    int infoCode;                               // level of sharing info
    int backorder;                              // current backorder
    int orderDelay;                             // delay in orders
    int shipmentDelay;                          // delay in shipments


public:

    /**
    * Default constructor for the Game class
    */
    Game();

    // setters

    /**
    * Set the delay, which is caused between shipping orders.
    * @param newShipmentDelay Value of how much delay is caused.
    */
    void setShipmentDelay(int newShipmentDelay);

    /**
    * Set the delay, which is caused between placing orders.
    * @param newOrderDelay Value of how much delay is caused.
    */
    void setOrderDelay(int newOrderDelay);

    /**
    * Set the level of information sharing in the game
    * @param ninfoCode the code for the new level of information sharing.
    */
    void setInfoCode(int ninfoCode);

    /**
    * Set the starting inventory level
    * @param nstartingInventory the new starting inventory
    */
    void setStartingInventory(int nstartingInventory);

    /**
    * Set backorder on the current game
    * @param nbackorder new backorder
    */
    void setBackorder(int nbackorder);

    /**
    * Set number of weeks the game will be played
    * @param nweeksToBePlayed the number of weeks to play
    */
    void setweeksToBePlayed(int nweeksToBePlayed);

    /**
    * Set cost of each backorder in the gamee
    * @param nbackorderCost new cost of backorder
    */
    void setBackorderCost(double nbackorderCost);

    /**
    * set cost of holding inventory
    * @param nholdingCost cost of holding inventory
    */
    void setHoldingCost(double nholdingCost);

    /**
    * set current week in the game
    * @param ncurrentWeek new current week
    */
    void setCurrentWeek(int ncurrentWeek);

    /**
    * set Game ID
    * @param ngID the new game ID
    */
    void setGId(int ngID);

    /**
    * set instructor ID
    * @param niID new instructor ID
    */
    void setInstrId(int niID);

    /**
    * set factory player's ID
    * @param nfID new factory ID
    */
    void setPFactId(int nfID);

    /**
    * set new distributor player ID
    * @param ndID new distributor ID
    */
    void setPDistributorId(int ndID);

    /**
    * set wholesaler's player ID
    * @param nwID new wholesaler ID
    */
    void setPWholesalerId(int nwID);

    /**
    * set retailer's player ID
    * @param nrID new retailer ID
    */
    void setRetailerId(int nrID);

    /**
    * set delay between orders
    * @param ndelay the new delay
    */
    void setOrderTimeDelay(int ndelay);

    // getters

    /**
    * get delay between shipments for the game
    * @return int - shipment delay
    */
    int getShipmentDelay() const;

    /**
    * get delay between orders
    * @return int - delay value
    */
    int getOrderDelay() const;

    /**
    * get max number of weeks to be played
    * @return int - no of weeks
    */
    int getWeeksToBePlayed() const;

    /**
    * get code for level of information sharing
    * @return int - code for information sharing
    */
    int getInfoCode() const;

    /**
    * get starting inventory for each player
    * @return int - starting inventory
    */
    int getStartingInventory() const;

    /**
    * get value of backorder
    * @return int - backorder value
    */
    int getBackorder() const;

    /**
    * get cost of being in backorder
    * @return double - backorder cost
    */
    double getBackorderCost() const;

    /**
    * get cost of holding inventory
    * @return double - holding cost
    */
    double getHoldingCost() const;

    /**
    * get map of orders to be executed
    * @return map<int, Order> - pending orders
    */
    map<int, Order> getOrdersToBeExecuted() const;

    /**
    * get current week in game
    * @return int - current week
    */
    int getCurrentWeek() const;

    /**
    * get game ID
    * @return int - game ID
    */
    int getGId() const;

    /**
    * get instructor ID that owns the game
    * @return int - instructor ID
    */
    int getInstrId() const;

    /**
    * get player ID of factory
    * @return int - factory ID
    */
    int getPFactId() const;

    /**
    * get player ID for distributor
    * @return int - distributor ID
    */
    int getPDistributorId() const;

    /**
    * get player ID for wholesaler
    * @return int - wholesaler ID
    */
    int getPWholesalerId() const;

    /**
    * get player ID for retailer
    * @return int - retailer ID
    */
    int getRetailerId() const;

    /**
    * get delay between orders
    * @return int - order delay
    */
    int getOrderTimeDelay() const;

    // misc

    /**
    * add order to list of orders
    * @param order order to add
    */
    void addOrder(Order order);

    /**
    * advance the current week
    * @return int - new week
    */
    int advanceWeek();

    /**
    * generate 4 random passwords
    * @return vector<string> - 4 random passwords
    */
    vector<string> generatePasswords();
};

#endif /* GAME_H_ */