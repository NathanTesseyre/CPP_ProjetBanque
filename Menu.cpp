#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <termios.h>
#include <unistd.h>

#include "Menu.h"

//Bloc de sécurité

int getch() 
{
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

string getpass(const char *prompt, bool show_asterisk)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  string password;
  unsigned char ch=0;

  cout <<prompt;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                if(show_asterisk)
                    cout <<"\b \b";
                password.resize(password.length()-1);
            }
        }
       else
        {
            password+=ch;
            if(show_asterisk)
                cout <<'*';
        }
    }
  cout <<endl;
  return password;
}

bool VerifierMotDePasse()
{
    string correct_password;
    ifstream f ("../Debug/src/sauvegarde", ios::in | ios::binary);
    if (!f.is_open())
        cout << "Impossible d'ouvrir le fichier en lecture !" << endl;
    else
    f.read ((char *)&correct_password, sizeof(string));
    f.close();

  string password=getpass("Entrez votre mot de passe : ", true);
  if(password==correct_password)
      return true;
  else
      return false;
}

void DefinirMdP()
{
    string password=getpass("Entrez votre mot de passe : ", true);

    ofstream f ("../Debug/src/sauvegarde", ios::out | ios::binary);

    if(!f.is_open())
        cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
    else
        f.write ((char *)&password, sizeof(string));
    
    f.close();

}

string GenererIDcompte(vector<Titulaire*> &Bank)
{
    int occurrence=0;
    string idTMP="0";
    srand (time(NULL));

    do
    {
        occurrence=0;
        idTMP="0";

        for (int i = 0; i < 9; i++)
        {
            idTMP+=to_string(rand()%9 +0);
        }
        
        for (int i = 0; i < Bank.size(); i++)
        {
            if(!Bank[i]->VerifierIDcompte(idTMP))
            {
                occurrence++;
                break;
            }
        }

    } while (occurrence!=0);
    
    

    return idTMP;
}

void EcritureFichier(const vector<Titulaire*> &Bank)
{
    FILE *fic;
    string nameTMP;
    string prenomTMP;
    string adresseTMP;
    int nbComptes;
    int typeCompte;
    int soldeTMP;
    string idTMP;

    int DureeBlocageTMP;
    double TauxInteretTMP;
    int DecouvertAutoriseTMP;
    double TauxAggiosTMP;
    int MontantDecouvertTMP;
    string MailTMP;
    string NumTelTMP;
    int PlafondLivretEpargneTMP;
    int VersementMensuelTMP;
    double TauxEmpruntTMP;

    fic = fopen("../Debug/src/bdd","wba");

    int tailleBank = Bank.size();

    fwrite(&tailleBank,sizeof(int),1,fic);

    for (int i = 0; i < tailleBank; i++)
    {
        nameTMP=Bank[i]->getName();
        prenomTMP=Bank[i]->getPrenom();
        adresseTMP=Bank[i]->getAdresse();
        nbComptes=Bank[i]->nbComptes();
        fwrite(&nameTMP,sizeof(string),1,fic);
        fwrite(&prenomTMP,sizeof(string),1,fic);
        fwrite(&adresseTMP,sizeof(string),1,fic);
        fwrite(&nbComptes,sizeof(int),1,fic);
        for (int j = 0; j < nbComptes; j++)
        {
            typeCompte=Bank[i]->getCompte(j)->RenvoyerTypeCompte();
            fwrite(&typeCompte,sizeof(int),1,fic);
            soldeTMP=Bank[i]->getSolde(j);
            fwrite(&soldeTMP,sizeof(int),1,fic);
            idTMP=Bank[i]->getID(j);
            fwrite(&idTMP,sizeof(string),1,fic);

            switch (typeCompte)
            {
            case 1: //Courant
                DecouvertAutoriseTMP=Bank[i]->getDecouvertAutorise(j);
                TauxAggiosTMP=Bank[i]->getTauxAggios(j);
                MontantDecouvertTMP=Bank[i]->getMontantDecouvert(j);
                fwrite(&DecouvertAutoriseTMP,sizeof(int),1,fic);
                fwrite(&TauxAggiosTMP,sizeof(double),1,fic);
                fwrite(&MontantDecouvertTMP,sizeof(int),1,fic);
                break;
            case 2: //Epargne
                PlafondLivretEpargneTMP=Bank[i]->getPlafondLivretEpargne(j);
                TauxInteretTMP=Bank[i]->getTauxInteret(j);
                fwrite(&PlafondLivretEpargneTMP,sizeof(int),1,fic);
                fwrite(&TauxInteretTMP,sizeof(double),1,fic);
                break;
            case 3: //PEL
                DureeBlocageTMP=Bank[i]->getDureeBlocage(j);
                VersementMensuelTMP=Bank[i]->getVersementMensuel(j);
                TauxEmpruntTMP=Bank[i]->getTauxEmprunt(j);
                fwrite(&DureeBlocageTMP,sizeof(int),1,fic);
                fwrite(&VersementMensuelTMP,sizeof(int),1,fic);
                fwrite(&TauxEmpruntTMP,sizeof(double),1,fic);
                break;
            case 4: //Blocked
                DureeBlocageTMP=Bank[i]->getDureeBlocage(j);
                TauxInteretTMP=Bank[i]->getTauxInteret(j);
                fwrite(&DureeBlocageTMP,sizeof(int),1,fic);
                fwrite(&TauxInteretTMP,sizeof(double),1,fic);
                break;
            case 5: //eCompte
                MailTMP=Bank[i]->getMail(j);
                NumTelTMP=Bank[i]->getNumTel(j);
                TauxInteretTMP=Bank[i]->getTauxInteret(j);
                fwrite(&MailTMP,sizeof(string),1,fic);
                fwrite(&NumTelTMP,sizeof(string),1,fic);
                fwrite(&TauxInteretTMP,sizeof(double),1,fic);
                break;
            
            default:
                break;
            }



        }
        
    }
    

    fclose(fic);
}

