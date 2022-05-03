#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5



int recherche (char* mot_utilisateur, char* fichier, int taille, char* mot) {
    int compa;

    //ouverture du dico
    FILE *dico = fopen(fichier, "rb");

    //test ouverture
    if (dico == NULL) {
        printf("erreur ouverture fichier dico avec que les mots d'une certaine longueur \n");
        exit(0);
    }

    for (int indice=0; indice<=taille;indice++){
        fscanf(dico, "%s", mot) ;
        compa = strcmp(mot,mot_utilisateur);
        if (compa == 0) {
            return(TRUE);
        }
    }
    fclose(dico);
    return(FALSE);
}



void affichage (char* mot_a_deviner, char* mot_utilisateur, char* fichier, int taille) {
/* prend en argument le mot rentré par l'utilisateur et le mot à deviner et affiche les informartions à l'utilisateur selon si 
les lettres sont bien placées (x), présente mais au mauvais endroit (o) ou non présente dans le mot à deviner (-) */

    // vérification de la longueur du mot donnée par l'utilisateur et vérification de la présence dans le dictionnaire 
    char mot[LONGUEUR];
    if (recherche(mot_utilisateur,fichier,taille,mot) == FALSE) {
           printf("le mot n'est pas dans le dictionnaire, merci d'en tenter un autre /n");
           exit(0);
       }

    int cpt=0;
    int tableau1[LONGUEUR];
    int tableau2[LONGUEUR];

    for (int j=0; j<LONGUEUR;j++){
      tableau2[j]=0;           // marquage de chaque lettre du mot à deviner
    }

    for (int i=0; i<LONGUEUR; i++) {
         tableau1[i]=0; 
        for (int j=0; j<LONGUEUR;j++){
            if ((mot_utilisateur[i]==mot_a_deviner[j])&&(cpt==0)&&(tableau2[j]==0)){
                if (i==j) {
                    printf("x");
                    tableau1[i]=1;  //marquage du mot utilisateur pour savoir si la lettre a été trouvée dans le mot mystère 
                    tableau2[j]=1;  //marquage du mot mystère pour savoir que la lettre a déjà été utilisée
                    cpt=1;
                } else {
                    printf("o");
                    tableau1[i]=1;   //marquage du mot utilisateur pour savoir si la lettre a été trouvée dans le mot mystère 
                    tableau2[j]=1;  //marquage du mot mystère pour savoir que la lettre a déjà été utilisée
                    cpt=1;
                }
            }
        }
        cpt=0;    
        if (tableau1[i]==0) {
           printf("-");
        }
    }
}