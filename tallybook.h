#ifndef TALLYBOOK_H
#define TALLYBOOK_H
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<QDataStream>
#include<QString>
//记账本背后逻辑头文件

extern QString Filename1;

#define Outlay 0//支出
#define Income 1//收入

enum OutputCase
{
    NotOutPut,
    Other,
    Clothes,
    Food,
    Housing,
    Transports,
};

class Bill {
private:
    int year_;
    int month_;
    int date_;
    int value_;//该账单金额
    QString note_=" ";//备注默认设置为空
    int case_=0;//The case of income==1 or outlay==0
    OutputCase kind_=NotOutPut;

public:
    Bill(int value=0, int year=0, int month=0, int date=0,
         QString note="Nothing", int Case = 0,OutputCase kind=NotOutPut);
    //函数重载，方便操作
    void ShowRecord(void);

    friend QDataStream& operator >>(QDataStream &in,Bill &t);
    //返回一个流的引用值，这个设计是非常科学的
    friend QDataStream& operator <<(QDataStream &out,Bill &t);

    //一堆接口
    //The reader获取数据
    int GetYear(void);
    int GetMonth(void);
    int GetDate(void);
    int GetHour(void);
    int GetMin(void);
    int GetValue(void);
    int GetCase(void);
    QString GetNote(void);
    OutputCase GetKind(void);

    //The writer写入数据
    void SetYear(int year);
    void SetMonth(int month);
    void SetDate(int date);
    void SetHour(int hour);
    void SetMin(int min);
    void SetValue(int value);
    void SetCase(int Case);
    void SetNote(QString name);
    void SetKind(OutputCase kind);
};

//链表相关
struct Node1 {
    Bill value;
    Node1* pNext;
};//创建一个结点

QDataStream& operator <<(QDataStream &out,Node1* &t);

QDataStream& operator >>(QDataStream &in,Node1* &t);


//----------service----------

void SaveList1(Node1* pHead);
//保存临时存储的链表

void BillAdd(Bill n);
//添加账单

Node1* BillFetch(void);
//返回数据文件中存储的所有数据的链表的头结点

void BillClear(void);
//清空账单

Node1* BillDelete(int which);
//删除一条账单

void Rewrite(Node1* pNew);
//重新写入

Node1* BillArrange(Node1* pHead);
//对账单按照时间进行排序

void BillSwap(Node1* current);
//交换上下两个结点的数据
//----------service----------

//----------view----------

void ShowList1(Node1* pHead);
//显示给入的链表数据

void BillShow(void);
//从数据文件中读取数据并且进行显示

void ShowYear(int year);
//显示year年份的所有账单

void ShowMonth(int year,int month);
//显示year年份下month月份的账单

void ShowDate(int year, int month,int date);
//显示year年份下month月份day天的账单


//----------view---------



#endif // TALLYBOOK_H
