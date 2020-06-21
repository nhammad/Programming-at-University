/*! \file Shipment.h
    \brief File containing the implementation of Shipment class.
    
    This class stores information related to the shipments made by players, so they can be treated as individual objects.
*/
/*! \class Shipment
    \brief The Shipment class.

    This class creates Shipments as objects with important properties 
    that ensure they get sent from one player to the correct destination player.

    Inherits from PlayerEvent class.
*/

#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "PlayerEvent.h"

class Shipment : public PlayerEvent
{
private:
    int shipmentId; /*!< Unique identifier for a Shipment. */
    int shippedInWeek; /*!< The week in which a shipment was dispatched. */
    int receivedInWeek; /*!< The week in which the shipment is expected to arrive.  */

public:

    //! Default constructor.
    /*!
          initializes a blank Shipment.
        */
    Shipment();

    //! Copy constructor.
    /*!
          initializes a duplicate Shipment.
        */
    Shipment(const Shipment &s);

    //! Parametric constructor.
    /*!
          initializes an Shipment with specified properties.
        */
    Shipment(int newgId, int newShipmentId, int newReceivedInWeek, int newShippedInWeek, int newNumberOfBeers, Player *newReceiver);

/**
* @brief Sends the shipment to the required unit
*/
    void executeShipment(); 


/**
* @brief getter for shipment ID
* @return ShipmentId 
*/
    int getShipmentId() const;

/**
* @brief setter for shipment ID
* @param shipmentId 
*/
    void setShipmentId(int shipmentId);

/**
* @brief returns amount of items shipped in a week
* @return amount of items shipped in a week
*/
    int getShippedInWeek() const;

/**
* @brief Setter for amount of items shipped in a week
* @param shippedInWeek
*/
    void setShippedInWeek(int shippedInWeek);

/**
* @brief Getter for amount of items shipped in a week
* @return amount of items received in week
*/
    int getReceivedInWeek() const;

/**
* @brief Setter for amount of items shipped in a week
* @param receivedInWeek
* @return 
*/
    void setReceivedInWeek(int receivedInWeek);
};

#endif //SE_04_TEAM_18_SHIPMENT_H