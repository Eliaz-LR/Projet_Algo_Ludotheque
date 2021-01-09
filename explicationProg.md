# Explication du code et des differents choix dans le projet
Première question au moment de la creation du projet : Utiliser un tableau ou une liste chainée ?
Nous avons fait le choix d'utiliser un tableau car nous n'avons pas besoin d'ajouter des données au milieu des tableaux. Chaque résérvation, adherent, etc... prend un nouvel ID et se place donc à la fin des tableaux/fichiers car les listes sont triées par id.

# Plan des menus
### Menu principal
- #### Espace Adhérent
    - Emprunts en cours
    - Nouvel emprunt
    - Nouvelle réservation
    - Annuler une réservation
    - Retour emprunt (avec transforamtion des réservations en emprunts automatiques)
- #### Modification des jeux
    - Ajouter un jeu (dans la base de donnée ou en stock)
    - Supprimer un jeu (base de donnée/stock)
- Afficher les jeux disponibles
- Afficher les emprunts en cours
- Afficher les reservations pour un jeu donné
- Sauvegarde vers les fichiers .txt

## Le .h
Nous avons fait le choix de créer des types pour chaque types d'objets des fichiers (adherents, jeux, emprunts et reservation).
Nous avons aussi fait un type date pour les dates dans les differents types.

## menu.c
menu.c regroupe differentes fonctions lié au fonctionnement du menu (plus précisémment celles liées à l'affichage et au choix des différents menus). Elles sont toutes refferencées dans le .h pour pouvoir etre accedées dans le fichier principal. La fonction principale de chaque menu reste neanmoins dans le fichier principale car elles font appel à d'autres fonction de ce fichier et ont parfois des particularitées qui leur sont propre.

## Les fonctions pour charger les fichiers

J'ai crée une fonction par fichier à charger, la raison majeure derière ce choix est que on ne peut pas reserver de la memoire via malloc/realloc pour un parametre importé par adresse (sous forme de pointeur).

## La fonction AffichageEmprunts

La fonction Affichage Emprunts utilise 2 fonctions similaires pour chercher la ligne d'un ID. La difference de ces 2 fonctions est que l'une prend un tableau de type Jeux en entrée là où l'autre prend un tableau de type Adherents en entrée. Il n'est possible de ne faire rentrer que la partie id (de type int) de ces structs, d'où la presence de ces 2 fonctions séparées.