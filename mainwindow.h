#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include "employe.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    employe e;



    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget *mainWidget;
    QWidget *statsWidget;



private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supp_clicked();


    void on_affichem_clicked();

    void on_pushButton_modifier_clicked();

    void on_pb_recher_clicked();

    //void on_pb_trier_clicked();
    //std::string chatbotFunction(const);
    void afficherStatistiques();







    void on_pb_pdf_clicked();



    void on_pb_stat_clicked();

    //void on_envoyer_clicked();



    void on_radioButton_NOM_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_radioButton_2_clicked();


    void on_pushButton_tentative_clicked();
    //void readFromArduino();
    void incrementNbreEntree();
    QString getnbreEntreeData();
    void update_label();
private:
    Ui::MainWindow *ui;
    QByteArray data;
    Arduino A;
};

#endif // MAINWINDOW_H
