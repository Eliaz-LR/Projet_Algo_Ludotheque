//Ce fichier a pour but d'alleger le fichier principal ludoproj.c en prenant en charge les fonction de menu de choix et d'affichage

#include "ludoproj.h"

//Interface graphique du menu
void afficheMenu(void){

    //permet de "netoyer" le terminal
    system("clear");
    
    printf("\t\t\tMenu\n");
    printf("\t\t1: Information sur les jeux\n");
    printf("\t\t2: Affichage des emprunts en cours\n");
    printf("\t\t3: Ajouter un jeu\n");
    printf("\t\t4: Espace adhérents\n");
    printf("\t\t5: Emprunt, retour ou annulation\n");
    printf("\t\t6: Sauvegarde des fichiers\n");
    printf("\t\t7:quitter\n");
}

/*Interface graphique du sous menu jeux */
void afficheMenuJeux(void){
    //permet de "netoyer" le terminal
    system("clear");
    
    printf("\t\t\tMenu Jeux\n");
    printf("\t\t1: Afficher les jeux disponible\n");
    printf("\t\t2: Chercher si un jeu existe\n");
    printf("\t\t3: Afficher les jeux emprunté\n");
    printf("\t\t4: Retour\n");
}

void afficheMenuAd(Adherents *tAdherent,int position){

    //permet de "netoyer" le terminal
    system("clear");
    
    printf("\t\t\tMenu de %s %s\n",tAdherent[position].nom,tAdherent[position].prenom);
    printf("\t\t1: Emprunt en cours\n");
    printf("\t\t2: Temps restant pour l'abonnement\n");
    printf("\t\t3: Faire un emprunt\n");
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
    printf("\nQuelle est votre choix : ");
    scanf("%d%*c",&choix);

    /*Condition qui indique que le choix de l'utilisateur doit être compris entre 1 et 7*/
    while (choix<1 || choix>4){
        printf("\nChoix incorect %d n'est pas compris entre 1 et 4\n",choix);
        printf("Retapez sur la touche entrée pour revenir au menu");
        getchar();
        afficheMenuJeux();
        printf("\nQuelle est votre choix : ");
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