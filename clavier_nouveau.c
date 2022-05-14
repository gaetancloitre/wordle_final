#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int taille_alphabet = 26;
char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


char* initialisation_clavier(char clavier[27]) {
    strcpy(clavier,alphabet);
    return(clavier);
}

void affichage_clavier(char clavier[27]){
    //code : si la letter = 0, alors n'est pas dans le mot
    for(int i=0;i<taille_alphabet;i++){
        if(clavier[i] != '0') {
            printf("%c ",clavier[i]);
        }
    }
    printf("\n");
}