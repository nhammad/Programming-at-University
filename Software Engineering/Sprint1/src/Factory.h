/**
* \class Factory
* \author nhammad
* \date 17.03.2020
*/


#ifndef FACTORY_H
#define FACTORY_H

using namespace std;

/**
* This class represents a Factory which produces beer units that are used 
* throughout the game.
*/

class Factory
{
    int productionTime;
    int produced = 0;

public:
    Factory();
    int produce(int numberOfBeers);
    void setProduced(int newProduced);
    void setProductionTime(int newProductionTime);
    int getProduced();
    int getProductionTime();
};



#endif