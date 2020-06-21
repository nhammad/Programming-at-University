/// \file

#include "gtest/gtest.h"
#include "../src/backend/game.h"
#include "../src/backend/instructor.h"
#include "../src/backend/player.h"
#include "../src/backend/playerevent.h"
#include "../src/backend/order.h"
#include "../src/backend/shipment.h"
#include "../src/frontend/mainwindow.h"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// #####################################################################################################################
// ########## Player Class Test Cases
// #####################################################################################################################


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
* Tests the getter for Player's Inventory value.
*/
TEST(playerTest, getInventoryTest)
{

    Player p;
    p.setInventory(10000);
    EXPECT_EQ(10000, p.getInventory());
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
* Tests the getter for Player's Backorder.
*/


TEST(playerTest, getBackOrderTest)
{

    Player p;
    p.setBackOrder(10);
    EXPECT_EQ(10, p.getBackOrder());
}

/**
* Tests the setter for Player's Backorder.
*/


TEST(playerTest, setBackOrderTest)
{

    Player p;
    p.setBackOrder(20);
    EXPECT_EQ(20, p.getBackOrder());
}

/**
* Tests the getter for Player's Incoming Order value.
*/
TEST(playerTest, getIncomingOrderTest)
{

    Player p;
    p.setIncomingOrder(10000);
    EXPECT_EQ(10000, p.getIncomingOrder());
}

/**
* Tests the setter for Player's Incoming Order value.
*/
TEST(playerTest, setIncomingOrderTest)
{

    Player p;
    p.setIncomingOrder(40);
    EXPECT_EQ(40, p.getIncomingOrder());
}

/**
* Tests the getter for Player's Incoming Shipment value.
*/
TEST(playerTest, getIncomingShipmentTest)
{

    Player p;
    p.setIncomingShipment(10000);
    EXPECT_EQ(10000, p.getIncomingShipment());
}

/**
* Tests the setter for Player's Incoming Shipment value.
*/
TEST(playerTest, setIncomingShipmentTest)
{

    Player p;
    p.setIncomingShipment(40);
    EXPECT_EQ(40, p.getIncomingShipment());
}

/**
* Tests the getter for Player's Incoming Shipment History where history is in form of a vector.
*/
TEST(playerTest, getIncomingShipmentHistoryTest)
{

    Player p;
    std::vector<int> history = {1,2,3,4,5,6};
    p.setIncomingShipmentHistory(history);
    EXPECT_EQ(history, p.getIncomingShipmentHistory());
}

/**
* Tests the setter for Player's Incoming Shipment History where history is in form of a vector.
*/
TEST(playerTest, setIncomingShipmentHistoryTest)
{

    Player p;
    std::vector<int> history = {1,2,3,4,5,6};
    p.setIncomingShipmentHistory(history);
    EXPECT_EQ(history, p.getIncomingShipmentHistory());
}

/**
* Tests the getter for Player's Outgoing Shipment.
*/
TEST(playerTest, getOutgoingShipmentTest)
{

    Player p;
    p.setOutgoingShipment(10000);
    EXPECT_EQ(10000, p.getOutgoingShipment());
}

/**
* Tests the setter for Player's Outgoing Shipment.
*/
TEST(playerTest, setOutgoingShipmentTest)
{

    Player p;
    p.setOutgoingShipment(40);
    EXPECT_EQ(40, p.getOutgoingShipment());
}

/**
* Tests the getter for Player's Outgoing Shipment History where history is in form of a vector.
*/
TEST(playerTest, getOutgoingShipmentHistoryTest)
{

    Player p;
    std::vector<int> history = {1,2,3,4,5,6};
    p.setOutgoingShipmentHistory(history);
    EXPECT_EQ(history, p.getOutgoingShipmentHistory());
}

/**
* Tests the setter for Player's Outgoing Shipment History where history is in form of a vector.
*/
TEST(playerTest, setOutgoingShipmentHistoryTest)
{

    Player p;
    std::vector<int> history = {1,2,3,4,5,6};
    p.setOutgoingShipmentHistory(history);
    EXPECT_EQ(history, p.getOutgoingShipmentHistory());
}

/**
* Tests the getter for Player's Order History.
*/
TEST(playerTest, getOrderHistoryTest)
{

    Player p;
    std::vector<int> history = {1,2,3,4,5,6};
    p.setOrderHistory(history);
    EXPECT_EQ(history, p.getOrderHistory());
}

/**
* Tests the setter for Player's Order History.
*/
TEST(playerTest, setOrderHistoryTest)
{

    Player p;
    std::vector<int> history = {1,2,3,4,5,6};
    p.setOrderHistory(history);
    EXPECT_EQ(history, p.getOrderHistory());
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
* Tests the setter for Player's Cost.
*/
TEST(playerTest, setCostTest)
{

    Player p;
    p.setCost(30);
    EXPECT_EQ(30, p.getCost());
}


/**
* Tests the getter for Player's Total Cost.
*/
TEST(playerTest, getTotalCostTest)
{

    Player p;
    p.setTotalCost(2);
    EXPECT_EQ(2, p.getTotalCost());
}

/**
* Tests the setter for Player's Total Cost.
*/
TEST(playerTest, setTotalCostTest)
{

    Player p;
    p.setTotalCost(30);
    EXPECT_EQ(30, p.getTotalCost());
}

/**
* Tests the setter for Order Received property.
*/
TEST(playerTest, setOrderReceivedTest)
{

    Player p;
    p.setOrderReceived(true);
    EXPECT_EQ(true, p.isOrderReceived());
    p.setOrderReceived(false);
    EXPECT_EQ(false, p.isOrderReceived());
}

/**
* Tests the Order Received property.
*/
TEST(playerTest, isOrderReceivedTest)
{

    Player p;
    p.setOrderReceived(false);
    EXPECT_EQ(false, p.isOrderReceived());
}

/**
* Tests the setter for Shipment Received property.
*/
TEST(playerTest, setShipmentReceivedTest)
{

    Player p;
    p.setShipmentReceived(true);
    EXPECT_EQ(true, p.isShipmentReceived());
    p.setShipmentReceived(false);
    EXPECT_EQ(false, p.isShipmentReceived());
}

/**
* Tests the Shipment Received property.
*/
TEST(playerTest, isShipmentReceivedTest)
{

    Player p;
    p.setShipmentReceived(false);
    EXPECT_EQ(false, p.isShipmentReceived());
}

/**
* Tests the setter for OrderPlaced property.
*/
TEST(playerTest, setOrderPlacedTest)
{

    Player p;
    p.setOrderPlaced(true);
    EXPECT_EQ(true, p.isOrderPlaced());
    p.setOrderPlaced(false);
    EXPECT_EQ(false, p.isOrderPlaced());
}

/**
* Tests the isOrderPlaced property.
*/
TEST(playerTest, isOrderPlacedTest)
{

    Player p;
    p.setOrderPlaced(false);
    EXPECT_EQ(false, p.isOrderPlaced());
}

/**
* Tests the setter for Shipment Placed property.
*/
TEST(playerTest, setShipmentPlacedTest)
{

    Player p;
    p.setShipmentPlaced(true);
    EXPECT_EQ(true, p.isShipmentPlaced());
    p.setShipmentPlaced(false);
    EXPECT_EQ(false, p.isShipmentPlaced());
}

/**
* Tests the Shipment Placed property.
*/
TEST(playerTest, isShipmentPlacedTest)
{

    Player p;
    p.setShipmentPlaced(false);
    EXPECT_EQ(false, p.isShipmentPlaced());
}

/**
* Tests the setter for Demand.
*/
TEST(playerTest, setDemandTest)
{

    Player p;
    p.setDemand(3);
    EXPECT_EQ(3, p.getDemand());
}

/**
* Tests the getter for Demand.
*/
TEST(playerTest, getDemandTest)
{

    Player p;
    p.setDemand(4);
    EXPECT_EQ(4, p.getDemand());
}

// Other Class Methods -------------------------------------------
//=================================================================

/**
* Tests the decreaseInventory() method.
*/

TEST(playerTest, decreaseInventoryTest)
{

    Player p;
    p.setInventory(15);
    p.decreaseInventory(5);
    EXPECT_EQ(10, p.getInventory());
}

/**
* Tests the increaseInventory() method from the Player class.
*/

TEST(playerTest, increaseInventoryTest)
{

     Player p;
    p.setInventory(10);
    p.increaseInventory(10);
    EXPECT_EQ(20, p.getInventory());
}

/**
* Tests if the setter for a Game
*/

TEST(playerTest, getGameTest)
{

    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player p;
    p.setGame(newgame);
    EXPECT_EQ(newgame, p.getGame());

}

/**
* Tests if the setter for a Game
*/

TEST(playerTest, setGameTest)
{

    Game *newgame = new Game(1,2,2,2,26,12,2);
    Game *game = new Game(1,2,2,2,26,12,2);
    Player p;
    p.setGame(newgame);
    p.setGame(game);
    EXPECT_EQ(game, p.getGame());

}

/**
* Tests the initialization of a game.
*/

TEST(playerTest, getGame_Test)
{

    Game *newgame = new Game();
    Player p;
    p.setGame(newgame);
    EXPECT_EQ(newgame, p.getGame());

}

/**
* Tests the initialization of a game.
*/
TEST(playerTest, setGame_Test)
{

    Game *newgame = new Game();
    Game *game = new Game();
    Player p;
    p.setGame(newgame);
    p.setGame(game);
    EXPECT_EQ(game, p.getGame());

}

/**
* Tests the placeOrder() method.
*/
TEST(playerTest, placeOrderTest ) {
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* retailer = new Player(newgame, 1);
    int numOfBeers = 10;
    newgame->addPlayer(retailer);
    retailer->placeOrder(numOfBeers);
    std::map<int, std::vector<Order>> ordersToBeExecuted =newgame->getOrdersToBeExecuted();
    std::vector <Order> myorder = ordersToBeExecuted[1];
    int beersInOrder = myorder[0].getNumberOfBeers();
    EXPECT_EQ(10, beersInOrder);
}

/**
* Tests the if statement inside addOrder() method. If the statement is executed, advanceWeek() is called.
*/
TEST(playerTest, addOrderTest)
{

    Game newgame; 
    Order ord;
    newgame.setTotalShipmentsInWeek(5);
    newgame.setTotalOrdersInWeek(3);
    newgame.addOrder(ord);
    EXPECT_EQ(true, newgame.getWeekAdvanced());
}

/**
* Tests the if statement inside addShipment() method. If the statement is executed, advanceWeek() is called.
*/
TEST(playerTest, addShipmentTest)
{

    Game newgame; 
    Shipment ship;
    newgame.setTotalShipmentsInWeek(4);
    newgame.setTotalOrdersInWeek(4);
    newgame.addShipment(ship);
    EXPECT_EQ(true, newgame.getWeekAdvanced());
}

/**
* Tests the placeOrder() method when the player is a Factory.
*/
TEST(playerTest, placeOrderFactoryTest ) {
    Game *newgame = new Game(0,2,2,2,26,15,2);
    Player* retailer = new Player(newgame, 1);
     Player* factory = new Player(newgame, 2);
    int numOfBeers = 20;
    newgame->addPlayer(retailer);
    newgame->addPlayer(factory);
    factory->placeOrder(numOfBeers);
    std::map<int, std::vector<Order>> ordersToBeExecuted =newgame->getOrdersToBeExecuted();
    std::vector <Order> myorder = ordersToBeExecuted[1];
    EXPECT_EQ(20, myorder[0].getNumberOfBeers());
}

//placeOrder should call Game's addShipment method

/**
* Tests the placeShipment() method.
*/
TEST(playerTest, placeShipmentTest) {
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* retailer = new Player(newgame, 1);
    int numOfBeers = 212;
    newgame->addPlayer(retailer);
    retailer->placeShipment(numOfBeers);
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted =newgame->getShipmentsToBeExecuted();
    std::vector <Shipment> myRecentShipment = shipmentsToBeExecuted[1];
    int beersInShipment = myRecentShipment[0].getNumberOfBeers();
    EXPECT_EQ(212, beersInShipment);
}

//getAvailableShipment returns the number of beers that are available for shipment to the next Player
/**
* Tests if the getAvailableShipment returns the correct value or available items or not.
*/
TEST(playerTest, getAvailableShipmentTest) {
    // With 12 as initial Inventory
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* retailer = new Player(newgame, 1);
    EXPECT_EQ(12, retailer->getAvailableShipment(200));
}

/**
* Tests the receiveShipment method.
*/
TEST(playerTest, receiveShipmentTest){
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* retailer = new Player(newgame, 1);
    retailer->receiveShipment(12);
    EXPECT_EQ(12, retailer->getIncomingShipment());
}

/**
* Tests the receiveShipment method by checking if inventory is updated or not.
*/
TEST(playerTest, receiveShipmentInventoryTest){
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* retailer = new Player(newgame, 1);
    retailer->setInventory(10);
    retailer->receiveShipment(12);
    EXPECT_EQ(22, retailer->getInventory());
}

/**
* Tests the receiveOrder method.
*/
TEST(playerTest, receiveOrderTest){
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* retailer = new Player(newgame, 1);
    retailer->receiveOrder(22);
    EXPECT_EQ(22, retailer->getIncomingOrder());
}

// #####################################################################################################################
// ########## Game Class Test Cases
// #####################################################################################################################

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
* test the getter for method getOrdersToBeExecuted() which returns a map.
*/
TEST(gameTest, getOrdersToBeExecutedTest)
{

     Game g;
     Player *pa = new Player();
     Player *pb = new Player();
     g.addPlayer(pa);
     g.addPlayer(pb);
     std::map<int, std::vector<Order>> ordersToBeExe ;
     ordersToBeExe[0].push_back(Order(g.getUpstream(CONSUMER), 1, 4, 1));
     ordersToBeExe[1].push_back(Order(g.getUpstream(CONSUMER), 1, 4, 1));
     g.setOrdersToBeExecuted(ordersToBeExe);
     EXPECT_EQ(ordersToBeExe.size(), g.getOrdersToBeExecuted().size());
}


/**
* test the setter for a method getOrdersToBeExecuted() which returns a map.
*/
TEST(gameTest, setOrdersToBeExecutedTest)
{

     Game g;
     Player *pa = new Player();
     Player *pb = new Player();
     g.addPlayer(pa);
     g.addPlayer(pb);
     std::map<int, std::vector<Order>> ordersToBeExe ;
     ordersToBeExe[0].push_back(Order(g.getUpstream(CONSUMER), 1, 2, 1));
     ordersToBeExe[1].push_back(Order(g.getUpstream(CONSUMER), 1, 6, 1));
     ordersToBeExe[3].push_back(Order(g.getUpstream(CONSUMER), 1, 6, 1));
     g.setOrdersToBeExecuted(ordersToBeExe);
     EXPECT_EQ(ordersToBeExe.size(), g.getOrdersToBeExecuted().size());
}


/**
* test the getter for method ShipmentToBeExecutedTest which is a map.
*/
TEST(gameTest, getShipmentToBeExecutedTest)
{

     Game g;
     Player *pa = new Player();
     Player *pb = new Player();
     g.addPlayer(pa);
     g.addPlayer(pb);
     std::map<int, std::vector<Shipment>> ShipmentToBeExe ;
     ShipmentToBeExe[0].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     ShipmentToBeExe[1].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     ShipmentToBeExe[0].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     ShipmentToBeExe[1].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     g.setShipmentsToBeExecuted(ShipmentToBeExe);
     EXPECT_EQ(ShipmentToBeExe.size(), g.getShipmentsToBeExecuted().size());
}

/**
* test the setter for ShipmentToBeExecutedTest
*/
TEST(gameTest, setShipmentToBeExecutedTest)
{

     Game g;
     Player *pa = new Player();
     Player *pb = new Player();
     g.addPlayer(pa);
     g.addPlayer(pb);
     std::map<int, std::vector<Shipment>> ShipmentToBeExe ;
     ShipmentToBeExe[0].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     ShipmentToBeExe[1].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     ShipmentToBeExe[0].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     ShipmentToBeExe[1].push_back(Shipment(g.getUpstream(RETAILER), 1, 4, 1));
     g.setShipmentsToBeExecuted(ShipmentToBeExe);
     EXPECT_EQ(ShipmentToBeExe.size(), g.getShipmentsToBeExecuted().size());
}

/**
* test the getPlayers method.
*/
TEST(gameTest, getPlayersTest)
{

    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);
    
    EXPECT_EQ(consumer, newgame->getPlayers()[0]);
    EXPECT_EQ(retailer, newgame->getPlayers()[1]);
    EXPECT_EQ(wholesaler, newgame->getPlayers()[2]);
    EXPECT_EQ(distributor, newgame->getPlayers()[3]);
    EXPECT_EQ(factory, newgame->getPlayers()[4]);
}

/**
* test the setPlayers method.
*/
TEST(gameTest, setPlayersTest)
{
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);

    std::vector<Player *> myplayers= {consumer, retailer, wholesaler};
    newgame->setPlayers(myplayers);
    
    EXPECT_EQ(myplayers, newgame->getPlayers());
    
}

