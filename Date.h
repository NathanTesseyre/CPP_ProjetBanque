#include <iostream>
#include <ctime>

using namespace std;


#ifndef DATE_H_
#define DATE_H_

class Date
{
protected:

    int jour;
    int mois;
    int annee;

public:
	static Date dateActuelle;
	//Forme canonique
	/* Définition du constructeur*/
	Date();
	/*Définition du constructeur par copie*/
	Date(const Date &ACopier);
	/*Définition du destructeur*/
	~Date();

	//Autre fonctions :
	/*Définition du constructeur avec paramètres*/
	Date(int j, int m, int a);
	/*Conversion d'un entier vers la classe*/
	Date(int i);
	/*Conversion de la classe vers un double*/
	operator double() const;
	/* Défintion de la fonction d'affichage*/
	void Afficher();
	/* Défintion de la fonction de saisie*/
	void Saisie();
	/* Défintion de la fonction de modification*/
	void Modifier(const Date &ACopier);
	/* Défintion de la fonction de comparaison*/
	bool Comparer(const Date &AComparer);
	/*Définition de la fonction pour définir si l'année est bisextile ou non*/
	bool Estbissextile() const;
	/*Vérifie la validité de la date entrée*/
	bool Verifier();
	int CalculNombreJour() const;
    /*Calcule le nombre n où la date entrée est le nième jour de l'année*/
	void Ecart(const Date &AComparer);

	void JourActuel();

	/*Ajouter un entier n aux annees*/
	Date operator+ (int mois);
	bool operator> (const Date &D);
	/*Définition de l'opérateur d'affectation*/
	Date &operator = (const Date &D);
	//Fonction non-membre de l'opérateur de saisie
	friend istream & operator>>(istream &in, Date &D);
	//Fonction non-membre de l'opérateur de sortie
	friend ostream & operator<<(ostream &out, Date D);



};

#endif

//Fonction qui rajoute un temps donné à une date    ==> Date AjouterEntier(int mois) 

//Fonction qui compare deux dates                   ==> bool operator>(const Date &Acomparer)

//Fonction qui affiche une date                     ==> operator<<

//Fonction qui calcule le temps entre 2 dates       ==> int Ecart(const Date &Acomparer)
