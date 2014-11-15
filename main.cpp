#include "mainwindow.h"
#include <QtGui/QApplication>
//#include <QToolTip>
//#include <QEvent>

/*SMS_KULDO*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //a.eventFilter(w, QEvent::ToolTip);
    
    return a.exec();
}
