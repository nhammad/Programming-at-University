#include <string>
#include <vector>
#include <iostream>

#include "game.h"
#include "instructor.h"
#include "../frontend/instructordialog.h"
#include "../frontend/ui_instructordialog.h"
#include "../frontend/playerdialog.h"



void Instructor::setUi(Ui::InstructorDialog *ui)
{
    this->ui = ui;
}

void Instructor::setParent(QWidget *parent_ui)
{
    this->parent_ui = parent_ui;
}

void Instructor::showGameStatus()
{
    std::cout << "Number of Games: " << games.size() << std::endl;
    std::cout << "Number of Players in Each Game: " << std::endl;
    for (unsigned i = 0; i < games.size(); i++)
    {
        std::cout << "Game " << i + 1 << ": " << (games.at(i))->getNPlayers() << "Players." << std::endl;
        checkGameStatus.push_back((games.at(i))->getNPlayers());
    }
}

Game* Instructor::createGame()
{
    // Get all the game setting that were given in the instructor dialog
    double backlogCost = ui->instructor_backlogCost->text().toDouble();
    double holdingCost = ui->instructor_holdingCost->text().toDouble();
    int orderDelay = ui->instructor_orderDelay->text().toInt();
    int totalWeeks = ui->instructor_totalWeeks->text().toInt();
    int startInventory = ui->instructor_startInventory->text().toInt();
    int factoryDelay = ui->instructor_factoryDelay->text().toInt();

    Game* newgame = new Game(instrId,
                             backlogCost,
                             holdingCost,
                             orderDelay,
                             totalWeeks,
                             startInventory,
                             factoryDelay);
    games.push_back(newgame);

    // Creating four players
    Player* consumer = new Player(newgame, CONSUMER);
    Player* retailer = new Player(newgame, RETAILER);
    Player* wholesaler = new Player(newgame, WHOLESALER);
    Player* distributor = new Player(newgame, DISTRIBUTOR);
    Player* factory = new Player(newgame, FACTORY);

    newgame->addPlayer(consumer);
    newgame->addPlayer(retailer);
    newgame->addPlayer(wholesaler);
    newgame->addPlayer(distributor);
    newgame->addPlayer(factory);

    // Creating the player dialogs for the ui
    std::vector<Player*> allPlayers {consumer, retailer, wholesaler, distributor, factory};

    PlayerDialog* C = new PlayerDialog(parent_ui, *newgame, consumer);
    PlayerDialog* R = new PlayerDialog(parent_ui, *newgame, allPlayers);
    PlayerDialog* W = new PlayerDialog(parent_ui,*newgame, allPlayers);
    PlayerDialog* D = new PlayerDialog(parent_ui,*newgame, allPlayers);
    PlayerDialog* F = new PlayerDialog(parent_ui,*newgame, allPlayers);

    R->move(0,0);
    W->move(1000,0);
    D->move(0,800);
    F->move(1000,800);

    C->hide();
    R->show();
    W->show();
    D->show();
    F->show();
    return newgame;

}

std::vector<Game*> Instructor::createGames(int numberOfGames)
{
    for (int i = 0 ;i <numberOfGames ;i++){
        this->createGame();
    }
    return games;
}


int Instructor::getInstrId() const
{
    return instrId;
}

void Instructor::setInstrId(int value)
{
    instrId = value;
}

std::string Instructor::getInstrEmail() const
{
    return instrEmail;
}

void Instructor::setInstrEmail(const std::string &value)
{
    instrEmail = value;
}

std::string Instructor::getInstrPassword() const
{
    return instrPassword;
}

void Instructor::setInstrPassword(const std::string &value)
{
    instrPassword = value;
}

std::vector<Game *> Instructor::getGames() const
{
    return games;
}

void Instructor::setGames(const std::vector<Game *> &value)
{
    games = value;
}

std::vector<int> Instructor::checkingStatus(){
    return checkGameStatus;
}