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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBoxShowKind;
    QPushButton *btnClear;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *numericSpinBox;
    QPushButton *btnDelete;
    QWidget *PageSta;
    QWidget *Blank;
    QWidget *Blank_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *PrintClothes;
    QLabel *PrintFood;
    QLabel *PrintHousing;
    QLabel *PrintTransports;
    QLabel *PrintOthers;
    QPushButton *ToKind;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *Title_8;
    QLabel *PrintIn;
    QLabel *PrintOut;
    QLabel *PrintAll;
    QPushButton *ToSpline;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Title_11;
    QComboBox *comboBoxPieColor;
    QWidget *PageSet;
    QLabel *Title_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxColor;
    QLabel *Title_2;
    QLabel *Title_4;
    QComboBox *comboBoxUser;
    QWidget *Welcome;
    QLabel *Title_6;
    QLabel *label;
    QWidget *PageAdd;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLabel *Title_5;
    QLabel *Title_10;
    QDateEdit *dateEdit;
    QLabel *Title_9;
    QPushButton *btnSave;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBoxKind;
    QLabel *Title_7;
    QHBoxLayout *horizontalLayout;
    QRadioButton *btnToday;
    QRadioButton *btnYesterday;
    QRadioButton *btnChoose;
    QLineEdit *lineEditNote;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditNum;
    QRadioButton *rbtnOut;
    QRadioButton *rbtnIn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Words;
    QPushButton *btnChange;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *TodayTime;
    QLCDNumber *Lcd;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *MenuLayout;
    QLabel *UserHead;
    QLabel *UserName;
    QPushButton *Add;
    QPushButton *Display;
    QPushButton *Statistics;
    QPushButton *Settings;
    QPushButton *Quit;

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

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        comboBoxShowKind = new QComboBox(verticalLayoutWidget);
        comboBoxShowKind->addItem(QString());
        comboBoxShowKind->addItem(QString());
        comboBoxShowKind->setObjectName("comboBoxShowKind");
        comboBoxShowKind->setFont(font2);
        comboBoxShowKind->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));

        horizontalLayout_7->addWidget(comboBoxShowKind);

        btnClear = new QPushButton(verticalLayoutWidget);
        btnClear->setObjectName("btnClear");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font3.setPointSize(14);
        font3.setBold(true);
        btnClear->setFont(font3);
        btnClear->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_7->addWidget(btnClear);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        numericSpinBox = new QSpinBox(verticalLayoutWidget);
        numericSpinBox->setObjectName("numericSpinBox");

        horizontalLayout_9->addWidget(numericSpinBox);

        btnDelete = new QPushButton(verticalLayoutWidget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setFont(font3);
        btnDelete->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_9->addWidget(btnDelete);


        verticalLayout_3->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(PageShow);
        PageSta = new QWidget();
        PageSta->setObjectName("PageSta");
        Blank = new QWidget(PageSta);
        Blank->setObjectName("Blank");
        Blank->setGeometry(QRect(30, 10, 371, 281));
        Blank_2 = new QWidget(PageSta);
        Blank_2->setObjectName("Blank_2");
        Blank_2->setGeometry(QRect(20, 310, 381, 291));
        verticalLayoutWidget_4 = new QWidget(PageSta);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(430, 310, 271, 281));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        PrintClothes = new QLabel(verticalLayoutWidget_4);
        PrintClothes->setObjectName("PrintClothes");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(false);
        PrintClothes->setFont(font4);
        PrintClothes->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_4->addWidget(PrintClothes);

        PrintFood = new QLabel(verticalLayoutWidget_4);
        PrintFood->setObjectName("PrintFood");
        PrintFood->setFont(font4);
        PrintFood->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_4->addWidget(PrintFood);

        PrintHousing = new QLabel(verticalLayoutWidget_4);
        PrintHousing->setObjectName("PrintHousing");
        PrintHousing->setFont(font4);
        PrintHousing->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_4->addWidget(PrintHousing);

        PrintTransports = new QLabel(verticalLayoutWidget_4);
        PrintTransports->setObjectName("PrintTransports");
        PrintTransports->setFont(font4);
        PrintTransports->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_4->addWidget(PrintTransports);

        PrintOthers = new QLabel(verticalLayoutWidget_4);
        PrintOthers->setObjectName("PrintOthers");
        PrintOthers->setFont(font4);
        PrintOthers->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_4->addWidget(PrintOthers);

        ToKind = new QPushButton(verticalLayoutWidget_4);
        ToKind->setObjectName("ToKind");
        ToKind->setFont(font3);
        ToKind->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_4->addWidget(ToKind);

        verticalLayoutWidget_2 = new QWidget(PageSta);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(430, 20, 261, 281));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Title_8 = new QLabel(verticalLayoutWidget_2);
        Title_8->setObjectName("Title_8");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Brush Script MT")});
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setItalic(true);
        Title_8->setFont(font5);
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

        ToSpline = new QPushButton(verticalLayoutWidget_2);
        ToSpline->setObjectName("ToSpline");
        ToSpline->setFont(font3);
        ToSpline->setStyleSheet(QString::fromUtf8("color:black"));

        verticalLayout_2->addWidget(ToSpline);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        Title_11 = new QLabel(verticalLayoutWidget_2);
        Title_11->setObjectName("Title_11");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setItalic(true);
        Title_11->setFont(font6);
        Title_11->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_4->addWidget(Title_11);

        comboBoxPieColor = new QComboBox(verticalLayoutWidget_2);
        comboBoxPieColor->addItem(QString());
        comboBoxPieColor->addItem(QString());
        comboBoxPieColor->addItem(QString());
        comboBoxPieColor->addItem(QString());
        comboBoxPieColor->addItem(QString());
        comboBoxPieColor->addItem(QString());
        comboBoxPieColor->setObjectName("comboBoxPieColor");
        comboBoxPieColor->setFont(font2);
        comboBoxPieColor->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));

        horizontalLayout_4->addWidget(comboBoxPieColor);


        verticalLayout_2->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(PageSta);
        PageSet = new QWidget();
        PageSet->setObjectName("PageSet");
        PageSet->setStyleSheet(QString::fromUtf8("background:transparent"));
        Title_3 = new QLabel(PageSet);
        Title_3->setObjectName("Title_3");
        Title_3->setGeometry(QRect(10, 10, 121, 41));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Brush Script MT")});
        font7.setPointSize(28);
        font7.setBold(true);
        font7.setItalic(true);
        Title_3->setFont(font7);
        Title_3->setStyleSheet(QString::fromUtf8("color:black"));
        gridLayoutWidget = new QWidget(PageSet);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 70, 291, 151));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBoxColor = new QComboBox(gridLayoutWidget);
        comboBoxColor->addItem(QString());
        comboBoxColor->addItem(QString());
        comboBoxColor->addItem(QString());
        comboBoxColor->addItem(QString());
        comboBoxColor->addItem(QString());
        comboBoxColor->setObjectName("comboBoxColor");
        comboBoxColor->setFont(font2);
        comboBoxColor->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));

        gridLayout_2->addWidget(comboBoxColor, 0, 1, 1, 1);

        Title_2 = new QLabel(gridLayoutWidget);
        Title_2->setObjectName("Title_2");
        Title_2->setFont(font6);
        Title_2->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout_2->addWidget(Title_2, 0, 0, 1, 1);

        Title_4 = new QLabel(gridLayoutWidget);
        Title_4->setObjectName("Title_4");
        Title_4->setFont(font6);
        Title_4->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout_2->addWidget(Title_4, 1, 0, 1, 1);

        comboBoxUser = new QComboBox(gridLayoutWidget);
        comboBoxUser->addItem(QString());
        comboBoxUser->addItem(QString());
        comboBoxUser->addItem(QString());
        comboBoxUser->addItem(QString());
        comboBoxUser->addItem(QString());
        comboBoxUser->addItem(QString());
        comboBoxUser->addItem(QString());
        comboBoxUser->setObjectName("comboBoxUser");
        comboBoxUser->setFont(font2);
        comboBoxUser->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));

        gridLayout_2->addWidget(comboBoxUser, 1, 1, 1, 1);

        stackedWidget->addWidget(PageSet);
        Welcome = new QWidget();
        Welcome->setObjectName("Welcome");
        Title_6 = new QLabel(Welcome);
        Title_6->setObjectName("Title_6");
        Title_6->setGeometry(QRect(0, 10, 231, 41));
        Title_6->setFont(font7);
        Title_6->setStyleSheet(QString::fromUtf8("color:black"));
        label = new QLabel(Welcome);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 511, 421));
        stackedWidget->addWidget(Welcome);
        PageAdd = new QWidget();
        PageAdd->setObjectName("PageAdd");
        PageAdd->setStyleSheet(QString::fromUtf8("background:transparent"));
        verticalLayoutWidget_3 = new QWidget(PageAdd);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(20, 70, 571, 301));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        Title_5 = new QLabel(verticalLayoutWidget_3);
        Title_5->setObjectName("Title_5");
        Title_5->setFont(font5);
        Title_5->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(Title_5, 0, 0, 1, 1);

        Title_10 = new QLabel(verticalLayoutWidget_3);
        Title_10->setObjectName("Title_10");
        Title_10->setFont(font4);
        Title_10->setStyleSheet(QString::fromUtf8("color:black;\n"
""));

        gridLayout->addWidget(Title_10, 1, 0, 1, 1);

        dateEdit = new QDateEdit(verticalLayoutWidget_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(dateEdit, 4, 2, 1, 1);

        Title_9 = new QLabel(verticalLayoutWidget_3);
        Title_9->setObjectName("Title_9");
        Title_9->setFont(font4);
        Title_9->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(Title_9, 3, 0, 1, 1);

        btnSave = new QPushButton(verticalLayoutWidget_3);
        btnSave->setObjectName("btnSave");
        btnSave->setFont(font2);
        btnSave->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(btnSave, 3, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        comboBoxKind = new QComboBox(verticalLayoutWidget_3);
        comboBoxKind->addItem(QString());
        comboBoxKind->addItem(QString());
        comboBoxKind->addItem(QString());
        comboBoxKind->addItem(QString());
        comboBoxKind->addItem(QString());
        comboBoxKind->setObjectName("comboBoxKind");
        comboBoxKind->setFont(font2);
        comboBoxKind->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color:white;"));

        verticalLayout->addWidget(comboBoxKind);


        gridLayout->addLayout(verticalLayout, 1, 2, 1, 1);

        Title_7 = new QLabel(verticalLayoutWidget_3);
        Title_7->setObjectName("Title_7");
        Title_7->setFont(font4);
        Title_7->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(Title_7, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnToday = new QRadioButton(verticalLayoutWidget_3);
        btnToday->setObjectName("btnToday");
        btnToday->setFont(font4);
        btnToday->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout->addWidget(btnToday);

        btnYesterday = new QRadioButton(verticalLayoutWidget_3);
        btnYesterday->setObjectName("btnYesterday");
        btnYesterday->setFont(font4);
        btnYesterday->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout->addWidget(btnYesterday);

        btnChoose = new QRadioButton(verticalLayoutWidget_3);
        btnChoose->setObjectName("btnChoose");
        btnChoose->setFont(font4);
        btnChoose->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout->addWidget(btnChoose);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);

        lineEditNote = new QLineEdit(verticalLayoutWidget_3);
        lineEditNote->setObjectName("lineEditNote");
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Britannic Bold")});
        font8.setPointSize(12);
        lineEditNote->setFont(font8);
        lineEditNote->setStyleSheet(QString::fromUtf8("color:black"));

        gridLayout->addWidget(lineEditNote, 3, 1, 1, 1);

        frame = new QFrame(verticalLayoutWidget_3);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, -4, 371, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditNum = new QLineEdit(horizontalLayoutWidget);
        lineEditNum->setObjectName("lineEditNum");
        lineEditNum->setFont(font8);
        lineEditNum->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_2->addWidget(lineEditNum);

        rbtnOut = new QRadioButton(horizontalLayoutWidget);
        rbtnOut->setObjectName("rbtnOut");
        QFont font9;
        font9.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font9.setPointSize(10);
        font9.setBold(true);
        rbtnOut->setFont(font9);
        rbtnOut->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_2->addWidget(rbtnOut);

        rbtnIn = new QRadioButton(horizontalLayoutWidget);
        rbtnIn->setObjectName("rbtnIn");
        rbtnIn->setFont(font9);
        rbtnIn->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_2->addWidget(rbtnIn);


        gridLayout->addWidget(frame, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        Words = new QLabel(verticalLayoutWidget_3);
        Words->setObjectName("Words");
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Papyrus")});
        font10.setPointSize(13);
        font10.setBold(true);
        Words->setFont(font10);

        horizontalLayout_5->addWidget(Words);

        btnChange = new QPushButton(verticalLayoutWidget_3);
        btnChange->setObjectName("btnChange");
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Papyrus")});
        font11.setPointSize(14);
        font11.setBold(false);
        btnChange->setFont(font11);
        btnChange->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_5->addWidget(btnChange);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        TodayTime = new QLabel(verticalLayoutWidget_3);
        TodayTime->setObjectName("TodayTime");
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font12.setPointSize(16);
        font12.setBold(true);
        font12.setItalic(true);
        TodayTime->setFont(font12);
        TodayTime->setStyleSheet(QString::fromUtf8("color:black"));

        horizontalLayout_3->addWidget(TodayTime);

        Lcd = new QLCDNumber(verticalLayoutWidget_3);
        Lcd->setObjectName("Lcd");

        horizontalLayout_3->addWidget(Lcd);


        verticalLayout_5->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(PageAdd);

        ExtraGrid->addWidget(stackedWidget, 1, 1, 1, 1);


        gridLayout_4->addLayout(ExtraGrid, 1, 1, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");

        gridLayout_4->addLayout(verticalLayout_6, 0, 0, 1, 1);

        MenuLayout = new QVBoxLayout();
        MenuLayout->setObjectName("MenuLayout");
        UserHead = new QLabel(MainWindow);
        UserHead->setObjectName("UserHead");
        UserHead->setStyleSheet(QString::fromUtf8("color:black"));

        MenuLayout->addWidget(UserHead);

        UserName = new QLabel(MainWindow);
        UserName->setObjectName("UserName");
        QFont font13;
        font13.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font13.setPointSize(15);
        font13.setBold(true);
        UserName->setFont(font13);

        MenuLayout->addWidget(UserName);

        Add = new QPushButton(MainWindow);
        Add->setObjectName("Add");
        QFont font14;
        font14.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font14.setPointSize(14);
        font14.setBold(false);
        font14.setItalic(false);
        Add->setFont(font14);
        Add->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        MenuLayout->addWidget(Add);

        Display = new QPushButton(MainWindow);
        Display->setObjectName("Display");
        QFont font15;
        font15.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font15.setPointSize(14);
        font15.setBold(false);
        Display->setFont(font15);
        Display->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        MenuLayout->addWidget(Display);

        Statistics = new QPushButton(MainWindow);
        Statistics->setObjectName("Statistics");
        Statistics->setFont(font15);
        Statistics->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;\n"
"\n"
""));

        MenuLayout->addWidget(Statistics);

        Settings = new QPushButton(MainWindow);
        Settings->setObjectName("Settings");
        Settings->setFont(font15);
        Settings->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;\n"
""));

        MenuLayout->addWidget(Settings);

        Quit = new QPushButton(MainWindow);
        Quit->setObjectName("Quit");
        Quit->setFont(font15);
        Quit->setStyleSheet(QString::fromUtf8("color:black;\n"
"background:transparent;"));

        MenuLayout->addWidget(Quit);


        gridLayout_4->addLayout(MenuLayout, 1, 0, 1, 1);


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
        comboBoxShowKind->setItemText(0, QCoreApplication::translate("MainWindow", "\346\214\211\350\276\223\345\205\245\346\227\266\351\227\264\346\216\222\345\272\217", nullptr));
        comboBoxShowKind->setItemText(1, QCoreApplication::translate("MainWindow", "\346\214\211\350\264\246\345\215\225\346\227\245\346\234\237\346\216\222\345\272\217", nullptr));

        btnClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244\345\210\240\351\231\244", nullptr));
        PrintClothes->setText(QCoreApplication::translate("MainWindow", "\350\241\243\357\274\232", nullptr));
        PrintFood->setText(QCoreApplication::translate("MainWindow", "\351\243\237\357\274\232", nullptr));
        PrintHousing->setText(QCoreApplication::translate("MainWindow", "\344\275\217\357\274\232", nullptr));
        PrintTransports->setText(QCoreApplication::translate("MainWindow", "\350\241\214\357\274\232", nullptr));
        PrintOthers->setText(QCoreApplication::translate("MainWindow", "\345\205\266\344\273\226\357\274\232", nullptr));
        ToKind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\350\277\207\345\216\273\344\270\203\345\244\251\346\224\257\345\207\272\345\210\206\351\205\215", nullptr));
        Title_8->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        PrintIn->setText(QCoreApplication::translate("MainWindow", "\346\224\266\345\205\245\357\274\232", nullptr));
        PrintOut->setText(QCoreApplication::translate("MainWindow", "\346\224\257\345\207\272\357\274\232", nullptr));
        PrintAll->setText(QCoreApplication::translate("MainWindow", "\346\200\273\350\256\241", nullptr));
        ToSpline->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\350\277\207\345\216\273\344\270\203\345\244\251\350\264\246\345\215\225\350\266\213\345\212\277", nullptr));
        Title_11->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\205\215\350\211\262", nullptr));
        comboBoxPieColor->setItemText(0, QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244\351\205\215\350\211\262", nullptr));
        comboBoxPieColor->setItemText(1, QCoreApplication::translate("MainWindow", "\350\223\235\346\265\267\346\251\231\345\244\251", nullptr));
        comboBoxPieColor->setItemText(2, QCoreApplication::translate("MainWindow", "\347\273\277\346\204\217\347\264\253\351\237\265", nullptr));
        comboBoxPieColor->setItemText(3, QCoreApplication::translate("MainWindow", "\347\262\211\347\273\277\346\242\246\345\275\261", nullptr));
        comboBoxPieColor->setItemText(4, QCoreApplication::translate("MainWindow", "\346\251\231\347\264\253\346\231\232\351\234\236", nullptr));
        comboBoxPieColor->setItemText(5, QCoreApplication::translate("MainWindow", "\347\272\242\350\223\235\345\222\214\351\270\243", nullptr));

        Title_3->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        comboBoxColor->setItemText(0, QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244", nullptr));
        comboBoxColor->setItemText(1, QCoreApplication::translate("MainWindow", "\351\207\221\351\273\204", nullptr));
        comboBoxColor->setItemText(2, QCoreApplication::translate("MainWindow", "\350\215\211\347\273\277", nullptr));
        comboBoxColor->setItemText(3, QCoreApplication::translate("MainWindow", "\346\271\226\350\223\235", nullptr));
        comboBoxColor->setItemText(4, QCoreApplication::translate("MainWindow", "\350\227\244\347\264\253", nullptr));

        Title_2->setText(QCoreApplication::translate("MainWindow", "\344\270\273\351\242\230\350\211\262", nullptr));
        Title_4->setText(QCoreApplication::translate("MainWindow", "\345\244\264\345\203\217", nullptr));
        comboBoxUser->setItemText(0, QCoreApplication::translate("MainWindow", "\351\273\230\350\256\244", nullptr));
        comboBoxUser->setItemText(1, QCoreApplication::translate("MainWindow", "Baby1", nullptr));
        comboBoxUser->setItemText(2, QCoreApplication::translate("MainWindow", "Baby2", nullptr));
        comboBoxUser->setItemText(3, QCoreApplication::translate("MainWindow", "Baby3", nullptr));
        comboBoxUser->setItemText(4, QCoreApplication::translate("MainWindow", "Baby4", nullptr));
        comboBoxUser->setItemText(5, QCoreApplication::translate("MainWindow", "CuteBoy", nullptr));
        comboBoxUser->setItemText(6, QCoreApplication::translate("MainWindow", "CuteGirl", nullptr));

        Title_6->setText(QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Title_5->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Title_10->setText(QCoreApplication::translate("MainWindow", "\351\207\221\351\242\235\357\274\232", nullptr));
        Title_9->setText(QCoreApplication::translate("MainWindow", "\345\244\207\346\263\250\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        comboBoxKind->setItemText(0, QCoreApplication::translate("MainWindow", "\345\205\266\344\273\226\346\224\257\345\207\272", nullptr));
        comboBoxKind->setItemText(1, QCoreApplication::translate("MainWindow", "\350\241\243", nullptr));
        comboBoxKind->setItemText(2, QCoreApplication::translate("MainWindow", "\351\243\237", nullptr));
        comboBoxKind->setItemText(3, QCoreApplication::translate("MainWindow", "\344\275\217", nullptr));
        comboBoxKind->setItemText(4, QCoreApplication::translate("MainWindow", "\350\241\214", nullptr));

        Title_7->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\264\246\345\215\225", nullptr));
        btnToday->setText(QCoreApplication::translate("MainWindow", "\344\273\212\345\244\251", nullptr));
        btnYesterday->setText(QCoreApplication::translate("MainWindow", "\346\230\250\345\244\251", nullptr));
        btnChoose->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\217\246\345\244\226\346\227\245\346\234\237", nullptr));
        lineEditNote->setText(QString());
        lineEditNum->setText(QString());
        rbtnOut->setText(QCoreApplication::translate("MainWindow", "\346\224\257\345\207\272", nullptr));
        rbtnIn->setText(QCoreApplication::translate("MainWindow", "\346\224\266\345\205\245", nullptr));
        Words->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnChange->setText(QCoreApplication::translate("MainWindow", "Give me another one", nullptr));
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
