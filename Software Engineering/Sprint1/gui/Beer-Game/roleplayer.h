#ifndef ROLEPLAYER_H
#define ROLEPLAYER_H

#include <QWidget>

namespace Ui {
class rolePlayer;
}

class rolePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit rolePlayer(QWidget *parent = nullptr);
    ~rolePlayer();

private:
    Ui::rolePlayer *ui;
};

#endif // ROLEPLAYER_H
