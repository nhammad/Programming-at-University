#ifndef TRYWINDOW_H
#define TRYWINDOW_H

#include <QMainWindow>

namespace Ui {
class tryWindow;
}

class tryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit tryWindow(QWidget *parent = nullptr);
    ~tryWindow();

private slots:

    void on_orderButton_clicked();

    void on_pl_login_clicked();

    void on_orderButton_3_clicked();

    void on_orderButton_4_clicked();

    void on_orderButton_5_clicked();

private:
    Ui::tryWindow *ui;
};

#endif // TRYWINDOW_H
