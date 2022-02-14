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
        string getNomJoueur(){
            return nom;
        }
        void setNomJoueur(string N){
            nom=N;
        }
        string getPrenomJoueur(){
            return prenom;
        }
        void setPrenomJoueur(string P){
            prenom=P;
        }
        int getAgeJoueur(){
            return age;
        }
        void setAgeJoueur(int A){
            age=A;
        }
        string getPositionJoueur(){
            return position;
        }
        void setPositionJoueur(string POS){
            position=POS;
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
       string getNomEntraineur(){
            return nom;
        }
        void setNomEntraineur(string n){
            nom =n;
        }
        string getPrenomEntraineur(){
            return prenom;
        }
        void setPrenomEntraineur(string p){
            prenom = p;
        }
        int getAgeEntraineur(){
            return age;
        }
        void setAgeEntraineur(int a){
            age = a;
        }
};

class Arbitre : public Personne {
    public:
        Arbitre(){};
        Arbitre(string n,string pr){
            nom = n;
            prenom = pr;
        }

        void afficher(){
            cout<< "Les informations de l'arbitre :" << endl;
            cout << "Nom : " << nom << endl;
            cout << "Prenom : " << prenom << endl;
        }
};

struct Equipes_joueuses
{
    Equipe e;
    Joueur j[1];
    Entraineur en;
};

