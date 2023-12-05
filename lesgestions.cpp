#include "lesgestions.h"
#include "ui_lesgestions.h"
#include "GestionMateriels.h"

LesGestions::LesGestions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LesGestions)
{
    ui->setupUi(this);

}
LesGestions::~LesGestions()
{
    delete ui;
}

void LesGestions::on_Buton_materiels_clicked()
{
    /*GestionMateriels mater;
    mater.setModal(true);
    mater.exec();*/
    GestionMateriels *mater = new GestionMateriels(this);  // Assuming GestionMateriels is derived from QDialog
        mater->setAttribute(Qt::WA_DeleteOnClose);  // This will automatically delete the object when closed
        mater->show();
}
