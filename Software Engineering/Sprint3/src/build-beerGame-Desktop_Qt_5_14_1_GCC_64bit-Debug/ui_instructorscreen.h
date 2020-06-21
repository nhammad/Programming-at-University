/********************************************************************************
** Form generated from reading UI file 'instructorscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTORSCREEN_H
#define UI_INSTRUCTORSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstructorScreen
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QFrame *pword_frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *fact_pword;
    QLabel *whole_pword;
    QLabel *dist_pword;
    QLabel *retail_pword;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InstructorScreen)
    {
        if (InstructorScreen->objectName().isEmpty())
            InstructorScreen->setObjectName(QString::fromUtf8("InstructorScreen"));
        InstructorScreen->resize(800, 600);
        centralwidget = new QWidget(InstructorScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 20, 241, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(519, 20, 21, 16));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 50, 491, 81));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 320, 151, 24));
        pword_frame = new QFrame(centralwidget);
        pword_frame->setObjectName(QString::fromUtf8("pword_frame"));
        pword_frame->setGeometry(QRect(410, 130, 131, 149));
        verticalLayout_2 = new QVBoxLayout(pword_frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fact_pword = new QLabel(pword_frame);
        fact_pword->setObjectName(QString::fromUtf8("fact_pword"));
        QFont font1;
        font1.setItalic(true);
        fact_pword->setFont(font1);
        fact_pword->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(fact_pword);

        whole_pword = new QLabel(pword_frame);
        whole_pword->setObjectName(QString::fromUtf8("whole_pword"));
        whole_pword->setFont(font1);
        whole_pword->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(whole_pword);

        dist_pword = new QLabel(pword_frame);
        dist_pword->setObjectName(QString::fromUtf8("dist_pword"));
        dist_pword->setFont(font1);
        dist_pword->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(dist_pword);

        retail_pword = new QLabel(pword_frame);
        retail_pword->setObjectName(QString::fromUtf8("retail_pword"));
        retail_pword->setFont(font1);
        retail_pword->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(retail_pword);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(249, 140, 176, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        verticalLayout->addWidget(label_7);

        InstructorScreen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(InstructorScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        InstructorScreen->setStatusBar(statusbar);

        retranslateUi(InstructorScreen);

        QMetaObject::connectSlotsByName(InstructorScreen);
    } // setupUi

    void retranslateUi(QMainWindow *InstructorScreen)
    {
        InstructorScreen->setWindowTitle(QCoreApplication::translate("InstructorScreen", "Generate Passwords", nullptr));
        label->setText(QCoreApplication::translate("InstructorScreen", "Password List for Players in Game", nullptr));
        label_2->setText(QCoreApplication::translate("InstructorScreen", "1", nullptr));
        label_3->setText(QCoreApplication::translate("InstructorScreen", "Find the passwords to distribute to your players below. If you need new ones, please press the update button below", nullptr));
        pushButton->setText(QCoreApplication::translate("InstructorScreen", "Update Passwords", nullptr));
        fact_pword->setText(QCoreApplication::translate("InstructorScreen", "abcdefgh", nullptr));
        whole_pword->setText(QCoreApplication::translate("InstructorScreen", "108dnwjx", nullptr));
        dist_pword->setText(QCoreApplication::translate("InstructorScreen", "password", nullptr));
        retail_pword->setText(QCoreApplication::translate("InstructorScreen", "plf08.@-", nullptr));
        label_4->setText(QCoreApplication::translate("InstructorScreen", "Factory password:", nullptr));
        label_5->setText(QCoreApplication::translate("InstructorScreen", "Distributor password:", nullptr));
        label_6->setText(QCoreApplication::translate("InstructorScreen", "Wholesaler password:", nullptr));
        label_7->setText(QCoreApplication::translate("InstructorScreen", "Retailer password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InstructorScreen: public Ui_InstructorScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTORSCREEN_H
