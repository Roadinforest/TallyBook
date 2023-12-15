/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGridLayout *gridLayout_4;
    QLabel *Title;
    QGridLayout *ExtraGrid;
    QStackedWidget *stackedWidget;
    QWidget *PageShow;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *Notice;
    QTableWidget *tableWidget;
    QPushButton *btnClear;
    QWidget *PageSta;
    QWidget *Blank;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *Title_8;
    QLabel *PrintIn;
    QLabel *PrintOut;
    QLabel *PrintAll;
    QPushButton *ToSpline;
    QWidget *PageSet;
    QLabel *Title_3;
    QComboBox *comboBox;
    QLabel *Title_2;
    QWidget *Welcome;
    QLabel *Title_6;
    QWidget *PageAdd;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLabel *Title_10;
    QLineEdit *lineEditNote;
    QLabel *Title_9;
    QPushButton *btnSave;
    QLabel *Title_5;
    QLineEdit *lineEditNum;
    QLabel *Title_7;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout;
    QRadioButton *btnToday;
    QRadioButton *btnYesterday;
    QRadioButton *btnChoose;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbtnOut;
    QRadioButton *rbtnIn;
    QLabel *LuckyPig;
    QHBoxLayout *horizontalLayout_3;
    QLabel *TodayTime;
    QLCDNumber *Lcd;
    QVBoxLayout *MenuLayout;
    QLabel *UserHead;
    QLabel *UserName;
    QPushButton *Add;
    QPushButton *Display;
    QPushButton *Statistics;
    QPushButton *Settings;
    QPushButton *Quit;
    QVBoxLayout *verticalLayout_6;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(820, 535);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        gridLayout_4 = new QGridLayout(MainWindow);
        gridLayout_4->setObjectName("gridLayout_4");
        Title = new QLabel(MainWindow);
        Title->setObjectName("Title");
        QFont font;
        font.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        Title->setFont(font);
        Title->setStyleSheet(QString::fromUtf8("color:black;"));

        gridLayout_4->addWidget(Title, 0, 1, 1, 1);

        ExtraGrid = new QGridLayout();
        ExtraGrid->setObjectName("ExtraGrid");
        stackedWidget = new QStackedWidget(MainWindow);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:white\n"
