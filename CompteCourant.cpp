#include "CompteCourant.h"

//constructeur par défault
Courant::Courant()
{
//affichage pédagogique

this-> DecouvertAutorise = 0;
this-> TauxAggios = 0;
this-> MontantDecouvert = 0;
}

//constructeur par copie
Courant::Courant(const Courant &C)
{
//affichage pédagogique
//cout <<"passage dans le constructeur par copie"<<endl;

this-> DecouvertAutorise = C.DecouvertAutorise;
this-> TauxAggios = C.TauxAggios;
this-> MontantDecouvert = C.MontantDecouvert;
}

//constructeur par parametre
Courant::Courant(int DecouvertAutorise, double TauxAggios, int MontantDecouvert, int solde, string id) : Compte(solde,id)
{
this->DecouvertAutorise = DecouvertAutorise;
this->TauxAggios = TauxAggios;
this-> MontantDecouvert = MontantDecouvert;
//return *this;
//cout << "création de CompteCourant " << " " << long(this) << endl;
}

Courant::~Courant()
{
//cout << "destruction du CompteCourant " << long(this) << endl;
}

void Courant::Afficher()
{

//Données issues de la classe Compte
cout << this->id;
cout << this->solde;
//cout << this->ouverture;

//Données appartenant à la classe Courant
cout << this->DecouvertAutorise;
cout << this->TauxAggios;
cout << this-> MontantDecouvert;
}

//permet d'afficher si un compte est à découvert ou non
void Courant::EtatCompte()
{
if(this->solde<0)
{  
    this-> MontantDecouvert = -(this->solde);
    cout << "Le compte est à découvert de "<< MontantDecouvert<< "€.";
}   
else
    cout << "Le compte est en positif <3";
    this-> MontantDecouvert = 0;
}

//permet d'enlever les agios du solde pour un mois
void Courant::EnleverAgiosMois()
{
    double coutAgiosMois = 0;
    this->TauxAggios = 0.16;
    int NombreJourDecouvert = 30;//30 jours pour un mois d'interet

    coutAgiosMois = (this->TauxAggios) * (this-> MontantDecouvert) * NombreJourDecouvert;
    this-> solde -= coutAgiosMois;
}

void Courant::RetraitCompte(int nb)
{
  this->solde = this->solde - nb;
}

Courant::Courant(string idTMP) : Compte(idTMP)
{
    int DecouvertAutoriseTMP=48;
    double TauxAgiosTMP=0.16;
    int MontantDecouvertTMP=0;
    
    cout << "Créations du compte courant numéro " << this->id << endl;

    this->DecouvertAutorise=DecouvertAutoriseTMP;
    this->TauxAggios=TauxAgiosTMP;
    this->MontantDecouvert=MontantDecouvertTMP;
} 

void Courant::AfficherCompte()
{
    //Donnée commune à la classe compte
    cout << "ID " << this->id << endl;
    cout << "Solde " << this->solde << endl;
    //cout << this->ouverture;

    //Données propres à la classe
    cout << "Découvert autorisé : "<< this-> DecouvertAutorise << endl;
    cout << "Taux d'agios : "<< this-> TauxAggios << endl;
    cout << "Montant du découvert : " << this-> MontantDecouvert << endl;

}

int Courant::RenvoyerTypeCompte()
{
    return 1;
}

int Courant::getDecouvertAutorise()
{
    return DecouvertAutorise;
}

double Courant::getTauxAggios()
{
    return TauxAggios;
}

int Courant::getMontantDecouvert()
{
    return MontantDecouvert;
}
