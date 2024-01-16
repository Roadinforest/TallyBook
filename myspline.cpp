#include "myspline.h"
#include "ui_myspline.h"
#include "tallybook.h"
#include <Qtime>

MySpline::MySpline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MySpline)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:white");
    setWindowTitle("一周内账单变化趋势折线图");

    auto set0 = new QBarSet("收入");
    auto set1 = new QBarSet("支出");

    connect(ui->QuitSpline,SIGNAL(clicked(bool)),this,SLOT(close()));

    QDateTime Today =QDateTime::currentDateTime();
    QString today =Today.toString("yyyy/MM/dd");
    QString today_year =Today.toString("yyyy");
    QString today_month =Today.toString("M");
    QString today_day =Today.toString("d");
    qDebug()<<"today is: "<<today;

    QFile file(Filename1);
    file.open(QIODevice::ReadOnly);
    QDataStream fout(&file);
    if (!fout.atEnd())
    {
        qDebug() << "fout open error!!!" << Qt::endl;
    }
    Node1* pHead = NULL;
    //准备读取数据文件中的头结点
    Node1* Each = new Node1;
    //先在这里声明一个结点
    int lastseven[7]{0};
    int Forbar[7][2]{0};//存放存入bar的数据

    int deal;

    Node1* pointer=NULL;
    while (!fout.atEnd())
    {
        fout>>Each;
        if(QString::number(Each->value.GetYear())==today_year
            &&QString::number(Each->value.GetMonth())==today_month
            &&(Each->value.GetDate())==today_day.toInt()
            ){
            if(Each->value.GetCase()==Income){
                deal=Each->value.GetValue();
                Forbar[6][0]+=deal;
            }
            else if(Each->value.GetCase()==Outlay){
                deal=-Each->value.GetValue();
                Forbar[6][1]+=deal;
            }
            lastseven[6]+=deal;
        }
        else if(QString::number(Each->value.GetYear())==today_year
                 &&QString::number(Each->value.GetMonth())==today_month
                   &&(Each->value.GetDate())==today_day.toInt()-1
                 ){
            if(Each->value.GetCase()==Income){
                deal=Each->value.GetValue();
                Forbar[5][0]+=deal;
            }
            else if(Each->value.GetCase()==Outlay){
                deal=-Each->value.GetValue();
                Forbar[5][1]+=deal;
            }
            lastseven[5]+=deal;
        }
        else if(QString::number(Each->value.GetYear())==today_year
                 &&QString::number(Each->value.GetMonth())==today_month
                 &&(Each->value.GetDate())==today_day.toInt()-2
                 ){
            if(Each->value.GetCase()==Income){
                deal=Each->value.GetValue();
                Forbar[4][0]+=deal;
            }
            else if(Each->value.GetCase()==Outlay){
                deal=-Each->value.GetValue();
                Forbar[4][1]+=deal;
            }
            lastseven[4]+=deal;
        }
        else if(QString::number(Each->value.GetYear())==today_year
                 &&QString::number(Each->value.GetMonth())==today_month
                 &&(Each->value.GetDate())==today_day.toInt()-3
                 ){
            if(Each->value.GetCase()==Income){
                deal=Each->value.GetValue();
                Forbar[3][0]+=deal;
            }
            else if(Each->value.GetCase()==Outlay){
                deal=-Each->value.GetValue();
                Forbar[3][1]+=deal;
            }
            lastseven[3]+=deal;
        }
        else if(QString::number(Each->value.GetYear())==today_year
                 &&QString::number(Each->value.GetMonth())==today_month
                 &&(Each->value.GetDate())==today_day.toInt()-4
                 ){
            if(Each->value.GetCase()==Income){
                deal=Each->value.GetValue();
                Forbar[2][0]+=deal;
            }
            else if(Each->value.GetCase()==Outlay){
                deal=-Each->value.GetValue();
                Forbar[2][1]+=deal;
            }
            lastseven[2]+=deal;
        }
        else if(QString::number(Each->value.GetYear())==today_year
                 &&QString::number(Each->value.GetMonth())==today_month
                 &&(Each->value.GetDate())==today_day.toInt()-5
                 ){
            if(Each->value.GetCase()==Income){
                deal=Each->value.GetValue();
                Forbar[1][0]+=deal;
            }
            else if(Each->value.GetCase()==Outlay){
                deal=-Each->value.GetValue();
                Forbar[1][1]+=deal;
            }
            lastseven[1]+=deal;
        }
        else if(QString::number(Each->value.GetYear())==today_year
                 &&QString::number(Each->value.GetMonth())==today_month
                 &&(Each->value.GetDate())==today_day.toInt()-6
                 ){
            if(Each->value.GetCase()==Income){
                deal=Each->value.GetValue();
                Forbar[0][0]+=deal;
            }
            else if(Each->value.GetCase()==Outlay){
                deal=-Each->value.GetValue();
                Forbar[0][1]+=deal;
            }
            lastseven[0]+=deal;
        }

        Each = new Node1;
        //千万千万注意只可以在结尾处给Each分配动态内存，因为我们的改变操作是在while中进行的
        //若是将上面语句放在第一行（也就是将创建放在读取之前），会将所有数据变成默认值
    }
    for(int i=0;i<7;i++){
        qDebug()<<lastseven[i]<<Qt::endl;
    }

    auto lineseries = new QLineSeries;
    lineseries->setName("总和");
    lineseries->append(QPoint(0, lastseven[0]));
    lineseries->append(QPoint(1, lastseven[1]));
    lineseries->append(QPoint(2, lastseven[2]));
    lineseries->append(QPoint(3, lastseven[3]));
    lineseries->append(QPoint(4, lastseven[4]));
    lineseries->append(QPoint(5, lastseven[5]));
    lineseries->append(QPoint(6, lastseven[6]));

    *set0 << Forbar[0][0]<<Forbar[1][0]<<Forbar[2][0]<<Forbar[3][0]<< Forbar[4][0]<<Forbar[5][0]<<Forbar[6][0];
    *set1 << Forbar[0][1]<<Forbar[1][1]<<Forbar[2][1]<<Forbar[3][1]<< Forbar[4][1]<<Forbar[5][1]<<Forbar[6][1];

    auto barseries = new QBarSeries;
    barseries->append(set0);
    barseries->append(set1);

    auto chart = new QChart;
    chart->addSeries(barseries);
    chart->addSeries(lineseries);
    chart->setTitle("一周内账单变化图");

    QStringList categories;
    categories << "六天前" << "五天前" << "四天前"<<"大前天" << "前天" << "昨天" << "今天";
    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    lineseries->attachAxis(axisX);
    barseries->attachAxis(axisX);
    axisX->setRange(QString("六天前"), QString("今天"));

    int min=Forbar[0][1];
    for(int i=0;i<7;i++)
    {
        if(min>Forbar[i][1])
        {
            min=Forbar[i][1];
        }
    }

    int max=Forbar[0][0];
    for(int i=0;i<7;i++)
    {
        if(max<Forbar[i][0])
        {
            max=Forbar[i][0];
        }
    }

    //上面两个循环用于计算最小最大值，用来确定y轴范围

    auto axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    lineseries->attachAxis(axisY);
    barseries->attachAxis(axisY);
    axisY->setRange(min,max);
    axisY->setLabelFormat("%.2f"); //标签格式
    axisY->setTickCount(1);
    axisY->setMinorTickCount(2);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QPen pen(QColor(255, 165, 0));  // 使用橙色
    pen.setWidth(3);
    lineseries->setPen(pen);

    QChartView *chartView = new QChartView(this);
    chartView->setChart(chart);
    chartView->resize(QSize(500,300));              //重新设置chartView的大小
    chartView->setRenderHints(QPainter::Antialiasing);//消除边缘，看起来平滑一些
    ui->horizontalLayout->addWidget(chartView);    //把chartView放到水平布局中（在ui中拖一个水平布局）
    this->setLayout(ui->horizontalLayout);
    this->resize(700,500);
}

MySpline::~MySpline()
{
    delete ui;
}
