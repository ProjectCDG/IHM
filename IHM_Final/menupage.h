#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QDialog>

namespace Ui {
class menupage;
}

class menupage : public QDialog
{
    Q_OBJECT

public:
    explicit menupage(QWidget *parent = nullptr);
    ~menupage();

private slots:
    void on_butSuivant_clicked();

    void on_butMesurer_clicked();

    void on_butCalibrer_clicked();

    void on_butDeco_clicked();

    void on_butHisto_clicked();

signals:
    void changePage(QString value);

private:
    Ui::menupage *ui;
};

#endif // MENUPAGE_H
