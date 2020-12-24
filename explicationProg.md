# Explication du code et des differents choix dans le projet
## Le .h
Nous avons fait le choix de créer des types pour chaque types d'objets des fichiers (adherents, jeux, emprunts et reservation).
Nous avons aussi fait un type date pour les dates dans les differents types.

## Les fonctions pour charger les fichiers

J'ai crée une fonction par fichier a charger, la raison majeure derière ce choix est que on ne peut pas reserver de la memoire via malloc/realloc pour un parametre importé par adresse (sous forme de pointeur).