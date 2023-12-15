#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QtCharts/QChartGlobal>//将饼状图相关文件加入
#include "tallybook.h"
#include <QtCharts>
#include <QChartView>
#include <QSplineSeries>
#include "myspline.h"
#include "ui_myspline.h"

#define typeIn 1
#define typeOut 0

extern QString Username="None";
extern QString Filename1="Ini.dat";

//----------其他函数实现----------
//页面切换
void MainWindow::switchPage(){
    qDebug()<<"Into the switchPage function";
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button==ui->Add)
        ui->stackedWidget->setCurrentIndex(4);
    else if(button==ui->Display)
        ui->stackedWidget->setCurrentIndex(0);
    else if(button==ui->Statistics)
        ui->stackedWidget->setCurrentIndex(1);
    else if(button==ui->Settings)
        ui->stackedWidget->setCurrentIndex(2);
}

//存储输入
void MainWindow::Save()
{
        if((ui->lineEditNum->text()!="")&&
        (ui->rbtnIn->isChecked()||ui->rbtnOut->isChecked()))
    //判断数值的输入结果，有值才干活
    //收入支出，二选一，必须
        {
        qDebug()<<"Prepare to save";
        QDateTime Today =QDateTime::currentDateTime();
        QDateTime Yesterday= Today.addDays(-1);
        QString today =Today.toString("yyyy/MM/dd");
        QString today_year =Today.toString("yyyy");
        QString today_month =Today.toString("M");
        QString today_day =Today.toString("d");
        QString yesterday_year =Yesterday.toString("yyyy");
        QString yesterday_month =Yesterday.toString("M");
        QString yesterday_day =Yesterday.toString("d");
        qDebug()<<"today is: "<<today;
            //定义变量，最后要在函数中返回的也是这一些变量
        int y;
        int m;
        int d;
        int type;
        int v;
        QString note;

        note=ui->lineEditNote->text();
        v=ui->lineEditNum->text().toInt();

            //开始给各个变量赋值
            //时间赋值
            if(ui->btnToday->isChecked())
            {
                y=today_year.toInt();
                m=today_month.toInt();
                d=today_day.toInt();
                qDebug()<<"User choose today";
            }
            if(ui->btnYesterday->isChecked())
            {
                y=yesterday_year.toInt();
                m=yesterday_month.toInt();
                d=yesterday_day.toInt();
                qDebug()<<"User choose yesterday";
            }
            if(ui->btnChoose->isChecked())
            {
                y= ui->dateEdit->date().toString("yyyy").toInt();
                m= ui->dateEdit->date().toString("M").toInt();
                d= ui->dateEdit->date().toString("d").toInt();
                qDebug()<<"User choose another day";
            }
            //是否为收入赋值
            if(ui->rbtnIn->isChecked())
            {
                type=typeIn;
            }
            else if(ui->rbtnOut->isChecked())
            {
                type=typeOut;
            }
            else
            {
                qDebug()<<"Big Error:Not sure about the account type";
            }

            Bill n=Bill(v,y,m,d,note,type);
            BillAdd(n);


            //将所有按钮恢复原位
            ui->lineEditNum->setText("");
            ui->lineEditNote->setText("");//将输入框的文本置空

            ui->rbtnIn->setAutoExclusive(false);
            ui->rbtnOut->setAutoExclusive(false);
            ui->rbtnIn->setChecked(false);
            ui->rbtnOut->setChecked(false);
            ui->rbtnIn->setAutoExclusive(true);
            ui->rbtnOut->setAutoExclusive(true);
            //只有将两个按钮之间的互斥状态取消之后，才能够进行全部取消选中
            //所以这里我是让两个按钮先取消互斥，再互相关联

            ui->btnToday->setAutoExclusive(false);
            ui->btnYesterday->setAutoExclusive(false);
            ui->btnChoose->setAutoExclusive(false);
            ui->btnToday->setChecked(false);
            ui->btnYesterday->setChecked(false);
            ui->btnChoose->setChecked(false);
            ui->btnToday->setAutoExclusive(true);
            ui->btnYesterday->setAutoExclusive(true);
            ui->btnChoose->setAutoExclusive(true);
            //日期处的按钮同理

            qDebug()<<"保存了一条数据";
        }
}

