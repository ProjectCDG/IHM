#include "calibrerpage.h"
#include "ui_calibrerpage.h"
#include <QMessageBox>

calibrerpage::calibrerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calibrerpage)
{
    ui->setupUi(this);
    ui->butTarCon->hide();
    ui->butTarVide->hide();
    ui->butSuivant->hide();
    ui->labLogo->setPixmap(QPixmap("logo.svg"));

}

calibrerpage::~calibrerpage()
{
    delete ui;
}

void calibrerpage::on_butYPlus_clicked()
{
    YTemp= YTemp+pas;
    ui->yLcd->display(YTemp);

}

void calibrerpage::on_butYMoin_clicked()
{
    YTemp= YTemp-pas;
    ui->yLcd->display(YTemp);
}

void calibrerpage::on_butXPlus_clicked()
{
    XTemp= XTemp+pas;
    ui->xLcd->display(XTemp);
}

void calibrerpage::on_butXMoin_clicked()
{
    XTemp= XTemp-pas;
    ui->xLcd->display(XTemp);
}

void calibrerpage::on_butZPlus_clicked()
{
    ZTemp= ZTemp+pas;
    ui->zLcd->display(ZTemp);
}

void calibrerpage::on_butZMoin_clicked()
{
    ZTemp= ZTemp-pas;
    ui->zLcd->display(ZTemp);
}

void calibrerpage::on_butDeco_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Deconnexion !");
    msgBox.exec();
    emit changePage("login");
}

void calibrerpage::on_butSuivant_clicked()
{
    emit changePage("mesurer");
}

void calibrerpage::on_butValidPalpeur_clicked()
{
    ui->butTarCon->show();
    ui->butPas1->setEnabled(false);
    ui->butPas10->setEnabled(false);
    ui->butPas100->setEnabled(false);
    ui->butXMoin->setEnabled(false);
    ui->butXPlus->setEnabled(false);
    ui->butYMoin->setEnabled(false);
    ui->butYPlus->setEnabled(false);
    ui->butZMoin->setEnabled(false);
    ui->butZPlus->setEnabled(false);

}

void calibrerpage::on_butTarVide_clicked()
{
    ui->butSuivant->show();

}

void calibrerpage::on_butTarCon_clicked()
{
    ui->butTarVide->show();
}

void calibrerpage::on_butPas1_clicked()
{
    pas = 1;
    ui->pasLcd->display(1);
}

void calibrerpage::on_butPas10_clicked()
{
    pas = 10;
    ui->pasLcd->display(10);
}

void calibrerpage::on_butPas100_clicked()
{
    pas = 100;
    ui->pasLcd->display(100);
}
