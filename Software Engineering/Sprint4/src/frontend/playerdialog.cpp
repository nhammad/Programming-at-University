#include "../backend/player.h"

#include "playerdialog.h"
#include "ui_playerdialog.h"

#include <QMessageBox>
#include <QPixmap>
#include <string>


void PlayerDialog::setStackWidgetUI()
{
    ui->stat_btn->setEnabled(false);
    QPixmap user(":/resources/images/user.png");
    ui->label_user->setPixmap(user.scaled(120,120, Qt::KeepAspectRatio));

    QPixmap retailer(":/resources/images/retailer.png");
    ui->label_retailer->setPixmap(retailer.scaled(100,100, Qt::KeepAspectRatio));

    QPixmap wholesaler(":/resources/images/wholesaler.png");
    ui->label_wholesaler->setPixmap(wholesaler.scaled(100,100, Qt::KeepAspectRatio));

    QPixmap distributor(":/resources/images/distributor.png");
    ui->label_distributor->setPixmap(distributor.scaled(100,100, Qt::KeepAspectRatio));

    QPixmap factory(":/resources/images/factory.png");
    ui->label_factory->setPixmap(factory.scaled(100,100, Qt::KeepAspectRatio));

}

PlayerDialog::PlayerDialog(QWidget *parent, Game &game, Player *player):
    QDialog(parent),
    ui(new Ui::PlayerDialog),
    game(game),
    player(player)
{
    ui->setupUi(this);
    setPlayerUI();
    setStackWidgetUI();
    ui->stackedWidget->setCurrentIndex(0);
}

PlayerDialog::PlayerDialog(QWidget *parent,Game& game, std::vector<Player*> allPlayers) :
    QDialog(parent),
    ui(new Ui::PlayerDialog),
    game(game),
    allPlayers(allPlayers)
{

    ui->setupUi(this);
    setStackWidgetUI();
    ui->stackedWidget->setCurrentIndex(0);
}

PlayerDialog::~PlayerDialog()
{
    delete ui;
}

void PlayerDialog::setPlayerUI()
{
    player->setUi(ui);
}

void PlayerDialog::on_stat_btn_clicked()
{   
    // Statistics
    std::vector<int> orders = player->getOrderHistory();
    std::vector<int> incomingShipment = player->getIncomingShipmentHistory();
    std::vector<int> outgoingShipment= player->getOutgoingShipmentHistory();

//    std::vector<int> orders = {1,4,3,4,5,6,7,12};
//    std::vector<int> incomingShipment =  {2,5,6,2,3,11,10,2};;
//    std::vector<int> outgoingShipment=  {8,7,6,5,4,3,2,1};

    ui->stat_widget->removeWidget(chartView);

    //Setting charts
    chart = new QtCharts::QChart();
    chart->legend()->hide();
    chart->setTitle("Player Stats");
    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);
    // setting different types of series

    if(ui->linegraph_check->isChecked()){
        series = new QtCharts::QLineSeries();

        QtCharts::QLineSeries *set_incoming = new QtCharts::QLineSeries();
        QtCharts::QLineSeries *set_outgoing = new QtCharts::QLineSeries();

        QtCharts::QValueAxis *axisX = new  QtCharts::QValueAxis();
        QtCharts::QValueAxis *axisY = new  QtCharts::QValueAxis();
        for(unsigned int i =0 ; i < orders.size();i++){
            series->append(i,orders[i]);
            set_incoming->append(i,incomingShipment[i]);
            set_outgoing->append(i,outgoingShipment[i]);
        }
        chart->addSeries(series);

        if(ui->show_incoming->isChecked()){
            chart->addSeries(set_incoming);
        }
        if(ui->show_outgoing->isChecked()){
            chart->addSeries(set_outgoing);
        }

        axisX->setLabelFormat("%d");
        chart->addAxis(axisX, Qt::AlignBottom);
        axisY->setLabelFormat("%.1f");
        chart->addAxis(axisY, Qt::AlignLeft);
        axisX->setTickCount(orders.size());
        series->attachAxis(axisX);
        series->attachAxis(axisY);

     } else {
        // Enable Barchart
        bseries = new QtCharts::QStackedBarSeries(chart);
        QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
        QStringList categories;
        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
        QtCharts::QBarSet *set = new QtCharts::QBarSet("Order");


        QtCharts::QBarSet *set_incoming = new QtCharts::QBarSet("Incoming ");
        QtCharts::QBarSet *set_outgoing = new QtCharts::QBarSet("Outgoing ");

        for (unsigned int i= 0; i < orders.size(); i++) {
            *set << orders[i];
            *set_incoming << incomingShipment[i];
            *set_outgoing<< outgoingShipment[i];
            categories << QString::number(i);

            bseries->append(set);

            if(ui->show_incoming->isChecked()){
                bseries->append(set_incoming);
            }
            if(ui->show_outgoing->isChecked()){
                bseries->append(set_outgoing);
            }
        }
        axisX->append(categories);
        chart->addSeries(bseries);

        chart->addAxis(axisX, Qt::AlignBottom);
        bseries->attachAxis(axisX);
        axisY->setLabelFormat("%d");
        chart->addAxis(axisY, Qt::AlignLeft);
        bseries->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    }
   // Setting series to the charts
   chartView = new QtCharts::QChartView(chart);
   chartView->setRenderHint(QPainter::Antialiasing);

   ui->stat_widget->addWidget(chartView);
   ui->stackedWidget->setCurrentIndex(2);

}

