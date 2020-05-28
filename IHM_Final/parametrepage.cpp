#include "parametrepage.h"
#include "ui_parametrepage.h"
#include <QMessageBox>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkInterface>
#include <QFile>
/*
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <net/route.h>
#include <arpa/inet.h>*/

parametrepage::parametrepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parametrepage)
{
    ui->setupUi(this);
    ui->ip->setEnabled(false);
    ui->masque->setEnabled(false);
    ui->ip->setStyleSheet("color: gray");
    ui->masque->setStyleSheet("color: gray");
    ui->labAddIp->setStyleSheet("color: gray");
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
    ui->ip->setStyleSheet("color: gray");
    ui->masque->setStyleSheet("color: gray");
    ui->labAddIp->setStyleSheet("color: gray");
    ui->labMasque->setStyleSheet("color: gray");
    getParamAuto();

}

void parametrepage::on_rbutIpMan_clicked()
{
    ui->ip->setEnabled(true);
    ui->masque->setEnabled(true);
    ui->ip->setStyleSheet("color: white");
    ui->masque->setStyleSheet("color: white");
    ui->labAddIp->setStyleSheet("color: white");
    ui->labMasque->setStyleSheet("color: white");

}

void parametrepage::on_butValide_clicked()
{
    QMessageBox msgBox;
    if(ui->rbutIpMan->isChecked() && (ui->ip->text().isEmpty() || ui->masque->text().isEmpty()))
    {
        msgBox.information(this, "Erreur", "<FONT COLOR='#ffffff'>Veuillez renseignez remplir les cases </FONT>");
    }
    else
    {
        changerParam();
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

    // Sous Windows.
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
    currentIp = localhostIP;
    qDebug() << "MAC = " << localMacAddress;
    qDebug() << "Netmask = " << localNetmask;
    ui->masque->setText(localNetmask);
    ui->ip->setText(localhostIP);




    //SUR LINUX
    /*
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
        for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
            if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
            {
                qDebug() << address.toString();
                ui->ip->setText(address.toString());
            }
        }

        int fd;
        struct ifreq ifr;
        QString mask;
        fd = socket(AF_INET, SOCK_DGRAM, 0);
         I want an IPv4 netmask
        ifr.ifr_addr.sa_family = AF_INET;
         I want netmask attached to "eth0"
        strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);
        ioctl(fd, SIOCGIFNETMASK, &ifr);
         display result
        mask = ("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
        qDebug() << mask;
        ui->masque->setText(mask);
        */
}


void parametrepage::changerParam()
{

    QString a;
    QString b;

   // cout << "nouvelle ip ? " << endl;                   //demande nouvell ip en x.x.x.x
    a = ui->ip->text();
    qDebug () << a;
    QString strReplace = "static ip_address=" + a;       //ligne qui doit etre modifier ( ligne de base )


    b = ui->masque->text();                  //demande nouveau mask en x
    qDebug() << b;
                                     //suprime les 20 caracteres aprés le 18 eme ( dans notre cas apres le = )
    QString strNew = strReplace + "/" + b ;                         //creation d'un nouveau string qui associe strReplaceNew et l'IP que l'utilisateur a entrer


    qDebug() << "strReplace : " << strReplace << endl;                 //affiche  la ligne qui doit etre modifier ( ligne de base : static ip_address=192.168.1.145/24)           //affiche  la ligne apres la suppression de l'IP (static ip_address=)
    qDebug() << "strNew : " << strNew << endl;                          //affiche  la ligne qui doit remplacer l'acien ( ligne de base : static ip_address=x.x.x.x/x )
    qDebug() << "ip de base : " << currentIp << endl;

    QFile filein("/etc/dhcpcd.conf");
    if(!filein.open(QIODevice::ReadWrite))
    {
        qDebug() << "Error opening files!" << endl;
    }

    QByteArray filedata;
    filedata = filein.readAll();
    QString text(filedata);
    text.replace(QString(currentIp), QString(a));
    filein.seek(0);
    filein.write(text.toUtf8());
    filein.close();


   /* while(getline(filein,strTemp))
    {
        if(strTemp == strReplace){
            strTemp = strNew;
            //found = true;
        }
        strTemp += "\n";
        fileout << strTemp;
        //if(found) break;
    }

      if( remove( "dhcpcd.conf" ) != 0 )
    perror( "Error deleting file" );

    else
    puts( "File successfully deleted" );


    if (rename("newdhcpcd.conf", "dhcpcd.conf")!=0)
        perror( "Error deleting file" );
  else
    puts( "File successfully renamed" );*/

}
