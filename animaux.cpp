#include "animaux.h"
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
     query.prepare("insert into ANIMAUX (ID=:idanim, RACE=:racea, SEXE=:sexea)");
     query.bindValue(":idanim",idanim);
     query.bindValue(":race",racea);
     query.bindValue(":sexea",sexea);
     return query.exec();
}
QSqlQueryModel * animaux::afficheranim(){
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from ANIMAUX");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("race"));
model->setHeaderData(0,Qt::Horizontal,QObject::tr("sexe"));
return model;

}
bool animaux::supprimeranim(int id){
QSqlQuery query;
QString res=QString::number(id);
query.prepare("Delete from ANIMAUX where ID= :id");
query.bindValue(":id",res);
return query.exec();
}
