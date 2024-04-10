#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("C:/Users/7300/Desktop/tvt23-pankkiprojekti/SPO_Group5/SPO_Group5/bank-automat/bankstyle.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    return a.exec();
}
