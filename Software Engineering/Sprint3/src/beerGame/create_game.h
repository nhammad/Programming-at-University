#ifndef CREATE_GAME_H
#define CREATE_GAME_H

#include <QDialog>

namespace Ui {
class create_game;
}

class create_game : public QDialog
{
    Q_OBJECT

public:
    explicit create_game(QWidget *parent = nullptr);
    ~create_game();

private slots:
    void on_pushButton_clicked();

private:
    Ui::create_game *ui;
};

#endif // CREATE_GAME_H
