#ifndef MODIFIER_H
#define MODIFIER_H
#include "animaux.h"
#include "GestionAnimaux.h"
#include <QDialog>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();

private slots:
    void on_modifierb_clicked();

private:
    Ui::modifier *ui;
    animaux anims;
};

#endif // MODIFIER_H
