#include "ludoproj.h"

void afficheMenu(void){
    system("clear");
    printf("\t\t\t\tMenu\n");
    printf("\t\t1: Option 1\n");
    printf("\t\t2: Option 2\n");
    printf("\t\t3: Option 3\n");
    printf("\t\t4: Option 4\n");
    printf("\t\t5: Option 5\n");
    printf("\t\t6: Option 6\n");
    printf("\t\t7:quitter\n");
}

int choixMenu(void){
    int choix;
    char c;
    afficheMenu();
    printf("Quelle est votre choix : ");
    scanf("%d%*c",&choix);

    while (choix<1 || choix>6){
        printf("\n\nChoix incorect\n");
        printf("Retapez sur la touche entrée pour revenir au menu");
        c=getchar();
        afficheMenu();
        printf("Quelle est votre choix : ");
        scanf("%d%*c",&choix);
    }

    return choix;
}