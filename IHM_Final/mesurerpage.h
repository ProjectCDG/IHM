#ifndef MESURERPAGE_H
#define MESURERPAGE_H

#include <QDialog>


namespace Ui {
class mesurerpage;
}

class mesurerpage : public QDialog
{
    Q_OBJECT

public:
    explicit mesurerpage(QWidget *parent = nullptr);
    ~mesurerpage();
    int envoieCoordX();
    int envoieCoordY();
    int envoieCoordZ();

private slots:
    void on_butMesure_clicked();

    void on_butSuivant_clicked();

    void on_butDeco_clicked();


signals:
    void changePage(QString value);


private:
    void reset();
    Ui::mesurerpage *ui;
    void centreDeGravite();
    int x;
    int y;
    int z;
    int TabCoord[3];


};

#endif // MESURERPAGE_H
