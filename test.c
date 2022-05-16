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
#include "IA_autre.h"



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
        char* mot_utilisateur="TARIE";
        int taille;
        int compteur=1;
        char pclavier[27];
        char* clavier = initialisation_clavier(pclavier);
        char* lettres_impossibles=malloc(27*sizeof(char));
        char* lettre_sur = malloc(LONGUEUR*sizeof(char));
        int nb_lettres_impossible=0;
        int nb_lettre_sur=0;
        int* pointeur_nb_lettres_impossible = &nb_lettres_impossible;
        int* pointeur_nb_lettre_sur = &nb_lettre_sur;
        int* position_lettre_sur =malloc(LONGUEUR*sizeof(int));
        char dico_IA[254];
        strcpy(dico_IA,nom_dico_longueur);
        char* dico_IA_moins = "dico_IA_moins";

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
            lettres_impossibles = recherche_lettre_impossible(clavier,lettres_impossibles,pointeur_nb_lettres_impossible);
            lettre_sur=recherche_lettre_sur(mot_a_deviner,mot_utilisateur,lettre_sur,pointeur_nb_lettre_sur,position_lettre_sur);

            for (int j=0;j<nb_lettres_impossible;j++) {
                enlever_mot_lettre_impossible(dico_IA,dico_IA_moins,clavier);
            }
            for (int j=0;j<nb_lettre_sur;j++){
                enlever_mot_lettre_mal_place(dico_IA_moins,dico_IA,clavier,lettre_sur[j],position_lettre_sur[j]);
            }

            mot_utilisateur=nouveau_mot(dico_IA,mot_utilisateur);           
            printf("%s",mot_utilisateur);
            affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);

            a_gagner(mot_a_deviner,mot_utilisateur);

        }

        printf("Dommage, le mot était %s. \nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
        free(lettres_impossibles);
        free(lettre_sur);
        free(position_lettre_sur);
    }


    return(0);
}