
#include "PlayerEvent.h"

//-- PlayerEvent class methods --//

//Constructors

//! Default constructor.
/*!
          initializes a blank PlayerEvent.
        */
PlayerEvent::PlayerEvent(){}

//! Destructor.
/*!
          Removes a PlayerEvent.
        */
PlayerEvent::~PlayerEvent(){}

//! Parametric constructor.
/*!
          initializes a PlayerEvent with specified properties.
        */
PlayerEvent::PlayerEvent(int newgId, Player *newReceiver, int newNumberOfBeers){
    gId = newgId;
    receiver = newReceiver;
    numberOfBeers = newNumberOfBeers;
}

//Setters and Getters

/**
* @brief Set the id for an order.
* @param eventId The order Id
*/

void PlayerEvent::setEventId(int eventId) {
    this->eventId = eventId;
}

void PlayerEvent::setReceiver(Player* p){
    receiver = p;
}

Player* PlayerEvent::getReceiver() const{
    return receiver;
}

void PlayerEvent::setNumberOfBeers(int n)
{
    numberOfBeers = n;
}


/**
* @brief Set the Id of the Player who delivers the order.
* @param fromPlayerId Id of the Player who delivers the order.
*/

void PlayerEvent::setFromPlayerId(int fromPlayerId) {
    this->fromPlayerId = fromPlayerId;
}

/**
* @brief Set the Id of the Player who recieves/places the order.
* @param toPlayerId Id of the Player who recieves/places the order.
*/

void PlayerEvent::setToPlayerId(int toPlayerId) {
    this->toPlayerId = toPlayerId;
}

/**
* @brief Set the Week Number when the order was placed.
* @param orderedInWeek Week Number when the order was placed.
*/

void PlayerEvent::setOrderedInWeek(int orderedInWeek) {
    this->orderedInWeek = orderedInWeek;
}

/**
* @brief Set the Week Number when the order was shipped.
* @param shippedInWeek Week Number when the order was shipped.
*/

void PlayerEvent::setShippedInWeek(int shippedInWeek) {
    this->shippedInWeek = shippedInWeek;
}

/**
* @brief Returns the PlayerEvent Id.
*/

int PlayerEvent::getEventId() {
    return this->eventId;
}

/**
* @brief Returns the Number of Beers
*/
int PlayerEvent::getNumberOfBeers() const
{
    return numberOfBeers;
}

/**
* @brief Returns the Game Id.
*/
int PlayerEvent::getGId() const
{
    return gId;
}

/**
* @brief Returns the Type of the Player Event. "o" for Order and "s" for Shipment.
*/
std::string PlayerEvent::getType() 
{
    return type;
}

/**
* @brief Sets the Game Id.
* @param newgId Game Id
*/
void PlayerEvent::setGId(int newgId)
{
    gId = newgId;
}

/**
* @brief Sets the Type of the Player Event. "o" for Order and "s" for Shipment.
* @param newType Game Type
*/
void PlayerEvent::setType(std::string newType)
{
    type = newType;
}

/**
* @brief Returns the Player Id who delivers the order.
*/

int PlayerEvent::getFromPlayerId() {
    return this->fromPlayerId;
}

/**
* @brief Returns the Player Id who places the order.
*/
int PlayerEvent::getToPlayerId() {
    return this->toPlayerId;
}

/**
* @brief Returns the Week number when the order was placed.
*/

int PlayerEvent::getOrderedInWeek() {
    return this->orderedInWeek;
}

/**
* @brief Returns the Week number when the order was shipped.
*/
int PlayerEvent::getShippedInWeek() {
    return this->shippedInWeek;
}
