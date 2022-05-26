#include <iostream>
#include <string>
using namespace std;

#ifndef ECOMPTE_H_
#define ECOMPTE_H_

#include "Compte.h"

//Création de la classe eCompte, classe fille de la classe Compte
class eCompte : public Compte
{
private :
      // pas de donnée private

protected :

    string mail;

    string numTel;

    double tauxInteret;

public:

    virtual string getNumTel();
    virtual string getMail();
    virtual double getTauxInteret();
    
	// prototype des constructeurs
    eCompte();
    eCompte(const eCompte &E);
    eCompte(string numTel, double tauxInteret, string mail, int solde, string id);
    eCompte(string idTMP);
    eCompte& operator= (const eCompte &eC); 
    

    virtual void Afficher();
    virtual void RetraitCompte(int nb);
    virtual void DepotCompte (int nb);
    virtual bool VerifierRetrait(int debit);
    virtual void ModifierTauxInteret();
	virtual void AjouterInterets();
    virtual void AfficherCompte();
    
	virtual ~eCompte();

    virtual int RenvoyerTypeCompte();
} ;

#endif /* ECOMPTE_H_ */