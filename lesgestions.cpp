#include "lesgestions.h"
#include "ui_lesgestions.h"
#include "GestionMateriels.h"
#include "GestionPlante.h"
#include "GestionEmploye.h"
#include "GestionAnimaux.h"

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

void LesGestions::on_Buton_plantes_clicked()
{
        GestionPlante *mater2 = new GestionPlante(this);
        mater2->setAttribute(Qt::WA_DeleteOnClose);
        mater2->show();

}

void LesGestions::on_Buton_employe_clicked()
{
        GestionEmploye *mater3 = new GestionEmploye(this);
        mater3->setAttribute(Qt::WA_DeleteOnClose);
        mater3->show();



}

void LesGestions::on_Buton_animaux_clicked()
{
    GestionAnimaux *mater4 = new GestionAnimaux (this);
    mater4->setAttribute(Qt::WA_DeleteOnClose);
    mater4->show();

}
