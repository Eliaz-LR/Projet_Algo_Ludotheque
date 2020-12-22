#include "ludoproj.h"

void global(void){
    int choix;
    char c;
    choix=choixMenu();
    while(choix!=7){   
        switch (choix){
            case 1:
                printf("Choix 1");
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
        c=getchar();
        choix=choixMenu();
    }
}
int main(void){
    global();
    return 0;
}