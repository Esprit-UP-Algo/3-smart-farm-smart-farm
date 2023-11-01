#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "animaux.h"
#include "ajouter.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:


    void on_supprimeran_clicked();


    void on_Ajouter_clicked();


private:
    Ui::MainWindow *ui;
    animaux anims;

};

#endif // MAINWINDOW_H
