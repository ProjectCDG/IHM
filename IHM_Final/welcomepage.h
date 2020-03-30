#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QDialog>
#include "loginpage.h"

namespace Ui {
class welcomePage;
}

class welcomePage : public QDialog
{
    Q_OBJECT

public:
    explicit welcomePage(QWidget *parent = nullptr);
    ~welcomePage();
    QString getPiece();
    QString nomPiece;

private slots:
    void on_butDeco_clicked();
    void on_butSuivant_clicked();

    void on_butSyncBdd_clicked();

    void on_butValPiece_clicked();

signals:
    void changePage(QString value);

private:
    Ui::welcomePage *ui;
};

#endif // WELCOMEPAGE_H
