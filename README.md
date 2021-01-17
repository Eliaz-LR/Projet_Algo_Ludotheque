# Explication du code et des différents choix dans le projet

Première question au moment de la création du projet : utiliser un tableau ou une liste chaînée ?
Nous avons fait le choix d'utiliser un tableau, car **nous n'avons pas besoin d'ajouter des données au milieu des tableaux**. Chaque réservation, adhérent, etc. prend un nouvel ID et se place donc à la fin des tableaux/fichiers, car les listes sont triées par id.

# Plan des menus
### Menu principal
- #### Espace Adhérent
    - Emprunts en cours
    - Nouvel emprunt
    - Nouvelle réservation
    - Annuler une réservation
    - Retour emprunt (avec transformation des réservations en emprunts automatiques)
- #### Modification des jeux
    - Ajouter un jeu (dans la base de donnée ou en stock)
    - Supprimer un jeu (base de donnée/stock)
- Afficher les jeux disponibles
- Afficher les emprunts en cours
- Afficher les réservations pour un jeu donné
- Sauvegarde vers les fichiers .txt

# Construction du programme

## Le .h
Nous avons fait le choix de créer des types pour chaque type d'objets des fichiers (adhérents, jeux, emprunts et réservation).
Nous avons aussi fait un type "date" pour les dates dans les différents types.

## menu.c
menu.c regroupe différentes fonctions lié au fonctionnement du menu (plus précisément celles liées à l'affichage et au choix des différents menus). Elles sont toutes référencées dans le .h pour pouvoir être accédées dans le fichier principal. La fonction principale de chaque menu reste néanmoins dans le fichier principale, car elles font appel à d'autres fonctions de ce fichier et ont parfois des particularités qui leur sont propres.

## Les fonctions pour charger les fichiers
J'ai créé une fonction par fichier à charger, la raison majeure derrière ce choix est qu'on ne peut pas réserver de la mémoire via malloc/realloc pour un paramètre importé par adresse (sous forme de pointeur).

## Les fonctions search
Les fonctions searchJeux/Adherent/Emprunt servent toutes les trois à obtenir l'emplacement dans le tableau de données à partir de l'ID de ces données. Ces données sont référées dans les autres tableaux par leur ID. Si l'on veut accéder à d'autres ils nous faut pouvoir accéder a toutes les données d'un élément à partir de son ID.

## La fonction AffichageEmprunts
La fonction AffichageEmprunts utilise 2 fonctions de recherche. La différence de ces 2 fonctions est que l'une prend un tableau de type Jeux en entrée là où l'autre prend un tableau de type Adherents en entrée. Il n'est possible de ne faire rentrer que la partie id (de type int) de ces structs, d'où la présence de ces 2 fonctions séparées.

## L'espace adherent
Pour certaines fonctions, on commence par entrer le nom, nous avons donc choisi de réunir toutes ces fonctions dans un même menu. Ce menu fait une sauvegarde auto de la liste des adhérents. Cela a été fait pour réduire le nombre de paramètres des fonctions, améliorer la lisibilité du programme et éviter de rendre le programme plus ergonomique.

## La fonction de retour emprunt
Cette fonction est contenue dans l'espace adhérent. Elle commence par demander quel est le jeu retourné, puis elle supprime l'emprunt correspondant du tableau d'emprunts puis examine ensuite les réservations. Si une réservation correspond, elle est acceptée et transformée en emprunt.

## Modification des jeux
Les fonctions pour créer/supprimer/modifier du stock de jeu, ont été réunies dans un seul et même menu. Ce menu fonctionne exactement comme le menu principal. Le tableau des jeux est retourné par ce menu pour ne pas avoir à le mettre en double pointeur, car on modifie sa taille avec les fonctions contenues dans le menu.