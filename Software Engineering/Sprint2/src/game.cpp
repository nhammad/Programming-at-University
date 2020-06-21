
/**
* @file game.cpp
*
*/

#include "game.h"

    /**
    * @file game.cpp
    * @brief Default constructor for the Game class
    */

Game::Game()
{
  srand(time(NULL));
  gId = rand() % 1000 + 1;

  for(int i=0; i<4; i++){
    players.push_back(NULL);
  }

}

    /**
    * @brief Generates 4 random passwords
    * Each password is of length 10. After generating passwords, they're stored in the vector passwords.
    * @return vector<string> - 4 random passwords
    */
std::vector<std::string> Game::generatePasswords()
{
     static const char alphanum[] =
         "0123456789"
         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
         "abcdefghijklmnopqrstuvwxyz";

     std::vector<std::string> passwords;
     std::string singlePassword;
     char c;

     for (int j = 0; j < 4; ++j)
     {
          singlePassword = "";

          for (int i = 0; i < 10; ++i)
          {
               c = alphanum[rand() % (sizeof(alphanum) - 1)];
               singlePassword.push_back(c);
          }

          passwords.push_back(singlePassword);
     }

     return passwords;
}

/**
* @brief method to get the orders that need to be executed by mapping the week number to the orders for that specific week
*/
std::map<int, std::vector<Order>> Game::getOrdersToBeExecuted()
{
    return this->ordersToBeExecuted;
}

/**
* @brief method to get the shipments that need to be executed by mapping the week number to the orders for that specific week
*/
std::map<int, std::vector<Shipment>> Game::getShipmentsToBeExecuted()
{
    return this->shipmentsToBeExecuted;
}

void Game::executeOrdersForCurrentWeek()
{
    // TODO - implement Game::executeOrdersForCurrentWeek
    throw "Not yet implemented";
}

void Game::updatePlayerInventories()
{
    // TODO - implement Game::updatePlayerInventories
    throw "Not yet implemented";
}

void Game::addOrder(const int &role, int numberOfBeers)
{
    // TODO - implement Game::addOrder
    throw "Not yet implemented";
}

void Game::startGame()
{
    // TODO - implement
    throw "Not yet implemented";
}

void Game::executeShipmentsForCurrentWeek()
{
    // TODO - implement
    throw "Not yet implemented";
}

void Game::getConsumerDemandForWeek(int week)
{
    // TODO - implement
    throw "Not yet implemented";
}

//This returns the Player object that is next in the "downstream" for a certain role.

void Game::getDownstream(const int &role)
{
    // Player*.
    throw "Not yet implemented";
}

//This returns the Player object that is next in the "upstream" for a certain role.

void Game::getUpstream(const int &role)
{
    // Player*.
    throw "Not yet implemented";
}

void Game::addShipment(int role, int numberOfBeers)
{
    // Player*.
    throw "Not yet implemented";
}

/**
* @brief method to continue to the next week
*/
int Game::advanceWeek()
{
    return this->currentWeek + 1;
}

/**
    * @brief set Game ID
    * @param gID the new game ID
    */

void Game::setGId(int gId)
{
    this->gId = gId;
}

/**
* @brief set instructor ID
* @param instrId new instructor ID
*/

void Game::setInstrId(int instrId)
{
    this->instrId = instrId;
}

/**
* @brief Set factory player's ID
* @param pFactId new factory ID
*/

void Game::setPFactId(int pFactId)
{
    this->pFactId = pFactId;
}

/**
    * @brief set new distributor player ID
    * @param pDistributorId new distributor ID
    */

void Game::setPDistributorId(int pDistributorId)
{
    this->pDistributorId = pDistributorId;
}

/**
    * @brief set wholesaler's player ID
    * @param pWholesalerId new wholesaler ID
    */

void Game::setPWholesalerId(int pWholesalerId)
{
    this->pWholesalerId = pWholesalerId;
}

/**
    * @brief set retailer's player ID
    * @param pRetailerId new retailer ID
    */

void Game::setPRetailerId(int pRetailerId)
{
    this->pRetailerId = pRetailerId;
}

/**
    * @brief Set the delay, which is caused between shipping orders.
    * @param shipmentDelay Value of how much delay is caused.
    */
void Game::setShipmentDelay(int shipmentDelay)
{
    this->shipmentDelay = shipmentDelay;
}

/**
    * @brief Set number of weeks the game will be played
    * @param nweeksToBePlayed the number of weeks to play
    */

void Game::setWeeksToBePlayed(int nweeksToBePlayed)
{
    this->weeksToBePlayed = nweeksToBePlayed;
}

/**
    * @brief Set the level of information sharing in the game
    * @param code the code for the new level of information sharing.
    */
