#include "welcomepage.h"
#include "ui_welcomepage.h"
#include <QMessageBox>
#include "ui_loginpage.h"

welcomePage::welcomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcomePage)
{
    ui->setupUi(this);

    ui->deroulPiece->addItem("Test");
    ui->deroulPiece->addItem("Oui");
    ui->deroulPiece->addItem("bverub");
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
}

welcomePage::~welcomePage()
{
    delete ui;
}

void welcomePage::on_butDeco_clicked()
{
    QMessageBox msgBox;
    msgBox.critical(this, "Deconnexion", "<FONT COLOR='#ffffff'>Deconnexion</FONT>", "Ok");
    emit changePage("login");

}

void welcomePage::on_butSuivant_clicked()
{
    emit changePage("calibrer");
}
