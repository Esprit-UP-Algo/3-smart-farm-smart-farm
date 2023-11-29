#ifndef LOGIN_H
#define LOGIN_H
#include "plante.h"
#include <QDialog>
#include<QString>
#include <QSqlQuery>
#include <QObject>
#include <QMainWindow>
#include <QSqlError>
#include<QSqlQueryModel>
#include<QDebug>
#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include"mainwindow.h"
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
private slots :
    void authentification();
    void on_pushButton_clicked();
    QSerialPort* getserial();
    void update_label();
    //int *write_to_arduino(const char * msg);
private:
Ui:: login *ui;
Arduino A;
};

#endif // LOGIN_H

