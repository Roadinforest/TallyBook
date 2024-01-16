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
#include <QSplineSeries>
#include <QRandomGenerator>
#include <QMovie>
#include "myspline.h"
#include "ui_myspline.h"
#include "kindchart.h"
#include "ui_kindchart.h"
#define typeIn 1
#define typeOut 0

QString Username="None";
QString Filename1="Ini.dat";

//----------一些一般函数的实现----------
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
        qDebug()<<"Enter the save function:"<<Qt::endl;
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
        OutputCase kind;

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

            if(ui->comboBoxKind->currentText()=="其他支出")
            {
                kind=Other;
            }
            else if(ui->comboBoxKind->currentText()=="衣")
                {
                kind=Clothes;
            }
            else if(ui->comboBoxKind->currentText()=="食")
                {
                kind=Food;
            }
            else if(ui->comboBoxKind->currentText()=="住")
                {
                kind=Housing;
            }
            else if(ui->comboBoxKind->currentText()=="行")
                {
                kind=Transports;
            }

            Bill n=Bill(v,y,m,d,note,type,kind);
            BillAdd(n);
            //将所有按钮恢复原位
            ui->lineEditNum->setText("");
            ui->lineEditNote->setText("");//将输入框的文本置空
            ui->comboBoxKind->setCurrentIndex(0);

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
            qDebug()<<"Out the Function Save"<<Qt::endl;
        }
}

//删除指定一条数据
void MainWindow::Delete()
{
        if(ui->comboBoxShowKind->currentText()=="按账单日期排序")
        {
            ui->Notice->setText("只可以在“按输入时间排序”状态下才能删除账单哦");
            ui->Notice->setStyleSheet("color: red;");
            return;
        }
        int which=ui->numericSpinBox->value();
        if(which==0)
        {
            ui->Notice->setText("不能删除不存在的账单哦");
            ui->Notice->setStyleSheet("color: red;");
            return;
        }
        Node1* changed=BillDelete(which);
        Rewrite(changed);
        TableClear();
        Table();
}

