#include "ludoproj.h"

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
    char c;
    afficheMenu();
    printf("\nQuelle est votre choix : ");
    scanf("%d%*c",&choix);

    /*Condition qui indique que le choix de l'utilisateur doit être compris entre 1 et 7*/
    while (choix<1 || choix>7){
        printf("\nChoix incorect %d n'est pas compris entre 1 et 7\n",choix);
        printf("Retapez sur la touche entrée pour revenir au menu");
        c=getchar();
        afficheMenu();
        printf("\nQuelle est votre choix : ");
        scanf("%d%*c",&choix);
    }

    return choix;
}