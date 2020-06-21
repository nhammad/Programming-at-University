/// \file

#include "gtest/gtest.h"
#include "../src/player.h"
#include "../src/game.h"
#include "../src/instructor.h"
#include "../src/playerEvent.h"
#include <iostream>
#include <map>
#include <gmock/gmock.h>

using testing::ElementsAre;
using testing::Pair;
// Tests for class Player


/**
* Tests the setter for Player Id.
*/

TEST(playerTest, setPIdTest) {

    Player p;
    p.setPId(2);
    EXPECT_EQ(2, p.getPId());
}

/**
* Tests the getter for Player Id.
*/

TEST(playerTest, getPIdTest) {

    Player p;
    p.setPId(25);
    EXPECT_EQ(25, p.getPId());
}

/**
* Tests the setter for Player Role.
*/


TEST(playerTest, setRoleTest) {

    Player p;
    p.setRole(1);
    EXPECT_EQ(1, p.getRole());
}

/**
* Tests the getter for Player Role.
*/

TEST(playerTest, getRoleTest) {

    Player p;
    p.setRole(2);
    EXPECT_EQ(2, p.getRole());
}


/**
* Tests the decreaseInventory() method from the Player class.
*/

TEST(playerTest, decreaseInventoryTest) {

    Player p;
    int curr_inv = p.getInventory();
    EXPECT_EQ(curr_inv-3, p.decreaseInventory(3));
}

/**
* Tests the increaseInventory() method from the Player class.
*/

TEST(playerTest, increaseInventoryTest) {

    Player p;
    int curr_inv = p.getInventory();
    EXPECT_EQ(curr_inv+3, p.increaseInventory(3));
}

/**
* Tests the getter for Player's Backorder.
*/

TEST(playerTest, getBackorderTest){

    Player p;
    p.setBackorder(10);
    EXPECT_EQ(10, p.getBackorder());
}


/**
* Tests the getter for Player's Cost.
*/

TEST(playerTest, getCostTest){

    Player p;
    p.setCost(2);
    EXPECT_EQ(2, p.getCost());
}

/**
* Tests the getter for Player's Inventory value.
*/
TEST(playerTest, getInventoryTest){

    Player p;
    p.setInventory(10000);
    EXPECT_EQ(10000, p.getInventory());
}

/**
* Tests the setter for Player's Backorder.
*/


TEST(playerTest, setBackorderTest){

    Player p;
    p.setBackorder(20);
    EXPECT_EQ(20, p.getBackorder());
}

/**
* Tests the setter for Player's Cost.
*/


TEST(playerTest, setCostTest){

    Player p;
    p.setCost(30);
    EXPECT_EQ(30, p.getCost());
}

/**
* Tests the setter for Player's Inventory value.
*/
TEST(playerTest, setInventoryTest){

    Player p;
    p.setInventory(40);
    EXPECT_EQ(40, p.getInventory());
}

/**
* Tests the setter for Player's Demand value.
*/
TEST(playerTest, setDemandTest) {

    Player p;
    p.setDemand(3);
    EXPECT_EQ(3, p.getDemand());
}

/**
* Tests the getter for Player's Demand value.
*/
TEST(playerTest, getDemandTest) {

    Player p;
    p.setDemand(4);
    EXPECT_EQ(4, p.getDemand());
}

/**
* Tests the setter for Incoming Order.
*/
TEST(playerTest, setIncomingOrderTest) {

    Player p;
    p.setIncomingOrder(5);
    EXPECT_EQ(5, p.getIncomingOrder());
}

/**
* Tests the getter for Incoming Order.
*/
TEST(playerTest, getIncomingOrderTest) {

    Player p;
    p.setIncomingOrder(49);
    EXPECT_EQ(49, p.getIncomingOrder());
}

/**
* Tests the setter for Incoming Shipment.
*/
TEST(playerTest, setIncomingShipmentTest) {

    Player p;
    p.setIncomingShipment(45);
    EXPECT_EQ(45, p.getIncomingShipment());
}

/**
* Tests the getter for Incoming Shipment.
*/
TEST(playerTest, getIncomingShipmentTest) {

    Player p;
    p.setIncomingShipment(45);
    EXPECT_EQ(45, p.getIncomingShipment());
}

/**
* Tests the getter for Outgoing Shipment.
*/
TEST(playerTest, getOutgoingShipmentTest) {

    Player p;
    p.setOutgoingShipment(45);
    EXPECT_EQ(45, p.getOutgoingShipment());
}

