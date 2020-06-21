#include <iostream>
#include "Game.h"
using namespace std;

void Game::setShipmentDelay(const int newShipmentDelay)
{
     shipmentDelay = newShipmentDelay;
}

void Game::setOrderDelay(const int newOrderDelay)
{
     orderDelay = newOrderDelay;
}


Game::Game()
{
     gID = 0;
     instrID = 0;
     pFactID = 0;
     pDistributorID = 0;
     pWholesalerID = 0;
     pRetailerID = 0;
     orderTimeDelay = 2;
     holdingCost = 0.5;
     backorderCost = 1;
     startingInventory = 12;
     weeksToBePlayed = 26;
     currentWeek = 0;
     infoCode = 0;
     backorder = 0;
     shipmentDelay = 0;
     orderDelay = 0;
};

void Game::setInfoCode(int ninfoCode)
{
     infoCode = ninfoCode;
};

void Game::setStartingInventory(int nstartingInventory)
{
     startingInventory = nstartingInventory;
};

void Game::setBackorder(int nbackorder)
{
     backorder = nbackorder;
};

void Game::setweeksToBePlayed(int nweeksToBePlayed)
{
     weeksToBePlayed = nweeksToBePlayed;
};

void Game::setBackorderCost(double nbackorderCost)
{
     backorderCost = nbackorderCost;
};

void Game::setHoldingCost(double nholdingCost)
{
     holdingCost = nholdingCost;
};

void Game::setCurrentWeek(int ncurrentWeek)
{
     currentWeek = ncurrentWeek;
};

void Game::setGId(int ngID)
{
     gID = ngID;
};

void Game::setInstrId(int nInstrID)
{
     instrID = nInstrID;
};

void Game::setPFactId(int nPFactID)
{
     pFactID = nPFactID;
};

void Game::setPDistributorId(int nPDistributorID)
{
     pDistributorID = nPDistributorID;
};

void Game::setPWholesalerId(int nPWholesalerID)
{
     pWholesalerID = nPWholesalerID;
};

void Game::setRetailerId(int nRetailerID)
{
     pRetailerID = nRetailerID;
};

void Game::setOrderTimeDelay(int nOrderTimeDelay)
{
     orderTimeDelay = nOrderTimeDelay;
};

int Game::getWeeksToBePlayed() const
{
     return weeksToBePlayed;
};

int Game::getInfoCode() const
{
     return infoCode;
};

int Game::getStartingInventory() const
{
     return startingInventory;
};

int Game::getBackorder() const
{
     return backorder;
};

double Game::getBackorderCost() const
{
     return backorderCost;
};

double Game::getHoldingCost() const
{
     return holdingCost;
};

map<int, Order> Game::getOrdersToBeExecuted() const
{
     return ordersToBeExecuted;
};

int Game::getCurrentWeek() const
{
     return currentWeek;
};

int Game::getShipmentDelay() const
{
     return shipmentDelay;
}

int Game::getOrderDelay() const
{
     return orderDelay;
}

int Game::getGId() const
{
     return gID;
}

int Game::getInstrId() const
{
     return instrID;
}

int Game::getPFactId() const
{
     return pFactID;
}

int Game::getPDistributorId() const
{
     return pDistributorID;
}

int Game::getPWholesalerId() const
{
     return pWholesalerID;
}

int Game::getRetailerId() const
{
     return pRetailerID;
}

int Game::getOrderTimeDelay() const
{
     return orderTimeDelay;
}

void Game::addOrder(Order order)
{
     ordersToBeExecuted.insert(pair<int, Order>(0, order));
};

int Game::advanceWeek()
{
     return ++currentWeek;
};

vector<string> Game::generatePasswords()
{

     // set array of possible chars
     static const char alphanum[] =
         "0123456789"
         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
         "abcdefghijklmnopqrstuvwxyz";

     vector<string> passwords;
     string s;
     char c;

     // for each password
     for (int j = 0; j < 4; ++j)
     {
          // init password
          s = "";

          // for 10 chars
          for (int i = 0; i < 10; ++i)
          {
               // select random char and push onto string
               c = alphanum[rand() % (sizeof(alphanum) - 1)];
               s.push_back(c);
          }

          // push final password onto passwords
          passwords.push_back(s);
     }

     return passwords;
};
