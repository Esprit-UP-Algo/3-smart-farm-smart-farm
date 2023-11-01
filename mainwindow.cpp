#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inter_ajouter.h"
#include<QApplication>
#include <QMessageBox>
#include<QTableWidget>
#include <QWidgetItem>
#include<QIntValidator>
#include<QString>
#include"connection.h"
#include <QDebug>
using namespace std;
#include <iostream>
#include "supp.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ma.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    inter_ajouter inter;
    inter.setModal(true);
    inter.exec();
}


void MainWindow::on_pushButton_sup_clicked()
{
        supp sup;
        sup.setModal(true);
        sup.exec();

}
