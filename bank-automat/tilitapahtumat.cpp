#include "environment.h"
#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"


tilitapahtumat::tilitapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);
}

tilitapahtumat::~tilitapahtumat()
{
    delete ui;
}
void tilitapahtumat::setAccountNumber(const QString &newAccountNumber)
{
    accountNumber = newAccountNumber;
    qDebug() << accountNumber;
}

void tilitapahtumat::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug()<<webToken;
}

void tilitapahtumat::populateList(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString list;
    list="Tililtä\t\tAika\t\tTapahtuma\tSumma\tTilille\r";
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        list+=json_obj["idAccount"].toString()+"\t";
        QString date = json_obj["dateAndTime"].toString();
        date.chop(5);
        date.replace(10, 1, " ");
        list+=date+"\t";
        list+=json_obj["transactionType"].toString()+"\t";
        list+=json_obj["transactionAmount"].toString()+"\t";
        list+="\r";
    }
    ui->textTransactions->setText(list);
   }

void tilitapahtumat::on_btnPopulate_clicked()
{
    QString site_url=Environment::getBaseUrl()+"/transaction/"+accountNumber;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    eventManager = new QNetworkAccessManager(this);
    connect(eventManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(populateList(QNetworkReply*)));
    reply = eventManager->get(request);
}


void tilitapahtumat::on_btnClose_clicked()
{
   this->close();
}

