#include "htiedot.h"
#include "ui_htiedot.h"

Htiedot::Htiedot(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Htiedot)
{
    ui->setupUi(this);
}

Htiedot::~Htiedot()
{
    delete ui;
}
