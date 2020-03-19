#include "fenetre.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fenetre f;
    f.show();
    return a.exec();

}
