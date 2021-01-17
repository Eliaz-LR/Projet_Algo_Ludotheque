# Explication du code et des differents choix dans le projet

Première question au moment de la creation du projet : Utiliser un tableau ou une liste chainée ?
Nous avons fait le choix d'utiliser un tableau car **nous n'avons pas besoin d'ajouter des données au milieu des tableaux**. Chaque résérvation, adherent, etc... prend un nouvel ID et se place donc à la fin des tableaux/fichiers car les listes sont triées par id.

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

# Construction du programme

## Le .h
Nous avons fait le choix de créer des types pour chaque types d'objets des fichiers (adherents, jeux, emprunts et reservation).
Nous avons aussi fait un type date pour les dates dans les differents types.

## menu.c
menu.c regroupe differentes fonctions lié au fonctionnement du menu (plus précisémment celles liées à l'affichage et au choix des différents menus). Elles sont toutes refferencées dans le .h pour pouvoir etre accedées dans le fichier principal. La fonction principale de chaque menu reste neanmoins dans le fichier principale car elles font appel à d'autres fonction de ce fichier et ont parfois des particularitées qui leur sont propre.

## Les fonctions pour charger les fichiers
J'ai crée une fonction par fichier à charger, la raison majeure derière ce choix est que on ne peut pas reserver de la memoire via malloc/realloc pour un parametre importé par adresse (sous forme de pointeur).

## Les fonctions search
Les fonctions searchJeux/Adherent/Emprunt servent toute les trois à obtenir l'emplacement dans le tableau de données a partir de l'ID de ces données. Ces données sont referées dans les autres tableau par leur ID. Si l'on veux acceder à d'autres ils nous faut pouvoir acceder a toutes les données d'un element a partir de son ID.

## La fonction AffichageEmprunts
La fonction Affichage Emprunts utilise 2 fonctions de recherche. La difference de ces 2 fonctions est que l'une prend un tableau de type Jeux en entrée là où l'autre prend un tableau de type Adherents en entrée. Il n'est possible de ne faire rentrer que la partie id (de type int) de ces structs, d'où la presence de ces 2 fonctions séparées.

## L'espace adherent
Pour certaines fonction, on commence par entrer le nom, nous avons donc choisi de reunir toute ces fonctions dans un même menu. Ce menu fait une sauvegarde auto de la liste des adherents. Cela a été fait pour reduire le nombre de parametre des fonctions, ameillorer la lisibilité du programme et eviter rendre le programme plus ergonomique.

## La fonction de retour emprunt
Cette fonction est contenue dans l'espace adherent. Elle commence par demander quel est le jeu retourné. Elle supprime l'emprunt correspondant du tableau d'emprunts puis examine ensuite les reservations. Si une réservation correspond elle est acceptée et transformée en emprunt.

## Modification des jeux
Les fonctions pour créer/supprimer/modifier du stock de jeu on été reunies dans un seul et même menu. Ce menu fonctionne exactement comme celui principal. Le tableau des jeux est retourné par ce menu pour pas avoir a le mettre en double pointeur car on modifie sa taille avec les fonctions contenues dans le menu.