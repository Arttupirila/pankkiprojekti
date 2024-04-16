#include "valitsetili.h"
#include "ui_valitsetili.h"
#include "valitse.h"

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


void valitseTili::on_btnDebit_clicked()
{
  //  qDebug()<<debit;
    Valitse *objectValitse = new Valitse(this);
    objectValitse->setWebToken(webToken);
    objectValitse->setAccountNumber(debit);
    objectValitse->open();
}


void valitseTili::on_btnCredit_clicked()
{
  //  qDebug()<<credit;
    Valitse *objectValitse = new Valitse(this);
    objectValitse->setWebToken(webToken);
    objectValitse->setAccountNumber(credit);
    objectValitse->open();
}

void valitseTili::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    //qDebug()<<webToken;
}
