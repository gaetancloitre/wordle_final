#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1
#define LONGUEUR 5

#include "affichage.c"





int main() {
    char* mot_a_deviner = "aleas";
    char* mot_utilisateur = "aller";
    char** tableau_nul [3];
    &tableau_nul[0]-> "aleas";
    
    &tableau_nul[1] -> "aller";
    &tableau_nul[2] -> "trucs";
    int taille = 3;

    affichage(mot_a_deviner,mot_utilisateur,tableau_nul,taille);

    return(0);
}