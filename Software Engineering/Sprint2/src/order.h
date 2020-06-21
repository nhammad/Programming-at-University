
/**
* @file order.h
* @brief This header file contains the functionalities of an order.
*
*/


#ifndef ORDER_H
#define ORDER_H

//#include "playerEvent.h"

class Order {
private:
  int numberOfBeers1;

public:
    void executeOrder();
    void setNumberOfBeers(int);

    //Order operator = (Order OrderIn);
};

#endif
