#include "nosto.h"
#include "ui_nosto.h"

Nosto::Nosto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Nosto)
{
    ui->setupUi(this);
    connect(ui->btn20, &QPushButton::clicked, this, &Nosto::openHtiedot);
    connect(ui->btn40, &QPushButton::clicked, this, &Nosto::openHtiedot);
    connect(ui->btn60, &QPushButton::clicked, this, &Nosto::openHtiedot);
    connect(ui->btn90, &QPushButton::clicked, this, &Nosto::openHtiedot);
    connect(ui->btn140, &QPushButton::clicked, this, &Nosto::openHtiedot);
    connect(ui->btn240, &QPushButton::clicked, this, &Nosto::openHtiedot);


}

Nosto::~Nosto()
{
    delete ui;
}


void Nosto::on_btn20_clicked()
{
    httpPost(20);
    //void nostoSlot (QNetworkReply *reply);

}


void Nosto::on_btn40_clicked()
{
    httpPost(40);
    //void nostoSlot (QNetworkReply *reply);

}


void Nosto::on_btn60_clicked()
{

    httpPost(60);
    //void nostoSlot (QNetworkReply *reply);

}


void Nosto::on_btn90_clicked()
{
    httpPost(90);
    //void nostoSlot (QNetworkReply *reply);

}


void Nosto::on_btn140_clicked()
{
    httpPost(140);
    //void nostoSlot (QNetworkReply *reply);

}


void Nosto::on_btn240_clicked()
{
    httpPost(240);
    //void nostoSlot (QNetworkReply *reply);

}


void Nosto::on_btnReturn_clicked()
{

}


void Nosto::on_btnOtherSum_clicked()
{

}

void Nosto::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    //qDebug()<<webToken;

}
void Nosto::nostoSlot (QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
}

void Nosto::setAccountNumber(const QString &newAccountNumber)
{
    accountNumber = newAccountNumber;
}

void Nosto::httpPost(double RahaMaara) {

    QJsonObject jsonObj;
    jsonObj.insert("firstid", accountNumber);
    jsonObj.insert("amount", RahaMaara);


    QString site_url="http://localhost:3000/procedures/nosto";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));


    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}
