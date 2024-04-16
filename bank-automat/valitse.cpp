#include "valitse.h"
#include "tilitapahtumat.h"
#include "ui_valitse.h"
#include"nosto.h"

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
    objectNosto->setAccountNumber(accountNumber);
    objectNosto -> open();
}

void Valitse::setAccountNumber(const QString &newAccountNumber)
{
    accountNumber = newAccountNumber;
    qDebug() << accountNumber;
}

void Valitse::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    //qDebug()<<webToken;
}

void Valitse::on_btnTapahtumat_clicked()
{
    tilitapahtumat *objectTilitapahtumat = new tilitapahtumat;
    objectTilitapahtumat->setWebToken(webToken);
    objectTilitapahtumat->setAccountNumber(accountNumber);
    objectTilitapahtumat->open();
}

