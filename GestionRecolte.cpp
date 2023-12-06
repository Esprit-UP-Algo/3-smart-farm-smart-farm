#include "GestionRecolte.h"
#include "ui_GestionRecolte.h"
#include "invites.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QSqlError>
//#include <QAxObject>
#include <QTextStreamManipulator>
//#include "arduino.h"
#include <QPrinter>
#include <QSqlQuery>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QSqlError>
//#include <QAxObject>
#include <QTextStreamManipulator>
#include <QFile>
#include <invites.h>


#include <QMainWindow>
QT_CHARTS_USE_NAMESPACE

GestionRecolte::GestionRecolte(QWidget *parent) : QMainWindow(parent), ui(new Ui::GestionRecolte)
{
    ui->setupUi(this);
}


    // Your initialization code...
/*
    arduino = new Arduino(this);

    // Connect to Arduino (change portName as needed)
    if (arduino->connectToArduino("COM4")) {
        connect(arduino, &Arduino::distanceChanged, this, &GestionRecolte::handleDistanceChanged);



    }
}

*
*
*/
/*
void GestionRecolte::handleDistanceChanged(int distance)
{
    // Do something with the distance received from Arduino
    ui->abcd->setText("Distance: " + QString::number(distance) + " cm");
    ui->abcde->setText( QString::number(distance) );
}*/
GestionRecolte::~GestionRecolte()
{
    // Destructor implementation

}
void GestionRecolte::on_Ajouter_clicked()
{
    QString NOM_PRODUIT = ui->NOM_PRODUIT->text();
    int ID = ui->CIN->text().toInt();  // Modifier la variable
    int Numero = ui->Numero->text().toInt();
    QString emplacement = ui->Metier->text();  // Modifier la variable

    invites i(NOM_PRODUIT, ID, Numero, emplacement);  // Modifier les arguments

    bool test = i.ajouter();

    if (test) {
        ui->table->setModel(i.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Ajout successful.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
            QObject::tr("Ajout failed.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void GestionRecolte::on_Supprimer_clicked()
{
    invites i1;
    i1.setID(ui->CIN->text().toInt());  // Modifier la variable

    bool test = i1.supprimer(i1.getID());  // Modifier l'argument

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Delete successful.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->table->setModel(i.afficher());
    } else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
            QObject::tr("Delete failed.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void GestionRecolte::on_Modifier_clicked()
{
    invites i3;
    QString NOM_PRODUIT = ui->NOM_PRODUIT->text();
    int ID = ui->CIN->text().toInt();  // Modifier la variable
    int Numero = ui->Numero->text().toInt();
    QString emplacement = ui->Metier->text();  // Modifier la variable

    bool test = i3.modifier(NOM_PRODUIT, ID, Numero, emplacement);  // Modifier les arguments

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("modifier successful.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->table->setModel(i.afficher());
    } else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
            QObject::tr("modifier failed.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}





void GestionRecolte::on_radioButton_2_toggled(bool checked)
{
    if (checked == true){
                       ui->table->setModel(i.trierParCIN());
                   } else {
                        ui->table->setModel(i.afficher());
                   }
}

void GestionRecolte::on_radioButton_toggled(bool checked)
{
    if (checked == true){
                       ui->table->setModel(i.trierParNOM_PRODUIT());
                   } else {
                        ui->table->setModel(i.afficher());
                   }
}


void GestionRecolte::exportToPDF()
{
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
    painter.drawText(100, 100, "5EDMET oussema");

    // Dessiner l'en-tête du tableau
    painter.drawText(100, 120, "NOM_PRODUIT");
    painter.drawText(200, 120, "ID");
    painter.drawText(300, 120, "QUANTITE");
    painter.drawText(400, 120, "EMPLACEMENT");

    // Récupérer les données depuis le modèle associé au QTableView (supposons que votre QTableView s'appelle 'tableView')
    QAbstractItemModel* model = ui->table->model();

    if (model) {
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();

        int row = 140;

        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < columnCount; ++j) {
                // Get data from the model
                QVariant data = model->index(i, j).data();

                // Dessiner les données dans le fichier PDF
                painter.drawText(100 + j * 100, row, data.toString());

                // Ajouter d'autres colonnes selon vos besoins
            }

            row += 20; // Augmenter la position Y pour la prochaine ligne

            // Passer à une nouvelle page après un certain nombre de lignes (par exemple, 20 lignes)
            if (i % 20 == 0 && i != 0) {
                printer.newPage();
                row = 100; // Réinitialiser la position Y pour la nouvelle page
            }
        }
    }

    // Terminer le dessin sur la page
    painter.end();

    // Afficher un message de succès
    QMessageBox::information(this, "Export PDF", "Les données ont été exportées avec succès vers un fichier PDF.");
}







void GestionRecolte::on_pushButton_clicked()
{
    exportToPDF();
}


void GestionRecolte :: afficherStatistiques()
{
    QBarSeries *series = new QBarSeries();

    // Récupérer les données d'absence depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT EMPLACEMENT, QUANTITE FROM INVITES");
    if (query.exec()) {
        while (query.next()) {
            QString EMPLACEMENT= query.value("EMPLACEMENT").toString();
            int QUANTITE = query.value("QUANTITE").toInt();

            QBarSet *QUANTITESet = new QBarSet(EMPLACEMENT);
            *QUANTITESet << QUANTITE;

            series->append(QUANTITESet);
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
    axisY->setTitleText("QUANTITE DE STOCK");
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

void GestionRecolte::on_pushButton_2_clicked()
{
     afficherStatistiques();
}
void GestionRecolte::on_aziz_clicked()

{

    QString NOM_PRODUIT=ui->aziza->text(); // Récupérez le numéro de livraison entré par l'utilisateur.

    // Créez un modèle de requête SQL pour afficher la livraison recherchée.
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT  * FROM invites WHERE NOM_PRODUIT = :NOM_PRODUIT");
    query.bindValue(":NOM_PRODUIT", NOM_PRODUIT);

    if (query.exec()) {
       model->setQuery(query);
        ui->table->setModel(model);

    } else {
        // Gérez les erreurs de requête SQL si nécessaire.
        qDebug() << "Erreur de requête SQL : " << query.lastError().text();
    }


}





void GestionRecolte::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget*)0, "Export CSV", QString(), "*.csv");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".csv"); }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        // Set field alignment to right-align
        out.setFieldAlignment(QTextStream::AlignRight);

        // Set the field width for each column
        out.setFieldWidth(15);

        // write header row
        out << "NOM_PRODUIT" << "ID" << "quantite" << "emplacement" << "\n";

        QSqlQuery q;
        q.prepare("SELECT * FROM INVITES");
        q.exec();

        while (q.next()) {
            // format row data
            out << q.value(0).toString() << q.value(1).toString() << q.value(2).toString() << q.value(3).toString() << "\n";
        }

        file.close();
    }





    }





void GestionRecolte::on_abc_linkActivated(const QString &link)
{

}

