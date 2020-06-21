#include <iostream>
#include "Factory.h"
using namespace std;

/**
* Default Constructor to initialize a Factory and its produced beer units.
*/

Factory::Factory()
{
    produced = 0;
    productionTime = 2;
}

/**
* Produces beer units are to be distributed in the whole game.
* @param numberOfBeers Number of beer units that are to be produced.
*/
int Factory::produce(int numberOfBeers)
{
    produced += numberOfBeers;
    return produced;
}

/**
* Set the number of beer units that are produced and are ready to be used
* by other players.
* @param newProduced Number of beer units that are produced and are ready to be used
* by other players.
*/

void Factory::setProduced(const int newProduced)
{
     produced = newProduced;
}

/**
* Set the time taken for production.
* @param newProductionTime Production time in weeks.
*/

void Factory::setProductionTime(const int newProductionTime)
{
     productionTime = newProductionTime;
}


/**
* Returns the qunatity of beer units that have been produced.
*/

int Factory::getProduced()
{
    return produced;
}

/**
* Returns the production time (in weeks)
*/

int Factory::getProductionTime()
{
    return productionTime;
}

