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
    {"3","Trou Noir","25","85","2"},
    {"4","Lumicanon","30","100","2"},
};

int lstDegat[5] ={10,30,20,25,30};

int messageId;

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- LES CLASSES --------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------


class Personnage
{
    public:
    Personnage(string n, bool h, int v, int m)
    : nom(n), hero(h), vie(v)
    {}

    string getNom() const { return nom; }
    bool getHero() const { return hero; }
    int getVie() const { return vie; }

    void setNom(string n) { nom = n;};
    void setHero(bool h) { hero = h;};
    void setVie(int v) { vie = v;};

    private:
    string nom;
    bool hero;
    int vie;
};

//-------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- LES FONCTIONS ------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------

int MessageDebut(Personnage mechant , Personnage hero)
{
    int i;
    string message[] =
    {
        "Vous entrez dans une taverne et " + mechant.getNom() + " vous acceuil avec un air menaçant",
        "Vous voulez couper du bois mais " + mechant.getNom() + " plante sa hache dedans avant vous et veux vous le voler",
        "Vous marchez dans la rue mais " + mechant.getNom() + " est sur votre trottoire et vous l'aggressez sans raison valable",
        "Olala, le scénario vous force a affronter " + mechant.getNom() +" quel choc :O",
        mechant.getNom() + ": OHOH, tu oses t'approcher de moi? \n" + hero.getNom() + ": je ne peut pas te battre sans m'approcher de toi",
        "Vous decouvrez que " + mechant.getNom() + " joue des personnages de distance sur la top lane",
        mechant.getNom() + " joue a des jeux videos et est en retard pour son projet, il met en retard son camarade",
        mechant.getNom() + " dit pain au chocolat au lieu de chocolatine, il faut le tuer",
        mechant.getNom() + " pense qu'ecrire un scenario est facile, vous voulez le frapper",
        mechant.getNom() + " ne met pas d'ecouteurs dans les transports publiques, il merite une lecon",
        mechant.getNom() + " n'aime pas minecraft, vous sortez votre hache en diamant",
        mechant.getNom() + " pense qu'on manque d'idee pour les intros, vous n'etes pas d'accord",
        mechant.getNom() + " trouv de fote dortografe & vou arcel"
    };

    srand(time(0));
    i = rand() % (sizeof(message)/sizeof(*message));
    cout << message[i] << "\n\n\n";
    return i;
}

void Victoire(Personnage mechant, Personnage hero, int i)
{
    string message[] =
    {
        mechant.getNom() + " est KO, vous pouvez boire votre bierre",
        mechant.getNom() + " est vaincu, vous avez voir bois",
        mechant.getNom() + " n'est plus sur votre trottoire, vous etes un monstre",
        "Olala, vous avez vaincu " + mechant.getNom(),
        hero.getNom() + ": La prochaine chose que tu vas dire est : C'EST IMPOSSIBLE \n" + mechant.getNom() + ": C'EST IMPOSSIBLE !!!",
        "Felicitation, vous venez d'eradiquer le sida",
        mechant.getNom() + " s'appelait en vrai Maxime",
        "La team chocolatine viens de gagner",
        "Il n'avait pas tord, vous vous sentez très mal de l'avoir assassinee",
        mechant.getNom() + " a ete retrouve mort rouee de coup",
        "En fuyant le combat " + mechant.getNom() + " c'est pris un creeper en plein visage ",
        mechant.getNom() + " a totalement raison",
        "lortograf cere a ri1"
    };
    cout << message[i];
}

void Defaite(Personnage mechant, Personnage hero, int i)
{
    string message[] =
    {
        mechant.getNom() + " bois une bierre sur votre corps",
        mechant.getNom() + " a volée tout le bois",
        "Vous perdez votre combat et la police vous arrete pour agression",
        "Olala, vous avez perdu",
        mechant.getNom() + ": ROADA ROLLA DAH",
        mechant.getNom() + " a gagne sa top lane, quelle surprise",
        mechant.getNom() + " n'est finalement pas en retard et tout est calculé",
        "La team pain au chocolat a gagné, la france est en deuil",
        mechant.getNom() + " avais tord et on ne sais meme pas comment faire un scenario de defaite dans ces conditions",
        "Avec la puissance de Yung Gravy, le train c'est transformee en Gravy Train",
        mechant.getNom() + " sors son sniper de Phantom Force sur Roblox et vous 360 noscope across the map",
        mechant.getNom() + " pense qu'on manque d'idee pour les defaites et a raison",
        "L'ortographe regne sur la terre "
    };
    cout << message[i];
}

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
    cout << "Nom hero : " << hero.getNom() << endl;
    cout << "Vie hero : "  << hero.getVie() << endl << endl << endl;
    cout << "Nom mechant : " << mechant.getNom() << endl;
    cout << "Vie mechant : " << mechant.getVie() << endl << endl;
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
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        if (choice <= 4)
        {
            pvVictime -= lstDegat[choice];
            victime.setVie(pvVictime);
            cout << "Le hero a utilise l'attaque " << lstAttaques[choice][1] << " et a fais " << lstDegat[choice] << " degats" << endl << endl;
        } else {
            cout << "Vous ratez votre attaque" << endl;
        }


    } else{
        srand(time(0));
        choice = rand() % 4;
        pvVictime -= lstDegat[choice];
        victime.setVie(pvVictime);
        cout << "Le mechant a utilise l'attaque " << lstAttaques[choice][1] << " et a fais " << lstDegat[choice] << " degats" << endl << endl;
    }


    return victime;


}

void Combat(Personnage hero, Personnage mechant)
{
    if ( hero.getVie() >= mechant.getVie() ){
        mechant = attaque(hero, mechant);
        hero = attaque(mechant, hero);
    } else {
        hero = attaque(mechant, hero);
        mechant = attaque(hero, mechant);
    }

    if( hero.getVie() <= 0){
        Defaite(mechant, hero, messageId);
    } else if (mechant.getVie() <= 0) {
        Victoire(mechant, hero, messageId);
    } else {
        afficheStat(hero, mechant);
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

    messageId = MessageDebut(mechant, hero);
    Combat(hero, mechant);
}
