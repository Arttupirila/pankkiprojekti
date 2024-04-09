#include "nosto.h"
#include "ui_nosto.h"

Nosto::Nosto(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Nosto)
{
    ui->setupUi(this);
    connect(ui->btn20, &QPushButton::clicked, this, &Nosto::openHtiedot);

}

Nosto::~Nosto()
{
    delete ui;
}


void Nosto::on_btn20_clicked()
{

}


void Nosto::on_btn40_clicked()
{

}


void Nosto::on_btn60_clicked()
{

}


void Nosto::on_btn90_clicked()
{

}


void Nosto::on_btn140_clicked()
{

}


void Nosto::on_btn240_clicked()
{

}


void Nosto::on_btnReturn_clicked()
{

}


void Nosto::on_btnOtherSum_clicked()
{

}

