#ifndef AJOUTER_H
#define AJOUTER_H
#include "GestionAnimaux.h"
#include <QDialog>

namespace Ui {
class ajouter;
}

class ajouter : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter(QWidget *parent = nullptr);
    ~ajouter();

private slots:
    void on_confirmer_clicked();

private:
    Ui::ajouter *ui;
};

#endif // AJOUTER_H