//----------PageAdd----------
//小时钟——更新时间
void MainWindow::ClockChange()
{
        QTime time=QTime::currentTime();
        QString text=time.toString(("hh:mm"));
        //So in this place,'h'&'m'&'s'symbolize hour and minute and second accordingly
        if((time.second()%2)==0)    text[2]=' ';
        //The second() is the "second"!,this means each second,the":"will be replaced by ' '
        ui->Lcd->display(text);
}

//小日历是否可见
void MainWindow::CalendarVisiable()
{
        if(ui->dateEdit->isVisible()==true)
            ui->dateEdit->setVisible(false);
        else
            ui->dateEdit->setVisible(true);
}

void MainWindow::Clear()
{
        BillClear();
}

//----------PageShow----------
void MainWindow::Table()
{
        qDebug()<<"The file name is:"<<Filename1;
        ui->tableWidget->setVisible(true);

        //接下来就是打开文件

        QFile file(Filename1);
        file.open(QIODevice::ReadOnly);
        QDataStream fout(&file);
        Node1* pHead = NULL;
        //准备读取数据文件中的头结点
        Node1* Each = new Node1;
        //先在这里声明一个结点

        int i = 0;
        Node1* pointer=NULL;

        if(fout.atEnd()){
            ui->Notice->setText("你还没有输入账单哦！！！");
            qDebug()<<"This is empty!!"<<Qt::endl;
            return;
        }

        ui->tableWidget->clearContents();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //进来时先全部清空内容

        int iRow = 0;
        do
        {

            fout>>Each;
            qDebug()<<"The iRow now is"<<iRow;

            ui->tableWidget->setRowCount(++iRow);
            qDebug()<<"行数设置为:"<<iRow;
            //总行数增加1//iRow从0变成1
            //setItem函数里面前两个参数row column
            //设置日期
            ui->tableWidget->
                setItem(iRow-1,0,new QTableWidgetItem(QString::number(Each->value.GetYear())+"/"
                                                      +QString::number(Each->value.GetMonth())+"/"+
                                                                       QString::number(Each->value.GetDate())));
            ui->tableWidget->item(iRow-1, 0)->setTextAlignment(Qt::AlignCenter);

            //设置收入还是支出
            if(Each->value.GetCase()==typeOut){
                ui->tableWidget->setItem(iRow-1,1,new QTableWidgetItem(QString("支出")));//amount,这里要加正号
            }
            else if(Each->value.GetCase()==typeIn){
                ui->tableWidget->setItem(iRow-1,1,new QTableWidgetItem(QString("收入")));//amount,这里要加正号
            }

            else{
                qDebug()<<"Error:数据收支类型出错";
            }
            ui->tableWidget->item(iRow-1, 1)->setTextAlignment(Qt::AlignCenter);//居中
            //设置金额
            ui->tableWidget->setItem(iRow-1,2,new QTableWidgetItem(QString::number(Each->value.GetValue())));
            ui->tableWidget->item(iRow-1, 2)->setTextAlignment(Qt::AlignCenter);

            //设置备注
            ui->tableWidget->setItem(iRow-1,3,new QTableWidgetItem(QString(Each->value.GetNote())));
            ui->tableWidget->item(iRow-1, 3)->setTextAlignment(Qt::AlignCenter);
            qDebug()<<"ONE";
            }while(!fout.atEnd());
        ui->Notice->setText("您一共有"+QString::number(iRow)+"条账单");
        //再把页面切过来
        ui->tableWidget->update();
        ui->stackedWidget->setCurrentIndex(0);
        //将页面重新刷新一遍，不然改变刷不出来
}

void MainWindow::TableClear()
{
        int row=0;
        while(ui->tableWidget->item(row,0))
        {
            qDebug()<<"Delete the"<<row<<"row";
            ui->tableWidget->removeRow(row);
            row++;
        }
}

