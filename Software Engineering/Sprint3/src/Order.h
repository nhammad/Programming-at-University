/*! \file Order.h
    \brief File containing the implementation of Order class.
    
    This class stores information related to the orders made by players, so they can be treated as individual objects.
*/
/*! \class Order
    \brief The Order class.

    This class creates Orders as objects with important properties 
    that ensure they get sent from one player to the correct destination player.

    Inherits from PlayerEvent class.
*/


#ifndef ORDER_H
#define ORDER_H

#include "PlayerEvent.h"


class Order : public PlayerEvent
{
private:
    int orderId; /*!< Unique identifier for an Order. */
    int orderedInWeek; /*!< The week in which an order was placed. */
    int shippedInWeek; /*!< The week in which the order is expected to arrive.  */

public:
    //! Default constructor.
    /*!
          initializes a blank Order.
        */
    Order();

    //! Parametric constructor.
    /*!
          initializes an Order with specified properties.
        */
    Order(int newgId, int newOrderId, int newOrderedInWeek, int newShippedInWeek, int newNumberOfBeers, Player *newReceiver);

    void executeOrder(); /*!< Sends the order to its destination in the specified week. */


    // Getters and Setters:

/**
* @brief getter for order id
* @return order id
*/
    int getOrderId() const;

/**
* @brief setter for order id
* @param orderId
* @return 
*/
    void setOrderId(int orderId);

/**
* @brief getter for number of items ordered in the week
* @return number of items ordered in the week
*/
    int getOrderedInWeek() const;

/**
* @brief setter for number of items ordered in the week
* @param orderedInWeek
* @return number of items ordered in the week
*/
    void setOrderedInWeek(int orderedInWeek);

/**
* @brief getter for number of items shipped in the week
* @return number of items shipped in the week
*/
    int getShippedInWeek() const;

/**
* @brief setter for number of items shipped in the week
* @param shippedInWeek
* @return 
*/
    void setShippedInWeek(int shippedInWeek);
};

#endif 