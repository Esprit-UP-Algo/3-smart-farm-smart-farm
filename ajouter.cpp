#include "ajouter.h"
#include "ui_ajouter.h"
#include "animaux.h"
#include "mainwindow.h"
#include <QMessageBox>
ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);
}

ajouter::~ajouter()
{
    delete ui;
}

void ajouter::on_confirmer_clicked()
{
     int id=ui->lineEdit_id->text().toInt();
     QString racea=ui->lineEdit_racea->text();
     QString sexe=ui->lineEdit_sexe->text();
     animaux an(id,racea,sexe);
     bool test=an.ajouteranim();
     if(test){

//ui->tablevie->setModel(anims.afficher)
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectuer \n click cancel to exit"), QMessageBox::Cancel);
     }
     else{
         QMessageBox::critical(nullptr, QObject::tr("not ok"),
                     QObject::tr(" ajout non effectué.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }

}