//----------PageStatics----------
void MainWindow::ShowPie()
{
        //接下来就是打开文件
        QFile file(Filename1);
        qDebug()<<"In ShowPie:"<<Filename1;
        file.open(QIODevice::ReadOnly);
        QDataStream fout(&file);
        Node1* pHead = NULL;
        //准备读取数据文件中的头结点
        Node1* Each = new Node1;
        //先在这里声明一个结点
        int i = 0;
        Node1* pointer=NULL;
        int income=0;
        int outlay=0;
        do
        {
            fout>>Each;
            qDebug()<<"The case is:"<<Each->value.GetCase();
            if(Each->value.GetCase()==0)
            {
                outlay+=Each->value.GetValue();
            }
            else if(Each->value.GetCase()==1)
            {
                income+=Each->value.GetValue();
            }
            else
            {
                qDebug()<<"Error：数据类型错误";
            }
            qDebug()<<"ONE";
        }while(!fout.atEnd());

        ui->PrintIn->setText("收入："+QString::number(income));
        ui->PrintOut->setText("支出："+QString::number(outlay));
        ui->PrintAll->setText("总计: "+QString::number(income-outlay));
        //设计绘饼图
        QPieSeries *pies = new QPieSeries();
        pies->setHoleSize(0.3); //设置饼图中心空心圆的大小
        //显示“指向饼图中份额的标签”，也就是图标；需要在添加所有label之后再写这句，不然之后添加的看不到
        pies->setLabelsVisible();
        pies->append("收入",income);
        pies->append("支出",outlay);
       //会重启一段

        //----------画表开始----------
        QChart *chart = new QChart();//创建chart//别删除这个，不然看不到
        chart->addSeries(pies);//把之前准备好的series放到表里
        chart->setBackgroundVisible(false);     //背景色透明

        QChartView *chartview = new QChartView(chart);//这个别删

        chartview->setRenderHint(QPainter::Antialiasing);//设置chart渲染属性为 “抗混叠” (QPainter::Antialiasing)；
        chartview->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);//不太清楚这个有用没，设置布局
        chartview->setParent(ui->Blank);//让chartview在第三页的空widget上显示出来（widget在ui界面放好了）
        chartview->resize(QSize(350,350));
        //resize 只有在最后一步，添加完所有效果之后才能指定大小
        chartview->show();//和上面一行的顺序不能换
       //----------画表结束----------
}

void MainWindow::ShowSpline()
{
        QDateTime Today =QDateTime::currentDateTime();
        QDateTime Yesterday= Today.addDays(-1);
        QString today =Today.toString("yyyy/MM/dd");
        QString today_year =Today.toString("yyyy");
        QString today_month =Today.toString("M");
        QString today_day =Today.toString("d");
        QString yesterday_year =Yesterday.toString("yyyy");
        QString yesterday_month =Yesterday.toString("M");
        QString yesterday_day =Yesterday.toString("d");
        qDebug()<<"today is: "<<today;
        if((today_day).toInt()<7)
            return ;
        MySpline *b=new MySpline();
        b->show();
}

//----------PageSet----------
//改变背景色
void MainWindow::ChangeColor()
{
        QString color;
        QString in=ui->comboBox->currentText();
        if(in=="金黄")
    {
            color="rgb(252,207,107)";
            qDebug()<<"金黄";
        }
        else if(in=="苍色")
{
            color="rgb(127,158,143)";
            qDebug()<<"苍色";
        }
        else if(in=="群青")
{
            color="rgb(148,163,187)";
            qDebug()<<"群青";
        }
        else if(in=="藤紫"){
            color="rgb(215,199,225)";
            qDebug()<<"藤紫";
        }

        this->setStyleSheet("background-color:"+color);
}

//主要窗口的构造函数
 MainWindow::MainWindow(QWidget *parent )
