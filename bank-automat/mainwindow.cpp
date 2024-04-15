#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "valitse.h"
#include <QMessageBox>
#include <environment.h>
#include <pindll.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objectSerialReader = new SerialReaderdll;
    connect(objectSerialReader,SIGNAL(serialRead(QString)),
           this,SLOT(showCardNumberSlot(QString)));
    //testaus ilman serialReaderia
    //showCardNumberSlot("6319704283501674");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::etsiTili(QByteArray token, QString cardNumber)
{

    QString site_url=Environment::getBaseUrl()+"/accountNumber/"+cardNumber;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(token));
    accountManager = new QNetworkAccessManager(this);
    connect(accountManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(accountSlot(QNetworkReply*)));
    reply = accountManager->get(request);

}

void MainWindow::showCardNumberSlot(QString value)
{
    qDebug() << value;
    Pindll *objectPindll = new Pindll;
    objectPindll->openDllDialog();
    QString pin = objectPindll->getPinValue();
    qDebug() << pin;
    idCard = value;
    QString idPin = pin;
    QJsonObject jsonObj;
    jsonObj.insert("idCard",idCard);
    jsonObj.insert("cardPin",idPin);
    QString site_url=Environment::getBaseUrl()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}
void MainWindow::on_btnTest_clicked()
{
    Pindll *objectPindll = new Pindll;
    objectPindll->openDllDialog();
}
void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    QMessageBox msgBox;
    if(response_data=="-4078" || response_data.length()==0){
        msgBox.setText("Virhe tietoyhteydessä");
            msgBox.exec();
    }
    else{
        if(response_data!="false"){
            //kirjautuminen onnistui
            msgBox.setText("kirjautuminen onnistui");
            msgBox.exec();
            webToken = "Bearer "+response_data;
            qDebug() << webToken;
            Valitse *objectValitse = new Valitse;
            objectValitse -> setWebToken(webToken);
            objectValitse -> open();
        }
        else{
            msgBox.setText("Tunnus/salasana ei täsmää");
            msgBox.exec();
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}

void MainWindow::accountSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug() << response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();

    reply->deleteLater();
    accountManager->deleteLater();
    qDebug() << json_array.size();
    if (json_array.size() == 2)
    {
        qDebug() << "avataan valitsetili";
        QString creditLimit1 = json_array.at(0)["creditLimit"].toString();
        QString debitNumber;
        QString creditNumber;
        if (creditLimit1 == "0.00"){
            debitNumber = json_array.at(0)["idAccount"].toString();
            creditNumber = json_array.at(1)["idAccount"].toString();
        }
        else {
            debitNumber = json_array.at(1)["idAccount"].toString();
            creditNumber = json_array.at(0)["idAccount"].toString();
        }
        qDebug() << debitNumber;


    }
    else{
        qDebug() << "mennään suoraan valitse";
        QString accountNumber = json_array.at(0)["idAccount"].toString();
        Valitse *objectValitse = new Valitse(this);
        objectValitse->setWebToken(webToken);
        objectValitse->setAccountNumber(accountNumber);
        objectValitse->open();
    }
}
