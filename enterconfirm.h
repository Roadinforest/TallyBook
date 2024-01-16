#ifndef ENTERCONFIRM_H
#define ENTERCONFIRM_H

#include <QWidget>
//确认界面类头文件

namespace Ui {
class EnterConfirm;
}

class EnterConfirm : public QWidget
{
    Q_OBJECT

public:
    explicit EnterConfirm(QWidget *parent = nullptr);//构造函数，添加explicit以防止构造时2发生隐式类型转化
    ~EnterConfirm();//析构函数

public slots:
    void check();//检测是否是存在该用户
    void clearAll();//清除控件的状态
    void CreateAccount();//创建一个用户

private:
    Ui::EnterConfirm *ui;
};

#endif // ENTERCONFIRM_H
