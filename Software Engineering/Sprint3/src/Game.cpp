#include "Game.h"
#include "Order.h"
#include "PlayerEvent.h"
#include "Player.h"
#include "Shipment.h"
#include <map>
#include <unordered_map>
#include <vector>
#include <random>
#include <string>
#include <iostream>

//! Default constructor.
/*!
          initializes a Game with default settings.
        */
Game::Game() {}

//! Parametric Constructor
/*!
initializes a Game with specified properties.
      \param newgameId unique Id for game.
      \param newinstructorId unique ID of associated instructor.
      \param newpFactoryId player ID of factory player.
      \param newpDistributorId player ID of Distributor player.
      \param newpWholesalerId player ID of Wholesaler player.
      \param newpRetailerId player ID of Retailer player.
      \param newweeklyDemand demand for each week.
      \param newOrderTimeDelay time delay associated with each order made by a given player.
      \param newbackOrderCost cost of keeping items in back order.
      \param newstartingInventory default inventory count at game start.
      \param newweeksToPlay week length of game.
      \param newcurrentWeek current week of game. Defaults to 0 at start.
      \param newinfoCode code controlling amount of info sharing between players.
      \param newshipmentDelay time between a shipmnet being dispatched and it being received.
      \param neworderDelay time delay  between sending and receiving of an order. .
*/
Game::Game(int newgId,
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
           std::vector<Player *> newplayers,
           std::unordered_map<int, std::vector<Order>> newordersToBeExecuted,
           std::unordered_map<int, std::vector<Shipment>> newshipmentsToBeExecuted,
           std::vector<int> newconsumerDemandPerWeek)
{
    gId = newgId;
    instrId = newinstrId;
    pFactId = newpFactId;
    pDistributorId = newpDistributorId;
    pWholesalerId = newpWholesalerId;
    pRetailerId = newpRetailerId;
    holdingCost = newholdingCost;
    backorderCost = newbackorderCost;
    startingInventory = newstartingInventory;
    weeksToBePlayed = newweeksToBePlayed;
    currentWeek = newcurrentWeek;
    infoCode = newinfoCode;
    orderDelay = neworderDelay;
    shipmentDelay = newshipmentDelay;
    factoryDelay = newfactoryDelay;
    numOfPlayers = newnumOfPlayers;
    players = newplayers;
    ordersToBeExecuted = newordersToBeExecuted;
    shipmentsToBeExecuted = newshipmentsToBeExecuted;
    consumerDemandPerWeek = newconsumerDemandPerWeek;
}

void Game::executeOrdersForCurrentWeek()
{
    // TODO
    //iterate through the vector for the current week and execute their respective orders
    for (int i = 0; i < 4; i++)
    {
        ordersToBeExecuted[currentWeek][i].executeOrder();
    }
}

void Game::executeShipmentsForCurrentWeek()
{
    // TODO
    for (int i = 0; i < 4; i++)
    {
        this->getShipmentsToBeExecuted()[this->getCurrentWeek()][i].executeShipment();
    }
}


void Game::updatePlayerInventories()
{
    PlayerEvent pe;
    for (int i = 0; i < numOfPlayers; i++)
    {
        if (pe.getType() == "o")
        {
            int availableShipment;

            if ((*players[i]).getDemand() > (*players[i]).getInventory())
            {
                availableShipment = (*players[i]).getInventory();
                (*players[i]).decreaseInventory(availableShipment);
            }
            else
            {
                availableShipment = (*players[i]).getDemand();
                (*players[i]).decreaseInventory(availableShipment);
            }
        }
        else
        {
            (*players[i]).increaseInventory(pe.numberOfBeers);
        }
    }
}




/** @brief advanceWeek(): Increment currentWeek by one and return it.
*
* @return currentWeek.
* */

int Game::advanceWeek()
{
    setCurrentWeek(getCurrentWeek() + 1);
    return getCurrentWeek();
}

//! Add Order method
/*!
    Adds an Order to the map ordersToBeExecuted for a given role in the current week
      \param role The index denoting which player places the order.
      \param numberOfBeers The number of beers the player requests in their Order.
*/
void Game::addOrder(const int &role, int numberOfBeers)
{
    //set the  properties of the order
    int x = 0; //dummy orderId
  
    Order ord;
    ord.setGId(gId);
    ord.setOrderedInWeek(currentWeek);
    ord.setShippedInWeek(currentWeek+2);
    ord.setNumberOfBeers(numberOfBeers);
    ord.setReceiver(this->getUpstream(role));

    std::vector<Order> orders;
    orders.push_back(ord);
    ordersToBeExecuted.emplace(currentWeek, orders);
    ordersToBeExecuted[currentWeek] = orders;

    Order ordnew(gId, x, currentWeek, currentWeek + 2, numberOfBeers, getUpstream(role));

}

//! Add Shipment method
/*!
    Adds an Shipment to the map shipmentsToBeExecuted for a given role in the current week
      \param role The index denoting which player makes the shipment.
      \param numberOfBeers The number of beers the player needs to ship.
*/
void Game::addShipment(const int &role, int numberOfBeers)
{

    int y = 0;
    Shipment ship;
    ship.setGId(gId);
    ship.setReceivedInWeek(currentWeek);
    ship.setShippedInWeek(currentWeek+2);
    ship.setNumberOfBeers(numberOfBeers);
    ship.setReceiver(this->getDownstream(role));

    std::vector<Shipment> shipments;
    shipments.push_back(ship);
    shipmentsToBeExecuted.emplace(currentWeek, shipments);
    shipmentsToBeExecuted[currentWeek] = shipments;

    Shipment newship(gId, y, currentWeek, currentWeek + 2, numberOfBeers, this->getDownstream(role));
}

