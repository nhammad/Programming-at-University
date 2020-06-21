#ifndef PRINT_PASSWORDS_H
#define PRINT_PASSWORDS_H

#include <QDialog>

namespace Ui {
class Print_passwords;
}

class Print_passwords : public QDialog
{
    Q_OBJECT

public:
    explicit Print_passwords(QWidget *parent = 0);
    ~Print_passwords();

private:
    Ui::Print_passwords *ui;
};

#endif // PRINT_PASSWORDS_H
