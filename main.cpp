#include <iostream>

using namespace std;

int main()
{
    int puissance, pouvoir, vie, niveau, choix, exp;
    int evilPuissance, evilPouvoir, evilVie, evilNiveau;
    int joueurNiveau = 1;
    cout << "Choisis une classe : (numero classe) " << endl;
    cout << "1. Guerrier" << endl;
    cout << "2. Mage" << endl;
    int joueurClasse;
    cin >> joueurClasse;
    if (joueurClasse == 1)
    {
        puissance = 10;
        pouvoir = 2;
        vie = 100;
        cout << "Tu as choisis la classe Guerrier! Voici tes stats!" << endl;
        cout << "Puissance = " << puissance << endl << "Pouvoir = " << pouvoir << endl << "Vie = " << vie << endl;
    }
    else if (joueurClasse == 2)
    {
        puissance = 3;
        pouvoir = 15;
        vie = 90;
        cout << "Tu as choisis la classe Mage! Voici tes stats!" << endl;
        cout << "Puissance = " << puissance << endl << "Pouvoir = " << pouvoir << endl << "Vie = " << vie << endl;
    }


    while ( vie > 0){
        cout << "Bienvenue! Quel est votre choix?" << endl << "\n 1. Tuer les monstres!" << "\n 2. Rester chez soi" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << "1. Un gobelin sauvage lvl 1 " << endl;
            cout << string( 100, '\n' );
            cout << "C'est l'heure du duel!" << endl;
            evilVie = 40;
            evilPuissance = 4;
            evilPouvoir = 0;


            while (vie > 0)
            {
                if (evilVie < 0)
                {

                    cout << "Vous avez tue le gobelin! "<< endl;
                    cout << "Veuillez continuer (n'importe quel chiffre) :" << endl;
                    cin >> choix;
                    cout << string( 100, '\n' );

                    break;
                }
                vie -= evilPuissance * 2;
                cout << "Le gobelin frappe et fait " << evilPuissance * 2 << " de degat sur vous!" << "\nVous avez " << vie << " point de vie restant!" << endl;
                cout << "Choississez : " << "\n 1. Attack" << "\ 2. Lancer un sort" << endl;
                cin >> choix;
                if (choix == 1)
                {
                    evilVie -= puissance * 2;
                    cout << "vous avez balancez votre arme qui fait " << puissance * 2 << " de degat sur le gobelin!" << endl;
                    cout << "le gobelin a " << evilVie << " point de vie!" << endl;
                }
                else if (choix == 2)
                {
                    evilVie -= pouvoir * 2;
                    cout << "vous avez lance une boule de feu qui fait " << pouvoir * 2 << " de degat sur le gobelin!" << endl;
                    cout << "le gobelin a " << evilVie << " point de vie!" << endl;
                }

            }
        }
    }
    if (vie < 0)
        cout << endl;
        cout << "Vous etes mort" << endl;


    return 0;
}
