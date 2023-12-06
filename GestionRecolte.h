#ifndef GestionRecolte_H
#define GestionRecolte_H

#include <QMainWindow>
#include <invites.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractItemModel>
#include "ui_GestionRecolte.h"
//#include "arduino.h"

namespace Ui {
class GestionRecolte;
}


class GestionRecolte: public QMainWindow
{
    Q_OBJECT

public:
    GestionRecolte(QWidget *parent = nullptr);
    ~GestionRecolte();
    void exportToPDF();
    void  afficherStatistiques();
    void create_excel();
    int distance;



private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();


    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);
    void on_aziz_clicked();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //void readArduinoData();
    //void handleDistanceChanged(int distance);



void on_pushButton_3_clicked();



void on_abc_linkActivated(const QString &link);

private:
    Ui::GestionRecolte *ui;
     invites i;



};
#endif // GestionRecolte_H
