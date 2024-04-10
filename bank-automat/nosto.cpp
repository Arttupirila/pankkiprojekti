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
   // int Rahamaara = 20;
    httpPost(20);
}


void Nosto::on_btn40_clicked()
{
    //int Rahamaara = 40;
    httpPost(40);
}


void Nosto::on_btn60_clicked()
{
    //int Rahamaara = 60;
    httpPost(60);
}


void Nosto::on_btn90_clicked()
{
    //int Rahamaara = 90;
    httpPost(90);
}


void Nosto::on_btn140_clicked()
{
    httpPost(140);
}


void Nosto::on_btn240_clicked()
{
    httpPost(240);
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

