#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "instructorwelcome.h"
//#include "playerscreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_lineEdit_password_returnPressed();

private:
    Ui::MainWindow *ui;
    InstructorWelcome* instructorWelcome;


};
#endif // MAINWINDOW_H