/**
* test getter for ConsumerDemandPerWeek()
*/
TEST(gameTest, getConsumerOrderPerWeekTest)
{

    Game g;
    std::vector<int> consumerDemandPerWeek = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    g.setConsumerDemandPerWeek(consumerDemandPerWeek);
    EXPECT_EQ(consumerDemandPerWeek, g.getConsumerDemandPerWeek());
}

/**
* test setter for ConsumerDemandPerWeek()
*/
TEST(gameTest, setConsumerOrderPerWeekTest)
{

    Game g;
    std::vector<int> consumerDemandPerWeek = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    g.setConsumerDemandPerWeek(consumerDemandPerWeek);
    EXPECT_EQ(consumerDemandPerWeek, g.getConsumerDemandPerWeek());
}

/**
* test getter for order time delay
*/
TEST(gameTest, getOrderDelayTest)
{

    Game g;
    g.setOrderDelay(3);
    EXPECT_EQ(3, g.getOrderDelay());
}

/**
* test setter for order time delay
*/
TEST(gameTest, setOrderDelayTest)
{

    Game g;
    g.setOrderDelay(4);
    EXPECT_EQ(4, g.getOrderDelay());
}

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
    EXPECT_EQ(0.5, g.getHoldingCost()); //checking default value
    g.setHoldingCost(9);
    EXPECT_EQ(9, g.getHoldingCost());
}

