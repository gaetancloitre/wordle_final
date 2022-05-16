#ifndef __IA_H__
#define __IA_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "IA_autre.c"

char* recherche_lettre_impossible(char* clavier, char* lettres_impossible,int* nb_lettres_impossible);
//recherche dans le clavier les lettres qui sont impossibles

char* recherche_lettre_sur(char* mot_a_deviner, char* mot_utilisateur, char* lettre_sur,int* pointeur_nb_lettre_sur,int* position_lettre_sur);
//recherche les lettres qui sont bien place et les renvoie ainsi que le nombre de lettre bien place

void enlever_mot_lettre_impossible(char* dico_5_lettres, char* dico_lettre_impossible, char* clavier);
//enleve tous les mots qui possèdent des lettres dont on sait qu'elles ne sont pas présente dans le mot

void enlever_mot_lettre_mal_place(char* dico_sans_lettres_impossible, char* dico_lettres_possible, char* clavier, char lettre_sur, int position_lettre_sur);
//enlève tous les mots dont une lettre dont on sait qu'elle est présente et bien place n'est pas bien place


char* nouveau_mot(char* dico_lettres_possible,char* nouveau_mot);
//renvoie un mot qui pourrait convenir

#endif