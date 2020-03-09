#include "parametrepage.h"
#include "ui_parametrepage.h"
#include <QMessageBox>

parametrepage::parametrepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parametrepage)
{
    ui->setupUi(this);
    ui->ip->setEnabled(false);
    ui->masque->setEnabled(false);
    ui->passerelle->setEnabled(false);
    ui->ip->setStyleSheet("color: gray");
    ui->passerelle->setStyleSheet("color: gray");
    ui->masque->setStyleSheet("color: gray");
    ui->labPass->setStyleSheet("color: gray");
    ui->labAddIp->setStyleSheet("color: gray");
    ui->labPass2->setStyleSheet("color: gray");
    ui->labMasque->setStyleSheet("color: gray");
}

parametrepage::~parametrepage()
{
    delete ui;
}

void parametrepage::on_rbutIpAuto_clicked()
{
    ui->ip->setEnabled(false);
    ui->masque->setEnabled(false);
    ui->passerelle->setEnabled(false);
    ui->ip->setStyleSheet("color: gray");
    ui->passerelle->setStyleSheet("color: gray");
    ui->masque->setStyleSheet("color: gray");
    ui->labPass->setStyleSheet("color: gray");
    ui->labAddIp->setStyleSheet("color: gray");
    ui->labPass2->setStyleSheet("color: gray");
    ui->labMasque->setStyleSheet("color: gray");

}

void parametrepage::on_rbutIpMan_clicked()
{
    ui->ip->setEnabled(true);
    ui->masque->setEnabled(true);
    ui->passerelle->setEnabled(true);
    ui->ip->setStyleSheet("color: white");
    ui->passerelle->setStyleSheet("color: white");
    ui->masque->setStyleSheet("color: white");
    ui->labPass->setStyleSheet("color: white");
    ui->labAddIp->setStyleSheet("color: white");
    ui->labPass2->setStyleSheet("color: white");
    ui->labMasque->setStyleSheet("color: white");

}

void parametrepage::on_butValide_clicked()
{
    QMessageBox msgBox;
    if(ui->rbutIpMan->isChecked() && (ui->ip->text().isEmpty() || ui->masque->text().isEmpty() || ui->passerelle->text().isEmpty()) )
    {
        msgBox.information(this, "Erreur", "<FONT COLOR='#ffffff'>Veuillez renseignez remplir les cases </FONT>");
    }
    else
    {
        msgBox.information(this, "Succés", "<FONT COLOR='#ffffff'>Vos réglages ont bien été sauvegarder </FONT>");
        emit changePage("login");
    }
}

void parametrepage::on_butAnnule_clicked()
{
    QMessageBox msgBox;
    int decoVerif = msgBox.critical(this, "Avertissement", "<FONT COLOR='#ffffff'>Êtes vous sur de vouloir vous deconnecter ? Aucuns réglage ne sera sauvegardé</FONT>", "Oui","Non");
    if (decoVerif == msgBox.result())
    {
        emit changePage("login");
    }

}
