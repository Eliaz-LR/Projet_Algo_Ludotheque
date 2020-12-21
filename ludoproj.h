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
    char nom[25], type[13];
}Jeux;

typedef struct
{
    int id;
    char civil[4], nom[30], prenom[30];
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



void filesLoad(void);

void affJeux(void);

void affEmp(void);

void affRes(void);

void addEmpRes(void);

void retourJeux(void);

void anuRes(void);

void saveFiles(void);