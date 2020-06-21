/********************************************************************************
** Form generated from reading UI file 'instructorwelcome.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTORWELCOME_H
#define UI_INSTRUCTORWELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstructorWelcome
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QPushButton *gen_pword;
    QWidget *page_2;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *game_create;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InstructorWelcome)
    {
        if (InstructorWelcome->objectName().isEmpty())
            InstructorWelcome->setObjectName(QString::fromUtf8("InstructorWelcome"));
        InstructorWelcome->resize(576, 552);
        InstructorWelcome->setStyleSheet(QString::fromUtf8("background-color: #B55D4B;"));
        centralwidget = new QWidget(InstructorWelcome);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, -10, 561, 561));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 190, 161, 51));
        gen_pword = new QPushButton(page);
        gen_pword->setObjectName(QString::fromUtf8("gen_pword"));
        gen_pword->setEnabled(true);
        gen_pword->setGeometry(QRect(190, 310, 161, 51));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 200, 161, 20));
        spinBox = new QSpinBox(page_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(260, 200, 131, 26));
        game_create = new QPushButton(page_2);
        game_create->setObjectName(QString::fromUtf8("game_create"));
        game_create->setGeometry(QRect(260, 260, 131, 31));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 40, 231, 51));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"  color:white;\n"
"  font-size: 25px;\n"
"font-weight: 600;\n"
"font-style: italic\n"
"}"));
        stackedWidget->addWidget(page_2);
        InstructorWelcome->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(InstructorWelcome);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        InstructorWelcome->setStatusBar(statusbar);

        retranslateUi(InstructorWelcome);

        QMetaObject::connectSlotsByName(InstructorWelcome);
    } // setupUi

    void retranslateUi(QMainWindow *InstructorWelcome)
    {
        InstructorWelcome->setWindowTitle(QCoreApplication::translate("InstructorWelcome", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("InstructorWelcome", "Create Games", nullptr));
        gen_pword->setText(QCoreApplication::translate("InstructorWelcome", "Generate passwords", nullptr));
        label->setText(QCoreApplication::translate("InstructorWelcome", "Number of games", nullptr));
        game_create->setText(QCoreApplication::translate("InstructorWelcome", "Create", nullptr));
        label_2->setText(QCoreApplication::translate("InstructorWelcome", "CREATE GAMES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InstructorWelcome: public Ui_InstructorWelcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTORWELCOME_H
