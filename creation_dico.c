#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dico.c"

#define LONGUEUR 5

int main () {
    /*main pour obtenir le dico avec les mots de la longueur souhaitée*/

    //creation dico avec mot d'une certaine longueur
    char* fichier = mot_de_cinq_lettres("dico_scrabble.txt","dico_5.txt",LONGUEUR);

    //creation du tableau
    int taille = taille_dico_lettres(fichier);

    struct dico_en_tableau t;
    t=transformation_dico_tableau(fichier, taille, t);



    free(t.tableau_mots); 

    return(0);
}