#include "mainwindow.h"
#include "ui_mainwindow.h"

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
