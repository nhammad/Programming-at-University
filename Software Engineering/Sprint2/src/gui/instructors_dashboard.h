/**
* @file instructors_dashboard.h
*
*/
#ifndef INSTRUCTORS_DASHBOARD_H
#define INSTRUCTORS_DASHBOARD_H

#include <QDialog>

#include "info_sharing.h"
#include "game.h"

/**
* @class Instructors_dashboard
* @brief Class for the Instructors Dashboard Window.
*/

namespace Ui {
class Instructors_dashboard;
}

class Instructors_dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Instructors_dashboard(QWidget *parent = 0);
    ~Instructors_dashboard();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Instructors_dashboard *ui;
    info_sharing * Info_Sharing;
    Game * game;
};

#endif // INSTRUCTORS_DASHBOARD_H
