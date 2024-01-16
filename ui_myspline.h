/********************************************************************************
** Form generated from reading UI file 'myspline.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSPLINE_H
#define UI_MYSPLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MySpline
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *QuitSpline;

    void setupUi(QWidget *MySpline)
    {
        if (MySpline->objectName().isEmpty())
            MySpline->setObjectName("MySpline");
        MySpline->resize(400, 300);
        horizontalLayoutWidget = new QWidget(MySpline);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(50, 40, 291, 191));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        QuitSpline = new QPushButton(MySpline);
        QuitSpline->setObjectName("QuitSpline");
        QuitSpline->setGeometry(QRect(280, 250, 80, 24));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font.setPointSize(15);
        font.setBold(true);
        QuitSpline->setFont(font);

        retranslateUi(MySpline);

        QMetaObject::connectSlotsByName(MySpline);
    } // setupUi

    void retranslateUi(QWidget *MySpline)
    {
        MySpline->setWindowTitle(QCoreApplication::translate("MySpline", "Form", nullptr));
        QuitSpline->setText(QCoreApplication::translate("MySpline", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MySpline: public Ui_MySpline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSPLINE_H
