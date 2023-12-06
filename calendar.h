#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Calendar;
}

class Calendar : public QWidget
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Calendar *ui;
    QTextCharFormat format;
};

#endif // CALENDAR_H
