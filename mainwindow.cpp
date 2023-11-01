#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"plante.h"
#include<QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
#include"connection.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->tableView->setModel(p.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    qDebug();
    QString idp=ui->le_id->text();
    QString position =ui->le_pos->text();
     QString type=ui->le_type->text();
     QString saison =ui->le_saison->text();
     int duree =ui->lineEdit->text().toInt();

 Plante p(idp ,position,type,saison,duree);
 bool test=p.ajouter();
 if (test){
     QMessageBox::information(nullptr, QObject::tr("ok"),
                 QObject::tr("ajout avec success.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

 }
 else
     QMessageBox::critical(nullptr, QObject::tr("not ok"),
                 QObject::tr(" ajout non effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supp_clicked()
{
    QString idp=ui->lineEdit_9->text();
bool test=p.supprimer(idp);
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
