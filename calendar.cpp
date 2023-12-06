#include "Calendar.h"
#include "ui_calenderier.h"

calenderier::calenderier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calenderier)
{
    ui->setupUi(this);
}

calenderier::~calenderier()
{
    delete ui;
}
