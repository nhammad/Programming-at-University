#ifndef FACTORY_H
#define FACTORY_H

#include <QDialog>

namespace Ui {
class Factory;
}

class Factory : public QDialog
{
    Q_OBJECT

public:
    explicit Factory(QWidget *parent = 0);
    ~Factory();
    int productionTime;
    void produce(int numberOfBeers);

private:
    Ui::Factory *ui;
};

#endif // FACTORY_H
