/********************************************************************************
** Form generated from reading UI file 'playerlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERLOGIN_H
#define UI_PLAYERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerLogin
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton_login_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *uname_2;
    QLabel *pword_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEdit_username_2;
    QLineEdit *lineEdit_password_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PlayerLogin)
    {
        if (PlayerLogin->objectName().isEmpty())
            PlayerLogin->setObjectName(QString::fromUtf8("PlayerLogin"));
        PlayerLogin->resize(800, 600);
        PlayerLogin->setStyleSheet(QString::fromUtf8("background-color: #B55D4B;"));
        centralwidget = new QWidget(PlayerLogin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 761, 561));
        groupBox->setAutoFillBackground(false);
        pushButton_login_2 = new QPushButton(groupBox);
        pushButton_login_2->setObjectName(QString::fromUtf8("pushButton_login_2"));
        pushButton_login_2->setGeometry(QRect(380, 380, 100, 30));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(290, 290, 203, 60));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        uname_2 = new QLabel(layoutWidget_2);
        uname_2->setObjectName(QString::fromUtf8("uname_2"));

        verticalLayout_3->addWidget(uname_2);

        pword_2 = new QLabel(layoutWidget_2);
        pword_2->setObjectName(QString::fromUtf8("pword_2"));

        verticalLayout_3->addWidget(pword_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lineEdit_username_2 = new QLineEdit(layoutWidget_2);
        lineEdit_username_2->setObjectName(QString::fromUtf8("lineEdit_username_2"));

        verticalLayout_4->addWidget(lineEdit_username_2);

        lineEdit_password_2 = new QLineEdit(layoutWidget_2);
        lineEdit_password_2->setObjectName(QString::fromUtf8("lineEdit_password_2"));
        lineEdit_password_2->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(lineEdit_password_2);


        horizontalLayout_2->addLayout(verticalLayout_4);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(290, 20, 200, 140));
        label_3->setTextFormat(Qt::RichText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 170, 561, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"  color:white;\n"
"  font-size: 25px;\n"
"font-weight: 600;\n"
"font-style: italic\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);
        PlayerLogin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayerLogin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        PlayerLogin->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayerLogin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PlayerLogin->setStatusBar(statusbar);

        retranslateUi(PlayerLogin);

        QMetaObject::connectSlotsByName(PlayerLogin);
    } // setupUi

    void retranslateUi(QMainWindow *PlayerLogin)
    {
        PlayerLogin->setWindowTitle(QCoreApplication::translate("PlayerLogin", "Player Login", nullptr));
        groupBox->setTitle(QString());
        pushButton_login_2->setText(QCoreApplication::translate("PlayerLogin", "Login", nullptr));
        uname_2->setText(QCoreApplication::translate("PlayerLogin", "Username", nullptr));
        pword_2->setText(QCoreApplication::translate("PlayerLogin", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("PlayerLogin", "<html><head/><body><p><img src=\":/new/prefix1/cheers.png\"/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("PlayerLogin", "Player Login Screen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerLogin: public Ui_PlayerLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERLOGIN_H
