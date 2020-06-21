#include "mainwindow.h"

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

void setdb();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    setdb();
    return a.exec();
    return 0;
}

void setdb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("BeerGame");

    if(db.open()){
        //successfully opened
    }
    else{
          qDebug() << "Database Not Connected";
    }

    QString dbpath = qApp->applicationDirPath()+"/../BeerGame.db";

    if(!QFile::exists(dbpath)){
        db.setDatabaseName(dbpath);
        if(!db.open()){
            qDebug()<<"Problem opening the database";
        }

            QString player_query = "CREATE TABLE Player ("
                "QStringpId INT UNSIGNED AUTO_INCREMENT,"
                "role INT NOT NULL,"
                "inventory INT NOT NULL,"
                "backorder INT NOT NULL,"
                "incomingOrder INT NOT NULL,"
                "outgoingShipment INT NOT NULL, "
                "cost DOUBLE NOT NULL, "
                "totalCost DOUBLE NOT NULL,"
                "orderReceived BOOL NOT NULL,"
                "shipmentReceived BOOL NOT NULL,"
                "orderPlaced BOOL NOT NULL,"
                "shipmentPlaced BOOL NOT NULL,"
                "demand INT NOT NULL,"
                "PRIMARY KEY(pId),"
                "gameId INT NOT NULL REFERENCES Game(gId))";


            QString game_query = "CREATE TABLE Game ("
                    "gId INT UNSIGNED AUTO_INCREMENT,"
                    "instrId INT NOT NULL REFERENCES Instructor(instrId),"
                    "pFactId INT UNSIGNED NOT NULL,"
                    "pDistributorId INT UNSIGNED NOT NULL,"
                    "pWholesalerId INT UNSIGNED,"
                    "pRetailerId INT UNSIGNED,"
                    "orderDelay INT NOT NULL, "
                    "shipmentDealy INT NOT NULL, "
                    "holdingCost DOUBLE NOT NULL,"
                    "backorderCost DOUBLE NOT NULL,"
                    "startingInventory INT NOT NULL,"
                    "weeksToBePlayed INT NOT NULL, "
                    "currentWeek INT NOT NULL,"
                    "infoCode INT NOT NULL, "
                    "factoryDelay INT NOT NULL,"
                    "numberOfPlayers INT NOT NULL,"
                    "players LONGTEXT NOT NULL,"
                    "consumerDemandPerWeek LONGTEXT,"
                    "PRIMARY KEY (gId))";


            QString instructor_query = "CREATE TABLE Instructor ("
                    "instrId INT UNSIGNED AUTO_INCREMENT,"
                    "instrEmail VARCHAR(100) NOT NULL, "
                    "instrPassword VARCHAR (100) NOT NULL,"
                    "games LONGTEXT,"
                    "PRIMARY KEY (instrId))";

            QString playerEvent_query = "CREATE TABLE PlayerEvent ("
                    "eventId INT UNSIGNED AUTO_INCREMENT,"
                    "gId INT NOT NULL REFERENCES Game(gId),"
                    "numberOfBeers INT NOT NULL,"
                    "orderedInWeek INT NOT NULL,"
                    "shipmentInWeek INT NOT NULL, "
                    "toPlayerId INT NOT NULL, "
                    "fromPlayerId INT NOT NULL,"
                    "PRIMARY KEY (eventId))";



            QSqlQuery qry;
            qDebug()<<"Working";

//        if(!qry.exec(game_query)){
//            qDebug()<<"Error creating game table";
//        }
//        if(!qry.exec(player_query)){
//            qDebug()<<"Error creating game table";
//        }
    }
}


//        QString player_query = "CREATE TABLE player ("
//                "PID integer,"
//                "PlayerId integer,"
//                "Inventory float,"
//                "BackOrder float,"
//                "IncomingOrder integer,"
//                "IncomingShipment integer,"
//                "TotalCost float,"
//                "Cost float,"
//                "Demand integer);";
