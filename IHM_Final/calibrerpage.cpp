#include "calibrerpage.h"
#include "ui_calibrerpage.h"

calibrerpage::calibrerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calibrerpage)
{
    ui->setupUi(this);
}

calibrerpage::~calibrerpage()
{
    delete ui;
}

void calibrerpage::on_butYPlus_clicked()
{
    YTemp= YTemp+1;
    ui->yLcd->display(YTemp);

}

void calibrerpage::on_butYMoin_clicked()
{
    YTemp= YTemp-1;
    ui->yLcd->display(YTemp);
}

void calibrerpage::on_butXPlus_clicked()
{
    XTemp= XTemp+1;
    ui->xLcd->display(XTemp);
}

void calibrerpage::on_butXMoin_clicked()
{
    XTemp= XTemp-1;
    ui->xLcd->display(XTemp);
}

void calibrerpage::on_butZPlus_clicked()
{
    ZTemp= ZTemp+1;
    ui->zLcd->display(ZTemp);
}

void calibrerpage::on_butZMoin_clicked()
{
    ZTemp= ZTemp-1;
    ui->zLcd->display(ZTemp);
}
