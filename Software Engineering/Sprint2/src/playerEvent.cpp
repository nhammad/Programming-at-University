/**
* @file playerEvent.cpp
*
*/
#include "playerEvent.h"

/**
* @brief Set the id for an order.
* @param orderId The order Id
*/

void PlayerEvent::setEventId(int eventId) {
    this->eventId = eventId;
}

/**
* @brief Set the id for a Game.
* @param gId The game id
*/

void PlayerEvent::setGId(int gId) {
    this->gId = gId;
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
* @brief Set the Quantity of beer units in the order.
* @param numberOfBeers Quantity of beer units in the order.
*/

void PlayerEvent::setNumberOfBeers(int numberOfBeers) {
    this->numberOfBeers = numberOfBeers;
}

/**
* @brief Set the Receiver Player,
* @param newReceiver Player who receives.
*/

void PlayerEvent::setReceiver(Player* newReceiver) {
    receiver = newReceiver;
}

/**
* @brief Returns the Reciever Player.
*/

Player* PlayerEvent::getReceiver() const {
    return receiver;
}

/**
* @brief Returns the PlayerEvent Id.
*/

int PlayerEvent::getEventId() {
    return this->eventId;
}

/**
* @brief Returns the Game Id.
*/

int PlayerEvent::getGId() {
    return this->gId;
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

/**
* @brief Returns the quantity of beer units in the order.
*/
int PlayerEvent::getNumberOfBeers() {
    return this->numberOfBeers;
}
