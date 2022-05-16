#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5

#include "affichage.h"
#include "clavier_nouveau.h"
#include "dico.h"

int verifier_lettre_deja_teste(char* liste_lettre, int taille_liste_lettre,char lettre){
    int test=0;
    for(int i=0; i<taille_liste_lettre;i++){
        if(liste_lettre[i]==lettre){
            test++;
        }
    }
    if (test!=0){
        return(FALSE);
    }
    return(TRUE);
}

void recherche_lettre_impossible(char* clavier, char* lettres_impossible,int* nb_lettres_impossible,char* lettre_sur,int* pointeur_nb_lettre_sur) {
    
    for(int i=0;i<taille_alphabet;i++){
        if(clavier[i]=='0'){
            int test = verifier_lettre_deja_teste(lettres_impossible,*nb_lettres_impossible,alphabet[i]);
            if (test == TRUE) {
                int test =0;
                for (int j=0;j<*pointeur_nb_lettre_sur;j++){
                    if (lettre_sur[j]==alphabet[i]){
                        //verification qu la lettre qu'on veuille enleve n'est pas dans les lettres surs
                        test++;
                    }

                }
                if (test==0){
                    lettres_impossible[*nb_lettres_impossible]=alphabet[i];
                    *nb_lettres_impossible=*nb_lettres_impossible+1;
                }
            }
        }
    }
   
}

void recherche_lettre_sur(char* mot_a_deviner, char* mot_utilisateur, char* lettre_sur,int* pointeur_nb_lettre_sur,int* position_lettre_sur){
    
    for (int i=0;i<LONGUEUR;i++){
        if(mot_a_deviner[i]==mot_utilisateur[i]){
            int test = verifier_lettre_deja_teste(lettre_sur,*pointeur_nb_lettre_sur,mot_a_deviner[i]);
            if (test==TRUE){
                lettre_sur[*pointeur_nb_lettre_sur]=mot_utilisateur[i];
                position_lettre_sur[*pointeur_nb_lettre_sur]=i;
                *pointeur_nb_lettre_sur=*pointeur_nb_lettre_sur+1;
            }
        }
    }
    printf("liste lettre sur %s et liste de leur indice %ls \n",lettre_sur,position_lettre_sur);
    
}

void enlever_mot_lettre_impossible(char* dico_5_lettres, char* dico_lettre_impossible, char* clavier){

    char mot[LONGUEUR+1];
    
    //creation fichier du dico avec que les mots ne possèdant que des lettres possibles ou non teste
    FILE *dico_lettres_impossible = fopen(dico_lettre_impossible,"w");

    if (dico_lettres_impossible==NULL) {
        printf("erreur creation nouveau dico \n");
        exit(0);
    }

    //ouverture du dico des mots de 5 lettres
    FILE *dico = fopen(dico_5_lettres, "rb");

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
    int cpt=0;
    int indice;
    for (int i=0; i<LONGUEUR; i++) {
        indice = indice_lettre(mot[i]);
        if (clavier[indice]!='0'){ //test si ses 5 lettres sont encore possible ie differente de '0' dans le clavier
            cpt++;
        }
    }
    if (cpt == 5) {//si c'est le cas, on l'ecrit dans le nouveau fichier
        fprintf(dico_lettres_impossible,"%s\n",mot);
        //printf("%s\n",mot);
    }
    
    fscanf(dico, "%s", mot);
    while (!feof(dico)) {
        
        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }

        cpt=0;
        for (int i=0; i<LONGUEUR; i++) {
            indice = indice_lettre(mot[i]);
            if (clavier[indice]!='0'){ //test si ses 5 lettres sont encore possible ie differente de '0' dans le clavier
                cpt++;
            }
        }
        if (cpt == 5) {//si c'est le cas, on l'ecrit dans le nouveau fichier
            fprintf(dico_lettres_impossible,"%s\n",mot);
            //printf("%s\n",mot);
        }

        fscanf(dico, "%s", mot);
    }

    fclose(dico);
    fclose(dico_lettres_impossible);
}

void enlever_mot_lettre_mal_place(char* dico_sans_lettres_impossible, char* dico_lettres_possible, char* clavier, char lettre_sur, int position_lettre_sur){

    char mot[LONGUEUR+1];
    int indice_lettre_sur = indice_lettre(lettre_sur);
    //creation fichier du dico avec que les mots ne possèdant que des lettres possibles ou non teste
    FILE *dico_nouveau = fopen(dico_lettres_possible,"w");

    if (dico_nouveau==NULL) {
        printf("erreur creation nouveau dico \n");
        exit(0);
    }

    //ouverture du dico des mots de 5 lettres sans les lettres impossibles
    FILE *dico = fopen(dico_sans_lettres_impossible, "rb");

    if (dico == NULL) {
        printf("erreur ouverture fichier avec que les lettres possible\n");
        exit(0);
    }

    //lecture premier mot
    fscanf(dico, "%s", mot);

    if (mot == NULL) {
        printf("erreur lecture mot dans le fichier \n");
        exit(0);
    }

    if (mot[position_lettre_sur] == clavier[indice_lettre_sur]) {//test si le mot du dico à la lettre sur bien place
        fprintf(dico_nouveau,"%s\n",mot);
        //printf("%s\n",mot);
    }
    
    fscanf(dico, "%s", mot);


    while (!feof(dico)) {
        
        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }

        if (mot[position_lettre_sur] == clavier[indice_lettre_sur]) {//test 
            fprintf(dico_nouveau,"%s\n",mot);
            //printf("%s\n",mot);
        }

        fscanf(dico, "%s", mot);
    }

    fclose(dico);
    fclose(dico_nouveau);
}

void nouveau_mot(char* dico_lettres_possible,char* nouveau_mot){
    int taille = trouver_nombre_de_mots(dico_lettres_possible);
    printf("taille %d \n",taille);
    
    tirage_mot(dico_lettres_possible,taille,nouveau_mot);
    
     
}