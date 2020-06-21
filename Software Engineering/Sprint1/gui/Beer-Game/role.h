#ifndef ROLE_H
#define ROLE_H

#include <QWidget>

namespace Ui {
class Role;
}

class Role : public QWidget
{
    Q_OBJECT

public:
    explicit Role(QWidget *parent = nullptr);
    ~Role();

private:
    Ui::Role *ui;
};

#endif // ROLE_H
