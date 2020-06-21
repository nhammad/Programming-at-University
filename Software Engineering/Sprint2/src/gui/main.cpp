#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int x=w.width()*1.2;
    int y=w.height()*1.2;
    w.setFixedSize(x,y);
    w.show();

    return a.exec();
}