/**
* test getter for backorder cost
*/
TEST(gameTest, getBackOrderCostTest)
{

    Game g;
    g.setBackOrderCost(5.7);
    EXPECT_EQ(5.7, g.getBackOrderCost());
}

/**
* test setter for backorder cost
*/
TEST(gameTest, setBackOrderCostTest)
{

    Game g;
    g.setBackOrderCost(9.1);
    EXPECT_EQ(9.1, g.getBackOrderCost());
}

/**
* Test the setter for starting inventory property.
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
* test getter for Factory Delay
*/
TEST(gameTest, getFactoryDelayTest)
{

    Game g;
    g.setFactoryDelay(3);
    EXPECT_EQ(3, g.getFactoryDelay());
}

/**
* test setter for Factory Delay
*/
TEST(gameTest, setFactoryDelayTest)
{

    Game g;
    g.setFactoryDelay(4);
    EXPECT_EQ(4, g.getFactoryDelay());
}

/**
* test getter for NPlayers property
*/
TEST(gameTest, getNPlayersTest)
{

    Game g;
    g.setNPlayers(3);
    EXPECT_EQ(3, g.getNPlayers());
}

/**
* test setter for NPlayers property
*/
TEST(gameTest, setNPlayersTest)
{
    Game g;
    g.setNPlayers(4);
    EXPECT_EQ(4, g.getNPlayers());
}


