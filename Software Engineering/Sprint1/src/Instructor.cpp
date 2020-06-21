#include <iostream>
#include "Instructor.h"
#include "Game.h"
using namespace std;

/**
* Default Constructor to initialize an Instructor with default values
* for instructor Id, email and password.
*/

Instructor::Instructor()
{
    instrId = 0;
    instrEmail = "@jaocbs-university.de";
    instrPassword = "123";
}

/**
* Shows the current game status.
*/
void Instructor::showGameStatus()
{

}

/**
* Initializes a new game.
*/

int Instructor::createGame()
{
    Game g;
}

/**
* Stores games in a vector.
*/
vector<int> Instructor::createGames(int numberOfGames)
{
}

/**
* Set an ID to distinguish between instructors.
* @param newInstrId Id for the instructor.
*/

void Instructor::setInstrId(const int newInstrId)
{
     instrId = newInstrId;
}

/**
* Set an email address for an instructor.
* @param newInstrEmail Email address for the instructor.
*/

void Instructor::setInstrEmail(const string newInstrEmail)
{
     instrEmail = newInstrEmail;
}

/**
* Set a Password for an instructor. 
* @param newInstrPassword Password for the instructor.
*/

void Instructor::setInstrPassword(const string newInstrPassword)
{
     instrPassword = newInstrPassword;
}

/**
* Returns an instructor's ID.
*/

int Instructor::getInstrId()
{
    return instrId;
}

/**
* Returns an instructor's email address..
*/

string Instructor::getInstrEmail()
{
    return instrEmail;
}

/**
* Returns an instructor's password.
*/

string Instructor::getInstrPassword()
{
    return instrPassword;
}