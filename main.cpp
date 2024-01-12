#include <QApplication>

#include "termwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    TermWidget w;
    w.resize(640,240);
    w.show();
    
    return a.exec();
}
