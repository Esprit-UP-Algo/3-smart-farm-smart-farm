#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"
#include "ajouter.h"
#include "supprimeran.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tablevie->setModel(anims.afficheranim());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_supprimeran_clicked()
{
    supprimeran supran;
    supran.setModal(true);
    supran.exec();
}




void MainWindow::on_Ajouter_clicked()
{
    ajouter ajout;
    ajout.setModal(true);
    ajout.exec();
}


