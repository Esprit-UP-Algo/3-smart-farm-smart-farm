#ifndef SUPPRIMERAN_H
#define SUPPRIMERAN_H
#include "animaux.h"
#include "GestionAnimaux.h"
#include <QDialog>

namespace Ui {
class supprimeran;
}

class supprimeran : public QDialog
{
    Q_OBJECT

public:
    explicit supprimeran(QWidget *parent = nullptr);
    ~supprimeran();

private slots:
    void on_supprimeran2_clicked();

private:
    Ui::supprimeran *ui;
    animaux anims;
};

#endif // SUPPRIMERAN_H
