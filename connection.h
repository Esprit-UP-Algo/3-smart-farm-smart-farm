#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closecConnection();
};

#endif // CONNECTION_H
