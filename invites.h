#ifndef INVITES_H
#define INVITES_H
#include<QString>
#include<QSqlQueryModel>
#include <QSerialPort>



class invites
{
public:
    invites();
        invites(QString, int, int, QString);
        int getID();  // Modifier le nom de la méthode
        QString getNOM_PRODUIT();  // Modifier le nom de la méthode
        int getquantite();  // Conserve le nom actuel
        void setID(int);  // Modifier le nom de la méthode
        void setNOM_PRODUIT(QString);  // Modifier le nom de la méthode
        void setquantite(int);  // Conserve le nom actuel
        QString getEmplacement();  // Modifier le nom de la méthode
        void setEmplacement(QString);  // Modifier le nom de la méthode
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool modifier(QString,int,int,QString);
        QSqlQueryModel *trierParCIN();
        QSqlQueryModel *trierParNOM_PRODUIT();



private:
        QString NOM_PRODUIT,emplacement;
        int ID, quantite;


};

#endif // INVITES_H
