#include "player.h"

/**
* @brief Default Constructor to initialize a Player with default values
* for inventory, backorder, demand, and cost.
*/

Player::Player()
{
    
    inventory = 12;
    backorder = 0;
    incomingOrder = 0;
    incomingShipment = 0;
    outgoingShipment = 0;
    cost = 0;
    totalCost = 0;
    orderReceived = false;
    shipmentReceived = false;
    orderPlaced = false;
    shipmentPlaced = false;
    demand = 0;
}

/**
* @brief Method to place an order for a particular quantity of beers.
* @param numberOfBeers Qunantity of beer units to be ordered.
*/

void Player::placeOrder(int numberOfBeers) {
    // TODO - implement Player::order
    std::cout << "Player " << this->getRole() << "'s pId is:" << this->getPId() << "\n";
}


/**
* @brief returns the Player object that is next in the "downstream" for a certain role.
*@param numberOfBeers How many beer units are to be shipped
*/
void Player::placeShipment(int numberOfBeers) {
    // TODO - implement Player::ship
    throw "Not yet implemented";
}

/**
* @brief accept an order
*/
int Player::receiveOrder() {
    return 0;

}

/**
* @brief accept a shipment
*/
int Player::receiveShipment() {
    return 0;

}


/**
* @brief method to decrease the number of beers in inventory
* @param numberOfBeers is the number of beers to decrease from inventory
*/

int Player::decreaseInventory(int numberOfBeers)
{
    this->inventory = this->inventory - numberOfBeers;
    return this->inventory;
}

 /**
* @brief method to increase the number of beers in inventory
 * @param numberOfBeers is the number of beers to increase in inventory
*/

int Player::increaseInventory(int numberOfBeers) {
    this->inventory = this->inventory + numberOfBeers;
    return this->inventory;
}

/**
* @brief Set an ID value to distinuguish between players .
* @param pId Id assigned to a player.
*/

void Player::setPId(int pId) {
    this->pId = pId;
}

/**
* @brief Set a Role to distinuguish between players. It could be
* Manufacturer, Distributor, Wholesaler, or Retailer (represented by a number)
* @param role Role of the player.
*/

void Player::setRole(int role) {
    this->role = role;
}

/**
* @brief Set a value for how many beers are present in the inventory.
* @param inventory Number of beers that are present in the inventory.
*/

void Player::setInventory(int inventory) {
    this->inventory = inventory;
}

/**
* @brief Set the backorder value, which indicates how much a player is lagging behind.
* @param backorder Value of backorder.
*/

void Player::setBackorder(int backorder) {
    this->backorder = backorder;
}

/**
* @brief Set the value for demand i.e how much beer is still needed.
* @param demand Number of beer units that are still needed.
*/

void Player::setDemand(int demand) {
    this->demand = demand;
}

/**
* @brief sets the incoming order
* @param incomingOrder amount of beer units ordered
*/
void Player::setIncomingOrder(int incomingOrder) {
    this->incomingOrder = incomingOrder;
}

/**
* @brief sets the incoming shipment
* @param incomingShipment amount of beer units shipped to the current player
*/
void Player::setIncomingShipment(int incomingShipment) {
    this->incomingShipment = incomingShipment;
}

/**
* @brief sets the outgoing Shipment
* @param outgoingShipment amount of beer units shipped outside
*/
void Player::setOutgoingShipment(int outgoingShipment) {
    this->outgoingShipment = outgoingShipment;
}

/**
* @brief Set a value for the cost of each beer unit.
* @param cost Cost set for each unit.
*/
void Player::setCost(double cost) {
    this->cost = cost;
}

/**
* @brief Set a value for the total cost of beer units.
* @param totalCost Total cost for beer units.
*/

void Player::setTotalCost(double totalCost) {
    this->totalCost = totalCost;
}

/**
* @brief Set a bool value for whether order is received or not.
* @param value whether the order is received or not (true or false)
*/

void Player::setOrderReceived(bool value) {
    this->orderReceived =  value;
}

/**
* @brief Set a bool value for whether shipment is received or not.
* @param value whether the shipment is received or not (true or false)
*/

void Player::setShipmentReceived(bool value) {
    this->shipmentReceived =  value;
}

/**
* @brief Set a bool value for whether order is placed or not.
* @param value whether the order is placed or not (true or false)
*/

void Player::setOrderPlaced(bool value) {
    this->orderPlaced =  value;
}

/**
* @brief Set a bool value for whether shipment is placed or not.
* @param value whether the shipment is placed or not (true or false)
*/

void Player::setShipmentPlaced(bool value) {
    this->shipmentPlaced =  value;
}

/**
* @brief According to the demand, inventory is adjusted and the number of beers available for shipping is returned.
* @param demand Total Number of beer units required by the other player.
*/

int Player::getAvailableShipment(int demand) {

    int availableShipment;
    int back_log;

    if (demand > getInventory()){
        availableShipment = getInventory();
        back_log = demand - getInventory();
        decreaseInventory(availableShipment);
        setBackorder(getBackorder() + back_log);
        return availableShipment;
    }
    else{
        availableShipment = demand;
        decreaseInventory(availableShipment);
        return availableShipment;
    }
}

/**
* @brief Set a Game.
* @param g The game object to be set.
*/

void Player::setGame(Game* g) {
    game =  g;
}

/**
* @brief Returns the Game.
*/

Game* Player::getGame() const {
    return game;
}

/**
* @brief Returns the Player Id.
*/

int Player::getPId() {
    return this->pId;
}

/**
* @brief Returns the Role.
*/

int Player::getRole() {
    return this->role;
}

/**
* @brief Returns the Inventory size.
*/

int Player::getInventory() {
    return this->inventory;
}

/**
* @brief Returns the value of current backorder of a player.
*/

int Player::getBackorder() {
    return this->backorder;
}


/**
* @brief Returns the value of beer demand for each player.
*/
int Player::getDemand() {
    return this->demand;
}

/**
* @brief Returns the value of the incoming order.
*/

int Player::getIncomingOrder() {
    return this->incomingOrder;
}

/**
* @brief Returns the value of the incoming shipment.
*/

int Player::getIncomingShipment() {
    return this->incomingShipment;
}

/**
* @brief Returns the value of the outgoing shipment.
*/

int Player::getOutgoingShipment() {
    return this->outgoingShipment;
}

/**
* @brief Returns the value of current cost of a player.
*/

double Player::getCost() {
    return this->cost;
}

/**
* @brief Returns the total cost of a player.
*/
int Player::getTotalCost() {
    return this->totalCost;
}


/**
* @brief Returns a bool value for whether the order is received or not.
*/
bool Player::getOrderReceived() {
    return this->orderReceived;
}

/**
* @brief Returns a bool value for whether the shipment is received or not.
*/
bool Player::getShipmentReceived() {
    return this->shipmentReceived;
}

/**
* @brief Returns a bool value for whether the order is placed or not.
*/
bool Player::getOrderPlaced() {
    return this->orderPlaced;
}


/**
* @brief Returns a bool value for whether the shipment is placed or not.
*/
bool Player::getShipmentPlaced() {
    return this->shipmentPlaced;
}
