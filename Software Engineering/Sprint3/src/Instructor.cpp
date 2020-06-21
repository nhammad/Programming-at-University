
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include "Instructor.h"
using namespace std;

/**
* @brief Default Constructor
*/
Instructor::Instructor()
{
}
/**
* @brief Destructor
*/
Instructor::~Instructor()
{
}

/**
* @brief Shows Number of Players in Each Game and adds the numbers to a vector for testing later
*/
void Instructor::showGamesStatus()
{
   cout << "Number of Games: " << games.size() << endl;
   cout << "Number of Players in Each Game: " << endl;
   for (unsigned i = 0; i < games.size();i++){
       cout << "Game " << i+1 << ": " << (games.at(i)).getNumberOfPlayers() << "Players." << endl;
       checkGameStatus.push_back((games.at(i)).getNumberOfPlayers());
   }
}

/**
* @brief Creates and stores n games in a vector.
* @return Game 
*/
Game Instructor::createGame()
{
    Game *newGame;
    int gameId = rand() % 100;
    vector<Player*> players;
    unordered_map<int, vector<Order>> orders;
    unordered_map<int, vector<Shipment>> shipments;
    vector<int> demands;

    for (int i = 0; i < 20; i++)
    {
        demands.push_back(rand() % 50);
    }

    for (int i = 0; i < 4; i++)
    {
        Player p(i + 1, i, NULL);
        players.push_back(&p);
       
    }
    newGame = new Game(gameId, this->instrID, players[0]->getPId(),
                       players[1]->getPId(), players[2]->getPId(), players[3]->getPId(),
                       2.0, 1.5, 20, 20, 0, 0, 2, 2, 2, 4, players, orders, shipments,
                       demands);
                       

    for (int i = 0; i < 4; i++)
    {
        players[i]->setGame(newGame);
    }
    return *newGame; 
}



// Game Instructor::createGame() {
// 	Game g;
// 	games.push_back(g);
// 	return g;
// }

/**
* @brief Creates and stores n games in a vector.
* @param numberOfGames Number of Games to be created.
*/

std::vector<Game> Instructor::createGames(int numberOfGames) {
	for (int i = 0; i < numberOfGames; i++){
		Game g = createGame();
		games.push_back(g);
	}
	return games;
}

// Getters and Setters

/**
* @brief Set an email address for an instructor.
* @param instrEmail Email address for the instructor.
*/

void Instructor::setInstrEmail(std::string instrEmail)
{
    this->instrEmail = instrEmail;
}

/**
* @brief Returns an instructor's Email.
*/
std::string Instructor::getInstrEmail() const
{
    return this->instrEmail;
}

/**
* @brief Set a Password for an instructor.
* @param instrPassword Password for the instructor.
*/
void Instructor::setInstrPassword(std::string instrPassword)
{
    this->instrPassword = instrPassword;
}

/**
* @brief Returns an instructor's password.
*/
std::string Instructor::getInstrPassword() const
{
    return this->instrPassword;
}

/**
* @brief Returns an instructor's ID.
*/
void Instructor::setInstrId(int instrID)
{
    this->instrID = instrID;
}

/**
* @brief Set an ID to distinguish between instructors.
*/
int Instructor::getInstrId() const
{
    return this->instrID;
}

/**
* @brief Takes a vector of games as an input and sets the main games vector.
* @param nGames vector of games to be played.
*/
void Instructor::setGames(vector<Game> nGames)
{
    games = nGames;
}

/**
* @brief Returns the vector of games to be played.
*/
vector<Game> Instructor::getGames() const
{
    return games;
}

/**
* @brief Returns the vector of which contains info about number of players in each game. This is used to test for showGameStatus()
*/
vector<int> Instructor::checkingStatus(){
    return checkGameStatus;
}