/**
* Tests the setter for Total Cost.
*/
TEST(playerTest, setTotalCostTest) {

    Player p;
    p.setTotalCost(13);
    EXPECT_EQ(13, p.getTotalCost());
}

/**
* Tests the getter for Total Cost.
*/
TEST(playerTest, getTotalCostTest) {

    Player p;
    p.setTotalCost(4);
    EXPECT_EQ(4, p.getTotalCost());
}

/**
* Tests the setter for Order Received.
*/
TEST(playerTest, setOrderReceivedTest) {

    Player p;
    p.setOrderReceived(true);
    EXPECT_TRUE(p.getOrderReceived());
}

/**
* Tests the getter for Order Received.
*/
TEST(playerTest, getOrderReceivedTest) {

    Player p;
    EXPECT_FALSE(p.getOrderReceived());
}

/**
* Tests the setter for Shipment Received.
*/
TEST(playerTest, setShipmentReceivedTest) {

    Player p;
    p.setShipmentReceived(true);
    EXPECT_TRUE(p.getShipmentReceived());
}

/**
* Tests the getter for Shipment Received.
*/
TEST(playerTest, getShipmentReceivedTest) {

    Player p;
    EXPECT_EQ(false, p.getShipmentReceived());
}

/**
* Tests the getter for Order Placed.
*/
TEST(playerTest, getOrderPlacedTest) {

    Player p;
    EXPECT_EQ(false, p.getOrderPlaced());
}


/**
* Tests the setter for Order Placed.
*/
TEST(playerTest, setOrderPlacedTest) {

    Player p;
    p.setOrderPlaced(true);
    EXPECT_EQ(true, p.getOrderPlaced());
}


/**
* Tests the setter for Shipment Placed.
*/
TEST(playerTest, setShipmentPlacedTest) {

    Player p;
    p.setShipmentPlaced(true);
    EXPECT_EQ(true, p.getShipmentPlaced());
}


/**
* Tests the getter for Shipment Placed.
*/
TEST(playerTest, getShipmentPlacedTest) {

    Player p;
    EXPECT_EQ(false, p.getShipmentPlaced());
}

/**
* Tests if the getAvailableShipment returns the correct value or available items or not.
*/
TEST(playerTest, getAvailableShipmentTest) {

    Player p;
    p.setInventory(1);
    EXPECT_EQ(1, p.getAvailableShipment(15));
}

/**
* Tests if the inventory is being updated properly after we use getAvailableShipment or not.
*/

TEST(playerTest, getAvailableShipment_InventoryTest) {

    Player p;
    p.setInventory(20);
    p.getAvailableShipment(15);
    EXPECT_EQ(5, p.getInventory());
}

/**
* Tests if the backorder is being updated properly after we use getAvailableShipment or not.
*/

TEST(playerTest, getAvailableShipment_BackOrderTest) {

    Player p;
    p.setInventory(2);
    p.getAvailableShipment(5);
    EXPECT_EQ(3, p.getBackorder());
}


/**
* Tests if the setter for a Game
*/

TEST(playerTest, setGameTest) {

    Player p;
    Game g;
    p.setGame(&g);
    EXPECT_EQ(&g, p.getGame());
}

/**
* Tests the getter for a Game
*/

TEST(playerTest, getGameTest) {

    Game g1;
    Player p;
    p.setGame(&g1);
    EXPECT_EQ(&g1, p.getGame());
}

//tests for class Game


/**
* Tests the setter for Shipment Delay.
*/
TEST(gameTest, setShipmentDelayTest) {

    Game g;
    g.setShipmentDelay(3);
    EXPECT_EQ(3, g.getShipmentDelay());
}


/**
* Tests the getter for Shipment Delay.
*/
TEST(gameTest, getShipmentDelayTest) {

    Game g;
    g.setShipmentDelay(8);
    EXPECT_EQ(8, g.getShipmentDelay());
}

/**
* test setter for game ID
*/
TEST(gameTest, setGIdTest){

    Game g;
    g.setGId(34);
    EXPECT_EQ(34, g.getGId());
}

/**
* test getter for game ID
*/
TEST(gameTest, getGIdTest){

    Game g;
    g.setGId(6);
    EXPECT_EQ(6, g.getGId());
}

/**
* test setter for instructor ID
*/
TEST(gameTest, setInstrIdTest){

    Game g;
    g.setInstrId(20);
    EXPECT_EQ(20, g.getInstrId());
}

