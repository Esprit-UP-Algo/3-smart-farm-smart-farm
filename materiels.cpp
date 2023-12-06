#include "materiels.h"
#include <QString>
#include <iostream>
Materiels::Materiels()
{
    nom=" ";
    age=0;
    id=0;
}
Materiels::Materiels(QString nom, int age, int id)
{
    this->id=id;
    this->nom=nom;
    this->age=age;
}
QString Materiels::getnom(){return nom;}
int Materiels::getid(){return id;}
int Materiels::getage(){return age;}
void Materiels::setnom(QString nom){this->nom=nom;}
void Materiels::setid(int id){this->id=id;}
void Materiels::setage(int age){this->age=age;}

bool Materiels::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString ag=QString::number(age);
    query.prepare("insert into Materiels (nom,id,age)" "values(:nom, :id, :age)");
    query.bindValue(":nom",nom);
    query.bindValue(":id",res);
    query.bindValue(":age",ag);
    return query.exec();
}
QSqlQueryModel * Materiels::afficher()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery("Select * from Materiels");
     model->setHeaderData(0,Qt::Horizontal, QObject ::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal, QObject ::tr("ID"));
    model->setHeaderData(2,Qt::Horizontal, QObject ::tr("age"));
    return model;
}
bool Materiels::supprimer (int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from Materiels where id= :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool Materiels::modifier(int id)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    QString a=QString::number(age);
    query.prepare("update Materiels set nom=:nom, age=:ag where ID=:ID");
    query.bindValue(":nom",nom);
    query.bindValue(":ag",a);
    query.bindValue(":id",id);
    return query.exec();
}
QSqlQueryModel * Materiels::trier()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery("Select * from Materiels order by ID ");
     model->setHeaderData(0,Qt::Horizontal, QObject ::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal, QObject ::tr("ID"));
    model->setHeaderData(2,Qt::Horizontal, QObject ::tr("age"));
    return model;
}

QSqlQueryModel * Materiels:: recherche(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATERIELS WHERE idp LIKE '"+id+"'  ");
    return model;
}
