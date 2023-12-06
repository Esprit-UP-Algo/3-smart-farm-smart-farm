#include "modifieran.h"
#include "ui_modifieran.h"
#include "animaux.h"
#include "GestionAnimaux.h"
#include <QMessageBox>
modifieran::modifieran(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifieran)
{
    ui->setupUi(this);
    ui->lineEdit_idmd->setValidator(new QRegExpValidator(QRegExp("\\d+"),this));
    QRegExp rx("(mouton|vache|poulet)");
    QRegExp rx2("(f|h)");
    QRegExpValidator *validator = new QRegExpValidator(rx);
    QRegExpValidator *validator2 = new QRegExpValidator(rx2);
    ui->lineEdit_racemd->setValidator(validator);
    ui->lineEdit_sexemd->setValidator(validator2);
}

modifieran::~modifieran()
{
    delete ui;
}

void modifieran::on_modifierb_clicked()
{
    int id=ui->lineEdit_idmd->text().toInt();
    QString racea=ui->lineEdit_racemd->text();
    QString sexe=ui->lineEdit_sexemd->text();
    animaux an(id,racea,sexe);
bool test=an.modifieranim(id);
if (test)
 {   QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("modificatio avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" modification non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
