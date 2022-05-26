#include "LivretEpargne.h"

// définition du constructeur
    LivretEpargne::LivretEpargne() : Compte()
    {
        //cout << "passage dans le constructeur par défaut" << endl;
        plafondLivretEpargne = 20000;
        tauxInteret = 0.03; //3%
        //soldeEpargne = 0;
    }

// définition du constructeur par copie
    LivretEpargne:: LivretEpargne(const LivretEpargne & Acopier)
    {
        //cout << "passage dans le constructeur par copie" << endl;
        this->plafondLivretEpargne = Acopier.plafondLivretEpargne;
        this->tauxInteret = Acopier.tauxInteret;
        //this->soldeEpargne = Acopier.soldeEpargne;
    }

// a creer ou a modifier le compte Livret Epargne
LivretEpargne::LivretEpargne(string idTMP) : Compte(idTMP)
{
    int plafondLivretEpargneTMP = 20000;
    double tauxInteretTMP = 0.03; //3%
    //int soldeEpargneTMP = 0;

    cout << "Créations du compte Livre Epargne numéro " << this->id << endl;

    this->plafondLivretEpargne = plafondLivretEpargneTMP;
    this->tauxInteret = tauxInteretTMP;
}

 LivretEpargne::LivretEpargne(int PlafondLivretEpargne, double TauxInteret, int solde, string id) : Compte(solde,id)
 {
     this->plafondLivretEpargne=PlafondLivretEpargne;
     this->tauxInteret=TauxInteret;
 }


// le destructeur
    LivretEpargne:: ~LivretEpargne()
    {
        //cout << "passage dans le dectructeur" << endl;
    }

// affecter le compte
   LivretEpargne& LivretEpargne:: operator = (const LivretEpargne &Acopier)    
    {
        this->plafondLivretEpargne = Acopier.plafondLivretEpargne;
        this->tauxInteret = Acopier.tauxInteret;
        return *this;
    }

// calculer solde de livret Epargne
    void LivretEpargne::AjouterInterets()
    {
        this->solde = this->solde + this->solde * tauxInteret;
        //this->solde += this->solde * this->tauxInteret;
        cout << "votre solde actuelle est: " << this->solde << endl;
    }

// calculer et afficher intérêt 
    void LivretEpargne::AfficherInteret()
    {
        int interetAnnee; // interet qui peut recevoir par an
        int interetMois; // interet qui peut recevoir par mois
        interetAnnee = this->solde * tauxInteret;
        interetMois = this->solde * (tauxInteret/12);
        cout << "votre interet d'année est: " << interetAnnee << endl;
    }

// permet de ne pas dépasser le plafond 20000€
/*    bool LivretEpargne::VerifierPlafond() -> included DepotCompte pour l'instant
    {
        int depot;
        if ((this->solde + depot) > 20000)
        return false;
    
        else
        return true;  
    }*/

// permet de ne pas rétirer plus que le montant de solde
    bool LivretEpargne::VerifierSolde(int debit)
    {
        if ((this->solde -debit) < 0)
        return false;
    
        else
        return true;  
    }

// deposer d'argent a compte Livret Epargne et afficher nouveau solde
     void LivretEpargne::DepotCompte(int nb)
    {
        int TMP = this->solde;
        cout << "combien vous voulez ajouter a votre Livret Epargne?" << endl;
        cin >> nb;
        TMP += nb;

        if(TMP <= 20000)
        {
            this->solde = TMP;
            cout << "votre nouveau solde de Livret Epargne est: " << this->solde << endl;
        }
        else
            cout << "vous aurez dépasser la plafond" << endl;
    }

// retrait d'argent de compte Livret Epargne
    void LivretEpargne::RetraitCompte(int nb)
    {
        if (this -> VerifierSolde(nb) == true)
        this->solde = this->solde - nb;
        else
        cout << "Retrait impossible, solde insuffisant " << endl;
    }

// changer le taux d'intérêt de Livret Epargne
//    int LivretEpargne:: ModifierTauxInteret()
    
// afficher le compte // lien avec classe mere
    void LivretEpargne::Afficher()
    {
         cout << "ce compte Livret Epargne contient" << 
        this->id << this->solde << this->tauxInteret << this->plafondLivretEpargne
        << endl;
    }
// afficher le compte Livret Epargne
    void LivretEpargne::AfficherCompte()
    {
        cout << "ID " << this->id << endl;
        cout << "Solde " << this->solde << endl;
        cout << "Taux d'intéret " << this->tauxInteret << endl;
        cout << "Platond " << this->plafondLivretEpargne << endl; 
        // *pas this->nom;nom, prenom comment afficher??
        
    }

// clôturer le compte
    void LivretEpargne::CloturerCompte()
    {

    }

    int LivretEpargne::RenvoyerTypeCompte()
    {
        return 2;
    }

    int LivretEpargne::getPlafondLivretEpargne()
    {
        return plafondLivretEpargne;
    }
    double LivretEpargne::getTauxInteret()
    {
        return tauxInteret;
    }    