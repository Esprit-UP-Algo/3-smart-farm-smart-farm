#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
#include"employe.h"
#include"connection.h"
#include <iostream>
#include <QPieSeries>
#include <QPieSlice>
#include <QChart>
#include <QChartView>
#include <QStackedWidget>
#include <QtCharts>
#include <QSqlQuery>

#include<QPrinter>
#include<QPainter>
#include<QPdfWriter>
#include<QTextTable>
#include<QTextDocument>

#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

#include <QFileDialog>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    int ret=A.connect_arduino();
    switch(ret){
    case (0) : qDebug ()<< "arduino is available"<< A.getarduino_port_name();
        break;
    case (1) : qDebug ()<< "arduino is but not"<<A.getarduino_port_name();
        break;
    case (-1) : qDebug ()<< "arduino is not";


    }
    QObject::connect(A.getserial(), SIGNAL (readyRead()),this, SLOT(update_label()));

    ui->tableView->setModel(e.afficher());

    ui->lineEdit_Date->setValidator(new QRegExpValidator(QRegExp("\\d{2}/\\d{2}/\\d{4}"),this));
    ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_Absence->setValidator(new QIntValidator(0,999,this));




}

void MainWindow::update_label()
{

    QByteArray data;
    data = A.read_from_arduino();

       if (!data.isEmpty()) {
           QString nom= A.chercher(data);
           if (!nom.isEmpty()) {
               QMessageBox::information(this, tr("Welcome"), tr("Bienvenue %1").arg(nom));
               qDebug() << "valid";
                A.write_to_arduino("0");
           }else {
               A.write_to_arduino("-1");

               QMessageBox::information(this, tr("verfication"), tr("code n existe pas"));
               qDebug() << "invalid";
           }
       } else {

       }
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
 qDebug();

    QString id_e=ui->lineEdit_CIN->text();
    QString nom=ui->lineEdit_NomEmploye->text();
    QString prenom=ui->lineEdit_PrenomEmploye->text();
    QString date_naissance=ui->lineEdit_Date->text();
    int tel=ui->lineEdit_Numtel->text().toInt();
    int absence=ui->lineEdit_Absence->text().toInt();




     employe e(id_e, nom, prenom, date_naissance, tel, absence);

bool test=e.ajouter();
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



void MainWindow::on_pushButton_supp_clicked()
{
    QString id_e=ui->lineEdit_Supp->text();
    bool test=e.supprimer(id_e);
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



void MainWindow::on_affichem_clicked()
{

    ui->tableView->setModel(e.afficher());
}

void MainWindow::on_pushButton_modifier_clicked()
{
    qDebug();
    QString id_e=ui->lineEdit_CIN->text();
    QString nom=ui->lineEdit_NomEmploye->text();
    QString prenom=ui->lineEdit_PrenomEmploye->text();
    QString date_naissance=ui->lineEdit_Date->text();
    int tel=ui->lineEdit_Numtel->text().toInt();
    int absence=ui->lineEdit_Absence->text().toInt();




     employe e(id_e, nom, prenom, date_naissance, tel, absence);

    bool test=e.modifier(id_e);
    if (test){ ui->tableView->setModel(e.afficher());
    QMessageBox::information(nullptr, QObject::tr("ok"), QObject::tr("update avec success.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
   else
   QMessageBox::critical(nullptr, QObject::tr("not ok"), QObject::tr(" update non effectué.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_recher_clicked()

{

    QString nom=ui->lineEdit_Id->text(); // Récupérez le numéro de livraison entré par l'utilisateur.

    // Créez un modèle de requête SQL pour afficher la livraison recherchée.
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT  * FROM EMPLOYEE WHERE NOM = :NOM");
    query.bindValue(":NOM", nom);

    if (query.exec()) {
        model->setQuery(query);
        ui->tableView->setModel(model);

    } else {
        // Gérez les erreurs de requête SQL si nécessaire.
        qDebug() << "Erreur de requête SQL : " << query.lastError().text();
    }


}



/*void MainWindow::on_pb_trier_clicked()
{
    QSqlQueryModel *sortedModel = e.trier(2);
    ui->tableView->setModel(sortedModel);
}

*/


void MainWindow::afficherStatistiques() {
    // Récupérer les données d'absence depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT nom, absence FROM EMPLOYEE");
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête SQL : " << query.lastError().text();
        // Gérez l'erreur de la requête SQL ici
        return;
    }

    QBarSeries *series = new QBarSeries();

    while (query.next()) {
        QString nom = query.value("nom").toString();
        int absence = query.value("absence").toInt();

        QBarSet *absenceSet = new QBarSet(nom);
        *absenceSet << absence;

        series->append(absenceSet);
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
    axisY->setTitleText("Nombre d'absences");
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
    closeButton->setStyleSheet("background-color: green; color: white;");  // Changer la couleur du fond et du texte
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




void MainWindow::on_pb_stat_clicked()
{
    afficherStatistiques();
}
void MainWindow::on_pb_pdf_clicked()
{  QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) {
        return;  // L'utilisateur a annulé la boîte de dialogue
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QTextCursor cursor(&doc);

    // En-tête du document
    QTextCharFormat headerFormat;
    headerFormat.setFontPointSize(14);
    headerFormat.setFontWeight(QFont::Bold);
    cursor.setCharFormat(headerFormat);
    cursor.insertText("Liste des livraisons\n\n");

    // Crée un tableau avec des colonnes pour chaque champ de la table
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignLeft);
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);
    QTextCursor cellCursor;

    // Remplir les en-têtes de colonne
    cellCursor = table->cellAt(0, 0).firstCursorPosition();
    cellCursor.insertText("Numéro du livraison");

    cellCursor = table->cellAt(0, 1).firstCursorPosition();
    cellCursor.insertText("Etat");

    cellCursor = table->cellAt(0, 2).firstCursorPosition();
    cellCursor.insertText("Date");

    cellCursor = table->cellAt(0, 3).firstCursorPosition();
    cellCursor.insertText("Adresse");



    // Obtain the client data from your table model
    QSqlQueryModel *model = static_cast<QSqlQueryModel*>(ui->tableView->model());

    // Fill the table data
    for (int row = 0; row < model->rowCount(); ++row) {
        table->appendRows(1);

        for (int col = 0; col < 7; ++col) {
            cellCursor = table->cellAt(row + 1, col).firstCursorPosition();
            cellCursor.insertText(model->data(model->index(row, col)).toString());
        }
    }

    doc.print(&printer);

    // Display a success message
    QMessageBox::information(this, "Succès", "Liste des livraisons exportée sous forme de PDF.");
}







/*void MainWindow::on_envoyer_clicked()
{
    int senderId = ui->lineEdit_senderId->text().toInt();
        int receiverId = ui->lineEdit_receiverId->text().toInt();
        QString message = ui->lineEdit_message->text();

        if (MessagingSystem.sendMessage(senderId, receiverId, message)) {
            // Message envoyé avec succès, effectuez des actions supplémentaires si nécessaire
            // Effacer les line edits ou afficher un message de succès, etc.
            ui->lineEdit_senderId->clear();
            ui->lineEdit_receiverId->clear();
            ui->lineEdit_message->clear();
        } else {
            // Gérer le cas où le message n'a pas pu être envoyé
            // Afficher un message d'erreur, journaliser l'erreur, etc.
        }
}
*/


void MainWindow::on_radioButton_NOM_clicked()
{
    QSqlQueryModel *sortedModel = e.trier(2);
    ui->tableView->setModel(sortedModel);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{

}

void MainWindow::on_radioButton_2_clicked()
{
    QSqlQueryModel *sortedModel = e.trier(3);
    ui->tableView->setModel(sortedModel);
}

void MainWindow::on_pushButton_tentative_clicked()
{
    QSqlQuery query;
    query.exec("SELECT NBRENTREE FROM RESPONSABLEA");

    QString data;
    if(query.next()){
        QString nbrentree=query.value(0).toString();
        data="NBRENTREE:" + nbrentree;

    }
    QMessageBox::information(this,tr("NBRENTREE"),data);

}
/*void MainWindow::readFromArduino() {
    QByteArray data = A.read_from_arduino();
    // Check if the received data is the "correct PIN" signal
    if (data == "1") {
        // If the correct PIN was entered, increment NBRENTREE in the database
        incrementNbreEntree();

        // Get the new value of NBRENTREE
        QString nbreEntree = getnbreEntreeData();

        // Display the new value of NBRENTREE
        QMessageBox::information(this, tr("NBRENTREE"), nbreEntree);
    }
}*/
void MainWindow::incrementNbreEntree() {
    QSqlQuery query;
    query.exec("UPDATE responsablea SET NBRENTREE = NBRENTREE + 1");
}
QString MainWindow::getnbreEntreeData() {
    QSqlQuery query;
    query.exec("SELECT NBRENTREE FROM responsablea");

    QString data;
    if (query.next()) {
        QString nbreEntree = query.value(0).toString();
        data = "NBRENTREE: " + nbreEntree;
    }

    return data;
}
