#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "loginpage.h"
#include <QStackedWidget>
#include <QMainWindow>

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

public slots :
    void changerDePage(QString value);

private:
    Ui::mainWindow *ui;
    QStackedWidget *stackPage;
    loginPage login;

};

#endif // MAINWINDOW_H
