#include "valitse.h"
#include "ui_valitse.h"

Valitse::Valitse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Valitse)
{
    ui->setupUi(this);
}

Valitse::~Valitse()
{
    delete ui;
}
