#include "invites.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QObject>
#include <QFileInfo>
#include <QFileDialog>
//#include <QSerialPortInfo>
//#include <QSerialPort>


invites::invites()
{
    NOM_PRODUIT = "";
    ID = 0;
    quantite = 0;
    emplacement = "";
}

invites::invites(QString NOM_PRODUIT, int ID, int quantite, QString emplacement)
{
    this->NOM_PRODUIT = NOM_PRODUIT;
    this->ID = ID;
    this->quantite = quantite;
    this->emplacement = emplacement;
}

int invites::getID()
{
    return ID;
}

QString invites::getNOM_PRODUIT()
{
    return NOM_PRODUIT;
}

int invites::getquantite()
{
    return quantite;
}

void invites::setID(int ID)
{
    this->ID = ID;
}

void invites::setNOM_PRODUIT(QString NOM_PRODUIT)
{
    this->NOM_PRODUIT = NOM_PRODUIT;
}

void invites::setquantite(int quantite)
{
    this->quantite = quantite;
}

QString invites::getEmplacement()
{
    return emplacement;
}

void invites::setEmplacement(QString emplacement)
{
    this->emplacement = emplacement;
}

bool invites::ajouter()
{
    bool test = true;
    QSqlQuery query;
    query.prepare("INSERT INTO INVITES (NOM_PRODUIT, ID, QUANTITE, emplacement) "
                  "VALUES (:NOM_PRODUIT, :ID, :quantite, :emplacement)");
    query.bindValue(":NOM_PRODUIT", NOM_PRODUIT);
    query.bindValue(":ID", ID);
    query.bindValue(":quantite", quantite);
    query.bindValue(":emplacement", emplacement);

    if (!query.exec())
    {
        qDebug() << "Erreur d'insertion:" << query.lastError().text();
        test = false;
    }
    else
    {
        qDebug() << "Insertion réussie!";
    }

    return test;
}


 QSqlQueryModel* invites::afficher()
 {
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM INVITES");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("QUANITTE"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("EMPLACEMENT"));
        return model;
    }


    bool invites::supprimer(int ID){

        QSqlQuery query;

        query.prepare("Delete from INVITES where ID=:ID");

        query.bindValue(":ID",ID);

        return query.exec();

    }





    bool invites::modifier(QString NOM_PRODUIT, int ID, int quantite, QString emplacement)
    {
        QSqlQuery query;
        query.prepare("UPDATE INVITES SET NOM_PRODUIT=:NOM_PRODUIT, quantite=:quantite, emplacement=:emplacement WHERE ID=:ID");
        query.bindValue(":NOM_PRODUIT", NOM_PRODUIT);
        query.bindValue(":ID", ID);
        query.bindValue(":quantite", quantite);
        query.bindValue(":emplacement", emplacement);

        return query.exec();
    }



    QSqlQueryModel* invites::trierParNOM_PRODUIT()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM INVITES ORDER BY NOM_PRODUIT ASC");
        model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
        model->setHeaderData(1,Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(2,Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(3,Qt::Horizontal, QObject::tr("EMPLACEMENT"));



        return model;
    }

    QSqlQueryModel* invites::trierParCIN()
    {
        QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("SELECT * FROM INVITES ORDER BY ID ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMPLACEMENT"));

        return model;
    }
    void create_excel()
    {
        QString fileName = QFileDialog::getSaveFileName((QWidget*)0, "Export CSV", QString(), "*.csv");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".csv"); }

        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // write header row
            out << "ID reparation,Nom ,type , description , Id produit, telephone\n";

            QSqlQuery q;
            q.prepare("SELECT * FROM REPARATION");
            q.exec();

            while (q.next()) {
                // format row data as comma-separated values
                QString rowData = QString("%1,%2,%3,%4,%5,%6\n")
                    .arg(q.value(0).toString())
                    .arg(q.value(1).toString())
                    .arg(q.value(2).toString())
                    .arg(q.value(3).toString())
                    .arg(q.value(4).toString())
                    .arg(q.value(5).toString());

                // write row to file
                out << rowData;
            }

            file.close();
        }
    }



