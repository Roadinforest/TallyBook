#ifndef KINDCHART_H
#define KINDCHART_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QSplineSeries>
//一周内账单变化趋势柱状图类的头文件

namespace Ui {
class kindchart;
}

class kindchart : public QWidget
{
    Q_OBJECT

public:
    explicit kindchart(QWidget *parent = nullptr);
    ~kindchart();

private:
    Ui::kindchart *ui;
    QChart *mChart;
};

#endif // KINDCHART_H
