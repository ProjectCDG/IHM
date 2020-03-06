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
    setWindowIcon(QIcon("logoblack.svg"));
    setWindowTitle("Mesurer le centre de gravité");


    //    welcome = new welcomePage(this);
    //    welcome->setObjectName("welcome");
    //    login = new loginPage(this); // inutile
    //    login->setObjectName("login");

    ui->mainStack->addWidget(&welcome);
    ui->mainStack->addWidget(&login);
    ui->mainStack->addWidget(&calibrer);
    ui->mainStack->addWidget(&mesurer);
    ui->mainStack->addWidget(&sauvegarder);
    ui->mainStack->setCurrentWidget(&login);   //Page d'ouverture !!
    connect(&login,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&welcome,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&calibrer,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&mesurer,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&sauvegarder,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    // emeteur                                  // recepteur
}

void MainWindow::changePage(QString value){
    qDebug() << "Changement de page";
    if(value == "welcome"){
        ui->mainStack->setCurrentWidget(&welcome);
    }
    else if(value == "login"){
        ui->mainStack->setCurrentWidget(&login);
    }
    else if(value == "calibrer"){
        ui->mainStack->setCurrentWidget(&calibrer);
    }
    else if(value == "mesurer"){
        ui->mainStack->setCurrentWidget(&mesurer);
    }
    else if(value == "sauvegarder"){
        ui->mainStack->setCurrentWidget(&sauvegarder);
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}



