#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"plante.h"
QT_BEGIN_NAMESPACE
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

private slots:
    void on_pb_ajouter_clicked();
    void on_pushButton_supp_clicked();

private:
    Ui::MainWindow *ui;
    Plante p;
};

#endif // MAINWINDOW_H
