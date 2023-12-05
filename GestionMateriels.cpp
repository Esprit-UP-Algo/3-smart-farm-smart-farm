#include "GestionMateriels.h"
#include "ui_GestionMateriels.h"

#include "inter_ajouter.h"
#include <QPixmap>
#include<QApplication>
#include <QMessageBox>
#include<QTableWidget>
#include <QWidgetItem>
#include<QIntValidator>
#include<QString>
#include"connection.h"
#include <QDebug>
using namespace std;
#include <iostream>
#include "supp.h"
#include "modifier.h"
#include <QPrinter>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
//stat
#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE
GestionMateriels::GestionMateriels(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionMateriels)
{
    ui->setupUi(this);
    //QPixmap pix();
     ui->tableView->setModel(Ma.afficher());
     connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(search()));

}

GestionMateriels::~GestionMateriels()
{
    delete ui;
}

void GestionMateriels::on_pushButton_clicked()
{
    inter_ajouter inter;
    inter.setModal(true);
    inter.exec();
}


void GestionMateriels::on_pushButton_sup_clicked()
{
        supp sup;
        sup.setModal(true);
        sup.exec();

}

void GestionMateriels::on_pushButton_3_clicked()
{
    ui->tableView->setModel(Ma.afficher());
}

void GestionMateriels::on_pushButton_2_clicked()
{
    modifier mo;
    mo.setModal(true);
    mo.exec();
    ui->tableView->setModel(Ma.afficher());
}


void GestionMateriels::on_pushButton_4_clicked()
{
  ui->tableView->setModel(Ma.trier());
}

void GestionMateriels::on_searchButton_clicked()
{

       QString nom=ui->search_lineEdit->text();
       QSqlQueryModel *model = new QSqlQueryModel();
       QSqlQuery query;
       query.prepare("SELECT  * FROM MATERIELS WHERE NOM = :NOM");
       query.bindValue(":NOM", nom);

       if (query.exec())
       {
           model->setQuery(query);
           ui->tableView->setModel(model);
       } else {

           qDebug() << "Erreur de requête SQL : " << query.lastError().text();
       }
}

void GestionMateriels::exportToPDF() {
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
        painter.drawText(100, 100, "Liste des materiels");

        // Dessiner l'en-tête du tableau
        painter.drawText(100, 120, "Nom");
        painter.drawText(300, 120, "ID");
        painter.drawText(400, 120, "Age");
        // Ajouter d'autres en-têtes selon vos besoins

        // Récupérer les données depuis la base de données
        QSqlQuery query;
        query.prepare("SELECT * FROM MATERIELS");
        if (query.exec()) {
            int row = 140;
            int rowCount = 0;
            while (query.next()) {
                QString nom = query.value("nom").toString();

                int id = query.value("ID").toInt();
                int age= query.value("age").toInt();
                // Ajouter d'autres colonnes selon vos besoins

                // Dessiner les données des employés
                painter.drawText(100, row, nom);
                painter.drawText(300, row, QString::number(id));
                painter.drawText(400, row, QString::number(age));
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
        QMessageBox::information(this, "Export PDF", "Les données des materiels ont été exportées avec succès vers un fichier PDF.");
}

void GestionMateriels::on_pushButton_pdf_clicked()
{
    exportToPDF();
}

void GestionMateriels::afficherStatistiques() {
    QBarSeries *series = new QBarSeries();
    // Récupérer les données d'absence depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT nom, age FROM MATERIELS");
    if (query.exec()) {
        while (query.next()) {
            QString nom = query.value("nom").toString();
            int age = query.value("age").toInt();

            QBarSet *absenceSet = new QBarSet(nom);
            *absenceSet << age;

            series->append(absenceSet);
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
    axisY->setTitleText("Nom des camions");
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



void GestionMateriels::on_pushButton_stat_clicked()
{
    afficherStatistiques();
}


