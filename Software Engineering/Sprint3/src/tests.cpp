#include "gtest/gtest.h"
#include "Player.h"
#include "PlayerEvent.h"
#include "Game.h"
#include "Instructor.h"

// Tests for class Player

/**
* Tests the setter for Player Id.
*/

TEST(playerTest, setPIdTest)
{

    Player p;
    p.setPId(2);
    EXPECT_EQ(2, p.getPId());
}

/**
* Tests the getter for Player Id.
*/

TEST(playerTest, getPIdTest)
{

    Player p;
    p.setPId(25);
    EXPECT_EQ(25, p.getPId());
}

/**
* Tests the setter for Player Role.
*/
TEST(playerTest, setRoleTest)
{

    Player p;
    p.setRole(1);
    EXPECT_EQ(1, p.getRole());
}

/**
* Tests the getter for Player Role.
*/
TEST(playerTest, getRoleTest)
{

    Player p;
    p.setRole(2);
    EXPECT_EQ(2, p.getRole());
}

/**
* Tests the decreaseInventory() method from the Player class.
*/
TEST(playerTest, decreaseInventoryTest)
{

    Player p;
    int curr_inv = p.getInventory();
    EXPECT_EQ(curr_inv - 3, p.decreaseInventory(3));
}

/**
* Tests the increaseInventory() method from the Player class.
*/
TEST(playerTest, increaseInventoryTest)
{

    Player p;
    int curr_inv = p.getInventory();
    EXPECT_EQ(curr_inv + 3, p.increaseInventory(3));
}

/**
* Tests the getter for Player's Backorder.
*/

TEST(playerTest, getBackorderTest)
{

    Player p;
    p.setBackorder(10);
    EXPECT_EQ(10, p.getBackorder());
}

/**
* Tests the getter for Player's Cost.
*/
TEST(playerTest, getCostTest)
{

    Player p;
    p.setCost(2);
    EXPECT_EQ(2, p.getCost());
}

/**
* Tests the getter for Player's Inventory value.
*/
TEST(playerTest, getInventoryTest)
{

    Player p;
    p.setInventory(10000);
    EXPECT_EQ(10000, p.getInventory());
}

/**
* Tests the setter for Player's Backorder.
*/

TEST(playerTest, setBackorderTest)
{

    Player p;
    p.setBackorder(20);
    EXPECT_EQ(20, p.getBackorder());
}

/**
* Tests the setter for Player's Cost.
*/
TEST(playerTest, setCostTest)
{

    Player p;
    p.setCost(30);
    EXPECT_EQ(30, p.getCost());
}

/**
* Tests the setter for Player's Inventory value.
*/
TEST(playerTest, setInventoryTest)
{

    Player p;
    p.setInventory(40);
    EXPECT_EQ(40, p.getInventory());
}

/**
* Tests the setter for Player's Demand value.
*/

TEST(playerTest, setDemandTest)
{

    Player p;
    p.setDemand(3);
    EXPECT_EQ(3, p.getDemand());
}

/**
* Tests the getter for Player's Demand value.
*/
TEST(playerTest, getDemandTest)
{

    Player p;
    p.setDemand(4);
    EXPECT_EQ(4, p.getDemand());
}

/**
* Tests if the getAvailableShipment returns the correct value or available items or not. When Demand > Inventory.
*/
TEST(playerTest, getAvailableShipmentTest) {

    Player p;
    p.setInventory(1);
    EXPECT_EQ(1, p.getAvailableShipment(15));
}

/**
* Tests if the getAvailableShipment returns the correct value or available items or not. When Demand < Inventory.
*/
TEST(playerTest, getAvailableShipment2Test) {

    Player p;
    p.setInventory(20);
    EXPECT_EQ(3, p.getAvailableShipment(3));
}

/**
* Tests the setter for receiveOrder() method.
*/
TEST(playerTest, receiveOrderTest) {

    Player p;
    p.receiveOrder(14);
    EXPECT_EQ(true, p.getOrderReceived());
}

