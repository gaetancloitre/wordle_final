#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5

#include "affichage.h"
#include "clavier_nouveau.h"
#include "dico.h"

void copie_dico(char* nom_dico_a_copier, char* nouveau_dico){
    char mot[LONGUEUR+1];

    //creation fichier du nouveau dico dans lequel on veut copier le contenu du premier dico
    FILE *dico_nouveau = fopen(nouveau_dico,"w");

    if (dico_nouveau==NULL) {
        printf("erreur creation dico nouveau \n");
        exit(0);
    }

    //ouverture du dico que l'on veut copier
    FILE *dico_ancien = fopen(nom_dico_a_copier, "rb");

    if (dico_ancien == NULL) {
        printf("erreur ouverture dico ancien \n");
        exit(0);
    }

    //lecture premier mot
    fscanf(dico_ancien,"%s",mot);

    //test lecture mot
    if (mot == NULL) {
        printf("erreur lecture mot dico ancien \n");
        exit(0);
    }

    fprintf(dico_nouveau,"%s\n",mot);
    //on parcours tout le fichier
    fscanf(dico_ancien,"%s",mot);
    while(!feof(dico_ancien)) {
        if (mot == NULL) {
            printf("erreur lecture mot dico ancien \n");
            exit(0);
        }
        fprintf(dico_nouveau,"%s\n",mot);
        fscanf(dico_ancien,"%s",mot);
    }

    fclose(dico_ancien);
    fclose(dico_nouveau);

}

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

