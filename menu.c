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
    
    printf("\t\t┌──────────────────────────────────────────────────┐\n");
    printf("\t\t│                 ╔════════════════╗               │\n");
    printf("\t\t│                 ║    Menu Jeux   ║               │\n");
    printf("\t\t│                 ╚════════════════╝               │\n");
    printf("\t\t│                                                  │\n");
    printf("\t\t│    1: Ajouter un jeu                             │\n");
    printf("\t\t│    2: Supprimer un jeu                           │\n");
    printf("\t\t│    3: Retour                                     │\n");
    printf("\t\t│                                                  │\n");
    printf("\t\t└──────────────────────────────────────────────────┘\n");
}

void afficheMenuAd(Adherents *tAdherent,int position){
    int nbEspace,i,nbEspaceMax=37,requis;

    nbEspace=strlen(tAdherent[position].nom)+strlen(tAdherent[position].prenom)+1;
    //permet de "netoyer" le terminal
    printf("\033c");


    printf("\t\t┌──────────────────────────────────────────────────┐\n");
    printf("\t\t│               ╔═══════════════════╗              │\n");
    printf("\t\t│               ║   Menu Adhérents  ║              │\n");
    printf("\t\t│               ╚═══════════════════╝              │\n");
    printf("\t\t│                                                  │\n");

    //permet de peut importe la taille du nom et prenom temps qu'il ne dépasse pas 37 de ne pas décaler le menu
    //si il dépasse 37 alors que le nom sera afficher car dans tout les cas la limite de caractère pour un nom est de 32
    if(nbEspace<36)
        printf("\t\t│    Menu de %s %s:",tAdherent[position].nom,tAdherent[position].prenom);
    else{
        nbEspace=strlen(tAdherent[position].nom);
        printf("\t\t│    Menu de %s:",tAdherent[position].nom);
    }
    requis=nbEspaceMax-nbEspace;
    for(i=0;i<requis;i++){
        printf(" ");
    }

    printf("│\n");
    printf("\t\t│                                                  │\n");
    printf("\t\t│    1: Emprunt en cours                           │\n");
    printf("\t\t│    2: Nouvel emprunt                             │\n");
    printf("\t\t│    3: Annulation d'une réservation               │\n");
    printf("\t\t│    4: Retour d'un jeu                            │\n");
    printf("\t\t│    5: Information sur l'abonnement               │\n");
    printf("\t\t│    6: Retour                                     │\n");
    printf("\t\t│                                                  │\n");
    printf("\t\t└──────────────────────────────────────────────────┘\n");
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
            printf("\nChoix incorect %d n'est pas compris entre 1 et 6\n",choix);
            printf("Retapez sur la touche entrée pour revenir au menu");
            getchar();
            afficheMenuAd(tAdherent,position);
            printf("\nQuelle est votre choix : ");
            scanf("%d%*c",&choix);
        }
    }
    return choix; 
}