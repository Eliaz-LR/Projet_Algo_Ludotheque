//Ce fichier a pour but d'alleger le fichier principal ludoproj.c en prenant en charge les fonction de menu de choix et d'affichage

#include "ludoproj.h"

//Interface graphique du menu
void afficheMenu(void){

    //permet de "netoyer" le terminal
    printf("\033c");
    
    printf("\t\t\tMenu\n");
    printf("\t\t1: Menu adhérents\n");
    printf("\t\t2: Menu modification des Jeux\n");
    printf("\t\t3: Afficher jeux en stock\n");
    printf("\t\t4: Afficher emprunts en cours\n");
    printf("\t\t5: Afficher les réservations pour un jeu\n");
    printf("\t\t6: Sauvegarde des fichiers\n");
    printf("\t\t7:quitter\n");
}

/*Interface graphique du sous menu jeux */
void afficheMenuJeux(void){
    //permet de "netoyer" le terminal
    printf("\033c");
    
    printf("\t\t\tMenu Jeux\n");
    printf("\t\t1: Ajouter un jeu\n");
    printf("\t\t2: Supprimer un jeu\n");
    printf("\t\t3: Retour\n");
}

void afficheMenuAd(Adherents *tAdherent,int position){

    //permet de "netoyer" le terminal
    printf("\033c");
    
    printf("\t\t\tMenu de %s %s\n",tAdherent[position].nom,tAdherent[position].prenom);
    printf("\t\t1: Emprunt en cours\n");
    printf("\t\t2: Temps restant pour l'abonnement\n");
    printf("\t\t3: Faire une réservation\n");
    printf("\t\t4: Annulation d'une réservation\n");
    printf("\t\t5: Retour d'un jeu\n");
    printf("\t\t6: Retour\n");
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

int choixMenuAd(Adherents *tAdherent,int *sizeA,char nom[],int *position){
    int choix;
    char option;

    *position=chercherNom(tAdherent,nom,*sizeA);

    if(*position==-1)
        printf("Cette adhérents n'existe pas\n");
    
    while(*position==-1){
        printf("Voulez vous crée un adhérent (o/n) : ");
        scanf("%c%*c",&option);
        if(option=='n' || option=='N'){
            while(*position==-1){
                printf("Rentrer votre pseudo utilisateur :");
                scanf("%s%*c",nom);
                *position=chercherNom(tAdherent,nom,*sizeA);
            }
            break;
        }
        else if(option=='o' || option=='O'){
            *sizeA=ajoutAd(tAdherent,*sizeA);
            printf("Création\n");
            strcpy(nom,tAdherent[*sizeA-1].nom);
            *position=chercherNom(tAdherent,nom,*sizeA);
            break;
        }
        else
            printf("Cette option n'existe pas !\n");
    }

    if(*position!=-1){
        afficheMenuAd(tAdherent,*position);

        printf("\nQuelle est votre choix : ");
        scanf("%d%*c",&choix);

        /*Condition qui indique que le choix de l'utilisateur doit être compris entre 1 et 7*/
        while (choix<1 || choix>6){
            printf("\nChoix incorect %d n'est pas compris entre 1 et 6\n",choix);
            printf("Retapez sur la touche entrée pour revenir au menu");
            getchar();
            afficheMenuAd(tAdherent,*position);
            printf("\nQuelle est votre choix : ");
            scanf("%d%*c",&choix);
        }
    }
    return choix; 
}