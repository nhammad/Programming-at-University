/**
* \class Instructor
* \author nhammad
* \date 17.03.2020
*/

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

/**
* This class represents an Instructor who then manages players.
*/


class Instructor
{
    int instrId;
    string instrEmail;
    string instrPassword;

public:
    Instructor();
    void showGameStatus();
    int createGame();                           
    vector<int> createGames(int numberOfGames); 
    void setInstrId(int newInstrId);
    void setInstrEmail(string newInstrEmail);
    void setInstrPassword(string newInstrPassword);
    int getInstrId();
    string getInstrEmail();
    string getInstrPassword();
};


#endif