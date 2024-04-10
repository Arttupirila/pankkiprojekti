#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btn1_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn1->text());
    }
}


void Dialog::on_btn2_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn2->text());
    }
}


void Dialog::on_btn3_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn3->text());
    }
}


void Dialog::on_btn4_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn4->text());
    }
}


void Dialog::on_btn5_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn5->text());
    }
}


void Dialog::on_btn6_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn6->text());
    }
}


void Dialog::on_btn7_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn7->text());
    }
}


void Dialog::on_btn8_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn8->text());
    }
}


void Dialog::on_btn9_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn9->text());
    }
}


void Dialog::on_btn0_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4){
        ui->lineEdit->setText(currentText+ui->btn0->text());
    }
}


void Dialog::on_btnReset_clicked()
{
    ui->lineEdit->clear();
}


void Dialog::on_btnErase_clicked()
{
    QString currentText = ui->lineEdit->text();
    ui->lineEdit->setText(currentText.chopped(1));
}


void Dialog::on_btnOK_clicked()
{
    QString currentText = ui->lineEdit->text();
    pin = currentText;
    if (currentText == correctPin){
        ui->label->setText("PIN Oikein");
        attempts = 3;
        //pin = currentText;
    }
    else {
        ui->label->setText("PIN Väärin");
        attempts--;
    }
    ui->lineEdit->clear();

    if (attempts == 0){
        ui->label->setText("Liian monta yritystä. Tili Lukittu");
        ui->btnOK->setEnabled(false);
    }
    this->close();
}

QString Dialog::getPin() const
{
    return pin;
}

