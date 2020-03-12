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
    QSqlDatabase base = QSqlDatabase::addDatabase("QODBC");
    base.setHostName("127.0.0.1");
    base.setUserName("root");
    base.setPassword("");
    base.setDatabaseName("projet_local");
    base.setPort(3308);
    bool etat_co = base.open();
    if (etat_co== true){
        QMessageBox::information(this, "Connexion réussie", "La connexion à la base de données est réussie.");
        ui->co_bdd->setText("Connexion valide");
    }
    else {
        QMessageBox::critical(this, "Connexion échouée", base.lastError().text());
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
