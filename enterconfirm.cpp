#include "enterconfirm.h"
#include "ui_enterconfirm.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tallybook.h"
#include "user.h"

EnterConfirm::EnterConfirm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterConfirm)
{
    ui->setupUi(this);
    setWindowTitle("登录界面");
    ui->Title->setText("用户登录界面");
    ui->label_1->setText("用户名：");
    ui->label_2->setText("密码：");
    ui->btnConfirm->setText("确认");
    ui->btnQuit->setText("退出");

    connect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(check()));
    connect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(close()));
}

EnterConfirm::~EnterConfirm()
{
    delete ui;
}

void EnterConfirm::clearAll()//清除控件的状态
{
    qDebug()<<"Function-clearAll():";
    ui->getName->setText("");
    ui->getCode->setText("");

    disconnect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(CreateAccount()));
    disconnect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(clearAll()));

    connect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(check()));
    connect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(close()));
    ui->btnConfirm->setText("确认");
    ui->btnQuit->setText("退出");
    qDebug()<<"End!";
    qDebug()<<Qt::endl;
}

void EnterConfirm::CreateAccount()//创建一个用户
{
    qDebug()<<"Function-CreateAccount():";
    QString name=ui->getName->text();
    QString code=ui->getCode->text();
    qDebug()<<"The name we get is:"<<name;
    UserAdd(name,code);//user.h
    ui->Title->setText("用户创建成功，请重新登录");
    ui->getName->setText("");
    ui->getCode->setText("");

    disconnect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(CreateAccount()));
    disconnect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(clearAll()));

    connect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(check()));
    connect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(close()));

    ui->btnConfirm->setText("确认");
    ui->btnQuit->setText("退出");
    qDebug()<<"End";
    qDebug()<<Qt::endl;
}

void EnterConfirm::check()//检测是否是存在该用户
{
    qDebug()<<"Function-check():";
    QString name=ui->getName->text();
    QString code=ui->getCode->text();
    qDebug()<<"What get in check() is:"<<name;

    Findcase myCase;//利用枚举对查找情况进行分类辨认
    myCase=Find(name,code);
    if(myCase==HaveUser)
    {
        qDebug()<<"HaveUser";
        this->setVisible(false);
        MainWindow* a=new MainWindow;
        a->show();
    }

    else if(myCase==CodeWrong)
    {
        qDebug()<<"CodeWrong";
        ui->Title->setText("密码输入错误，请再试一次");
        ui->getCode->setText("");
        ui->getName->setText("");
    }

    else if(myCase==NoUser)
    {
        qDebug()<<"NoUser";
        ui->Title->setText("该用户不存在！");
        ui->btnConfirm->setText("创建新用户");
        ui->btnQuit->setText("重新登录");

        disconnect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(check()));
        connect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(CreateAccount()));

        disconnect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(close()));
        connect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(clearAll()));
        qDebug()<<"End";
        qDebug()<<Qt::endl;

    }
}