/**
* test setter for NOrdersReceived property i.e Number of Orders Received
*/
TEST(gameTest, setNOrdersReceivedTest)
{
    Game g;
    g.setNOrdersReceived(6);
    EXPECT_EQ(6, g.getNOrdersReceived());
}

/**
* test getter for NOrdersReceived property i.e Number of Orders Received
*/
TEST(gameTest, getNOrdersReceivedTest)
{
    Game g;
    g.setNOrdersReceived(8);
    EXPECT_EQ(8, g.getNOrdersReceived());
}

/**
* test setter for NShipmentsReceived property i.e Number of Shipments Received
*/
TEST(gameTest, setNShipmentsReceivedTest)
{
    Game g;
    g.setNOrdersReceived(6);
    EXPECT_EQ(6, g.getNOrdersReceived());
}

/**
* test getter for NShipmentsReceived property i.e Number of Shipments Received
*/
TEST(gameTest, getNShipmentsReceivedTest)
{
    Game g;
    g.setNShipmentsReceived(8);
    EXPECT_EQ(8, g.getNShipmentsReceived());
}

// Other Class Methods for Game -----------------------------------
//=================================================================


/**
* tests the startGame() method
*/

TEST(gameTest, startGameTest){

    char beergame[] = {'g','a','m','e'};
    char* argv[] = {beergame};
    int argc = 1 ;
    QApplication a(argc, argv);
    MainWindow w;
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);

    std::vector<Player*> allPlayers {consumer, retailer, wholesaler, distributor, factory};
    PlayerDialog* C = new PlayerDialog(&w, *newgame, consumer);
    PlayerDialog* R = new PlayerDialog(&w, *newgame, retailer);
    PlayerDialog* W = new PlayerDialog(&w,*newgame, wholesaler);
    PlayerDialog* D = new PlayerDialog(&w,*newgame, distributor);
    PlayerDialog* F = new PlayerDialog(&w,*newgame, factory);
    newgame->startGame();

    EXPECT_EQ(5, newgame->getPlayers().size());
    EXPECT_EQ(consumer, newgame->getPlayers()[0]);
    EXPECT_EQ(retailer, newgame->getPlayers()[1]);
    EXPECT_EQ(wholesaler, newgame->getPlayers()[2]);
    EXPECT_EQ(distributor, newgame->getPlayers()[3]);
    EXPECT_EQ(factory, newgame->getPlayers()[4]);
    EXPECT_EQ(1, newgame->getInstrId());

    // The checking the values that we pass for the first two weeks
    EXPECT_EQ(4, retailer->getDemand());
    EXPECT_EQ(4, wholesaler->getDemand());
    EXPECT_EQ(4, distributor->getDemand());
    EXPECT_EQ(4, factory->getDemand());

    delete newgame;
    w.close();
}

