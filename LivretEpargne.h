#include <iostream>
#include <string>
using namespace std;

#ifndef LIVRETEPARGNE_H_
#define LIVRETEPARGNE_H_


#include "Compte.h"
#include "Titulaire.h"

class LivretEpargne : public Compte
{
    private :

    //Plafond

    int plafondLivretEpargne;

    //Taux d'intéret
    double tauxInteret;

    //Solde de compte Livret Epargne
    //int soldeEpargne;

    public :

    virtual int getPlafondLivretEpargne();
    virtual double getTauxInteret();

    // définition du constructeur
    LivretEpargne();
    LivretEpargne(string idTMP);
    LivretEpargne(int PlafondLivretEpargne, double TauxInteret, int solde, string id);

    // définition du constructeur par copie
    LivretEpargne(const LivretEpargne &Acopier);

    // le destructeur
    virtual ~LivretEpargne();

    // affecter le compte Livret Epargne
    LivretEpargne& operator = (const LivretEpargne &Acopier);
    //friend ostream & operator << (ostream &out, LivretEpargne Acopier);
    //friend istream & operator >> (istream &in, LivretEpargne &Acopier);

   

    // calculer solde de livert Epargne 
    // Payer les intérêts (sans vérifier plafond)
    virtual void AjouterInterets();
    
    // calculer et afficher intérêt
    virtual void AfficherInteret();

    // permet de ne pas dépasser le plafond 20000€
    //virtual bool VerifierPlafond(); 

    // permet de ne pas rétirer plus que le montant de solde
    virtual bool VerifierSolde(int debit);

    // deposer d'argent a compte Livret Epargne
    virtual void DepotCompte(int nb);

    // retrait d'argent de compte Livret Epargne
    virtual void RetraitCompte(int nb);

    // changer le taux d'intérêt de Livret Epargne ?? quelle condition??
   // virtual int ModifierTauxInteret();

    // lien avec classe mere 
    virtual void Afficher();

    // afficher le compte 
    virtual void AfficherCompte();

    // clôturer le compte
    virtual void CloturerCompte();

    virtual int RenvoyerTypeCompte();

} ;

#endif 