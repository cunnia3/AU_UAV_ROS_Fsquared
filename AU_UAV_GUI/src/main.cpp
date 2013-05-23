/***************************************************
 Coder: Jacob Dalton Conaway - jdc0019@auburn.edu
 Reviewer/Tester: Kayla Casteel - klc0025@auburn.edu
 Senior Design - Spring 2013
 Sources are in-line
 ***************************************************/

#include <QtGui/QApplication>
#include "AU_UAV_GUI/mainwindow.hpp"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    MainWindow w(argc, argv);

    w.show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));

    return a.exec();
}
