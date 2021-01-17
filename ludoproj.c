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

Emprunts* retourEmprunt(Jeux* tJeux, Adherents* tAdherents, Emprunts* tEmprunts, Reserv** tReserv, int* sizeE, int* sizeJ, int* sizeR, int idAd){
    int i, j, idE, idJ, rank, nbEmp=0;
    printf("retour d'emprunt pour adherent ID:%d",idAd);
    for(i=0;i<*sizeE;i++){
        if(tEmprunts[i].idAd==idAd){
            nbEmp++;
            if(nbEmp==1)
                printf("\nidEmprunt, idJeux, date d'emprunt\n");
            printf("Emprunt num:%d  %d  %02d/%02d/%d\n",tEmprunts[i].id,tEmprunts[i].idJeu,tEmprunts[i].emprunt.jour,tEmprunts[i].emprunt.mois,tEmprunts[i].emprunt.an);
        }
    }
    if (nbEmp>0)
        printf("Veuillez entrer l'ID d'emprunt retourné");
    else
    {
        printf("ERREUR: L'adherent n'a pas d'emprunts");
        return tEmprunts;
    }
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

Reserv* anulationReserv(Reserv* tReserv, int* sizeR, int idAd){
    int i, numR, nbRes=0;
    printf("annulation reservation pour adherent ID:%d\n",idAd);
    for(i=0;i<*sizeR;i++){
        if(tReserv[i].idAd==idAd){
            nbRes++;
            if(nbRes==1)
                printf("idReserv, idJeux, date de reserv\n");
            printf("%d)  %d  %02d/%02d/%d\n",i,tReserv[i].idJeu,tReserv[i].res.jour,tReserv[i].res.mois,tReserv[i].res.an);
        }
    }
    if (nbRes>0)
        printf("Veuillez entrer le num de la reserv a annuler");
    else
    {
        printf("ERREUR: L'adherent n'a pas de reserv");
        return tReserv;
    }
    scanf("%d",&numR);
    //Va de la case a supprimer jusqu'a l'avant dernière dispo...
    for (i = numR; i < *sizeR-1; i++)
    {
        //...pour decaler d'une case les données de tReserv(cela permet d'ecraser les données de l'emprunt rendu et d'avoir la derniere case prète a etre supprimée).
        tReserv[i]=tReserv[i+1];
    }
    printf("fin decalage reserv\n");
    *sizeR=*sizeR-1;
    tReserv=realloc(tReserv,*sizeR*sizeof(Reserv));
    printf("realloc tReserv reussie\n");
    return tReserv;
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
                printf("%s\t%d/%d/%d\n", tAdherents[rankA].nom, tRes[j].res.jour, tRes[j].res.mois, tRes[j].res.an); /*afficher nom a la place de id */
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
        scanf("%s%*c",(tJeux[*sizeJ-1].nom));
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
                printf("\nMenu adhérents\n\n");
                Menu_ad(&sizeA,&sizeE,&sizeJ,&sizeR,tAdherents,tJeux,&tEmprunts,&tReservations);
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
    auRevoir();
    free(tJeux);
    free(tAdherents);
    free(tEmprunts);
    free(tReservations);
}

void auRevoir(void){
    int i,j,lg=0;
    char mot2[20];
    char mot[11]="Au revoir!";
    int nbEspace=0;
    while(nbEspace!=102){
        if(nbEspace==0){
            for(j=10;j!=-1;j--){
                printf("\033c");
                printf("\n\n\n\n");
                strcpy(mot2,&mot[j]);
                printf("%s\n",mot2);
                usleep(100000);
            }
        }
        printf("\033c");
        printf("\n\n\n\n");
        for(i=0;i<nbEspace;i++){
            printf(" ");
        }
        if(nbEspace<=90){
            nbEspace++;
            printf("%s\n",mot);
            usleep(100000);
        }
        else if(nbEspace>90){
            j=0;
            while(mot[j]!='\0'){
                printf("%c",mot[j]);
                j++;
            }
            printf("\n");
            mot[j-1]='\0';
            usleep(100000);
            nbEspace++;
        }
    }
}



void EmpruntEnCourt(Emprunts *tEmprunts,int sizeE,int idAd){
    int i,emp=1;

    for(i=0;i<sizeE;i++){
        if(tEmprunts[i].idAd==idAd){
            emp++;
            if(emp==2)
                printf("\nidEmprunt, idJeux, date d’emprunt\n");
            printf("%d  %d  %d/%d/%d\n",tEmprunts[i].id,tEmprunts[i].idJeu,tEmprunts[i].emprunt.jour,tEmprunts[i].emprunt.mois,tEmprunts[i].emprunt.an);
        }
    }
    if(emp==1)
        printf("\nCette utilisateur n'a aucun emprunt\n");
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
    int i,position,nbrepet=0;
    for(i=0;i<sizeA;i++){
        if(strcmp(tAdherents[i].nom,nom)==0){
            position=i;
            nbrepet++;
        }
    }
    if(nbrepet>1)
        return -1;
    else if(nbrepet==1)
        return position;
    else
        return -2;
}
int chercherPrenom(Adherents *tAdherents,char prenom[],int sizeA){
    int i,position,nbrepet=0;
    
    for(i=0;i<sizeA;i++){
        if(strcmp(tAdherents[i].prenom,prenom)==0){
            position=i;
            nbrepet++;
        }
    }
    if(nbrepet>1)
        return -1;
    else if(nbrepet==1)
        return position;
    else
        return -2;
} 


Adherents saisieAd(Adherents *tAdherent,int sizeA){
    Adherents nvAd;
    char genre;
    char nom[32], prenom[32];
    int lgt,erreur;

    printf("Saisie d'un nom : ");
    fgets(nom,32,stdin);
    nom[strlen(nom)-1]='\0';
    
    while(1){
        lgt=0;
        erreur=0;
        while(nom[lgt]!='\0'){
            lgt++;
            if(nom[lgt]=='0' || nom[lgt]=='1' || nom[lgt]=='2' || nom[lgt]=='3' || nom[lgt]=='4' || nom[lgt]=='5' || nvAd.nom[lgt]=='6' || nom[lgt]=='7' || nom[lgt]=='8' || nom[lgt]=='9')
                erreur=1;
        }
        if(erreur==1){
            printf("Erreur: le nom contient des nombres\n");
            printf("Saisie d'un nom : ");
            fgets(nom,32,stdin);
            nom[strlen(nom)-1]='\0';
        }
        else if(lgt<=1 && lgt!=-1){
            printf("Erreur: le nom est trop petit\n");
            printf("Saisie d'un nom : ");
            fgets(nom,32,stdin);
            nom[strlen(nom)-1]='\0';
        }
        else
            break;
    }
    concatener(nom,nvAd.nom);

    printf("Saisie d'un prénom : ");
    fgets(prenom,32,stdin);
    prenom[strlen(prenom)-1]='\0';
    
    while(1){
        lgt=0;
        erreur=0;
        while(prenom[lgt]!='\0'){
            lgt++;
            if(prenom[lgt]=='0' || prenom[lgt]=='1' || prenom[lgt]=='2' || prenom[lgt]=='3' || prenom[lgt]=='4' || prenom[lgt]=='5' || prenom[lgt]=='6' || prenom[lgt]=='7' || prenom[lgt]=='8' || prenom[lgt]=='9')
                erreur=1;
        }
        if(erreur==1){
            printf("Erreur: le prenom contient des nombres\n");
            printf("Saisie d'un prenom : ");
            fgets(prenom,32,stdin);
            prenom[strlen(prenom)-1]='\0';
        }
        else if(lgt<=1 && lgt!=-1){
            printf("Erreur: le prenom est trop petit\n");
            printf("Saisie d'un prenom : ");
            fgets(prenom,32,stdin);
            prenom[strlen(prenom)-1]='\0';
        }
        else
            break;
    }

    concatener(prenom,nvAd.prenom);

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

    sauvergarde(tAdherent,sizeA);
    return sizeA;
}

//Sous menu adherent
void Menu_ad(int *sizeA,int *sizeE,int *sizeJ,int *sizeR,Adherents *tAdherents,Jeux *tJeux,Emprunts **tEmprunts,Reserv** pointeur_vers_tReserv){
    int choix,condition,nbpoint=0;
    int i,j,positionNom,positionPrenom;
    char nom[32], prenom[32];
    char nomFinal[32],prenomFinal[32];
    char option;

    printf("Rentrer le nom : ");
    fgets(nom,32,stdin);
    nom[strlen(nom)-1]='\0';

    concatener(nom,nomFinal);
    positionNom=chercherNom(tAdherents,nomFinal,*sizeA);

    //si le nom est en double on demande le prenom
    if(positionNom==-1){
        printf("Rentrer le prénom : ");
        fgets(prenom,32,stdin);
        prenom[strlen(prenom)-1]='\0';

        concatener(prenom,prenomFinal);
        positionPrenom=chercherPrenom(tAdherents,prenomFinal,*sizeA);
    }

    //si le nom ou prenom n'est pas bon on précise qu'il n'existe pas
    if(positionNom==-2 || positionPrenom==-2)
        printf("\nCette adhérents n'existe pas\n\n");
    
    //temps que le nom ou le prenom est non existant on sort pas de la boucle
    while(positionNom==-2 || positionPrenom==-2){
        printf("Voulez vous crée un adhérent (o/n) : ");
        scanf("%c%*c",&option);
        printf("\n");
        //Si l'utilisateur ne veut pas crée de nouveau adhérent on lui propose de rentrer un non si il s'est juste tromper dans l'écriture ou revenir en arrières
        if(option=='n' || option=='N'){
            while(positionNom==-2 || positionPrenom==-2){
                printf("Rentrer votre nom :");
                fgets(nom,32,stdin);
                nom[strlen(nom)-1]='\0';
                
                concatener(nom,nomFinal);
                positionNom=chercherNom(tAdherents,nomFinal,*sizeA);
            
                //si le nom est en double on demande le prenom
                if(positionNom==-1){
                    printf("Rentrer le prénom : ");
                    fgets(prenom,32,stdin);
                    prenom[strlen(prenom)-1]='\0';

                    concatener(prenom,prenomFinal);
                    positionPrenom=chercherPrenom(tAdherents,prenomFinal,*sizeA);
                }
                if(positionNom==-2 || positionPrenom==-2){
                    printf("L'adhérent n'existe pas voulez vous continuez (o/n) : ");
                    scanf("%c%*c",&option);
                    if(option=='n' || option=='O')
                        return;
                }
            }
            break;
        }
        //choix on l'utilisateur veut crée un nouveau adhérent
        else if(option=='o' || option=='O'){
            *sizeA=ajoutAd(tAdherents,*sizeA);
            for(i=0;i<5;i++){
                system("clear");
                printf("\n\n\n\t\t\tCréation");
                for(j=0;j<nbpoint;j++){
                    printf(".");
                    usleep(250000);
                }
                nbpoint++;
            }
            printf("\n");
            strcpy(nomFinal,tAdherents[*sizeA-1].nom);
            positionNom=chercherNom(tAdherents,nomFinal,*sizeA);
            if(positionNom==-1){
                strcpy(prenomFinal,tAdherents[*sizeA-1].prenom);
                positionPrenom=chercherPrenom(tAdherents,prenomFinal,*sizeA);
            }
            break;
        }
        else
            printf("Cette option n'existe pas !\n");
    }
    
    //permet à l'utilisateur de renouveler sont abonnement si il est expirès
    if(positionNom<0){
        tempRestantAbo(tAdherents,positionPrenom,*sizeA);
        //j'attribue a la positionNom la positionPrenom car maintenant nous avons trouver a quelle nom nous avons affaire de plus j'utilise la variable positionNom ensuite
        positionNom=positionPrenom;
    }
    else
        tempRestantAbo(tAdherents,positionNom,*sizeA);

    choix=choixMenuAd(tAdherents,sizeA,nomFinal,positionNom);
    while(choix!=7){   
        switch (choix){
            case 1:
                EmpruntEnCourt(*tEmprunts,*sizeE,tAdherents[positionNom].id);
                break;
            case 2:
                *tEmprunts=nouvelEmprunt(*tEmprunts,tAdherents,tJeux,sizeE,*sizeA,*sizeJ,tAdherents[positionNom].id,*pointeur_vers_tReserv,sizeR);
                break;
            case 3:
                *pointeur_vers_tReserv=anulationReserv(*pointeur_vers_tReserv, sizeR, tAdherents[positionNom].id);
                break;
            case 4:
                *tEmprunts=retourEmprunt(tJeux,tAdherents,*tEmprunts,pointeur_vers_tReserv,sizeE,sizeJ,sizeR,tAdherents[positionNom].id);
                break;
            case 5:
                printf("\nInscrit le %d/%d/%d\n",tAdherents[positionNom].inscrip.jour,tAdherents[positionNom].inscrip.mois,tAdherents[positionNom].inscrip.an);
                tempRestantAbo(tAdherents,positionNom,*sizeA);
                break;
            case 6:
                return;
                break;
        }
        printf("\nTapez sur la touche entrée pour retourner au menu");
        getchar();
        choix=choixMenuAd(tAdherents,sizeA,nomFinal,positionNom);
    }
}

int tempRestantAbo(Adherents *tAdherents,int position,int sizeA){
    //on normalise une année (365 jours) ainsi que les mois (30 jours)
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
    

    if(restant<0){
        while(1){
            printf("\nL'abonnement est dépasser\n"); 
            printf("\nVoulez vous renouvellez votre abonnement (o/n) : ");
            scanf("%c%*c",&option);
            if(option == 'o' || option == 'O'){
                tAdherents[position].inscrip=dateAujrd();
                printf("\nRenouvellement effectuer ...\n");
                sauvergarde(tAdherents,sizeA);
                //fonction disponible par le header unistd.h sous linux uniquement windows.h et Sleep() pour windows
                sleep(1);
                break;
            }
            else if(option == 'n' || option == 'N'){
                printf("Il vous est donc impossible de reserver de nouveaux jeux\n");
                sleep(1);
                break;
            }
            else
                printf("Le choix n'est pas correct veuillez ressayer\n");
        }
    }
    return restant;  
}

//fonction qui permet d'enlever les espaces pour une meilleur utilisation dans le fichier texte
int concatener(char mot[],char motfinal[]){
    int i=0;

    while(mot[i]!='\0'){
        if(mot[i]==' ')
            motfinal[i]='_';
        else
            motfinal[i]=mot[i];
        i++;
    }
    motfinal[i]='\0';
}

Emprunts* nouvelEmprunt(Emprunts* tEmprunts,Adherents* tAdherents,Jeux* tJeux, int *sizeE, int sizeA, int sizeJ, int idAdherent,Reserv *tReservation,int *sizeR)
{
	int i, tempsAbo, nbEmprunt=0,passer;
	int idJeu, rankAdh,idChercher;
	for (i = 0; i < *sizeE; i++)
    	{
        	if (idAdherent == tEmprunts[i].idAd)
        		{
           	 		nbEmprunt++;
        		}
		}
    tempsAbo=tempRestantAbo(tAdherents,idAdherent-1,sizeA);

	if(nbEmprunt==3)
		{
			printf("Vous ne pouvez pas emprunter car vous êtes actuellement à 3 jeux empruntés.");
			return tEmprunts;
		}
    
    if (tempsAbo<0)
        {
            printf("Vous ne pouvez pas emprunter car votre abonnement a expiré.");
			return tEmprunts;
        }
	else
		{
			*sizeE=*sizeE+1;
			tEmprunts=realloc(tEmprunts,*sizeE*sizeof(Emprunts));
			if(*sizeE==1)
				{
					tEmprunts[*sizeE-1].id=1;
				}
			else
				{
					tEmprunts[*sizeE-1].id=tEmprunts[*sizeE-2].id+1;
				}
		}
	printf("Quel jeu voulez-vous emprunter\n");
	for(i=0;i<sizeJ;i++)
		{
			printf("%d) %s\n",i+1,tJeux[i].nom);
		}
	printf("Entrer le numéro du jeu voulu : ");
	scanf("%d%*c",&idChercher);
    passer=reserver(tJeux,tEmprunts,sizeJ,*sizeE,idChercher,&tReservation,sizeR,idAdherent);

    if(passer==1){
        tEmprunts[*sizeE-1].idJeu=idChercher;
        tEmprunts[*sizeE-1].idAd=idAdherent;
        tEmprunts[*sizeE-1].emprunt=dateAujrd();
    }
    return tEmprunts;
}

int exemplaireRestant(int idJeux,Jeux *tJeux,int sizeE,Emprunts *tEmprunts){
    int nbExDispo;
    int i;

    nbExDispo=tJeux[idJeux].nbExemplaires;

    for(i=0;i<sizeE;i++){
        if(idJeux==tEmprunts[i].idJeu-1){
            nbExDispo=nbExDispo-1;
        }
    }
    return nbExDispo;
}

int reserver(Jeux *tJeux,Emprunts *tEmprunts,int sizeJ,int sizeE,int idJeuChoisie,Reserv **tReservation,int *sizeR,int idAdherent){
    int i;
    int reservable;
    char option;

    reservable=exemplaireRestant(idJeuChoisie,tJeux,sizeE,tEmprunts);
    if(reservable==0){
        printf("\nCe jeux n'est pas encore disponible,voulez-vous le reserver (o/n) : ");
        scanf("%c%*c",&option);
        
        if(option=='o' || option=='O'){
            for(i=0;i<*sizeR;i++){
                if((*tReservation)[i].idJeu==idJeuChoisie && (*tReservation)[i].idAd==idAdherent){
                    printf("\nVous avez déjà emprunter ce jeux\n");
                    return -1;
                }
            }
            *sizeR=*sizeR+1;
		    *tReservation=realloc(*tReservation,*sizeR*sizeof(Reserv));
            (*tReservation)[*sizeR-1].id=*sizeR;
            (*tReservation)[*sizeR-1].idJeu=idJeuChoisie;
            (*tReservation)[*sizeR-1].res=dateAujrd();
            (*tReservation)[*sizeR-1].idAd=idAdherent;
        }
        else if(option=='n' || option=='N'){
            printf("Annulation du réservement");
        }
        else{
            printf("\nL'option n'existe pas\n");
        }
    }
    else
        return 1;
}
/*
int chercherIdDispo(Emprunts *tEmprunts,int sizeE){
    int i,id=1,min;
    for(i=0;i<sizeE;i++){
        if(tEmprunts[i].id!=id){
            min=id;
            tEmprunts[i].id;
        }
    }
}
*/
