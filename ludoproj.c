#include "ludoproj.h"

Jeux* loadJeux(int* sizeJ){
    /*répété dans les 4 fonction des fichiers : mettre dans une fonction a part pour reduire ?*/
    FILE *flot;
    flot = fopen("fichiers texte/jeux.txt","r");
    if (flot == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(1);
    }
    fscanf(flot,"%*[^\n]\n"); /*Permet de scan toute la premiere ligne et de la jeter : *=jeter, et scan de tout sauf \n suivi d'un \n trouvé*/

    *sizeJ=1;
    Jeux* tJeux = malloc(sizeof(Jeux));
    fscanf(flot,"%d %s %s %d", &tJeux[0].id, &tJeux[0].nom, &tJeux[0].type, &tJeux[0].nbExemplaires);
    while (!feof(flot))
    {
        *sizeJ=*sizeJ+1;
        tJeux = realloc(tJeux,*sizeJ*sizeof(Jeux));
        fscanf(flot,"%d %s %s %d", &tJeux[*sizeJ-1].id, &tJeux[*sizeJ-1].nom, &tJeux[*sizeJ-1].type, &tJeux[*sizeJ-1].nbExemplaires);
    }
    fclose(flot);
    return tJeux;
}

Adherents* loadAdherents(int* sizeA){
    FILE *flot;
    flot = fopen("fichiers texte/adherents.txt","r");
    if (flot == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(1);
    }
    fscanf(flot,"%*[^\n]\n"); /*Permet de scan toute la premiere ligne et de la jeter : *=jeter, et scan de tout sauf \n suivi d'un \n trouvé*/

    *sizeA=1;
    Adherents* tAdherents = malloc(sizeof(Adherents));
    fscanf(flot,"%d %s %s %s %d/%d/%d", &tAdherents[0].id, &tAdherents[0].civil, &tAdherents[0].nom, &tAdherents[0].prenom, &tAdherents[0].inscrip.jour, &tAdherents[0].inscrip.mois, &tAdherents[0].inscrip.an);
    while (!feof(flot))
    {
        *sizeA=*sizeA+1;
        tAdherents = realloc(tAdherents,*sizeA*sizeof(Adherents));
        fscanf(flot,"%d %s %s %s %d/%d/%d", &tAdherents[*sizeA-1].id, &tAdherents[*sizeA-1].civil, &tAdherents[*sizeA-1].nom, &tAdherents[*sizeA-1].prenom, &tAdherents[*sizeA-1].inscrip.jour, &tAdherents[*sizeA-1].inscrip.mois, &tAdherents[*sizeA-1].inscrip.an);
    }
    fclose(flot);
    return tAdherents;
}

Emprunts* loadEmprunts(int* sizeE){
    FILE *flot;
    flot = fopen("fichiers texte/emprunts.txt","r");
    if (flot == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(1);
    }
    fscanf(flot,"%*[^\n]\n"); /*Permet de scan toute la premiere ligne et de la jeter : *=jeter, et scan de tout sauf \n suivi d'un \n trouvé*/

    *sizeE=1;
    Emprunts* tEmprunts = malloc(sizeof(Emprunts));
    fscanf(flot,"%d %d %d %d/%d/%d", &tEmprunts[0].id, &tEmprunts[0].idAd, &tEmprunts[0].idJeu, &tEmprunts[0].emprunt.jour, &tEmprunts[0].emprunt.mois, &tEmprunts[0].emprunt.an);
    while (!feof(flot))
    {
        *sizeE=*sizeE+1;
        tEmprunts = realloc(tEmprunts,*sizeE*sizeof(Emprunts));
        fscanf(flot,"%d %d %d %d/%d/%d", &tEmprunts[0].id, &tEmprunts[0].idAd, &tEmprunts[0].idJeu, &tEmprunts[0].emprunt.jour, &tEmprunts[0].emprunt.mois, &tEmprunts[0].emprunt.an);
    }
    fclose(flot);
    return tEmprunts;
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
    int sizeJ, sizeA, sizeE, sizeR;
    Jeux *tJeux = loadJeux(&sizeJ);;
    Adherents* tAdherents = loadAdherents(&sizeA);
    Emprunts* tEmprunts;
    Reserv* tReservations;
    choix=choixMenu();
    while(choix!=7){   
        switch (choix){
            case 1:
                printf("Choix 1\n");
                printf("%d , %s, %s, %d", tJeux[2].id, tJeux[2].nom, tJeux[2].type, tJeux[2].nbExemplaires);
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