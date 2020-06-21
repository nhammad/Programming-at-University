#-------------------------------------------------
#
# Project created by QtCreator 2020-03-10T14:17:24
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeerGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    instructor.cpp \
    create_game.cpp \
    instructors_dashboard.cpp \
    info_sharing.cpp \
    players_playing.cpp \
    player_password.cpp \
    print_passwords.cpp \
    game.cpp \
    player.cpp \
    order.cpp \
    factory.cpp

HEADERS += \
        mainwindow.h \
    instructor.h \
    create_game.h \
    instructors_dashboard.h \
    info_sharing.h \
    players_playing.h \
    player_password.h \
    print_passwords.h \
    game.h \
    player.h \
    order.h \
    factory.h

FORMS += \
        mainwindow.ui \
    instructor.ui \
    create_game.ui \
    instructors_dashboard.ui \
    info_sharing.ui \
    players_playing.ui \
    player_password.ui \
    print_passwords.ui \
    game.ui \
    player.ui

RESOURCES += \
    resource.qrc
