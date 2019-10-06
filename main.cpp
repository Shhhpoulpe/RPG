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

}

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- MAIN ---------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------



int main()
{
    /*
    Personnage hero = creaHero();
    cout << hero.getNom() << endl;
    cout << hero.getVie() << endl;
    cout << hero.getMana() << endl;

    Personnage mechant = creaMechant();
    cout << mechant.getNom() << endl;
    cout << mechant.getVie() << endl;
    cout << mechant.getMana() << endl;
*/
    cout << generationNomMechant() << endl;
    return 0;
}
