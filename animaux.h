#ifndef ANIMAUX_H
#define ANIMAUX_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
class animauxData;

class animaux
{
    QString racea,sexea,vaccin,medic,regimali,dateanim;
    int poids,idanim,visitvet,norriture;
public:
    animaux();
    //animaux(int  ,QString ,QString ,int ,QString ,QString ,int ,QString ,QString , int );
    animaux(int,QString,QString);

                                       //date



    //getters
    int getIdanim(){return idanim;}
    QString getRacea(){return racea;}
    QString getSexea(){return sexea;}
    QString getvaccin(){return vaccin;}
    QString getMEdic(){return medic;}
    QString getRegimali(){return regimali;}
    int getPoids(){return poids;}
    int getVisitvet(){return visitvet;}
    QString getDateanim(){return dateanim;}
    int getNorriture(){return norriture;}


    //setters
    void setIdanim(int ida){idanim=ida;}
    void setRacea(QString race){racea=race;}
    void setSexea(QString sexe){sexea=sexe;}
    void setvaccin(QString vacc){vaccin=vacc;}
    void setMEdic(QString med){medic=med;}
    void setRegimali(QString regim){regimali=regim;}
    void setDateanim(QString datea){dateanim=datea;}
    void setPoids(int poi){poids=poi;}
    void setVisitvet(int visit){visitvet=visit;}
    void setNorriture(int norrit){norriture=norrit;}
    //les fonctions
    bool ajouteranim();
    QSqlQueryModel * afficheranim();
    bool supprimeranim(int);

};

#endif // ANIMAUX_H
