#ifndef INSTRUCTORWELCOME_H
#define INSTRUCTORWELCOME_H

#include <QMainWindow>
#include "instructorscreen.h"
//#include "create_game.h"

namespace Ui {
class InstructorWelcome;
}

class InstructorWelcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit InstructorWelcome(QWidget *parent = nullptr);
    ~InstructorWelcome();

private slots:

    void on_gen_pword_clicked();

    void on_game_create_clicked();

    void on_pushButton_clicked();

private:
    Ui::InstructorWelcome *ui;
    InstructorScreen *instructorScreen;
//    create_game *g;
};

#endif // INSTRUCTORWELCOME_H
