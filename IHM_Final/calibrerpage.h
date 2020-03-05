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

private:
    Ui::calibrerpage *ui;
};

#endif // CALIBRERPAGE_H
