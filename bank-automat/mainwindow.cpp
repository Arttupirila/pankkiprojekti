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
    //connect(objectSerialReader,SIGNAL(serialRead(QString)),
    //        this,SLOT(showCardNumberSlot(QString)));
    //testaus ilman serialReaderia
    showCardNumberSlot("12344UYysys");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::btnClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button clicked: " << name.last(1);
}

void MainWindow::on_btn_A_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_B_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_C_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_D_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_E_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_F_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_G_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_H_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_I_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_J_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_K_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_L_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_1_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_2_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_3_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_4_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_5_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_6_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_7_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_8_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_9_clicked()
{    btnClickedHandler();}
void MainWindow::on_btn_0_clicked()
{    btnClickedHandler();}


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

