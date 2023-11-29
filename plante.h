#ifndef PLANTE_H
#define PLANTE_H
#include<QString>
#include <QSqlQuery>
#include <QObject>
#include<QSqlQueryModel>
#include<iostream>
using namespace std;
#include <QString>

class Plante
{public:
    Plante();
    Plante(QString ,QString ,QString ,QString ,int);
    //virtual ~Plante();
    QString idp;
    QString position;
    QString type;
    QString saison;
     int duree;
    QString Getidp() { return idp; }
    void Setidp(QString val) { idp = val; }
   QString Getposition() { return position; }
    void Setposition(QString val) { position = val; }
   QString Gettype() { return type; }
    void Settype(QString val) { type = val; }
   QString Getsaison() { return saison; }
    void Setsaison(QString val) { saison = val; }
    int Getduree() { return duree; }
    void Setduree(int val) { duree = val; }

    //crud//

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString );
    QSqlQueryModel * rechercher(QString );
    QSqlQueryModel * trier(int);
void exportToPDF();

protected:

private:


};

#endif // PLANTE_H
