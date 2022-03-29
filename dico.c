#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* lecture d'un dictionnaire francais et récriture dans le bon format (sans accent) et avec seulement les mots de 5 lettres */

char* fichier;
int longueur;
char* fichier_lettre;

int test_longueur(char* mot,int longueur) {
    /*prend en argument un mot et une longueur et renvoie True si le mot fait une longueur longueur et false 
    sinon. convention :  True = +1; False = -1 */
    
    int cpt=0;

    while (mot[cpt] != '\0') {
        cpt++;
    }

    if (cpt == longueur) {
        return(TRUE);
    }
    else {
        return(FALSE);
    }

}

void mot_de_cinq_lettre(char* fichier, char* fichier_lettre, int longueur) {
    /*prend en argument nom du fichier associé au dictionnaire de la langue francais et le nom du fichier dans
    lequel on réecrit le dictionnaire en enlevant les mots de longueur autre que longueur
    */

    char mot[256];
    int test;
    //creation fichier du dico avec que les mots de longueur longueur
    FILE *dico_5lettres = fopen(fichier_lettre,"w");

    if (dico_5lettres==NULL) {
        printf("erreur creation nouveau dico \n");
        exit(0);
    }

    //ouverture du dico
    FILE *dico = fopen(fichier, "rb");

    if (dico == NULL) {
        printf("erreur ouverture fichier dictionnaire francais \n");
        exit(0);
    }

    //lecture premier mot
    fscanf(dico, "%s", mot);

    if (mot == NULL) {
        printf("erreur lecture mot dans le fichier \n");
        exit(0);
    }

    
    while (!feof(dico)) {
        test = test_longueur(mot,longueur);

        if (test == TRUE) {
            fprintf(dico_5lettres,"%s\n",mot);
        }

        fscanf(dico, "%s", mot);

        if (mot == NULL) {
            //test erreur
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }
    }

    fclose(dico);
    fclose(dico_5lettres);
    

}

int main (int argc, char *argv[]) {
    char lettre = *argv[1];

    printf("lettre %s et code %d \n",&lettre, lettre);
    printf("resultat test %d \n",test_longueur("motus",5));
    mot_de_cinq_lettre("dico_scrabble.txt","dico_5.txt",5);
    return(0);
}