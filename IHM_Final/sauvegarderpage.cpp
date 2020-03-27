#include "sauvegarderpage.h"
#include "ui_sauvegarderpage.h"
#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include <QStackedWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"

sauvegarderpage::sauvegarderpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sauvegarderpage)
{
    ui->setupUi(this);
    ui->labLogo->setPixmap(QPixmap("logo.svg"));

    ui->xLcd->hide();
    ui->yLcd->hide();
    ui->zLcd->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->labX->hide();
    ui->labY->hide();
    ui->labZ->hide();
    ui->butSave->setEnabled(false);

}

sauvegarderpage::~sauvegarderpage()
{
    delete ui;
}

void sauvegarderpage::on_butSave_clicked()
{
    QMessageBox msgBox;

    if(ui->nomPiece->text() == "")
    {

        msgBox.critical(this, "Erreur", "<FONT COLOR='#ffffff'>Veuillez renseignez un nom pour la pièce</FONT>");
        // msgBox.exec();
    }
    else
    {
        msgBox.information(this, "Succés", "<FONT COLOR='#ffffff'>Votre pièce a été sauvegarder au nom de : " + piece + "</FONT>");
        ui->nomPiece->setText("");
        ui->xLcd->hide();
        ui->yLcd->hide();
        ui->zLcd->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->labX->hide();
        ui->labY->hide();
        ui->labZ->hide();

        QString xString = QString::number(x);
        QString yString = QString::number(y);
        QString zString = QString::number(z);

        QString fichier = "C:/Users/frederic/Documents/monfichier.txt";
        QFile file(fichier); // Appel du constructeur de la classe QFile
        if (file.open(QIODevice::Text | QIODevice::ReadWrite))
        {
            file.readAll();
            file.write("Nom de la piece : " + piece.toUtf8() + "\n");
            file.write("Coord x: " + xString.toUtf8() + "\n");
            file.write("Coord y: " + yString.toUtf8() + "\n");
            file.write("Coord z: " + zString.toUtf8() + "\n" + "    \n");
            file.close();
        }


        emit changePage("login");
    }
}

void sauvegarderpage::on_nomPiece_textEdited(const QString &arg1)
{
    piece = arg1;
}

void sauvegarderpage::on_butDeco_clicked()
{
    QMessageBox msgBox;
    int decoVerif = msgBox.critical(this, "Avertissement", "<FONT COLOR='#ffffff'>Êtes vous sur de vouloir vous deconnecter ? Vous risquer de perdre votre mesure</FONT>", "Oui","Non");
    if (decoVerif == msgBox.result())
    {
        ui->xLcd->hide();
        ui->yLcd->hide();
        ui->zLcd->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->labX->hide();
        ui->labY->hide();
        ui->labZ->hide();
        ui->nomPiece->setText("");
        emit changePage("login");
    }
}



void sauvegarderpage::on_affichValeur_clicked()
{
    ui->xLcd->show();
    ui->yLcd->show();
    ui->zLcd->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->labX->show();
    ui->labY->show();
    ui->labZ->show();
    ui->butSave->setEnabled(true);
    extern MainWindow * pw;
    mesurerpage * pMesure = (mesurerpage *)pw->getMainUi()->mainStack->widget(3);
    x = pMesure->envoieCoordX();
    y = pMesure->envoieCoordY();
    z = pMesure->envoieCoordZ();
    // x = -887;
    // y = 450;
    // z = -574;
    ui->xLcd->display(x);
    ui->yLcd->display(y);
    ui->zLcd->display(z);

}
