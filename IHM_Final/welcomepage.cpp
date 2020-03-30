#include "welcomepage.h"
#include "ui_welcomepage.h"
#include <QMessageBox>
#include "ui_loginpage.h"
#include <QFile>
#include <QDebug>


welcomePage::welcomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcomePage)
{
    ui->setupUi(this);

    ui->deroulPiece->addItem("Test");
    ui->deroulPiece->addItem("Oui");
    ui->deroulPiece->addItem("bverub");
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
    ui->labPiece->hide();
    ui->butSuivant->setEnabled(false);
}

welcomePage::~welcomePage()
{
    delete ui;
}

void welcomePage::on_butDeco_clicked()
{
    QMessageBox msgBox;
    msgBox.critical(this, "Deconnexion", "<FONT COLOR='#ffffff'>Deconnexion</FONT>", "Ok");
    ui->butSuivant->setEnabled(false);
    emit changePage("login");

}

void welcomePage::on_butSuivant_clicked()
{
    ui->butSuivant->setEnabled(false);
    emit changePage("calibrer");
}

void welcomePage::on_butSyncBdd_clicked()
{/*
    QString fichier = "C:/Users/frederic/Documents/monfichier.txt";
    QFile file(fichier); // Appel du constructeur de la classe QFile
    if (file.open(QIODevice::Text | QIODevice::ReadOnly))
    {
    file.readAll();
    QTextStream in(&fichier);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          ui->deroulPiece->addItem(line);
       }

    }*/
    QFile file("C:/Users/frederic/Documents/monfichier.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        //qDebug() << line;
        const char preLettre[] = "N";
        const char deuLettre[] = "o";
        const char slashLettre[] = "*";   //18
        char nomPiece[20];
        if (line[0] == preLettre[0] && line[1] == deuLettre[0])
        {

        }


        qDebug() << "Syncro";
    }
}



QString welcomePage::getPiece()
{
    return nomPiece;
}


void welcomePage::on_butValPiece_clicked()
{
    ui->labPiece->setText(ui->deroulPiece->currentText());
    nomPiece = ui->labPiece->text();
    ui->butSuivant->setEnabled(true);
}
