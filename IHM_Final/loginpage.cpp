#include "loginpage.h"
#include "ui_loginpage.h"
#include <QMessageBox>

loginPage::loginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPage)
{
    ui->setupUi(this);
    ui->userName->setText("");
    ui->password->setText("");
}

loginPage::~loginPage()
{
    delete ui;
}

void loginPage::on_okButton_clicked()
{
    //@TODO
    if(ui->userName->text() == "Axel" && ui->password->text() == "password"){
       emit changePage("welcome");
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Retry.");
        msgBox.exec();
    }

}
