#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5

#include "clavier_nouveau.h"

int recherche(char* mot_utilisateur, char* fichier, int taille, char* mot) {
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

int recherche_gus(char* mot_utilisateur, char* fichier) {
    int compa;
    char mot[LONGUEUR+1];

    //ouverture du dico
    FILE *dico = fopen(fichier, "rb");

    //test ouverture
    if (dico == NULL) {
        printf("erreur ouverture fichier dico avec que les mots d'une certaine longueur \n");
        exit(0);
    }

    //lecture premier mot
    fscanf(dico, "%s", mot) ;

    if (mot == NULL) {
        printf("erreur lecture mot dans le fichier \n");
        exit(0);
    }

    compa = strcmp(mot,mot_utilisateur);
    

    if (compa==0){
        return(TRUE);
    }

    //on rentre dans ta boucle
    fscanf(dico, "%s", mot) ;
    while(!feof(dico)) {
        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }

        compa = strcmp(mot,mot_utilisateur);
        //printf("compa %d \n",compa);
            if (compa==0){
            return(TRUE);
        }
        fscanf(dico, "%s", mot) ;
    }

    fclose(dico);
    return(FALSE);
}


void affichage (char* mot_a_deviner, char* mot_utilisateur, char* fichier, int taille, char* clavier) {
/* prend en argument le mot rentré par l'utilisateur et le mot à deviner et affiche les informartions à l'utilisateur selon si 
les lettres sont bien placées (x), présente mais au mauvais endroit (o) ou non présente dans le mot à deviner (-) */ 
    

    // vérification de la longueur du mot donnée par l'utilisateur et vérification de la présence dans le dictionnaire 

    //char mot[LONGUEUR+1];
    while (recherche_gus(mot_utilisateur,fichier) == FALSE) {
        printf("le mot %s n'est pas dans le dictionnaire, merci d'en tenter un autre \n",mot_utilisateur);
        printf("Rentrez un nouveau mot :\n");
        scanf("%s",mot_utilisateur);
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
           int indice = indice_lettre(mot_utilisateur[i]);
           clavier[indice]='0';
        }
    }

       printf("\n");
}

void a_gagner(char* mot_a_deviner, char* mot_utilisateur) {

    int compa;
    //printf("%s et %s \n",mot_a_deviner,mot_utilisateur);
    compa=strcmp(mot_a_deviner,mot_utilisateur);

    if (compa == 0) {
        printf("Félicitation !\n");
        exit(0);
    } 
}