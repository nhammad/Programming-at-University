#include <QApplication>
#include <QLabel>
#include "mainwindow.h"
#include "loginform.h"
#include "role.h"
#include "roleplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QLabel *label = new QLabel("Hello");
    //label->show();
    //label->setWindowTitle("Beer Game");
    //label->resize(400,400);
    MainWindow w;
    w.show();
    LoginForm l;
    l.show();
    Role r;
    r.show();
    rolePlayer rp;
    rp.show();

    return a.exec();
}
