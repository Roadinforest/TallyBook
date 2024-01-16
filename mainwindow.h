
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLCDNumber>
#include <QMenu>
#include <QtCharts>
#include <QChartView>
//主要界面类头文件

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *Timer;//计时器
    QPieSeries *pies1;//指代统计界面上方的饼状图对象
    QPieSeries *pies2;//指代统计界面下方的饼状图对象

public slots:
    void switchPage();//切换页面
    void ClockChange();//时间改变
    void CalendarVisiable();//小日历的可见与否
    void KindVisiable();//支出种类是否可见
    QString GiveMeOne();//返回一条名句
    void ChangeOne();//更改名句
    void Save();//存储数据
    void Delete();//删除一条数据
    void Clear();//将数据全部清除
    void Table();//将表格显示
    void Table_arranged();//将表格排好序输出
    void ChangeArrange();//改变表格显示顺序
    void TableClear();//清空表格
    void ShowPie1();//展示饼状图(支出收入)
    void ShowPie2();//展示饼状图(支出分类)
    void ShowSpline();//展示曲线图的窗口
    void ShowKind();//展示支出分类图
    void ChangeColor();//改变背景底色
    void ChangeUserHead();//改变头像
    void ChangePieColor();//改变饼状图配色


};
#endif // MAINWINDOW_H
