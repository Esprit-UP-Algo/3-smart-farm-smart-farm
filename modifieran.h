#ifndef MODIFIERAN_H
#define MODIFIERAN_H
#include "ui_modifieran.h"
#include "animaux.h"
#include "GestionAnimaux.h"
#include <QDialog>

namespace Ui {
class modifieran;
}

class modifieran : public QDialog
{
    Q_OBJECT

public:
    explicit modifieran(QWidget *parent = nullptr);
    ~modifieran();

private slots:
    void on_modifierb_clicked();

private:
    Ui::modifieran *ui;
    animaux anims;
};

#endif // MODIFIERAN_H
