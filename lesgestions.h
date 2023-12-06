#ifndef LESGESTIONS_H
#define LESGESTIONS_H

#include <QDialog>
#include <GestionMateriels.h>
#include "GestionEmploye.h"
#include "GestionPlante.h"
#include "GestionAnimaux.h"
namespace Ui {
class LesGestions;
}

class LesGestions : public QDialog
{
    Q_OBJECT

public:
    explicit LesGestions(QWidget *parent = nullptr);
    ~LesGestions();

private slots:
    void on_Buton_materiels_clicked();

    void on_Buton_plantes_clicked();

    void on_Buton_employe_clicked();

    void on_Buton_animaux_clicked();

private:
    Ui::LesGestions *ui;
};

#endif // LESGESTIONS_H
