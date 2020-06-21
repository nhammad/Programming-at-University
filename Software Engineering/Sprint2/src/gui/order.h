#ifndef ORDER_H
#define ORDER_H

#include <QDialog>

class Orders
{


public:
    Orders();
    ~Orders();
    void executeOrder();

private:
    int orderId;
    int gId;
    int fromPlayerId;
    int toPlayerId;
    int orderedInWeek;
    int shippedInWeek;
};
#endif // ORDER_H
