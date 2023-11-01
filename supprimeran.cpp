#include "supprimeran.h"
#include "ui_supprimeran.h"
#include <QMessageBox>
#include "animaux.h"
#include "mainwindow.h"
supprimeran::supprimeran(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supprimeran)
{
    ui->setupUi(this);
}

supprimeran::~supprimeran()
{
    delete ui;
}

void supprimeran::on_supprimeran2_clicked()
{
    int id=ui->lineEdit_suppa->text().toInt();
bool test=anims.supprimeranim(id);
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


