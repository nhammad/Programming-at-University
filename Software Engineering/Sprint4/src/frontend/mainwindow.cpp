#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
     m_view(new QWebEngineView(this))
{
    ui->setupUi(this);
    QMovie *gif = new QMovie(":/resources/images/beer-game.gif");
    ui->stackedWidget->setCurrentIndex(0);
    // For the demo video
    QGridLayout *gridLayout = new QGridLayout;
    ui->video->setLayout(gridLayout);
    m_view->show();
    ui->video->layout()->addWidget(m_view);

    QPixmap pix(":/resources/images/beergame.png");
    QPixmap cover(":/resources/images/cover.png");
    QPixmap youtube(":/resources/images/youtube.png");
    ui->label_logo->setPixmap(pix.scaled(200,180, Qt::KeepAspectRatio));
    ui->label_cover->setPixmap(cover.scaled(820,820, Qt::KeepAspectRatio));
    ui->youtube_logo->setPixmap(youtube.scaled(36,36, Qt::KeepAspectRatio));
    // The gif cover
    ui->label_cover->setMovie(gif);
    gif->start();
    ui->checkBox_isInstructor->setCheckState(Qt::Checked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_useremail->text();
    QString password = ui->lineEdit_password->text();
    bool isInstructor = ui->checkBox_isInstructor->checkState();
    if(username == "test" && password =="1234" && isInstructor){
        QMessageBox::information(this,"Instructor Login", "Username and Password is correct");
        hide();
        secDialog = new InstructorDialog(this);
        secDialog->show();
    }else if (username == "test" && password =="1234" && !isInstructor){
        QMessageBox::information(this,"Player Login", "Try as a instructor. Player login under construction");
    }else
    {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}

void MainWindow::on_youtube_btn_clicked()
{
    //setCentralWidget(m_view);
    // For the youtube Video
    m_view->load(QUrl(QStringLiteral("qrc:/resources/images/html/index.html")));
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
   m_view->reload();
}
