/** 
 *  @file   playerdialog.h
 *  @brief  This is the window of the game that pops up for player after login.
 ***************************************************************************************/

#ifndef PLAYERDIALOG_H
#define PLAYERDIALOG_H

#include <QDialog>
#include <vector>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>

#include "../backend/player.h"
#include "../backend/game.h"


class Game;
class Player;

namespace Ui
{
class PlayerDialog;
}
/// @brief Class for setting the window for players in Beer Game
class PlayerDialog : public QDialog
{
    Q_OBJECT

public:
    /// @brief Construct a player dialog
    /// @param parent  The parent ui for the class
    /// @param game  The game pointer of the player's game
    /// @param player  The pointer of the player linked with the player dialog
    PlayerDialog(QWidget *parent, Game &game, Player *player);

    /// @brief Construct a player dialog
    /// @param parent  The parent ui for the class
    /// @param game  The game pointer of the player's game
    /// @param allPlayers  The vector of pointers of the players linked with the player dialog
    explicit PlayerDialog(QWidget *parent, Game &game, std::vector<Player *> allPlayers);

    /// Default destructor
    ~PlayerDialog();
    /// @brief Function to set the player class ui with plyerdialog's ui
    void setPlayerUI();
    /// @brief Method to get the Player linked with the Playerdialog
    Player *getPlayer() const;
    /// @brief Method to set the Player linked with the Playerdialog
    void setPlayer(Player *value);

    /// @brief Method for the UI to wait until all the players are ready and to start the game
    void startGame();

    // Helper Function
    /// @brief Helper function to set the UI's images
    void setStackWidgetUI();

private slots:

    /// @brief Method for role selection (button) for player in their interface
    void on_retailer_btn_clicked();
    /// @brief Method for role selection (button) for player in their interface
    void on_wholesaler_btn_clicked();
    /// @brief Method for role selection (button) for player in their interface
    void on_distributor_btn_clicked();
    /// @brief Method for role selection (button) for player in their interface
    void on_factory_btn_clicked();
    /// @brief Method for role selection (button) for player in their interface
    void on_player_order_clicked();
    /// @brief Method for player to exit the game
    void on_pushButton_clicked();
    /// @brief Method for player to exit the game
    void on_stat_btn_clicked();
    /// @brief Method for player to see the current game
    void on_current_game_clicked();
    /// @brief Method for player to see the the line graph
    void on_linegraph_check_stateChanged(int arg1);
    /// @brief Method for player to exit the game
    void on_pushButton_2_clicked();

    void on_show_incoming_stateChanged(int arg1);
    void on_show_outgoing_stateChanged(int arg1);

private:
    /// @brief The ui of the main window
    Ui::PlayerDialog *ui;
    /// @brief The game pointer of the player's game
    Game &game;
    /// @brief The pointer of the player linked with the player dialog
    Player *player;
    /// @brief The vector of pointers of the players linked with the player dialog
    std::vector<Player *> allPlayers;

    QtCharts::QLineSeries *series;
    QtCharts::QStackedBarSeries *bseries;
    QtCharts::QChart *chart;
    QtCharts::QChartView *chartView;

};

#endif // PLAYERDIALOG_H
