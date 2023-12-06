#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql \
    quick
Qt       +=sql
QT       += core gui printsupport
QT       += core gui sql
QT       += charts
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    GestionAnimaux.cpp \
    GestionEmploye.cpp \
    GestionPlante.cpp \
    ajouter.cpp \
    animaux.cpp \
    cal.cpp \
    employe.cpp \
    inter_ajouter.cpp \
    lesgestions.cpp \
        main.cpp \
        GestionMateriels.cpp \
    connection.cpp \
    materiels.cpp \
    modifier.cpp \
    modifieran.cpp \
    plante.cpp \
    supp.cpp \
    supprimeran.cpp \
    utilisateur.cpp

HEADERS += \
    GestionAnimaux.h \
    GestionEmploye.h \
    GestionPlante.h \
    ajouter.h \
    animaux.h \
    cal.h \
    employe.h \
    inter_ajouter.h \
        GestionMateriels.h \
    connection.h \
    lesgestions.h \
    materiels.h \
    modifier.h \
    modifieran.h \
    plante.h \
    supp.h \
    supprimeran.h \
    ui_mainwindow.h \
    utilisateur.h

FORMS += \
        GestionAnimaux.ui \
        GestionEmploye.ui \
        GestionPlante.ui \
        afficher.ui \
        ajouter.ui \
        cal.ui \
        inter_ajouter.ui \
        GestionMateriels.ui \
        lesgestions.ui \
        modifier.ui \
        modifieran.ui \
        supp.ui \
        supprimeran.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
