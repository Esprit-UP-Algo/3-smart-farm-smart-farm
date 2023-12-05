#ifndef CONNEXION_H
#define CONNEXION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNEXION_H
