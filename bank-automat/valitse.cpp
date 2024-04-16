#include "valitse.h"
#include "ui_valitse.h"
#include "nosto.h"
#include "saldo.h"

Valitse::Valitse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Valitse)
{
    ui->setupUi(this);
}

Valitse::~Valitse()
{
    delete ui;
}

void Valitse::on_btnOtto_clicked()
{
    Nosto *objectNosto = new Nosto;
    objectNosto -> setWebToken(webToken);
    objectNosto -> open();
}

void Valitse::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    //qDebug()<<webToken;
}

void Valitse::on_SaldoBtn_clicked()
{
    Saldo *objectSaldo = new Saldo;
    objectSaldo -> setWebToken(webToken);
    objectSaldo -> open();
}