: QWidget(parent)
    , ui(new Ui::MainWindow)
{

        QPalette PAllbackground = this->palette();
        QImage ImgAllbackground(":/res/background.jpg");
        QImage fitimgpic=ImgAllbackground.scaled(this->width(),this->height(), Qt::IgnoreAspectRatio);
        PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
        this->setPalette(PAllbackground);

    ui->setupUi(this);
        this->resize(1000,700);//规定窗口大小
    ui->PageShow->setLayout(ui->verticalLayout_3);
        ui->PageAdd->setLayout(ui->verticalLayout_5);

    ui->MenuLayout->setSpacing(2);

    setWindowIcon(QIcon(":/res/Note.png"));

    setWindowTitle("桌面助手——记账本");
    ui->stackedWidget->setCurrentIndex(3);
    //将进入的默认界面设置为Welcome Page

    ui->UserHead->setPixmap(QPixmap(":/res/UserHead.png"));
    ui->UserHead->resize(200,200);
    //设置图标
    QIcon icon = QIcon(":/res/Note.png");
    QPixmap titlen = icon.pixmap(icon.actualSize(QSize(70, 70)));

    ui->Title->setText("Tally Book —— 记账本");
    ui->UserName->setText(Username);
    ui->UserName->setAlignment(Qt::AlignHCenter);
    ui->Add->setIcon(QIcon(":/res/Add.png"));
    ui->Add->setIconSize(QSize(25,25));

    ui->Display->setIcon(QIcon(":/res/Modify.png"));
    ui->Display->setIconSize(QSize(25,25));

    ui->Statistics->setIcon(QIcon(":/res/Statistics.png"));
    ui->Statistics->setIconSize(QSize(25,25));

    ui->Settings->setIcon(QIcon(":/res/Settings.png"));
    ui->Settings->setIconSize(QSize(25,25));

    ui->Quit->setIcon(QIcon(":/res/Quit.png"));
    ui->Quit->setIconSize(QSize(25,25));

    ui->LuckyPig->setPixmap(QPixmap(":/res/LuckyPig.png"));
    ui->LuckyPig->resize(QSize(150,125));

    //连接信号和槽
    connect(ui->Quit,SIGNAL(clicked(bool)),this,SLOT(close()));
    qDebug() << "获取当前页面的索引: " << ui->stackedWidget->currentIndex();
    connect(ui->Add,SIGNAL(clicked(bool)),this,SLOT(switchPage()));
    connect(ui->Display,SIGNAL(clicked(bool)),this,SLOT(switchPage()));
    connect(ui->Settings,SIGNAL(clicked(bool)),this,SLOT(switchPage()));
    connect(ui->Statistics,SIGNAL(clicked(bool)),this,SLOT(switchPage()));

//页面1：Add Page
    QDateTime Today =QDateTime::currentDateTime();
    QDateTime Yesterday= Today.addDays(-1);
    QString today =Today.toString("yyyy/MM/dd");
    QString today_year =Today.toString("yyyy");
    QString today_month =Today.toString("M");
    QString today_day =Today.toString("d");
    QString yesterday_year =Yesterday.toString("yyyy");
    QString yesterday_month =Yesterday.toString("M");
    QString yesterday_day =Yesterday.toString("d");
    qDebug()<<"today is: "<<today;
    ui->stackedWidget->setStyleSheet("background-color:white");

    //对于Lcd的设置
    Timer=new QTimer(this);
    ui->Lcd->display("UUUUF:O");
    ui->TodayTime->setText("今天日期：\tToday\t"+today);//让最上面的标签显示当前日期
    ui-> Lcd->setStyleSheet("QLCDNumber{background-color:white;color:black}");

    ui->horizontalLayout_3->setStretchFactor(ui->TodayTime,4);
    ui->horizontalLayout_3->setStretchFactor(ui->Lcd,1);
    connect(Timer,SIGNAL(timeout()),this,SLOT(ClockChange()));
    Timer->start(1000);
    //Timer在这里怎么感觉更像是一个计时器之类的，而Time就是获取系统时间的
    //确实，Timer就是用来计时间触发的
    ui->btnToday->setChecked(true);
    //默认勾选今天
    ui->dateEdit->setDate(Today.date());
    //自定义的候选框也默认是今天的时间

    ui->dateEdit->setVisible(false);
    //dateEdit的默认状态为false，当勾选其他日期时，才会显示

    connect(ui->btnChoose,SIGNAL(toggled(bool)),this,SLOT(CalendarVisiable()));

    //设置只能输入数字
    ui->lineEditNum->setValidator(new QIntValidator(1, 65535));
    //设置背景提示字符
    ui->lineEditNum->setPlaceholderText(QString("只允许输入数字"));
    ui->lineEditNote->setPlaceholderText(QString("请输入备注"));

    connect(ui->btnSave,SIGNAL(clicked(bool)),this,SLOT(Save()));

//页面2：Display/Show Page
    connect(ui->Display,SIGNAL(clicked(bool)),this,SLOT(Table()));
    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(Clear()));
    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(TableClear()));
    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(Table()));
    ui->tableWidget->setColumnWidth(0,150);//设置列宽
    ui->tableWidget->setColumnWidth(1, 100);//设置列宽
    ui->tableWidget->setColumnWidth(2, 100);//设置列宽
    ui->tableWidget->setColumnWidth(3, 250);//设置列宽
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->Display,SIGNAL(clicked(bool)),this,SLOT(Table()));

//页面3：Statistics Page
    connect(ui->Statistics,SIGNAL(clicked(bool)),this,SLOT(ShowPie()));
    connect(ui->ToSpline,SIGNAL(clicked(bool)),this,SLOT(ShowSpline()));

//页面4：Setting Page
    connect(ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(ChangeColor()));
}


MainWindow::~MainWindow()
{
delete ui;
}



