#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "niveau.h"

using namespace std;

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- LES VARIABLES ------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------


string lstAttaques[][5] =
{
    {"0","Attaque","10","100","2"},
    {"1","Tonnerre","30","90","2"},
    {"2","Boule de feu","20","95","2"},
    {"3","Trou Noir","120","85","2"},
    {"4","Lumicanon","90","100","2"},
};

int lstDegat[5] ={10,30,20,120,90};

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- LES CLASSES --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------


class Personnage
{
    public:
    Personnage(string n, bool h, int v, int m)
    : nom(n), hero(h), vie(v), mana(m)
    {}

    string getNom() const { return nom; }
    bool getHero() const { return hero; }
    int getVie() const { return vie; }
    int getMana() const { return mana; }

    void setNom(string n) { nom = n;};
    void setHero(bool h) { hero = h;};
    void setVie(int v) { vie = v;};
    void setMana(int m) { mana = m;};

    private:
    string nom;
    bool hero;
    int vie;
    int mana;
};

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- LES FONCTIONS ------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------


Personnage creaHero()
{
    string nom;

    cout << "Quel est votre nom aventurier?" << endl;
    cout << "Votre nom : ";
    getline(cin,nom);
    cout << endl;

    Personnage hero(nom, 1, 100, 100);

    return hero;
}

string generationNomMechant()
{
    srand(time(0));
    string listeNom[] = {"leBlanc","leGris","leNoir","le Maudit","le maitre des haches","le maitre des lames","le grand","le petit"};
    string listePrenom[] = {"Draven","Balthazar","Jinx","Igor","Mathieu","Jack","Oscar","Nicolas","Bob"};
    string nom =listePrenom[rand() % (sizeof(listePrenom)/sizeof(*listePrenom))] + " " + listeNom[rand() % (sizeof(listeNom)/sizeof(*listeNom))];
    return nom;
}

Personnage creaMechant()
{
    string nom = generationNomMechant();

    Personnage mechant(nom, 0, 100, 100);

    return mechant;
}

void afficheStat(Personnage hero, Personnage mechant)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Nom hero : " << hero.getNom() << endl;
    cout << "Vie hero : "  << hero.getVie() << endl;
    cout << "Mana hero : " << hero.getMana() << endl << endl << endl;
    cout << "Nom mechant : " << mechant.getNom() << endl;
    cout << "Vie mechant : " << mechant.getVie() << endl;
    cout << "Mana mechant : " << mechant.getMana() << endl << endl;
}

Personnage attaque(Personnage attaquant, Personnage victime)
{
    int choice;
    int pvVictime = victime.getVie();
    int i,j;

    if(attaquant.getHero())
    {
        cout << attaquant.getNom() << " Choissisez votre attaque (numero) : " << endl;

        /* Affichage de la liste des attaques */
        for ( i = 0; i < 5; i++ ) {
            for ( j = 0; j < 5; j++ ) {
                if( j == 0 || j == 1 ){
                    cout << " " << lstAttaques[i][j] ;
                }
            }
            cout << endl;
        }

        cin >> choice ;

        pvVictime -= lstDegat[choice];
        victime.setVie(pvVictime);

    } else{

        pvVictime -= lstDegat[1];
        victime.setVie(pvVictime);

    }


    return victime;


}

void Combat(Personnage hero, Personnage mechant)
{
    afficheStat(hero, mechant);

    if ( hero.getVie() >= mechant.getVie() ){
        mechant = attaque(hero, mechant);
    } else {
        hero = attaque(mechant, hero);
    }

    if( hero.getVie() <= 0){
        cout << "le mechant a gagne " << endl;
    } else if (mechant.getVie() <= 0) {
        cout << "le hero a gagne " << endl;
    } else {
        Combat(hero, mechant);
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- MAIN ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------



int main()
{

    Personnage hero = creaHero();
    Personnage mechant = creaMechant();

    Combat(hero, mechant);

    return 0;
}
