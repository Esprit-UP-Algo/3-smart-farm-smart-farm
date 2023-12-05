#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2AA");
db.setUserName("oussema1");//inserer nom de l'utilisateur
db.setPassword("oussema");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