void LectureFichier(vector<Titulaire*> &Bank)
{
    
    FILE *fic;

    int tailleBank;
    string nameTMP;
    string prenomTMP;
    string adresseTMP;
    int nbComptes;
    int typeCompte;
    int soldeTMP;
    string idTMP;

    int DureeBlocageTMP;
    double TauxInteretTMP;
    int DecouvertAutoriseTMP;
    double TauxAggiosTMP;
    int MontantDecouvertTMP;
    string MailTMP;
    string NumTelTMP;
    int PlafondLivretEpargneTMP;
    int VersementMensuelTMP;
    double TauxEmpruntTMP;

    fic = fopen("../Debug/src/bdd","rb");

    fread(&tailleBank,sizeof(tailleBank),1,fic);

    for (int i = 0; i < tailleBank; i++)
    {
        fread(&nameTMP,sizeof(string),1,fic);
        fread(&prenomTMP,sizeof(string),1,fic);
        fread(&adresseTMP,sizeof(string),1,fic);
        //Bank.push_back(new Titulaire(nameTMP,prenomTMP,adresseTMP));
        fread(&nbComptes,sizeof(int),1,fic);
        for (int j = 0; j < nbComptes; j++)
        {
            fread(&typeCompte,sizeof(int),1,fic);
            fread(&soldeTMP,sizeof(int),1,fic);
            fread(&idTMP,sizeof(string),1,fic);

            switch (typeCompte)
            {
            case 1://Courant
                fread(&DecouvertAutoriseTMP,sizeof(int),1,fic);
                fread(&TauxAggiosTMP,sizeof(double),1,fic);
                fread(&MontantDecouvertTMP,sizeof(int),1,fic);
                if(j==0)
                {
                    CreerUserAuto(Bank,nameTMP,prenomTMP,adresseTMP);
                    Bank[i]->AjouterCompte(new Courant(DecouvertAutoriseTMP,TauxAggiosTMP,MontantDecouvertTMP,soldeTMP,idTMP));
                }
                else
                {
                    Bank[i]->AjouterCompte(new Courant(DecouvertAutoriseTMP,TauxAggiosTMP,MontantDecouvertTMP,soldeTMP,idTMP));
                }
                break;
            case 2://Epargne
                
                fread(&PlafondLivretEpargneTMP,sizeof(int),1,fic);
                fread(&TauxInteretTMP,sizeof(double),1,fic);
                if(j==0)
                {
                    CreerUserAuto(Bank,nameTMP,prenomTMP,adresseTMP);
                    Bank[i]->AjouterCompte(new LivretEpargne(PlafondLivretEpargneTMP,TauxInteretTMP,soldeTMP,idTMP));
                }
                else
                {
                    Bank[i]->AjouterCompte(new LivretEpargne(PlafondLivretEpargneTMP,TauxInteretTMP,soldeTMP,idTMP));
                }
                break;
            case 3://PEL
                fread(&DureeBlocageTMP,sizeof(int),1,fic);
                fread(&VersementMensuelTMP,sizeof(int),1,fic);
                fread(&TauxEmpruntTMP,sizeof(double),1,fic);
                if(j==0)
                {
                    CreerUserAuto(Bank,nameTMP,prenomTMP,adresseTMP);
                    Bank[i]->AjouterCompte(new PlanEpargneLogement(DureeBlocageTMP,VersementMensuelTMP,TauxEmpruntTMP,soldeTMP,idTMP));
                }
                else
                {
                    Bank[i]->AjouterCompte(new PlanEpargneLogement(DureeBlocageTMP,VersementMensuelTMP,TauxEmpruntTMP,soldeTMP,idTMP));
                }
                break;
            case 4://Blocked
                fread(&DureeBlocageTMP,sizeof(int),1,fic);
                fread(&TauxInteretTMP,sizeof(double),1,fic);
                if(j==0)
                {
                    CreerUserAuto(Bank,nameTMP,prenomTMP,adresseTMP);
                    Bank[i]->AjouterCompte(new Blocked(DureeBlocageTMP,TauxInteretTMP,soldeTMP,idTMP));
                }
                else
                {
                    Bank[i]->AjouterCompte(new Blocked(DureeBlocageTMP,TauxInteretTMP,soldeTMP,idTMP));
                }
                break;
            case 5://eCompte
                fread(&MailTMP,sizeof(string),1,fic);
                fread(&NumTelTMP,sizeof(string),1,fic);
                fread(&TauxInteretTMP,sizeof(double),1,fic);
                if(j==0)
                {
                    CreerUserAuto(Bank,nameTMP,prenomTMP,adresseTMP);
                    Bank[i]->AjouterCompte(new eCompte(NumTelTMP,TauxInteretTMP,MailTMP,soldeTMP,idTMP));
                }
                else
                {
                    Bank[i]->AjouterCompte(new eCompte(NumTelTMP,TauxInteretTMP,MailTMP,soldeTMP,idTMP));
                }
                break;
            
            default:
                break;
            }
        }
        
    }


    fclose(fic);

    //return temp;
}

