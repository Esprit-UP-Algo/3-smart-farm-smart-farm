#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"plante.h"
QT_BEGIN_NAMESPACE
#include "login.h"
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void exportToPDF();
    void afficherStatistiques();
    QWidget *statsWidget;
       QWidget *mainWidget;

private slots:
    void on_pb_ajouter_clicked();
    void on_pushButton_supp_clicked();


    void on_pb_ajouter_2_clicked();



    void on_rechercher_clicked();






    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_clicked();



    void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Plante p;
};

#endif // MAINWINDOW_H
