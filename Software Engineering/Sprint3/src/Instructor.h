
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include <vector>
#include "Game.h"

using namespace std;

class Instructor
{
private:
    int instrID;          /*!< ID of the instructor */
    string instrEmail;    /*!< Email of the instructor */
    string instrPassword; /*!< Password of the instructor */
    vector<Game> games;   /*!< All games that have been created by the instructor */
    vector<int> checkGameStatus;

public:
    Instructor();  /*!< Default Constructor */
    ~Instructor(); /*!< Destructor */

    void showGamesStatus();                  /*!< Show the players' performance in the game */
    Game createGame();                        /*!< Create a game for players*/
    vector<Game> createGames(int numOfGames); /*!< Show game status here*/

    // Getters and Setters

    void setInstrId(int instrID);                /*!< Setter for instructor's ID */
    void setInstrEmail(string instrEmail);       /*!< Setter for instructor's email */
    void setInstrPassword(string instrPassword); /*!< Setter for instructor's password */
    void setGames(vector<Game> nGames);          /*!< Setter for instructor's games */

    string getInstrEmail() const;    /*!< Getter for instructor's ID */
    string getInstrPassword() const; /*!< Getter for instructor's email */
    int getInstrId() const;          /*!< Getter for instructor's password */
    vector<Game> getGames() const;   /*!< Getter for instructor's games */
    vector<int> checkingStatus();
};
#endif
