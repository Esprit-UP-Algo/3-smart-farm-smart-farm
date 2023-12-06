#ifndef cal_H
#define cal_H

#include <QWidget>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>
namespace Ui {
class cal;
}

class cal : public QDialog
{
    Q_OBJECT

public:
    explicit cal(QWidget *parent = nullptr);
    ~cal();

private slots:
    void on_confirmerc_clicked();

private:
    Ui::cal *ui;
    QTextCharFormat format;
};

#endif // cal_H
