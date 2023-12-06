#include "utilisateur.h"

Utilisateur::Utilisateur()
{

}
void  Utilisateur:: reinitialiserMotDePasse(const QString& nouvelleReponseSecrete, const QString& nouveauMotDePasse)
{
    // Vérifier la réponse à la question secrète
    if (nouvelleReponseSecrete == reponseSecrete) {
        // Réinitialiser le mot de passe
        motDePasse = nouveauMotDePasse;
        std::cout << "Mot de passe réinitialisé avec succès." << std::endl;
    } else {
        std::cerr << "Réponse à la question secrète incorrecte. Mot de passe non réinitialisé." << std::endl;
    }
}
/*
Utilisateur chargerUtilisateurDepuisFichier(const QString& nomFichier)
{
    std::ifstream fichier(nomFichier.toStdString());
    QString nomUtilisateur, motDePasse, questionSecrete, reponseSecrete;
    if (fichier.is_open()) {
        fichier >> nomUtilisateur >> motDePasse >> questionSecrete >> reponseSecrete;
        fichier.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier pour charger." << std::endl;
    }
    return Utilisateur(nomUtilisateur, motDePasse, questionSecrete, reponseSecrete);
}
*/
