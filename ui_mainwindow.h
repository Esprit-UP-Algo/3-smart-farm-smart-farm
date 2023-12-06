/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>


QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pb_ajouter;
    QLineEdit *le_id;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *le_pos;
    QLineEdit *le_type;
    QLineEdit *le_saison;
    QLineEdit *lineEdit;
    QPushButton *pb_ajouter_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QTableView *tableView;
    QLineEdit *le_rechercher_2;
    QPushButton *rechercher;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *tab_3;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_supp;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(770, 664);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 0, 711, 451));
        QFont font;
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("color: rgb(39, 211, 174);\n"
"background-color: rgb(224, 227, 211);\n"
"\n"
""));
        tabWidget->setIconSize(QSize(18, 18));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 711, 401));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(198, 198, 198);"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 151, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(7, 7, 7);\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 161, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(7, 7, 7);\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 20, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(7, 7, 7);\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName("pb_ajouter");
        pb_ajouter->setGeometry(QRect(40, 230, 41, 41));
        pb_ajouter->setStyleSheet(QString::fromUtf8("\n"
"font: 75 18pt \"MS Shell Dlg 2\";"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../image-removebg-preview (3).png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_ajouter->setIcon(icon);
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName("le_id");
        le_id->setGeometry(QRect(10, 60, 121, 16));
        le_id->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: rgb(255, 255, 255);}"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(100, 160, 201, 16));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(7, 7, 7);\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(170, 100, 201, 16));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(7, 7, 7);\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        le_pos = new QLineEdit(groupBox);
        le_pos->setObjectName("le_pos");
        le_pos->setGeometry(QRect(180, 60, 121, 16));
        le_pos->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: rgb(255, 255, 255);}"));
        le_type = new QLineEdit(groupBox);
        le_type->setObjectName("le_type");
        le_type->setGeometry(QRect(20, 130, 121, 16));
        le_type->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: rgb(255, 255, 255);}"));
        le_saison = new QLineEdit(groupBox);
        le_saison->setObjectName("le_saison");
        le_saison->setGeometry(QRect(190, 130, 121, 16));
        le_saison->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: rgb(255, 255, 255);}"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 190, 113, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: rgb(255, 255, 255);}"));
        pb_ajouter_2 = new QPushButton(groupBox);
        pb_ajouter_2->setObjectName("pb_ajouter_2");
        pb_ajouter_2->setGeometry(QRect(80, 230, 41, 41));
        pb_ajouter_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 14, 14);\n"
"font: 75 18pt \"MS Shell Dlg 2\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../image-removebg-preview (4).png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_ajouter_2->setIcon(icon1);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 230, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../image-removebg-preview (7).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 230, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../image-removebg-preview (6).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableView = new QTableView(tab_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(240, 0, 461, 401));
        le_rechercher_2 = new QLineEdit(tab_2);
        le_rechercher_2->setObjectName("le_rechercher_2");
        le_rechercher_2->setGeometry(QRect(20, 30, 171, 20));
        le_rechercher_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        rechercher = new QPushButton(tab_2);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(200, 30, 41, 23));
        rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 213, 44);color :rgb(255, 255, 255);\n"
"border-radius: 70px;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../image-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        rechercher->setIcon(icon4);
        radioButton = new QRadioButton(tab_2);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(50, 90, 83, 18));
        radioButton_2 = new QRadioButton(tab_2);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(50, 130, 83, 18));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(0, 0, 691, 501));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 30, 261, 41));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(7, 7, 7);\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(60, 70, 331, 51));
        lineEdit_9->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_supp = new QPushButton(groupBox_3);
        pushButton_supp->setObjectName("pushButton_supp");
        pushButton_supp->setGeometry(QRect(190, 240, 141, 51));
        pushButton_supp->setStyleSheet(QString::fromUtf8("font: 75 16pt \"MS Shell Dlg 2\";"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 770, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "nom de plante", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "type de plante", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "positon", nullptr));
        pb_ajouter->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Dur\303\251e de croissance", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Saison de croissance", nullptr));
        pb_ajouter_2->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        rechercher->setText(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "tri id", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "tri pos", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "afficher", nullptr));
        groupBox_3->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "taper l'identifiant", nullptr));
        pushButton_supp->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionPlante: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
