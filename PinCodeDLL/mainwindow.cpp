#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn1_clicked()
{
    QString currentText = ui->lineEdit->text();
    if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn1->text());


        }


}


void MainWindow::on_btn2_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn2->text());
        }



}


void MainWindow::on_btn3_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn3->text());
        }


}


void MainWindow::on_btn4_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn4->text());
        }


}


void MainWindow::on_btn5_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn5->text());
        }


}


void MainWindow::on_btn6_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn6->text());
        }

}


void MainWindow::on_btn7_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn7->text());
        }


}


void MainWindow::on_btn8_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn8->text());
        }

}


void MainWindow::on_btn9_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn9->text());
        }


}


void MainWindow::on_btn0_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText.length() < 4) {
         ui->lineEdit->setText(currentText+ui->btn0->text());
        }


}


void MainWindow::on_btnReset_clicked()
{
        ui->lineEdit->clear();
}


void MainWindow::on_btnErase_clicked()
{
        QString currentText = ui->lineEdit->text();
        ui->lineEdit->setText(currentText.chopped(1));
}


void MainWindow::on_btnOK_clicked()
{
        QString currentText = ui->lineEdit->text();
        if (currentText==correctPin) {
         ui->label->setText("PIN Oikein");
         attempts = 3;
        }
        else {
         ui->label->setText("PIN Väärin");
         attempts --;
        }
        ui->lineEdit->clear();

        if (attempts == 0) {
         ui->label->setText("Liian monta väärää yritystä. Tili lukittu.");
         ui->btnOK->setEnabled(false);
        }
}
