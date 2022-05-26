#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;

#ifndef COMPTE_H_
#define COMPTE_H_



class Compte
{
    protected :

    string id;
    int solde;
    //Date ouverture;

    public:

    //Constructeur par défaut
    Compte();
    //Constructeur par paramètres
    Compte(string id);
    Compte(int solde,string id);
    //Constructeur par copie
    Compte(const Compte &Acopier);
    //Destructeur
    virtual ~Compte();
    //Opérateur d'affectation
    Compte& operator=(const Compte &Acopier);

    //Fonction virtuelle qui fait de la classe une classe abstraite
    virtual void Afficher()=0;


    //Fonctions de la classe mère Compte

    //void Afficher();

    void CloturerCompte();

    void ModifierSoldeCompte();

    void AfficherInformationsTitulaire();

    void HistoriqueCompte();


    string getID();
    int getSolde();

    virtual void AfficherCompte();

    virtual void DepotCompte(int nb);

    virtual void RetraitCompte(int nb);

    virtual int RenvoyerTypeCompte();

    virtual int getDureeBlocage();
    virtual double getTauxInteret();
    virtual int getDecouvertAutorise();
    virtual double getTauxAggios();
    virtual int getMontantDecouvert();
    virtual string getMail();
    virtual string getNumTel();
    virtual int getPlafondLivretEpargne();
    virtual int getVersementMensuel();
    virtual double getTauxEmprunt();

    
};

#endif