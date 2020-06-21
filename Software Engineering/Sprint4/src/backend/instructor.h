/** 
 *  @file   instructor.h
 *  @brief  Defines the Instructor
 ************************************/

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <vector>
#include <string>

#include "game.h"
#include "../frontend/instructordialog.h"
#include "../frontend/ui_instructordialog.h"

/// @brief Class for defining an instructor, his ID, email, password and list of games
class Instructor 
{
public :
    /// @brief To set the UI
    void setUi(Ui::InstructorDialog* ui);
    void setParent(QWidget* parent_ui);

    /// @brief show game status
    void showGameStatus();

    /// @brief create game and apply all the game setting that were given in the instructor dialog
    Game* createGame();

    /// @brief create a certain amount of games
    /// @param numberOfGames number of games
    /// @returns vector of games
    std::vector<Game*> createGames(int numberOfGames);
private:
    Ui::InstructorDialog *ui;
    QWidget* parent_ui;

    /// @brief The instructor Id of the game
    int instrId;

    /// @brief The Instructor's Email
    std::string instrEmail;

    /// @brief The Instructor's Password
    std::string instrPassword;

    /// @brief The Instructor's list of created games
    std::vector<Game*> games;

    /// @brief Vector for Checking Game Status
    std::vector<int> checkGameStatus;
public:
    
    /// @brief Getter Method for Instructor's Id
    int getInstrId() const;
    void setInstrId(int value);

    /// @brief Getter Method for Instructor's Id
    std::string getInstrEmail() const;
    void setInstrEmail(const std::string &value);

    /// @brief Getter Method for Instructor's Id
    std::string getInstrPassword() const;
    void setInstrPassword(const std::string &value);

    std::vector<Game *> getGames() const;
    void setGames(const std::vector<Game *> &value);


    ///@brief Returns the vector of which contains info about number of players in each game. This is used to test for showGameStatus()
    std::vector<int> checkingStatus();
};

#endif // INSTRUCTOR_H