//----------PageAdd----------
//小时钟——更新时间
void MainWindow::ClockChange()
{
        QTime time=QTime::currentTime();
        QString text=time.toString(("hh:mm"));
        if((time.second()%2)==0)    text[2]=' ';
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

//支出种类是否可见
void MainWindow::KindVisiable()
{
        if(ui->comboBoxKind->isVisible()==true)
            ui->comboBoxKind->setVisible(false);
        else
            ui->comboBoxKind->setVisible(true);
}

//返回一句随机名言
QString MainWindow::GiveMeOne()
{
        int randomNumber = QRandomGenerator::global()->bounded(10);//获取一个十以内的随机数(0-9)
        QString get;
        if(randomNumber==0)
        {
            get="The only way to do great work is to love what you do.\n- Steve Jobs";
        }
        else if(randomNumber==1)
        {
            get="Believe you can and you're halfway there.\n- Theodore Roosevelt";
        }
        else if(randomNumber==2)
        {
            get="Don't watch the clock; do what it does. Keep going.\n - Sam Levenson";
        }
        else if(randomNumber==3)
        {
            get="The future belongs to those who believe in the beauty of their dreams.\n- Eleanor Roosevelt";
        }
        else if(randomNumber==4)
        {
            get="It's not whether you get knocked down, it's whether you get up.\n- Vince Lombardi";
        }
        else if(randomNumber==5)
        {
            get="Success is not final, failure is not fatal: It is the courage to continue that counts.\n- Winston Churchill";
        }
        else if(randomNumber==6)
        {
            get="Your time is limited, don't waste it living someone else's life.\n- Steve Jobs";
        }
        else if(randomNumber==7)
        {
            get="Don't be pushed around by the fears in your mind. Be led by the dreams in your heart.\n- Roy T. Bennett";
        }
        else if(randomNumber==8)
        {
            get="The only limit to our realization of tomorrow will be our doubts of today.\n- Franklin D. Roosevelt";
        }
        else if(randomNumber==9)
        {
            get="The only way to achieve the impossible is to believe it is possible.\n - Charles Kingsleigh";
        }
        return get;
}

void MainWindow::ChangeOne()
{
    QString get=GiveMeOne();
    ui->Words->setText(get);
}

void MainWindow::Clear()
{
    BillClear();
}

//----------PageShow----------
void MainWindow::Table()
{
    ui->comboBoxShowKind->setCurrentIndex(0);
        ui->Notice->setStyleSheet("color: black;");
        qDebug()<<"The file name is:"<<Filename1;
        ui->tableWidget->setVisible(true);

        //接下来就是打开文件

        QFile file(Filename1);
        file.open(QIODevice::ReadOnly);
        QDataStream fout(&file);
        //准备读取数据文件中的头结点
        Node1* Each = new Node1;
        //先在这里声明一个结点

        if(fout.atEnd()){
            ui->Notice->setText("你还没有输入账单哦！！！");
            ui->Notice->setStyleSheet("color: red;");
            qDebug()<<"This is empty!!"<<Qt::endl;
            ui->numericSpinBox->setMaximum(0);
            return;
        }

        ui->tableWidget->clearContents();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //进来时先全部清空内容

        int iRow = 0;
        do
        {
            if(Each==NULL)break;
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

        // 设置spinbox最小值和最大值
        ui->numericSpinBox->setMinimum(0);
        ui->numericSpinBox->setMaximum(iRow);
        //再把页面切过来
        ui->tableWidget->update();
        ui->stackedWidget->setCurrentIndex(0);
        //将页面重新刷新一遍，不然改变刷不出来
        Each=NULL;
}

void MainWindow::Table_arranged()
{
        qDebug()<<"The file name is:"<<Filename1;
        ui->tableWidget->setVisible(true);

        ui->tableWidget->clearContents();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //进来时先全部清空内容

        Node1* phead=BillArrange(BillFetch());
        if(phead==NULL){
            ui->Notice->setText("你还没有输入账单哦！！！");
            ui->Notice->setStyleSheet("color: red;");
            qDebug()<<"This is empty!!"<<Qt::endl;
            ui->numericSpinBox->setMaximum(0);
            return;
        }

        Node1* Each=phead;
        //先在这里声明一个结点
        int iRow = 0;
        do
        {
            if(Each==NULL)break;
            if(iRow!=0)Each=Each->pNext;
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
        }while(Each->pNext!=NULL);

        ui->Notice->setText("您一共有"+QString::number(iRow)+"条账单");

        // 设置spinbox最小值和最大值
        ui->numericSpinBox->setMinimum(0);
        ui->numericSpinBox->setMaximum(iRow);
        //再把页面切过来
        ui->tableWidget->update();
        ui->stackedWidget->setCurrentIndex(0);
        //将页面重新刷新一遍，不然改变刷不出来
        Each=NULL;
}

void MainWindow::ChangeArrange()
{
        QString in=ui->comboBoxShowKind->currentText();
        if(in=="按输入时间排序")
        {
            TableClear();
            Table();
        }
        else if(in=="按账单日期排序")
        {
            TableClear();
            Table_arranged();
        }
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
void MainWindow::ShowPie1()
{
        ui->comboBoxPieColor->setCurrentIndex(0);
        //接下来就是打开文件
        QFile file(Filename1);
        qDebug()<<"In ShowPie1:"<<Filename1;
        file.open(QIODevice::ReadOnly);
        QDataStream fout(&file);
        //准备读取数据文件中的头结点
        Node1* Each = new Node1;
        Each->pNext=NULL;
        //先在这里声明一个结点
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
        file.close();

        delete Each;
        Each=NULL;

        ui->PrintIn->setText("收入："+QString::number(income));
        ui->PrintOut->setText("支出："+QString::number(outlay));
        ui->PrintAll->setText("总计: "+QString::number(income-outlay));
        //设计绘饼图
        pies1 = new QPieSeries();
        pies1->setHoleSize(0.3); //设置饼图中心空心圆的大小
        //显示“指向饼图中份额的标签”，也就是图标；需要在添加所有label之后再写这句，不然之后添加的看不到
        pies1->setLabelsVisible();
        pies1->append("收入",income);
        pies1->append("支出",outlay);

       //会重启一段

        //----------画表开始----------
        QChart *chart = new QChart();//创建chart//别删除这个，不然看不到
        chart->addSeries(pies1);//把之前准备好的series放到表里
        chart->setBackgroundVisible(false);     //背景色透明
        chart->setTitle("收入支出占比饼状图");

        QChartView *chartview = new QChartView(chart);//这个别删

        chartview->setRenderHint(QPainter::Antialiasing);//设置chart渲染属性为 “抗混叠” (QPainter::Antialiasing)；
        chartview->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);//不太清楚这个有用没，设置布局
        chartview->setParent(ui->Blank);//让chartview在第三页的空widget上显示出来（widget在ui界面放好了）
        chartview->resize(QSize(300,300));
        //resize 只有在最后一步，添加完所有效果之后才能指定大小
        chartview->show();//和上面一行的顺序不能换
        //----------画表结束----------
}

void MainWindow::ShowPie2()
{
        //接下来就是打开文件
        QFile file(Filename1);
        qDebug()<<"In ShowPie2:"<<Filename1;
        file.open(QIODevice::ReadOnly);
        QDataStream fout(&file);
        //准备读取数据文件中的头结点
        Node1* Each = new Node1;
        Each->pNext=NULL;
        //先在这里声明一个结点

        int others=0;
        int clothes=0;
        int food=0;
        int houseing=0;
        int transports=0;
        do
        {
            fout>>Each;
            if(Each->value.GetCase()==1)
            {
                continue;
            }

            if(Each->value.GetKind()==Other)
            {
                others+=Each->value.GetValue();
            }
            else if(Each->value.GetKind()==Clothes)
            {
                clothes+=Each->value.GetValue();
            }
            else if(Each->value.GetKind()==Food)
            {
                food+=Each->value.GetValue();
            }
            else if(Each->value.GetKind()==Housing)
            {
                houseing+=Each->value.GetValue();
            }
            else if(Each->value.GetKind()==Transports)
            {
                transports+=Each->value.GetValue();
            }
            else
            {
                qDebug()<<"Error：数据类型错误";
            }
            qDebug()<<"ONE";
        }while(!fout.atEnd());
        file.close();

        delete Each;
        Each=NULL;
        //设计绘饼图
        pies2 = new QPieSeries();
        pies2->setHoleSize(0.3); //设置饼图中心空心圆的大小
        //显示“指向饼图中份额的标签”，也就是图标；需要在添加所有label之后再写这句，不然之后添加的看不到
        pies2->setLabelsVisible();
        pies2->append("其他支出",others);
        pies2->append("衣",clothes);
        pies2->append("食",food);
        pies2->append("住",houseing);
        pies2->append("行",transports);
       //会重启一段
        double all=others+clothes+food+houseing+transports;
        ui->PrintClothes->setText("衣："+QString::number(clothes)+"\t占比："+QString::number(clothes/all));
        ui->PrintFood->setText("食："+QString::number(food)+"\t占比："+QString::number(food/all));
        ui->PrintHousing->setText("住: "+QString::number(houseing)+"\t占比："+QString::number(houseing/all));
        ui->PrintTransports->setText("行："+QString::number(transports)+"\t占比："+QString::number(transports/all));
        ui->PrintOthers->setText("其他: "+QString::number(others)+"\t占比："+QString::number(others/all));
        //----------画表开始----------

        QChart *chart2 = new QChart();//创建chart//别删除这个，不然看不到
        chart2->addSeries(pies2);//把之前准备好的series放到表里
        chart2->setBackgroundVisible(false);     //背景色透明
        chart2->setTitle("支出分配饼状图");

        QChartView *chartview2 = new QChartView(chart2);
        chartview2->setRenderHint(QPainter::Antialiasing);//设置chart渲染属性为 “抗混叠” (QPainter::Antialiasing)；
        chartview2->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);//不太清楚这个有用没，设置布局
        chartview2->setParent(ui->Blank_2);//让chartview在第三页的空widget上显示出来（widget在ui界面放好了）

        chartview2->resize(QSize(350,350));
        //resize 只有在最后一步，添加完所有效果之后才能指定大小
        chartview2->show();//和上面一行的顺序不能换
        //----------画表结束----------
}

void MainWindow::ShowSpline()
{
        QDateTime Today =QDateTime::currentDateTime();
        QString today =Today.toString("yyyy/MM/dd");
        QString today_day =Today.toString("d");
        qDebug()<<"today is: "<<today;
        if((today_day).toInt()<7)
            return ;
        MySpline *b=new MySpline();
        b->show();
}

void MainWindow::ShowKind()
{
        QDateTime Today =QDateTime::currentDateTime();
        QString today =Today.toString("yyyy/MM/dd");
        QString today_day =Today.toString("d");
        qDebug()<<"today is: "<<today;
        if((today_day).toInt()<7)
            return ;
        kindchart *c=new kindchart();
        c->show();
}

//----------PageSet----------
//改变背景色
void MainWindow::ChangeColor()
{
        QString color;
        QString in=ui->comboBoxColor->currentText();
        if(in=="金黄")
    {
            color="rgb(252,207,107)";
            qDebug()<<"金黄";
        }
        else if(in=="草绿")
{
            color="rgb(144, 220, 140)";
            qDebug()<<"草绿";
        }
        else if(in=="湖蓝")
{
            color="rgb(173, 216, 230)";
            qDebug()<<"湖蓝";
        }
        else if(in=="藤紫"){
            color="rgb(230, 230, 250)";
            qDebug()<<"藤紫";
        }

        this->setStyleSheet("background-color:"+color);
}

void MainWindow::ChangeUserHead()
{
        QString in=ui->comboBoxUser->currentText();
        if(in=="默认")
        {
            ui->UserHead->setPixmap(QPixmap(":/res/UserHead.png"));
            ui->UserHead->resize(200,200);
            //png与jpg的处理方式略有不同
        }
        else if(in=="Baby1")
        {
            QPixmap originalPixmap(":/res/Baby1.jpg");
            QPixmap scaledPixmap = originalPixmap.scaled(200, 200, Qt::KeepAspectRatio);
            ui->UserHead->setPixmap(scaledPixmap);
        }
        else if(in=="Baby2")
        {
            QPixmap originalPixmap(":/res/Baby2.jpg");
            QPixmap scaledPixmap = originalPixmap.scaled(200, 200, Qt::KeepAspectRatio);
            ui->UserHead->setPixmap(scaledPixmap);
        }
        else if(in=="Baby3")
        {
            QPixmap originalPixmap(":/res/Baby3.jpg");
            QPixmap scaledPixmap = originalPixmap.scaled(200, 200, Qt::KeepAspectRatio);
            ui->UserHead->setPixmap(scaledPixmap);
        }
        else if(in=="Baby4")
        {
            QPixmap originalPixmap(":/res/Baby4.jpg");
            QPixmap scaledPixmap = originalPixmap.scaled(200, 200, Qt::KeepAspectRatio);
            ui->UserHead->setPixmap(scaledPixmap);
        }
        else if(in=="CuteBoy")
        {
            QPixmap originalPixmap(":/res/CuteBoy.jpg");
            QPixmap scaledPixmap = originalPixmap.scaled(200, 200, Qt::KeepAspectRatio);
            ui->UserHead->setPixmap(scaledPixmap);
        }
        else if(in=="CuteGirl")
        {
            QPixmap originalPixmap(":/res/CuteGirl.jpg");
            QPixmap scaledPixmap = originalPixmap.scaled(200, 200, Qt::KeepAspectRatio);
            ui->UserHead->setPixmap(scaledPixmap);
        }

}

void MainWindow::ChangePieColor()
{
        QString in=ui->comboBoxPieColor->currentText();
        if(in=="默认配色")
        {
            pies1->slices().at(0)->setColor(QColor(0,42,62));
            pies1->slices().at(1)->setColor(QColor(22,159,224));
        }
        else if(in=="蓝海橙天")
        {
            pies1->slices().at(0)->setColor(QColor(52, 152, 219));
            pies1->slices().at(1)->setColor(QColor(230, 126, 34));

        }
        else if(in=="绿意紫韵")
        {
            pies1->slices().at(0)->setColor(QColor(46, 204, 113));
            pies1->slices().at(1)->setColor(QColor(155, 89, 182));
        }
        else if(in=="粉绿梦影")
        {
            pies1->slices().at(0)->setColor(QColor(233, 30, 99));
            pies1->slices().at(1)->setColor(QColor(46, 204, 113));
        }
        else if(in=="红蓝和鸣")
        {
            pies1->slices().at(0)->setColor(QColor(231, 76, 60));
            pies1->slices().at(1)->setColor(QColor(52, 152, 219));

        }
        else if(in=="橙紫晚霞")
        {
            pies1->slices().at(0)->setColor(QColor(230, 126, 34));
            pies1->slices().at(1)->setColor(QColor(155, 89, 182));
        }


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
    //ui->Welcome->setLayout(ui->verticalLayout_7);
    ui->UserHead->setPixmap(QPixmap(":/res/UserHead.png"));
    ui->UserHead->resize(200,200);

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

    QString get=GiveMeOne();
    ui->Words->setText(get);
    connect(ui->btnChange,SIGNAL(clicked(bool)),this,SLOT(ChangeOne()));
//    ui->LuckyPig->setPixmap(QPixmap(":/res/LuckPig.jpg"));
//    ui->LuckyPig->resize(QSize(150,125));

//    QPixmap originalPixmap(":/res/LuckPig.jpg");
//    QPixmap scaledPixmap = originalPixmap.scaled(500, 300, Qt::KeepAspectRatio);
//    ui->LuckyPig->setPixmap(scaledPixmap);
    //上面是被放弃的幸运小猪图片
    QMovie *movie = new QMovie(":/res/LuckyPig.gif");
    // 将 QMovie 对象设置给 QLabel
    ui->label->setMovie(movie);
    // 播放动画
    movie->start();
    ui->label->show();

    //连接信号和槽
    connect(ui->Quit,SIGNAL(clicked(bool)),this,SLOT(close()));
    qDebug() << "获取当前页面的索引: " << ui->stackedWidget->currentIndex();
    connect(ui->Add,SIGNAL(clicked(bool)),this,SLOT(switchPage()));
    connect(ui->Display,SIGNAL(clicked(bool)),this,SLOT(switchPage()));
    connect(ui->Settings,SIGNAL(clicked(bool)),this,SLOT(switchPage()));
    connect(ui->Statistics,SIGNAL(clicked(bool)),this,SLOT(switchPage()));

//页面1：Add Page
    QDateTime Today =QDateTime::currentDateTime();
    QString today =Today.toString("yyyy/MM/dd");
    qDebug()<<"today is: "<<today;
    ui->stackedWidget->setStyleSheet("background-color:white");

    //对于Lcd的设置
    Timer=new QTimer(this);
    ui->Lcd->display("UUUUF:O");
    ui->TodayTime->setText("今天日期：\tToday\t"+today);//让最上面的标签显示当前日期
    ui-> Lcd->setStyleSheet("QLCDNumber{background-color:white;color:black}");
    ui->Lcd->setFixedSize(200, 50);

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

    ui->comboBoxKind->setVisible(false);
    //支出种类平时也不显示
    ui->dateEdit->setVisible(false);
    //dateEdit的默认状态为false，当勾选其他日期时，才会显示

    connect(ui->btnChoose,SIGNAL(toggled(bool)),this,SLOT(CalendarVisiable()));
    connect(ui->rbtnOut,SIGNAL(toggled(bool)),this,SLOT(KindVisiable()));
    //connect(radioButton, SIGNAL(toggled(bool)), this, SLOT(slotRadioButtonToggled(bool)));
    //设置只能输入数字
    ui->lineEditNum->setValidator(new QIntValidator(1, 65535));
    //设置背景提示字符
    ui->lineEditNum->setPlaceholderText(QString("只允许输入数字"));
    ui->lineEditNote->setPlaceholderText(QString("请输入备注"));

    connect(ui->btnSave,SIGNAL(clicked(bool)),this,SLOT(Save()));


//页面2：Display/Show Page
    ui->numericSpinBox->setMinimum(0);
    ui->numericSpinBox->setMaximum(0);

    connect(ui->Display,SIGNAL(clicked(bool)),this,SLOT(Table()));

    connect(ui->btnDelete,SIGNAL(clicked(bool)),this,SLOT(Delete()));

    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(Clear()));
    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(TableClear()));
    connect(ui->btnClear,SIGNAL(clicked(bool)),this,SLOT(Table()));

    ui->tableWidget->setColumnWidth(0,150);//设置列宽
    ui->tableWidget->setColumnWidth(1, 100);//设置列宽
    ui->tableWidget->setColumnWidth(2, 100);//设置列宽
    ui->tableWidget->setColumnWidth(3, 250);//设置列宽
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->comboBoxShowKind,SIGNAL(currentTextChanged(QString)),this,SLOT(ChangeArrange()));

    connect(ui->Display,SIGNAL(clicked(bool)),this,SLOT(Table()));

//页面3：Statistics Page
    connect(ui->comboBoxPieColor,SIGNAL(currentTextChanged(QString)),this,SLOT(ChangePieColor()));
    connect(ui->Statistics,SIGNAL(clicked(bool)),this,SLOT(ShowPie1()));
    connect(ui->Statistics,SIGNAL(clicked(bool)),this,SLOT(ShowPie2()));
    connect(ui->ToSpline,SIGNAL(clicked(bool)),this,SLOT(ShowSpline()));
    connect(ui->ToKind,SIGNAL(clicked(bool)),this,SLOT(ShowKind()));


//页面4：Setting Page
    connect(ui->comboBoxColor,SIGNAL(currentTextChanged(QString)),this,SLOT(ChangeColor()));
    connect(ui->comboBoxUser,SIGNAL(currentTextChanged(QString)),this,SLOT(ChangeUserHead()));
}


MainWindow::~MainWindow()
{
delete ui;
}



