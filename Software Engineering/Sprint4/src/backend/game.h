/** 
 *  @file   game.h
 *  @brief  Settings of the game, which are set and can be changed by the instructor
 ***************************************************************************************/

#ifndef GAME_H
#define GAME_H

#include <string>
#include <map>
#include <vector>
#include <QtSql>
#include "shipment.h"
#include "order.h"
#include "player.h"

/// @brief Class for setting and configuring the constraints of the Beer Game
class Game
{
public:
    /// @brief Default constructor 
    Game();

    /// @brief Construct game object with a given instructor id.
    ///
    /// @param instrId  Instructor ID
    ///
    Game(int instrId);

    /// @brief Construct game object with a different given parameters
    ///
    /// @param instrId  Instructor ID
    /// @param backlogCost Cost for the one backlog item
    /// @param holdingCost Cost for holding one item
    /// @param orderDelay Order Delay
    /// @param totalWeeks Total amount of weeks to be played in the game
    /// @param startInventory Initial amount of inventory
    /// @param factoryDelay Factory Delay

    Game(int instrId, double backlogCost, double holdingCost, int orderDelay ,int totalWeeks ,int startInventory ,int factoryDelay);

    ///
    ///@brief This method is called by the instructor to start the game
    ///
    ///Basically when this function is called, it starts executing orders and shipments for the 1st week
    ///
    void startGame();

    /// @brief Combine executeWeekTransactions and executeOrdersForCurrentWeek functions
    void executeWeekTransactions();

    ///
    ///@brief Takes the order vector for the current week based on currentWeek proerty. Then loops through the vector and 
    ///executes the orders by calling order.executeEvent() 
    ///
    void executeOrdersForCurrentWeek();
    ///
    ///@brief Takes the shipment vector for the current week based on currentWeek proerty. Then loops through the vector and 
    ///executes the shipments by calling shipment.executeEvent() 
    ///
    void executeShipmentsForCurrentWeek();

    ///
    ///@brief This method was listed in the initial documentation, but has been deprecated
    ///
    ///@deprecated
    ///
    void updatePlayerInventories();


    /// @brief For the current week return the consumer Demand.
    /// 
    /// The values for consumer order are set by default. These values can be overriden by values provided by the instructor. However, as of Sprint2 
    /// this functionality in instructor does not exist
    /// 
    /// @return Consumer Demad for the current week.

    int getConsumerDemandForWeek();

    /// @brief Move onto the next week and executeWeekTransactions
    void advanceWeek();

    // @brief Add the parameter to the vector of orders
    // 
    // The order contains a property that says in which week it is going to be executed. Using this property, the order is placed in 
    // ordertoBeExecuted vector's correct location
    // 
    // @param order The order object that is to be added to ordersToBeExecuted

    void addOrder(Order order);

    
    /// @brief Add the parameter to the vector of shipments
    /// 
    /// The shipment contains a property that says in which week it is going to be executed. Using this property, the shipment is placed in 
    /// shipmentsToBeExecuted vector's correct location
    /// 
    /// @param shipment The shipment object that is to be added to shipmentsToBeExecuted
     
    void addShipment(Shipment shipment);

    /// @brief add a new player
    /// @param *player pointer to the player
    void addPlayer(Player *player);

    /// @brief get a certain player
    /// @param role Could be Factory, Distributor, Wholesaler, Retailer
    /// @return the player (role) who is predecessor in the chain
    Player *getDownstream(int role);

    /// @brief get a certain player
    /// @param role Could be Factory, Distributor, Wholesaler, Retailer
    /// @return the player (role) who is successor in the chain
    Player *getUpstream(int role);

    /// @brief randomly generate password containing characters and some other symbols
    /// @return generated password
    std::vector<std::string> generatePasswords();

    /// @brief If all the players has joined the game, then game is ready to start and
    ///  return true, otherwise false
    /// @return true or false
    bool gameReadyToStart();

private:
    /// @brief The game id
    QSqlDatabase db;

    /// @brief The game id
    unsigned int gId;
    /// @brief The game's intructor's id
    unsigned int instrId = 0;
    /// @brief The game's factory player id
    unsigned int pFactId = 0;
    /// @brief The game's distributor player id
    unsigned int pDistributorId = 0;
    /// @brief The game's wholesaler player id
    unsigned int pWholesalerId = 0;
    /// @brief The game's retailer player id
    unsigned int pRetailerId = 0;

    /// @brief Vector of orders to be executed
    std::map<int, std::vector<Order>> ordersToBeExecuted;

    /// @brief Vector of shipments to be executed
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;

    /// @brief Vector of players
    std::vector<Player *> players;

    /// @brief Vector of consumer demands
    std::vector<int> consumerDemandPerWeek = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    /// @brief Order Delay
    int orderDelay = 2;

    /// @brief Shipment Delay
    int shipmentDelay = 2;

    /// @brief Holding Cost
    double holdingCost = 0.5;

    /// @brief Backorder Cost
    double backorderCost = 1;

    /// @brief Starting Inventory
    int startingInventory = 12;

    /// @brief Weeks to be played
    int weeksToBePlayed = 26;

    /// @brief Current Week number
    int currentWeek = 0;

    /// @brief Info code
    int infoCode = 0;

    /// @brief Factory Delay
    int factoryDelay = 1;

    /// @brief Total orders in week
    int totalOrdersInWeek = 0;

    /// @brief Total shipments in weel
    int totalShipmentsInWeek = 0;