//In executeOrdersForCurrentWeek, the Order objects in the map ordersToBeExecuted are executed (the method
// executeOrder for each object is called)

/**
* tests the  executeOrdersForCurrentWeek() method
*/
TEST(gameTest, executeOrdersForCurrentWeekTest){
    char beergame[] = {'g','a','m','e'};
    char* argv[] = {beergame};
    int argc = 1 ;
    QApplication a(argc, argv);
    MainWindow w;
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);

    std::vector<Player*> allPlayers {consumer, retailer, wholesaler, distributor, factory};
    PlayerDialog* C = new PlayerDialog(&w, *newgame, consumer);
    PlayerDialog* R = new PlayerDialog(&w, *newgame, retailer);
    PlayerDialog* W = new PlayerDialog(&w,*newgame, wholesaler);
    PlayerDialog* D = new PlayerDialog(&w,*newgame, distributor);
    PlayerDialog* F = new PlayerDialog(&w,*newgame, factory);
    newgame->startGame();
    //Execution of the order is done at the end of start game
    EXPECT_EQ(5, newgame->getPlayers().size());
    EXPECT_EQ(consumer, newgame->getPlayers()[0]);
    EXPECT_EQ(retailer, newgame->getPlayers()[1]);
    EXPECT_EQ(wholesaler, newgame->getPlayers()[2]);
    EXPECT_EQ(distributor, newgame->getPlayers()[3]);
    EXPECT_EQ(factory, newgame->getPlayers()[4]);
    EXPECT_EQ(1, newgame->getInstrId());

    // The checking the values that we pass for the first two weeks
    EXPECT_EQ(4, retailer->getDemand());
    EXPECT_EQ(4, wholesaler->getDemand());
    EXPECT_EQ(4, distributor->getDemand());
    EXPECT_EQ(4, factory->getDemand());

    delete newgame;
    w.close();
}

/**
* Tests the addPlayer() Method where each player is assigned a role
*/
TEST(gameTest, addPlayerTest){
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);

    EXPECT_EQ(5, newgame->getPlayers().size());

    // Checking the players in the game class with the original players
    EXPECT_EQ(consumer, newgame->getPlayers()[0]);
    EXPECT_EQ(retailer, newgame->getPlayers()[1]);
    EXPECT_EQ(wholesaler, newgame->getPlayers()[2]);
    EXPECT_EQ(distributor, newgame->getPlayers()[3]);
    EXPECT_EQ(factory, newgame->getPlayers()[4]);

}