/**
* test getter for instructor ID
*/
TEST(gameTest, getInstrIdTest){

    Game g;
    g.setInstrId(2);
    EXPECT_EQ(2, g.getInstrId());
}

/**
* test setter for factory ID
*/
TEST(gameTest, setPFactIdTest){

    Game g;
    g.setPFactId(100);
    EXPECT_EQ(100, g.getPFactId());
}

/**
* test getter for factory ID
*/
TEST(gameTest, getPFactIdTest){

    Game g;
    g.setPFactId(1030);
    EXPECT_EQ(1030, g.getPFactId());
}

/**
* test getter for Distributor ID
*/
TEST(gameTest, getPDistributorIdTest){

    Game g;
    g.setPDistributorId(56);
    EXPECT_EQ(56, g.getPDistributorId());
}

/**
* test setter for Distributor ID
*/
TEST(gameTest, setPDistributorIdTest){

    Game g;
    g.setPDistributorId(45);
    EXPECT_EQ(45, g.getPDistributorId());
}

/**
* test getter for wholesaler ID
*/
TEST(gameTest, getPWholesalerIdTest){

    Game g;
    g.setPWholesalerId(56);
    EXPECT_EQ(56, g.getPWholesalerId());
}

/**
* test setter for wholesaler ID
*/
TEST(gameTest, setPWholesalerIdTest){

    Game g;
    g.setPWholesalerId(12);
    EXPECT_EQ(12, g.getPWholesalerId());
}

/**
* test setter for retailer ID
*/
TEST(gameTest, setPRetailerIdTest){

    Game g;
    g.setPRetailerId(24);
    EXPECT_EQ(24, g.getPRetailerId());
}

/**
* test getter for retailer ID
*/
TEST(gameTest, getPRetailerIdTest){

    Game g;
    g.setPRetailerId(24);
    EXPECT_EQ(24, g.getPRetailerId());
}

/**
* test getter for order time delay
*/
TEST(gameTest, getOrderDelayTest){

    Game g;
    g.setOrderDelay(3);
    EXPECT_EQ(3, g.getOrderDelay());
}

/**
* test setter for order time delay
*/
TEST(gameTest, setOrderDelayTest){

    Game g;
    g.setOrderDelay(4);
    EXPECT_EQ(4, g.getOrderDelay());
}

/**
* test advanceWeek method
*/
TEST(gameTest, advanceWeekTest){

    Game g;
    int currweek = g.getCurrentWeek();
    EXPECT_EQ(currweek+1, g.advanceWeek());
}

/**
* test setter for weeks to be played
*/
TEST(gameTest, setWeeksToBePlayedTest){

    Game g;
    g.setWeeksToBePlayed(2);
    EXPECT_EQ(2, g.getWeeksToBePlayed());
}

/**
* test getter for weeks to be played
*/
TEST(gameTest, getWeeksToBePlayedTest) {

    Game g;
    EXPECT_EQ(26, g.getWeeksToBePlayed()); //checking default value
    g.setWeeksToBePlayed(2);
    EXPECT_EQ(2, g.getWeeksToBePlayed());
}

/**
* test setter for information sharing code
*/
TEST(gameTest, setInfoCodeTest){

    Game g;
    g.setInfoCode(3);
    EXPECT_EQ(3, g.getInfoCode());
}

/**
* test getter for information sharing code
*/
TEST(gameTest, getInfoCodeTest) {

    Game g;
    g.setInfoCode(3);
    EXPECT_EQ(3, g.getInfoCode());
}

/**
* test setter for holding cost
*/
TEST(gameTest, setHoldingCostTest){

    Game g;
    g.setHoldingCost(6.3);
    EXPECT_EQ(6.3, g.getHoldingCost());
}

/**
* test getter for holding cost
*/
TEST(gameTest, getHoldingCostTest){

    Game g;
    EXPECT_EQ(0.5, g.getHoldingCost()); //checking default value
    g.setHoldingCost(9);
    EXPECT_EQ(9, g.getHoldingCost());
}

/**
* test setter for starting inventory
*/
TEST(gameTest, setStartingInventoryTest){

    Game g;
    g.setStartingInventory(4);
    EXPECT_EQ(4, g.getStartingInventory());
}

/**
* test getter for starting inventory
*/
TEST(gameTest, getStartingInventoryTest){

    Game g;
    EXPECT_EQ(12, g.getStartingInventory()); //checking default value
    g.setStartingInventory(14);
    EXPECT_EQ(14, g.getStartingInventory());
}

