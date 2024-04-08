#include "mainwindow.h"
#include "ui_mainwindow.h"

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

<<<<<<< HEAD
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
=======
void MainWindow::showCardNumberSlot(QString value)
{
    qDebug() << value;
    Pindll *objectPindll = new Pindll;
    objectPindll->openDllDialog();
    QString pin = objectPindll->getPinValue();
    qDebug() << pin;

}



void MainWindow::on_btnTest_clicked()
{
    Pindll *objectPindll = new Pindll;
    objectPindll->openDllDialog();
}

>>>>>>> a2350e992711692107ea9e6913c94ec0ecfed4ce
