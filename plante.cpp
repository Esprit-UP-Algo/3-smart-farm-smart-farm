#include "plante.h"
#include<QString>
#include<QObject>
#include <iostream>
using namespace std;
Plante::Plante()
{
     idp=" ";
      position=" ";
      type=" ";
      saison=" ";
      duree=0;
}
Plante::Plante(QString idp,QString position,QString type,QString saison,int duree)
{
    this->idp=idp;
    this->position=position;
    this->type=type;
    this->saison=saison;
    this->duree=duree;
}
bool Plante::ajouter()
{
    bool test=false;
    QSqlQuery query;
    QString res=QString::number(duree);
    query.prepare("INSERT INTO Plante (idp,position,type,saison , duree) "
                  "VALUES (:idp ,:position,:type,:saison,:duree)");
    query.bindValue(":idp", idp);
    query.bindValue(":position", position);
    query.bindValue(":type", type);
    query.bindValue(":saison", saison);
    query.bindValue(":duree", res);
    query.exec();

    return query.exec();
}
QSqlQueryModel* Plante::afficher()
{
    QSqlQueryModel* model=new  QSqlQueryModel();

    model->setQuery("SELECT *  FROM Plante");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("position"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("saison"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("duree"));



    return model;
}
bool Plante::supprimer(QString idp)
{
QSqlQuery query;
query.prepare("Delete from Plante where idp=:idp");
query.bindValue(":idp",idp);
return query.exec();
}
