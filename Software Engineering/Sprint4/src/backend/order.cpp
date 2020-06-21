#include "playerevent.h"
#include "order.h"
#include "player.h"

Order::Order() : PlayerEvent(NULL,0,0,0){}

Order::Order(Player *receiver, int eventId, int numberOfBeers, int execInWeek) :
    PlayerEvent(receiver, eventId, numberOfBeers, execInWeek)
{}

void Order::executeEvent()
{
    receiver->receiveOrder(numberOfBeers);
}
