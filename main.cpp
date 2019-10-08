#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "niveau.h"

using namespace std;


//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- LES CLASSES --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------


class Personnage
{
    public:
    Personnage(string n, int v, int m)
    : nom(n), vie(v), mana(m)
    {}

    string getNom() const { return nom; }
    int getVie() const { return vie; }
    int getMana() const { return mana; }

    void setNom(string n) { nom = n;};
    void setVie(int v) { vie = v;};
    void setMana(int m) { mana = m;};

    private:
    string nom;
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

    Personnage hero(nom, 100, 100);

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

    Personnage mechant(nom, 100, 100);

    return mechant;
}

    string lstAttaques[][5] =
    {
        {"0","Attaque","10","100","2"},
        {"1","Tonnerre","30","90","2"},
        {"2","Boule de feu","20","95","2"},
        {"3","Trou Noir","120","85","2"},
        {"4","Lumicanon","90","100","2"},

    };

void attaque(Personnage attaquant, Personnage cible){

    cout << attaquant.getNom() << " Choissisez votre attaque (numero) : " << endl;

    int choice;

    int i,j;

   /* Affichage de la liste des attaques */
   for ( i = 0; i < 5; i++ ) {
      for ( j = 0; j < 5; j++ ) {
        if( j == 0 || j == 1 ){
         cout << " " << lstAttaques[i][j] ;
        }
      }
      cout << endl;
   }

   cout << lstAttaques ;






}


//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- MAIN ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------



int main()
{


    Personnage hero = creaHero();
    cout << "Nom hero : " << hero.getNom() << endl;
    cout << "Vie hero : "  << hero.getVie() << endl;
    cout << "Mana hero : " << hero.getMana() << endl << endl << endl;

    Personnage mechant = creaMechant();
    cout << "Nom mechant : " << mechant.getNom() << endl;
    cout << "Vie mechant : " << mechant.getVie() << endl;
    cout << "Mana mechant : " << mechant.getMana() << endl;

    cout << " \n " ;

    attaque(hero,mechant);

    if ( hero.getVie() > mechant.getVie() ){
        attaque(mechant,hero);
    } else {
        attaque(hero,mechant);
    }

    if( hero.getVie() == 0){
        cout << "le mechant a gagne " << endl;
    } else {
        cout << "le hero a gagne " << endl;
    }

    return 0;
}
