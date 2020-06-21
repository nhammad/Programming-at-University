#ifndef INSTRUCTORSCREEN_H
#define INSTRUCTORSCREEN_H

#include <QMainWindow>

namespace Ui {
class InstructorScreen;
}

class InstructorScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit InstructorScreen(QWidget *parent = nullptr);
    ~InstructorScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InstructorScreen *ui;
};

#endif // INSTRUCTORSCREEN_H
