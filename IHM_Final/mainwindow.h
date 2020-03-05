#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "welcomepage.h"
#include "loginpage.h"
#include "calibrerpage.h"
#include "mesurerpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void changePage(QString value);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stack;
    welcomePage welcome; //composition
    loginPage login;
    calibrerpage calibrer;
    mesurerpage mesurer;

};
#endif // MAINWINDOW_H
