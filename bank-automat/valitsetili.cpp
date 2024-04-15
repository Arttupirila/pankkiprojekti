#include "valitsetili.h"
#include "ui_valitsetili.h"

valitseTili::valitseTili(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::valitseTili)
{
    ui->setupUi(this);
}

valitseTili::~valitseTili()
{
    delete ui;
}

void valitseTili::setCredit(const QString &newCredit)
{
    credit = newCredit;
}

void valitseTili::setDebit(const QString &newDebit)
{
    debit = newDebit;
}
