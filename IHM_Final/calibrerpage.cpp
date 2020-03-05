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