/**
* test getter for backorder cost
*/
TEST(gameTest, getBackorderCostTest){

    Game g;
    g.setBackorderCost(5.7);
    EXPECT_EQ(5.7, g.getBackorderCost());
}

/**
* test setter for backorder cost
*/
TEST(gameTest, setBackorderCostTest){

    Game g;
    g.setBackorderCost(1.7);
    EXPECT_EQ(1.7, g.getBackorderCost());
}

/**
* test getter for current week
*/
TEST(gameTest, getCurrentWeekTest) {

    Game g;
    EXPECT_EQ(0, g.getCurrentWeek()); //checking default value
    g.setCurrentWeek(5);
    EXPECT_EQ(5, g.getCurrentWeek());
}

/**
* sest getter for current week
*/
TEST(gameTest, setCurrentWeekTest) {

    Game g;
    g.setCurrentWeek(1);
    EXPECT_EQ(1, g.getCurrentWeek());
}

/**
* test getter for Factory Delay
*/
TEST(gameTest, getFactoryDelayTest) {

    Game g;
    EXPECT_EQ(1, g.getFactoryDelay());
}

/**
* test setter for Factory Delay
*/
TEST(gameTest, setFactoryDelayTest) {

    Game g;
    g.setFactoryDelay(13);
    EXPECT_EQ(13, g.getFactoryDelay());
}

/**
* test setter for Number of Players
*/
TEST(gameTest, setNumberOfPlayersTest) {

    Game g;
    g.setNumberOfPlayers(4);
    EXPECT_EQ(4, g.getNumberOfPlayers());
}

/**
* test getter for Number of Players
*/
TEST(gameTest, getNumberOfPlayersTest) {

    Game g;
    g.setNumberOfPlayers(1);
    EXPECT_EQ(1, g.getNumberOfPlayers());
}

/**
* Tests for the generatePasswords method. This consists of three different tests:
* 1. It checks if there are exactly 4 passwords generated or not.
* 2. It checks if the length of each password is 10 or not.
* 3. It checks if each generated password only consists of the characters allowed in the alphaNum array or not.
*/

TEST(gameTest, generatePasswordsTest) {
    Game g;
    static const char allowedCharacters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";
    std::string alphan(allowedCharacters);
    std::vector<std::string> passwordsSet = g.generatePasswords();

    EXPECT_EQ(passwordsSet.size(), 4);

    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(passwordsSet[i].length(), 10);
    }

    for (std::string const &s : passwordsSet) {
        for (char const &c : s) {
            EXPECT_NE(alphan.find(c), std::string::npos);
        }
    }
}

/**
* test getter for Number of Players
*/
// TEST(gameTest, setPlayersTest) {
//     Player* p;
//     Game g;
//     (*p).setRole(2);
//     g.setPlayers(&p, p->getRole()-1);
//     EXPECT_EQ(1,g->(players[1])->getRole());
// }


// Instructor Class Test Cases

/**
* Tests the setter for Instructor's Email.
*/
TEST(instructorTest, setInstrEmailTest){

    Instructor i;
    i.setInstrEmail("hi.there@jacobs-university.de");
    EXPECT_EQ("hi.there@jacobs-university.de", i.getInstrEmail());
}

/**
* Tests the getter for Instructor's Email.
*/
TEST(instructorTest, getInstrEmailTest){

  Instructor i;
  i.setInstrEmail("hi.again@jacobs-university.de");
  std::string email = "hi.again@jacobs-university.de";
  EXPECT_EQ( email, i.getInstrEmail());
}

/**
* Tests the setter for Instructor's Password.
*/
TEST(instructorTest, setInstrPasswordTest){

    Instructor i;
    i.setInstrPassword("superstrongpassword");
    EXPECT_EQ("superstrongpassword", i.getInstrPassword());
}

/**
* Tests the getter for Instructor's Password.
*/
TEST(instructorTest, getInstrPasswordTest){

  Instructor i;
  i.setInstrPassword("weakpassword");
  EXPECT_EQ("weakpassword", i.getInstrPassword());
}

/**
* Tests the setter for Instructor's Id.
*/
TEST(instructorTest, setInstrIdTest){

  Instructor i;
  i.setInstrId(2020);
  EXPECT_EQ(2020, i.getInstrId());
}

/**
* Tests the getter for Instructor's Id.
*/
TEST(instructorTest, getInstrIdTest){

  Instructor i;
  i.setInstrId(30);
  EXPECT_EQ(30, i.getInstrId());
}

/**
* Tests the createGame method by checking if the returned game Id value coressponds to the default value set or not.
*/

