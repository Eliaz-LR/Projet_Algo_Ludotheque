//Ce fichier a pour but d'alleger le fichier principal ludoproj.c en prenant en charge les fonction de menu de choix et d'affichage

#include "ludoproj.h"

//Interface graphique du menu
void afficheMenu(void){

    //permet de "netoyer" le terminal
    printf("\033c");

    printf("\t\t┌──────────────────────────────────────────────────┐\n");
    printf("\t\t│                 ╔═════════════╗                  │\n");
    printf("\t\t│                 ║    Menu     ║                  │\n");
    printf("\t\t│                 ╚═════════════╝                  │\n");
    printf("\t\t│                                                  │\n");
    printf("\t\t│    1: Menu adhérents                             │\n");
    printf("\t\t│    2: Menu modification des Jeux                 │\n");
    printf("\t\t│    3: Afficher jeux en stock                     │\n");
    printf("\t\t│    4: Afficher emprunts en cours                 │\n");
    printf("\t\t│    5: Afficher les réservations pour un jeu      │\n");
    printf("\t\t│    6: Sauvegarde des fichiers                    │\n");
    printf("\t\t│    7:quitter                                     │\n");
    printf("\t\t│                                                  │\n");
    printf("\t\t└──────────────────────────────────────────────────┘\n");
}

/*Interface graphique du sous menu jeux */
void afficheMenuJeux(void){
    //permet de "netoyer" le terminal
    printf("\033c");
    
    printf("\t\t\t╔══════════════╗\n\t\t\t║   Menu Jeux  ║\n\t\t\t╚══════════════╝\n\n");
    printf("\t\t1: Ajouter un jeu\n");
    printf("\t\t2: Supprimer un jeu\n");
    printf("\t\t3: Retour\n");
}

void afficheMenuAd(Adherents *tAdherent,int position){

    //permet de "netoyer" le terminal
    printf("\033c");

    printf("\t\t\t╔═════════════════════╗\n\t\t\t║  Menu de %s %s  ║\n\t\t\t╚═════════════════════╝\n\n",tAdherent[position].nom,tAdherent[position].prenom);
    printf("\t\t1: Emprunt en cours\n");
    printf("\t\t2: Nouvel emprunt\n");
    printf("\t\t3: Faire une réservation\n");
    printf("\t\t4: Annulation d'une réservation\n");
    printf("\t\t5: Retour d'un jeu\n");
    printf("\t\t6: Information sur l'abonnement\n");
    printf("\t\t7: Retour\n");
}

//Formulaire permettant de relever le choix de l'utilisateur
int choixMenu(void){
    int choix;
    afficheMenu();
    printf("\nQuelle est votre choix : ");
    scanf("%d%*c",&choix);

    /*Condition qui indique que le choix de l'utilisateur doit être compris entre 1 et 7*/
    while (choix<1 || choix>7){
        printf("\nChoix incorect %d n'est pas compris entre 1 et 7\n",choix);
        printf("Retapez sur la touche entrée pour revenir au menu");
        getchar();
        afficheMenu();
        printf("\nQuelle est votre choix : ");
        scanf("%d%*c",&choix);
    }

    return choix;
}

/* Choix au niveau du sous menu jeu*/
int choixMenuJeux(void){
    int choix;
    afficheMenuJeux();
    printf("\nQuel est votre choix : ");
    scanf("%d%*c",&choix);

    /*Condition qui indique que le choix de l'utilisateur doit être compris entre 1 et 3*/
    while (choix<1 || choix>3){
        printf("\nChoix incorect %d n'est pas compris entre 1 et 3\n",choix);
        printf("Retapez sur la touche entrée pour revenir au menu");
        getchar();
        afficheMenuJeux();
        printf("\nQuel est votre choix : ");
        scanf("%d%*c",&choix);
    }

    return choix; 
}

int choixMenuAd(Adherents *tAdherent,int *sizeA,char nom[],int position){
    int choix;
    char option;

    if(position!=-1){
        afficheMenuAd(tAdherent,position);

        printf("\nQuelle est votre choix : ");
        scanf("%d%*c",&choix);

        /*Condition qui indique que le choix de l'utilisateur doit être compris entre 1 et 7*/
        while (choix<1 || choix>7){
            printf("\nChoix incorect %d n'est pas compris entre 1 et 7\n",choix);
            printf("Retapez sur la touche entrée pour revenir au menu");
            getchar();
            afficheMenuAd(tAdherent,position);
            printf("\nQuelle est votre choix : ");
            scanf("%d%*c",&choix);
        }
    }
    return choix; 
}