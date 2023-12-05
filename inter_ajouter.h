 #ifndef INTER_AJOUTER_H
#define INTER_AJOUTER_H

#include <QDialog>

namespace Ui {
class inter_ajouter;
}

class inter_ajouter : public QDialog
{
    Q_OBJECT

public:
    explicit inter_ajouter(QWidget *parent = nullptr);
    ~inter_ajouter();

private slots:


    void on_confirm_button_clicked();

private:
    Ui::inter_ajouter *ui;
};

#endif // INTER_AJOUTER_H
