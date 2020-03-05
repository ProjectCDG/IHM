#include "mesurerpage.h"
#include "ui_mesurerpage.h"
#include <QLabel>
#include <QMovie>

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
}

mesurerpage::~mesurerpage()
{
    delete ui;
}

void mesurerpage::on_pushButton_clicked()
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

   /* if(ui->xLcd->value() != 3 && ui->yLcd->value() != -2 && ui->zLcd->value() !=13 )
    {
        movie->stop();
    }*/
}
void mesurerpage::centreDeGravite()
{

}
