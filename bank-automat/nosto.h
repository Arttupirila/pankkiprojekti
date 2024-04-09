#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include "htiedot.h"

namespace Ui {
class Nosto;
}

class Nosto : public QDialog
{
    Q_OBJECT

public:
    explicit Nosto(QWidget *parent = nullptr);
    ~Nosto();

private slots:

    void on_btn20_clicked();

    void on_btn40_clicked();

    void on_btn60_clicked();

    void on_btn90_clicked();

    void on_btn140_clicked();

    void on_btn240_clicked();

    void on_btnReturn_clicked();

    void on_btnOtherSum_clicked();

    void openHtiedot() {
        Htiedot * newHtiedot = new Htiedot(this);
        newHtiedot->show();
    }

private:
    Ui::Nosto *ui;
};

#endif // NOSTO_H
