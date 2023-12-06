#include "GestionAnimaux.h"
#include "ui_GestionAnimaux.h"
#include "animaux.h"
#include "ajouter.h"
#include "supprimeran.h"
//#include "ui_GestionAnimaux.h"

#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include<QTextTable>
#include<QTextDocument>
#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QSqlError>
#include <QPropertyAnimation>
//stat
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE
GestionAnimaux::GestionAnimaux(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionAnimaux)
{
    ui->setupUi(this);
    QString ch="select * from ANIMAUX";
   ui->tablevie->setModel(anims.afficheranim(ch));
   QLabel *label = findChild<QLabel*>("label");
   label->setMinimumWidth(300); // Augmenter la largeur minimale
   QPropertyAnimation *animation = new QPropertyAnimation(label, "geometry");
   animation->setDuration(10000);
   animation->setStartValue(label->geometry());
   animation->setEndValue(QRect(0, 0, 100, 50));
   animation->start(QAbstractAnimation::DeleteWhenStopped);
}

GestionAnimaux::~GestionAnimaux()
{
    delete ui;
}
void GestionAnimaux::on_supprimeran_clicked()
{
    supprimeran supran;
    supran.setModal(true);
    supran.exec();
     QString ch="select * from ANIMAUX";
    ui->tablevie->setModel(anims.afficheranim(ch));
}
void GestionAnimaux::on_Ajouter_clicked()
{
    ajouter ajout;
    ajout.setModal(true);
    ajout.exec();
    QString ch="select * from ANIMAUX";
   ui->tablevie->setModel(anims.afficheranim(ch));
}



void GestionAnimaux::on_affichean_clicked()
{

    QString ch="select * from ANIMAUX";
    ui->tablevie->setModel(anims.afficheranim(ch));

}

/*void GestionAnimaux::on_modifieran_clicked()
{
    modifier mod;
    mod.setModal(true);
    mod.exec();
    QString ch="select * from ANIMAUX";
    ui->tablevie->setModel(anims.afficheranim(ch));
}*/

void GestionAnimaux::on_Trieran_clicked()
{
    QString ch="select * from ANIMAUX order by ID";
     ui->tablevie->setModel(anims.afficheranim(ch));
}

void GestionAnimaux::on_pdfa_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
      if (fileName.isEmpty()) {
          return;  // L'utilisateur a annulé la boîte de dialogue
      }

      QPrinter printer(QPrinter::HighResolution);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName(fileName);

      QPainter painter;
         if (!painter.begin(&printer)) {
             // Handle the error
             QMessageBox::critical(this, "Erreur", "Erreur lors de l'ouverture du fichier PDF.");
             return;
         }

         painter.setFont(QFont("Arial", 14, QFont::Bold));
         painter.drawText(100, 100, "Liste des animaux");

      QTextDocument doc;
      QTextCursor cursor(&doc);

      // En-tête du document
      QTextCharFormat headerFormat;
      headerFormat.setFontPointSize(14);
      headerFormat.setFontWeight(QFont::Bold);
      cursor.setCharFormat(headerFormat);
      cursor.insertText("Liste des animaux\n\n");

      // Crée un tableau avec des colonnes pour chaque champ de la table
      QTextTableFormat tableFormat;
      tableFormat.setAlignment(Qt::AlignLeft);
      QTextTable *table = cursor.insertTable(1, 7, tableFormat);
      QTextCursor cellCursor;

      // Remplir les en-têtes de colonne
      cellCursor = table->cellAt(0, 0).firstCursorPosition();
      cellCursor.insertText("id");

      cellCursor = table->cellAt(0, 1).firstCursorPosition();
      cellCursor.insertText("race");

      cellCursor = table->cellAt(0, 2).firstCursorPosition();
      cellCursor.insertText("sexe");




      // Obtain the client data from your table model
      QSqlQueryModel *model = static_cast<QSqlQueryModel*>(ui->tablevie->model());

      // Fill the table data
      for (int row = 0; row < model->rowCount(); ++row) {
          table->appendRows(1);

          for (int col = 0; col < 7; ++col) {
              cellCursor = table->cellAt(row + 1, col).firstCursorPosition();
              cellCursor.insertText(model->data(model->index(row, col)).toString());
          }
      }

      QImage image("file:///C:/Users/HP/Downloads/logofinal (1).png");
         if (!image.isNull()) {
             // Adjust the size and position of the image as needed
             painter.drawImage(QRectF(100, 200, image.width(), image.height()), image);
         }

  painter.end();

      doc.print(&printer);

      // Display a success message
      QMessageBox::information(this, "Succès", "Liste des Animaux exportée sous forme de PDF.");
  }

void GestionAnimaux::afficherStatistiques() {
    QBarSeries *series = new QBarSeries();
    // Récupérer les données d'absence depuis la base de données
    QSqlQuery query;


    query.prepare("SELECT RACE, COUNT(*) AS COUNT FROM ANIMAUX GROUP BY RACE");
    if (query.exec()) {
        while (query.next()) {
            QString RACE = query.value("RACE").toString();
         int count = query.value("COUNT").toInt();
            QBarSet *RACEA = new QBarSet(RACE);
            *RACEA << count;

            series->append(RACEA);
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
    axisY->setTitleText("Statistique Race Animaux");
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
    statsWindow->resize(1000, 700);  // Remplacez 800 et 600 par les dimensions souhaitées

    // Afficher la nouvelle fenêtre
    statsWindow->show();


}



void GestionAnimaux::on_statanim_clicked()
{
afficherStatistiques();
}

void GestionAnimaux::on_recherchean_clicked()
{

        QString race=ui->lineditrech->text();
        QSqlQueryModel *model = new QSqlQueryModel();
           QSqlQuery query;
           query.prepare("SELECT  * FROM ANIMAUX WHERE RACE= :race");
           query.bindValue(":race", race);

           if (query.exec()) {

               model->setQuery(query);
               ui->tablevie->setModel(model);

           } else {
               // Gérez les erreurs de requête SQL si nécessaire.

               qDebug() << "Erreur de requête SQL : " << query.lastError().text();
           }



}
