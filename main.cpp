#include "GestionMateriels.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"inter_ajouter.h"
#include "lesgestions.h"
#include "login.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionMateriels w;
    Materiels Ma;
    Connection c;
    LesGestions l;
    login log;
    qDebug();
    bool test=c.createconnect();

    if(test)
    {log.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
