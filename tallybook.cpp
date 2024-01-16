#include "tallybook.h"
#include <QDebug>
#include <QDataStream>
#include <QFile>

//extern QString Filename1;

//链表进入文件准则：头插法进入，尾插法输出

/*****重载运算符*****/
QDataStream& operator >>(QDataStream &in,Bill &t)
{
    in>>t.case_>>t.value_>>t.year_>>t.month_>>t.date_>>t.note_>>t.kind_;
    return in;
}
//这个输入是确确实实地把数据对应到了每一个成员当中去

QDataStream& operator <<(QDataStream &out,Bill &t)
{
    out<<t.case_<<t.value_<<t.year_<<t.month_<<t.date_<<t.note_<<t.kind_;
    return out;
}

QDataStream& operator <<(QDataStream &out,Node1* &t)
{
    out<<t->value;
    return out;
}

QDataStream& operator >>(QDataStream &in,Node1* &t)
{
    in>>t->value;
    return in;
}

/*****Bill类相关函数的具体实现*****/
Bill::Bill(int value, int year, int month, int date,
     QString note, int Case,OutputCase kind) {
    value_ = value;
    year_ = year;
    month_ = month;
    date_=date;
    note_ = note;
    case_ = Case;
    kind_=kind;
}

//获得年份
int Bill::GetYear()
{
    return year_;
}
//获得月份
int Bill::GetMonth()
{
    return month_;
}
//获得日期
int Bill::GetDate()
{
    return date_;
}
//获得金额
int Bill::GetValue()
{
    return value_;
}
//获得收支情况
int Bill::GetCase()
{
    return case_;
}
//获得备注
QString Bill::GetNote()
{
    return note_;
}
//获得支出种类
OutputCase Bill::GetKind()
{
    return kind_;
}

//设置年份
void Bill::SetYear(int year)
{
    year_ = year;
}
//设置月份
void Bill::SetMonth(int month)
{
    month_ = month;
}
//设置日期
void Bill::SetDate(int date)
{
    date_ = date;
}

void Bill::SetValue(int value)
{
    value_ = value;
}
//设置金额
void Bill::SetCase(int Case)
{
    case_ = Case;
}

void Bill::SetNote(QString note)
{
    note_ = note;
}

void Bill::SetKind(OutputCase kind)
{
    kind_=kind;
}



//调试用，将这一个成员的值进行显示
void Bill::ShowRecord(void)
{
    qDebug() << year_ << "-" << month_ << "-" << date_ << " ";
    if (case_ == Outlay)
    {
        qDebug() << "支出" << value_ << "元用于:"<<kind_;
    }
    else if (case_ == Income)
    {
        qDebug() << "收入" << value_ << "元";
    }
    qDebug() << note_ << Qt::endl;
}

//将账单中存储的数据全部清空
void BillClear()
{
    QFile file(Filename1);
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    file.close();
}

//将目前临时存储的账单全部显示出来，仅作工具用
void ShowList1(Node1* pHead)
{
    if (pHead)
    {
        Node1* pointer = pHead;
        int range=1;
        while (pointer)
        {
            qDebug() << "记录" << range << ":";
            pointer->value.ShowRecord();
            pointer = pointer->pNext;
            range++;
        }
        qDebug()<< ("暂时存储链表如上！") << Qt::endl;
    }
    else if (!pHead)
    {
        qDebug()<<("Error:链表为空")<< Qt::endl;
    }
}

void SaveList1(Node1* pNew)
{

    qDebug()<<"Enter the SaveList1 Function!!!";
    //pNew是给入的暂时链表的头结点

    //几个基本步骤：
    //1.将指针指向临时存储的链表的最后一个
    //2.得到数据文件中存储的数据
    //3.将两个链表进行拼接

    //步骤2.得到数据文件中存储的数据
//    QDataStream finout(&file);
    Node1* pointer = NULL;
    Node1* pHead = NULL;
    //准备读取数据文件中的头结点
    Node1* Each = new Node1;
    //先在这里声明一个结点
    Each->pNext=NULL;

    int i = 0;
    QFile file(Filename1);
    file.open(QFile::ReadOnly);
    QDataStream fout(&file);
    if(fout.atEnd())    qDebug()<<"Nothing in data file";
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
        i++;
        Each = new Node1;
        Each->pNext=NULL;
        //千万千万注意只可以在结尾处给Each分配动态内存，因为我们的改变操作是在while中进行的
        //若是将上面语句放在第一行（也就是将创建放在读取之前），会将所有数据变成默认值
    }
    qDebug()<<"The end of the file";
    ShowList1(pHead);

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
    qDebug()<<"Here is the new list";
    ShowList1(pNew);


    //步骤三。将两个链表进行拼接
    qDebug()<<"Did it have";
    ShowList1(pointer);
    pointer->pNext= pHead;
    qDebug()<<"Finish";

    qDebug()<<"Here";
    Node1* Np = pNew;
    qDebug()<<"The list prepare to be saved";
    ShowList1(Np);
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
        fin<<Np;
        Np = Np->pNext;
        i++;
    }

    qDebug() << "成功保存"<<i <<"条数据"<< Qt::endl;
    file.close();
}

