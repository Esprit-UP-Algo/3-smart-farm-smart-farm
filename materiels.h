#ifndef MATERIELS_H
#define MATERIELS_H
#include <QSqlQuery>
#include <QString>
#include<QSqlQueryModel>
class Materiels
{
public:
    Materiels();
    Materiels(QString, int, int);
    QString getnom();
    int getid();
    int getage();
    void setnom(QString);
    void setid(int);
    void setage(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);

private:
    QString nom;
    int id,age;
    //int date;



};

#endif // MATERIELS_H
