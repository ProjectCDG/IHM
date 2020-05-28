#include "menupage.h"
#include "ui_menupage.h"
#include <QFile>
#include <QDebug>

menupage::menupage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menupage)
{
    ui->setupUi(this);
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
}

menupage::~menupage()
{
    delete ui;
}

void menupage::on_butSuivant_clicked()
{
    emit changePage("welcome");
}

void menupage::on_butMesurer_clicked()
{
    emit changePage("welcome");
}

void menupage::on_butCalibrer_clicked()
{
    emit changePage("calibrer");
}

void menupage::on_butDeco_clicked()
{
     emit changePage("login");
}

void menupage::on_butHisto_clicked()
{
    QString fichier("C:/Users/frederic/Documents/monfichier.txt");
    QFile file(fichier); // Appel du constructeur de la classe QFile
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Error opening files!" << endl;
    }

    QByteArray filedata = file.readAll();
    qDebug() << filedata;
    ui->labHisto->setText(filedata);

    if(filedata.contains("piece"))
    {

    }



}
