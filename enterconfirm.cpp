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

void EnterConfirm::clearAll()
{
    ui->getName->setText("");
    ui->getCode->setText("");

    disconnect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(UserAdd(name,code)));
    disconnect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(clearAll()));

    connect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(check()));
    connect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(close()));
    ui->btnConfirm->setText("确认");
    ui->btnQuit->setText("退出");
}

void EnterConfirm::CreateAccount()
{
    qDebug()<<"Here is CreateAccount";
    QString name=ui->getName->text();
    QString code=ui->getCode->text();
    qDebug()<<"before the UserAdd()";
    qDebug()<<"!!!!!!!!!!";
    qDebug()<<name<<"and"<<ui->getName->text();
    UserAdd(name,code);
    qDebug()<<"after the UserAdd()";
    ui->Title->setText("用户创建成功，请重新登录");
    ui->getName->setText("");
    ui->getCode->setText("");

    disconnect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(CreateAccount()));
    disconnect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(clearAll()));

    connect(ui->btnConfirm,SIGNAL(clicked(bool)),this,SLOT(check()));
    connect(ui->btnQuit,SIGNAL(clicked(bool)),this,SLOT(close()));
    ui->btnConfirm->setText("确认");
    ui->btnQuit->setText("退出");
}

void EnterConfirm::check()
{
    QString name=ui->getName->text();
    QString code=ui->getCode->text();
    qDebug()<<"What get in check() is:"<<name;
    Findcase myCase;
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

    }
}


