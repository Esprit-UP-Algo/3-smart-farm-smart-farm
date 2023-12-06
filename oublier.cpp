#include "oublier.h"
#include "ui_oublier.h"
#include <QMessageBox>
#include <QMainWindow>
#include "mainwindow.h"
#include "plante.h"

oublier::oublier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::oublier)
{
    ui->setupUi(this);

    connect(ui->pushButton_valider, &QPushButton::clicked, this, &oublier::on_pushButton_valider_clicked);
}

oublier::~oublier()
{
    delete ui;
}

void oublier::on_pushButton_valider_clicked()
{
    Plante p; ///employe mbaad
    //QString reponseQ = ui->lineEdit_q->text().toLower();
    QString reponseQq = ui->lineEdit_qq->text();
    QSqlQuery query;

    if ( (reponseQq == "emna" && !reponseQq.isEmpty())
       ||( reponseQq == "selim" && !reponseQq.isEmpty()) )
    {
        // Récupérer le mot de passe à partir de la base de données ou utiliser une valeur prédéfinie
        QString motDePasse = "smartfarm";
        emit passwordRecovered(motDePasse);
        query.prepare("UPDATE Plante SET position='smartfarm' WHERE IDP='emna' ");
        query.prepare("UPDATE Plante SET position='smartfarm' WHERE IDP='selim' ");
        query.exec();
        QMessageBox::information(nullptr, QObject::tr("Réinitialisation du mot de passe"),
                                 QObject::tr("Votre mot de passe est : %1").arg(motDePasse),
                                 QMessageBox::Ok);
        this->close();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Réponse incorrecte. Veuillez vérifier vos informations."),
                              QMessageBox::Ok);
    }

}
