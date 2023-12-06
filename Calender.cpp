#include "calendar.h"
#include "ui_calendar.h"
#include <QDate>

Calendar::Calendar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calendar)
{
    ui->setupUi(this);
    format.setForeground(Qt::red);
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::on_pu_clicked()
{
    QDate date = QDate::fromString(ui->lineEdit->text(), "dd/MM/yyyy");
    if (date.isValid()) {
        ui->calendarWidget->setDateTextFormat(date, format);
    }
}
