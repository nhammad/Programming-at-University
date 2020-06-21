#include "playerevent.h"
#include "player.h"

PlayerEvent::PlayerEvent(){};

PlayerEvent::PlayerEvent(Player* receiver, int eventId, int numberOfBeers, int orderedInWeek) :
    receiver(receiver),
    eventId(eventId),
    numberOfBeers(numberOfBeers),
    orderedInWeek(orderedInWeek)
{}

/**
 *  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 *
 * \brief Implementation of getters and setter for this class
 *
 * $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 */

int PlayerEvent::getFromPlayerId() const
{
    return fromPlayerId;
}

void PlayerEvent::setFromPlayerId(int value)
{
    fromPlayerId = value;
}

int PlayerEvent::getToPlayerId() const
{
    return toPlayerId;
}

void PlayerEvent::setToPlayerId(int value)
{
    toPlayerId = value;
}

int PlayerEvent::getShippedInWeek() const
{
    return shippedInWeek;
}

void PlayerEvent::setShippedInWeek(int value)
{
    shippedInWeek = value;
}

int PlayerEvent::getOrderedInWeek() const
{
    return orderedInWeek;
}

void PlayerEvent::setOrderedInWeek(int value)
{
    orderedInWeek = value;
}

int PlayerEvent::getNumberOfBeers() const
{
    return numberOfBeers;
}

void PlayerEvent::setNumberOfBeers(int value)
{
    numberOfBeers = value;
}

int PlayerEvent::getGId() const
{
    return gId;
}

void PlayerEvent::setGId(int value)
{
    gId = value;
}

int PlayerEvent::getEventId() const
{
    return eventId;
}

void PlayerEvent::setEventId(int value)
{
    eventId = value;
}

Player *PlayerEvent::getReceiver() const
{
    return receiver;
}

void PlayerEvent::setReceiver(Player *value)
{
    receiver = value;
}
