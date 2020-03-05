#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QStackedWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    stack = ui->mainStack;
//    ui->centralwidget = stack;
//    stack->show();



//    welcome = new welcomePage(this);
//    welcome->setObjectName("welcome");
    ui->mainStack->addWidget(&welcome);
//    login = new loginPage(this); // inutile
//    login->setObjectName("login");
    ui->mainStack->addWidget(&login);
    ui->mainStack->addWidget(&calibrer);
    ui->mainStack->setCurrentWidget(&login);
    connect(&login,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&welcome,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));

                // emeteur                                  // recepteur
}

void MainWindow::changePage(QString value){
    qDebug() << "Slot change page";
    if(value == "welcome"){
        ui->mainStack->setCurrentWidget(&welcome);
    }
    else if(value == "login"){
        ui->mainStack->setCurrentWidget(&login);
    }
    else if(value == "calibrer"){
        ui->mainStack->setCurrentWidget(&calibrer);
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}



