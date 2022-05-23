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
#include "IA_1.h"
#include "IA_2.h"



int main(int argc,char* argv[]) {
    srand(time(NULL));

    if (argc !=2){
        printf("problème choix mode de jeu \n");
        exit(0);
    }

    int mode=atoi(argv[1]);

    if(mode==0){
        //mode de jeu classique

        //initialisation des variables utiles à ce mode de jeu
        char mot_a_deviner[LONGUEUR+1];
        char mot_utilisateur[LONGUEUR+1];
        char* nom_dico_longueur = "dico_5.txt";
        int taille;
        int compteur;
        char pclavier[27];
        char* clavier = initialisation_clavier(pclavier);
        
        mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
        taille = trouver_nombre_de_mots(nom_dico_longueur);
        tirage_mot(nom_dico_longueur,taille,mot_a_deviner);
        
        for (compteur=6; compteur >0; compteur--){
            printf("Essais restants : %d \n",compteur);
            printf("Lettres possibles :\n");
            affichage_clavier(clavier);

            printf("Quel est le mot de %d lettres que vous souhaitez tester ? \n",LONGUEUR);
            scanf("%s",mot_utilisateur);

            affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);
            a_gagner(mot_a_deviner,mot_utilisateur);
            printf("\n");
        }
        
        printf("Dommage, le mot était %s. \nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
    }


    if (mode==1){
        //mode de jeu IA premiere solution fait par Gaetan

        //declaration des variables utiles au fonctionnement de cette IA. 
        char* nom_dico_longueur = "dico_5.txt";
        char mot_a_deviner[LONGUEUR+1];
        char mot_utilisateur[LONGUEUR+1]="TARIE";
        int taille;
        int compteur=6;
        char pclavier[27];
        char* clavier = initialisation_clavier(pclavier);

        mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
        taille = trouver_nombre_de_mots(nom_dico_longueur);
        tirage_mot(nom_dico_longueur,taille,mot_a_deviner);

        printf("Essais restants : %d \n",compteur);

        printf("Mot proposé par l'IA : \n");
        printf("%s\n",mot_utilisateur);

        affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);
        a_gagner(mot_a_deviner,mot_utilisateur);
        printf("\n");

        for (compteur=5; compteur>0; compteur--){
            printf("Essais restants : %d \n",compteur);

            printf("Mot proposé par l'IA : \n");
            creation_mot_IA(mot_a_deviner, mot_utilisateur, nom_dico_longueur, taille,clavier); 
            printf("%s\n",mot_utilisateur);

            affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);
            a_gagner(mot_a_deviner,mot_utilisateur);
            printf("\n");

        }

        printf("Dommage, le mot était %s. L'ordinateur n'a pas été meilleur que l'humain... Ouf !\nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
    }

    if (mode==2) {
        //mode de jeu IA deuxième solution

        //initialisation des variables utiles au focntionnement de cette IA
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
        char* dico_IA_debut ="dico_IA_debut.txt";
        char* dico_IA_final ="dico_IA_final.txt";
        char* dico_IA_intermediaire = "dico_IA_intermediaire.txt";
        char* dico_IA_intermediaire_2 ="dico_IA_intermediaire_2.txt";

        mot_de_cinq_lettres("dico_scrabble.txt",nom_dico_longueur,LONGUEUR);
        taille = trouver_nombre_de_mots(nom_dico_longueur);
        tirage_mot(nom_dico_longueur,taille,mot_a_deviner);

        //char mot_a_deviner[LONGUEUR+1] ="CIREE";
        //printf("mot à deviner %s \n",mot_a_deviner);
        printf("Essais restants : %d \n",compteur);
        printf("Mot proposé par l'IA :\n%s\n",mot_utilisateur);

        affichage(mot_a_deviner,mot_utilisateur,nom_dico_longueur,taille,clavier);
        a_gagner(mot_a_deviner,mot_utilisateur);
        printf("\n");
        enlever_mot(nom_dico_longueur,dico_IA_debut,mot_utilisateur);        

        for (compteur=5; compteur >0; compteur--){
            
            recherche_lettre_mal_place(mot_a_deviner,mot_utilisateur,lettre_mal_place,pointeur_nb_lettre_mal_place);
            recherche_lettre_impossible(clavier,lettres_impossibles,pointeur_nb_lettres_impossible,lettre_sur,pointeur_nb_lettre_sur,lettre_mal_place,pointeur_nb_lettre_mal_place);
            recherche_lettre_sur(mot_a_deviner,mot_utilisateur,lettre_sur,pointeur_nb_lettre_sur,position_lettre_sur);
            
            //printf("indice lettre sur %ls \n",position_lettre_sur);
            //on enleve tous les mots avec des lettres impossibles
            
            enlever_mot_lettre_impossible(dico_IA_debut,dico_IA_intermediaire,lettres_impossibles,pointeur_nb_lettres_impossible);
                
           
            //on enleve tous les mots avec des lettres qui ne sont pas les bonnes lettres quand on sait qu'elles sont bien place
            //FILE* f4=fopen(dico_IA_final,"w");
            //fclose(f4);
            enlever_mot_lettre_mal_place(dico_IA_intermediaire,dico_IA_intermediaire_2,lettre_sur,position_lettre_sur,pointeur_nb_lettre_sur);
            
            enlever_mot_sans_lettre_mal_place(dico_IA_intermediaire_2,dico_IA_final,lettre_mal_place,pointeur_nb_lettre_mal_place);
            //printf("affichage contenu dico final sortie de fonction \n");
            //affichage_mot_fichier(dico_IA_final);
            /*
            for (int i=0;i<*pointeur_nb_lettre_sur;i++){
                printf("%d %c ,",position_lettre_sur[i],lettre_sur[i]);
            }
            printf("\n");
            */
            
            //printf("lettre impossible %s \n",lettres_impossibles);
            //printf("lettre sur %s lettre mal place %s et  lettre impossible %s \n",lettre_sur,lettre_mal_place,lettres_impossibles);
            printf("Essais restants : %d \n",compteur);

            nouveau_mot(dico_IA_final,mot_utilisateur);           
            printf("Mot proposé par l'IA : \n%s \n",mot_utilisateur);

            affichage(mot_a_deviner,mot_utilisateur,dico_IA_final,taille,clavier);
            a_gagner(mot_a_deviner,mot_utilisateur);
            printf("\n");
            enlever_mot(dico_IA_final,dico_IA_debut,mot_utilisateur);
            
            //if (compteur==3){exit(0);}
        }
        
        printf("Dommage, le mot était %s. L'ordinateur n'a peut être juste pas eu de chance...\nRelance le programme si tu veux rejouer. \n",mot_a_deviner);
        free(lettres_impossibles);
        free(lettre_sur);
        free(position_lettre_sur);
        free(lettre_mal_place);
    }


    return(0);
}