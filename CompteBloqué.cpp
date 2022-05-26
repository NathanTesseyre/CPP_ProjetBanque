#include "CompteBloqué.h"

Blocked::Blocked() // Constructeur par défaut
{
    dureeBlocage=60; // 5 ans //
    tauxInteret=4;
    
} 
Blocked::Blocked(const Blocked &Acopier)
{
    this->dureeBlocage=Acopier.dureeBlocage;
    this->tauxInteret=Acopier.tauxInteret;

}  

Blocked::Blocked(int dureeBlocage,double tauxInteret, int solde, string id) : Compte(solde,id)
{
    this->dureeBlocage=dureeBlocage;
    this->tauxInteret=tauxInteret;

}  

//A CREER OU A MODIFIER

//Modifier Blocked par le nom de votre classe
//Rajouter dans le .h
Blocked::Blocked(string idTMP) : Compte(idTMP)
{
    //Changer dureeBlocage et tauxInteret par le nom des données spécifiques a votre compte
    //Rajouter une donnée si nécessaire sur le même modèle
    int dureeBlocageTMP=60;
    int tauxInteretTMP=4;

    
    //Juste le terme bloqué à changer par le type de votre compte
    cout << "Création du compte bloqué numéro " << this->id << endl;


    //A ne pas toucher
    // this->Compte::id=idTMP;
    // this->Compte::solde=soldeTMP;

    //Changer dureeBlocage et tauxInteret par le nom des données spécifiques a votre compte
    //Rajouter une donnée si nécessaire sur le même modèle
    this->dureeBlocage=dureeBlocageTMP;
    this->tauxInteret=tauxInteretTMP;

} 

Blocked::~Blocked()
{

}
Blocked& Blocked::operator=(const Blocked &Acopier)
{
    this->dureeBlocage=Acopier.dureeBlocage;
    this->tauxInteret=Acopier.tauxInteret;
    return *this;
}

void Blocked::Afficher()
{

}

void Blocked::AfficherCompte()
{
    //Donnée commune à la classe compte
    cout << "ID " << this->id << endl;
    cout << "Solde " << this->solde << endl;
    //cout << this->ouverture;

    //Données propres à la classe
    //exemple pour Blocked
    cout << "Taux d'intéret "<< this->tauxInteret << endl;
    cout << "Durée de blocage " << this->dureeBlocage << endl;


}

bool Blocked::VerifierBlocage()
{
    return false;
}

void Blocked::RetraitCompte(int nb)
{
    if (this -> VerifierBlocage() == true)
        this->solde = this->solde - nb;
    else
        cout << "Retrait impossible" << endl;
}

void Blocked::DepotCompte(int nb)
{
    this->solde += nb;
}

void Blocked::CloturerCompte()
{
    //
}

int Blocked::RenvoyerTypeCompte()
{
    return 4;
}
int Blocked::getDureeBlocage()
{
    return dureeBlocage;
}

double Blocked::getTauxInteret()
{
    return tauxInteret;
}