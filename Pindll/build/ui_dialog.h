/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btnReset;
    QPushButton *btn0;
    QPushButton *btnErase;
    QPushButton *btnOK;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(896, 608);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 30, 211, 61));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(290, 90, 201, 41));
        btn1 = new QPushButton(Dialog);
        btn1->setObjectName("btn1");
        btn1->setGeometry(QRect(250, 150, 81, 41));
        btn2 = new QPushButton(Dialog);
        btn2->setObjectName("btn2");
        btn2->setGeometry(QRect(350, 150, 81, 41));
        btn3 = new QPushButton(Dialog);
        btn3->setObjectName("btn3");
        btn3->setGeometry(QRect(450, 150, 81, 41));
        btn4 = new QPushButton(Dialog);
        btn4->setObjectName("btn4");
        btn4->setGeometry(QRect(250, 200, 81, 41));
        btn5 = new QPushButton(Dialog);
        btn5->setObjectName("btn5");
        btn5->setGeometry(QRect(350, 200, 81, 41));
        btn6 = new QPushButton(Dialog);
        btn6->setObjectName("btn6");
        btn6->setGeometry(QRect(450, 200, 81, 41));
        btn7 = new QPushButton(Dialog);
        btn7->setObjectName("btn7");
        btn7->setGeometry(QRect(250, 250, 81, 41));
        btn8 = new QPushButton(Dialog);
        btn8->setObjectName("btn8");
        btn8->setGeometry(QRect(350, 250, 81, 41));
        btn9 = new QPushButton(Dialog);
        btn9->setObjectName("btn9");
        btn9->setGeometry(QRect(450, 250, 81, 41));
        btnReset = new QPushButton(Dialog);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(250, 300, 81, 41));
        btn0 = new QPushButton(Dialog);
        btn0->setObjectName("btn0");
        btn0->setGeometry(QRect(350, 300, 81, 41));
        btnErase = new QPushButton(Dialog);
        btnErase->setObjectName("btnErase");
        btnErase->setGeometry(QRect(450, 300, 81, 41));
        btnOK = new QPushButton(Dialog);
        btnOK->setObjectName("btnOK");
        btnOK->setGeometry(QRect(320, 350, 141, 51));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Anna PIN-koodi", nullptr));
        btn1->setText(QCoreApplication::translate("Dialog", "1", nullptr));
        btn2->setText(QCoreApplication::translate("Dialog", "2", nullptr));
        btn3->setText(QCoreApplication::translate("Dialog", "3", nullptr));
        btn4->setText(QCoreApplication::translate("Dialog", "4", nullptr));
        btn5->setText(QCoreApplication::translate("Dialog", "5", nullptr));
        btn6->setText(QCoreApplication::translate("Dialog", "6", nullptr));
        btn7->setText(QCoreApplication::translate("Dialog", "7", nullptr));
        btn8->setText(QCoreApplication::translate("Dialog", "8", nullptr));
        btn9->setText(QCoreApplication::translate("Dialog", "9", nullptr));
        btnReset->setText(QCoreApplication::translate("Dialog", "Tyhjenn\303\244", nullptr));
        btn0->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        btnErase->setText(QCoreApplication::translate("Dialog", "Pyyhi", nullptr));
        btnOK->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
