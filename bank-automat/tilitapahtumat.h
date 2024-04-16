#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QWidget *parent = nullptr);
    ~tilitapahtumat();

    void setWebToken(const QByteArray &newWebToken);

    void setAccountNumber(const QString &newAccountNumber);

private slots:
    void on_btnPopulate_clicked();
    void populateList(QNetworkReply *reply);


private:
    Ui::tilitapahtumat *ui;
    QByteArray webToken;
    QString accountNumber;
    QNetworkAccessManager *eventManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // TILITAPAHTUMAT_H
