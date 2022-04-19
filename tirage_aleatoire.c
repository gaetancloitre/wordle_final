#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int trouver_nombre_mot(char* fichier) {
    /* prend en argument le nom du dico considéré et renvoie le nombre de mots de ce dico*/

    char mot[256];
    int cpt=0;

    //ouverture du dico
    FILE *dico = fopen(fichier, "rb");

    if (dico == NULL) {
        printf("erreur ouverture fichier dictionnaire  \n");
        exit(0);
    }

    //lecture premier mot
    fscanf(dico, "%s", mot);

    if (mot == NULL) {
        printf("erreur lecture mot dans le fichier \n");
        exit(0);
    }
    cpt++;
    
    while (!feof(dico)) {
        
        fscanf(dico, "%s", mot);

        if (mot == NULL) {
            //test erreur
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }
        cpt++;
    }

    fclose(dico);
    return(cpt);
}




char* choisir_mot_aleatoire(char** tableau_dico, int taille) {
    /*prend en argument le dictionnaire sous forme de tableau et la taille de celui-ci et renvoie un mot aléatoire du dico*/

    int nb_alea = rand()%taille;

    char* mot_alea = tableau_dico[nb_alea];

    return(mot_alea);
}