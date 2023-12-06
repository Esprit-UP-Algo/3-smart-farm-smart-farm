#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <iostream>
#include <fstream>
#include <QString>

class Utilisateur
{
public:
    Utilisateur();
    Utilisateur(const QString& nomUtilisateur, const QString& motDePasse, const QString& questionSecrete, const QString& reponseSecrete)
            : nomUtilisateur(nomUtilisateur), motDePasse(motDePasse), questionSecrete(questionSecrete), reponseSecrete(reponseSecrete) {}

        void reinitialiserMotDePasse(const QString& nouvelleReponseSecrete, const QString& nouveauMotDePasse);
        //Utilisateur chargerUtilisateurDepuisFichier(const QString& nomFichier);
private:
            QString nomUtilisateur;
            QString motDePasse;
            QString questionSecrete;
            QString reponseSecrete;
};

#endif // UTILISATEUR_H
