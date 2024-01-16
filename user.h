#ifndef USER_H
#define USER_H
#include<QString>
//用户类头文件

#define UserFile "User.dat"

extern QString Filename1;
extern QString Username;

enum Findcase
{
    HaveUser,
    CodeWrong,
    NoUser
};
//用于判定find的返回情况的

class User
{
public:
    User(QString name="NULL",QString code="NULL");
    void setName(QString a);
    void setCode(QString a);
    QString getName(void);
    QString getCode(void);
    void ShowRecord(void);

    friend QDataStream& operator >>(QDataStream &in,User &t);
    //返回一个流的引用，这个设计是非常科学的
    friend QDataStream& operator <<(QDataStream &out,User &t);

private:
    QString _name;
    QString _code;
};

//链表相关
struct Node2 {
    User value;
    Node2* pNext;
};//创建一个结点

QDataStream& operator <<(QDataStream &out,Node2* &t);

QDataStream& operator >>(QDataStream &in,Node2* &t);

void ShowList2(Node2* pHead);//展示这个链表
void SaveList2(Node2* pNew);//将一个临时链表存储进去
void UserAdd(QString name,QString code);//将一个数据添加进去
Findcase Find(QString name,QString code);//检测对应数据是否存在，并且返回一个值

#endif // USER_H
