#include "employe.h"
#include <QSqlQuery>
#include<QString>
#include<QObject>
#include <iostream>
#include <QMessageBox>
using namespace std;



employe::employe(){

    id_e=" ";
    date_naissance=" ";
    nom=" ";
    prenom=" ";
    tel=0;
    absence=0;

}
employe::employe(QString id_e,QString nom,QString prenom,QString date,int tel, int absence){

    this->id_e=id_e;
    this->nom=nom;
    this->prenom=prenom;
    this->date_naissance=date;
    this->tel=tel;
    this->absence=absence;

}
bool employe::ajouter(){
    QSqlQuery query;
    QString res = QString::number(tel);
    QString res2 = QString::number(absence);

    query.prepare("insert into employee (ID_E , NOM , PRENOM , DATE_NAISSANCE, TEL, ABSENCE) "
                  "values (:id_e , :nom, :prenom , :date, :tel, :absence)");
query.bindValue(":id_e",id_e);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":date",date_naissance);
query.bindValue(":tel",res);
query.bindValue(":absence",res2);



return query.exec();

}



bool employe::modifier(QString id_e)
 {
 QSqlQuery query;
 query.prepare("UPDATE EMPLOYEE SET ID_E=:ID_E , NOM=:NOM , PRENOM= :PRENOM , DATE_NAISSANCE=:DATE_NAISSANCE, TEL=:TEL, ABSENCE=:ABSENCE WHERE ID_E=:ID_E");
 query.bindValue(":id_e",id_e);
 query.bindValue(":nom",nom);
 query.bindValue(":prenom",prenom);
 query.bindValue(":date",date_naissance);
 query.bindValue(":tel",tel);
 query.bindValue(":absence",absence);

 query.exec();
return query.exec();
 }



bool employe::supprimer(QString id_e){
QSqlQuery query;
query.prepare("Delete from EMPLOYEE where id_e=:id_e");
query.bindValue(":id_e",id_e);
return query.exec();
}
QSqlQueryModel * employe::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from EMPLOYEE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_e"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("absence"));


return model;
}

std::string employe::chatbotFunction(const QString &userMessage)
{
std::string lowerMessage = userMessage.toStdString();
std::transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);

    if (lowerMessage.find("bonjour") != std::string::npos) {
        return "Salut! Comment puis-je vous aider aujourd'hui?";
    } else if (lowerMessage.find("comment ça va?") != std::string::npos) {
        return "Je suis un programme, donc je n'ai pas de sentiments, mais merci de demander!";
    } else if (lowerMessage.find("quel est ton nom?") != std::string::npos) {
        return "Je suis un chatbot créé par OpenAI.";
    } else if (lowerMessage.find("au revoir") != std::string::npos) {
        return "Au revoir! N'hésitez pas à revenir si vous avez d'autres questions.";
    } else {
        return "Désolé, je ne comprends pas. Pouvez-vous reformuler votre question?";
    }
    return  "Reponse du chatbot";
}





QSqlQueryModel * employe::trier(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;

    if(test==1)
    {
        query.prepare("SELECT *  FROM EMPLOYEE ORDER BY DATE_N ASC ") ;
    }
    else if(test==2)
    {
        query.prepare("SELECT *  FROM EMPLOYEE ORDER BY NOM ASC ") ;
    }
    else if(test==3)
    {
        query.prepare("SELECT *  FROM EMPLOYEE ORDER BY PRENOM ASC ") ;
    }

    if (query.exec()&&query.next())
    {
        model->setQuery(query) ;
    }
    return model;

}


