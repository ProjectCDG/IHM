#include "sauvegarderpage.h"
#include "ui_sauvegarderpage.h"
#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include <QStackedWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QCoreApplication>
#include <QSqlDatabase>



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
    ui->labNomPiece->hide();
    ui->labPiece->hide();
    ui->butSave->setEnabled(false);


}

sauvegarderpage::~sauvegarderpage()
{
    delete ui;
}

void sauvegarderpage::on_butSave_clicked()
{
    QMessageBox msgBox;

    msgBox.information(this, "Succés", "<FONT COLOR='#ffffff'>Votre pièce a été sauvegarder au nom de : " + piece + "</FONT>");
    ui->xLcd->hide();
    ui->yLcd->hide();
    ui->zLcd->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->labX->hide();
    ui->labY->hide();
    ui->labZ->hide();
    ui->labNomPiece->hide();
    ui->labPiece->hide();

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

    ui->butSave->setEnabled(false);
    emit changePage("login");

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
    ui->labNomPiece->show();
    ui->labPiece->show();
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

    welcomePage * pWelcome = (welcomePage *)pw->getMainUi()->mainStack->widget(0);
    piece = pWelcome->getPiece();
    ui->labNomPiece->setText(piece);


    baseDeDonne();


}

void sauvegarderpage::baseDeDonne()
{

    QSqlDatabase base = QSqlDatabase::addDatabase("QMYSQL");
  // On entre l’adresse IP de la base de données
     base.setHostName("5.9.170.254");
  // On entre l’identifiant de connexion
     base.setUserName("pcdg");
  // On entre le mot de passe
     base.setPassword("lescouzdu12");
  // On entre le nom de la base de données à laquelle on veut se connecter
     base.setDatabaseName("db_cdg");
  // Ce booléen retourne True si la connexion est faite, False si elle n’est pas opérationnelle
     bool etat_co = base.open();
  // Cette boucle teste si la connection est bonne, dans ce cas elle affiche que la connexion a été bien faite, dans le cas contraire elle indique que non avec une erreur.
     if (etat_co== true){
         QMessageBox::information(this, "Connexion réussie", "La connexion à la base de données est réussie.");
         qDebug() << "Ca marche";
     }
     else {
  // base.lastError().text() retourne l’erreur de connexion
         QMessageBox::critical(this, "Connexion échouée", base.lastError().text());
         qDebug() << "Ca marche pas";
     }


}
