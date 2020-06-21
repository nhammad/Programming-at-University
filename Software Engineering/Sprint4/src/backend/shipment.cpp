#include "playerevent.h"
#include "shipment.h"
#include "player.h"

Shipment::Shipment() : PlayerEvent(NULL,0,0,0){}

Shipment::Shipment(Player *receiver, int eventId, int numberOfBeers, int execInWeek) :
    PlayerEvent(receiver, eventId, numberOfBeers, execInWeek)
{

}
void Shipment::executeEvent()
{
    receiver->receiveShipment(numberOfBeers);
}
