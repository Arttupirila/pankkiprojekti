#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SerialReaderdll.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SerialReaderdll *objectSerialReader;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;

private slots:
    void showCardNumberSlot(QString);
    void on_btnTest_clicked();
};
#endif // MAINWINDOW_H
