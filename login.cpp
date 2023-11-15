#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "plante.h"
#include <QMainWindow>
#include <QMessageBox>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    Plante p;
        QString idp = ui->id->text();
        QString mdp = ui->pwd->text();

        QSqlQuery query;
        query.prepare("SELECT * FROM Plante WHERE idp=:idp");
        query.bindValue(":idp",idp);

        if (query.exec() && query.next() && mdp=="smartfarm") {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                        QObject::tr("login avec success.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            this->hide();
                   MainWindow *auth = new MainWindow;
                   auth->show();

        } else {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr(" please enter valid id or password.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}
