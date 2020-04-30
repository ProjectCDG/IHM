#ifndef FENETRE_H
#define FENETRE_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>


namespace Ui {
class fenetre;
}

class fenetre : public QDialog
{
    Q_OBJECT

public:
    explicit fenetre(QWidget *parent = nullptr);
    ~fenetre();

private slots:
    void on_butSql_clicked();
    void on_butLire_clicked();

private:
    Ui::fenetre *ui;
    QSqlDatabase base;
};

#endif // FENETRE_H
