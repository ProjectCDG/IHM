#include "testsylvain.h"
#include "ui_testsylvain.h"

testSylvain::testSylvain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testSylvain)
{
    ui->setupUi(this);
}

testSylvain::~testSylvain()
{
    delete ui;
}

void testSylvain::on_valider_clicked()
{
    ui->monLabel->text("test");

}
