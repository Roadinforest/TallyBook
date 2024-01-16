#include "enterconfirm.h"
#include "ui_enterconfirm.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        EnterConfirm w;
        w.show();

    return a.exec();
}
