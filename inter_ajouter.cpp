#include "inter_ajouter.h"
#include "ui_inter_ajouter.h"
#include "materiels.h"
#include <QMessageBox>
inter_ajouter::inter_ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inter_ajouter)
{
    ui->setupUi(this);
    /*
    ui->lineEdit->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_3->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_2->setMaxLength(8);*/
    //ui->lineEdit_2->setValidator(new QRegExpValidator("^[A-Za-z_]{1,8}$,this"));
}

inter_ajouter::~inter_ajouter()
{
    delete ui;
}


void inter_ajouter::on_confirm_button_clicked()
{
    int id=ui->lineEdit->text().toInt();
    int age=ui->lineEdit_3->text().toInt();
    QString nom=ui->lineEdit_2->text();
   Materiels M(nom,id,age);
    bool test=M.ajouter();
    if (test)
       {
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Ajout effectue \n""Click cancel to to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" NOT OK"),QObject::tr("Ajout non effectue \n""Click cancel to exit."), QMessageBox ::Cancel);
    }
}
