/**
* @file instructor.h
* @brief This header file contains the functionalities of the instructor in the game.
*
*/


#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <vector>

#include "game.h"

class Instructor {

private:
	int instrId;
    std::string instrEmail;
    std::string instrPassword;
    std::vector<Game> games;

public:
    Instructor();
	void showGamesStatus();
    int createGame();
    Game createNewGame();
    std::vector<Game> createGames(int numberOfGames);

    //setters
    void setInstrEmail(std::string instrEmail);
    void setInstrId(int instrId);
    void setInstrPassword(std::string instrPassword);

    //getters
    std::string getInstrEmail();
    int getInstrId();
    std::string getInstrPassword();


    int checkGameVectorSize();
};

#endif
