#ifndef GestionMAteriels_H
#define GestionMAteriels_H
#include <QDialog>
#include <QMainWindow>
#include "materiels.h"
#include "ui_GestionMateriels.h"
namespace Ui {
class GestionMateriels;
}

class GestionMateriels : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionMateriels(QWidget *parent = nullptr);
    ~GestionMateriels();
    QWidget *mainWidget;
       QWidget *statsWidget;

private slots:

    void on_pushButton_clicked();
    void on_pushButton_sup_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    //void on_pushButton_4_clicked();
    void on_pushButton_4_clicked();
    void on_searchButton_clicked();
    void exportToPDF();
    void afficherStatistiques();
    void on_pushButton_pdf_clicked();
    void on_pushButton_stat_clicked();

private:
    Ui::GestionMateriels *ui;
    Materiels Ma;

};

#endif // GestionMAteriels_H
