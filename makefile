
Banque3.0: CompteBloqué.o CompteCourant.o eCompte.o LivretEpargne.o PlanEpargneLogement.o Compte.o Titulaire.o Menu.o main.cpp
	g++ CompteBloqué.o CompteCourant.o eCompte.o LivretEpargne.o PlanEpargneLogement.o Compte.o Titulaire.o Menu.o main.cpp -o Banque3.0
CompteBloqué.o: CompteBloqué.cpp CompteBloqué.h
	g++ -c CompteBloqué.cpp
CompteCourant.o: CompteCourant.cpp CompteCourant.h 
	g++ -c CompteCourant.cpp
eCompte.o: eCompte.cpp eCompte.h
	g++ -c eCompte.cpp 
LivretEpargne.o: LivretEpargne.cpp LivretEpargne.h
	g++ -c LivretEpargne.cpp
PlanEpargneLogement.o: PlanEpargneLogement.cpp PlanEpargneLogement.h
	g++ -c PlanEpargneLogement.cpp
Compte.o: Compte.cpp Compte.h CompteBloqué.o CompteCourant.o eCompte.o LivretEpargne.o PlanEpargneLogement.o
	g++ -c Compte.cpp
Titulaire.o: Titulaire.cpp Titulaire.h Compte.o
	g++ -c Titulaire.cpp
Menu.o: Menu.cpp Menu.h Titulaire.o
	g++ -c Menu.cpp

MrProper:
	rm -f *.o