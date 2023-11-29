#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("Malek");//inserer nom de l'utilisateur
db.setPassword("esprit1");//inserer mot de passe de cet utilisateur

if (db.open()) test=true;
test=true;
    return  test;
}

void Connection::closeconnection(){
    db.close();

}
