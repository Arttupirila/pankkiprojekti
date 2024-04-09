#ifndef VALITSE_H
#define VALITSE_H

#include <QDialog>

namespace Ui {
class Valitse;
}

class Valitse : public QDialog
{
    Q_OBJECT

public:
    explicit Valitse(QWidget *parent = nullptr);
    ~Valitse();

private:
    Ui::Valitse *ui;
};

#endif // VALITSE_H
