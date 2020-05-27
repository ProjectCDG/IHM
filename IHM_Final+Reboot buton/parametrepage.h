#ifndef PARAMETREPAGE_H
#define PARAMETREPAGE_H

#include <QDialog>
#include "mesurerpage.h"

namespace Ui {
class parametrepage;
}

class parametrepage : public QDialog
{
    Q_OBJECT

public:
    explicit parametrepage(QWidget *parent = nullptr);
    ~parametrepage();

private:
    Ui::parametrepage *ui;
    QString currentIp;


signals:
    void changePage(QString value);


private slots:
    void on_rbutIpAuto_clicked();
    void on_rbutIpMan_clicked();
    void on_butValide_clicked();
    void on_butAnnule_clicked();
    void getParamAuto();
    void changerParam();
};

#endif // PARAMETREPAGE_H
