#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

/* lecture d'un dictionnaire francais et réecriture dans le bon format (sans accents) et avec seulement les mots de 5 lettres */

char* fichier;
int longueur;
char* fichier_lettre;

struct dico_en_tableau {
    int taille;
    char** tableau_mots;
};




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

void mot_de_cinq_lettres(char* fichier, char* fichier_lettre, int longueur) {
    /*prend en argument nom du fichier associé au dictionnaire de la langue francais et le nom du fichier dans
    lequel on réecrit le dictionnaire en enlevant les mots de longueur autre que longueur. renvoie le nom du fichier
    dans lequel on ecrit le nouveau dico
    */

    char mot[254];
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

//test


int trouver_nombre_de_mots(char* fichier) {
    /* prend en argument le fichier correspondand au dictionnaire avec que les mots d'une certaine longueur, la pluspart du temps 5
    lettres et renvoie la taille de ce fichier, c'est à dire le nombre de mots*/

    int cpt=0;
    char mot[254];

    //ouverture du dico
    FILE *dico = fopen(fichier, "rb");

    if (dico == NULL) {
        printf("erreur ouverture fichier dico avec que les mots d'une certaine longueur \n");
        exit(0);
    }

    //lecture premier mot
    fscanf(dico, "%s", mot);

    if (mot == NULL) {
        printf("erreur lecture mot dans le fichier \n");
        exit(0);
    }

    cpt++; //incrementation

    while( !feof(dico)) {
        //on veut juste recuperer le nombre de mots de telle longueur. pas besoin a priori de lire le mot
        fscanf(dico, "%s", mot);
        cpt++; //incrementation
        //printf("%d\n",cpt);
    }

    return(cpt);
}




struct dico_en_tableau transformation_dico_tableau(char* fichier, int taille, struct dico_en_tableau t) {
    /*prend en argument le nom du fichier associé au dictionnaire contenant que les mots d'une certaine longueur et le nombre de mots associés et
    renvoie une strcuture contenant la taille du tableau et le tableau de mots*/

    char mot[254];
    int indice=0;
    t.taille = taille;


    //ouverture du dico
    FILE *dico = fopen(fichier, "rb");

    //test ouverture
    if (dico == NULL) {
        printf("erreur ouverture fichier dico avec que les mots d'une certaine longueur \n");
        exit(0);
    }

    //lecture premier mot
    fscanf(dico, "%s", mot);

    if (mot == NULL) {
        printf("erreur lecture mot dans le fichier \n");
        exit(0);
    }

    printf("indice %d \n",indice);
    t.tableau_mots[indice]=mot;
    printf("%s \n",t.tableau_mots[indice]);

    indice++;
    printf("indice %d \n",indice);

    // parcours du fichier texte et ajout les mots dans le tableau
    while(! feof(dico)) {

        fscanf(dico,"%s",mot);
        
        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }

        printf("%s \n",mot);
        t.tableau_mots[indice]=mot;
        printf("%s \n",t.tableau_mots[indice]);

        indice++;
        
    }
    printf("indice finale %d \n",indice);
    printf("fonction finale %s \n",t.tableau_mots[indice-1]);
    printf("mot au hasard dans le dico %s \n",t.tableau_mots[500]);
    return(t);
}

void tirage_mot(char* fichier, int taille, char* mot) {
    /* renvoie le mot à deviner par passage de pointeur en prenant en argument le nom du fichier, la taille ie le nombre de ligne, et le pointeur
    */
   

    int nb_alea = rand()%taille;
    

    //ouverture du dico
    FILE *dico = fopen(fichier, "rb");

    //test ouverture
    if (dico == NULL) {
        printf("erreur ouverture fichier dico avec que les mots d'une certaine longueur \n");
        exit(0);
    }

    for (int indice=0; indice<=nb_alea;indice++){
        fscanf(dico, "%s", mot) ;

        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier 1\n");
            exit(0);
        }

        

    }
    //printf("mot a deviner en cours %s \n",mot);
    fclose(dico);
    /*
    //lecture premier mot
    fscanf(dico, "%s", mot) ;

    if (mot == NULL) {
        printf("erreur lecture mot dans le fichier 1\n");
        exit(0);
    }

    if (indice == nb_alea) {
        exit(0);
    }

    indice ++;
    printf("nb alea %d \n",nb_alea);
    

    while(!feof(dico)){
        fscanf(dico, "%s", mot);
        //printf("%s \n",mot);
        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier 2\n");
            exit(0);
        }
        if (indice == nb_alea) {
            exit(0);
        }
        indice++;
    }
    printf("indice %d \n",indice);
    printf("mot %s \n",mot);
    if (indice == nb_alea) {
        exit(0);
    }
    exit(0);  //pb entre nb_aleatoire et indice, normalement ne peut pas arriver
    */
}