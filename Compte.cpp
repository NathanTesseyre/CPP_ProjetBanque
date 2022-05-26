#include "Compte.h"

//Forme canonique
//Constructeur par défaut
    Compte::Compte()
    {
        //Date tmp;
        this->id="010000000000";
        solde=0;
        //ouverture=tmp;
        //Proprio = NULL;
    }
    //Constructeur par paramètres
    Compte::Compte(string id)
    {
        //Date tmp;
        this->id=id;
        this->solde=0;
        //ouverture=tmp;
        //Proprio = NULL;
    }
    Compte::Compte(int solde,string id)
    {
        //Date tmp;
        this->id=id;
        this->solde=solde;
        //ouverture=tmp;
        //Proprio = NULL;
    }
    //Constructeur par copie
    Compte::Compte(const Compte &Acopier)
    {
        this->id=Acopier.id;
        this->solde=Acopier.solde;
        //this->ouverture=Acopier.ouverture;
        //this->Proprio=Acopier.Proprio;
    }
    //Destructeur
    Compte::~Compte()
    {
        
    }
    //Opérateur d'affectation
    Compte& Compte::operator=(const Compte &Acopier)
    {
        this->id=Acopier.id;
        this->solde=Acopier.solde;
        //this->ouverture=Acopier.ouverture;
        //this->Proprio=Acopier.Proprio;
        return *this;
    }

    string Compte::getID() 
    {
        return this->id;
    }

    int Compte::getSolde() 
    {
        return this->solde;
    }

    void Compte::AfficherCompte()
    {
        cout << "Numéro de compte : " << this->id << endl;
        cout << "Solde du compte : " << this->solde << endl;
    }

    void Compte::DepotCompte(int nb)
    {

    }

    void Compte::RetraitCompte(int nb)
    {

    }

    int Compte::RenvoyerTypeCompte()
    {
        return 0;
    }



    int Compte::getDureeBlocage()
    {
        return 0;
    }
    double Compte::getTauxInteret()
    {
        return 0;
    }
    int Compte::getDecouvertAutorise()
    {
        return 0;
    }
    double Compte::getTauxAggios()
    {
        return 0;
    }
    int Compte::getMontantDecouvert()
    {
        return 0;
    }
    string Compte::getMail()
    {
        return "0";
    }
    string Compte::getNumTel()
    {
        return "0";
    }
    int Compte::getPlafondLivretEpargne()
    {
        return 0;
    }
    int Compte::getVersementMensuel()
    {
        return 0;
    }
    double Compte::getTauxEmprunt()
    {
        return 0;
    }