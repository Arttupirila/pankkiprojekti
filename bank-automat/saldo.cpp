#include "saldo.h"
#include "ui_saldo.h"
#include "nosto.h"
#include "nosto.cpp"


Saldo::Saldo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Saldo)
{
    ui->setupUi(this);

}

Saldo::~Saldo()
{
    delete ui;
}

void Saldo::on_Lopeta_clicked()
{
    this -> close();
}

void Saldo::saldoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString accountBalance;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        accountBalance+=(json_obj["balance"].toString());
    }

    ui->lineEdit->setText(accountBalance);

    reply->deleteLater();
    getManager->deleteLater();
}

void Saldo::setAccountNumber(const QString &newAccountNumber)
{
    accountNumber = newAccountNumber;
}

void Saldo::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void Saldo::getSaldo()
{
    qDebug() << "saldo";
    qDebug() << webToken;
    QString site_url="http://localhost:3000/account/balance/"+accountNumber;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(saldoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}


