#include "sauvegarderpage.h"
#include "ui_sauvegarderpage.h"
#include "loginpage.h"
#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include <QStackedWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>



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


    QString fichier = "/home/pi/Desktop/ici/Ihm-EnDev/monfichier.txt";
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

    //baseDeDonne();

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
    ui->xLcd->display(x);
    ui->yLcd->display(y);
    ui->zLcd->display(z);
    xString = QString::number(x);
    yString = QString::number(y);
    zString = QString::number(z);

    welcomePage * pWelcome = (welcomePage *)pw->getMainUi()->mainStack->widget(0);
    piece = pWelcome->getPiece();
    ui->labNomPiece->setText(piece);

    loginPage * pLogin = (loginPage *)pw->getMainUi()->mainStack->widget(1);
    nomUser = pLogin->getUser();
    qDebug() << nomUser;



}

void sauvegarderpage::baseDeDonne()
{

    QSqlDatabase base = QSqlDatabase::addDatabase("QMYSQL");
    base.setHostName("labatcave.fr");    // On entre l’adresse IP de la base de données
    base.setUserName("bconstant");           // On entre l’identifiant de connexion
    base.setPassword("8@Nr1k2e");    // On entre le mot de passe
    base.setDatabaseName("db_erems");     // On entre le nom de la base de données à laquelle on veut se connecter
    bool etat_co = base.open();         // Ce booléen retourne True si la connexion est faite, False si elle n’est pas opérationnelle
    if (etat_co== true){                // Cette boucle teste si la connection est bonne, dans ce cas elle affiche que la connexion a été bien faite, dans le cas contraire elle indique que non avec une erreur.
        qDebug() << "Ca marche la co bdd";
        QSqlQuery envoieMesure;
        envoieMesure.exec("INSERT INTO mesure (iden_raspberry, iden_piece, cdgmesurer, axe_x, axe_y, axe_z, username) VALUES ('idenrasperry1', '" + piece + "', 0, '" + xString + "', '" + yString + "', '" + zString + "', '" + nomUser + "');");
        base.close();
    }

    else {
                                        // base.lastError().text() retourne l’erreur de connexion
        QMessageBox::critical(this, "Connexion échouée", base.lastError().text());
        qDebug() << "Ca marche pas";
    }
}
