#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Definition du type Date, utile pour la suite*/
typedef struct
{
    int jour, mois, an;
}Date;

/*Definition des types liés aux differents fichiers*/
typedef struct
{
    int id, nbExemplaires;
    char nom[25],type[13];
}Jeux;

typedef struct
{
    int id;
    char nom[30], prenom[30], civil[4];
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


void prepFiles(FILE *flot);
Jeux* loadJeux(int* sizeJ);
Adherents* loadAdherents(int* sizeA);
Emprunts* loadEmprunts(int* sizeE);
Reserv* loadReserv(int* sizeR);

void saveFiles(Jeux* tJeux, Adherents* tAdherents, Emprunts* tEmprunts, Reserv* tReserv, int sizeJ, int sizeA, int sizeE, int sizeR);


/*annonciation des fonctions pour le menu*/
void afficheMenu(void);
int choixMenu(void);

void global(void);


/*Menu jeux en cours*/
void partie_jeux(void);
int choixMenuJeux(void);
void afficheMenuJeux(void);


void tri_iteratif(Jeux* tJeux, int sizeJ);
void affichageJeux(Jeux* tJeux, int sizeJ);