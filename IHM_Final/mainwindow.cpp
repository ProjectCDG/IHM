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
    setWindowIcon(QIcon("logoblack.svg"));
    setWindowTitle("Mesurer le centre de gravité");
    ui->mainStack->addWidget(&welcome);
    ui->mainStack->addWidget(&login);
    ui->mainStack->addWidget(&calibrer);
    ui->mainStack->addWidget(&mesurer);
    ui->mainStack->addWidget(&sauvegarder);
    ui->mainStack->addWidget(&parametre);
    ui->mainStack->setCurrentWidget(&sauvegarder);   //Page d'ouverture !!
    connect(&login,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&welcome,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&calibrer,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&mesurer,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&sauvegarder,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
    connect(&parametre,SIGNAL(changePage(QString)),this,SLOT(changePage(QString)));
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
    else if(value == "parametre"){
        ui->mainStack->setCurrentWidget(&parametre);
    }

}

Ui::MainWindow * MainWindow::getMainUi()
{
    return ui;
}


MainWindow::~MainWindow()
{
    delete ui;
}






