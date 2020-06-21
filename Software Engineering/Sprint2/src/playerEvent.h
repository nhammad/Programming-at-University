/**
* @file playerEvent.h
* @brief This header file contains the functionalities to keep track of the orders.
*
*/

#ifndef PLAYEREVENT_H
#define PLAYEREVENT_H

#include "player.h"

class PlayerEvent {

private:
	int eventId;
  	int gId;
	int numberOfBeers;
	int orderedInWeek;
	int shippedInWeek;
	Player* receiver;
	int toPlayerId;
  	int fromPlayerId;

public:
	//setters
	void setEventId(int eventId);
	void setGId(int gId);
	void setFromPlayerId(int fromPlayerId);
	void setToPlayerId(int toPlayerId);
	void setOrderedInWeek(int orderedInWeek);
	void setShippedInWeek(int shippedInWeek);
	void setNumberOfBeers(int numberOfBeers);
	void setReceiver(Player* receiver);

	//getters
	int getEventId();
	int getGId();
	int getFromPlayerId();
	int getToPlayerId();
	int getOrderedInWeek();
	int getShippedInWeek();
	int getNumberOfBeers();
	Player* getReceiver() const;
};

#endif
