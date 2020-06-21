/**
* @file game.h
* @brief This header file contains the functionalities needed for initiating games.
*
*/
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include <string>
#include <stddef.h>
#include <time.h>
#include <stdlib.h>

#include "shipment.h"
#include "order.h"
#include "player.h"

class Game
{

private:
  int gId;
  int instrId;
  int pFactId;
  int pDistributorId;
  int pWholesalerId;
  int pRetailerId;
  std::map<int, std::vector<Order>> ordersToBeExecuted;
  std::map<int, std::vector<Shipment>>shipmentsToBeExecuted;
  std::vector<Player*> players;
  std::vector<int> consumerDemandPerWeek;
  double holdingCost = 0.5;
  double backorderCost = 1;
  int startingInventory = 12;
  int weeksToBePlayed = 26;
  int currentWeek = 0;
  int infoCode = 0;
  int orderDelay = 2;
  int shipmentDelay = 2;
  int factoryDelay = 1;
  int numberOfPlayers;

public:
  Game();
  std::vector<std::string> generatePasswords();
  std::map<int, std::vector<Order>> getOrdersToBeExecuted();
  std::map<int, std::vector<Shipment>> getShipmentsToBeExecuted();
  void executeOrdersForCurrentWeek();
  void updatePlayerInventories();
  void addOrder(const int &role, int numberOfBeers);
  void startGame();
  void executeShipmentsForCurrentWeek();
  void getConsumerDemandForWeek(int week);
  void getDownstream(const int &role); //Player*.
  void getUpstream(const int &role);
  void addShipment(int role, int numberOfBeers);
  std::vector<Player*> getPlayers();
  void addPlayer(Player*, int);
  void printPlayers();

  int advanceWeek();

  //setters
  void setGId(int gId);
  void setInstrId(int instrId);
  void setPFactId(int pFactId);
  void setPDistributorId(int pDistributorId);
  void setPWholesalerId(int pWholeSalerId);
  void setPRetailerId(int pRetailerId);
  void setShipmentDelay(int shipmentDelay);
  void setWeeksToBePlayed(int nweeksToBePlayed);
  void setInfoCode(int code);
  void setHoldingCost(double holdingCost);
  void setStartingInventory(int startingInventory);
  void setBackorderCost(double cost);
  void setCurrentWeek(int week);
  void setOrderDelay(int shipmentDelay);
  void setFactoryDelay(int factoryDelay);
  void setNumberOfPlayers(int numOfPlayers);

  //getters
  int getGId();
  int getInstrId();
  int getPFactId();
  int getPDistributorId();
  int getPWholesalerId();
  int getPRetailerId();
  int getShipmentDelay();
  int getWeeksToBePlayed();
  int getInfoCode();
  int getStartingInventory();
  int getCurrentWeek();
  int getOrderDelay();
  int getFactoryDelay();
  int getNumberOfPlayers();
  double getHoldingCost();
  double getBackorderCost();
};
#endif
