#include "Titulaire.h"

//constructeur par défaut
    Titulaire::Titulaire()
    {
        this->nom="nom inconnu";
        this->prenom="prenom inconnu";
        this->adresse="adresse inconnu";
    }

    //constructeur par paramètres
    Titulaire::Titulaire(string nom, string prenom, string adresse)
    {
        this->nom=nom;
        this->prenom=prenom;
        this->adresse=adresse;
    }

    //constructeur par paramètres
    Titulaire::Titulaire(string nom, string prenom, string adresse, Compte *ptr)
    {
        this->nom=nom;
        this->prenom=prenom;
        this->adresse=adresse;
        MesComptes.push_back(ptr);
    }

    //constructeur par copie
    Titulaire::Titulaire(const Titulaire &Acopier)
    {
        this->nom=Acopier.nom;
        this->prenom=Acopier.prenom;
        this->adresse=Acopier.adresse;
    }

    //Destructeur
    Titulaire::~Titulaire()
    {

    }

    void Titulaire::AfficherMesComptes()
    {
        cout << "Affichage des comptes de " << this->nom << " " << this->prenom << endl;

        for (int i = 0; i < this->MesComptes.size() ; i++)
        {
            cout << endl;
            cout << "COMPTE NUMERO " << i;
            cout << endl;
            this->MesComptes[i]->AfficherCompte();
            cout << endl;
        }
        
    }

    void Titulaire::AfficherUnCompte(int nb)
    {
        this->MesComptes[nb]->AfficherCompte();
    }

    string Titulaire::getName() const
    {
        return this->nom;
    }
    string Titulaire::getPrenom() const
    {
        return this->prenom;
    }
    string Titulaire::getAdresse() const
    {
        return this->adresse;
    }

    void Titulaire::AjouterCompte(Compte *ptr)
    {
        this->MesComptes.push_back(ptr);
    }

    void Titulaire::CloturerCompte(int index)
    {
        this->MesComptes.erase(this->MesComptes.begin()+(index-1));
    }

    bool Titulaire::VerifierIDcompte(string s)
    {
        for (int i = 0; i < this->MesComptes.size(); i++)
        {
            if(s==MesComptes[i]->getID())
            return false;
        }

        return true;
        
    }

    void Titulaire::DepotCompte(int nb)
    {
        int adeposer;
        cout << "Combien souhaitez-vous déposer ? ";
        cin >> adeposer;
        this->MesComptes[nb]->DepotCompte(adeposer);
    }

    void Titulaire::RetraitCompte(int nb)
    {
        int aretirer;
        cout << "Combien souhaitez-vous retrait ? ";
        cin >> aretirer;
        this->MesComptes[nb]->RetraitCompte(aretirer);
    }

    void Titulaire::ModifierInformations(string nom, string prenom, string adresse)
    {
        this->nom=nom;
        this->prenom=prenom;
        this->adresse=adresse;
    }

    int Titulaire::nbComptes()
    {
        return this->MesComptes.size();
    }

    Compte* Titulaire::getCompte(int nb)
    {
        return this->MesComptes[nb];
    }

    int Titulaire::getSolde(int nb)
    {
        return this->MesComptes[nb]->getSolde();
    }

    string Titulaire::getID(int nb)
    {
        return this->MesComptes[nb]->getID();
    }



    int Titulaire::getDureeBlocage(int nb)
    {
        return this->MesComptes[nb]->getDureeBlocage();
    }
    int Titulaire::getTauxInteret(int nb)
    {
        return this->MesComptes[nb]->getTauxInteret();
    }
    int Titulaire::getDecouvertAutorise(int nb)
    {
        return this->MesComptes[nb]->getDecouvertAutorise();
    }
    double Titulaire::getTauxAggios(int nb)
    {
        return this->MesComptes[nb]->getTauxAggios();
    }
    int Titulaire::getMontantDecouvert(int nb)
    {
        return this->MesComptes[nb]->getMontantDecouvert();
    }
    string Titulaire::getMail(int nb)
    {
        return this->MesComptes[nb]->getMail();
    }
    string Titulaire::getNumTel(int nb)
    {
        return this->MesComptes[nb]->getNumTel();
    }
    int Titulaire::getPlafondLivretEpargne(int nb)
    {
        return this->MesComptes[nb]->getPlafondLivretEpargne();
    }
    int Titulaire::getVersementMensuel(int nb)
    {
        return this->MesComptes[nb]->getVersementMensuel();
    }
    double Titulaire::getTauxEmprunt(int nb)
    {
        return this->MesComptes[nb]->getTauxEmprunt();
    }