/**
* Tests the setter for receiveShipment() method.
*/
TEST(playerTest, receiveShipmentTest) {

    Player p;
    p.receiveShipment(1500);
    EXPECT_EQ(true, p.getShipmentReceived());
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
* Tests the placeOrder() method
*/
TEST(playerTest, placeOrderTest) {

    Order ord;
    ord.setNumberOfBeers(12);
    Game g;
    g.setGId(1);

    Player p1, p2, p3;
    p1.setRole(0);
    p2.setRole(1);
    p3.setRole(2);

    std::vector<Player*> v;
    g.setPlayers(v);
    g.addPlayer(&p1);
    g.addPlayer(&p2);
    g.addPlayer(&p3);
    p2.placeOrder(12);
    EXPECT_TRUE(p2.getOrderPlaced());

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
* Tests the setter for Outgoing Shipment.
*/
TEST(playerTest, setOutgoingShipmentTest) {

    Player p;
    p.setOutgoingShipment(48);
    EXPECT_EQ(48, p.getOutgoingShipment());
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
* Tests the factoryProduce() method used by the Factory to
* create beer units in the first place
*/
TEST(playerTest, getfactoryProduceTest) {

    Player p;
    int inventory = p.factoryProduce(15);
    EXPECT_EQ(15, inventory);
}


TEST(playerTest, placeShipmentTest) {

    Game g;
    g.setStartingInventory(100);
    Player p(1,2, &g);
    p.setInventory(100);
    p.placeShipment(20);
    EXPECT_EQ(100-20, p.getInventory());

}




//tests for class Game

/**
* Tests the setter for Shipment Delay.
*/
TEST(gameTest, setShipmentDelayTest)
{

    Game g;
    g.setShipmentDelay(3);
    EXPECT_EQ(3, g.getShipmentDelay());
}

/**
* Tests the getter for Shipment Delay.
*/
TEST(gameTest, getShipmentDelayTest)
{

    Game g;
    g.setShipmentDelay(8);
    EXPECT_EQ(8, g.getShipmentDelay());
}

/**
* test setter for order time delay
*/
TEST(gameTest, setOrderDelayTest)
{

    Game g;
    g.setOrderDelay(3);
    EXPECT_EQ(3, g.getOrderDelay());
}

/**
* test getter for order time delay
*/
TEST(gameTest, getOrderDelayTest)
{

    Game g;
    g.setOrderDelay(10);
    EXPECT_EQ(10, g.getOrderDelay());
}

/**
* Tests the setter for Game Id.
*/
TEST(gameTest, setGIdTest)
{

    Game g;
    g.setGId(34);
    EXPECT_EQ(34, g.getGId());
}

/**
* Tests the getter for Game Id.
*/
TEST(gameTest, getGIdTest)
{

    Game g;
    g.setGId(6);
    EXPECT_EQ(6, g.getGId());
}

/**
* test setter for instructor ID
*/
TEST(gameTest, setInstrIdTest)
{

    Game g;
    g.setInstrId(20);
    EXPECT_EQ(20, g.getInstrId());
}

/**
* test getter for instructor ID
*/
TEST(gameTest, getInstrIdTest)
{

    Game g;
    g.setInstrId(2);
    EXPECT_EQ(2, g.getInstrId());
}

/**
* test setter for factory ID
*/
TEST(gameTest, setPFactIdTest)
{

    Game g;
    g.setPFactId(100);
    EXPECT_EQ(100, g.getPFactId());
}

/**
* test getter for factory ID
*/
TEST(gameTest, getPFactIdTest)
{

    Game g;
    g.setPFactId(1030);
    EXPECT_EQ(1030, g.getPFactId());
}

/**
* test getter for Distributor ID
*/
TEST(gameTest, getPDistributorIdTest)
{

    Game g;
    g.setPDistributorId(56);
    EXPECT_EQ(56, g.getPDistributorId());
}

/**
* test setter for Distributor ID
*/
TEST(gameTest, setPDistributorIdTest)
{

    Game g;
    g.setPDistributorId(45);
    EXPECT_EQ(45, g.getPDistributorId());
}

/**
* test getter for wholesaler ID
*/
TEST(gameTest, getPWholesalerIdTest)
{

    Game g;
    g.setPWholesalerId(56);
    EXPECT_EQ(56, g.getPWholesalerId());
}

/**
* test setter for wholesaler ID
*/
TEST(gameTest, setPWholesalerIdTest)
{

    Game g;
    g.setPWholesalerId(12);
    EXPECT_EQ(12, g.getPWholesalerId());
}


/**
* test setter for retailer ID
*/
TEST(gameTest, setPRetailerIdTest)
{

    Game g;
    g.setPRetailerId(24);
    EXPECT_EQ(24, g.getPRetailerId());
}


/**
* test getter for retailer ID
*/
TEST(gameTest, getPRetailerIdTest)
{

    Game g;
    g.setPRetailerId(24);
    EXPECT_EQ(24, g.getPRetailerId());
}

/**
* test advanceWeek method
*/
TEST(gameTest, advanceWeekTest)
{

    Game g;
    int currweek = g.getCurrentWeek();
    EXPECT_EQ(currweek + 1, g.advanceWeek());
}

/**
* test setter for weeks to be played
*/
TEST(gameTest, setWeeksToBePlayedTest)
{

    Game g;
    g.setWeeksToBePlayed(2);
    EXPECT_EQ(2, g.getWeeksToBePlayed());
}

/**
* test getter for weeks to be played
*/
TEST(gameTest, getWeeksToBePlayedTest)
{

    Game g;
    EXPECT_EQ(26, g.getWeeksToBePlayed()); //checking default value
    g.setWeeksToBePlayed(2);
    EXPECT_EQ(2, g.getWeeksToBePlayed());
}

/**
* test setter for information sharing code
*/
TEST(gameTest, setInfoCodeTest)
{

    Game g;
    g.setInfoCode(3);
    EXPECT_EQ(3, g.getInfoCode());
}

/**
* test getter for information sharing code
*/
TEST(gameTest, getInfoCodeTest)
{

    Game g;
    g.setInfoCode(3);
    EXPECT_EQ(3, g.getInfoCode());
}

/**
* test setter for holding cost
*/
TEST(gameTest, setHoldingCostTest)
{

    Game g;
    g.setHoldingCost(6.3);
    EXPECT_EQ(6.3, g.getHoldingCost());
}

/**
* test getter for holding cost 
*/
TEST(gameTest, getHoldingCostTest)
{

    Game g;
    EXPECT_EQ(0.5, g.getHoldingCost()); 
    g.setHoldingCost(9);
    EXPECT_EQ(9, g.getHoldingCost());
}

/**
* test setter for starting inventory
*/
TEST(gameTest, setStartingInventoryTest)
{

    Game g;
    g.setStartingInventory(4);
    EXPECT_EQ(4, g.getStartingInventory());
}

/**
* test getter for starting inventory
*/
TEST(gameTest, getStartingInventoryTest)
{

    Game g;
    EXPECT_EQ(12, g.getStartingInventory()); //checking default value
    g.setStartingInventory(14);
    EXPECT_EQ(14, g.getStartingInventory());
}

/**
* test getter for backorder cost
*/
TEST(gameTest, getBackorderCostTest)
{

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
TEST(gameTest, getCurrentWeekTest)
{

    Game g;
    EXPECT_EQ(0, g.getCurrentWeek()); //checking default value
    g.setCurrentWeek(5);
    EXPECT_EQ(5, g.getCurrentWeek());
}

/**
* test setter for current week
*/
TEST(gameTest, setCurrentWeekTest)
{

    Game g;
    g.setCurrentWeek(1);
    EXPECT_EQ(1, g.getCurrentWeek());
}

/**
* test setter for ordersToBeExecuted, which is an unordered map.
*/
TEST(gameTest, setOrdersToBeExecutedTest)
{
    Order ord;
    Game g;
    std::vector<Order> v;
    std::unordered_map<int, std::vector<Order>> mp;

    ord.setOrderId(123);
    v.push_back(ord);
    mp[0] = v;
    g.setOrdersToBeExecuted(mp);
    EXPECT_EQ(123, g.getOrdersToBeExecuted()[0][0].getOrderId());
}

/**
* test getter for ordersToBeExecuted, which is an unordered map.
*/
TEST(gameTest, getOrdersToBeExecutedTest)
{
    Order ord;
    Game g;
    std::vector<Order> v;
    std::unordered_map<int, std::vector<Order>> mp;

    ord.setOrderId(225);
    v.push_back(ord);
    mp[0] = v;
    g.setOrdersToBeExecuted(mp);
    EXPECT_EQ(225, g.getOrdersToBeExecuted()[0][0].getOrderId());
}


/**
* test setter for shipmentsToBeExecuted, which is an unordered map.
*/
TEST(gameTest, setShipmentsToBeExecutedTest)
{
    Shipment ship;
    Shipment ship2;
    Game g;
    std::vector<Shipment> v(0);
    std::unordered_map<int, std::vector<Shipment>> mp;

    ship.setShipmentId(19);
    ship2.setShipmentId(29);
    v.push_back(ship);
    v.push_back(ship2);

    mp.emplace(0, v);

    g.setShipmentsToBeExecuted(mp);
    EXPECT_EQ(19, g.getShipmentsToBeExecuted()[0][0].getShipmentId());
    EXPECT_EQ(29, g.getShipmentsToBeExecuted()[0][1].getShipmentId());

}

/**
* tests getter for shipmentsToBeExecuted, which is an unordered map.
*/
TEST(gameTest, getShipmentsToBeExecutedTest)
{
    Shipment ship;
    Game g;
    std::vector<Shipment> v;
    std::unordered_map<int, std::vector<Shipment>> mp;


    ship.setShipmentId(19);
    v.push_back(ship);
    
    mp.emplace(0, v);
    mp[0] = v;
    

    g.setShipmentsToBeExecuted(mp);
    EXPECT_EQ(19, g.getShipmentsToBeExecuted()[0][0].getShipmentId());
}

/**
* test setter for players where players is a vector
*/
TEST(gameTest, setPlayersTest)
{
    Game g;
    Player *p1, *p2;
    std::vector<Player*> v;
    v.push_back(p1);
    v.push_back(p2);
    
    g.setPlayers(v);
    std::vector<Player *> players = g.getPlayers();
    EXPECT_EQ(2, players.size());
}

/**
* tests  getter for players where players is a vector
*/
TEST(gameTest, getPlayersTest)
{
    Game g;
    Player *p1, *p2, *p3;
    std::vector<Player*> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    g.setPlayers(v);
    EXPECT_EQ(3, (g.getPlayers()).size());
}

/**
* test setter for ConsumerDemandPerWeek()
*/
TEST(gameTest, setConsumerDemandPerWeekTest)
{
    Game g;
    int d = 5;

    std::vector<int> v;
    v.push_back(d);

    g.setConsumerDemandPerWeek(v);

    EXPECT_EQ(5, g.getConsumerDemandPerWeek()[0]);

}

/**
* test getter for ConsumerDemandPerWeek()
*/
TEST(gameTest, getConsumerDemandPerWeekTest)
{
    Game g;
    int d = 5;

    std::vector<int> v;
    v.push_back(d);

    g.setConsumerDemandPerWeek(v);

    EXPECT_EQ(5, g.getConsumerDemandPerWeek()[0]);
}


/**
* test setter for Factory Delay
*/
TEST(gameTest, setFactoryDelayTest)
{
    Game g;
    g.setFactoryDelay(23);
    EXPECT_EQ(23, g.getFactoryDelay());
}

/**
* test getter for Factory Delay
*/
TEST(gameTest, getFactoryDelayTest)
{
    Game g;
    EXPECT_EQ(1, g.getFactoryDelay()); //checking default value
    g.setFactoryDelay(5);
    EXPECT_EQ(5, g.getFactoryDelay());
}

/**
* test setter for Number of Players
*/
TEST(gameTest, setNumberOfPlayersTest)
{
    Game g;
    g.setNumberOfPlayers(3);
    EXPECT_EQ(3, g.getNumberOfPlayers());
}

/**
* test getter for Number of Players
*/
TEST(gameTest, getNumberOfPlayersTest)
{
    Game g;
    g.setNumberOfPlayers(4);
    EXPECT_EQ(4, g.getNumberOfPlayers());
}

/**
* test setter for gameStarted parameter
*/
TEST(gameTest, setGameStartedTest)
{
    Game g;
    g.startGame();
    EXPECT_EQ(true, g.getGameStarted());
}

/**
* test getter for gameStarted parameter
*/
TEST(gameTest, getGameStartedTest)
{
    Game g;
    EXPECT_EQ(false, g.getGameStarted());
}

//In executeOrdersForCurrentWeek, the Order objects in the map ordersToBeExecuted are executed (the method
// executeOrder for each object is called)
TEST(gameTest, executeOrdersForCurrentWeekTest)
{
    Game g;
    g.executeOrdersForCurrentWeek();
}

//In executeShipmentsForCurrentWeek, the Shipment objects in the map setShipmentsToBeExecuted are executed (the method
// executeShipment for each object is called)
TEST(gameTest, executeShipmentsForCurrentWeekTest)
{
}


/**
* test method ConsumerOrderForWeek()
*/
TEST(gameTest, getConsumerOrderForWeekTest)
{
    Game g;
    std::vector<int> v; //dummy vector with some demands
    v.push_back(3);
    v.push_back(5);
    g.setConsumerDemandPerWeek(v);
    
    EXPECT_EQ(3, g.getConsumerDemandPerWeek()[0]);
    EXPECT_EQ(5, g.getConsumerDemandPerWeek()[1]);
}


/**
* test the addOrder() method which puts orders into an unordered map
*/

TEST(gameTest, addOrderTest)
{
     Order ord;
    ord.setNumberOfBeers(12);
    Game g;
    g.setGId(1);

    Player p1, p2, p3;
    p1.setPId(12);
    p1.setRole(0);
    p2.setPId(13);
    p2.setRole(1);
    p2.setOrderPlaced(12);
    p3.setRole(2);

    std::vector<Player*> v;
    g.setPlayers(v);
    g.addPlayer(&p1);
    g.addPlayer(&p2);
    g.addPlayer(&p3);
    g.addOrder(p2.getRole(), p2.getOrderPlaced());
    EXPECT_EQ(1, (g.getOrdersToBeExecuted()).size());

    // Order ord;
    // Game g;
    // Player p1;
    // p1.setRole(1);
    // p1.setOrderPlaced(25);
    // std::vector<Order> v;
    // std::map<int, std::vector<Order>> mp;

    
    // mp[0] = v;
    // g.setOrdersToBeExecuted(mp);
    // g.addOrder(p1.getRole(), p1.getOrderPlaced());
    // EXPECT_EQ(25, g.getOrdersToBeExecuted()[0][0].getNumberOfBeers());
}
/**
* test the addShipment() method which puts orders into an unordered map
*/

TEST(gameTest, addShipmentTest)
{
    Shipment ship;
    ship.setNumberOfBeers(12);
    Game g;
    g.setGId(1);

    Player p1, p2, p3;
    p1.setPId(12);
    p1.setRole(0);
    p2.setPId(13);
    p2.setRole(1);
    p2.setOrderPlaced(12);
    p3.setRole(2);

    std::vector<Player*> v;
    g.setPlayers(v);
    g.addPlayer(&p1);
    g.addPlayer(&p2);
    g.addPlayer(&p3);
    g.addShipment(p2.getRole(), p2.getOrderPlaced());
    //g.addShipment(p2.getRole(), p2.getOrderPlaced());
    //EXPECT_EQ(1, (g.getShipmentsToBeExecuted()[currentWeek]).size());
    EXPECT_EQ(1, (g.getShipmentsToBeExecuted()).size());
}

/**
* tests the startGame() method
*/
TEST(gameTest, startGameTest)
{
    Game g;
    g.startGame();
    EXPECT_EQ(true, g.getGameStarted());
}

/**
* test the downstream method, which tells the previous player
*/
TEST(gameTest, getDownstreamTest)
{
    Game g;
    Player p1, p2;
    p1.setPId(12);
    p1.setRole(0);
    p2.setPId(13);
    p2.setRole(1);

    std::vector<Player*> v;
    g.setPlayers(v);
    g.addPlayer(&p1);
    g.addPlayer(&p2);

    EXPECT_EQ(p2.getPId(), g.getDownstream(p1.getRole())->getPId());
}

/**
* test the upstream method, which tells the next player
*/
TEST(gameTest, getUpstreamTest)
{
    Game g;
    Player p1, p2;
    p1.setPId(24);
    p1.setRole(1);
    p2.setPId(25);
    p2.setRole(2);

    std::vector<Player*> q;
    g.setPlayers(q);
    g.addPlayer(&p1);
    g.addPlayer(&p2);

    EXPECT_EQ(p1.getPId(), g.getUpstream(p2.getRole())->getPId());
}

/**
* test the upstream method, which tells the next player - null pointer case
*/
TEST(gameTest, getUpstreamNullPtrTest)
{
    Game g;
    Player p1, p2;
    p1.setPId(24);
    p1.setRole(1);
    p2.setPId(25);
    p2.setRole(5);

    std::vector<Player*> q;
    g.setPlayers(q);
    g.addPlayer(&p1);
    g.addPlayer(&p2);
    EXPECT_EQ(nullptr, g.getUpstream(6));
}

/**
* Tests the addPlayer() Method where each player is assigned a role
*/
TEST(gameTest, addPlayerTest)
{
    Game g;
    Player p1, p2, p3;
    g.addPlayer(&p1);
    g.addPlayer(&p2);
    g.addPlayer(&p3);

    EXPECT_EQ(1, p1.getRole());
}

/**
* Tests the addPlayer() method to see if it updates the number of players or not.
*/
TEST(gameTest, addPlayerNumOfPlayersTest)
{
    Game g;
    Player p1, p2, p3;
    g.addPlayer(&p1);
    g.addPlayer(&p2);
    g.addPlayer(&p3);

    EXPECT_EQ(3,g.getNumberOfPlayers());
}

/**
* Tests the updatePlayer() inventory by checking if the PlayerEvent is order or shipment
*/
TEST(gameTest, updatePlayerInventoryTest)
{
    Game g;
    Player p1, p2, p3;
    p2.setDemand(15);
    p2.setInventory(4);
    g.addPlayer(&p1);
    g.addPlayer(&p2);
    g.addPlayer(&p3);
    g.updatePlayerInventories();
    std::vector<Player *> players = g.getPlayers();
    EXPECT_EQ(0,(*players[1]).getInventory());
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
// Instructor Class Test Cases

/**
* Tests the setter for Games where games is a vector
*/
TEST(instructorTest, setGamesTest)
{

    Instructor i;
    vector <Game> gameSet;
    Game g1;
    Game g2;
    gameSet.push_back(g1);
    gameSet.push_back(g2);
    i.setGames(gameSet);
    EXPECT_EQ(2, (i.getGames()).size());
}

/**
* Tests the getter for Games where games is a vector
*/
TEST(instructorTest, getGamesTest)
{

    Instructor i;
    vector <Game> gameSet;
    Game g1, g2, g3;
    gameSet.push_back(g1);
    gameSet.push_back(g2);
    gameSet.push_back(g3);
    i.setGames(gameSet);
    vector<Game> returnedGameSet = i.getGames();
    EXPECT_EQ(3, returnedGameSet.size());
}

/**
* Tests the setter for Instructor's Email.
*/
TEST(instructorTest, setInstrEmailTest)
{

    Instructor i;
    i.setInstrEmail("hi.there@jacobs-university.de");
    EXPECT_EQ("hi.there@jacobs-university.de", i.getInstrEmail());
}

/**
* Tests the getter for Instructor's Email.
*/
TEST(instructorTest, getInstrEmailTest)
{

    Instructor i;
    i.setInstrEmail("hi.again@jacobs-university.de");
    std::string email = "hi.again@jacobs-university.de";
    EXPECT_EQ(email, i.getInstrEmail());
}


/**
* Tests the setter for Instructor's Password.
*/
TEST(instructorTest, setInstrPasswordTest)
{

    Instructor i;
    i.setInstrPassword("superstrongpassword");
    EXPECT_EQ("superstrongpassword", i.getInstrPassword());
}


/**
* Tests the getter for Instructor's Password.
*/
TEST(instructorTest, getInstrPasswordTest)
{

    Instructor i;
    i.setInstrPassword("weakpassword");
    EXPECT_EQ("weakpassword", i.getInstrPassword());
}

/**
* Tests the setter for Instructor's Id.
*/
TEST(instructorTest, setInstrIdTest)
{

    Instructor i;
    i.setInstrId(2020);
    EXPECT_EQ(2020, i.getInstrId());
}

/**
* Tests the getter for Instructor's Id.
*/
TEST(instructorTest, getInstrIdTest)
{

    Instructor i;
    i.setInstrId(30);
    EXPECT_EQ(30, i.getInstrId());
}

/**
* Tests the createGame() method using the default backorder value
*/
TEST(instructorTest, createGameTest)
{

    Instructor i;
    Game g = i.createGame();
    EXPECT_EQ(2.0, g.getHoldingCost());
}

/**
* Tests the createGame() method using the default backorder value
*/
TEST(instructorTest, createGamesTest)
{
    Instructor i;
    vector<Game> games = i.createGames(4);
    EXPECT_EQ(4, games.size());
}

/**
* Tests showGameStatus() method
*/
TEST(instructorTest, showGamesStatusTest)
{

    Instructor i;
    vector <Game> gameSet;
    Game g1, g2, g3;
    g1.setNumberOfPlayers(3);
    g2.setNumberOfPlayers(2);
    g3.setNumberOfPlayers(4);
    gameSet.push_back(g1);
    gameSet.push_back(g2);
    gameSet.push_back(g3);
    i.setGames(gameSet);
    i.showGamesStatus();
    EXPECT_EQ(4, (i.checkingStatus()).at(2));
}
// Order Class Test Cases

TEST(orderTest, getOrderIdTest)
{

    Order o;
    o.setOrderId(23);
    EXPECT_EQ(23, o.getOrderId());
}

TEST(orderTest, setOrderIdTest)
{

    Order o;
    o.setOrderId(32);
    EXPECT_EQ(32, o.getOrderId());
}

TEST(orderTest, getGIdTest)
{

    Order o;
    o.setGId(53);
    EXPECT_EQ(53, o.getGId());
}

TEST(orderTest, setGIdTest)
{

    Order o;
    o.setGId(13);
    EXPECT_EQ(13, o.getGId());
}

TEST(orderTest, getOrderedInWeekTest)
{

    Order o;
    o.setOrderedInWeek(5);
    EXPECT_EQ(5, o.getOrderedInWeek());
}

TEST(orderTest, setOrderedInWeekTest)
{

    Order o;
    o.setOrderedInWeek(2);
    EXPECT_EQ(2, o.getOrderedInWeek());
}

TEST(orderTest, getShippedInWeekTest)
{

    Order o;
    o.setShippedInWeek(4);
    EXPECT_EQ(4, o.getShippedInWeek());
}

TEST(orderTest, setShippedInWeekTest)
{

    Order o;
    o.setShippedInWeek(3);
    EXPECT_EQ(3, o.getShippedInWeek());
}

TEST(orderTest, setNumberOfBeersTest)
{

    Order o;
    o.setNumberOfBeers(20);
    EXPECT_EQ(20, o.getNumberOfBeers());
}

TEST(orderTest, orderConstructorTest)
{
    Player p;
    p.setRole(2);
    int beer_quantity = 7;
    Order o(1,2,3,4, beer_quantity, &p);
    EXPECT_EQ(7, o.getNumberOfBeers());
}
//Shipment Class Tests


TEST(shipmentTest, getEventIdTest)
{

    Shipment s;
    s.setShipmentId(23);
    EXPECT_EQ(23, s.getShipmentId());
}

TEST(shipmentTest, setEventIdTest)
{

    Shipment s;
    s.setShipmentId(32);
    EXPECT_EQ(32, s.getShipmentId());
}

TEST(shipmentTest, getGIdTest)
{

    Shipment s;
    s.setGId(53);
    EXPECT_EQ(53, s.getGId());
}

TEST(shipmentTest, setGIdTest)
{
    Shipment s;
    s.setGId(13);
    EXPECT_EQ(13, s.getGId());
}

TEST(shipmentTest, getRecievedInWeekTest)
{
    Shipment s;
    s.setReceivedInWeek(5);
    EXPECT_EQ(5, s.getReceivedInWeek());
}

TEST(shipmentTest, setReceivedInWeekTest)
{
    Shipment s;
    s.setReceivedInWeek(2);
    EXPECT_EQ(2, s.getReceivedInWeek());
}

TEST(shipmentTest, getShippedInWeekTest)
{
    Shipment s;
    s.setShippedInWeek(4);
    EXPECT_EQ(4, s.getShippedInWeek());
}

TEST(shipmentTest, setShippedInWeekTest)
{
    Shipment s;
    s.setShippedInWeek(3);
    EXPECT_EQ(3, s.getShippedInWeek());
}

TEST(shipmentTest, setNumberOfBeersTest)
{
    Shipment s;
    s.setNumberOfBeers(20);
    EXPECT_EQ(20, s.getNumberOfBeers());
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

TEST(playerEventTest, getReceiverTest) {

    PlayerEvent pe;
    Player p;
    pe.setReceiver(&p);
    EXPECT_EQ(&p, pe.getReceiver());
}

/**
* Tests the setter for PlayerEvent Type i.e Order or Shipment
*/

TEST(playerEventTest, setTypeTest) {

    PlayerEvent pe;
    pe.setType("s");
    EXPECT_EQ("s", pe.getType());
}

/**
* Tests the getter for PlayerEvent Type i.e Order or Shipment
*/

TEST(playerEventTest, getTypeTest) {

    PlayerEvent pe;
    pe.setType("o");
    EXPECT_EQ("o", pe.getType());
}


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
TEST(playerEventTest, setNumberOfBeersTest)
{

    PlayerEvent pe;
    pe.setNumberOfBeers(20);
    EXPECT_EQ(20, pe.getNumberOfBeers());
}

/**
* Tests the getter for the number of beer units.
*/
TEST(playerEventTest, getNumberOfBeersTest)
{

    PlayerEvent pe;
    pe.setNumberOfBeers(20);
    EXPECT_EQ(20, pe.getNumberOfBeers());
}

