#ifndef HTIEDOT_H
#define HTIEDOT_H

#include <QDialog>

namespace Ui {
class Htiedot;
}

class Htiedot : public QDialog
{
    Q_OBJECT

public:
    explicit Htiedot(QWidget *parent = nullptr);
    ~Htiedot();

private:
    Ui::Htiedot *ui;
};

#endif // HTIEDOT_H
