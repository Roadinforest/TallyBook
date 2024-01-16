/********************************************************************************
** Form generated from reading UI file 'kindchart.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KINDCHART_H
#define UI_KINDCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kindchart
{
public:
    QPushButton *QuitKind;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *kindchart)
    {
        if (kindchart->objectName().isEmpty())
            kindchart->setObjectName("kindchart");
        kindchart->resize(400, 300);
        QuitKind = new QPushButton(kindchart);
        QuitKind->setObjectName("QuitKind");
        QuitKind->setGeometry(QRect(300, 260, 80, 24));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font.setPointSize(15);
        font.setBold(true);
        QuitKind->setFont(font);
        horizontalLayoutWidget = new QWidget(kindchart);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(50, 30, 291, 191));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(kindchart);

        QMetaObject::connectSlotsByName(kindchart);
    } // setupUi

    void retranslateUi(QWidget *kindchart)
    {
        kindchart->setWindowTitle(QCoreApplication::translate("kindchart", "Form", nullptr));
        QuitKind->setText(QCoreApplication::translate("kindchart", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class kindchart: public Ui_kindchart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KINDCHART_H
