#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}


