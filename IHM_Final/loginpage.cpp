#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>
#include "welcomepage.h"



loginPage::loginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPage)
{
    ui->setupUi(this);
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_okButton_clicked()
{
    //@TODO
    if(ui->userName->text() == "Axel" && ui->password->text() == "password")
    {
        ui->userName->setText("");
        ui->password->setText("");
       emit changePage("welcome");
    }
    else {
        QMessageBox msgBox;
        msgBox.critical(this, "Erreur", "<FONT COLOR='#ffffff'>Mauvaise combinaison !</FONT>", "Ok");
        ui->password->setText("");
    }

}

void loginPage::on_butParam_clicked()
{
    ui->userName->setText("");
    ui->password->setText("");
    emit changePage("parametre");
}
