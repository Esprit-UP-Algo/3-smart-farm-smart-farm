#ifndef SUPP_H
#define SUPP_H

#include <QDialog>
#include "materiels.h"
#include <QMessageBox>
namespace Ui {
class supp;
}

class supp : public QDialog
{
    Q_OBJECT

public:
    explicit supp(QWidget *parent = nullptr);
    ~supp();

private slots:
    void on_pushButton_sp_clicked();

private:
    Ui::supp *ui;
    Materiels Ma;

};

#endif // SUPP_H