void Game::setInfoCode(int code)
{
    this->infoCode = code;
}

/**
    * @brief set cost of holding inventory
    * @param holdingCost cost of holding inventory
    */

void Game::setHoldingCost(double holdingCost)
{
    this->holdingCost = holdingCost;
}

/**
    * @brief Set the starting inventory level
    * @param nstartingInventory the new starting inventory
    */
void Game::setStartingInventory(int startingInventory)
{
    this->startingInventory = startingInventory;
}

/**
    * @brief Set backorder cost on the current game
    * @param cost new backorder
    */

void Game::setBackorderCost(double cost)
{
    this->backorderCost = cost;
}

/**
    * @brief set current week in the game
    * @param week new current week
    */
void Game::setCurrentWeek(int week)
{
    this->currentWeek = week;
}

    /**
    * @brief Set the delay, which is caused between placing orders.
    * @param orderDelay Value of how much delay is caused.
    */

void Game::setOrderDelay(int orderDelay)
{
    this->orderDelay = orderDelay;
}

    /**
    * @brief Set the delay, which is caused between productions at the factory.
    * @param factoryDelay Value of how much delay is caused.
    */

void Game::setFactoryDelay(int factoryDelay)
{
    this->factoryDelay = factoryDelay;
}

    /**
    * @brief Set the number of players in each game.
    * @param numberOfPlayers number of players in each game.
    */

void Game::setNumberOfPlayers(int numberOfPlayers)
{
    this->numberOfPlayers = numberOfPlayers;
}

/**
    * @brief get game ID
    * @return int - game ID
    */

int Game::getGId()
{
    return this->gId;
}

/**
* @brief get instructor ID that owns the game
* @return int - instructor ID
*/

int Game::getInstrId()
{
    return this->instrId;
}

/**
* @brief get player ID of factory
* @return int - factory ID
*/

int Game::getPFactId()
{
    return this->pFactId;
}

    /**
    * @brief get player ID for distributor
    * @return int - distributor ID
    */

int Game::getPDistributorId()
{
    return this->pDistributorId;
}

    /**
    * @brief get player ID for wholesaler
    * @return int - wholesaler ID
    */

int Game::getPWholesalerId()
{
    return this->pWholesalerId;
}

    /**
    * @brief get player ID for retailer
    * @return int - retailer ID
    */

int Game::getPRetailerId()
{
    return this->pRetailerId;
}

    /**
    * @brief get delay between shipments
    * @return int - shipment delay
    */

int Game::getShipmentDelay()
{
    return this->shipmentDelay;
}

    /**
    * @brief get max number of weeks to be played
    * @return int - no of weeks
    */

int Game::getWeeksToBePlayed()
{
    return this->weeksToBePlayed;
}

    /**
    * @brief get code for level of information sharing
    * @return int - code for information sharing
    */

int Game::getInfoCode()
{
    return this->infoCode;
}

    /**
    * @brief get cost of holding inventory
    * @return double - holding cost
    */

double Game::getHoldingCost()
{
    return this->holdingCost;
}

    /**
    * @brief get starting inventory for each player
    * @return int - starting inventory
    */

int Game::getStartingInventory()
{
    return this->startingInventory;
}

    /**
    * @brief get value of backorder cost
    * @return double - backorder value
    */

double Game::getBackorderCost()
{
    return this->backorderCost;
}

    /**
    * @brief get current week in game
    * @return int - current week
    */

int Game::getCurrentWeek()
{
    return this->currentWeek;
}

    /**
    * @brief get delay between orders
    * @return int - order delay
    */

int Game::getOrderDelay()
{
    return this->orderDelay;
}

    /**
    * @brief get delay between factory productions
    * @return int - factory delay
    */

int Game::getFactoryDelay()
{
    return this->factoryDelay;
}

    /**
    * @brief get number of players involved in the game
    * @return int - number of players
    */

int Game::getNumberOfPlayers()
{
    return this->numberOfPlayers;
}

    /**
    * @brief get the player pointer vector from the game
    * @return vector<Player*> - vector of players
    */

std::vector<Player*> Game::getPlayers(){
  return this->players;
}

    /**
    * @brief Sets a Player in a particular position inside a vector named players
    * @param Player* Pointer to pass the player instance
    * @param p_position Position where to insert the Player
    */

void Game::addPlayer(Player* player_arg, int p_position){
  players[p_position] = player_arg;
  std::cout << "Player pos: " << players[p_position]->getRole() << "\n";
}

    /**
    * @brief Prints all players
    */

void Game::printPlayers(){
  std::vector<Player*>::iterator iter, end;
  for(iter = players.begin(), end = players.end(); iter != end; ++iter){
    (*iter)->placeOrder(0);
  }
}