//! Add Player method
/*!
    Adds a created player to the vector of players in a given Game
      \param player A pointer to the player to be added.
*/
void Game::addPlayer(Player *player)
{

    if (numOfPlayers < 4)
    {
        int role = numOfPlayers + 1;
        player->setRole(role);
        players.push_back(player);
        numOfPlayers++;
    }
}


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

// Getters and Setters

int Game::getGId() const
{
    return gId;
}

void Game::setGId(int gId)
{
    Game::gId = gId;
}

int Game::getInstrId() const
{
    return instrId;
}

void Game::setInstrId(int instrId)
{
    Game::instrId = instrId;
}

int Game::getPFactId() const
{
    return pFactId;
}

void Game::setPFactId(int pFactId)
{
    Game::pFactId = pFactId;
}

int Game::getPDistributorId() const
{
    return pDistributorId;
}

void Game::setPDistributorId(int pDistributorId)
{
    Game::pDistributorId = pDistributorId;
}

int Game::getPWholesalerId() const
{
    return pWholesalerId;
}

void Game::setPWholesalerId(int pWholesalerId)
{
    Game::pWholesalerId = pWholesalerId;
}

int Game::getPRetailerId() const
{
    return pRetailerId;
}

void Game::setPRetailerId(int pRetailerId)
{
    Game::pRetailerId = pRetailerId;
}

std::unordered_map<int, std::vector<Order>> &Game::getOrdersToBeExecuted()
{
    return ordersToBeExecuted;
}

void Game::setOrdersToBeExecuted(std::unordered_map<int, std::vector<Order>> &ordersToBeExecuted)
{
    Game::ordersToBeExecuted = ordersToBeExecuted;
}

std::unordered_map<int, std::vector<Shipment>> &Game::getShipmentsToBeExecuted()
{
    return shipmentsToBeExecuted;
}

void Game::setShipmentsToBeExecuted(std::unordered_map<int, std::vector<Shipment>> &shipmentsToBeExecuted)
{
    Game::shipmentsToBeExecuted = shipmentsToBeExecuted;
}

const std::vector<int> &Game::getConsumerDemandPerWeek() const
{
    return consumerDemandPerWeek;
}

void Game::setConsumerDemandPerWeek(const std::vector<int> &demandPerWeek)
{
    Game::consumerDemandPerWeek = demandPerWeek;
}

double Game::getHoldingCost() const
{
    return holdingCost;
}

void Game::setHoldingCost(double holdingCost)
{
    Game::holdingCost = holdingCost;
}

double Game::getBackorderCost() const
{
    return backorderCost;
}

void Game::setBackorderCost(double backorderCost)
{
    Game::backorderCost = backorderCost;
}

int Game::getStartingInventory() const
{
    return startingInventory;
}

void Game::setStartingInventory(int startingInventory)
{
    Game::startingInventory = startingInventory;
}

int Game::getWeeksToBePlayed() const
{
    return weeksToBePlayed;
}

void Game::setWeeksToBePlayed(int weeksToBePlayed)
{
    Game::weeksToBePlayed = weeksToBePlayed;
}

int Game::getCurrentWeek()
{
    return currentWeek;
}

void Game::setCurrentWeek(int currentWeek)
{
    Game::currentWeek = currentWeek;
}

int Game::getInfoCode() const
{
    return infoCode;
}

void Game::setInfoCode(int infoCode)
{
    Game::infoCode = infoCode;
}

int Game::getOrderDelay() const
{
    return orderDelay;
}

void Game::setOrderDelay(int orderDelay)
{
    Game::orderDelay = orderDelay;
}

int Game::getShipmentDelay() const
{
    return shipmentDelay;
}

void Game::setShipmentDelay(int shipmentDelay)
{
    Game::shipmentDelay = shipmentDelay;
}

int Game::getFactoryDelay() const
{
    return factoryDelay;
}

void Game::setFactoryDelay(int factoryDelay)
{
    Game::factoryDelay = factoryDelay;
}

void Game::startGame()
{
    setGameStarted(true);
}

Player *Game::getDownstream(const int &role)
{
    for (int i = 0; i < numOfPlayers; i++)
    {
        if (players[i]->getRole() == role + 1)
            return players[i];
    }
    return nullptr;
}

Player *Game::getUpstream(const int &role)
{
    for (int i = 0; i < numOfPlayers; i++)
    {
        if (players[i]->getRole() == role - 1)
            return players[i];
    }
    return nullptr;
}

std::vector<Player *> Game::getPlayers()
{
    return players;
}

void Game::setPlayers(std::vector<Player *> v)
{
    players = v;
}

int Game::getNumberOfPlayers() const
{
    return numOfPlayers;
}

void Game::setNumberOfPlayers(int newN)
{
    numOfPlayers = newN;
}

void Game::setGameStarted(bool status)
{
    gameStarted = status;
}

bool Game::getGameStarted() 
{
    return gameStarted;
}

