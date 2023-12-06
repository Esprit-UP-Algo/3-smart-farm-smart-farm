#include "animaux.h"
#include "GestionAnimaux.h"
animaux::animaux(){
    idanim=0;
    sexea="R";
    racea="R";
}
animaux::animaux(int idanim ,QString racea,QString sexea){
    this->idanim=idanim;
     this->racea=racea;
     this->sexea=sexea;
  }

bool animaux::ajouteranim(){
     QSqlQuery query;
     QString res = QString::number(idanim);
     query.prepare("insert into ANIMAUX (ID, RACE, SEXE)" "values (:idanim, :racea, :sexea)");
     query.bindValue(":idanim",idanim);
     query.bindValue(":racea",racea);
     query.bindValue(":sexea",sexea);
     return query.exec();
}
QSqlQueryModel * animaux::afficheranim(QString ch){
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery(ch);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("race"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("sexe"));
return model;

}
bool animaux::supprimeranim(int id){
QSqlQuery query;
QString res=QString::number(id);
query.prepare("Delete from ANIMAUX where ID= :id");
query.bindValue(":id",res);
return query.exec();
}
bool animaux::modifieranim(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("update animaux set RACE=:racea, SEXE=:sexea where ID=:id");
    query.bindValue(":racea",racea);
    query.bindValue(":sexea",sexea);
    query.bindValue(":id",res);
    return query.exec();
}
