#ifndef PLAYERS_PLAYING_H
#define PLAYERS_PLAYING_H

#include <QDialog>

namespace Ui {
class Players_playing;
}

class Players_playing : public QDialog
{
    Q_OBJECT

public:
    explicit Players_playing(QWidget *parent = 0);
    ~Players_playing();

private:
    Ui::Players_playing *ui;
};

#endif // PLAYERS_PLAYING_H
