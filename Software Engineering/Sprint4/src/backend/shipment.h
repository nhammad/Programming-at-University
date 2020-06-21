/** 
 *  @file   shipment.h
 *  @brief  Settings of the shipment, which are set by the player in the game play
 ***************************************************************************************/

#ifndef _SHIPMENT_H
#define _SHIPMENT_H

#include "playerevent.h"
#include "player.h"

class Player;

/// @brief Class for setting and configuring the constraints of Player's Shipment
class Shipment : public PlayerEvent {

public:
    
    /// Default constructor 
    Shipment();
    
    /// @brief Construct a event object with a given different given parameters.
    /// @param receiver  The player who receives the shipment
    /// @param eventId  The Id of the event
    /// @param numberOfBeers The total number of beers involved in the shipment
    /// @param execInWeek The week of event shipment
    Shipment(Player* receiver, int eventId, int numberOfBeers, int execInWeek);

    /// @brief Execute the order for the player that is receiving the shipment
    void executeEvent();
};

#endif