//Elle va faire le tour de notre Banque en comparant name avec le nom de tous les utilisateurs
//Si jamais un utilisateur a le même nom elle renvoie true
//Sinon elle renvoie false
bool ExistingUser(const vector<Titulaire*> &Bank, const string name)
{
    for (int i = 0; i < Bank.size(); i++)
    {
        if(Bank[i]->getName()==name)
        {
            return true;
        }
    }
    return false;
}

int IndexUser(const vector<Titulaire*> &Bank, const string name)
{
    for (int i = 0; i < Bank.size(); i++)
    {
        if(Bank[i]->getName()==name)
        {
            return i;
        }
    }
    return -1;
}

void CreationUserETCompte(vector<Titulaire*> &Bank, string nom, string prenom, string adresse)
{
    int choix;

    string idTMP=GenererIDcompte(Bank);

    cout << "\nQuel est le type de compte que vous souhaitez créer ? \n";
    cout << "\t1- Compte Courant \n";
    cout << "\t2- Livret Epargne\n";
    cout << "\t3- Plan Epargne Logement\n";
    cout << "\t4- Compte Bloqué\n";
    cout << "\t5- eCompte \n";
    cout << "\t0- Quitter la procédure et revenir au menu. \n";
    cin >> choix;

    switch (choix)
    {
    case 1:
        Bank.push_back(new Titulaire(nom, prenom, adresse));
        Bank[Bank.size()-1]->AjouterCompte(new Courant(idTMP));
        break;
    case 2:
        Bank.push_back(new Titulaire(nom, prenom, adresse));
        Bank[Bank.size()-1]->AjouterCompte(new LivretEpargne(idTMP));
        break;
    case 3:
        Bank.push_back(new Titulaire(nom, prenom, adresse));
        Bank[Bank.size()-1]->AjouterCompte(new PlanEpargneLogement(idTMP));
        break;
    case 4:
        Bank.push_back(new Titulaire(nom, prenom, adresse));
        Bank[Bank.size()-1]->AjouterCompte(new Blocked(idTMP));
        break;
    case 5:
        Bank.push_back(new Titulaire(nom, prenom, adresse));
        Bank[Bank.size()-1]->AjouterCompte(new eCompte(idTMP));
        break;
    case 0:
        MenuApp(Bank);
        break;
    
    default:
        break;
    }
}

