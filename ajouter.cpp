#include "ajouter.h"
#include "ui_ajouter.h"
#include "animaux.h"
#include "GestionAnimaux.h"
#include <QMessageBox>
#include <QString>
#include <QLineEdit>
ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("\\d+"),this));
    QRegExp rx("(mouton|vache|poulet)");
    QRegExpValidator *validator = new QRegExpValidator(rx);
    ui->lineEdit_racea->setValidator(validator);
    QRegExp rx2("(f|m)");

    QRegExpValidator *validator2 = new QRegExpValidator(rx2);
    ui->lineEdit_sexe->setValidator(validator2);


}

ajouter::~ajouter()
{
    delete ui;
}

void ajouter::on_confirmer_clicked()
{
     int idanim=ui->lineEdit_id->text().toInt();
     QString racea=ui->lineEdit_racea->text();
    QString poul="poulet";
     QString sexe=ui->lineEdit_sexe->text();
     animaux an(idanim,racea,sexe);
     bool test=an.ajouteranim();
     if(test){

         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectuer \n click cancel to exit"), QMessageBox::Cancel);
     }
     else{
         QMessageBox::critical(nullptr, QObject::tr("not ok"),
                     QObject::tr(" ajout non effectué.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }

}
