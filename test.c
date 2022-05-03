#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE -1
#define LONGUEUR 5

#include "affichage.c"

#include "dico.c"


int main() {
    srand(time(NULL));

    char mot_a_deviner[LONGUEUR];
    char* nom_dico_longueur = "dico_5.txt";
    int taille;
    
    //creation du dico de mot de 5 lettres, taille et 
    mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
    taille = trouver_nombre_de_mots(nom_dico_longueur);
    tirage_mot(nom_dico_longueur,taille,mot_a_deviner);
 

    char* mot_utilisateur = "bancs";

    affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille);

    return(0);
}