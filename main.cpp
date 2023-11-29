#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"login.h"
#include<QDebug>
#include<iostream>
using namespace std;
#include <QApplication>
#include "plante.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Plante p;
    qDebug();

    Connection c;


    bool test=c.createconnect();
    MainWindow w;
     login l;
     l.show();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    //l.authentification();
    return a.exec();
}
