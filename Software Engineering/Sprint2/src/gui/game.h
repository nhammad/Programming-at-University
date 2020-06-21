#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "players_playing.h"
#include "player_password.h"
#include "print_passwords.h"
#include "order.h"
#include "factory.h"

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    void executeOrdersForCurrentWeek();
    void updatePlayerInventories();
    void advanceWeek();
    void addOrder(Orders order);
    void setWeeksToBePlayed(int w);
    void setInfoCode(int code);
    void setStartingInventory(int si);
    void setBackorderCost(double cost);
    void setHoldingCost(double hc);
    QVector<QString> generatePasswords();
    int getCurrentWeek();
    void setCurrentWeek(int week);
    int getWeeksToBePlayed();
    int getInfoCode();
    int getStartingInventory();
    double getBackorderCost();
    double getHoldingCost();
    QVector<int> getOrdersToBeExecuted();

private:
    Ui::Game *ui;
    Player_password * Player_Password;
    Players_playing * Player_Playing;
    Orders * Order;
    Factory * factory;
    int gId;
    int instrId;
    int pFactId;
    int pDistributorId;
    int pWholesalerId;
    int pRetailerId;
    QVector<int> ordersToBeExecuted;
    QVector<int> demandPerWeek;
    int orderTimeDelay;
    double holdingCost;
    double backorderCost;
    int startingInventory;
    int weeksToBePlayed;
    int currentWeek;
    int infoCode;
};

#endif // GAME_H
