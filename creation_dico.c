#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "dico.c"

#define LONGUEUR 5


/*
void creation_dico_et_mot(char* mot, char* nom_dico_longueur, int* taille){
    //srand(time(NULL));
    main pour obtenir le dico avec les mots de la longueur souhaitée
    
    creation dico avec mot d'une certaine longueur
    mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
    //printf("1 \n");
    //printf("%s \n",nom_dico_longueur);
    /reation du tableau
    trouver_nombre_de_mots(nom_dico_longueur,taille);

    
    struct dico_en_tableau t;
    t.tableau_mots = malloc(taille*sizeof(char[LONGUEUR]));

    //test echec creation
    if (t.tableau_mots == NULL) {
        printf("erreur création tableau mot \n");
        free(t.tableau_mots);
        exit(0);
    }

    t=transformation_dico_tableau(nom_dico_longueur, taille, t);

    printf("taille %d \n",taille);
    printf("test tableau debut %s \n",t.tableau_mots[0]);
    printf("test tableau fin %s \n",t.tableau_mots[7476]);

    for (int i=0;i<taille;i++) {
        free(t.tableau_mots[i]);
    }
    free(t.tableau_mots); 
    
    printf("1\n");
    

    tirage_mot(nom_dico_longueur,taille,mot);
    printf("test  \n");
    printf("mot %s \n",mot);

    
}
*/