void CreerUser(vector<Titulaire*> &Bank)
{
    string tmpNom;
    cout << "Quel est le nom de l'utilisateur que vous souhaitez créer ? ";
    cin >> tmpNom;
    if(!ExistingUser(Bank,tmpNom))
    {
        int choix;
        string tmpPrenom;
        string tmpAdresse;

        cout << "Quel est le prénom de l'utilisateur que vous souhaitez créer ? ";
        cin >> tmpPrenom;
            cout << "Quel est l'adresse de l'utilisateur que vous souhaitez créer ? ";
        cin >> tmpAdresse;

        CreationUserETCompte(Bank, tmpNom, tmpPrenom, tmpAdresse);
        
    }
    else
    cout << "Cet utilisateur existe deja";

}

void CreerUserAuto(vector<Titulaire*> &Bank,string nom, string prenom, string adresse)
{
    Bank.push_back(new Titulaire(nom, prenom, adresse));
}

void CreationCompteSupp(vector<Titulaire*> &Bank, Titulaire &T)
{
    int choix;

    string idTMP=GenererIDcompte(Bank);

    cout << "Quel est le type de compte que vous souhaitez créer ? \n";
    cout << "\t1- Compte Courant \n";
    cout << "\t2- Livret Epargne\n";
    cout << "\t3- Plan Epargne Logement\n";
    cout << "\t4- Compte Bloqué\n";
    cout << "\t5- eCompte \n";
    cout << "\t0- Quitter la procédure et revenir au menu. \n";

    cout << "Choix : ";
    cin >> choix;

    switch (choix)
    {
    case 1:
        T.AjouterCompte(new Courant(idTMP));
        break;
    case 2:
        T.AjouterCompte(new LivretEpargne(idTMP));
        break;
    case 3:
        T.AjouterCompte(new PlanEpargneLogement(idTMP));
        break;
    case 4:
        T.AjouterCompte(new Blocked(idTMP));
        break;
    case 5:
        T.AjouterCompte(new eCompte(idTMP));
        break;
    case 0:
        MenuApp(Bank);
        break;
    
    default:
        break;
    }
}