TEST(instructorTest, createGameTest){

  Instructor i;
  EXPECT_NE(0, i.createGame());
}

/**
* Tests the createGames method by checking if the number of games presented in the games vector coressponds to the number of games we wished to create.
*/
TEST(instructorTest, createGamesTest){

  Instructor i;
  i.createGames(10);
  EXPECT_EQ(10, i.checkGameVectorSize());
}

// PlayerEvent Class Test Cases

/**
* Tests the setter for Player's Event Id.
*/
TEST(playerEventTest, setEventIdTest){

    PlayerEvent pe;
    pe.setEventId(32);
    EXPECT_EQ(32, pe.getEventId());
}

/**
* Tests the getter for Player's Event Id.
*/
TEST(playerEventTest, getEventIdTest){

    PlayerEvent pe;
    pe.setEventId(12);
    EXPECT_EQ(12, pe.getEventId());
}

/**
* Tests the getter for Game Id.
*/
TEST(playerEventTest, getGIdTest){

    PlayerEvent pe;
    pe.setGId(53);
    EXPECT_EQ(53, pe.getGId());
}

/**
* Tests the setter for Game Id.
*/
TEST(playerEventTest, setGIdTest){

    PlayerEvent pe;
    pe.setGId(13);
    EXPECT_EQ(13, pe.getGId());
}

/**
* Tests the getter for the Player Id who will deliver the order.
*/
TEST(playerEventTest, getFromPlayerIdTest){

    PlayerEvent pe;
    pe.setFromPlayerId(4775);
    EXPECT_EQ(4775, pe.getFromPlayerId());
}

/**
* Tests the setter for the Player Id who will deliver the order.
*/
TEST(playerEventTest, setFromPlayerIdTest){

    PlayerEvent pe;
    pe.setFromPlayerId(5323);
    EXPECT_EQ(5323, pe.getFromPlayerId());
}

/**
* Tests the getter for the Player Id who will recieve the order.
*/
TEST(playerEventTest, getToPlayerIdTest){

    PlayerEvent pe;
    pe.setToPlayerId(424);
    EXPECT_EQ(424, pe.getToPlayerId());
}

/**
* Tests the setter for the Player Id who will recieve the order.
*/
TEST(playerEventTest, setToPlayerIdTest){

    PlayerEvent pe;
    pe.setToPlayerId(42);
    EXPECT_EQ(42, pe.getToPlayerId());
}

/**
* Tests the getter for the Week number when the order was placed.
*/

TEST(playerEventTest, getOrderedInWeekTest){

    PlayerEvent pe;
    pe.setOrderedInWeek(5);
    EXPECT_EQ(5, pe.getOrderedInWeek());
}

/**
* Tests the setter for the Week number when the order was placed.
*/

TEST(playerEventTest, setOrderedInWeekTest){

    PlayerEvent pe;
    pe.setOrderedInWeek(2);
    EXPECT_EQ(2, pe.getOrderedInWeek());
}


/**
* Tests the getter for the Week number when the order was shipped.
*/
TEST(playerEventTest, getShippedInWeekTest){

    PlayerEvent pe;
    pe.setShippedInWeek(4);
    EXPECT_EQ(4, pe.getShippedInWeek());
}

/**
* Tests the setter for the Week number when the order was shipped.
*/
TEST(playerEventTest, setShippedInWeekTest){

    PlayerEvent pe;
    pe.setShippedInWeek(3);
    EXPECT_EQ(3, pe.getShippedInWeek());
}

/**
* Tests the setter for the number of beer units.
*/

TEST(playerEventTest, setNumberOfBeersTest){

    PlayerEvent pe;
    pe.setNumberOfBeers(20);
    EXPECT_EQ(20, pe.getNumberOfBeers());
}

/**
* Tests the getter for the number of beer units.
*/

TEST(playerEventTest, getNumberOfBeersTest){

    PlayerEvent pe;
    pe.setNumberOfBeers(100);
    EXPECT_EQ(100, pe.getNumberOfBeers());
}

/**
* Tests the setter for receiver Player
*/

TEST(playerEventTest, setReceiverTest) {

    Player p;
    PlayerEvent pe;
    pe.setReceiver(&p);
    EXPECT_EQ(&p, pe.getReceiver());
}

/**
* Tests the getter for receiver Player
*/

TEST(playerTest, getReceiverTest) {

    PlayerEvent pe;
    Player p;
    pe.setReceiver(&p);
    EXPECT_EQ(&p, pe.getReceiver());
}

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
