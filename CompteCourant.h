#include <iostream>
using namespace std;

#ifndef COMPTECOURANT_H_
#define COMPTECOURANT_H_

#include "Compte.h"

class Courant : public Compte
{
private :

int DecouvertAutorise;

double TauxAggios;

int MontantDecouvert;

public :

    virtual int getDecouvertAutorise();

    virtual double getTauxAggios();

    virtual int getMontantDecouvert();




Courant();
Courant(const Courant &C);

Courant(int DecouvertAutorise, double TauxAggios, int MontantDecouvert, int solde, string id);

virtual void Afficher();
virtual ~Courant();
void EtatCompte();
void EnleverAgiosMois();
Courant(string idTMP);
virtual void RetraitCompte(int nb);

void AfficherCompte();

Courant & operator= (const Courant &C);//operateur d'affectation

virtual int RenvoyerTypeCompte();

} ;

#endif