//覆盖写入一个文件内容
void Rewrite(Node1 *pNew)
{

    qDebug()<<"Enter the Rewrite Function!!!";
    //pNew是给入的暂时链表的头结点

    int i = 0;
    QFile file(Filename1);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    //截断，因为我们要从头开始写
    {
        qDebug() << "Error2:文件打开错误！！！" << Qt::endl;
    }
    QDataStream fin(&file);
    Node1* Np = pNew;
    while (Np)
    {
        fin<<Np;
        Np = Np->pNext;
        i++;
    }
    qDebug() << "成功保存"<<i <<"条数据"<< Qt::endl;
    file.close();
}

void BillAdd(int value, int year, int month, int date,
             QString note, bool Case)
{

        Node1* Add = new Node1;
        Add->value = Bill(value, year, month, date, note, Case);
        Add->pNext = NULL;

    SaveList1(Add);
    //将临时存储表进行添加
}

void BillAdd(Bill n)
{
    Node1* Add = new Node1;
    Add->value = n;
    Add->pNext = NULL;

    SaveList1(Add);
    //将临时存储表进行添加
}


//显示所有从数据文件中拿出的账单
void BillShow(void)
{
    ShowList1(BillFetch());
}

Node1* BillFetch(void)
{

    QFile file(Filename1);
    file.open(QIODevice::ReadOnly);
    QDataStream fout(&file);
    if (fout.atEnd())
    {
        qDebug() << "fout open error!!!" << Qt::endl;
        return NULL;
    }

    Node1* pHead = NULL;
    //准备读取数据文件中的头结点
    Node1* Each = new Node1;
    //先在这里声明一个结点
    Each->pNext=NULL;

    int i = 0;
    Node1* pointer=NULL;
    while (!fout.atEnd())
    {
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
        i++;
        Each = new Node1;
        Each->pNext=NULL;
        //千万千万注意只可以在结尾处给Each分配动态内存，因为我们的改变操作是在while中进行的
        //若是将上面语句放在第一行（也就是将创建放在读取之前），会将所有数据变成默认值
    }
    return pHead;
    qDebug()<<"Fetch finished";
}

Node1* BillDelete(int num)
{
    qDebug()<<"Enter the BillDelete Function";
    qDebug()<<"The delete number is:"<<num;
    Node1* head=BillFetch();
    Node1* pointer=head;
    Node1* pre=NULL;
    int i=0;
    if(num==1)
    {
        head=pointer->pNext;
        delete(pointer);
        pointer=NULL;
        qDebug()<<"Out the BillDelete Function"<<Qt::endl;
        ShowList1(head);
        return head;
    }

    while(1){
        i++;
        if(i==num)
        {
            break;
        }

        else
        {
            pre=pointer;
            pointer=pointer->pNext;
        }

        if(pointer==NULL){
            qDebug()<<"没有找到该数据";
            return NULL;
        }
    }

    //在这里我多加了一个which来避免IDE不清楚自己该回收哪一个部分
    pre->pNext=pointer->pNext;
    delete(pointer);
    pointer=NULL;
    qDebug()<<"Out the BillDelete Function"<<Qt::endl;
    ShowList1(head);
    return head;
}

//交换上下两个结点的数据
void BillSwap(Node1* current)
{
    Bill Tem = current->value;
    Bill Tem2 = current->pNext->value;
    current->value = Tem2;
    current->pNext->value = Tem;
}

//对账单进行排序
Node1* BillArrange(Node1* pHead)
{
    //创建辅助指针
    Node1* current = pHead;//此时current即为头指针，指向第一个节点
    int num = 0;
    //用于计算共有多少个结点
    while (current)
    {
        current = current->pNext;
        num++;
    }
    //for循环是冒泡排序第一层，while循环是冒泡排序第二层
    for (int i = 0; i < num - 1; i++)//冒泡思想，查找num-1次
    {
        current = pHead;//每次都从头开始找
        //cout << "第" << i + 1 << "次进入循环" << endl;//测试时使用
        while (current->pNext)
        {
            //获取相邻两个节点中所存储的时间数据
            int y1 = current->value.GetYear();
            int mo1 = current->value.GetMonth();
            int d1 = current->value.GetDate();

            int y2 = current->pNext->value.GetYear();
            int mo2 = current->pNext->value.GetMonth();
            int d2 = current->pNext->value.GetDate();

            //冒泡排序，年份先出现的大于后出现的则直接交换
            //如果两条数据时间完全相同则不交换
            if (y1 > y2)
            {
                BillSwap(current);
            }
            else if (y1 == y2)
            {
                if (mo1 > mo2)
                {
                    BillSwap(current);
                }
                else if (mo1 == mo2)
                {
                    if (d1 > d2)
                    {
                        BillSwap(current);
                    }


                }
            }
            current = current->pNext;
        }
    }
    current = pHead;

    return pHead;
}















