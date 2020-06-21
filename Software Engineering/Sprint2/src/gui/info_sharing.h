#ifndef INFO_SHARING_H
#define INFO_SHARING_H

#include <QDialog>

namespace Ui {
class info_sharing;
}

class info_sharing : public QDialog
{
    Q_OBJECT

public:
    explicit info_sharing(QWidget *parent = 0);
    ~info_sharing();

private:
    Ui::info_sharing *ui;
};

#endif // INFO_SHARING_H