void RechercherUser(vector<Titulaire*> &Bank)
{
    char rep; 
    int choix1;
    char choix2;
    int numCompte;
    string name;

    string tmpNom;
    cout << "Quel est le nom de l'utilisateur que vous souhaitez rechercher ? ";
    cin >> tmpNom;
    if(ExistingUser(Bank,tmpNom))
    {
        int index = IndexUser(Bank,tmpNom);
        string nom=Bank[index]->getName();
        string prenom=Bank[index]->getPrenom();
        string adresse=Bank[index]->getAdresse();
        //CreationCompteSupp(Bank,*Bank[index]);
        Bank[index]->AfficherMesComptes();
        cout << "\nQue souhaitez-vous faire ? " << endl;

        cout << "\t1- Créer un nouveau compte pour l'utilisateur " << Bank[index]->getName() << "\n";
        cout << "\t2- Déposer de l'argent sur un des comptes \n";
        cout << "\t3- Retirer de l'argent sur un des comptes \n";
        cout << "\t4- Afficher les informations d'un compte \n";
        cout << "\t5- Modifier les informations du titulaire \n";
        cout << "\t6- Cloturer un compte \n";
        cout << "\t0- Revenir au menu \n";

        cout << "Choix : ";

        cin >> choix1;

        switch (choix1)
        {
        case 1:
            CreationCompteSupp(Bank,*Bank[index]);
            cout << "Nouveau compte utilisateur créé, voici la liste de ses comptes : \n";
            Bank[index]->AfficherMesComptes();
            break;

        case 2:
            cout << "Sur quel compte souhaitez-vous effectuer un dépot ?";
            cin >> numCompte;
            Bank[index]->DepotCompte(numCompte);
            break;
        
        case 3:
            cout << "Sur quel compte souhaitez-vous effectuer un retrait ?";
            cin >> numCompte;
            Bank[index]->RetraitCompte(numCompte);
            break;
        
        case 4:
            cout << "Quel compte afficher ?";
            cin >> numCompte;
            Bank[index]->AfficherUnCompte(numCompte);
            break;
        
        case 5:

            cout << "Souhaitez-vous modifier le nom ?";

            cin >> rep;

            if(rep=='o')
            {
                cout << "Entrez le nom : ";
                cin >> nom;
            }

            cout << "Souhaitez-vous modifier le prénom ?";

            cin >> rep;

            if(rep=='o')
            {
                cout << "Entrez le prénom : ";
                cin >> prenom;
            }

            cout << "Souhaitez-vous modifier le adresse ?";

            cin >> rep;

            if(rep=='o')
            {
                cout << "Entrez l'adresse' : ";
                cin >> adresse;
            }

            Bank[index]->ModifierInformations(nom,prenom,adresse);

            cout << "Modification effectuée";

            break;
        
        case 6:
            cout << "Quel compte souhaitez-vous cloturer ?";
            cin >> numCompte;
            Bank[index]->CloturerCompte(numCompte);
            break;

        case 0:
            MenuApp(Bank);
            break;
        
        default:
            cout << "Nous n'avons par compris votre réponse, retour au Menu Principal. \n";
            MenuApp(Bank);
            break;
        }
    }
    else
    {
        cout << "Cet utilisateur n'existe pas, souhaitez-vous le créer ? (o/n)";
        cin >> choix2;
        if(choix2=='o')
        {
            CreerUser(Bank);
            MenuApp(Bank);
        }
        else
            MenuApp(Bank);
    }
    
}

int OptionsApp()
{
    return 0;
}

//Fonctions du menu
void MenuApp(vector<Titulaire*> &Bank)
{
    string tmpNom;
    int choix;
    int index;

    cout << "\nQue voulez vous faire ?\n";

        cout << "\n\t1- Créer un nouvel utilisateur;\n"; //=> Depuis un compte existant vers un compte existant (ou non ?)
        cout << "\n\t2- Rechercher un utilisateur;\n"; //=> Option de le créer s'il n'existe pas
        cout << "\n\t3- Supprimer un utilisateur; \n"; //=> Exporter liste, Modifier taux, Modifier date du jour
        cout << "\n\t4- Afficher toute ma banque; \n"; //=> Exporter liste, Modifier taux, Modifier date du jour
        cout << "\n\t0- Quitter l'application\n";  

        cout << "\nChoix : ";
        cin >> choix;
        cout << "\n";
        
    // int select;

    switch (choix)
    {
    case 1:
        CreerUser(Bank);
        Bank[0]->AfficherMesComptes();
        MenuApp(Bank); 
        break;
    
    case 2:
        RechercherUser(Bank);
        MenuApp(Bank); 
        break;
    
    case 3:
        
        cout << "Quel est le nom de l'utilisateur que vous souhaitez supprimer ? ";
        cin >> tmpNom;
        if(!ExistingUser(Bank,tmpNom))
            cout << "Cet utilisateur n'existe pas et ne peut donc pas être supprimé. Retour au menu.";
        else
        {
            index = IndexUser(Bank, tmpNom);
            Bank.erase(Bank.begin()+(index));
            cout << "Utilisateur supprimé. Retour au menu.";
        }
        
        MenuApp(Bank); 
        break;
    case 4:
        for (int i = 0; i < Bank.size(); i++)
        {
            Bank[i]->AfficherMesComptes();
        }
        MenuApp(Bank);
        break;
    case 0:
        EcritureFichier(Bank);
        break;
    
    default:
        cout << "Nous n'avons pas compris votre choix";
        MenuApp(Bank); 
        break;
    }
}


//Après rechercher user
//Plusieurs options :
//Créer un nouveau compte
//Afficher ses comptes
//Sélectionner un compte =>
    //Afficher  ==> Use class::AfficherCompte

    //Historique
    //Simulation
