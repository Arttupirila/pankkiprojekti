#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();

    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_Lopeta_clicked();
private slots:
    void saldoSlot (QNetworkReply *reply);

private:
    Ui::Saldo *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray webToken;

};

#endif // SALDO_H
