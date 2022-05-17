#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE -1
#define LONGUEUR 5

#include "affichage.h"
#include "dico.h"
#include "clavier_nouveau.h"
#include "IA.h"
#include "IA_autre.c"



int main(int argc,char* argv[]) {
    srand(time(NULL));

    if (argc !=2){
        printf("problème chix mode de jeu \n");
        exit(0);
    }

    int mode=atoi(argv[1]);

    if(mode==0){
        //mode de jeu normal
        char mot_a_deviner[LONGUEUR+1];
        char mot_utilisateur[LONGUEUR+1];
        char* nom_dico_longueur = "dico_5.txt";
        int taille;
        int compteur;
        char pclavier[27];
        char* clavier = initialisation_clavier(pclavier);
        
        //creation du dico de mot de 5 lettres, taille et 
        
        mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
        taille = trouver_nombre_de_mots(nom_dico_longueur);
        tirage_mot(nom_dico_longueur,taille,mot_a_deviner);
        
        for (compteur=1; compteur <=6; compteur++){
            printf("essai %d \n",compteur);
            affichage_clavier(clavier);
            printf("Rentrez le mot : \n");
            scanf("%s",mot_utilisateur);
            affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);

            a_gagner(mot_a_deviner,mot_utilisateur);

        }
        affichage_clavier(clavier);
        printf("Dommage, le mot était %s. \nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
    }


    if (mode==1){
        //mode de jeu IA premiere solution

        char* nom_dico_longueur = "dico_5.txt";
        char mot_a_deviner[LONGUEUR+1];
        char* mot_utilisateur="TARIE";
        int taille;
        int compteur=1;
        char pclavier[27];
        char* clavier = initialisation_clavier(pclavier);

        mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
        taille = trouver_nombre_de_mots(nom_dico_longueur);
        tirage_mot(nom_dico_longueur,taille,mot_a_deviner);

        printf("essai %d \n",compteur);

    
        printf("Rentrez le mot : \n");
        printf("%s\n",mot_utilisateur);
        affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);

        a_gagner(mot_a_deviner,mot_utilisateur);

        for (compteur=2; compteur <=6; compteur++){
            printf("essai %d \n",compteur);

            printf("Rentrez le mot : \n");
            mot_utilisateur = creation_mot_IA(mot_a_deviner, mot_utilisateur, nom_dico_longueur, taille,clavier); 
            printf("%s",mot_utilisateur);
            affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);

            a_gagner(mot_a_deviner,mot_utilisateur);

        }

        printf("Dommage, le mot était %s. \nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
    }

    if (mode==2) {
    //mode de jeu IA deuxième solution

        char* nom_dico_longueur = "dico_5.txt";
        char mot_a_deviner[LONGUEUR+1];
        char mot_utilisateur[LONGUEUR+1]="TARIE";
        int taille;
        int compteur=1;
        char pclavier[27];
        char* clavier = initialisation_clavier(pclavier);
        char* lettres_impossibles=malloc(27*sizeof(char));
        char* lettre_sur = malloc(LONGUEUR*sizeof(char));
        char* lettre_mal_place = malloc(LONGUEUR*sizeof(char));
        int nb_lettres_impossible=0;
        int nb_lettre_sur=0;
        int nb_lettre_mal_place=0;
        int* pointeur_nb_lettres_impossible = &nb_lettres_impossible;
        int* pointeur_nb_lettre_sur = &nb_lettre_sur;
        int* pointeur_nb_lettre_mal_place = &nb_lettre_mal_place;
        int* position_lettre_sur=malloc((LONGUEUR)*sizeof(int));
        for (int i=0; i<LONGUEUR;i++) {position_lettre_sur[i]=0;}
        //printf("test affichage liste indice %ls et juste un indice %d \n",position_lettre_sur,position_lettre_sur[0]);
        char* dico_IA="dico_IA";
        char* dico_IA_moins = "dico_IA_moins";

        mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
        taille = trouver_nombre_de_mots(nom_dico_longueur);
        tirage_mot(nom_dico_longueur,taille,mot_a_deviner);

        printf("mot à deviner %s \n",mot_a_deviner);
        printf("essai %d \n",compteur);
        printf("%s\n",mot_utilisateur);

        affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);
        a_gagner(mot_a_deviner,mot_utilisateur);

        copie_dico(nom_dico_longueur,dico_IA);

        for (compteur=2; compteur <=6; compteur++){
            
            recherche_lettre_mal_place(mot_a_deviner,mot_utilisateur,lettre_mal_place,pointeur_nb_lettre_mal_place);
            recherche_lettre_impossible(clavier,lettres_impossibles,pointeur_nb_lettres_impossible,lettre_sur,pointeur_nb_lettre_sur,lettre_mal_place,pointeur_nb_lettre_mal_place);
            recherche_lettre_sur(mot_a_deviner,mot_utilisateur,lettre_sur,pointeur_nb_lettre_sur,position_lettre_sur);
            
            //printf("indice lettre sur %ls \n",position_lettre_sur);
            //on enleve tous les mots avec des lettres impossibles
            
            enlever_mot_lettre_impossible(dico_IA,dico_IA_moins,lettres_impossibles,pointeur_nb_lettres_impossible);
                
            
            //on enleve tous les mots avec des lettres qui ne sont pas les bonnes lettres quand on sait qu'elles sont bien place
            for (int j=0;j<*pointeur_nb_lettre_sur;j++){
                printf("lettre sur %c et sa position %d \n",lettre_sur[j],position_lettre_sur[j]);
                enlever_mot_lettre_mal_place(dico_IA_moins,dico_IA,lettre_sur[j],position_lettre_sur[j]);
            }
            //printf("lettre impossible %s \n",lettres_impossibles);
            printf("lettre sur %s lettre mal place %s et  lettre impossible %s \n",lettre_sur,lettre_mal_place,lettres_impossibles);
            printf("essai %d \n",compteur);
            nouveau_mot(dico_IA,mot_utilisateur);           
            printf("%s \n",mot_utilisateur);
            affichage(mot_a_deviner,mot_utilisateur,dico_IA,taille,clavier);
            
            a_gagner(mot_a_deviner,mot_utilisateur);
            //if (compteur==3){exit(0);}
        }
        
        printf("Dommage, le mot était %s. \nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
        free(lettres_impossibles);
        free(lettre_sur);
        free(position_lettre_sur);
        free(lettre_mal_place);
    }


    return(0);
}