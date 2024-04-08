#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SerialReaderdll.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    void on_btn_A_clicked();
    void on_btn_B_clicked();
    void on_btn_C_clicked();
    void on_btn_D_clicked();
    void on_btn_E_clicked();
    void on_btn_F_clicked();
    void on_btn_G_clicked();
    void on_btn_H_clicked();
    void on_btn_I_clicked();
    void on_btn_J_clicked();
    void on_btn_K_clicked();
    void on_btn_L_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_0_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
    void btnClickedHandler();

=======
    SerialReaderdll *objectSerialReader;

private slots:
    void showCardNumberSlot(QString);
    void on_btnTest_clicked();
>>>>>>> a2350e992711692107ea9e6913c94ec0ecfed4ce
};
#endif // MAINWINDOW_H
