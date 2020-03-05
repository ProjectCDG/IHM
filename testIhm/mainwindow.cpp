#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginpage.h"
#include <QLabel>
#include <QStackedWidget>
#include <QDebug>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    ui->mainStack->addWidget(&welcome);



}


mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::changerDePage(QString value)
{

}

