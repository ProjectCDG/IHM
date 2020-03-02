#ifndef TESTSYLVAIN_H
#define TESTSYLVAIN_H

#include <QDialog>

namespace Ui {
class testSylvain;
}

class testSylvain : public QDialog
{
    Q_OBJECT

public:
    explicit testSylvain(QWidget *parent = nullptr);
    ~testSylvain();

private slots:
    void on_valider_clicked();

private:
    Ui::testSylvain *ui;
};

#endif // TESTSYLVAIN_H
