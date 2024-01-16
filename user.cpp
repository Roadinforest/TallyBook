#include "user.h"
#include "enterconfirm.h"
#include "ui_enterconfirm.h"
#include <QDebug>
#include <QDataStream>
#include <QFile>
#include "tallybook.h"

/*****重载运算符*****/
QDataStream& operator >>(QDataStream &in,User &t)
{
    in>>t._name>>t._code;
    return in;
}

QDataStream& operator <<(QDataStream &out,User &t)
{
    out<<t._name<<t._code;
    return out;
}

QDataStream& operator <<(QDataStream &out,Node2* &t)
{
    out<<t->value;
    return out;
}

QDataStream& operator >>(QDataStream &in,Node2* &t)
{
    in>>t->value;
    return in;
}
//----------结束----------

//----------User类中相关函数的实现----------
User::User(QString name, QString code)
{
    _name=name;
    _code=code;
}

void User::setName(QString a)
{
    _name=a;
}
void User::setCode(QString a)
{
    _code=a;
}
QString User::getName(void)
{
    return _name;
}
QString User::getCode(void)
{
    return _code;
}
//调试用，将这一个成员的值进行显示
void User::ShowRecord(void)
{
    qDebug() << "用户:"<<_name << " - " <<"密码:"<<_code;
}
//----------结束----------


//----------其他部分内容----------
void ShowList2(Node2* pHead)
{
    if (pHead)
    {
        Node2* pointer = pHead;
        int range=1;
        while (pointer)
        {
            qDebug() << "记录" << range << ":";
            pointer->value.ShowRecord();
            pointer = pointer->pNext;
            range++;
        }
        qDebug()<< ("暂时存储用户链表如上！") << Qt::endl;
    }
    else if (!pHead)
    {
        qDebug()<<("Error:链表为空")<< Qt::endl;
    }
}

void SaveList2(Node2* pNew)
{
    qDebug()<<"Enter the SaveList2!!!";
    //pNew是给入的暂时链表的头结点

    //几个基本步骤：
    //1.将指针指向临时存储的链表的最后一个
    //2.得到数据文件中存储的数据
    //3.将两个链表进行拼接

    //步骤2.得到数据文件中存储的数据
    Node2* pointer = NULL;
    Node2* pHead = NULL;
    //准备读取数据文件中的头结点
    Node2* Each = new Node2();
    Each->pNext=NULL;
    //先在这里声明一个结点
    int i = 0;
    QFile file(UserFile);
    file.open(QFile::ReadOnly);
    QDataStream fout(&file);
    if(fout.atEnd())    qDebug()<<"There is nothing in the file";
    while (!fout.atEnd())
    //这里是取出,其实每一步都是在重新取出东西
    //运算符重载，在这里就非常好咯
    {
        qDebug()<<"Here 1:read";
        fout>>Each;
        //每一个结点，只有刚开始的时候给它分配动态内存，之后它才有地方可以存
        if (i == 0)
        {
            pHead = Each;//将pHead进行初始化
            pointer = pHead;
        }
        else if (i > 0)
        {
            pointer->pNext = Each;
            pointer = Each;
        }//千万注意这里要用尾插法取出！！！
        //Each->value.ShowRecord();
        i++;
        Each = new Node2;
        Each->pNext=NULL;
        Each->value.setName("End!!!");
        Each->value.setCode("You shouldn't see me!!!");
        //千万千万注意只可以在结尾处给Each分配动态内存，因为我们的改变操作是在while中进行的
        //若是将上面语句放在第一行（也就是将创建放在读取之前），会将所有数据变成默认值
    }
    qDebug()<<"The end in file";
    qDebug()<<"The former list as belowed:";
    ShowList2(pHead);

    //步骤1.将指针指向临时存储的链表的最后一个
    //刚开始的时候必须要将Node分配到NULL，否则它随便指到一个内存，那就完蛋啦
    //将pointer指向临时链表的最后结点,并且得到临时链表中的总个数range
    if (pNew)
    {//如果传进来的临时链表的头结点存在
        pointer = pNew;
        int range = 1;
        while (pointer->pNext)
        {
            range++;
            pointer = pointer->pNext;
        }
        qDebug()<<"共有"<<range<<"组数据进入";
    }
    else if (!pNew)
    {//如果这个头结点并不存在
        qDebug() << "Error:链表为空" << Qt::endl;
            return ;//因为是一个void函数，所以return后面并没有参数
    }
    qDebug()<<"Here is the enter list:";
    ShowList2(pNew);
    //步骤三。将两个链表进行拼接

    pointer->pNext= pHead;

    Node2* Np = pNew;
    qDebug()<<"The list prepare to be saved as belowed:";
    ShowList2(Np);

    file.close();
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    //截断，因为我们要从头开始写
    {
        qDebug() << "Error2:文件打开错误！！！" << Qt::endl;
    }
    QDataStream fin(&file);
    i = 0;
    while (Np)
    {
        qDebug()<<"Here 2:write";
        fin<<Np;
        Np = Np->pNext;
        i++;
    }
    qDebug()<<"最终写入"<<i<<"条数据";

    qDebug() << "最终成功保存!!!" << Qt::endl;
    file.close();
}

void UserAdd(QString name,QString code)
{
    qDebug()<<"Enter the UserAdd() is:"<<name;
    Node2* Add = new Node2;
    Add->value = User(name,code);
    Add->pNext = NULL;
    SaveList2(Add);
    //将临时存储表进行添加
    qDebug()<<"用户成功创建";
}

//查找文件中是否保存有该名字
Findcase Find(QString name,QString code)
{
    int i = 0;
    QFile file(UserFile);
    file.open(QFile::ReadOnly);
    QDataStream fout(&file);
    if(fout.atEnd())    qDebug()<<"Nothing";
    Node2* Each = new Node2();
    //先在这里声明一个结点
    Findcase myCase;
    while (!fout.atEnd())
    //这里是取出,其实每一步都是在重新取出东西
    //运算符重载，在这里就非常好咯
    {
        qDebug()<<"Here 1:read";
        fout>>Each;
        Each->value.ShowRecord();
        if(Each->value.getName()==name)
        {
            if(Each->value.getCode()==code)
            {
                myCase=HaveUser;
                Username=name;
                Filename1="BillOf"+name+".dat";
                qDebug()<<"Find!!!The username here is:"<<Username;
            }
            else
            {
                myCase=CodeWrong;
            }
            return myCase;
        }
        i++;
    }
    myCase=NoUser;
    qDebug()<<"The end of the user file";
    return myCase;
}


