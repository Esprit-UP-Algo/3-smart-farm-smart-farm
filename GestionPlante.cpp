#include "GestionPlante.h"
#include "ui_mainwindow.h"
#include"plante.h"
#include<QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
#include"connection.h"
#include <iostream>
#include <QPrinter>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE
GestionPlante::GestionPlante(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionPlante)
{
    ui->setupUi(this);
   ui->tableView->setModel(p.afficher());
   //ui->lineEdit->setValidator(new QRegExpValidator (QRegExp("\\d+"),this));
}

GestionPlante::~GestionPlante()
{
    delete ui;
}

void GestionPlante::on_pb_ajouter_clicked()
{
    qDebug();
    QString idp=ui->le_id->text();
    QString position =ui->le_pos->text();
     QString type=ui->le_type->text();
     QString saison =ui->le_saison->text();
     int duree =ui->lineEdit->text().toInt();

 Plante p(idp ,position,type,saison,duree);
 bool test=p.ajouter();
 if (test){
     QMessageBox::information(nullptr, QObject::tr("ok"),
                 QObject::tr("ajout avec success.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

 }
 else
     QMessageBox::critical(nullptr, QObject::tr("not ok"),
                 QObject::tr(" ajout non effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}

void GestionPlante::on_pushButton_supp_clicked()
{
    QString idp=ui->lineEdit_9->text();
bool test=p.supprimer(idp);
if (test)
 {   QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("suppression avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" suppression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void GestionPlante::on_pb_ajouter_2_clicked()
{
    qDebug();
       QString idp=ui->le_id->text();
       QString position =ui->le_pos->text();
        QString type=ui->le_type->text();
        QString saison =ui->le_saison->text();
        int duree =ui->lineEdit->text().toInt();

    Plante p(idp ,position,type,saison,duree);
    bool test=p.modifier(idp);
    if (test){ ui->tableView->setModel(p.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"), QObject::tr("update avec success.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
   else
   QMessageBox::critical(nullptr, QObject::tr("not ok"), QObject::tr(" update non effectué.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void GestionPlante::on_rechercher_clicked()

    {
        Plante plante;
        // Récupérez les critères de recherche depuis votre interface utilisateur

            QString idp= ui->le_rechercher_2->text();

            // Appelez la fonction de recherche dans la classe Commande
            QSqlQueryModel *result = plante.rechercher(idp);

            // Mettez à jour le modèle de données de votre widget d'affichage, par exemple un tableau
            ui->tableView->setModel(result);
    }








void GestionPlante::exportToPDF()
{
    /*
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

        if (filePath.isEmpty()) {
            // L'utilisateur a annulé la sélection du fichier
            return;
        }

        // Créer un objet QPrinter
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);

        // Créer un objet QPainter qui dessinera sur le QPrinter
        QPainter painter(&printer);

        // Commencer le dessin sur la page
        painter.begin(&printer);

        // Définir la taille de la page
        printer.setPageSize(QPrinter::A4);

        // Définir la police et la taille du texte
        painter.setFont(QFont("Arial", 12));

        // Dessiner le titre
        painter.drawText(100, 100, "Liste des plantes");

        // Dessiner l'en-tête du tableau
        painter.drawText(100, 120, "idp");
        painter.drawText(200, 120, "position");
        painter.drawText(300, 120, "type");
        painter.drawText(400, 120, "Saison");
        painter.drawText(500, 120, "duree");
        // Ajouter d'autres en-têtes selon vos besoins

        // Récupérer les données depuis la base de données
        QSqlQuery query;
        query.prepare("SELECT * FROM Plante");
        if (query.exec()) {
            int row = 140;
            int rowCount = 0;
            while (query.next()) {
                QString idp = query.value("idp").toString();
                QString position = query.value("position").toString();
                QString type = query.value("type").toString();
                QString saison = query.value("saison").toString();
                int duree= query.value("duree").toInt();
                // Ajouter d'autres colonnes selon vos besoins

                // Dessiner les données des employés
                painter.drawText(100, row, idp);
                painter.drawText(200, row, position);
                painter.drawText(300, row, type);
                painter.drawText(400, row, saison);
                painter.drawText(500, row, QString::number(duree));
                // Ajouter d'autres colonnes selon vos besoins

                row += 20; // Augmenter la position Y pour la prochaine ligne
                rowCount++;

                // Passer à une nouvelle page après un certain nombre de lignes (par exemple, 20 lignes)
                if (rowCount % 20 == 0) {
                    printer.newPage();
                    row = 100; // Réinitialiser la position Y pour la nouvelle page
                }
            }
        } else {
            // Gestion de l'erreur de la requête
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'exécution de la requête SQL : " + query.lastError().text());
        }

        // Terminer le dessin sur la page
        painter.end();

        // Afficher un message de succès
        QMessageBox::information(this, "Export PDF", "Les données des employés ont été exportées avec succès vers un fichier PDF.");

*/}




void GestionPlante::on_pushButton_2_clicked()
{
    exportToPDF();
}



void GestionPlante:: afficherStatistiques()
{
    QBarSeries *series = new QBarSeries();

    // Récupérer les données d'absence depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT idp, duree FROM Plante");
    if (query.exec()) {
        while (query.next()) {
            QString idp = query.value("idp").toString();
            int duree = query.value("duree").toInt();

            QBarSet *dureeSet = new QBarSet(idp);
            *dureeSet << duree;

            series->append(dureeSet);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête SQL : " << query.lastError().text();
        // Gérez l'erreur de la requête SQL ici
        return;
    }

    // Créer le graphique et y ajouter la série
    QChart *chart = new QChart();
    chart->addSeries(series);

    // Créer l'axe X et définir le titre
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Créer l'axe Y et définir le titre
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("duree de croissance");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer une nouvelle fenêtre pour afficher le graphique
    QMainWindow *statsWindow = new QMainWindow();
    statsWindow->setCentralWidget(chartView);

    // Ajouter un bouton de fermeture
    QPushButton *closeButton = new QPushButton("Fermer", statsWindow);
    QObject::connect(closeButton, &QPushButton::clicked, statsWindow, &QMainWindow::close);

    // Créer un layout pour organiser le bouton
    QVBoxLayout *layout = new QVBoxLayout(statsWindow);
    layout->addWidget(chartView);
    layout->addWidget(closeButton);

    // Ajuster la taille de la fenêtre
    statsWindow->resize(800, 600);  // Remplacez 800 et 600 par les dimensions souhaitées

    // Afficher la nouvelle fenêtre
    statsWindow->show();
}
void GestionPlante::on_pushButton_3_clicked()
{
        afficherStatistiques();
}



void GestionPlante::on_radioButton_clicked()
{
    QSqlQueryModel * sortedModel =p.trier(1);
    ui->tableView->setModel(sortedModel);
}

void GestionPlante::on_radioButton_2_clicked()
{
    QSqlQueryModel * sortedModel =p.trier(2);
    ui->tableView->setModel(sortedModel);
}