"\n"
""));
        PageShow = new QWidget();
        PageShow->setObjectName("PageShow");
        verticalLayoutWidget = new QWidget(PageShow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 711, 491));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Notice = new QLabel(verticalLayoutWidget);
        Notice->setObjectName("Notice");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(true);
        Notice->setFont(font1);
        Notice->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_3->addWidget(Notice);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font2.setPointSize(16);
        font2.setBold(true);
        tableWidget->setFont(font2);
        tableWidget->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_3->addWidget(tableWidget);

        btnClear = new QPushButton(verticalLayoutWidget);
        btnClear->setObjectName("btnClear");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font3.setPointSize(14);
        font3.setBold(true);
        btnClear->setFont(font3);
        btnClear->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_3->addWidget(btnClear);

        stackedWidget->addWidget(PageShow);
        PageSta = new QWidget();
        PageSta->setObjectName("PageSta");
        Blank = new QWidget(PageSta);
        Blank->setObjectName("Blank");
        Blank->setGeometry(QRect(30, 10, 401, 331));
        verticalLayoutWidget_2 = new QWidget(PageSta);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(350, 80, 160, 156));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Title_8 = new QLabel(verticalLayoutWidget_2);
        Title_8->setObjectName("Title_8");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Brush Script MT")});
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setItalic(true);
        Title_8->setFont(font4);
        Title_8->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_2->addWidget(Title_8);

        PrintIn = new QLabel(verticalLayoutWidget_2);
        PrintIn->setObjectName("PrintIn");
        PrintIn->setFont(font4);
        PrintIn->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_2->addWidget(PrintIn);

        PrintOut = new QLabel(verticalLayoutWidget_2);
        PrintOut->setObjectName("PrintOut");
        PrintOut->setFont(font4);
        PrintOut->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_2->addWidget(PrintOut);

        PrintAll = new QLabel(verticalLayoutWidget_2);
        PrintAll->setObjectName("PrintAll");
        PrintAll->setFont(font4);
        PrintAll->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_2->addWidget(PrintAll);

        ToSpline = new QPushButton(PageSta);
        ToSpline->setObjectName("ToSpline");
        ToSpline->setGeometry(QRect(350, 290, 301, 27));
        ToSpline->setFont(font3);
        ToSpline->setStyleSheet(QString::fromUtf8("color:black"));
        stackedWidget->addWidget(PageSta);
        PageSet = new QWidget();
        PageSet->setObjectName("PageSet");
        PageSet->setStyleSheet(QString::fromUtf8("background:transparent"));
        Title_3 = new QLabel(PageSet);
        Title_3->setObjectName("Title_3");
        Title_3->setGeometry(QRect(10, 10, 121, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Brush Script MT")});
        font5.setPointSize(28);
        font5.setBold(true);
        font5.setItalic(true);
        Title_3->setFont(font5);
        Title_3->setStyleSheet(QString::fromUtf8("color:black"));
        comboBox = new QComboBox(PageSet);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(120, 90, 121, 31));
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));
        Title_2 = new QLabel(PageSet);
        Title_2->setObjectName("Title_2");
        Title_2->setGeometry(QRect(20, 80, 91, 46));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setItalic(true);
        Title_2->setFont(font6);
        Title_2->setStyleSheet(QString::fromUtf8("color:black"));
        stackedWidget->addWidget(PageSet);
        Welcome = new QWidget();
        Welcome->setObjectName("Welcome");
        Title_6 = new QLabel(Welcome);
        Title_6->setObjectName("Title_6");
        Title_6->setGeometry(QRect(80, 90, 371, 41));
        Title_6->setFont(font5);
        Title_6->setStyleSheet(QString::fromUtf8("color:black"));
        stackedWidget->addWidget(Welcome);
        PageAdd = new QWidget();
        PageAdd->setObjectName("PageAdd");
        PageAdd->setStyleSheet(QString::fromUtf8("background:transparent"));
        verticalLayoutWidget_3 = new QWidget(PageAdd);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(7, 73, 551, 401));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        Title_10 = new QLabel(verticalLayoutWidget_3);
        Title_10->setObjectName("Title_10");
        QFont font7;
        font7.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font7.setPointSize(16);
        font7.setBold(true);
        font7.setItalic(true);
        Title_10->setFont(font7);
        Title_10->setStyleSheet(QString::fromUtf8("color:black;\n"
""));

        gridLayout->addWidget(Title_10, 1, 0, 1, 1);

        lineEditNote = new QLineEdit(verticalLayoutWidget_3);
        lineEditNote->setObjectName("lineEditNote");
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Britannic Bold")});
        font8.setPointSize(12);
        lineEditNote->setFont(font8);
        lineEditNote->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(lineEditNote, 3, 1, 1, 1);

        Title_9 = new QLabel(verticalLayoutWidget_3);
        Title_9->setObjectName("Title_9");
        Title_9->setFont(font7);
        Title_9->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(Title_9, 3, 0, 1, 1);

        btnSave = new QPushButton(verticalLayoutWidget_3);
        btnSave->setObjectName("btnSave");
        QFont font9;
        font9.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font9.setPointSize(10);
        font9.setBold(true);
        btnSave->setFont(font9);
        btnSave->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(btnSave, 3, 2, 1, 1);

        Title_5 = new QLabel(verticalLayoutWidget_3);
        Title_5->setObjectName("Title_5");
        Title_5->setFont(font4);
        Title_5->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(Title_5, 0, 0, 1, 1);

        lineEditNum = new QLineEdit(verticalLayoutWidget_3);
        lineEditNum->setObjectName("lineEditNum");
        lineEditNum->setFont(font8);
        lineEditNum->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(lineEditNum, 1, 1, 1, 1);

        Title_7 = new QLabel(verticalLayoutWidget_3);
        Title_7->setObjectName("Title_7");
        Title_7->setFont(font7);
        Title_7->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(Title_7, 4, 0, 1, 1);

        dateEdit = new QDateEdit(verticalLayoutWidget_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(dateEdit, 4, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnToday = new QRadioButton(verticalLayoutWidget_3);
        btnToday->setObjectName("btnToday");
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Brush Script MT")});
        font10.setPointSize(16);
        font10.setItalic(true);
        btnToday->setFont(font10);
        btnToday->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout->addWidget(btnToday);

        btnYesterday = new QRadioButton(verticalLayoutWidget_3);
        btnYesterday->setObjectName("btnYesterday");
        btnYesterday->setFont(font10);
        btnYesterday->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout->addWidget(btnYesterday);

        btnChoose = new QRadioButton(verticalLayoutWidget_3);
        btnChoose->setObjectName("btnChoose");
        btnChoose->setFont(font10);
        btnChoose->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout->addWidget(btnChoose);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addLayout(verticalLayout, 1, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        frame = new QFrame(verticalLayoutWidget_3);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(90, 0, 351, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        rbtnOut = new QRadioButton(horizontalLayoutWidget);
        rbtnOut->setObjectName("rbtnOut");
        rbtnOut->setFont(font9);
        rbtnOut->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_2->addWidget(rbtnOut);

        rbtnIn = new QRadioButton(horizontalLayoutWidget);
        rbtnIn->setObjectName("rbtnIn");
        rbtnIn->setFont(font9);
        rbtnIn->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_2->addWidget(rbtnIn);


        verticalLayout_5->addWidget(frame);

        LuckyPig = new QLabel(verticalLayoutWidget_3);
        LuckyPig->setObjectName("LuckyPig");

        verticalLayout_5->addWidget(LuckyPig);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        TodayTime = new QLabel(verticalLayoutWidget_3);
        TodayTime->setObjectName("TodayTime");
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font11.setPointSize(16);
        font11.setBold(true);
        font11.setItalic(true);
        TodayTime->setFont(font11);
        TodayTime->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_3->addWidget(TodayTime);

        Lcd = new QLCDNumber(verticalLayoutWidget_3);
        Lcd->setObjectName("Lcd");

        horizontalLayout_3->addWidget(Lcd);


        verticalLayout_5->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(PageAdd);

        ExtraGrid->addWidget(stackedWidget, 1, 1, 1, 1);


        gridLayout_4->addLayout(ExtraGrid, 1, 1, 1, 1);

        MenuLayout = new QVBoxLayout();
        MenuLayout->setObjectName("MenuLayout");
        UserHead = new QLabel(MainWindow);
        UserHead->setObjectName("UserHead");
        UserHead->setStyleSheet(QString::fromUtf8("color:black"));

        MenuLayout->addWidget(UserHead);

        UserName = new QLabel(MainWindow);
        UserName->setObjectName("UserName");
        QFont font12;
        font12.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font12.setPointSize(15);
        font12.setBold(true);
        UserName->setFont(font12);

        MenuLayout->addWidget(UserName);

        Add = new QPushButton(MainWindow);
        Add->setObjectName("Add");
        QFont font13;
        font13.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font13.setPointSize(14);
        font13.setBold(false);
        font13.setItalic(false);
        Add->setFont(font13);
        Add->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        MenuLayout->addWidget(Add);

        Display = new QPushButton(MainWindow);
        Display->setObjectName("Display");
        QFont font14;
        font14.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font14.setPointSize(14);
        font14.setBold(false);
        Display->setFont(font14);
        Display->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        MenuLayout->addWidget(Display);

        Statistics = new QPushButton(MainWindow);
        Statistics->setObjectName("Statistics");
        Statistics->setFont(font14);
        Statistics->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;\n"
"\n"
""));

        MenuLayout->addWidget(Statistics);

        Settings = new QPushButton(MainWindow);
        Settings->setObjectName("Settings");
        Settings->setFont(font14);
        Settings->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;\n"
""));

        MenuLayout->addWidget(Settings);

        Quit = new QPushButton(MainWindow);
        Quit->setObjectName("Quit");
        Quit->setFont(font14);
        Quit->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        MenuLayout->addWidget(Quit);


        gridLayout_4->addLayout(MenuLayout, 1, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");

        gridLayout_4->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TallyBook", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "\350\256\260\350\264\246\346\234\254", nullptr));
        Notice->setText(QCoreApplication::translate("MainWindow", "\350\277\230\346\262\241\346\234\211\350\264\246\345\215\225\350\256\260\345\275\225\345\223\246\357\274\214\350\257\267\345\205\210\345\216\273\346\267\273\345\212\240\345\220\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\224\266\346\224\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\345\244\207\346\263\250", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        Title_8->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        PrintIn->setText(QCoreApplication::translate("MainWindow", "\346\224\266\345\205\245\357\274\232", nullptr));
        PrintOut->setText(QCoreApplication::translate("MainWindow", "\346\224\257\345\207\272\357\274\232", nullptr));
        PrintAll->setText(QCoreApplication::translate("MainWindow", "\346\200\273\350\256\241", nullptr));
        ToSpline->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\346\234\254\346\234\210\350\277\207\345\216\273\344\270\203\345\244\251\350\264\246\345\215\225\350\266\213\345\212\277", nullptr));
        Title_3->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\351\207\221\351\273\204", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\350\213\215\350\211\262", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\347\276\244\351\235\222", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\350\227\244\347\264\253", nullptr));

        Title_2->setText(QCoreApplication::translate("MainWindow", "\344\270\273\351\242\230\350\211\262", nullptr));
        Title_6->setText(QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        Title_10->setText(QCoreApplication::translate("MainWindow", "\351\207\221\351\242\235\357\274\232", nullptr));
        lineEditNote->setText(QString());
        Title_9->setText(QCoreApplication::translate("MainWindow", "\345\244\207\346\263\250\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        Title_5->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        lineEditNum->setText(QString());
        Title_7->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\264\246\345\215\225", nullptr));
        btnToday->setText(QCoreApplication::translate("MainWindow", "Today", nullptr));
        btnYesterday->setText(QCoreApplication::translate("MainWindow", "Yesterday", nullptr));
        btnChoose->setText(QCoreApplication::translate("MainWindow", "Choose a day", nullptr));
        rbtnOut->setText(QCoreApplication::translate("MainWindow", "\346\224\257\345\207\272", nullptr));
        rbtnIn->setText(QCoreApplication::translate("MainWindow", "\346\224\266\345\205\245", nullptr));
        LuckyPig->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        TodayTime->setText(QCoreApplication::translate("MainWindow", "Today Time", nullptr));
        UserHead->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        UserName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        Display->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272", nullptr));
        Statistics->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241", nullptr));
        Settings->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        Quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
