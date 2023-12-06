#include "login.h"
#include "ui_login.h"
#include"GestionPlante.h"
#include <QMessageBox>
#include "plante.h"
#include<QDebug>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
}

login::~login()
{
    delete ui;
}
void login::authentification(){
    Plante p;
        QString idp= ui->id->text();
        QString position = ui->pwd->text();
        Arduino arduino; // Instantiate the Arduino object
         QByteArray arduinoData = arduino.read_from_arduino();
                    // Check if data is received from Arduino
        QSqlQuery query;
        query.prepare("SELECT * FROM Plante WHERE idp=:idp AND position=:position");
        query.bindValue(":idp",idp);
         query.bindValue(":position",position);

        if (query.exec() && query.next() ) {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("login avec success.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            this->hide();
                   MainWindow *auth = new MainWindow ;
                   auth->show();

        }

         if (!arduinoData.isEmpty())
         {
          QMessageBox::information(nullptr, QObject::tr("ok"),
          QObject::tr("Data received from Arduino.\nClick Cancel to exit."),QMessageBox::Cancel);
          this->hide();
          MainWindow* auth = new MainWindow;
             auth->show();
                    }
        else {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr(" please enter valid id or password.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void login::on_pushButton_clicked()
{
    authentification();
}

QSerialPort* login::getserial() {
    return A.getserial();
}
void login::update_label()
{ QByteArray data = A.getserial()->readAll();
    QString receivedData = QString::fromUtf8(data);

    if (!receivedData.isEmpty()) {
        // Supposons que les données série contiennent uniquement l'UID
        QString badgeCode = receivedData.trimmed();
        qDebug() << badgeCode;



        QSqlQuery query;
        query.prepare("SELECT * FROM Plante WHERE BADGECODE=:badgeCode ");
        query.bindValue(":badgeCode", badgeCode);

        if (query.exec() && query.next()) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Login réussi avec succès.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
            login *l = new login;
          l->show();
          hide();
          QString idp = query.value("idp").toString();



        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("Veuillez vérifier le badge.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    }


      }
