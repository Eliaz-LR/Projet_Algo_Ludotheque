#include "ludoproj.h"
//Bout de code répété dans les fonctions load
void prepFiles(FILE *flot){
    if (flot == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(1);
    }
    fscanf(flot,"%*[^\n]\n"); /*Permet de scan toute la premiere ligne et de la jeter : *=jeter, et scan de tout sauf \n suivi d'un \n trouvé*/
}

Jeux* loadJeux(int* sizeJ){
    FILE *flot;
    flot = fopen("fichiers texte/jeux.txt","r");
    prepFiles(flot);
    *sizeJ=1;
    Jeux* tJeux = malloc(sizeof(Jeux));
    if(tJeux==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    fscanf(flot,"%d %s %s %d", &tJeux[0].id, tJeux[0].nom, tJeux[0].type, &tJeux[0].nbExemplaires);
    while (!feof(flot))
    {
        *sizeJ=*sizeJ+1;
        tJeux = realloc(tJeux,*sizeJ*sizeof(Jeux));
        fscanf(flot,"%d %s %s %d", &tJeux[*sizeJ-1].id, tJeux[*sizeJ-1].nom, tJeux[*sizeJ-1].type, &tJeux[*sizeJ-1].nbExemplaires);
    }
    fclose(flot);
    return tJeux;
}

Adherents* loadAdherents(int* sizeA){
    FILE *flot;
    flot = fopen("fichiers texte/adherents.txt","r");
    prepFiles(flot);
    *sizeA=1;
    Adherents* tAdherents = malloc(sizeof(Adherents));
    if(tAdherents==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    fscanf(flot,"%d %s %s %s %d/%d/%d", &tAdherents[0].id, tAdherents[0].civil, tAdherents[0].nom, tAdherents[0].prenom, &tAdherents[0].inscrip.jour, &tAdherents[0].inscrip.mois, &tAdherents[0].inscrip.an);
    while (!feof(flot))
    {
        *sizeA=*sizeA+1;
        tAdherents = realloc(tAdherents,*sizeA*sizeof(Adherents));
        fscanf(flot,"%d %s %s %s %d/%d/%d", &tAdherents[*sizeA-1].id, tAdherents[*sizeA-1].civil, tAdherents[*sizeA-1].nom, tAdherents[*sizeA-1].prenom, &tAdherents[*sizeA-1].inscrip.jour, &tAdherents[*sizeA-1].inscrip.mois, &tAdherents[*sizeA-1].inscrip.an);
    }
    fclose(flot);
    return tAdherents;
}

Emprunts* loadEmprunts(int* sizeE){
    FILE *flot;
    flot = fopen("fichiers texte/emprunts.txt","r");
    prepFiles(flot);
    *sizeE=1;
    Emprunts* tEmprunts = malloc(sizeof(Emprunts));
    if(tEmprunts==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    fscanf(flot,"%d %d %d %d/%d/%d", &tEmprunts[0].id, &tEmprunts[0].idAd, &tEmprunts[0].idJeu, &tEmprunts[0].emprunt.jour, &tEmprunts[0].emprunt.mois, &tEmprunts[0].emprunt.an);
    while (!feof(flot))
    {
        *sizeE=*sizeE+1;
        tEmprunts = realloc(tEmprunts,*sizeE*sizeof(Emprunts));
        fscanf(flot,"%d %d %d %d/%d/%d", &tEmprunts[*sizeE-1].id, &tEmprunts[*sizeE-1].idAd, &tEmprunts[*sizeE-1].idJeu, &tEmprunts[*sizeE-1].emprunt.jour, &tEmprunts[*sizeE-1].emprunt.mois, &tEmprunts[*sizeE-1].emprunt.an);
    }
    fclose(flot);
    return tEmprunts;
}

Reserv* loadReserv(int* sizeR){
    FILE *flot;
    flot = fopen("fichiers texte/reservations.txt","r");
    prepFiles(flot);
    *sizeR=1;
    Reserv* tReservations = malloc(sizeof(Reserv));
    if(tReservations==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    fscanf(flot,"%d %d %d %d/%d/%d", &tReservations[0].id, &tReservations[0].idAd, &tReservations[0].idJeu, &tReservations[0].res.jour, &tReservations[0].res.mois, &tReservations[0].res.an);
    while (!feof(flot))
    {
        *sizeR=*sizeR+1;
        tReservations = realloc(tReservations,*sizeR*sizeof(Reserv));
        fscanf(flot,"%d %d %d %d/%d/%d", &tReservations[*sizeR-1].id, &tReservations[*sizeR-1].idAd, &tReservations[*sizeR-1].idJeu, &tReservations[*sizeR-1].res.jour, &tReservations[*sizeR-1].res.mois, &tReservations[*sizeR-1].res.an);
    }
    fclose(flot);
    return tReservations;
}

void saveFiles(Jeux* tJeux, Adherents* tAdherents, Emprunts* tEmprunts, Reserv* tReserv, int sizeJ, int sizeA, int sizeE, int sizeR){
    //Cette fonction est plutot longue, je vous invite donc à, si votre IDE le permet la minimiser une fois lue. 
    FILE *flot;
    int i;
    //save jeux
    flot = fopen("fichiers texte/jeux.txt","w");
    fprintf(flot,"idJeux, nom du jeux, type du jeux (construction, plateau, tuile, carte, logique), nombre d’exemplaires\n");
    for (i = 0; i < sizeJ-1; i++)
    {
        fprintf(flot, "%d %s %s %d\n", tJeux[i].id, tJeux[i].nom, tJeux[i].type, tJeux[i].nbExemplaires);
    }
    fclose(flot);
    //save adherents
    flot = fopen("fichiers texte/adherents.txt","w");
    fprintf(flot,"idAdherent, civilité (Mr, Mme), nom, prénom, date d’inscription\n");
    for (i = 0; i < sizeA-1; i++)
    {
        fprintf(flot,"%d %s %s %s %d/%d/%d\n", tAdherents[i].id, tAdherents[i].civil, tAdherents[i].nom, tAdherents[i].prenom, tAdherents[i].inscrip.jour, tAdherents[i].inscrip.mois, tAdherents[i].inscrip.an);
    }
    fclose(flot);
    //save emprunts
    flot = fopen("fichiers texte/emprunts.txt","w");
    fprintf(flot,"idEmprunt, idAdherent, idJeux, date d’emprunt\n");
    for (i = 0; i < sizeE-1; i++)
    {
        fprintf(flot,"%d %d %d %d/%d/%d\n", tEmprunts[i].id, tEmprunts[i].idAd, tEmprunts[i].idJeu, tEmprunts[i].emprunt.jour, tEmprunts[i].emprunt.mois, tEmprunts[i].emprunt.an);
    }
    fclose(flot);
    //save reservations
    flot = fopen("fichiers texte/reservations.txt","w");
    fprintf(flot,"idResa, idAdherent, idJeux, date de réservation\n");
    for (i = 0; i < sizeR-1; i++)
    {
        fprintf(flot,"%d %d %d %d/%d/%d\n", tReserv[i].id, tReserv[i].idAd, tReserv[i].idJeu, tReserv[i].res.jour, tReserv[i].res.mois, tReserv[i].res.an);
    }
    fclose(flot);
}

//ces deux fonctions sont similaires mais se doivent d'être séparées car elles utilisent des tableaux à types differents.
int searchJeux(int searchedID, Jeux* tJeux, int sizeJ){
    int i;
    for (i = 0; i < sizeJ-1; i++)
    {
        if (searchedID==tJeux[i].id)
        {
            return i;
        }
        
    }
    printf("erreur dans searchJeux: id cheché non trouvé, verifiez la base de donnée\n");
    return -1;
}
int searchAdherent(int searchedID, Adherents* tAdherents, int sizeA){
    int i;
    for (i = 0; i < sizeA-1; i++)
    {
        if (searchedID==tAdherents[i].id)
        {
            return i;
        }
    }
    printf("erreur dans searchAdherent: id cheché non trouvé, verifiez la base de donnée\n");
    return -1;    
}

void AffichageEmprunts(Jeux* tJeux, Adherents* tAdherents, Emprunts* tEmprunts, int sizeJ, int sizeA, int sizeE){
    int i, jRank, aRank;

    for (i = 0; i < sizeE-1; i++)
    {
        jRank=searchJeux(tEmprunts[i].idJeu, tJeux, sizeJ);
        aRank=searchAdherent(tEmprunts[i].idAd, tAdherents, sizeA);
        printf("%s %s %d/%d/%d\n",tJeux[jRank].nom, tAdherents[aRank].nom, tEmprunts[i].emprunt.jour, tEmprunts[i].emprunt.mois, tEmprunts[i].emprunt.an);
    }
    
}

//Interface graphique du menu
void afficheMenu(void){

    //permet de "netoyer" le terminal
    system("clear");
    
    printf("\t\t\tMenu\n");
    printf("\t\t1: Information sur les jeux\n");
    printf("\t\t2: Affichage des emprunts en cours\n");
    printf("\t\t3: Ajouter un jeu\n");
    printf("\t\t4: Supprimer un jeu\n");
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
    printf("\t\t3: Afficher les jeux emprunter\n");
    printf("\t\t4: Retour\n");
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

/* Sous menu jeux */
void partie_jeux(void){
    int choix;
    choix=choixMenuJeux();
    while(choix!=4){
        switch(choix){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                return;
                break;
        }
        printf("\nTapez sur la touche entrée pour retourner au menu");
        getchar();
        choix=choixMenuJeux();
    }
}

//Fonction globale : execute toutes les fonctions
void global(void){
    int choix;
    int sizeJ, sizeA, sizeE, sizeR;
    int i;
    Jeux *tJeux = loadJeux(&sizeJ);;
    Adherents* tAdherents = loadAdherents(&sizeA);
    Emprunts* tEmprunts = loadEmprunts(&sizeE);
    Reserv* tReservations = loadReserv(&sizeR);
    choix=choixMenu();
    while(choix!=7){   
        switch (choix){
            case 1:
                partie_jeux();
                break;
            case 2:
                //doit etre modifié : creer une fonction special pour qui remplace les ids par les nom
                printf("Affichage des emprunts en cours\n");
                AffichageEmprunts(tJeux, tAdherents, tEmprunts, sizeJ, sizeA, sizeE);
                break;
            case 3:
                printf("Choix 3\n");
                break;
            case 4:
                printf("Choix 4\n");
                break;
            case 5:
                printf("Choix 5\n");
                break;
            case 6:
                printf("Sauvegarde des fichiers\n");
                saveFiles(tJeux, tAdherents, tEmprunts, tReservations, sizeJ, sizeA, sizeE, sizeR);
                break;
        }
        printf("\nTapez sur la touche entrée pour retourner au menu");
        getchar();
        choix=choixMenu();
    }
    system("clear");
    printf("\n\n\t\t\tAu revoir !\n\n");
}