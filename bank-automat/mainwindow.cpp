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

