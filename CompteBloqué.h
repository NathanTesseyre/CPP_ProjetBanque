#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include "Compte.h"

#ifndef COMPTEBLOQUE_H_
#define COMPTEBLOQUE_H_


class Blocked : public Compte
{
    protected :

    //Durée du blocage
    int dureeBlocage;
    //Taux d'intéret
    double tauxInteret;

    public:

    virtual int getDureeBlocage();
    virtual double getTauxInteret();

//Forme canonique

    //Constructeur par défaut
    Blocked();
    //Constructeur par copie
    Blocked(const Blocked &Acopier);
    Blocked(int dureeBlocage,double tauxInteret, int solde, string id);
    //Destructeur virtuel
    Blocked(string idTMP);
    virtual ~Blocked();
    //Opérateur d'affectation
    Blocked &operator=(const Blocked &Acopier);



//Autres fonctions

    virtual void AfficherCompte();
    virtual void Afficher();
    //Fonction lien avec la classe Compte
    //Elle fait que CompteBloqué peut accéder aux données de Compte


    bool VerifierBlocage(); //=> A passer dans compte ?? //Clement//
    //Va inclure les fonctions Date suivantes : JourActuel, AjouterEntier, operator>


    ////////
    virtual void RetraitCompte(int nb);

    void Depot(int montant);
    //Va inclure VerifierBlocage et ModifierSolde

    ////////
    virtual void DepotCompte(int nb);

    void AfficherTempsBlocage(); //Clement//
    //Va inclure la fonction VerifierBlocage
    //Va inclure les fonctions Date suivantes : operator<<, Ecart, JourActuel

    double CalculerInterets(); //Clement//
    //Renvoie le montant des interets à ajouter au solde
    //Va inclure les fonctions Date suivantes : Ecart, JourActuel
    //Penser à utiliser l'historique des transactions

    void AjouterInterets(double montantInterets); //Clement//
    //Va appeler CalculerInterets
    //Va inclure ModifierSolde

    void ModifierTauxInteret(); //Clement//
    //Pertinence???

    void Creer();

    /////////////////
    virtual void CloturerCompte();

    virtual int RenvoyerTypeCompte();

/*

    A implémenter dans Compte :

Afficher toutes les informations du compte                  Afficher
!! Pour l'instant c'est la fonction virtuelle pure

Cloturer le compte                                           CloturerCompte

Modifier le solde ??                                         ModifierSoldeCompte
Faire depuis classe mère ou classe fille ??

Afficher informations du titulaire                           AfficherInformationsTitulaire
Faire depuis titulaire ou depuis compte (faisable ?) ??

//Optionnel
Afficher l'historique des 10 dernières opérations            HistoriqueCompte
A faire : Comment implémenter cette histoire d'historique ??
    Idées : Faire un tableau contenant l'historique (vector ?) qu'on vérifie avant de push_back et qui supprime v.begin si v.size==10


    A implémenter dans Date :

Fonction qui va me renvoyer la date du jour       ==> Date JourActuel()

Fonction qui rajoute un temps donné à une date    ==> Date AjouterEntier(int mois) 

Fonction qui compare deux dates                   ==> bool operator>(const Date &Acomparer)

Fonction qui affiche une date                     ==> operator<<

Fonction qui calcule le temps entre 2 dates       ==> int Ecart(const Date &Acomparer)

*/

} ;

#endif