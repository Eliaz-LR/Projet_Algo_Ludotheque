#include "ludoproj.h"

void filesLoad(Jeux* tJeux, Adherents* tAdherents ,Emprunts* tEmprunts, Reserv* tReserv, int* sizeJ, int* sizeA, int* sizeE, int* sizeR){
    FILE *flot;
    flot = fopen("fichiers texte/jeux.txt","r");
    if (flot == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(1);
    }
    fscanf(flot,"%*[^\n]\n"); /*Permet de scan toute la premiere ligne et de la jeter : *=jeter, et scan de tout sauf \n suivi d'un \n trouvé*/
    printf("malloc done\n");
    fscanf(flot,"%d%*[^\n]\n", &tJeux->id);
    printf("id stocké: %d\n", tJeux->id);
    fclose(flot);
}


/*Interface graphique du menu*/
void afficheMenu(void){

    /*permet de "netoyer" le terminal*/
    system("clear");
    
    printf("\t\t\tMenu\n");
    printf("\t\t1: Option 1\n");
    printf("\t\t2: Option 2\n");
    printf("\t\t3: Option 3\n");
    printf("\t\t4: Option 4\n");
    printf("\t\t5: Option 5\n");
    printf("\t\t6: Option 6\n");
    printf("\t\t7:quitter\n");
}

/*Formulaire permettant de relever le choix de l'utilisateur*/
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

/*Fonction globale : execute toutes les fonctions*/
void global(void){
    int choix;
    Jeux *tJeux = malloc(sizeof(Jeux));
    Adherents* tAdherents;
    Emprunts* tEmprunts;
    Reserv* tReservations;
    int sizeJ, sizeA, sizeE, sizeR;
    choix=choixMenu();
    while(choix!=7){   
        switch (choix){
            case 1:
                printf("Choix 1\n");
                filesLoad(tJeux, tAdherents, tEmprunts, tReservations, &sizeJ, &sizeA, &sizeE, &sizeR);
                printf("stdout flushé\n");
                printf("id stocké: %d\n", tJeux->id);
                break;
            case 2:
                printf("Choix 2");
                break;
            case 3:
                printf("Choix 3");
                break;
            case 4:
                printf("Choix 4");
                break;
            case 5:
                printf("Choix 5");
                break;
            case 6:
                printf("Choix 6");
                break;
        }
        printf("\nTapez sur la touche entrée pour retourner au menu");
        getchar();
        choix=choixMenu();
    }
}