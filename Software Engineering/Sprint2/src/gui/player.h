
#ifndef PLAYER_H
#define PLAYER_H

#include <QDialog>

namespace Ui {
class player;
}

class player : public QDialog
{
    Q_OBJECT

public:
    explicit player(QWidget *parent = 0);
    ~player();
    void order(int numberOfBeers, player from);
    void ship(int numberOfBeers, player from);
    void decreaseInventory(int numberOfBeers);
    void increaseInventory(int numberOfBeers);
    int getBackorder();
    int getCost();
    int getInventory();
    void setBackorder(int backorder);
    void setCost(int cost);
    void setInventory(int inventory);
    void setDemand(int demand);
    int getDemand();
    void setOrder(int order);
    int getOrder();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_SignIn_clicked();

private:
    Ui::player *ui;
    int pId;
    enum role{Factory=1, Distributer = 2, Wholesaler= 3, Retailer=4};
    int inventory;
    int backorder;
    double cost;
    int shipmentDelay;
    int orderDelay;
    int demand;
    int Order;
};

#endif // PLAYER_H
