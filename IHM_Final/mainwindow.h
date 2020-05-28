#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "welcomepage.h"
#include "loginpage.h"
#include "calibrerpage.h"
#include "mesurerpage.h"
#include "sauvegarderpage.h"
#include "parametrepage.h"
#include "menupage.h"
#include <QProgressDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow * getMainUi();


public slots:
    void changePage(QString value);


private:
    Ui::MainWindow *ui;
    QStackedWidget *stack;
    welcomePage welcome; //composition
    loginPage login;
    calibrerpage calibrer;
    mesurerpage mesurer;
    sauvegarderpage sauvegarder;
    parametrepage parametre;
    menupage menu;

};
#endif // MAINWINDOW_H
