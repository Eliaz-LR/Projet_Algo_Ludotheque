#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Definition du type Date, utile pour la suite*/
typedef struct
{
    int jour, mois, an;
}Date;

/*Definition des enum pour le type de jeux et pour la civilité*/
typedef enum
{
    construction, plateau, tuile, carte, logique
}typeJ;

typedef enum
{
    Mr, Mme
}civil;

/*Definition des types liés aux differents fichiers*/
typedef struct
{
    int id, nbExemplaires;
    char nom[25];
    typeJ typeJ;
}Jeux;

typedef struct
{
    int id;
    char nom[30], prenom[30];
    civil civil;
    Date inscrip;
}Adherents;

typedef struct
{
    int id, idAd, idJeu;
    Date emprunt;
}Emprunts;

typedef struct
{
    int id, idAd, idJeu;
    Date res;
}Reserv;



Jeux* loadJeux(int* sizeJ);
Adherents* loadAdherents(int* sizeA);
Emprunts* loadEmprunts(int* sizeE);
Reserv* loadReserv(int* sizeR);

void affJeux(Jeux* tJeux, int* sizeJ);

void affEmp(Emprunts* tEmprunts, int* sizeE);

void affRes(void);

void addEmpRes(void);

void retourJeux(void);

void anuRes(void);

void saveFiles(void);

/*annonciation des fonctions pour le menu*/
void afficheMenu(void);
int choixMenu(void);

void global(void);