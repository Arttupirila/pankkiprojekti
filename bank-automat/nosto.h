#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "htiedot.h"



namespace Ui {
class Nosto;
}

class Nosto : public QDialog
{
    Q_OBJECT

public:
    explicit Nosto(QWidget *parent = nullptr);
    ~Nosto();

    void setWebToken(const QByteArray &newWebToken);

private slots:

    void on_btn20_clicked();

    void on_btn40_clicked();

    void on_btn60_clicked();

    void on_btn90_clicked();

    void on_btn140_clicked();

    void on_btn240_clicked();

    void on_btnReturn_clicked();

    void on_btnOtherSum_clicked();

    void openHtiedot() {
        Htiedot * newHtiedot = new Htiedot(this);
        newHtiedot->show();
    }

    void httpPost(int RahaMaara) {

        QJsonObject jsonObj;
        jsonObj.insert("rahaa",RahaMaara);

        QString site_url="http://localhost:3000/procedures/nosto";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        //WEBTOKEN ALKU
        request.setRawHeader(QByteArray("Authorization"),(webToken));
        //WEBTOKEN LOPPU

        postManager = new QNetworkAccessManager(this);
        connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));

        reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
    }
    //void nostoSlot (QNetworkReply *reply);


private:
    Ui::Nosto *ui;
    QByteArray webToken;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // NOSTO_H
