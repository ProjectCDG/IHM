#include "sauvegarderpage.h"
#include "ui_sauvegarderpage.h"
#include <QMessageBox>

sauvegarderpage::sauvegarderpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sauvegarderpage)
{
    ui->setupUi(this);
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
}

sauvegarderpage::~sauvegarderpage()
{
    delete ui;
}

void sauvegarderpage::on_butSave_clicked()
{
    QMessageBox msgBox;

    if(ui->nomPiece->text() == "")
    {

        msgBox.critical(this, "Erreur", "<FONT COLOR='#ffffff'>Veuillez renseignez un nom pour la pièce</FONT>");
        // msgBox.exec();
    }
    else
    {
        msgBox.information(this, "Succés", "<FONT COLOR='#ffffff'>Votre pièce a été sauvegarder au nom de : " + piece + "</FONT>");
        ui->nomPiece->setText("");
        emit changePage("login");
    }
}

void sauvegarderpage::on_nomPiece_textEdited(const QString &arg1)
{
    piece = arg1;
}

void sauvegarderpage::on_butDeco_clicked()
{
    QMessageBox msgBox;
   int decoVerif = msgBox.critical(this, "Avertissement", "<FONT COLOR='#ffffff'>Êtes vous sur de vouloir vous deconnecter ? Vous risquer de perdre votre mesure</FONT>", "Oui","Non");
    if (decoVerif == msgBox.result())
    {
        ui->nomPiece->setText("");
        emit changePage("login");
    }
}
