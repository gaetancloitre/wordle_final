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
    FILE *dico_ancien = fopen(nom_dico_a_copier, "r");

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
        //printf("%s\n",mot);
        fscanf(dico_ancien,"%s",mot);
    }

    fclose(dico_ancien);
    fclose(dico_nouveau);

}

void affichage_mot_fichier(char* nom_fichier){

    FILE *fichier = fopen(nom_fichier,"r");
    if (fichier==NULL){
        printf("erreur \n");
        exit(0);
    }

    char mot[LONGUEUR+1];
    fscanf(fichier,"%s",mot);
    printf("%s \n",mot);

    while(!feof(fichier)){
        fscanf(fichier,"%s",mot);
        printf("%s \n",mot);
    }
    fclose(fichier);
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
    
    for(int i=0;i<taille_alphabet;i++){//on parcours toutes les lettres de l'alphabet
        if(clavier[i]=='0'){
            int test = verifier_lettre_deja_teste(lettres_impossible,*nb_lettres_impossible,alphabet[i]);
            
            if (test == TRUE) {//ie la lettre n'a pas ete repere avant comme lettre impossible
                int test_sur = 0;
                int test_mal_place =0;

                for (int j=0;j<*pointeur_nb_lettre_sur;j++){
                    if (lettre_sur[j]==alphabet[i]){
                        //verification qu la lettre qu'on veuille enleve n'est pas dans les lettres surs
                        test_sur++;
                    }
                }
                for (int j=0;j<*pointeur_nb_lettre_mal_place;j++){
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
            //parcourir liste lettre sur
            int test=0;
            for (int j=0;j<*pointeur_nb_lettre_sur;j++){
                if((mot_utilisateur[i]==lettre_sur[j])&&(position_lettre_sur[j]==i)){
                    test++;
                    //si le lettre est la meme et que la position aussi, alors on l'a deja trouve
                }
            }
            if (test==0){
                lettre_sur[*pointeur_nb_lettre_sur]=mot_utilisateur[i];
                position_lettre_sur[*pointeur_nb_lettre_sur]=i;
                *pointeur_nb_lettre_sur=*pointeur_nb_lettre_sur+1;       
            }


            /*
            int test = verifier_lettre_deja_teste(lettre_sur,*pointeur_nb_lettre_sur,mot_a_deviner[i]);      
            if (test==TRUE){
                lettre_sur[*pointeur_nb_lettre_sur]=mot_utilisateur[i];
                position_lettre_sur[*pointeur_nb_lettre_sur]=i;
                *pointeur_nb_lettre_sur=*pointeur_nb_lettre_sur+1;
            }
            */
            /*
            if (test==FALSE){
                int position;
                //but : verifier la position de la lettre sur qu'on vient de trouver pour voir si on l'a deja reperer ou si c'est un doublon
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
            */

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

void enlever_mot_lettre_impossible(char* dico_ancien, char* dico_nouveau, char* lettre_impossible, int* pointeur_nb_lettre_impossible){

    char mot[LONGUEUR+1];
    
    //creation fichier du dico avec que les mots ne possèdant que des lettres possibles ou non teste
    FILE *dico_lettres_impossible = fopen(dico_nouveau,"w");

    if (dico_lettres_impossible==NULL) {
        printf("erreur creation nouveau dico \n");
        exit(0);
    }

    //ouverture du dico des mots de 5 lettres
    FILE *dico = fopen(dico_ancien, "r");

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
            printf("ZUT \n");
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

    
    if (*pointeur_nb_lettre_sur!=0){
        
        char mot[LONGUEUR+1];
        char* dico_tampon = "dico_tampon.txt";
        //printf("indice lettre sur %d \n",indice_lettre_sur);
        //creation fichier du dico avec que les mots ne possèdant que des lettres possibles ou non teste
        //FILE *dico_nouveau = fopen(dico_lettres_possible,"w");
        FILE *dico_nouveau = fopen(dico_tampon,"w");
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
        //printf("lecture mots dico \n");
        //lecture premier mot
        fscanf(dico, "%s", mot);
        
        if (mot == NULL) {
            printf("erreur lecture mot dans le fichier \n");
            exit(0);
        }
        int test =0;

        for (int i=0;i<*pointeur_nb_lettre_sur;i++){//on parcours toutes les lettre surs et leur position
            if(mot[position_lettre_sur[i]]!=lettre_sur[i]){//si ce n'est la bonne lettre, on incremente
                test++;
                
            }
        }
        if (test==0) {//test si le mot du dico à la lettre sur bien place ie on a pas incremente le test
            fprintf(dico_nouveau,"%s\n",mot);//on ecrit le mot dans le nouveau fichier texte
            
            //printf("%s\n",mot);
        }
        
        fscanf(dico, "%s", mot); //on lit le mot suivant


        while (!feof(dico)) {//tant qu'on arrive pas à la fin du fichier
            
            if (mot == NULL) {//test de la lecture du mot
                printf("erreur lecture mot dans le fichier \n");
                exit(0);
            }

            test = 0;
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
                //printf("%s\n",mot);
            }
            //printf("valeur test %d et mot lu %s \n",test,mot);
            fscanf(dico, "%s", mot);
        }
        
        fclose(dico);
        fclose(dico_nouveau);
        //printf("affichage avant copie dico tampon \n");
        //affichage_mot_fichier(dico_tampon);
        copie_dico(dico_tampon,dico_lettres_possible);
        //printf("affichage apres copie du dico final \n");
        //affichage_mot_fichier(dico_lettres_possible);
    }
    if (*pointeur_nb_lettre_sur==0){
        copie_dico(dico_sans_lettres_impossible,dico_lettres_possible);
    }
}

void enlever_mot_sans_lettre_mal_place(char* dico_ancien, char* dico_nouveau, char* lettre_mal_place,int* pointeur_nb_lettre_mal_place){
    if(*pointeur_nb_lettre_mal_place==0){
        copie_dico(dico_ancien,dico_nouveau);
    }

    FILE* ancien_dico = fopen(dico_ancien,"r");
    if(ancien_dico==NULL){
        printf("erreur \n");
        exit(0);
    }
    FILE* nouveau_dico=fopen(dico_nouveau,"w");
    if(nouveau_dico==NULL){
        printf("erreur\n");
        exit(0);
    }
    char mot[LONGUEUR+1];
    int test=0;
    int test_compteur=0;
    int* compteur_lettre_mp = malloc(*pointeur_nb_lettre_mal_place*sizeof(int));
    for(int k=0;k<*pointeur_nb_lettre_mal_place;k++){//initialisation
        compteur_lettre_mp[k]=0;
    }
    fscanf(ancien_dico,"%s",mot);
    if(mot==NULL){
        printf("erreur \n");
        exit(0);
    }
    for(int i=0;i<LONGUEUR;i++){
        for(int j=0;j<*pointeur_nb_lettre_mal_place;j++){
            if (mot[i]==lettre_mal_place[j]){
                compteur_lettre_mp[j]++;
                test++;
                //attention cas lettre double ...
            }
        }
    }
    if(test>=*pointeur_nb_lettre_mal_place){
        for (int k =0;k<*pointeur_nb_lettre_mal_place;k++){
            if (compteur_lettre_mp[k]==0){
                test_compteur++;
            }
        }
        if(test_compteur==0){
            fprintf(nouveau_dico,"%s\n",mot);
            //printf("test %d et mot %s \n",test,mot);
        }
        
    }
    fscanf(ancien_dico,"%s",mot);

    while(!feof(ancien_dico)){
        if(mot==NULL){
            printf("erreur \n");
            exit(0);
        }
        test=0;
        test_compteur=0;
        for(int k=0;k<*pointeur_nb_lettre_mal_place;k++){//initialisation
            compteur_lettre_mp[k]=0;
        }
        for(int i=0;i<LONGUEUR;i++){
            for(int j=0;j<*pointeur_nb_lettre_mal_place;j++){
                if (mot[i]==lettre_mal_place[j]){
                    compteur_lettre_mp[j]++;
                    test++;
                    //attention cas lettre double ...
                }
            }
        }
        if(test>=*pointeur_nb_lettre_mal_place){
            for (int k =0;k<*pointeur_nb_lettre_mal_place;k++){
                if (compteur_lettre_mp[k]==0){
                    test_compteur++;
                }
            }
            if(test_compteur==0){
                fprintf(nouveau_dico,"%s\n",mot);
                //printf("test %d et mot %s \n",test,mot);
            }
            
        }
        fscanf(ancien_dico,"%s",mot);
    }

    fclose(ancien_dico);
    fclose(nouveau_dico);


}



void nouveau_mot(char* dico_lettres_possible,char* nouveau_mot){
    int taille = trouver_nombre_de_mots(dico_lettres_possible);
    //printf("taille du dico %d \n",taille);
    tirage_mot(dico_lettres_possible,taille,nouveau_mot);
    
     
}

void enlever_mot(char* dico_ancien, char* dico_nouveau, char* mot_a_enlever){
    char mot[LONGUEUR+1];

    //creation fichier du nouveau dico dans lequel on veut copier le contenu du premier dico
    FILE *nouveau_dico = fopen(dico_nouveau,"w");

    if (nouveau_dico==NULL) {
        printf("erreur creation dico nouveau \n");
        exit(0);
    }

    //ouverture du dico que l'on veut copier
    FILE *ancien_dico = fopen(dico_ancien, "r");

    if (ancien_dico == NULL) {
        printf("erreur ouverture dico ancien \n");
        exit(0);
    }

    //lecture premier mot
    fscanf(ancien_dico,"%s",mot);

    //test lecture mot
    if (mot == NULL) {
        printf("erreur lecture mot dico ancien \n");
        exit(0);
    }
    int compa = strcmp(mot,mot_a_enlever);
    if (compa !=0){
        fprintf(nouveau_dico,"%s\n",mot);
    }
    
    //on parcours tout le fichier
    fscanf(ancien_dico,"%s",mot);

    while(!feof(ancien_dico)) {
        if (mot == NULL) {
            printf("erreur lecture mot dico ancien \n");
            exit(0);
        }
        compa = strcmp(mot,mot_a_enlever);
        if(compa!=0){
            fprintf(nouveau_dico,"%s\n",mot);
        }
        //printf("%s\n",mot);
        fscanf(ancien_dico,"%s",mot);
    }

    fclose(ancien_dico);
    fclose(nouveau_dico);

}