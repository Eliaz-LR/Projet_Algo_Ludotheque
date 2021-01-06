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
    *sizeJ=0;
    Jeux* tJeux = malloc(sizeof(Jeux));
    if(tJeux==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    while (!feof(flot))
    {
        *sizeJ=*sizeJ+1;
        tJeux = realloc(tJeux,*sizeJ*sizeof(Jeux));
        fscanf(flot,"%d %s %s %d", &tJeux[*sizeJ-1].id, tJeux[*sizeJ-1].nom, tJeux[*sizeJ-1].type, &tJeux[*sizeJ-1].nbExemplaires);
    }
    //la derniere ligne des fichiers est vide et ne doit pas etre comptée
    *sizeJ=*sizeJ-1;
    fclose(flot);
    return tJeux;
}

Adherents* loadAdherents(int* sizeA){
    FILE *flot;
    flot = fopen("fichiers texte/adherents.txt","r");
    prepFiles(flot);
    *sizeA=0;
    Adherents* tAdherents = malloc(sizeof(Adherents));
    if(tAdherents==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    while (!feof(flot))
    {
        *sizeA=*sizeA+1;
        tAdherents = realloc(tAdherents,*sizeA*sizeof(Adherents));
        fscanf(flot,"%d %s %s %s %d/%d/%d", &tAdherents[*sizeA-1].id, tAdherents[*sizeA-1].civil, tAdherents[*sizeA-1].nom, tAdherents[*sizeA-1].prenom, &tAdherents[*sizeA-1].inscrip.jour, &tAdherents[*sizeA-1].inscrip.mois, &tAdherents[*sizeA-1].inscrip.an);
    }
    //la derniere ligne des fichiers est vide et ne doit pas etre comptée
    *sizeA=*sizeA-1;
    fclose(flot);
    return tAdherents;
}

Emprunts* loadEmprunts(int* sizeE){
    FILE *flot;
    flot = fopen("fichiers texte/emprunts.txt","r");
    prepFiles(flot);
    *sizeE=0;
    Emprunts* tEmprunts = malloc(sizeof(Emprunts));
    if(tEmprunts==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    while (!feof(flot))
    {
        *sizeE=*sizeE+1;
        tEmprunts = realloc(tEmprunts,*sizeE*sizeof(Emprunts));
        fscanf(flot,"%d %d %d %d/%d/%d", &tEmprunts[*sizeE-1].id, &tEmprunts[*sizeE-1].idAd, &tEmprunts[*sizeE-1].idJeu, &tEmprunts[*sizeE-1].emprunt.jour, &tEmprunts[*sizeE-1].emprunt.mois, &tEmprunts[*sizeE-1].emprunt.an);
    }
    //la derniere ligne des fichiers est vide et ne doit pas etre comptée
    *sizeE=*sizeE-1;
    fclose(flot);
    return tEmprunts;
}

Reserv* loadReserv(int* sizeR){
    FILE *flot;
    flot = fopen("fichiers texte/reservations.txt","r");
    prepFiles(flot);
    *sizeR=0;
    Reserv* tReservations = malloc(sizeof(Reserv));
    if(tReservations==NULL){
        printf("Erreur: problème d'allocation dynamique\n");
        fclose(flot);
        return NULL;
    }
    while (!feof(flot))
    {
        *sizeR=*sizeR+1;
        tReservations = realloc(tReservations,*sizeR*sizeof(Reserv));
        fscanf(flot,"%d %d %d %d/%d/%d", &tReservations[*sizeR-1].id, &tReservations[*sizeR-1].idAd, &tReservations[*sizeR-1].idJeu, &tReservations[*sizeR-1].res.jour, &tReservations[*sizeR-1].res.mois, &tReservations[*sizeR-1].res.an);
    }
    //la derniere ligne des fichiers est vide et ne doit pas etre comptée
    *sizeR=*sizeR-1;
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
    for (i = 0; i < sizeJ; i++)
    {
        fprintf(flot, "%d %s %s %d\n", tJeux[i].id, tJeux[i].nom, tJeux[i].type, tJeux[i].nbExemplaires);
    }
    fclose(flot);
    //save adherents
    flot = fopen("fichiers texte/adherents.txt","w");
    fprintf(flot,"idAdherent, civilité (Mr, Mme), nom, prénom, date d’inscription\n");
    for (i = 0; i < sizeA; i++)
    {
        fprintf(flot,"%d %s %s %s %d/%d/%d\n", tAdherents[i].id, tAdherents[i].civil, tAdherents[i].nom, tAdherents[i].prenom, tAdherents[i].inscrip.jour, tAdherents[i].inscrip.mois, tAdherents[i].inscrip.an);
    }
    fclose(flot);
    //save emprunts
    flot = fopen("fichiers texte/emprunts.txt","w");
    fprintf(flot,"idEmprunt, idAdherent, idJeux, date d’emprunt\n");
    for (i = 0; i < sizeE; i++)
    {
        fprintf(flot,"%d %d %d %d/%d/%d\n", tEmprunts[i].id, tEmprunts[i].idAd, tEmprunts[i].idJeu, tEmprunts[i].emprunt.jour, tEmprunts[i].emprunt.mois, tEmprunts[i].emprunt.an);
    }
    fclose(flot);
    //save reservations
    flot = fopen("fichiers texte/reservations.txt","w");
    fprintf(flot,"idResa, idAdherent, idJeux, date de réservation\n");
    for (i = 0; i < sizeR; i++)
    {
        fprintf(flot,"%d %d %d %d/%d/%d\n", tReserv[i].id, tReserv[i].idAd, tReserv[i].idJeu, tReserv[i].res.jour, tReserv[i].res.mois, tReserv[i].res.an);
    }
    fclose(flot);
}

Date dateAujrd(void){
    Date aujrd;
    time_t timestamp=time(NULL);
    struct tm* now=localtime(&timestamp);
    aujrd.an=now->tm_year+1900;
    aujrd.mois=now->tm_mon+1;
    aujrd.jour=now->tm_mday;
    return aujrd;
}

//ces trois fonctions sont similaires mais se doivent d'être séparées car elles utilisent des tableaux à types differents.
int searchJeux(int searchedID, Jeux* tJeux, int sizeJ){
    int i;
    for (i = 0; i < sizeJ; i++)
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
    for (i = 0; i < sizeA; i++)
    {
        if (searchedID==tAdherents[i].id)
        {
            return i;
        }
    }
    printf("erreur dans searchAdherent: id cheché non trouvé, verifiez la base de donnée\n");
    return -1;    
}
int searchEmprunt(int searchedID, Emprunts* tEmprunts, int sizeE){
    int i;
    for (i = 0; i < sizeE; i++)
    {
        if (searchedID==tEmprunts[i].id)
        {
            return i;
        }
    }
    printf("erreur dans searchEmprunt: id cheché non trouvé, verifiez la base de donnée\n");
    return -1;
}

void AffichageEmprunts(Jeux* tJeux, Adherents* tAdherents, Emprunts* tEmprunts, int sizeJ, int sizeA, int sizeE){
    int i, jRank, aRank, moisRetour, anneeRetour;
    Date aujourdhui=dateAujrd();
    if(!(aujourdhui.an==tEmprunts[0].emprunt.an || aujourdhui.an-1==tEmprunts[0].emprunt.an))
            printf("\nIl n'y a actuellement pas d'emprunts en cours.\n");
    else
        {
            printf("\nLes emprunts en cours sont :\n");
            printf("Jeu Nom Prénom Date d'emprunt Date de retour\n");
            for (i = 0; i < sizeE; i++)
                {
                    jRank=searchJeux(tEmprunts[i].idJeu, tJeux, sizeJ);
                    aRank=searchAdherent(tEmprunts[i].idAd, tAdherents, sizeA);
                    moisRetour=tEmprunts[i].emprunt.mois+1;
                    if(moisRetour > 12) /* Quand le nombre de mois dépasse 12 donc 1 an, la difference est mit dans mois puis on rajoute 1 à l'année.*/
                        {
                            anneeRetour=tEmprunts[i].emprunt.an+1;
                            moisRetour=moisRetour-12;
                        }
                    printf("%s %s %s %02d/%02d/%d %02d/%02d/%d\n",tJeux[jRank].nom, tAdherents[aRank].nom, tAdherents[aRank].prenom, tEmprunts[i].emprunt.jour, tEmprunts[i].emprunt.mois, tEmprunts[i].emprunt.an,tEmprunts[i].emprunt.jour, moisRetour, anneeRetour);
                }
        }
}

Emprunts* retourEmprunt(Jeux* tJeux, Adherents* tAdherents, Emprunts* tEmprunts, Reserv** tReserv, int* sizeE, int* sizeJ, int* sizeR){
    int i, j, idE, idJ, rank;
    printf("Entrez l'ID de l'emprunt a retourner\n");
    scanf("%d",&idE);
    rank=searchEmprunt(idE, tEmprunts, *sizeE);
    idJ=tEmprunts[rank].idJeu;
    printf("jeu emprunté num %d\n",idJ);
    printf("sizeE = %d, rank = %d\n", *sizeE, rank);
    //Va de la case a supprimer jusqu'a l'avant dernière dispo...
    for (i = rank; i < *sizeE-1; i++)
    {
        //...pour decaler d'une case les données de tEmprunts(cela permet d'ecraser les données de l'emprunt rendu et d'avoir la derniere case prète a etre supprimée).
        tEmprunts[i]=tEmprunts[i+1];
    }
    if (i==rank)
    {
        tEmprunts[i].id=0;
    }
    else
    {
        tEmprunts[i+1].id=0;
    }
    printf("fin decalage emprunts\n");
    *sizeE=*sizeE-1;
    tEmprunts=realloc(tEmprunts,*sizeE*sizeof(Emprunts));
    printf("realloc temprunts reussie\n");
    rank=searchJeux(idJ, tJeux, *sizeJ);
    tJeux[rank].nbExemplaires=tJeux[rank].nbExemplaires+1;
    printf("jeu remis en stock\n");
    //gestion des reservations (a continuer)
    for (i = 0; i < *sizeR; i++)
    {
        if ((*tReserv)[i].idJeu==idJ)
        {
            printf("Reservation du jeu retourné détetée ! Creation automatique de l'emprunt...\n");
            //on ajoute l'emprunt...
                *sizeE=*sizeE+1;
                tEmprunts=realloc(tEmprunts,*sizeE*sizeof(Emprunts));
                if (*sizeE==1)
                {
                    tEmprunts[*sizeE-1].id=1;//si c'est le premier emprunt, il prend l'id 1
                }
                else
                {
                    tEmprunts[*sizeE-1].id=tEmprunts[*sizeE-2].id+1; //l'id de l'emprunt prend la valeur du dernier du tableau +1
                }
                tEmprunts[*sizeE-1].idAd=(*tReserv)[i].idAd;
                tEmprunts[*sizeE-1].idJeu=(*tReserv)[i].idJeu;
                printf("emprunt ajouté\n");
                //on enleve le jeu du stock
                tJeux[rank].nbExemplaires=tJeux[rank].nbExemplaires-1;
                //on regle la date de l'emprunt sur la date actuelle obtenue avec dos.h
                tEmprunts[*sizeE-1].emprunt=dateAujrd();
            //et on supprime la reservation
            for (j = i; j < *sizeR-1; j++)
            {
                (*tReserv)[j]=(*tReserv)[j+1];
            }
            *sizeR=*sizeR-1;
            *tReserv=realloc(*tReserv,*sizeR*sizeof(Reserv));
            printf("résérvation supprimée\n");
            break;
        }
    }
    printf("fin de la fonction !\n");
    return tEmprunts;
}

void listeReservJeux(Jeux* tJeux, Reserv* tRes, Adherents* tAdherents, int nbjeux, int nbres, int sizeA){
    int i, j, numJ, rankA;
    char nameJeux;
    printf("Pour quel jeu voulez-vous voir ses réservations ?\n");
    for(i=0; i<nbjeux; i++)
        {
            printf("%d) %s\n",tJeux[i].id,tJeux[i].nom);
        }
    printf("Entrer le numéro du jeu voulu : ");
    ScanChiffreJeux:
    scanf("%d%*c",&numJ);
    if(numJ < 1 || numJ > nbjeux )
        {  
            printf("Erreur: le chiffre n'est pas valable\n");
            printf("Veuillez entrer un numéro de jeu valide\n");
            goto ScanChiffreJeux;
        }
    for (j = 0; j < nbres; j++)
        {
            if (numJ==tRes[j].idJeu){
                goto ImpressionReserv; //Car Au Moins Un Truc A Imprimer
            }
        }
    printf("Pas de reservation pour ce jeu !\n");
    return;
    ImpressionReserv:
    printf("Les réservations sont :\n");
    printf("Nom\tDate de réservation\n");
    for (j = 0; j < nbres; j++)
        {
            if (numJ==tRes[j].idJeu){
                rankA=searchAdherent(tRes[j].idAd, tAdherents, sizeA);
                printf("%s\t%d/%d/%d", tAdherents[rankA].nom, tRes[j].res.jour, tRes[j].res.mois, tRes[j].res.an); /*afficher nom a la place de id */
            }
        }
}

void AffichageJeuxTrie(Jeux* tJeux, Emprunts tEmprunts[], int nbjeux, int nbEmprunts){
    int i, j, k, rankJ, sizeTri=0;
    char type[13], temp[25];
    Jeux *jeuxTries,*jeuxDispo;
    jeuxTries = malloc(nbjeux*sizeof(Jeux));
    jeuxDispo = malloc(nbjeux*sizeof(Jeux));
    //copie du contenu de tjeux vers jeuxdispo ou le nombre de jeux dispo va etre modifié
    for (i = 0; i < nbjeux; i++)
    {
        jeuxDispo[i]=tJeux[i];
    }
    //vide la partie nom de jeuxTries, utilisé plus tard pour detecter si un jeux y est stocké
    for (i = 0; i < nbjeux; i++)
    {
        strcpy(jeuxTries[i].nom,"");
    }
    for (i = 0; i < nbEmprunts; i++)
    {
        rankJ=searchJeux(tEmprunts[i].idJeu, tJeux, nbjeux);
        jeuxDispo[rankJ].nbExemplaires=jeuxDispo[rankJ].nbExemplaires-1;
    }
    for (i = 0; i <= 4; i++)
    {
        switch (i)
        {
        case 0:
            strcpy(type,"construction");
            break;
        case 1:
            strcpy(type,"plateau");
            break;
        case 2:
            strcpy(type,"tuile");
            break;
        case 3:
            strcpy(type,"carte");
            break;
        case 4:
            strcpy(type,"logique");
            break;
        }
        for (j = 0; j < nbjeux; j++)
        {
            if (strcmp(jeuxDispo[j].type,type)==0 && jeuxDispo[j].nbExemplaires>0)
            {
                for (k = 0; k <nbjeux ; k++)
                {
                    if (strcmp(jeuxTries[k].nom,"")==0)
                    {
                        jeuxTries[k]=tJeux[j];
                        sizeTri++;
                        break;
                    }
                    
                }
            }
        }
    }
    printf("Type\tNom\t\tstock\tid\n");
    for (i = 0; i <sizeTri; i++)
    {
        printf("%s\t%s\t\t%d\t%d\n",jeuxTries[i].type,jeuxTries[i].nom,jeuxTries[i].nbExemplaires,jeuxTries[i].id);
    }    
}


Jeux* ajouterJeux(Jeux* tJeux, int* sizeJ){
    int choix, i, quantite;
    printf("Voulez vous:\n");
    printf("\t1)\tAjouter un nouveau jeu\n");
    printf("\t2)\tRajouter du stock pour un jeu deja dans la base de donnée\n");
    scanf("%d%*c",&choix);
    if (choix==1)
    {
        *sizeJ=*sizeJ+1;
        tJeux=realloc(tJeux,*sizeJ*sizeof(Jeux));
        if (*sizeJ==1)
        {
            tJeux[*sizeJ-1].id=1;//si c'est le premier jeux, il prend l'id 1
        }
        else
        {
            tJeux[*sizeJ-1].id=tJeux[*sizeJ-2].id+1; //l'id du jeu prend la valeur du dernier du tableau +1
        }
        printf("Entrez le nom du jeu à ajouter (sans espaces)\n");
        scanf("%s%*c",&(tJeux[*sizeJ-1].nom));
        SelecType: //label selecType pour si choix du type ne correspond pas aux chiffres definis
        printf("Entrez le type du jeu à ajouter (parmis: 1.construction, 2.plateau, 3.tuile, 4.carte, 5.logique)\n");
        scanf("%d%*c",&choix);
        switch (choix)
        {
        case 1:
            strcpy(tJeux[*sizeJ-1].type,"construction");
            break;
        case 2:
            strcpy(tJeux[*sizeJ-1].type,"plateau");
            break;
        case 3:
            strcpy(tJeux[*sizeJ-1].type,"tuile");
            break;
        case 4:
            strcpy(tJeux[*sizeJ-1].type,"carte");
            break;
        case 5:
            strcpy(tJeux[*sizeJ-1].type,"logique");
            break;
        default:
            printf("ERREUR: numero de type non disponible\n");
            goto SelecType;
        }
        printf("Entrez le nombre d'exemplaires du jeu à ajouter\n");
        scanf("%d%*c",&(tJeux[*sizeJ-1].nbExemplaires));
        printf("le jeu rentré est %s, de type %s avec %d exemplaires",tJeux[*sizeJ-1].nom,tJeux[*sizeJ-1].type,tJeux[*sizeJ-1].nbExemplaires);
    }
    else
    if (choix==2)
    {
        printf("LISTE DES JEUX:\n");
        for (i = 0; i < *sizeJ; i++)
        {
            printf("%d) %s\n",i+1,tJeux[i].nom);
        }
        printf("De quel jeu devont nous modifier la quantité de stock ? (numéro)\n");
        scanf("%d",&i);
        i--;
        printf("Combiens de jeux voulez vous rajouter ?\n");
        scanf("%d",&quantite);
        tJeux[i].nbExemplaires=tJeux[i].nbExemplaires+quantite;
    }
    else
    {
        printf("ERREUR: Veuillez entrer un chiffre entre 1 et 2\n");
    }
    return tJeux;
}
Jeux* supprimerJeux(Jeux* tJeux, int* sizeJ){
    int choix, i, quantite, rank;
    printf("Voulez vous:\n");
    printf("\t1)\tSupprimer totalement un type de jeu\n");
    printf("\t2)\tDiminuer le stock pour un jeu deja dans la base de donnée\n");
    scanf("%d%*c",&choix);
    if (choix==1)
    {
        printf("LISTE DES JEUX:\n");
        for (i = 0; i < *sizeJ; i++)
        {
            printf("%d) %s\n",i+1,tJeux[i].nom);
        }
        printf("Quel jeu devont nous supprimer ? (numéro)\n");
        scanf("%d",&rank);
        for (i = rank-1; i < *sizeJ-1; i++)
        {
            tJeux[i]=tJeux[i+1];
        }
        *sizeJ=*sizeJ-1;
        tJeux=realloc(tJeux,*sizeJ*sizeof(Jeux));
    }
    else
    if (choix==2)
    {
        printf("LISTE DES JEUX:\n");
        for (i = 0; i < *sizeJ; i++)
        {
            printf("%d) %s\n",i+1,tJeux[i].nom);
        }
        printf("De quel jeu devont nous modifier la quantité de stock ? (numéro)\n");
        scanf("%d",&i);
        i--;
        do
        {
            printf("Combiens de jeux voulez vous supprimer ?\n");
            scanf("%d",&quantite);
            if (tJeux[i].nbExemplaires-quantite<0)
            {
                printf("ERREUR : la quantité de ce jeu ne peut pas etre nulle ou négative\n");
            }
        }while (tJeux[i].nbExemplaires-quantite<0);
        tJeux[i].nbExemplaires=tJeux[i].nbExemplaires-quantite;
    }
    else
    {
        printf("ERREUR: Veuillez entrer un chiffre entre 1 et 2\n");
    }
    return tJeux;
}
/* Sous menu jeux */
Jeux* partie_jeux(Jeux* tJeux, int* sizeJ){
    int choix,id,i;
    char code[50];

    choix=choixMenuJeux();
    while(choix!=4){
        switch(choix){
            case 1:
                tJeux=ajouterJeux(tJeux, sizeJ);
                break;
            case 2:
                tJeux=supprimerJeux(tJeux, sizeJ);
                break;
            case 3:
                return tJeux;
                break;
        }
        printf("\nTapez sur la touche entrée pour retourner au menu");
        getchar();
        choix=choixMenuJeux();
    }
}

//Fonction globale : menu principal qui execute toutes les fonctions
void global(void){
    int choix;
    int sizeJ, sizeA, sizeE, sizeR;
    int i;
    Jeux *tJeux = loadJeux(&sizeJ);
    Adherents* tAdherents = loadAdherents(&sizeA);
    Emprunts* tEmprunts = loadEmprunts(&sizeE);
    Reserv* tReservations = loadReserv(&sizeR);
    choix=choixMenu();
    while(choix!=7){   
        switch (choix){
            case 1:
                printf("Menu adhérents\n");
                Menu_ad(&sizeA);
                break;
            case 2:
                //doit etre modifié : creer une fonction special pour qui remplace les ids par les nom
                printf("Menu modification des Jeux\n");
                tJeux=partie_jeux(tJeux, &sizeJ);
                break;
            case 3:
                printf("Afficher jeux disponibles\n");
                AffichageJeuxTrie(tJeux, tEmprunts, sizeJ, sizeE);
                break;
            case 4:
                printf("Afficher emprunts en cours\n");
                AffichageEmprunts(tJeux, tAdherents, tEmprunts, sizeJ, sizeA, sizeE);
                break;
            case 5:
                printf("Afficher les réservations pour un jeu\n");
                listeReservJeux(tJeux, tReservations, tAdherents, sizeJ, sizeR, sizeA);
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
    printf("\033c");
    printf("\n\n\t\t\tAu revoir !\n\n");
    free(tJeux);
    free(tAdherents);
    free(tEmprunts);
    free(tReservations);
}



int chercherIdJeux(Jeux *tJeux,int sizeJ,char code[]){
    int i;

    for(i=0;i<sizeJ;i++){
        if(strcmp(tJeux[i].nom,code)==0)
            return tJeux[i].id;
    }
    return -1;
}

int chercherRes(Reserv *tReservations,int nbres,int jeux,int *nbEmprunt){
    int i,t=0;
    int trouve=0;

    for(i=0;i<nbres;i++){
        if(tReservations[i].idJeu==jeux){
            trouve=1;
            t++;
        }
    }
    *nbEmprunt=t;
    return trouve;
}

void jeuxEmprunter(Reserv tRes[],Jeux tJeux[],int nbjeux,int nbres){
    int i;
    int emprunter,nbEmprunt;
    printf("Id\tNom\t\tType\tNombre d'exemplaire emprunter\n");

    for(i=0;i<nbjeux-1;i++){
        emprunter=chercherRes(tRes,nbres,tJeux[i].id,&nbEmprunt);
        if(emprunter==1){
            if(tJeux[i].nbExemplaires<0){
                printf("Erreur: Le jeu %s a était emprunter plus de fois qu'il était diponible\n\n",tJeux[i].nom);
                return;
            }
            else if(tJeux[i].nbExemplaires!=0)
                printf("%d\t%s\t%s\t\t%d\n",tJeux[i].id,tJeux[i].nom,tJeux[i].type,nbEmprunt);
        }
    }
    printf("\n\n");
}

void jeuxDisponible(Reserv tRes[],int nbjeux,int nbres){
    int i;
    int emprunter,nbEmprunt;
    Jeux *tJeux = loadJeux(&nbjeux);

    printf("Id\tNom\t\tType\t\tNombre d'emplaires restant\n");

    for(i=0;i<nbjeux-1;i++){
        emprunter=chercherRes(tRes,nbres,tJeux[i].id,&nbEmprunt);
        if(emprunter==1)
            tJeux[i].nbExemplaires=tJeux[i].nbExemplaires-nbEmprunt;
        if(emprunter!=1 || tJeux[i].nbExemplaires>0)
            printf("%d\t%s\t%s\t\t%d\n",tJeux[i].id,tJeux[i].nom,tJeux[i].type,tJeux[i].nbExemplaires);
    }
    printf("\n\n");
}
void sauvergarde(Adherents *tAdherents,int sizeA){
    int i;
    FILE *flot;
    flot=fopen("fichiers texte/adherents.txt","w");

    if(flot==NULL){
        printf("Erreur: problème d'ouverture de fichier\n");
    }

    fprintf(flot,"idAdherent, civilité (Mr, Mme), nom, prénom, date d’inscription\n");
    for (i = 0; i < sizeA; i++)
    {
        fprintf(flot,"%d %s %s %s %d/%d/%d\n", tAdherents[i].id, tAdherents[i].civil, tAdherents[i].nom, tAdherents[i].prenom, tAdherents[i].inscrip.jour, tAdherents[i].inscrip.mois, tAdherents[i].inscrip.an);
    }
    fclose(flot);
}

int chercherNom(Adherents *tAdherents,char nom[],int sizeA){
    int i;

    for(i=0;i<sizeA;i++){
        if(strcmp(tAdherents[i].nom,nom)==0){
            return i;
        }
    }
    return -1;
}

Adherents saisieAd(Adherents *tAdherent,int sizeA){
    Adherents nvAd;
    char genre;
    int lgt,erreur;

    printf("Saisie d'un nom : ");
    scanf("%s%*c",nvAd.nom);
    
    while(1){
        lgt=0;
        erreur=0;
        while(nvAd.nom[lgt]!='\0'){
            lgt++;
            if(nvAd.nom[lgt]=='0' || nvAd.nom[lgt]=='1' || nvAd.nom[lgt]=='2' || nvAd.nom[lgt]=='3' || nvAd.nom[lgt]=='4' || nvAd.nom[lgt]=='5' || nvAd.nom[lgt]=='6' || nvAd.nom[lgt]=='7' || nvAd.nom[lgt]=='8' || nvAd.nom[lgt]=='9')
                erreur=1;
        }
        if(erreur==1){
            printf("Erreur: le nom contient des nombres\n");
            printf("Saisie d'un nom : ");
            scanf("%s%*c",nvAd.nom);
        }
        else if(lgt<=1 && lgt!=-1){
            printf("Erreur: le nom est trop petit\n");
            printf("Saisie d'un nom : ");
            scanf("%s%*c",nvAd.nom);
        }
        else
            break;
    }

    printf("Saisie d'un prénom : ");
    scanf("%s%*c",nvAd.prenom);
    
    while(1){
        lgt=0;
        erreur=0;
        while(nvAd.prenom[lgt]!='\0'){
            lgt++;
            if(nvAd.prenom[lgt]=='0' || nvAd.prenom[lgt]=='1' || nvAd.prenom[lgt]=='2' || nvAd.prenom[lgt]=='3' || nvAd.prenom[lgt]=='4' || nvAd.prenom[lgt]=='5' || nvAd.prenom[lgt]=='6' || nvAd.prenom[lgt]=='7' || nvAd.prenom[lgt]=='8' || nvAd.prenom[lgt]=='9')
                erreur=1;
        }
        if(erreur==1){
            printf("Erreur: le prenom contient des nombres\n");
            printf("Saisie d'un prenom : ");
            scanf("%s%*c",nvAd.prenom);
        }
        else if(lgt<=1 && lgt!=-1){
            printf("Erreur: le prenom est trop petit\n");
            printf("Saisie d'un prenom : ");
            scanf("%s%*c",nvAd.prenom);
        }
        else
            break;
    }


    printf("Etes-vous un homme ou une femme (f/h) : ");
    scanf("%c%*c",&genre);

    while(1){
        if(genre=='f' || genre=='F'){
            strcpy(nvAd.civil,"Mme");
            break;
        }
        else if(genre=='h' || genre=='H'){
            strcpy(nvAd.civil,"Mr");
            break;
        }
        else{
            printf("Ce genre n'existe pas\n");
            printf("Etes-vous un homme ou une femme (f/h) : ");
            scanf("%c%*c",&genre);
        }
    }

    nvAd.inscrip=dateAujrd();

    nvAd.id=sizeA+1;

    return nvAd;
}

int ajoutAd(Adherents *tAdherent,int sizeA){
    Adherents nvAd;

    nvAd=saisieAd(tAdherent,sizeA);
    tAdherent=realloc(tAdherent,sizeA+1*sizeof(Adherents));
    tAdherent[sizeA]=nvAd;
    sizeA++;

    return sizeA;
}

//Sous menu adherent
void Menu_ad(int *sizeA){
    int choix,abo;
    int i,position;
    char nom[32], prenom[32];
    char option;

    Adherents* tAdherents = loadAdherents(sizeA);

    printf("Rentrer le nom :\n");
    scanf("%s%*c",nom);
    printf("Rentrer le prénom :\n");
    scanf("%s%*c",prenom);

    position=chercherNom(tAdherents,nom,*sizeA);

    if(position==-1)
        printf("Cette adhérents n'existe pas\n");
    
    while(position==-1){
        printf("Voulez vous crée un adhérent (o/n) : ");
        scanf("%c%*c",&option);
        if(option=='n' || option=='N'){
            while(position==-1){
                printf("Rentrer votre pseudo utilisateur :");
                scanf("%s%*c",nom);
                position=chercherNom(tAdherents,nom,*sizeA);
            }
            break;
        }
        else if(option=='o' || option=='O'){
            *sizeA=ajoutAd(tAdherents,*sizeA);
            printf("Création\n");
            strcpy(nom,tAdherents[*sizeA-1].nom);
            position=chercherNom(tAdherents,nom,*sizeA);
            break;
        }
        else
            printf("Cette option n'existe pas !\n");
    }

    tempRestantAbo(tAdherents,position);

    choix=choixMenuAd(tAdherents,sizeA,nom,position);
    while(choix!=6){   
        switch (choix){
            case 1:
                printf("%d",*sizeA);
                break;
            case 2:
                
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
                return;
                break;
        }
        printf("\nTapez sur la touche entrée pour retourner au menu");
        getchar();
        choix=choixMenuAd(tAdherents,sizeA,nom,position);
    }
    sauvergarde(tAdherents,*sizeA);
}

int tempRestantAbo(Adherents *tAdherents,int position){
    int nbj,nbm,nba,restant=365;
    char option;
    Date dateActu;

    dateActu=dateAujrd();

    nbj=dateActu.jour-tAdherents[position].inscrip.jour;
    nbm=dateActu.mois-tAdherents[position].inscrip.mois;
    nba=dateActu.an-tAdherents[position].inscrip.an;

    if(nbj>=0)
        restant=restant-nbj;
    if(nbm>=0)
        restant=restant-nbm*30;
    if(nba>=0)
        restant=restant-nba*365;
    
    if(restant>0)
        printf("\nTemps restant : %d jours\n",restant);
    else{
        printf("\nL'abonnement est dépasser\n"); 
        printf("Voulez vous renouvellez votre abonnement : ");
        scanf("%c%*c",&option);
        if(option == 'o' || option == 'O'){
            tAdherents[position].inscrip=dateAujrd();
            printf("\nRenouvellement effectuer ...\n");
        }
        else if(option == 'n' || option == 'N'){
            printf("Il vous est donc pas possible de reserver\n");
        }
        else
        {
            printf("Le choix n'est pas correct veuillez ressayer\n");
        }      
    }
    return restant;  
}
