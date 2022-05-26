#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <termios.h>
#include <unistd.h>

#include "Titulaire.h"
#include "Compte.h"
#include "CompteBloqué.h"
#include "CompteCourant.h"
#include "eCompte.h"
#include "LivretEpargne.h"
#include "PlanEpargneLogement.h"
#include "Date.h"

#ifndef MENU_H_
#define MENU_H_

//Bloc de sécurité
int getch();
string getpass(const char *prompt, bool show_asterisk=true);
bool VerifierMotDePasse();
void DefinirMdP();

//Fonctions du menu

bool ExistingUser(const vector<Titulaire*> &Bank, const string name);
int IndexUser(const vector<Titulaire*> &Bank, const string name);
void CreationUserETCompte(vector<Titulaire*> &Bank, string nom, string prenom, string adresse);
void CreerUser(vector<Titulaire*> &Bank);
void CreerUserAuto(vector<Titulaire*> &Bank,string nom, string prenom, string adresse);
void CreationCompteSupp(vector<Titulaire*> &Bank, Titulaire &T);
void RechercherUser(vector<Titulaire*> &Bank, string name);
int OptionsApp(vector<Titulaire*> &Bank);

// Fonction du menu principal qui redirige l'utilisateur
void MenuApp(vector<Titulaire*> &Bank);

void EcritureFichier(const vector<Titulaire*> &Bank);
void LectureFichier(vector<Titulaire*> &Bank);

#endif