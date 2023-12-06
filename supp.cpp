#include "supp.h"
#include "ui_supp.h"
#include "GestionMateriels.h"
#include "materiels.h"
#include <QMessageBox>
supp::supp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supp)
{
    ui->setupUi(this);
}

supp::~supp()
{
    delete ui;
}

void supp::on_pushButton_sp_clicked()
{
    int ID =ui->lineEdit_ids->text().toInt();
    bool test=Ma.supprimer(ID);
    if (test)
    {   QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("suppression avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" suppression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
