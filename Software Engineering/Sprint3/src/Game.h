/*! \file Game.h
    \brief File containing the implementation of Game class.
    
    This class stores information related to the overall functionality of the Game
    This handles activities that involves players exchanges information such as orders and shipments,
    and also handles the game logic.
*/
/*! \class Game
    \brief The Game class.

    This class creates a Game with the relevant properties and methods to ensure 
    the Game is played correctly.
*/

#ifndef GAME_H
#define GAME_H

#include <map>
#include <vector>
#include <string>

#include "PlayerEvent.h"
#include "Order.h"
#include "Shipment.h"
#include "Player.h"
#include "PlayerEvent.h"
#include <unordered_map>

class Game {
private:
    int gId;     /*!< Unique identifier for a Game */
    int instrId; /*!< Unique identifier for the Instructor who creates the Game */

    int pFactId; /*!< players number from 0-3. The players will be assigned baed on their order in the supply chain. */
    int pDistributorId; /*!< \sa pFactId */
    int pWholesalerId;  /*!< \sa pFactId. \n Wholesalers and/or Retailers can be removed from the game if there are not enough players. Their Ids will consequently not be set.*/
    int pRetailerId;    /*!< \sa pWholesalerId, pFactId */

    std::unordered_map<int, std::vector<Order>> ordersToBeExecuted; /*!< Stores a map that links a particular week number of the vector of orders from the players for that given week. */
    std::unordered_map<int, std::vector<Shipment>> shipmentsToBeExecuted; /*!< Stores a map that links a particular week number ot the vector of shipments from the players for that given week. */

    std::vector<int> consumerDemandPerWeek; /*!< Stores the various randomnly generated consumer demands in a vector form. */
    std::vector<Player *> players;            /*!< Stores the pointers to the player objects representing the players taking part in the game. */

    double holdingCost = 0.5; /*!< The cost of having items in inventory. Default value = 0.5. */
    double backorderCost = 1; /*!< The cost of having items in backorder. Default value = 1.0 */
    int startingInventory = 12; /*!< The amount of crates of beer every player starts the game with. Default value = 12. */
    int weeksToBePlayed = 26;   /*!< The length of the game in number of rounds which are the equivalent of weeks. Default value = 26. */
    int currentWeek = 0;        /*!< The current week the Game is in. At start, defaults to 0. */
    int infoCode = 0; /*!< Specify the degree of information sharing in Game. */

    int orderDelay; /*!< Rounds delay between sending an order and it arriving at the destination player. Traditional rules set this value to 2 weeks. */
    int shipmentDelay; /*!< Rounds delay between sending a shipment and it arriving at the destination player. Traditional rules set this value to 2 weeks. */
    int factoryDelay = 1; /*!< Rounds delay between the factory making an order and it being prepared. Default = 1 week. */
    int numOfPlayers=0;     /*!< Number of players in the Game. */
    bool gameStarted =false;

public:

    Game();
    Game(int newgId,
         int newinstrId,
         int newpFactId,
         int newpDistributorId,
         int newpWholesalerId,
         int newpRetailerId,
         double newholdingCost,
         double newbackorderCost,
         int newstartingInventory,
         int newweeksToBePlayed,
         int newcurrentWeek,
         int newinfoCode,
         int neworderDelay,
         int newshipmentDelay,
         int newfactoryDelay,
         int newnumOfPlayers,
         std::vector<Player*> newplayers,
         std::unordered_map<int, std::vector<Order>> newordersToBeExecuted,
         std::unordered_map<int, std::vector<Shipment>> newshipmentsToBeExecuted,
         std::vector<int> newconsumerDemandPerWeek);


/**
* @brief Execute each order for the current week
*/
    void executeOrdersForCurrentWeek(); 

/**
* @brief Execute each shipment for the current week 
*/
    void executeShipmentsForCurrentWeek(); /*!< */

/**
* @brief updates the inventory of the players 
*/
    void updatePlayerInventories(); 

/**
* @brief move to the next week
* @return next week number
*/
    int advanceWeek(); 

/**
* @brief adds the number of orders
* @param role Role Number of the player who gives the order
* @param numberOfBeers Number of Beers to be orderd
* @return week number
*/
    void addOrder(const int &role, int numberOfBeers); 

/**
* @brief adds the shipment
* @param role Role Number of the player who gives the shipment
* @param numberOfBeers Number of Beers to be shipped
*/
    void addShipment(const int &role, int numberOfBeers);

/**
* @brief adds the Player to the vector of players
* @param player Player to be added
*/
    void addPlayer(Player* player);

/**
    * @brief Generates 4 random passwords
    * Each password is of length 10. After generating passwords, they're stored in the vector passwords.
    * @return vector<string> - 4 random passwords
    */
    std::vector<std::string> generatePasswords(); /*!<  */

// Getters and Setters:
/**
* @brief getter for game id
* @return game id
*/
    int getGId() const;

/**
* @brief setter for game id
* @param gId game id
* @return 
*/
    void setGId(int gId);

/**
* @brief getter for instructor id
* @return instructor id
*/
    int getInstrId() const;

/**
* @brief setter for instructor id
* @param instrId
* @return 
*/
    void setInstrId(int instrId);

/**
* @brief getter for game id
* @return factory id
*/
    int getPFactId() const;

/**
* @brief setter for instructor id
* @param pFactId
*/
    void setPFactId(int pFactId);

/**
* @brief getter for game id
* @return distributor id
*/
    int getPDistributorId() const;

/**
* @brief setter for instructor id
* @param pDistributorId
* @return 
*/
    void setPDistributorId(int pDistributorId);

/**
* @brief getter for wholesaler id
* @return wholesaler id
*/
    int getPWholesalerId() const;

/**
* @brief setter for wholesaler id
* @param pWholesalerId
* @return 
*/
    void setPWholesalerId(int pWholesalerId);

/**
* @brief getter for retailer id
* @return retailer id
*/
    int getPRetailerId() const;

/**
* @brief setter for retailer id
* @param pRetailerId retailer id
*/
    void setPRetailerId(int pRetailerId);


/**
* @brief returns a map of week number and the orders
* @return orders to be executed
*/
    std::unordered_map<int, std::vector<Order>> &getOrdersToBeExecuted();

/**
* @brief setter for a map of week number  and the orders
* @param ordersToBeExecuted orders to be executed, as an ordered map 
*/
    void setOrdersToBeExecuted(std::unordered_map<int, std::vector<Order>> &ordersToBeExecuted);

/**
* @brief returns a map of week number and the shipments
* @return getShipmentsToBeExecuted
*/
    std::unordered_map<int, std::vector<Shipment>> &getShipmentsToBeExecuted();

/**
* @brief returns a map of week number  and the shipments
* @param shipmentsToBeExecuted shipments to be executed in each week as an unordered map
*/
    void setShipmentsToBeExecuted(std::unordered_map<int, std::vector<Shipment>> &shipmentsToBeExecuted);

/**
* @brief returns a vector of customer demand per week
* @return vector of customer demand per week
*/
    const std::vector<int> &getConsumerDemandPerWeek() const;

/**
* @brief setter for consumer demand per week as a vector
* @param demandPerWeek consumer demand per week
*/
    void setConsumerDemandPerWeek(const std::vector<int> &demandPerWeek);

/**
* @brief getter for order time delay
* @return demandPerWeek
*/

