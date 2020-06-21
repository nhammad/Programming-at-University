
/**
* @class Shipment
* @file shipment.h
* @brief This header file contains the functionalities of a shipment.
*
*/

#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "playerEvent.h"

class Shipment : public PlayerEvent{

public:
    void executeShipment();
};

#endif
