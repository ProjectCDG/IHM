#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
MainWindow * pw;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pw = new MainWindow;
    pw->show();
    return a.exec();

}
