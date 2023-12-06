#ifndef GestionAnimaux_H
#define GestionAnimaux_H
#include "animaux.h"
#include "ajouter.h"
#include <QMainWindow>
#include <QGridLayout>
#include "ui_GestionAnimaux.h"
namespace Ui {
class GestionAnimaux;
}
class GestionAnimaux : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionAnimaux(QWidget *parent = nullptr);
    ~GestionAnimaux();
    QWidget *mainWidget;
    QWidget *statsWidget;
private slots:
    void on_supprimeran_clicked();
    void on_Ajouter_clicked();
    void on_affichean_clicked();
    //void on_modifieran_clicked();
    void on_Trieran_clicked();
    void on_pdfa_clicked();
    void on_statanim_clicked();
    void afficherStatistiques();
    void on_recherchean_clicked();

private:
    Ui::GestionAnimaux *ui;
    animaux anims;

};

#endif // GestionAnimaux_H
