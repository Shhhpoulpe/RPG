# RPG Vincent Meechai & Maxime Jobard

## Principe de l'application

1. La partie commence en demandant au joueur de choisir le nom du héro
2. Un message de scénario choisi aléatoirement s'affiche
3. Le combat commence
    * Choisissez une attaque en tapant l'ID de l'attaque
    * Les PV s'affichent et vous rejouez jusqu'a ce qu'un personnage soit KO
4. Un message de victoire s'affiche et vous demande si vous voulez rejouer

## Les variables globales

1. string lstAttaques[][5] : Liste des attaques avec l'id, le nom et les dégats
2. int lstDegat[] : Liste des dégats en int car on arrive pas faire passer des string en int
3. int messageId :  Id du message en début de combat pour correspondre au message de fin

## La Classe Personnage

Une classe Personnage a été créer pour que le héro et le méchant ce partage

### Les paramètres 

1. string nom : Le nom du personnage
2. bool hero : True si le personnage est le hero, False si il est le mechant
3. int vie : Vie du personnage

## Les fonctions

### int MessageDebut(Personnage mechant , Personnage hero)

* La fonction affiche un message de scénario pour mettre en scène le combat
* Le message est choisi aléatoirement avec la fonction srand(time(0)) et rand()
* La fonction retourne l'id du message pour plus tard
* La fonction récupères les personnages pour intégrer leurs noms dans les textes

### void Victoire(Personnage mechant, Personnage hero, int i)

* La fonction affiche un message de victoire pour le héro
* La fonction utilise la variable i pour savoir quelle message de début a été utilisé

### void Defaite(Personnage mechant, Personnage hero, int i)

* La fonction affiche un message de defaite pour le héro
* La fonction utilise la variable i pour savoir quelle message de début a été utilisé

### Personnage creaHero()

* La fonction créée un héro avec le nom donnée par le joueur

### string generationNomMechant()
* Génère un nom procéduralement a partir d'une liste de nom et de prénom

### Personnage creaMechant()
* La fonction créée un méchant avec le nom donnée par la fonction generationNomMechant()

### void afficheStat(Personnage hero, Personnage mechant)
* Affiche le nom et la vie des personnages

### Personnage attaque(Personnage attaquant, Personnage victime)
* Si attaquant.getHero() == True
    * C'est le héro qui attaque
    * Affiche la liste des attaques
    * Demande de séléctionner une attaque
    * Si l'attaque saisie n'existe pas, l'attaque rate, sinon il fait l'attaque

* Si attaquant.getHero() == False
    * C'est le méchant qui attaque
    * Fait une attaque aléatoirement

* La fonction retourne la victime pour changer ses PV

### void Combat(Personnage hero, Personnage mechant)
* Si le héro a autant ou moins de PV que le méchant, il attaque en premier ce tour-ci
* La fonction vérifie si quelqu'un est KO, sinon, il relance la fonction Combat()

### bool restartPrompt()
* Demande au joueur si il veut recommancer une partie
* Retourne True ou False