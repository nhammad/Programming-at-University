
/**
* @file instructor.cpp
*
*/
#include "instructor.h"
#include <iostream>
#include <vector>

Instructor::Instructor()
{
	std::cout << "Creating An Instructor" << std::endl;
}

/**
* @brief Shows the current game status.
*/

void Instructor::showGamesStatus() {
	// TODO - implement Instructor::showGamesStatus
	throw "Not yet implemented";
}

/**
* @brief Initializes a new game and returns its id.
*/

int Instructor::createGame() {
	Game g;
	return g.getGId();
}

/**
* @brief Initializes a new game and returns the game object itself.
*/
Game Instructor::createNewGame() {
	Game g;
	games.push_back(g);
	return g;
}

/**
* @brief Creates and stores n games in a vector.
* @param numberOfGames Number of Games to be created.
*/

std::vector<Game> Instructor::createGames(int numberOfGames) {
	for (int i = 0; i < numberOfGames; i++){
		Game g;
		games.push_back(g);
	}
	return games;
}

/**
* @brief Set an ID to distinguish between instructors.
* @param instrId Id for the instructor.
*/

void Instructor::setInstrId(int instrId) {
	this->instrId = instrId;
}

/**
* @brief Set an email address for an instructor.
* @param instrEmail Email address for the instructor.
*/

void Instructor::setInstrEmail(std::string instrEmail) {
	this->instrEmail = instrEmail;
}

/**
* @brief Set a Password for an instructor.
* @param newInstrPassword Password for the instructor.
*/

void Instructor::setInstrPassword(std::string instrPassword) {
	this->instrPassword = instrPassword;
}

/**
* @brief Returns an instructor's ID.
*/

int Instructor::getInstrId() {
	return instrId;
}

/**
* @brief Returns an instructor's email address..
*/

std::string Instructor::getInstrEmail() {
	return instrEmail;
}

/**
* @brief Returns an instructor's password.
*/

std::string Instructor::getInstrPassword() {
	return instrPassword;
}

/**
* @brief Returns the number of games present in the games vector.
*/

int Instructor::checkGameVectorSize() {
	return games.size();
}
