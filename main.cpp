#include <iostream>
#include <vector>

#include "Menu.h"
#include "Titulaire.h"
#include "Compte.h"
#include "CompteBloqué.h"
#include "CompteCourant.h"
#include "eCompte.h"
#include "LivretEpargne.h"
#include "PlanEpargneLogement.h"
//#include "Date.h"

using namespace std;

//Date Date::dateActuelle = Date(4, 2, 2022);

int main()
{
    //Dans notre main on a un tableau (vector) de pointeurs sur des titulaires
    //En gros c'est tous les clients de notre banque
    vector<Titulaire*> MaBanque;
    //MaBanque.push_back(new Titulaire("Maitret","Erwin","Cugnaux"));
    //MaBanque.push_back(new Titulaire("Marty","Clément","Albi"));
    //MaBanque.p
    
    //EcritureFichier(MaBanque);
    // if(VerifierMotDePasse())
    // {
        LectureFichier(MaBanque);
        MenuApp(MaBanque);
    // }
    /*DefinirMdP();
    MenuApp(MaBanque);*/
    //EcritureFichier(MaBanque);
    //LectureFichier(MaBanque);

    //cout << MaBanque[0]->getAdresse();

    //MaBanque.push_back(new Titulaire("Maitret", "Erwin", "Cugnaux",new Blocked(2,4)));

    //MaBanque[0]->AfficherMesComptes();





    //Pointeur ou pas pointeur ?

    return 0;
}