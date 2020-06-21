/** 
 *  @file   playerevent.h
 *  @brief  Settings of the playerevent, which are set by the player in the game play
 ***************************************************************************************/

#include "player.h"

#ifndef _PLAYER_EVENT_H
#define _PLAYER_EVENT_H

class Player;

/// @brief Class for setting and configuring the constraints of Player Events
class PlayerEvent {

public:
    /// Default constructor 
    PlayerEvent();
    /// @brief Construct a event object with a given different given parameters.
    /// @param receiver  The player who receives the event type
    /// @param eventId  The Id of the event
    /// @param numberOfBeers The total number of beers involved in the event
    /// @param orderedInWeek The week of event order/shipment 
    PlayerEvent(Player* receiver, int eventId, int numberOfBeers, int orderedInWeek);
    
    /// @brief Execute the event for the player that is receiving the event
    void executeEvent() const;

protected:
    /// @brief The player who receives the event type
    Player *receiver;
    /// @brief The Id of the event
    int eventId;
    /// @brief The Id of the game
    int gId;
    /// @brief The total number of beers involved in the event
    int numberOfBeers;
    /// @brief The week of event order
    int orderedInWeek;
    /// @brief The week of event shipment 
    int shippedInWeek;
    /// @brief The Id of the receiving player
    int toPlayerId;
    /// @brief The Id of the sending player
    int fromPlayerId;

public:

    /**
     *  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
     *
     *   Implementation of getters and setter for this class
     *
     * $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
     */
    Player *getReceiver() const;
    void setReceiver(Player *value);
    
    int getEventId() const;
    void setEventId(int value);
    
    int getGId() const;
    void setGId(int value);
    
    int getNumberOfBeers() const;
    void setNumberOfBeers(int value);
    
    int getOrderedInWeek() const;
    void setOrderedInWeek(int value);
    
    int getShippedInWeek() const;
    void setShippedInWeek(int value);
    
    int getToPlayerId() const;
    void setToPlayerId(int value);
    
    int getFromPlayerId() const;
    void setFromPlayerId(int value);
};

#endif // PLAYEREVENT_H