    int getOrderTimeDelay() const;

/**
* @brief setter for Order Time Delay 
* @param orderTimeDelay Order Time Delay
*/

    void setOrderTimeDelay(int orderTimeDelay);

/**
* @brief get Holding Cost
*/
    double getHoldingCost() const;

/**
* @brief setter for Holding Cost
* @param holdingCost Holding Cost
* @return 
*/
    void setHoldingCost(double holdingCost);

/**
* @brief getter for back order cost
* @return Backorder Cost
*/
    double getBackorderCost() const;

/**
* @brief setter for backorder cost
* @param backorderCost backorder cost
* @return 
*/
    void setBackorderCost(double backorderCost);

/**
* @brief getter for starting inventory size
* @return starting inventory size
*/
    int getStartingInventory() const;

/**
* @brief setter for starting inventory size
* @param startingInventory
* @return starting inventory size
*/
    void setStartingInventory(int startingInventory);

/**
* @brief getter for weeks to be played
* @return Weeks To Be Played
*/
    int getWeeksToBePlayed() const;

/**
* @brief setter for Weeks to be Played
* @param weeksToBePlayed
*/
    void setWeeksToBePlayed(int weeksToBePlayed);

/**
* @brief getter for current week
* @return Current Week
*/
    int getCurrentWeek();

/**
* @brief setter for Current Week
* @param currentWeek
*/
    void setCurrentWeek(int currentWeek);

/**
* @brief getter for info code
* @return InfoCode
*/
    int getInfoCode() const;

/**
* @brief setter for info code
* @param infoCode
* @return 
*/
    void setInfoCode(int infoCode);

/**
* @brief getter for Order Delay
* @return Order Delay
*/
    int getOrderDelay() const;

/**
* @brief setter for Order Delay
* @param orderDelay
* @return 
*/
    void setOrderDelay(int orderDelay);

/**
* @brief getter for Shipment Delay

* @return ShipmentDelay
*/
    int getShipmentDelay() const;

/**
* @brief setter for Shipment Delay
* @param shipmentDelay
* @return 
*/
    void setShipmentDelay(int shipmentDelay);

/**
* @brief getter for Factory Delay
* @return Factory Delay
*/
    int getFactoryDelay() const;

/**
* @brief setter for Factory Delay
* @param newFactoryDelay
* @return 
*/
    void setFactoryDelay(int newFactoryDelay);

/**
* @brief starts the game
*/
    void startGame();

/**
* @brief gets the information of the downstream unit
* @param role Current Role
* @return Downstream Player
*/
    Player* getDownstream(const int& role);

/**
* @brief gets the information of the upstream unit
* @param role Current Role
* @return Upstream Player
*/
    Player* getUpstream(const int& role);

/**
* @brief gets the players
* @return vector of all players
*/
    std::vector<Player*> getPlayers();

/**
* @brief sets the players
* @param newPlayers
*/
    void setPlayers(std::vector<Player*> newPlayers);

/**
* @brief returns the number of players
* @return number of players
*/
    int getNumberOfPlayers() const;

/**
* @brief returns the status of the game
*/
    bool getGameStarted();


/**
* @brief returns the number of players
* @param newNumberOfPlayers number of players
*/
    void setNumberOfPlayers(int newNumberOfPlayers);

/**
* @brief sets the gameStarted variable true.
*/
    void setGameStarted(bool status);
};


#endif 
