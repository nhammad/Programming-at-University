/** 
 *  @file   order.h
 *  @brief  Settings of the order, which are set by the player in the game play
 ***************************************************************************************/

#ifndef ORDER_H
#define ORDER_H

#include "playerevent.h"
#include "player.h"


class Player;

/// @brief Class for setting and configuring the constraints of Player's Order
class Order : public PlayerEvent {

public:
    /// Default constructor 
    Order();

    /// @brief Construct a event object with a given different given parameters.
    /// @param receiver  The player who receives the oder
    /// @param eventId  The Id of the event
    /// @param numberOfBeers The total number of beers involved in the order
    /// @param execInWeek The week of event order
    Order( Player* receiver, int eventId, int numberOfBeers, int execInWeek);
    
    /// @brief Execute the order for the player that is receiving the event
    void executeEvent();
};


#endif //ORDER_H
