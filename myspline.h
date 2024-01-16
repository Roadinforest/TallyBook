#ifndef MYSPLINE_H
#define MYSPLINE_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QSplineSeries>
//一周内账单变化趋势折线图类的头文件

namespace Ui {
class MySpline;
}

class MySpline : public QWidget
{
    Q_OBJECT

public:
    explicit MySpline(QWidget *parent = nullptr);
    ~MySpline();

private:
    Ui::MySpline *ui;
    QChart *mChart;//图表类（包含折线图）
};

#endif // MYSPLINE_H
