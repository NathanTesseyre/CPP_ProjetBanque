#include <iostream>

#ifndef PLANEPARGNELOGEMENT_H_
#define PLANEPARGNELOGEMENT_H_

#include "Compte.h"
#include "Date.h"

class PlanEpargneLogement : public Compte
{
    private :

    //Durée du blocage à partir de la date d'ouverture
    int dureeBlocage;

    //Versement Mensuel
    int versementMensuel;

    //Taux d'emprunt
    double tauxEmprunt;

    //Date ouverture;

    public : 

    virtual int getDureeBlocage();
    virtual int getVersementMensuel();
    virtual double getTauxEmprunt();

    //Forme canonique
    PlanEpargneLogement();
    PlanEpargneLogement(const PlanEpargneLogement &Acopier);
    PlanEpargneLogement(string idTMP);
    virtual ~PlanEpargneLogement();
    PlanEpargneLogement &operator=(const PlanEpargneLogement &Acopier);

    //Constructeur par paramètres
    PlanEpargneLogement(int dureeBlocage, int versementMensuel, double tauxEmprunt, int solde, string id);

    //Fonction lien avec la classe Compte
    virtual void Afficher();



    //Fonctions du PEL

    void AjouterEmprunt();
//double tauxEmprunt
//double solde
//appelle CalculerEmprunt()
//appelle ModifierSoldeCompte()

    void ModifierTauxEmprunt();
//double tauxEmprunt
//double solde

    bool VerifierBlocage();
//ouverture
//int dureeBlocage
//retourne si vrai ou faux, le compte a + de 4 ans

    bool VerifierDuree();
//ouverture
//retourne si vrai ou faux, le compte a + de 7 ans
//appelle CloturerCompte() si vrai


    void ModifierVirementMensuel();
//int versementMensuel

    virtual void DepotCompte(int nb);
//double solde
//appelle ModifierSoldeCompte()

    void AfficherCompte();

    virtual void RetraitCompte(int nb);

    virtual int RenvoyerTypeCompte();

} ;

#endif