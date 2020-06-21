#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QMainWindow>
#include "playerScreen.h"
#include "instructorwelcome.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

private slots:

    void on_demoScreen_pushButton_clicked();

    void on_demoScreen_pushButton_2_clicked();

private:
    Ui::MainDialog *ui;
    tryWindow *playerScreen;
    InstructorWelcome *instructorScreen;
};

#endif // MAINDIALOG_H
