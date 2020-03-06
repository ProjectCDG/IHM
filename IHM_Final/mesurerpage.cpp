#include "mesurerpage.h"
#include "ui_mesurerpage.h"
#include <QLabel>
#include <QMovie>
#include <QMessageBox>
mesurerpage::mesurerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mesurerpage)
{
    ui->setupUi(this);
    ui->labX->hide();
    ui->labY->hide();
    ui->labZ->hide();
    ui->xLcd->hide();
    ui->yLcd->hide();
    ui->zLcd->hide();
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
}

mesurerpage::~mesurerpage()
{
    delete ui;
}

void mesurerpage::on_butMesure_clicked()
{
    QMovie *movie = new QMovie("giphy.gif");
    ui->labGif->setMovie(movie);
    movie->start();
    ui->labX->show();
    ui->labY->show();
    ui->labZ->show();
    ui->xLcd->show();
    ui->yLcd->show();
    ui->zLcd->show();
    ui->butMesure->setEnabled(false);
    centreDeGravite();

}
void mesurerpage::centreDeGravite()
{
    /*int test = 0;
    while(test != 1)
    {
        ui->xLcd->display(3);
        ui->yLcd->display(-2);
        ui->zLcd->display(13);
        if(ui->xLcd->value() != 3 && ui->yLcd->value() != -2 && ui->zLcd->value() !=13 )
        {
            test = 1;
        }

    }*/


}

void mesurerpage::on_butSuivant_clicked()
{
    emit changePage("sauvegarder");
}

void mesurerpage::on_butDeco_clicked()
{
    QMessageBox msgBox;
   int decoVerif = msgBox.critical(this, "Avertissement", "<FONT COLOR='#ffffff'>Êtes vous sur de vouloir vous deconnecter ? Vous risquer de perdre votre mesure</FONT>", "Oui","Non");
    if (decoVerif == msgBox.result())
    {
        emit changePage("login");
    }


}
