#include "cal.h"
#include "ui_cal.h"
#include <QDate>
#include <QMessageBox>
cal::cal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cal)
{
    ui->setupUi(this);
    format.setForeground(Qt::red);
}

cal::~cal()
{
    delete ui;
}


void cal::on_confirmerc_clicked()
{
    QDate date = QDate::fromString(ui->lineEditc->text(), "dd/MM/yyyy");
    if (date.isValid()) {
        ui->calendarWidget->setDateTextFormat(date, format);
        QMessageBox::information(this, "Succès", "Le jour férié a été ajouté avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "La date entrée n'est pas valide. Veuillez entrer une date valide au format dd/MM/yyyy.");
    }
}
