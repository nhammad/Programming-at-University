/**
* \author nhammad, dorab
* \date 17.03.2020
*/

/// \file

#include "gtest/gtest.h"
#include "./src/Factory.h"
#include "./src/Player.h"
#include "./src/Instructor.h"
#include "./src/Order.h"
#include "./src/Game.h"
#include <string>
#include <vector>

/**
* Player Class Tests
*/

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

TEST(playerTest, decreaseInventoryTest ) {

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
* Tests the setter for Player's OrderPlaced value.
*/

TEST(playerTest, setOrderPlacedTest) {

    Player p;
    p.setOrderPlaced(3);
    EXPECT_EQ(3, p.getOrderPlaced());
    p.setOrderPlaced(5);
    EXPECT_EQ(5, p.getOrderPlaced());
}

/**
* Tests the getter for Player's OrderPlaced value.
*/

TEST(playerTest, getOrderPlacedTest) {

    Player p;
    p.setOrderPlaced(10);
    EXPECT_EQ(10, p.getOrderPlaced());
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
* Tests the ship() method, which moves beer units from Player1's 
* inventory to Player2's inventory.
*/

TEST(playerTest, shipTest) {

    Player p1, p2;
    p1.setInventory(10);
    p2.setInventory(10);
    p1.ship(4, p2);
    EXPECT_EQ(6, p1.getInventory());
    EXPECT_EQ(14, p2.getInventory());
}

/**
* Tests the order() method, which moves beer units from Player2's 
* inventory to Player1's inventory.
*/

TEST(playerTest, orderTest) {

    Player p1, p2;
    p1.setInventory(10);
    p2.setInventory(10);
    p1.order(4, p2);
    EXPECT_EQ(14, p1.getInventory());
    EXPECT_EQ(6, p2.getInventory());;
}

/**
* Game Class Tests
*/

/**
* test setter for shipment delay
*/
TEST(gameTest, setShipmentDelayTest) {

    Game g;
    g.setShipmentDelay(3);
    EXPECT_EQ(3, g.getShipmentDelay());
}

/**
* test getter for shipment delay
*/
TEST(gameTest, getShipmentDelayTest) {

    Game g;
    g.setShipmentDelay(8);
    EXPECT_EQ(8, g.getShipmentDelay());
}

/**
* test setter for order delay
*/
TEST(gameTest, setOrderDelayTest) {

    Game g;
    g.setOrderDelay(3);
    EXPECT_EQ(3, g.getOrderDelay());
}

/**
* test getter for order delay
*/
TEST(gameTest, getOrderDelayTest) {

    Game g;
    g.setOrderDelay(10);
    EXPECT_EQ(10, g.getOrderDelay());
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
* test getter for distributor ID
*/
TEST(gameTest, getPDistributorIdTest){

    Game g;
    g.setPDistributorId(56);
    EXPECT_EQ(56, g.getPDistributorId());
}

/**
* test setter for distributor ID
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
    g.setRetailerId(24);
    EXPECT_EQ(24, g.getRetailerId());
}

/**
* test getter for retailer ID
*/
TEST(gameTest, getPRetailerIdTest){

    Game g;
    g.setRetailerId(24);
    EXPECT_EQ(24, g.getRetailerId());
}

/**
* test getter for order time delay
*/
TEST(gamTest, getOrderTimeDelayTest){

    Game g;
    g.setOrderTimeDelay(3);
    EXPECT_EQ(3, g.getOrderTimeDelay());
}

/**
* test setter for order time delay
*/
TEST(gamTest, setOrderTimeDelayTest){

    Game g;
    g.setOrderTimeDelay(4);
    EXPECT_EQ(4, g.getOrderTimeDelay());
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
    g.setweeksToBePlayed(2);
    EXPECT_EQ(2, g.getWeeksToBePlayed());
}

/**
* test getter for weeks to be played
*/
TEST(gameTest, getWeeksToBePlayedTest) {

    Game g;
    EXPECT_EQ(26, g.getWeeksToBePlayed()); //checking default value
    g.setweeksToBePlayed(2);
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

/**test getter for starting inventory
* 
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
* test getter for current week
*/
TEST(gameTest, getCurrentWeekTest) {

    Game g;
    EXPECT_EQ(0, g.getCurrentWeek()); //checking default value
    g.setCurrentWeek(5);
    EXPECT_EQ(5, g.getCurrentWeek());
}

/**
* test setter for current week
*/
TEST(gameTest, setCurrentWeekTest) {

    Game g;
    g.setCurrentWeek(1);
    EXPECT_EQ(1, g.getCurrentWeek());
}
/**
* Test generation of passwords
*/
TEST(gameTest, generatePasswordsTest) {
    Game g;

    // set list of possible chars
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string alphan(alphanum);

    // get generated passwods
    vector<string> passwords = g.generatePasswords();

    // assert there are 4 passwords
    EXPECT_EQ(passwords.size(), 4);

    // assert each password is 10 chars long
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(passwords[i].length(), 10);
    }

    // assert that each password contains only allowed chars
    for (string const &s : passwords) {
        for (char const &c : s) {
            EXPECT_NE(alphan.find(c), string::npos);
        }

    }
}

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
  string email = "hi.again@jacobs-university.de";
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
* Tests the getter for Instructor's Email.
*/

TEST(instructorTest, getInstrIdTest){

  Instructor i;
  i.setInstrId(30);
  EXPECT_EQ(30, i.getInstrId());
}

// Order Class Test Cases

/**
* Tests the getter for Order Id.
*/

TEST(orderTest, getOrderIdTest){

    Order o;
    o.setOrderId(23);
    EXPECT_EQ(23, o.getOrderId());
}

/**
* Tests the setter for Order Id.
*/

TEST(orderTest, setOrderIdTest){

    Order o;
    o.setOrderId(32);
    EXPECT_EQ(32, o.getOrderId());
}

/**
* Tests the getter for Game Id.
*/
TEST(orderTest, getGIdTest){

    Order o;
    o.setGId(53);
    EXPECT_EQ(53, o.getGId());
}

/**
* Tests the setter for Game Id.
*/
TEST(orderTest, setGIdTest){

    Order o;
    o.setGId(13);
    EXPECT_EQ(13, o.getGId());
}

/**
* Tests the getter for the Player Id who will deliver the order.
*/

TEST(orderTest, getFromPlayerIdTest){

    Order o;
    o.setFromPlayerId(4775);
    EXPECT_EQ(4775, o.getFromPlayerId());
}

/**
* Tests the setter for the Player Id who will deliver the order.
*/

TEST(orderTest, setFromPlayerIdTest){

    Order o;
    o.setFromPlayerId(5323);
    EXPECT_EQ(5323, o.getFromPlayerId());
}

/**
* Tests the getter for the Player Id who will recieve the order.
*/

TEST(orderTest, getToPlayerIdTest){

    Order o;
    o.setToPlayerId(424);
    EXPECT_EQ(424, o.getToPlayerId());
}

/**
* Tests the getter for the Player Id who will deliver the order.
*/

TEST(orderTest, setToPlayerIdTest){

    Order o;
    o.setToPlayerId(42);
    EXPECT_EQ(42, o.getToPlayerId());
}

/**
* Tests the getter for the Week number when the order was placed.
*/

TEST(orderTest, getOrderedInWeekTest){

    Order o;
    o.setOrderedInWeek(5);
    EXPECT_EQ(5, o.getOrderedInWeek());
}

/**
* Tests the setter for the Week number when the order was placed.
*/

TEST(orderTest, setOrderedInWeekTest){

    Order o;
    o.setOrderedInWeek(2);
    EXPECT_EQ(2, o.getOrderedInWeek());
}

/**
* Tests the getter for the Week number when the order was shipped.
*/

TEST(orderTest, getShippedInWeekTest){

    Order o;
    o.setShippedInWeek(4);
    EXPECT_EQ(4, o.getShippedInWeek());
}

/**
* Tests the setter for the Week number when the order was shipped.
*/

TEST(orderTest, setShippedInWeekTest){

    Order o;
    o.setShippedInWeek(3);
    EXPECT_EQ(3, o.getShippedInWeek());
}


/**
* Tests the setter for the number of beer units.
*/

TEST(orderTest, setNumberOfBeersTest){

    Order o;
    o.setNumberOfBeers(20);
    EXPECT_EQ(20, o.getNumberOfBeers());
}

/**
* Tests the getter for the number of beer units.
*/

TEST(orderTest, getNumberOfBeersTest){

    Order o;
    o.setNumberOfBeers(11);
    EXPECT_EQ(11, o.getNumberOfBeers());
}

// Factory Class Test Cases

/**
* Tests the produce() method from Factory, which generates beer units
* and adds them into the produced attribute. 
*/

TEST(factoryTest, produceTest){

    Factory f;
    f.produce(15);
    f.produce(20);
    EXPECT_EQ(35, f.getProduced());
}

/**
* Tests the setter for the attribute produced: i.e how many beer units
* are produced already.
*/

TEST(factoryTest, setProducedTest){

    Factory f;
    f.setProduced(10);
    EXPECT_EQ(10, f.getProduced());
}

/**
* Tests the getter for the attribute produced: i.e how many beer units
* are produced already.
*/

TEST(factoryTest, getProducedTest){

    Factory f;
    EXPECT_EQ(0, f.getProduced());
}

/**
* Tests the setter for the attribute productionTime: i.e how much time 
* it takes for the production of a batch.
*/

TEST(factoryTest, setProductionTimeTest){

    Factory f;
    f.setProductionTime(3);
    EXPECT_EQ(3, f.getProductionTime());
}

/**
* Tests the getter for the attribute productionTime: i.e how much time 
* it takes for the production of a batch.
*/

TEST(factoryTest, getProductionTimeTest){

    Factory f;
    EXPECT_EQ(2, f.getProductionTime());
}

/**
* Runs all the Google Tests.
*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
