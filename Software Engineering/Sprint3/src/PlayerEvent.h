/*! \file PlayerEvent.h
    \brief File containing the implementation of PlayerEvent class.
    
    This class stores information related to the Player Events issued by players - either as Orders or Shipments - and creates corresponding objects accordingly
*/
/*! \class PlayerEvent
    \brief The PlayerEvent class.

    This class creates PlayerEvents as objects with important properties 
    that ensure they get sent from one player to the correct destination player.

*/

#ifndef PLAYEREVENT_H
#define PLAYEREVENT_H

#include "Player.h"
#include <string>

class PlayerEvent{

    public:
        int eventId;
        int gId; /*!< Unique ID for the game to which a PlayerEvent belongs. */
        Player *receiver; /*!< The player receiving the action of the event. */
        int numberOfBeers; /*!< The number of beers being sent/received. */
        int toPlayerId;
    	int fromPlayerId;
        int orderedInWeek;
	    int shippedInWeek;
        std::string type = "o";
        PlayerEvent();
        ~PlayerEvent();
        PlayerEvent(int newgId, Player* newReceiver, int newNumberOfBeers);

        void setReceiver(Player* player);
        void setFromPlayerId(int fromPlayerId);
	    void setToPlayerId(int toPlayerId);
        void setNumberOfBeers(int n);
        void setGId(int newgId);
        void setType(std::string newType);
        void setEventId(int eventId);
        void setOrderedInWeek(int orderedInWeek);
	    void setShippedInWeek(int shippedInWeek);


        Player* getReceiver() const;
        int getNumberOfBeers() const;
        int getGId() const;
        std::string getType();
        int getFromPlayerId();
	    int getToPlayerId();
        int getEventId();
        int getOrderedInWeek();
	    int getShippedInWeek();
};


#endif 
