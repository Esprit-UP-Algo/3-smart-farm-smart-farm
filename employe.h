#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>

#include <QSqlQueryModel>

class employe
{
public:


    employe();
    employe(QString,QString,QString,QString,int,int);



    QString Getid_c() { return id_e; }
    void Setid_c(QString val) { id_e = val; }

    QString Getnom() { return nom; }
    void Setnom(QString val) { nom = val; }

    QString Getprenom() { return prenom; }
    void Setprenom(QString val) { prenom = val; }

    QString Getdate() { return date_naissance; }
    void Setdate(QString val) { date_naissance = val; }

    int Gettel() { return tel; }
    void Settel(int val) { tel = val; }

    int Getabsence() { return absence; }
    void Setabsence(int val) { absence= val; }


    QString id_e;
    QString nom;
    QString prenom;
    QString date_naissance;
    int tel;
    int absence;

    //crud
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString );

    QSqlQueryModel * trier(int test);

    bool numExists(const QString  &nom );
    std::string chatbotFunction(const QString &userMessage);

private:


};


#endif // EMPLOYE_H
