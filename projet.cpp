#include<iostream>

using namespace std;

class Equipe {
    private:
        string nom;
        string nationalite;

    public:
        Equipe(){}
        Equipe(string no, string na){
            nom = no;
            nationalite = na;
        }

        string getNom(){
            return nom;
        }
        void afficher(){
            cout<<"Les informations de l'equipe  :" << endl;
            cout << "Nom : " << nom << endl;
            cout << "Nationalité : " << nationalite << endl;      
        }
};

class Personne{
    protected:
        string nom;
        string prenom;
        int age;

    public:
        Personne(){}
        Personne(string n, string pr, int a){
            nom = n;
            prenom = pr;
            age = a;
        }

        virtual void afficher(){}
};

class Joueur : public Personne{
    private:
        string position;
    public:
        Joueur(){}
        Joueur(string n, string pr, int a, string pos):Personne(n,pr,a){
            position = pos;
        }

        void afficher(){
            cout<<"Les informations du joueur  :"<<endl;
            cout << "Nom : " << nom << endl;
            cout << "Prenom : " << prenom << endl;
            cout << "Age : " << age << endl;
            cout << "Position : " << position << endl;
        }
};



class Entraineur : public Personne {
    public:
        Entraineur(){};
        Entraineur(string n,string pr,int a):Personne(n,pr,a){}

        void afficher(){
            cout<< "Les informations de l'entraineur :" << endl;
            cout << "Nom : " << nom << endl;
            cout << "Prenom : " << prenom << endl;
            cout << "Age : " << age << endl;
        }
};

class Arbitre : public Personne {
    public:
        Arbitre(){};
        Arbitre(string n,string pr,int a):Personne(n,pr,a){}

        void afficher(){
            cout<< "Les informations de l'arbitre :" << endl;
            cout << "Nom : " << nom << endl;
            cout << "Prenom : " << prenom << endl;
            cout << "Age : " << age << endl;
        }
};


struct Equipes_joueuses
{
    Equipe e;
    Joueur j[1];
    Entraineur en;
};


struct Equipes_tours
{
    Equipes_joueuses e_tour;
};

void pass(Equipes_joueuses *st_equi, int x, int cont){
    
    int tmp = 0;
    int passe;
    
    x /= 2;

    cout << "\n\tTour " << cont << " :" << endl;
    Equipes_joueuses *g = new Equipes_joueuses[x];
    for (int i = 0; i < x; i++)
    {
        int numero = 1;
        cout << "\n\tChoix :" << endl;
        cout << "Equipe "<< numero <<" : " << st_equi[tmp].e.getNom() << endl;
        cout << "Equipe "<< numero+1 << " : " << st_equi[tmp+1].e.getNom() << endl;
        cout << "Quel equipe passe au tour suivant (Tapez \"1\" pour equipe 1 et \"2\" pour equipe 2) ?" << endl;
        cin >> passe;
        if (passe == 1)
        {
            g[i].e = st_equi[tmp].e;
        }else if(passe == 2){
            g[i].e = st_equi[tmp+1].e;
        }
        tmp += 2;
    }

    if (x>1)
    {
        cout << "\n\tLes equipes qui passe au tour suivant :" << endl;
        for (int i = 0; i < x; i++)
        {
            g[i].e.afficher();
        }
    }
    else if(x == 1){
        cout << "\n\tVainqueur :" << endl;
        g[0].e.afficher();
    }

    cont += 1;

    if (x>1)    pass(g, x, cont);
}




void afficher(Equipes_joueuses *equipes, int n){
    cout << "\n\n\tAffichage des equipes qui participent a cette competition :" <<endl;
    for (int i = 0; i < n; i++)
    {
        equipes[i].e.afficher();
    }
}



Equipes_joueuses *saisie(int n){
    string nom, prenom, natio, position;
    int age;

    Equipes_joueuses *equipes = new Equipes_joueuses[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nInfo Equipe " << i+1 << " :" << endl;
        cout << "Entrez le nom :" << endl;
        cin >> nom;
        cout << "Entrez la nationnalité :" << endl;
        cin >> natio;
        Equipe equipe(nom, natio);
        equipes[i].e = equipe;


        cout << "\nInfo Joueurs :" << endl;
        for (int j = 0; j < 1; j++)
        {
            cout << "Joueur " << j+1 << " :" << endl;
            cout << "Entrez le nom :" << endl;
            cin >> nom;
            cout << "Entrez le prenom :" << endl;
            cin >> prenom;
            cout << "Entrez l'age :" << endl;
            cin >> age;
            cout << "Entrez la position :" << endl;
            cin >> position;
            Joueur joueur(nom, prenom, age, position);
            equipes[i].j[j] = joueur;
        }

        cout << "\nInfo entraineur" << endl;
        cout << "Entrez le nom :" << endl;
        cin >> nom;
        cout << "Entrez le prenom :" << endl;
        cin >> prenom;
        cout << "Entrez l'age :" << endl;
        cin >> age;
        Entraineur entraineur(nom, position, age);
        equipes[i].en = entraineur;

    }

    return equipes;
}



void chercher (Equipes_joueuses *equipes,int n){
     string chercher;
    cout << "\n\n\tEntrez le nom de l'equipe pour afficher ses infos :" << endl;
    cin >> chercher;
    for (int i = 0; i < n; i++)
    {
        if (chercher == equipes[i].e.getNom())
        {
            equipes[i].e.afficher();
            for (int j = 0; j < 1; j++)
            {
                equipes[i].j[j].afficher();
            }
            equipes[i].en.afficher();   
        }
    }
}




main(){
    int cont = 1;
    int n,choix;

 Equipes_joueuses *equipes ;
    do
    {
    system ("cls");
    cout <<" -------------------------MENU-------------------------------"<<endl;
    cout << "|  1-L'ajout  des informations des equipes                 |" << endl;
    cout << "|  2-Creation d'une compétition                            |" << endl;
    cout << "|   3-Affichage des equipes participant dans la competition|" << endl;
    cout << "|   4-Affichage de la liste des joueurs d'une equipe       |"<< endl;
    cout << "|   5- Quitter                                             |"<<endl;
    cout <<" ------------------------------------------------------------" <<endl;
    cout <<"\nVeuillez entrez un choix :  "<<endl;
    cin>>choix;
     switch (choix)
    {
        case 1:
            cout << "Entrez le nombre d'equipe qui joue :" << endl;
            cin >> n;
           equipes = new Equipes_joueuses[n];
            equipes = saisie(n);
            break;
        case 2:
            pass(equipes, n, cont);
            break;
        case 3:
            afficher(equipes, n);
            break;
        case 4:
            chercher(equipes, n);
            break;
        case 5:
            exit(0);
            break;
    }

     
    } while (choix!=5);
    
}