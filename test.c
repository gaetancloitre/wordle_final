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

    char mot_a_deviner[LONGUEUR+1];
    char mot_utilisateur[LONGUEUR+1];
    char* nom_dico_longueur = "dico_5.txt";
    int taille;
    int compteur;
    
    //creation du dico de mot de 5 lettres, taille et 
    
    mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
    taille = trouver_nombre_de_mots(nom_dico_longueur);
    tirage_mot(nom_dico_longueur,taille,mot_a_deviner);
    
    for (compteur=1; compteur <=6; compteur++){
        printf("essai %d \n",compteur);

        printf("Rentrez le mot : \n");
        scanf("%s",mot_utilisateur);
        affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille);

        a_gagner(mot_a_deviner,mot_utilisateur);

    }

    printf("Dommage, le mot était %s. \nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
    
    

    

    return(0);
}