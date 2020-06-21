/** 
 *  @file   player.h
 *  @brief  Abstract class for different roles
 ******************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "game.h"
#include "../frontend/playerdialog.h"
#include "../frontend/ui_playerdialog.h"

#define CONSUMER 0
#define RETAILER 1
#define WHOLESALER 2
#define DISTRIBUTOR 3
#define FACTORY 4


const std::string GLOBAL_PLAYERS[] = {
    "Consumer",
    "Retailer",
    "Wholesaler",
    "Distributor",
    "Factory"};

class Game;

/// @brief Class for roles like Factory, Distributor, Wholesaler, Retailer
class Player
{
public:
    /// @brief Default Constructor
    Player() {}

    /// @brief Construct player object with a given game instance and role.
    ///
    /// @param *game pointer to the game
    /// @param role Factory, Distributor, Wholesaler, Retailer
    ///
    Player(Game *game, int role);

    /// @brief set UI
    void setUi(Ui::PlayerDialog *ui);

    /// @brief update player UI
    void updatePlayerUi();

    // To be implemented

    /// @brief place order with a certain number of beers
    /// @param numberOfBeers number of beers
    void placeOrder(int numberOfBeers);

    /// @brief place shipment with a certain number of beers
    /// @param numberOfBeers number of beers
    void placeShipment(int numberOfBeers);

    /// @brief get available shipment
    /// @param numberOfBeers number of beers
    int getAvailableShipment(int numberOfBeers);

    /// @brief receive shipment
    /// @param numberOfBeers number of beers
    void receiveShipment(int numberOfBeers);

    /// @brief receive order
    /// @param numberOfBeers number of beers
    void receiveOrder(int numberOfBeers);

    /// @brief decrease inventory by a certain number of beers
    /// @param numberOfBeers number of beers
    void decreaseInventory(int numberOfBeers);

    /// @brief increase inventory by a certain number of beers
    /// @param numberOfBeers number of beers
    void increaseInventory(int numberOfBeers);

    /// @brief get unique order id
    int getUniqueOrderId();
private:
  /// @brief pointer to the game
  Game *game;
  /// @brief player ui
  Ui::PlayerDialog *playerui;

  /// @brief player id
  int pId = 0;

  /// @brief role
  int role;

  /// @brief inventory
  int inventory = 12;

  /// @brief back order
  int backOrder = 0;

  /// @brief incoming order
  int incomingOrder = 0;

  /// @brief incoming shipment
  int incomingShipment = 0;

  /// @brief incoming shipment history
  std::vector<int> incomingShipmentHistory= {};

  /// @brief outgoing shipment
  int outgoingShipment = 0;

  /// @brief outgoing shipment history
  std::vector<int> outgoingShipmentHistory= {};

  /// @brief demand
  int demand= 0;

  /// @brief demadhistory
  std::vector<int> orderHistory= {};

  /// @brief cost
  double cost = 0;

  /// @brief total cost
  double totalCost = 0;

  /// @brief order received
  bool orderReceived = false;

  /// @brief shipment received
  bool shipmentReceived = false;

  /// @brief order placed
  bool orderPlaced = false;

  /// @brief shipment placed
  bool shipmentPlaced = false;
public:

  Game *getGame() const;
  void setGame(Game *value);
  Ui::PlayerDialog *getPlayerui() const;
  void setPlayerui(Ui::PlayerDialog *value);
  int getPId() const;
  void setPId(int value);
  int getRole() const;
  void setRole(int value);
  int getInventory() const;
  void setInventory(int value);
  int getBackOrder() const;
  void setBackOrder(int value);
  int getIncomingOrder() const;
  void setIncomingOrder(int value);
  int getIncomingShipment() const;
  void setIncomingShipment(int value);
  int getOutgoingShipment() const;
  void setOutgoingShipment(int value);
  int getDemand() const;
  void setDemand(int value);
  double getCost() const;
  void setCost(double value);
  double getTotalCost() const;
  void setTotalCost(double value);
  bool isOrderReceived() const;
  void setOrderReceived(bool value);
  bool isShipmentReceived() const;
  void setShipmentReceived(bool value);
  bool isOrderPlaced() const;
  void setOrderPlaced(bool value);
  bool isShipmentPlaced() const;
  void setShipmentPlaced(bool value);
  std::vector<int> getOrderHistory() const;
  void setOrderHistory(const std::vector<int> &value);
  std::vector<int> getIncomingShipmentHistory() const;
  void setIncomingShipmentHistory(const std::vector<int> &value);
  std::vector<int> getOutgoingShipmentHistory() const;
  void setOutgoingShipmentHistory(const std::vector<int> &value);
};

#endif // PLAYER_H