    /// @brief Number of players
    int nPlayers = 5;

    /// @brief Number of players
    bool weekAdvanced = false;
public:
    
     /// @brief Getter Method for game's number of Player
    int getNPlayers() const;
    /// @brief Setter Method for game's number of Player
    /// @param value  number of Player
    void setNPlayers(int value);

    /// @brief Getter Method for game's number of shipment received
    int getNShipmentsReceived() const;
    /// @brief Setter Method for game's number of shipment received
    /// @param value  number of shipment received
    void setNShipmentsReceived(int value);

    /// @brief Getter Method for game's  number of orders received
    int getNOrdersReceived() const;
    /// @brief Setter Method for game's number of orders received
    /// @param value  number of orders received
    void setNOrdersReceived(int value);

    /// @brief Getter Method for game's factory delay
    int getFactoryDelay() const;
    /// @brief Setter Method for game's factory delay
    /// @param value  factory delay
    void setFactoryDelay(int value);

    /// @brief Getter Method for game's info code    
    int getInfoCode() const;
    /// @brief Setter Method for game's info code
    /// @param value  info code
    void setInfoCode(int value);

    /// @brief Getter Method for game's current week 
    int getCurrentWeek() const;
    /// @brief Setter Method for game's current week
    /// @param value  current week
    void setCurrentWeek(int value);

    /// @brief Getter Method for game's weeks to be played
    int getWeeksToBePlayed() const;
    /// @brief Setter Method for game's weeks to be played
    /// @param value  weeks to be played
    void setWeeksToBePlayed(int value);

    /// @brief Getter Method for game's starting inventory   
    int getStartingInventory() const;
    /// @brief Setter Method for game's starting inventory
    /// @param value  starting inventory
    void setStartingInventory(int value);

    /// @brief Getter Method for game's backorder cost   
    double getBackOrderCost() const;
    /// @brief Setter Method for game's backorder cost
    /// @param value  backorder cost
    void setBackOrderCost(double value);

    /// @brief Getter Method for game's holding cost    
    double getHoldingCost() const;
    /// @brief Setter Method for game's holding cost
    /// @param value  holding cost
    void setHoldingCost(double value);

    /// @brief Getter Method for game's shipment delay
    int getShipmentDelay() const;

    /// @brief Getter Method for game's weekAdvanced Property
    bool getWeekAdvanced() const;

    /// @brief Setter Method for game's shipment delay
    /// @param value  shipment delay
    void setShipmentDelay(int value);

    /// @brief Getter Method for game's order delay
    int getOrderDelay() const;
    /// @brief Setter Method for game's order delay
    /// @param value  order delay
    void setOrderDelay(int value);

    /// @brief Getter Method for game's Consumer Demand Per Week  
    std::vector<int> getConsumerDemandPerWeek() const;
    /// @brief Setter Method for game's Consumer Demand Per Week
    /// @param value  Consumer Demand Per Week
    void setConsumerDemandPerWeek(const std::vector<int> &value);

    /// @brief Getter Method for game's vector of players
    std::vector<Player *> getPlayers() const;
    /// @brief Setter Method for game's vector of players
    /// @param value  vector of players
    void setPlayers(const std::vector<Player *> &value);

    /// @brief Getter Method for game's    
    std::map<int, std::vector<Shipment>> getShipmentsToBeExecuted() const;
    /// @brief Setter Method for game's
    /// @param value  
    void setShipmentsToBeExecuted(const std::map<int, std::vector<Shipment>> &value);

    /// @brief Getter Method for game's orders to be executed    
    std::map<int, std::vector<Order>> getOrdersToBeExecuted() const;
    /// @brief Setter Method for game's orders to be executed
    /// @param value orders to be executed
    void setOrdersToBeExecuted(const std::map<int, std::vector<Order>> &value);

    /// @brief Getter Method for game's retailer Id 
    unsigned int getPRetailerId() const;
    /// @brief Setter Method for game's retailer Id
    /// @param value  retailer Id
    void setPRetailerId(unsigned int value);

    /// @brief Getter Method for game's wholesaler Id
    unsigned int getPWholesalerId() const;
    /// @brief Setter Method for game's wholesaler Id
    /// @param value  wholesaler Id
    void setPWholesalerId(unsigned int value);

    /// @brief Getter Method for game's Distributor Id
    unsigned int getPDistributorId() const;
    /// @brief Setter Method for game's Distributor Id
    /// @param value  Distributor Id
    void setPDistributorId(unsigned int value);

    /// @brief Getter Method for game's Factory Id    
    unsigned int getPFactId() const;
    /// @brief Setter Method for game's Factory Id
    /// @param value  Factory Id
    void setPFactId(unsigned int value);

    /// @brief Getter Method for game's Instructor Id
    unsigned int getInstrId() const;
    /// @brief Setter Method for game's  Instructor Id
    /// @param value   Instructor Id
    void setInstrId(unsigned int value);

    /// @brief Getter Method for game's Game Id
    unsigned int getGId() const;
    /// @brief Setter Method for game's Game Id
    /// @param value  Game Id
    void setGId(unsigned int value);

    /// @brief Setter Method for game's TotalOrdersInWeek parameter
    /// @param value  Number of Total Orders In Week
    void setTotalOrdersInWeek(unsigned int value);

    /// @brief Setter Method for game's TotalShipmentInWeek parameter
    /// @param value  Number of Total Orders In Week
    void setTotalShipmentsInWeek(unsigned int value);

};

#endif // GAME_H
