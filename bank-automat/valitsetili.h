#ifndef VALITSETILI_H
#define VALITSETILI_H

#include <QDialog>

namespace Ui {
class valitseTili;
}

class valitseTili : public QDialog
{
    Q_OBJECT

public:
    explicit valitseTili(QWidget *parent = nullptr);
    ~valitseTili();

    void setCredit(const QString &newCredit);

    void setDebit(const QString &newDebit);

private:
    Ui::valitseTili *ui;
    QString credit;
    QString debit;
};

#endif // VALITSETILI_H
