#include "parametrepage.h"
#include "ui_parametrepage.h"
#include <QMessageBox>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkInterface>

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
    getParamAuto();
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
    getParamAuto();

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

void parametrepage::getParamAuto()
{
    QString localhostname =  QHostInfo::localHostName();
    QString localhostIP;
    QList<QHostAddress> hostList = QHostInfo::fromName(localhostname).addresses();
    foreach (const QHostAddress& address, hostList) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address.isLoopback() == false) {
            localhostIP = address.toString();
        }
    }
    QString localMacAddress;
    QString localNetmask;
    foreach (const QNetworkInterface& networkInterface, QNetworkInterface::allInterfaces()) {
        foreach (const QNetworkAddressEntry& entry, networkInterface.addressEntries()) {
            if (entry.ip().toString() == localhostIP) {
                localMacAddress = networkInterface.hardwareAddress();
                localNetmask = entry.netmask().toString();
                break;
            }
        }
    }
    qDebug() << "Localhost name: " << localhostname;
    qDebug() << "IP = " << localhostIP;
    qDebug() << "MAC = " << localMacAddress;
    qDebug() << "Netmask = " << localNetmask;
    ui->masque->setText(localNetmask);
    ui->ip->setText(localhostIP);
}
