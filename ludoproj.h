#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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


/*annonciation des fonctions de menu.c*/
void afficheMenu(void);
void afficheMenuJeux(void);
int choixMenu(void);
int choixMenuJeux(void);
int choixMenuAd(Adherents *tAdherent,int *sizeA,char nom[],int position);
void afficheMenuAd(Adherents *tAdherent,int position);


void global(void);


/*Menu jeux en cours*/
Jeux* partie_jeux(Jeux* tJeux, int* sizeJ);


void tri_iteratif(Jeux* tJeux, int sizeJ);
void affichageJeux(Jeux* tJeux, int sizeJ);

int chercherRes(Reserv *tReservations,int nbres,int jeux,int *nbEmprunt);
void jeuxEmprunter(Reserv tRes[],Jeux tJeux[],int nbjeux,int nbres);
void jeuxDisponible(Reserv tRes[],int nbjeux,int nbres);
int chercherIdJeux(Jeux *tJeux,int sizeJ,char code[]);

int ajoutAd(Adherents *tAdherent,int sizeA);
Adherents saisieAd(Adherents *tAdherent,int sizeA);
int chercherPrenom(Adherents *tAdherents,char prenom[],int sizeA);
int chercherNom(Adherents *tAdherents,char nom[],int sizeA);
void sauvergarde(Adherents *tAdherents,int sizeA);
void Menu_ad(int *sizeA,int *sizeE,int *sizeJ,int *sizeR,Adherents *tAdherents,Jeux *tJeux,Emprunts **tEmprunts,Reserv** pointeur_vers_tReserv);
int tempRestantAbo(Adherents *tAdherents,int position,int sizeA);
int concatener(char mot[],char motfinal[]);

void nouvelEmprunt(Emprunts* tEmprunts,Adherents* tAdherents,Jeux* tJeux, int *sizeE, int sizeA, int sizeJ, int idAdherent);
void EmpruntEnCourt(Emprunts *tEmprunts,int sizeE,int idAd);

void auRevoir(void);
int exemplaireRestant(int idJeux,Jeux *tJeux,int sizeE,Emprunts *tEmprunts);

void reserver(Jeux *tJeux,Emprunts *tEmprunts,int sizeJ,int sizeE,int idJeu,Reserv *tReservation,int sizeR,int idAd);