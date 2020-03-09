#ifndef CALIBRERPAGE_H
#define CALIBRERPAGE_H

#include <QDialog>

namespace Ui {
class calibrerpage;
}

class calibrerpage : public QDialog
{
    Q_OBJECT

public:
    explicit calibrerpage(QWidget *parent = nullptr);
    ~calibrerpage();

private slots:
    void on_butYPlus_clicked();

    void on_butXPlus_clicked();

    void on_butYMoin_clicked();

    void on_butXMoin_clicked();

    void on_butZPlus_clicked();

    void on_butZMoin_clicked();

    void on_butDeco_clicked();

    void on_butSuivant_clicked();

    void on_butValidPalpeur_clicked();

    void on_butTarVide_clicked();

    void on_butTarCon_clicked();

    void on_butPas1_clicked();

    void on_butPas10_clicked();

    void on_butPas100_clicked();

signals:
   void changePage(QString value);

private:
    Ui::calibrerpage *ui;
    int YTemp = 0;
    int XTemp = 0;
    int ZTemp = 0;
    int pas = 1;
    void reset();
};

#endif // CALIBRERPAGE_H
