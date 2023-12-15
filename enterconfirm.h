#ifndef ENTERCONFIRM_H
#define ENTERCONFIRM_H

#include <QWidget>

namespace Ui {
class EnterConfirm;
}

class EnterConfirm : public QWidget
{
    Q_OBJECT

public:
    explicit EnterConfirm(QWidget *parent = nullptr);
    ~EnterConfirm();


public slots:
    void check();
    void clearAll();
    void CreateAccount();

private:
    Ui::EnterConfirm *ui;
};

#endif // ENTERCONFIRM_H
