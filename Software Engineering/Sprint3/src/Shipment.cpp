#include "Shipment.h"
#include <iostream>

Shipment::Shipment() {}

Shipment::Shipment(const Shipment &s) {
    shipmentId = s.shipmentId;
    shippedInWeek = s.shippedInWeek;
}

Shipment::Shipment(int newgId, int newShipmentId, int newReceivedInWeek, int newShippedInWeek, int newNumberOfBeers, Player *newReceiver) : PlayerEvent(newgId, newReceiver, newNumberOfBeers)
{
    shipmentId = newShipmentId;
    shippedInWeek = newShippedInWeek;
    receivedInWeek = newReceivedInWeek;
}

// Getters and Setters

int Shipment::getShipmentId() const
{
    return shipmentId;
}

void Shipment::setShipmentId(int newShipmentId)
{
    shipmentId = newShipmentId;
}

int Shipment::getShippedInWeek() const
{
    return shippedInWeek;
}

void Shipment::setShippedInWeek(int newShippedInWeek)
{
    shippedInWeek = newShippedInWeek;
}

int Shipment::getReceivedInWeek() const
{
    return receivedInWeek;
}

void Shipment::setReceivedInWeek(int newReceivedInWeek)
{
    Shipment::receivedInWeek = newReceivedInWeek;
}

//Additional Methods
void Shipment::executeShipment()
{
    // TODO
    //we decrease the inventory of the shipper by the numberOfBeers Ordered
}