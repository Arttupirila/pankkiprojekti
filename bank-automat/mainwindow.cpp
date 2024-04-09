#include "mainwindow.h"
#include "ui_mainwindow.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCardNumberSlot(QString value)
{
    qDebug() << value;
    Pindll *objectPindll = new Pindll;
    objectPindll->openDllDialog();
    QString pin = objectPindll->getPinValue();
    qDebug() << pin;

    QString idCard = value;
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
        }
        else{
            msgBox.setText("Tunnus/salasana ei täsmää");
            msgBox.exec();
        }
    }
    reply->deleteLater();
    loginManager->deleteLater();
}

