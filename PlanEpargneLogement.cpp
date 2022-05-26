#include "PlanEpargneLogement.h"

//Constructeur par défaut
PlanEpargneLogement::PlanEpargneLogement()
    {
        this->dureeBlocage=4;
        this->versementMensuel=100;
        this->tauxEmprunt=1.5;
    }

//Constructeur par copie
PlanEpargneLogement::PlanEpargneLogement(const PlanEpargneLogement &Acopier)
    {
        this->dureeBlocage=Acopier.dureeBlocage;
        this->versementMensuel=Acopier.versementMensuel;
        this->tauxEmprunt=Acopier.tauxEmprunt; 
    }

//Modifier Blocked par le nom de votre classe
//Rajouter dans le .h
PlanEpargneLogement:: PlanEpargneLogement(string idTMP) : Compte(idTMP)
{
    //Changer dureeBlocage et tauxInteret par le nom des données spécifiques a votre compte
    //Rajouter une donnée si nécessaire sur le même modèle
        int dureeBlocageTMP=4;
        int versementMensuelTMP=100;
        double tauxEmpruntTMP=1.5;

    
    //Juste le terme bloqué à changer par le type de votre compte
    cout << "Création du plan d'éparge logement numéro " << this->id << endl;


    //A ne pas toucher
    // this->Compte::id=idTMP;
    // this->Compte::solde=soldeTMP;

    //Changer dureeBlocage et tauxInteret par le nom des données spécifiques a votre compte
    //Rajouter une donnée si nécessaire sur le même modèle

        this->dureeBlocage=dureeBlocageTMP;
        this->versementMensuel=versementMensuelTMP;
        this->tauxEmprunt=tauxEmpruntTMP;
        //this->ouverture.Date::JourActuel();
} 


//Destructeur
PlanEpargneLogement::~PlanEpargneLogement()
    {

    }

//Opérateur d'affectation
PlanEpargneLogement& PlanEpargneLogement::operator=(const PlanEpargneLogement &Acopier)
    {
        this->dureeBlocage=Acopier.dureeBlocage;
        this->versementMensuel=Acopier.versementMensuel;
        this->tauxEmprunt=Acopier.tauxEmprunt;
        return *this;
    }

//Constructeur par paramètres
PlanEpargneLogement::PlanEpargneLogement(int dureeBlocage, int versementMensuel, double tauxEmprunt, int solde, string id) : Compte(solde,id)
    {
        this->dureeBlocage=dureeBlocage;
        this->versementMensuel=versementMensuel;
        this->tauxEmprunt=tauxEmprunt;
    }

//Fonction Afficher (les infos du compte)
void PlanEpargneLogement::Afficher()
    {   
        //Données issues de la classe Compte
        cout << this->id;
        cout << this->solde;
        //cout << this->ouverture;

        //Données appartenant à la classe PlanEpargneLogement
        cout << this->dureeBlocage;
        cout << this->versementMensuel;
        cout << this->tauxEmprunt;
    }

///////////////////////////////////////////////////
///////////////////////////////////////////////////
//Fonctions du PEL


void PlanEpargneLogement::AjouterEmprunt()
    {
        this->ModifierTauxEmprunt();
        cout << "Si vous demandez votre crédit maintenant, votre taux sera de: " << this->tauxEmprunt << endl;
    }


void PlanEpargneLogement::ModifierTauxEmprunt()
    {
        if(this->solde < 5000)
        this->tauxEmprunt = 2;

        if(this->solde >= 5000 && this->solde<10000)
        this->tauxEmprunt = 1.75;

        if(this->solde >= 10000 && this->solde<20000)
        this->tauxEmprunt = 1.5;

        if(this->solde >= 20000 && this->solde<30000)
        this->tauxEmprunt = 1.25;

        if(this->solde >= 30000 && this->solde<40000)
        this->tauxEmprunt = 1;

        if(this->solde >= 40000)
        this->tauxEmprunt = 0.75;
    }


//Compte bloqué mais emprunt possible au bout de 4 ans
// bool PlanEpargneLogement::VerifierBlocage()
//     {
//         Date Jour;
//         Jour.JourActuel();
//         Date Deblocage = this->ouverture;
//         Deblocage+4;

//         if(Jour>Deblocage)
//             return true;
//         else
//             return false;
//     } 


//Fonction pour savoir quand fermer le compte (au bout de 7 ans)
// bool PlanEpargneLogement::VerifierDuree()
//     {
//         Date Jour;
//         Jour.Date::JourActuel();
//         Date FermetureCompte = this->ouverture;
//         FermetureCompte+7;

//         if(Jour>FermetureCompte)
//         {
//             cout << "Le délai de 7 ans est dépassé, ce compte doit être fermé.";
//             return true;  
//         }      
//         else
//             return false;
            
//     }


void PlanEpargneLogement::ModifierVirementMensuel()
    {
        int nb;
        cout << "Combien d'argent voulez-vous virer chaque mois?";
        cin >> nb;

        //On remplace l'argent à virer chaque mois
        this->versementMensuel = nb;  
    }


void PlanEpargneLogement::DepotCompte(int nb)
    {
        //L'argent à déposer est 'nb'
        cout << "Combien voulez-vous déposer ?";
        cin >> nb;
        
        //On ajoute l'argent au solde du compte
        this->solde += nb;  //C'est pareil que 'this->solde = this->solde + nb;'
    }



void PlanEpargneLogement::AfficherCompte()
{
    //Donnée commune à la classe compte
    cout << "ID " << this->id << endl;
    cout << "Solde " << this->solde << endl;
    //cout << this->ouverture;

    //Données propres à la classe
    //exemple pour Blocked
    //cout << "Année "<< this->dureeBlocage << endl;
    cout << "Versement mensuel " << this->versementMensuel << endl;
    cout << "Taux d'emprunt " << this->tauxEmprunt << endl;

}

// permet un retrait d'argent
void PlanEpargneLogement::RetraitCompte(int nb)
{
    this->solde = this->solde - nb;
}

int PlanEpargneLogement::RenvoyerTypeCompte()
{
    return 3;
}

int PlanEpargneLogement::getDureeBlocage()
{
    return dureeBlocage;
}
int PlanEpargneLogement::getVersementMensuel()
{
    return versementMensuel;
}
double PlanEpargneLogement::getTauxEmprunt()
{
    return tauxEmprunt;
}