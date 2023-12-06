#include "modifier.h"
#include "ui_modifier.h"
#include "materiels.h"
#include <QMessageBox>
#include "GestionMateriels.h"
modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}

void modifier::on_pushButton_clicked()
{
    int id=ui->id_modi->text().toInt();
    bool test=Ma.modifier(id);
    if (test)
    {   QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("modification avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" modification non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
