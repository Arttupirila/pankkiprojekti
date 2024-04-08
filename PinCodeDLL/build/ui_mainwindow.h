/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn5;
    QPushButton *btn8;
    QPushButton *btn1;
    QPushButton *btn9;
    QPushButton *btn3;
    QLineEdit *lineEdit;
    QPushButton *btn6;
    QPushButton *btnErase;
    QLabel *label;
    QPushButton *btn4;
    QPushButton *btn7;
    QPushButton *btn0;
    QPushButton *btnReset;
    QPushButton *btn2;
    QPushButton *btnOK;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName("btn5");
        btn5->setGeometry(QRect(300, 140, 71, 41));
        QFont font;
        font.setPointSize(12);
        btn5->setFont(font);
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName("btn8");
        btn8->setGeometry(QRect(300, 190, 71, 41));
        btn8->setFont(font);
        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName("btn1");
        btn1->setGeometry(QRect(220, 90, 71, 41));
        btn1->setFont(font);
        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName("btn9");
        btn9->setGeometry(QRect(380, 190, 71, 41));
        btn9->setFont(font);
        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName("btn3");
        btn3->setGeometry(QRect(380, 90, 71, 41));
        btn3->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(270, 50, 131, 31));
        QFont font1;
        font1.setPointSize(16);
        lineEdit->setFont(font1);
        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName("btn6");
        btn6->setGeometry(QRect(380, 140, 71, 41));
        btn6->setFont(font);
        btnErase = new QPushButton(centralwidget);
        btnErase->setObjectName("btnErase");
        btnErase->setGeometry(QRect(380, 240, 71, 41));
        btnErase->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 0, 531, 51));
        QFont font2;
        font2.setPointSize(18);
        label->setFont(font2);
        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName("btn4");
        btn4->setGeometry(QRect(220, 140, 71, 41));
        btn4->setFont(font);
        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName("btn7");
        btn7->setGeometry(QRect(220, 190, 71, 41));
        btn7->setFont(font);
        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName("btn0");
        btn0->setGeometry(QRect(300, 240, 71, 41));
        btn0->setFont(font);
        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(220, 240, 71, 41));
        btnReset->setFont(font);
        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName("btn2");
        btn2->setGeometry(QRect(300, 90, 71, 41));
        btn2->setFont(font);
        btnOK = new QPushButton(centralwidget);
        btnOK->setObjectName("btnOK");
        btnOK->setGeometry(QRect(270, 300, 131, 41));
        btnOK->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        lineEdit->setText(QString());
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btnErase->setText(QCoreApplication::translate("MainWindow", "Pyyhi", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Anna PIN-koodi", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Tyhjenn\303\244", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btnOK->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