void recherche_lettre_impossible(char* clavier, char* lettres_impossible,int* nb_lettres_impossible,char* lettre_sur,int* pointeur_nb_lettre_sur,char* lettre_mal_place, int* pointeur_nb_lettre_mal_place) {
    
    for(int i=0;i<taille_alphabet;i++){
        if(clavier[i]=='0'){
            int test = verifier_lettre_deja_teste(lettres_impossible,*nb_lettres_impossible,alphabet[i]);
            
            if (test == TRUE) {
                int test_sur = 0;
                int test_mal_place =0;

                for (int j=0;j<*pointeur_nb_lettre_sur;j++){
                    if (lettre_sur[j]==alphabet[i]){
                        //verification qu la lettre qu'on veuille enleve n'est pas dans les lettres surs
                        test_sur++;
                    }
                    if (lettre_mal_place[j]==alphabet[i]){
                        //verification que la lettre qu'on veuille enleve n'est pas simplement mam place
                        test_mal_place++;
                    }
                }
                if ((test_sur==0)&&(test_mal_place==0)){
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
            if (test==FALSE){
                int position;
                
                for (int j=0;j<*pointeur_nb_lettre_sur;j++){
                    if ((lettre_sur[j]==mot_utilisateur[i])&&(j!=i)){
                        
                        position=j;
                        int test2=0;
                        for (int k=0;k<*pointeur_nb_lettre_sur;k++){
                            if(position==position_lettre_sur[k]){
                                test2++;
                            }
                        }
                        if (test2==0) {
                            lettre_sur[*pointeur_nb_lettre_sur]=mot_utilisateur[i];
                            position_lettre_sur[*pointeur_nb_lettre_sur]=position;
                            *pointeur_nb_lettre_sur=*pointeur_nb_lettre_sur+1;
                        }

                    }
                }

            }

        }

    }
    //printf("liste lettre sur %s \n",lettre_sur);
    
}

void recherche_lettre_mal_place(char* mot_a_deviner, char* mot_utilisateur, char* lettre_mal_place, int* pointeur_nb_lettre_mal_place) {
    //fait une liste de lettre mal place

    for(int i=0;i<LONGUEUR;i++){
        for (int j=0;j<LONGUEUR;j++){
            
            if (mot_a_deviner[i]==mot_utilisateur[j]){
                //on verifie deja si la lettre est potentiellement mal place
                int test=0;
                for(int k=0;k<*pointeur_nb_lettre_mal_place;k++){
                    if(mot_utilisateur[j]==lettre_mal_place[k]){
                        
                        test++;
                    }
                }
                if (test==0){
                    //si lettre mal place et qu'on ne l'a pas deja repere, c'eswt tout bon
                    lettre_mal_place[*pointeur_nb_lettre_mal_place]=mot_utilisateur[j];
                    *pointeur_nb_lettre_mal_place=*pointeur_nb_lettre_mal_place+1;
                    

                }
            }
        }
    }
}

void enlever_mot_lettre_impossible(char* dico_5_lettres, char* dico_lettre_impossible, char* lettre_impossible, int* pointeur_nb_lettre_impossible){

    char mot[LONGUEUR+1];
    
    //creation fichier du dico avec que les mots ne possèdant que des lettres possibles ou non teste
    FILE *dico_lettres_impossible = fopen(dico_lettre_impossible,"w");

    if (dico_lettres_impossible==NULL) {
        printf("erreur creation nouveau dico \n");
        exit(0);
    }

    //ouverture du dico des mots de 5 lettres
    FILE *dico = fopen(dico_5_lettres, "r");

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
    int test=0;
    
    for (int i=0; i<LONGUEUR; i++) {
        //test de toutes les lettres du mot qu'on vient de lire
        for (int j=0;j<*pointeur_nb_lettre_impossible;j++) {
            if (mot[i]==lettre_impossible[j]){//si on retrouve une lettre du mot dans la liste des lettres impossible, on incremente
                test++;
            }
        }
    }
    //printf("test %d et %s\n",test,mot);
    if (test == 0) {//si on a pas incremente, c'est que pas de lettre impossiblle
        int verif =fprintf(dico_lettres_impossible,"%s\n",mot);
        if (verif==EOF){
            printf("MERDE \n");
            exit(0);
        }
        //printf("%s\n",mot);
    }
    
    fscanf(dico, "%s", mot);
    while (!feof(dico)) {
        
        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }

        test=0;
    
        for (int i=0; i<LONGUEUR; i++) {
            for (int j=0;j<*pointeur_nb_lettre_impossible;j++) {
                if (mot[i]==lettre_impossible[j]){//si on retrouve une lettre du mot dans la liste des lettres impossible, on incremente
                    test++;
                }
            }
        }
        //printf("test %d et %s\n",test,mot);
        if (test == 0) {//si on a pas incremente, c'est que pas de lettre impossiblle

            fprintf(dico_lettres_impossible,"%s\n",mot);
            //printf("%s\n",mot);
        }

        fscanf(dico, "%s", mot);
    }

    fclose(dico);
    fclose(dico_lettres_impossible);
}

void enlever_mot_lettre_mal_place(char* dico_sans_lettres_impossible, char* dico_lettres_possible, char* lettre_sur, int* position_lettre_sur, int* pointeur_nb_lettre_sur){
/*
    for (int i=0;i<*pointeur_nb_lettre_sur;i++){
        printf("%c %d,",lettre_sur[i],position_lettre_sur[i]);
    }
    printf("\n");
    */

    if (*pointeur_nb_lettre_sur!=0){
        char mot[LONGUEUR+1];
        
        //printf("indice lettre sur %d \n",indice_lettre_sur);
        //creation fichier du dico avec que les mots ne possèdant que des lettres possibles ou non teste
        FILE *dico_nouveau = fopen(dico_lettres_possible,"w");
        //printf("%s\n",dico_lettres_possible);
        if (dico_nouveau==NULL) {
            printf("erreur creation nouveau dico \n");
            exit(0);
        }

        //ouverture du dico des mots de 5 lettres sans les lettres impossibles
        FILE *dico = fopen(dico_sans_lettres_impossible, "r");

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
        int test =0;

        for (int i=0;i<*pointeur_nb_lettre_sur;i++){
            if(mot[position_lettre_sur[i]]!=lettre_sur[i]){
                test++;
                
            }
        }
        if (test==0) {//test si le mot du dico à la lettre sur bien place
            fprintf(dico_nouveau,"%s\n",mot);
            
            //printf("%s\n",mot);
        }
        
        fscanf(dico, "%s", mot);


        while (!feof(dico)) {
            
            if (mot == NULL) {
                printf("erreur lecture mot dans le fichier \n");
                exit(0);
            }

            test =0;
            for (int i=0;i<*pointeur_nb_lettre_sur;i++){
                //printf("position lettre sur %d lettre sur %c et lettre mot %c \n",position_lettre_sur[i],lettre_sur[i],mot[position_lettre_sur[i]]);
                if(mot[position_lettre_sur[i]]!=lettre_sur[i]){
                    test++;
                    //printf("%d %c \n",position_lettre_sur[i],mot[position_lettre_sur[i]]);
                
                }
            }
            
            if (test==0) {//test si le mot du dico à la lettre sur bien place
                fprintf(dico_nouveau,"%s\n",mot);
                //printf("mot %s \n",mot);
                printf("%s\n",mot);
            }

            fscanf(dico, "%s", mot);
        }

        fclose(dico);
        fclose(dico_nouveau);
    }

    copie_dico(dico_sans_lettres_impossible,dico_lettres_possible);
}

void nouveau_mot(char* dico_lettres_possible,char* nouveau_mot){
    int taille = trouver_nombre_de_mots(dico_lettres_possible);
    printf("taille %d \n",taille);
    
    tirage_mot(dico_lettres_possible,taille,nouveau_mot);
    
     
}