void pass(Equipes_joueuses *st_equi, int x, int cont){
    int b1, b2;
    int tmp = 0;
    string nom, prenom;

    x /= 2;

    Equipes_joueuses *g = new Equipes_joueuses[x];

    cout << "\n\tTour " << cont << " :" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "\n\tMatch " << i+1 << " :" << endl;

        cout << "Nom de l'arbitre : " << endl;
        cin >> nom;
        cout << "Prenom de l'arbitre :" << endl;
        cin >> prenom;

        Arbitre arb(nom, prenom);

        cout << "Combat de but a marqué l'equipe " << st_equi[tmp].e.getNom() << " ?" << endl;
        cin >> b1;
        cout << "Combat de but a marqué l'equipe " << st_equi[tmp +1].e.getNom() << " ?" << endl;
        cin >> b2;
        if (b1 > b2)
        {
            g[i].e = st_equi[tmp].e;
            cout << "L'équipe " << st_equi[tmp].e.getNom() << " a gagné le match !" << endl;
        }else if(b1 < b2){
            g[i].e = st_equi[tmp+1].e;
            cout << "L'équipe " << st_equi[tmp +1].e.getNom() << " a gagné le match !" << endl;
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

void afficherUneEquipe(Equipes_joueuses *equipes, int n){
    string eq;

    cout << "Entrez le nom de l'equipe :" << endl;
    cin >> eq;
    
    cout << "\n\n\tAffichage des informations de l'equipe :" <<endl;
    for (int i = 0; i < n; i++)
    {
        if (equipes[i].e.getNom() == eq)
        {
            for (int j = 0; j < 1; j++)
            {
                equipes[i].j[j].afficher();
            }
            equipes[i].en.afficher();
        }
        
    }
}

Equipes_joueuses *saisie(int n){
    string nom, prenom, natio, position;
    int age;

    Equipes_joueuses *equipes = new Equipes_joueuses[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Info Equipe " << i+1 << " :" << endl;
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

void modificationEntraineur (Equipes_joueuses *equipes,int n){
    int choic;
    string ent;
    string nn,pp,chercher;
    int aa;
    cout << "\n\n\tEntrez le nom de l'equipe :" << endl;
    cin >> chercher;

    for (int i = 0; i < n; i++)
    {
        if(equipes[i].e.getNom() == chercher)
        {       
            cout << "\n\n\tEntrez l'entraineur a modifier ses informations :" << endl;
            cin >> ent;
            if(ent==equipes[i].en.getNomEntraineur())
            {
                do{
                    cout <<"Que voulez vous modifier ?" <<endl;
                    cout<<"0-Quitter"<<endl;
                    cout<<"1-Nom "<<endl;
                    cout<<"2-Prenom "<<endl;
                    cout<<"3-age"<<endl;
                    cin>>choic;

                    switch (choic)
                    {
                        case 0:  
                            break;

                        case 1:
                            cout <<"donner le nouveau nom "<<endl;
                            cin>>nn;
                            equipes[i].en.setNomEntraineur(nn);
                            break;
                        
                        case 2:
                            cout <<"donner le nouveau prenom "<<endl;
                            cin>>pp;
                            equipes[i].en.setPrenomEntraineur(pp);
                            break;
                        case 3:
                            cout <<"Donnez l'age d'entraineur" << endl;
                            cin>> aa;
                            equipes[i].en.setAgeEntraineur(aa);
                            break;
                    }
                }while(choic!=0);
                }
            else
            {
                cout<<"Cet entraineur n'existe pas "<<endl;
            }
        }
    }
}
    
void modificationJoueur (Equipes_joueuses *equipes,int n){
    int choice, aa;
    string nn,pp,posi,chercher,c;
    
    cout << "\n\n\tEntrez le nom de l'equipe :" << endl;
    cin >> chercher;
 
    for(int i=0;i<n;i++)
    {
        if(equipes[i].e.getNom() == chercher)
        {       
        cout << "\n\n\tEntrez le joueur a modifier ses informations :" << endl;
        cin >> c;
            for(int k=0;k<1;k++)
            {
                if(c==equipes[i].j[k].getNomJoueur())
                {
                    do{
                        cout <<"\nQue voulez vous modifier ?" <<endl;
                        cout<<"0-Quitter"<<endl;
                        cout<<"1-Nom "<<endl;
                        cout<<"2-Prenom "<<endl;
                        cout<<"3-Position"<<endl;
                        cout<<"4-age"<<endl;
                        cin>>choice;

                        switch (choice)
                            {
                            case 0:  
                                cout << "Fin de modification" << endl;
                                break;                            
                            case 1:
                                cout <<"donner le nouveau nom "<<endl;
                                cin>>nn;
                                equipes[i].j[k].setNomJoueur(nn);
                                break;

                            case 2:
                                cout <<"donner le nouveau prenom "<<endl;
                                cin>>pp;
                                equipes[i].j[k].setPrenomJoueur(pp);
                                break;

                            case 3:
                                cout <<"donner la nouvelle position "<<endl;
                                cin>>posi;
                                equipes[i].j[k].setPositionJoueur(posi);
                                break;

                            case 4:
                                cout <<"Donnez l'age du joueur" << endl;
                                cin>> aa;
                                equipes[i].j[k].setAgeJoueur(aa);
                                break;
                        }
                    }while(choice!=0);
                }
                else
                {
                    cout<<"Ce joueur n'existe pas "<<endl;
                }
            }   
        }
    }
}

void AffichEqp(Equipes_joueuses *equipes,int n){
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
    char cc;

    Equipes_joueuses *equipes ;
    do
    {
        cout <<" -------------------------MENU-------------------------------"<<endl;
        cout << "|   1-L'ajout  des informations des equipes                 |" << endl;
        cout << "|   2-Creation d'une compétition                            |" << endl;
        cout << "|   3-Affichage des equipes participant dans la competition |" << endl;
        cout << "|   4-Chercher les informations d'une equipe                |"<< endl;
        cout << "|   5-Modification des informations                         |"<<endl;
        cout << "|   6-Quitter                                               |"<<endl;
        cout <<" -------------------------------------------------------------" <<endl;
    
        cout <<"\nVeuillez entrez un choix :  "<<endl;
        cin>>choix;
        switch (choix)
        {
            case 0:
                cout << "Fin du program." << endl;
                delete equipes;
                break;
            
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
                afficherUneEquipe(equipes, n);
                break;
            case 5:
                cout <<"Vous voulez modifier les infos du joueur ou de l'entraineur ? (j/e) ";
                cin>>cc;
                if (cc=='j')
                {
                    modificationJoueur(equipes,n);  
                }
                if(cc=='e')
                {
                    modificationEntraineur(equipes,n);
                }           
                break;
        }     
    } while (choix!=6);    
}
