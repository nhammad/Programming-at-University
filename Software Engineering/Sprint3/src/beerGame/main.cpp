#include "loginscreen.h"
//#include "../player.h"
#include "../PlayerEvent.h"
#include "../Order.h"
#include "../Shipment.h"
#include "../Game.h"
#include "../Instructor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginScreen w;
    w.show();
    return a.exec();
}