void PlayerDialog::on_current_game_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void PlayerDialog::on_retailer_btn_clicked()
{
    int retailerPlayer = game.getPRetailerId();
    if(retailerPlayer == 0){
        setPlayer(allPlayers[1]);
        ui->stackedWidget->setCurrentIndex(1);
        game.setPRetailerId(game.getGId()+1);
        this->setWindowTitle(QString::fromStdString(GLOBAL_PLAYERS[1]));
        ui->gameplayscreen->setTitle(QString::fromStdString(GLOBAL_PLAYERS[1]));
        setPlayerUI();
        startGame();
    }else{
        QMessageBox::information(this,"Player Choose", "Role alreday chosen");
    }
}

void PlayerDialog::on_wholesaler_btn_clicked()
{
    int wholesalerPlayer = game.getPWholesalerId();
    if(wholesalerPlayer == 0){
        setPlayer(allPlayers[2]);
        ui->stackedWidget->setCurrentIndex(1);
        game.setPWholesalerId(game.getGId()+1);
        this->setWindowTitle(QString::fromStdString(GLOBAL_PLAYERS[2]));
        ui->gameplayscreen->setTitle(QString::fromStdString(GLOBAL_PLAYERS[2]));
        setPlayerUI();
        startGame();
    }else{
        QMessageBox::information(this,"Player Choose", "Role alreday chosen");
    }
}

void PlayerDialog::on_distributor_btn_clicked()
{
    int distributorPlayer = game.getPDistributorId();
    if(distributorPlayer == 0){
        setPlayer(allPlayers[3]);
        ui->stackedWidget->setCurrentIndex(1);
        game.setPDistributorId(game.getGId()+1);
        this->setWindowTitle(QString::fromStdString(GLOBAL_PLAYERS[3]));
        ui->gameplayscreen->setTitle(QString::fromStdString(GLOBAL_PLAYERS[3]));
        setPlayerUI();
        startGame();
    }else{
        QMessageBox::information(this,"Player Choose", "Role alreday chosen");
    }
}

void PlayerDialog::on_factory_btn_clicked()
{
    int factoryPlayer = game.getPFactId();
    if(factoryPlayer == 0){
        setPlayer(allPlayers[4]);
        ui->stackedWidget->setCurrentIndex(1);
        game.setPFactId(game.getGId()+1);
        this->setWindowTitle(QString::fromStdString(GLOBAL_PLAYERS[4]));
        ui->gameplayscreen->setTitle(QString::fromStdString(GLOBAL_PLAYERS[4]));
        setPlayerUI();
        startGame();
    }else{
        QMessageBox::information(this,"Player Choose", "Role alreday chosen");
    }
}

void PlayerDialog::on_player_order_clicked()
{
    QString numberOfBeers = ui-> order_amount->text();
    ui->player_order->setEnabled(false);
    player->placeOrder(numberOfBeers.toInt());
    player->placeShipment(player->getOutgoingShipment());

//    player->processOrder(numberOfBeers.toInt());

}

Player *PlayerDialog::getPlayer() const
{
    return player;
}

void PlayerDialog::setPlayer(Player *value)
{
    player = value;
}

void PlayerDialog::startGame()
{
    ui->stat_btn->setEnabled(true);
    bool readyToStart = game.gameReadyToStart();
    if(readyToStart){
        game.startGame();
    }
}

void PlayerDialog::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QMessageBox::information(this,"Choose Game", "Sorry not implemented yet");
}


void PlayerDialog::on_linegraph_check_stateChanged(int arg1)
{
    on_stat_btn_clicked();
}

void PlayerDialog::on_show_incoming_stateChanged(int arg1)
{
    on_stat_btn_clicked();
}

void PlayerDialog::on_show_outgoing_stateChanged(int arg1)
{
    on_stat_btn_clicked();
}


void PlayerDialog::on_pushButton_2_clicked()
{
    this->close();
}
