#include "eCompte.h"

// constructeur par défaut
eCompte::eCompte() {
    // affichage pédagogique
    //cout << "passage dans le contructeur par défaut" << endl;

    this->numTel  = "0782913645";
    this->tauxInteret = 1;
    this->mail = "test";
}

// constructeur par copie
eCompte::eCompte(const eCompte &E) {
    // affichage pédagogique
    //cout << "passage dans le contructeur par copie" << endl; 

    this-> numTel  = E.numTel;
    this-> tauxInteret = E.tauxInteret;
    this-> mail = E.mail;
}

// Constructeur par paramètres
eCompte::eCompte( string numTel, double tauxInteret, string mail, int solde, string id) : Compte(solde,id)
{
    // affichage pédagogique
    //cout << "passage dans le contructeur par copie" << endl;

    this-> numTel = numTel;
    this-> tauxInteret = tauxInteret;
    this-> mail = mail;
}

eCompte::eCompte(string idTMP) : Compte(idTMP)
{
    string mailTMP  = "mail@test";
    string numTelTMP = "0562201500";
    int tauxInteretTMP = 0;

    
    cout << "Créations du e.Compte numéro " << this->id << endl;
    cout << "Quel est votre mail?"<< endl;
    cin >> mail;
    this->mail = mailTMP;
    cout << "Quel est votre numéro de téléphone ?"<< endl;
    cin >> numTel;
    this->numTel = numTelTMP;
    this->tauxInteret = tauxInteretTMP;

    this->solde +=50;
} 

// Destructeur
eCompte::~eCompte()
{
    // affichage pédagogique
    //cout << "passage dans le destructeur" << endl;
}

// opérateur d'affectation
eCompte& eCompte::operator=(const eCompte &eC)
{
    this -> numTel = eC.numTel;
    this -> tauxInteret = eC.tauxInteret;
    this -> mail = eC.mail;
    return *this;
}

//cette fonction est nécessaire pour toutes les classes fille car classe compte est abstraite, 
// grace à elle je peux accéder à la classe compte
void eCompte::Afficher()
{
    cout << this -> id;
    cout << this -> solde;
    //cout << this -> ouverture;
    cout << this -> numTel;
    cout << this -> tauxInteret;
    cout << this -> mail;
}   

// permet de pas avoir un solde < 10€, 
//dans ce cas interdire le retrait
bool eCompte::VerifierRetrait(int debit)
{
    //int newSolde = this -> solde;
    //newSolde = newSolde - debit;
    // AUTRE OPTION plutot que que ligne 83
    
    if ((this->solde - debit) < 10)
        return false;
    
    else
        return true;    
}

// permet un retrait d'argent 
void eCompte::RetraitCompte(int nb)
{
    if (this -> VerifierRetrait(nb) == true) 
        this->solde = this->solde - nb;
    else 
    cout << "Retrait impossible"<<endl;
}

void eCompte::DepotCompte (int nb)
{
    this->solde += nb;
}


void eCompte::ModifierTauxInteret()
{
    //if (JourActuel > ouverture.AjouterEntier(3))
    //this -> tauxInteret = 1.5;
    //else
    //this -> tauxInteret = 4.5;
}

void eCompte::AjouterInterets()
{ 
    this-> ModifierTauxInteret();
    this-> solde += ( (this->solde) * (this->tauxInteret) /100);
}

void eCompte::AfficherCompte()
{
    //Donnée commune à la classe compte
    cout << "ID " << this->id << endl;
    cout << "Solde " << this->solde << endl;
    //cout << this->ouverture;

    //Données propres à la classe
    //exemple pour Blocked
    cout << "e.mail : "<< this-> mail << endl;
    cout << "Numéro de téléphone : "<< this-> numTel << endl;
    cout << "Taux d'intérêt : "<< this-> tauxInteret << endl;

}

int eCompte::RenvoyerTypeCompte()
{
    return 5;
}

string eCompte::getMail()
{
    return mail;
}
string eCompte::getNumTel()
{
    return numTel;
}
double eCompte::getTauxInteret()
{
    return tauxInteret;
}