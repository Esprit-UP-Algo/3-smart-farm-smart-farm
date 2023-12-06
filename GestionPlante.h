#ifndef GESTIONPLANTE_H
#define GESTIONPLANTE_H
#include <QMainWindow>
#include <QDialog>
#include"plante.h"
QT_BEGIN_NAMESPACE
#include "login.h"

namespace Ui {
class GestionPlante;
}
QT_END_NAMESPACE
class GestionPlante : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionPlante(QWidget *parent = nullptr);
    ~GestionPlante();
    void exportToPDF();
    void afficherStatistiques();
    QWidget *statsWidget;
       QWidget *mainWidget;

private slots:
    void on_pb_ajouter_clicked();
    void on_pushButton_supp_clicked();


    void on_pb_ajouter_2_clicked();



    void on_rechercher_clicked();






    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_clicked();



    void on_radioButton_2_clicked();

private:
    Ui::GestionPlante *ui;
    Plante p;
};

#endif // MAINWINDOW_H
