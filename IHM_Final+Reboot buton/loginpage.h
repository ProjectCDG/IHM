#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

namespace Ui {
class loginPage;
}

class loginPage : public QDialog
{
    Q_OBJECT

public:
    explicit loginPage(QWidget *parent = nullptr);
    ~loginPage();
    QString getUser();

private slots:
    void on_okButton_clicked();
    void on_butParam_clicked();
	
	void on_butReboot_clicked();

 signals:
    void changePage(QString value);

private:
    Ui::loginPage *ui;
    QString user;
    void baseDeDonne();

};

#endif // LOGINPAGE_H
