#include <iostream>
#include <ctime>

using namespace std;

//#include "Date.h"

//Forme canonique
/*Constructeur par défaut*/
Date::Date()
{
	jour = 1;
	mois = 1;
	annee = 2022;
}

/*Constructeur par copie*/
Date::Date(const Date &ACopier)
{
	this->jour = ACopier.jour;
	this->mois = ACopier.mois;
	this->annee = ACopier.annee;
}

/*Destructeur*/
Date::~Date()
{
	
}

/*Constructeur avec paramètres*/
Date::Date(int j, int m, int a = 2022)
{
	jour = j;
	mois = m;
	annee = a;
}

//Autres fonctions
/*Conversion d'un entier vers la classe*/
Date::Date(int i)
{
	jour = 01;
	mois = i;
	annee = 2022;
}

/*Conversion de la classe vers un double*/
Date::operator double() const
{
	return jour*1000000+mois*10000+annee;
}

/*Fonction d'affichage*/
void Date::Afficher()
{
	cout << "Voici la date : ";
	cout << jour << "/" << mois << "/" << annee <<endl;
}

/*Fonction de saisie*/
void Date::Saisie()
{
	char slash;
	cout << "Veuillez saisir la date format jj/mm/aaaa ainsi qu'un nom : ";
	cin >> jour >> slash >> mois  >> slash >> annee;
}

/*Fonction de modification depuis une autre Date*/
void Date::Modifier(const Date &ACopier)
{
	jour = ACopier.jour;
	mois = ACopier.mois;
	annee = ACopier.annee;
}

/*Fonction de comparaison*/
bool Date::Comparer(const Date &AComparer)
{
	if(jour == AComparer.jour && mois == AComparer.mois && annee == AComparer.annee)
		return (true);
	else
		return(false);
}

/*Fonction non-membre de la classe Date qui vérifie si l'année est bissextile*/
bool Date::Estbissextile() const
{
	if(annee % 4 == 0 && annee % 100 != 0)
		return(true);
	else if(annee % 400 ==0)
		return(true);
	else
		return(false);
}

bool Date::Verifier()
{
	if(mois < 1 || mois > 12)
		return (false);
	else if(jour < 1)
		return (false);
	else if((mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12) && jour > 31)
		return (false);
	else if((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30)
		return (false);
	else if(Estbissextile() == false && mois == 2 && jour > 29)
		return (false);
	else if(Estbissextile() == true && mois == 2 && jour > 28)
		return (false);
	else
		return(true);
}
int Date::CalculNombreJour() const
{
	int tabBase[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int tabBissextile[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int nbJours = 0;
	int i;

	if(Estbissextile() == false)
	{
		for(i = 0 ; i < mois - 1 ; i++)
			nbJours = nbJours + tabBase[i];

		nbJours = nbJours+jour;
	}

	if(Estbissextile() == true)
	{
		for(i = 0 ; i < mois - 1 ; i++)
			nbJours = nbJours + tabBissextile[i];

		nbJours = nbJours + jour;
	}

	return (nbJours);
}

void Date::Ecart(const Date &AComparer)
{
	int nbJoursAnnees = 0;
	int nbJours = 0;
	int diffAnnee = 0;

	diffAnnee = annee - AComparer.annee;

	if(diffAnnee < 0)
	{
		diffAnnee = AComparer.annee;

		for(int i = annee ; i < diffAnnee ; i++)
		{
			if(i % 4 == 0 && i % 100 != 0)
				nbJoursAnnees = nbJoursAnnees + 366;

			else if(i % 400 == 0)
				nbJoursAnnees = nbJoursAnnees + 366;

			else
				nbJoursAnnees = nbJoursAnnees + 365;
		}

		if((AComparer.annee % 4 == 0 && AComparer.annee % 100 != 0) || (AComparer.annee % 400 == 0))
			nbJoursAnnees = nbJoursAnnees - 1;

	}
	else
	{
		diffAnnee = annee;

		for(int i = AComparer.annee ; i < diffAnnee ; i++)
		{
			if(i % 4 == 0 && i % 100 != 0)
				nbJoursAnnees = nbJoursAnnees + 366;
			else if(i % 400 == 0)
				nbJoursAnnees = nbJoursAnnees + 366;
			else
				nbJoursAnnees = nbJoursAnnees + 365;
		}

		if((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
			nbJoursAnnees = nbJoursAnnees - 1;

	}

	if(jour != AComparer.jour || mois != AComparer.mois)
		nbJours = CalculNombreJour() - AComparer.CalculNombreJour();

	if(nbJours < 0)
		nbJours = nbJours * (-1);

	nbJours = nbJours + nbJoursAnnees;

	cout << "Il y a " << nbJours << " jours d'écart entre ces deux dates." << endl;
}

void Date::JourActuel()
{
	time_t actuel = time(0);
	tm *ltm = localtime(&actuel);

	this->jour=ltm->tm_mday;
	this->mois=1+ltm->tm_mon;
	this->annee=1900+ltm->tm_year;
}

Date Date::operator+ (int annee) 
{
	Date tmp=*this;
	tmp.annee=tmp.annee + annee;

	return tmp;
}

bool Date::operator> (const Date &D) 
{
	if(this->annee>D.annee)
	{
		return true;
	}
	if(this->mois>D.mois&&this->annee==D.annee)
	{
		return true;
	}
	if(this->jour>D.jour&&this->mois==D.mois&&this->annee==D.annee)
	{
		return true;
	}
	
	return false;

}

/*Opérateur d'affectation*/
Date& Date::operator= (const Date &D) 
{
	this->jour=D.jour;
	this->mois=D.mois;
	this->annee=D.annee;

	return *this;
}

// opérateur de saisie
istream & operator>>(istream &in, Date &D)
{
	char slash;
	cout << "Veuillez saisir la date format jj/mm/aaaa";
	in >> D.jour >> slash >> D.mois  >> slash >> D.annee;
	return in;
}

// opérateur de sortie
ostream & operator<<(ostream &out, Date D)
{
	out << D.jour << "/" << D.mois << "/" << D.annee << endl;
	return out;
}

int main()
{
	Date ouverture;
	Date test(3,6,2011);
	ouverture.JourActuel();
	test.JourActuel();
	
	if(test>ouverture)
		test.Afficher();
	else
	ouverture.Afficher();
}