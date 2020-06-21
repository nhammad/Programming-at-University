/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *player_pushButton;
    QPushButton *instructor_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName(QString::fromUtf8("LoginScreen"));
        LoginScreen->resize(800, 600);
        LoginScreen->setStyleSheet(QString::fromUtf8("background-color: #B55D4B;"));
        centralwidget = new QWidget(LoginScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(310, 210, 191, 141));
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 30, 551, 81));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"  color:white;\n"
"  font-size: 35px;\n"
"font-weight: 600;\n"
"font-style: italic\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        player_pushButton = new QPushButton(centralwidget);
        player_pushButton->setObjectName(QString::fromUtf8("player_pushButton"));
        player_pushButton->setGeometry(QRect(570, 280, 141, 41));
        instructor_pushButton = new QPushButton(centralwidget);
        instructor_pushButton->setObjectName(QString::fromUtf8("instructor_pushButton"));
        instructor_pushButton->setGeometry(QRect(100, 280, 141, 41));
        LoginScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        LoginScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginScreen->setStatusBar(statusbar);

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QMainWindow *LoginScreen)
    {
        LoginScreen->setWindowTitle(QCoreApplication::translate("LoginScreen", "Beer Game Login", nullptr));
        label->setText(QCoreApplication::translate("LoginScreen", "<html><head/><body><p><img src=\":/new/prefix1/cheers.png\"/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginScreen", "BeerGame", nullptr));
        player_pushButton->setText(QCoreApplication::translate("LoginScreen", "I'm a Player", nullptr));
        instructor_pushButton->setText(QCoreApplication::translate("LoginScreen", "I'm an Instructor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
