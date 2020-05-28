#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>
#include "welcomepage.h"
#include <QCryptographicHash>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QtSql>
#include <QCoreApplication>

loginPage::loginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPage)
{
    ui->setupUi(this);
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_okButton_clicked()
{
  //  baseDeDonne();
    //@TODO
    if(ui->userName->text() == "Axel" && ui->password->text() == "password")
    {
        user = ui->userName->text();
        ui->userName->setText("");
        ui->password->setText("");
       emit changePage("menu");
    }
    else {
        QMessageBox msgBox;
        msgBox.critical(this, "Erreur", "<FONT COLOR='#ffffff'>Mauvaise combinaison !</FONT>", "Ok");
        ui->password->setText("");
    }

}

void loginPage::on_butParam_clicked()
{
    ui->userName->setText("");
    ui->password->setText("");
    emit changePage("parametre");
}

QString loginPage::getUser()
{
    return user;
}


void loginPage::baseDeDonne()
{
    QSqlDatabase base = QSqlDatabase::addDatabase("QMYSQL");
    base.setHostName("labatcave.fr");    // On entre l’adresse IP de la base de données
    base.setUserName("bconstant");           // On entre l’identifiant de connexion
    base.setPassword("8@Nr1k2e");    // On entre le mot de passe
    base.setDatabaseName("db_erems");     // On entre le nom de la base de données à laquelle on veut se connecter
    bool etat_co = base.open();         // Ce booléen retourne True si la connexion est faite, False si elle n’est pas opérationnelle
    if (etat_co== true){                // Cette boucle teste si la connection est bonne, dans ce cas elle affiche que la connexion a été bien faite, dans le cas contraire elle indique que non avec une erreur.
        qDebug() << "Ca marche la co bdd";
        QSqlQuery recepDonne;
        recepDonne.exec("SELECT username FROM 'utilisateur';");
        while (recepDonne.next()) {
            QString name = recepDonne.value(0).toString();
            qDebug() << name; }

        base.close();
    }
    else {                                        // base.lastError().text() retourne l’erreur de connexion
        QMessageBox::critical(this, "Connexion échouée", base.lastError().text());
        qDebug() << "Ca marche pas";
    }
}
