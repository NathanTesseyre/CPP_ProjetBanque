#include <iostream>
#include <vector>

using namespace std;

#ifndef TITULAIRE_H_
#define TITULAIRE_H_

#include "Compte.h"

class Titulaire
{
    protected:

    //Nom
    string nom;

    //Prenom
    string prenom;

    //Adresse
    string adresse;

    //Tableaux de comptes
    vector<Compte*> MesComptes;

    public:

    //constructeur par défaut
    Titulaire();

    Titulaire(string nom, string prenom, string adresse);

    //constructeur par paramètres
    Titulaire(string nom, string prenom, string adresse, Compte *ptr);

    //constructeur par copie
    Titulaire(const Titulaire &Acopier);

    //Destructeur
    ~Titulaire();

    void AfficherMesComptes();
    void AfficherUnCompte(int nb);

    string getName() const;
    string getPrenom() const;
    string getAdresse() const;

    void AjouterCompte(Compte *ptr);
    void CloturerCompte(int index);
    bool VerifierIDcompte(string s);

    void DepotCompte(int nb);
    void RetraitCompte(int nb);
    void ModifierInformations(string nom, string prenom, string adresse);
    int nbComptes();
    Compte* getCompte(int nb);
    int getSolde(int nb);
    string getID(int nb);

    int getDureeBlocage(int nb);
    int getTauxInteret(int nb);
    int getDecouvertAutorise(int nb);
    double getTauxAggios(int nb);
    int getMontantDecouvert(int nb);
    string getMail(int nb);
    string getNumTel(int nb);
    int getPlafondLivretEpargne(int nb);
    int getVersementMensuel(int nb);
    double getTauxEmprunt(int nb);

};

#endif