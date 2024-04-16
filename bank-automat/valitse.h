#ifndef VALITSE_H
#define VALITSE_H

#include <QDialog>

namespace Ui {
class Valitse;
}

class Valitse : public QDialog
{
    Q_OBJECT

public:
    explicit Valitse(QWidget *parent = nullptr);
    ~Valitse();

    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_btnOtto_clicked();

    void on_SaldoBtn_clicked();

private:
    Ui::Valitse *ui;
    QByteArray webToken;
};

#endif // VALITSE_H
