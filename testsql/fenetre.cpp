#include "fenetre.h"
#include "ui_fenetre.h"
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

fenetre::fenetre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fenetre)
{
    ui->setupUi(this);
}

fenetre::~fenetre()
{
    delete ui;
}

void fenetre::on_butSql_clicked()
{
    QSqlDatabase base = QSqlDatabase::addDatabase("QMYSQL", "BDD1");
    base.setHostName("localhost");
    base.setUserName("root");
    base.setPassword("");
    base.setDatabaseName("projet_local");
    base.setPort(3306);
    bool etat_co = base.open();
    if (etat_co== true){
        QMessageBox::information(this, "Connexion", "La connexion à la base de données est réussie.");
        ui->co_bdd->setText("Connexion valide");
    }
    else {
        QMessageBox::critical(this, "Connexion", "La connexion à la base de données est un échec.");
        ui->co_bdd->setText("Connexion non valide");
    }
}

void fenetre::on_butLire_clicked()
{
    QSqlQuery query ("SELECT * FROM `mesure`");

    if (query.exec() && query.first()){
        ui->select_bdd->setText(query.value(0).toString());
    }
    else {
        QString();
    }

}
