#ifndef GESTIONEMLPOYE_H
#define GESTIONEMLPOYE_H
#include <QMainWindow>

#include "arduino.h"
#include "employe.h"
#include "ui_GestionEmploye.h"
namespace Ui {
class GestionEmploye;
}

namespace Ui {

class GestionEmploye;
}
class GestionEmploye: public QMainWindow
{
    Q_OBJECT

public:
    employe e;



    explicit GestionEmploye(QWidget *parent = nullptr);
    ~GestionEmploye();

    QWidget *mainWidget;
    QWidget *statsWidget;



private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supp_clicked();
    void on_affichem_clicked();
    void on_pushButton_modifier_clicked();
    void on_pb_recher_clicked();
    //void on_pb_trier_clicked();
    //std::string chatbotFunction(const);
    void afficherStatistiques();
    void on_pb_pdf_clicked();
    void on_pb_stat_clicked();
    //void on_envoyer_clicked();
    void on_radioButton_NOM_clicked();
   //oid on_tabWidget_currentChanged(int index);
    void on_radioButton_2_clicked();
    void on_pushButton_tentative_clicked();
    //void readFromArduino();
   //oid incrementNbreEntree();
   //String getnbreEntreeData();
    void update_label();
    void on_pushButton_qrcode_clicked();

private:
    Ui::GestionEmploye *ui;
    QByteArray data;
    Arduino A;
};

#endif // DIAL