/**
* test the downstream method, which tells the previous player
*/
TEST(gameTest, getDownstreamTest){
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);

    EXPECT_EQ(retailer, newgame->getUpstream(0));
    EXPECT_EQ(wholesaler, newgame->getUpstream(1));
    EXPECT_EQ(distributor, newgame->getUpstream(2));
    EXPECT_EQ(factory, newgame->getUpstream(3));

}

/**
* Tests the downstream method in case of a consumer
*/
TEST(gameTest, getDownstreamConsumerTest){
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);

    //Player *p = newgame->getDownstream(0);
    //EXPECT_EQ(consumer, newgame->getDownstream(1));
     EXPECT_EQ(consumer, newgame->getDownstream(0));
}
/**
* test the upstream method, which tells the previous player
*/
TEST(gameTest, getUpstreamTest){

    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);

    EXPECT_EQ(consumer, newgame->getDownstream(1));
    EXPECT_EQ(retailer, newgame->getDownstream(2));
    EXPECT_EQ(wholesaler, newgame->getDownstream(3));
    EXPECT_EQ(distributor, newgame->getDownstream(4));

}


/**
* Tests for the generatePasswords method.
*/
TEST(gameTest, generatePasswordsTest){
    Game *newgame = new Game(1,2,2,2,26,12,2);
    newgame->generatePasswords();
    EXPECT_EQ(5, newgame->generatePasswords().size());
}

//In executeShipmentsForCurrentWeek, the Shipment objects in the map setShipmentsToBeExecuted are executed (the method
// executeShipment for each object is called)


/**
* Tests for the executeShipmentsForCurrentWeek() method.
*/
TEST(gameTest, executeShipmentsForCurrentWeekTest){
    char beergame[] = {'g','a','m','e'};
    char* argv[] = {beergame};
    int argc = 1 ;
    QApplication a(argc, argv);
    MainWindow w;
    Game *newgame = new Game(1,2,2,2,26,12,2);
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);

    std::vector<Player*> allPlayers {consumer, retailer, wholesaler, distributor, factory};
    PlayerDialog* C = new PlayerDialog(&w, *newgame, consumer);
    PlayerDialog* R = new PlayerDialog(&w, *newgame, retailer);
    PlayerDialog* W = new PlayerDialog(&w,*newgame, wholesaler);
    PlayerDialog* D = new PlayerDialog(&w,*newgame, distributor);
    PlayerDialog* F = new PlayerDialog(&w,*newgame, factory);
    newgame->startGame();

    //Execution of the shipment is done at the end of start game
    EXPECT_EQ(5, newgame->getPlayers().size());
    EXPECT_EQ(consumer, newgame->getPlayers()[0]);
    EXPECT_EQ(retailer, newgame->getPlayers()[1]);
    EXPECT_EQ(wholesaler, newgame->getPlayers()[2]);
    EXPECT_EQ(distributor, newgame->getPlayers()[3]);
    EXPECT_EQ(factory, newgame->getPlayers()[4]);
    EXPECT_EQ(1, newgame->getInstrId());

    // The checking the values that we pass for the first two weeks
    EXPECT_EQ(4, retailer->getDemand());
    EXPECT_EQ(4, wholesaler->getDemand());
    EXPECT_EQ(4, distributor->getDemand());
    EXPECT_EQ(4, factory->getDemand());

    delete newgame;
    w.close();
}

/**
* test advanceWeek method
*/
TEST(gameTest, advanceWeekTest)
{

    Game g;
    int currweek = g.getCurrentWeek();
    g.advanceWeek();
    EXPECT_EQ(currweek + 1, g.getCurrentWeek());
}

/**
* test the gameReadyToStart() method.
*/
TEST(gameTest, gameReadyToStartTest)
{

    Game g;
    Player p1, p2, p3, p4;
    g.setPFactId(1);
    g.setPRetailerId(2);
    g.setPWholesalerId(3);
    g.setPDistributorId(4);
    bool ready = g.gameReadyToStart();
    EXPECT_TRUE(ready);
}


/**
* test the parametric Game constructor.
*/
TEST(gameTest, gameConstructorTest)
{

    Game g(12);
    EXPECT_EQ(12, g.getInstrId());
}

/**
* test the gameReadyToStart() method, when game is not fully ready.
*/
TEST(gameTest, gameNotReadyToStartTest)
{

    Game g;
    g.setPFactId(0);
    g.setPRetailerId(2);
    g.setPWholesalerId(3);
    g.setPDistributorId(4);
    bool ready = g.gameReadyToStart();
    EXPECT_FALSE(ready);
}
// #####################################################################################################################
// ########## Instructor Class Test Cases
// #####################################################################################################################

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
* Tests the setter for Instructor's Email.
*/
TEST(instructorTest, setInstrEmailTest2)
{

    Instructor i;
    i.setInstrEmail("there@gmail.de");
    EXPECT_EQ("there@gmail.de", i.getInstrEmail());
}

