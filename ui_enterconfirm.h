/********************************************************************************
** Form generated from reading UI file 'enterconfirm.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERCONFIRM_H
#define UI_ENTERCONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterConfirm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Title;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *getCode;
    QLabel *label_1;
    QLineEdit *getName;
    QLabel *label_2;
    QPushButton *btnConfirm;
    QPushButton *btnQuit;

    void setupUi(QWidget *EnterConfirm)
    {
        if (EnterConfirm->objectName().isEmpty())
            EnterConfirm->setObjectName("EnterConfirm");
        EnterConfirm->resize(400, 300);
        verticalLayoutWidget = new QWidget(EnterConfirm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 30, 301, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Title = new QLabel(verticalLayoutWidget);
        Title->setObjectName("Title");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        Title->setFont(font);

        verticalLayout->addWidget(Title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        getCode = new QLineEdit(verticalLayoutWidget);
        getCode->setObjectName("getCode");

        gridLayout->addWidget(getCode, 1, 1, 1, 1);

        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName("label_1");
        label_1->setFont(font);

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        getName = new QLineEdit(verticalLayoutWidget);
        getName->setObjectName("getName");

        gridLayout->addWidget(getName, 0, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        btnConfirm = new QPushButton(verticalLayoutWidget);
        btnConfirm->setObjectName("btnConfirm");
        btnConfirm->setFont(font);

        gridLayout->addWidget(btnConfirm, 2, 0, 1, 1);

        btnQuit = new QPushButton(verticalLayoutWidget);
        btnQuit->setObjectName("btnQuit");
        btnQuit->setFont(font);

        gridLayout->addWidget(btnQuit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(EnterConfirm);

        QMetaObject::connectSlotsByName(EnterConfirm);
    } // setupUi

    void retranslateUi(QWidget *EnterConfirm)
    {
        EnterConfirm->setWindowTitle(QCoreApplication::translate("EnterConfirm", "Form", nullptr));
        Title->setText(QCoreApplication::translate("EnterConfirm", "TextLabel", nullptr));
        label_1->setText(QCoreApplication::translate("EnterConfirm", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("EnterConfirm", "TextLabel", nullptr));
        btnConfirm->setText(QCoreApplication::translate("EnterConfirm", "PushButton", nullptr));
        btnQuit->setText(QCoreApplication::translate("EnterConfirm", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterConfirm: public Ui_EnterConfirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERCONFIRM_H