/**
* Tests the getter for Instructor's Email.
*/
TEST(instructorTest, getInstrEmailTest2)
{

    Instructor i;
    i.setInstrEmail("again@jacobs-university.de");
    std::string email = "again@jacobs-university.de";
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
* Tests the createGame() method.
*/
TEST(instructorTest, createGameTest){
    char beergame[] = {'g','a','m','e'};
    char* argv[] = {beergame};
    int argc = 1 ;
    QApplication a(argc, argv);
    MainWindow w;
    InstructorDialog *myinstructor = new InstructorDialog(&w);
    myinstructor->instructor->createGame();
    EXPECT_EQ(1, myinstructor->instructor->getGames().size());
    w.close();

}

/**
* Tests the createGames() method.
*/
TEST(instructorTest, createGamesTest){
    char beergame[] = {'g','a','m','e'};
    char* argv[] = {beergame};
    int argc = 1 ;
    QApplication a(argc, argv);
    MainWindow w;
    InstructorDialog *myinstructor = new InstructorDialog(&w);
    myinstructor->instructor->createGames(5);
    EXPECT_EQ(5, myinstructor->instructor->getGames().size());
    w.close();

}

/**
* Tests showGameStatus() method
*/
TEST(instructorTest, showGamesStatusTest)
{

    Instructor i;
    std::vector<Game *> gameSet;
    Game *g1, *g2, *g3;
    g1 = new Game();
    g2 = new Game();
    g3 = new Game();
    g1->setNPlayers(3);
    g2->setNPlayers(2);
    g3->setNPlayers(4);
    gameSet.push_back(g1);
    gameSet.push_back(g2);
    gameSet.push_back(g3);
    i.setGames(gameSet);
    i.showGameStatus();
    EXPECT_EQ(4, (i.checkingStatus()).at(2));
}

/**
* Tests the setter for Games where games is a vector
*/
TEST(instructorTest, setGamesTest)
{

    Instructor i;
    std::vector<Game *> gameSet;
    Game *g1, *g2, *g3;
    g1 = new Game();
    g2 = new Game();
    g3 = new Game();
    // g1->setNPlayers(3);
    // g2->setNPlayers(2);
    // g3->setNPlayers(4);
    gameSet.push_back(g1);
    gameSet.push_back(g2);
    gameSet.push_back(g3);
    i.setGames(gameSet);
    EXPECT_EQ(gameSet, i.getGames());
}

/**
* Tests the getter for Games where games is a vector
*/
TEST(instructorTest, getGamesTest)
{

    Instructor i;
    std::vector<Game *> gameSet;
    Game *g1, *g2, *g3, *g4;
    g1 = new Game();
    g2 = new Game();
    g3 = new Game();
    g4 = new Game();
    g1->setNPlayers(3);
    gameSet.push_back(g1);
    gameSet.push_back(g2);
    gameSet.push_back(g3);
    gameSet.push_back(g4);
    i.setGames(gameSet);
    EXPECT_EQ(gameSet, i.getGames());
}

// #####################################################################################################################
// ########## PlayerEvent Class Test Cases
// #####################################################################################################################

/**
* Tests the getter for Player's Event Id.
*/
TEST(playerEventTest, getEventIdTest)
{
    PlayerEvent p;
    p.setEventId(7071);
    EXPECT_EQ(7071, p.getEventId());
}

/**
* Tests the setter for Player's Event Id.
*/
TEST(playerEventTest, setEventIdTest)
{
    PlayerEvent p;
    p.setEventId(7006);
    EXPECT_EQ(7006, p.getEventId());
}

/**
* Tests the getter for Game Id.
*/
TEST(playerEventTest, getGIdTest)
{
    PlayerEvent p;
    p.setGId(222);
    EXPECT_EQ(222, p.getGId());
}

/**
* Tests the setter for Game Id.
*/
TEST(playerEventTest, setGIdTest)
{
    PlayerEvent p;
    p.setGId(444);
    EXPECT_EQ(444, p.getGId());
}

/**
* Tests the getter for the number of beer units.
*/
TEST(playerEventTest, getNumberOfBeersTest)
{
    PlayerEvent p;
    p.setNumberOfBeers(10);
    EXPECT_EQ(10, p.getNumberOfBeers());
}

/**
* Tests the setter for the number of beer units.
*/
TEST(playerEventTest, setNumberOfBeersTest)
{
    PlayerEvent p;
    p.setNumberOfBeers(10);
    EXPECT_EQ(10, p.getNumberOfBeers());
}

/**
* Tests the getter for the Week number when the order was placed.
*/

TEST(playerEventTest, getOrderedInWeekTest)
{
    PlayerEvent p;
    p.setOrderedInWeek(110);
    EXPECT_EQ(110, p.getOrderedInWeek());
}

/**
* Tests the setter for the Week number when the order was placed.
*/

TEST(playerEventTest, setOrderedInWeekTest)
{
    PlayerEvent p;
    p.setOrderedInWeek(110);
    EXPECT_EQ(110, p.getOrderedInWeek());
}

/**
* Tests the getter for the Week number when the order was shipped.
*/
TEST(playerEventTest, getShippedInWeekTest)
{
    PlayerEvent p;
    p.setShippedInWeek(110);
    EXPECT_EQ(110, p.getShippedInWeek());
}

/**
* Tests the setter for the Week number when the order was shipped.
*/
TEST(playerEventTest, setShippedInWeekTest)
{
    PlayerEvent p;
    p.setShippedInWeek(110);
    EXPECT_EQ(110, p.getShippedInWeek());
}


/**
* Tests the getter for receiver Player
*/

TEST(playerEventTest, getReceiverTest)
{
    PlayerEvent p;
    Player* pl = new Player;
    p.setReceiver(pl);
    EXPECT_EQ(pl, p.getReceiver());
}


/**
* Tests the setter for receiver Player
*/

TEST(playerEventTest, setReceiverTest)
{
    PlayerEvent p;
    Player* pl = new Player;
    p.setReceiver(pl);
    EXPECT_EQ(pl, p.getReceiver());
}

/**
* Tests the setter for the Player Id who will get the order.
*/
TEST(playerEventTest, setToPlayerIdTest)
{
    PlayerEvent p;
    p.setToPlayerId(50);
    EXPECT_EQ(50, p.getToPlayerId());
}

/**
* Tests the getter for the Player Id who will get the order.
*/
TEST(playerEventTest, getToPlayerIdTest)
{
    PlayerEvent p;
    p.setToPlayerId(40);
    EXPECT_EQ(40, p.getToPlayerId());
}

/**
* Tests the getter for the Player Id who will send the order.
*/
TEST(playerEventTest, getFromPlayerIdTest)
{
    PlayerEvent p;
    p.setFromPlayerId(50);
    EXPECT_EQ(50, p.getFromPlayerId());
}

/**
* Tests the setter for the Player Id who will deliver the order.
*/
TEST(playerEventTest, setFromPlayerIdTest)
{
    PlayerEvent p;
    p.setFromPlayerId(50);
    EXPECT_EQ(50, p.getFromPlayerId());
}

/** Tests for class Order **/

/**
* Tests the executeOrder method.
*/
TEST(orderTest, executeOrderTest){
    Game *newgame = new Game(1,2,2,2,26,20,2);
    Player* pl = new Player(newgame,2);
    Order myOrder = Order(pl, 1, 480, 1);
    myOrder.executeEvent();
    EXPECT_EQ(480, pl->getDemand());
}

/**
* Tests the Default Constructor for the order class, which is derived from the PlayerEvent class.
*/
TEST(orderTest, orderConstructorTest){
    Order ord;
    EXPECT_EQ(0, ord.getNumberOfBeers());
}


/** Tests for class Shipment **/

/**
* Tests the executeShipment method.
*/
TEST(shipmentTest, executeShipmentTest){
    Game *newgame = new Game(1,2,2,2,26,20,2);
    Player* pl = new Player(newgame,2);
    Shipment sh = Shipment(pl, 1, 220, 1);
    sh.executeEvent();
    EXPECT_EQ(220, pl->getIncomingShipment());
}

/**
* Tests the default constructor for Shipment class, which is derived from PlayerEvent.
*/
TEST(shipmentTest, shipmentConstructorTest){
    
    Shipment ship;
    EXPECT_EQ(0, ship.getEventId());
}


/** Tests for class PlayerDialog **/

/**
* tests getter for player.
*/
 TEST(PlayerDialogTest, getPlayerTest){
         char beergame[] = {'g','a','m','e'};
     char* argv[] = {beergame};
     int argc = 1 ;
     QApplication a(argc, argv);
     MainWindow w;
     Game *newgame = new Game(1,2,2,2,26,12,2);
     Player* retailer = new Player(newgame, RETAILER);
     newgame->addPlayer(retailer);
     PlayerDialog* R = new PlayerDialog(&w, *newgame, retailer);
     EXPECT_EQ(retailer, R->getPlayer());
 }

/**
* tests setter for player.
*/
 TEST(PlayerDialogTest, setPlayerTest){
         char beergame[] = {'g','a','m','e'};
     char* argv[] = {beergame};
     int argc = 1 ;
     QApplication a(argc, argv);
     MainWindow w;
     Game *newgame = new Game(1,2,2,2,26,12,2);
     Player* retailer = new Player(newgame, RETAILER);
     Player* wholesaler = new Player(newgame, WHOLESALER);
     PlayerDialog* R = new PlayerDialog(&w, *newgame, retailer);
     R->setPlayer(wholesaler);
     EXPECT_EQ(wholesaler, R->getPlayer());
 }



/**
* tests updateInstructorUI method.
*/
 TEST(InstructorDialogTest, updateInstructorUI){
         char beergame[] = {'g','a','m','e'};
     char* argv[] = {beergame};
     int argc = 1 ;
     QApplication a(argc, argv);
     MainWindow w;
     InstructorDialog* i = new InstructorDialog(&w);
     i->updateInstructorUI();
     EXPECT_EQ(1,i->instructor->getInstrId());
 }
