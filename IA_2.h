#ifndef __IA_2_H__
#define __IA_2_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "IA_2.c"

void copie_dico(char* nom_dico_a_copier, char* nouveau_dico);
//permet de copier le contenu d'un fichier texte dans un autre fichier texte

void affichage_mot_fichier(char* nom_fichier);
//paffiche dans la console tous les mots d'un fichier. a ete utile pour debugger.

int verifier_lettre_deja_teste(char* liste_lettre, int taille_liste_lettre,char lettre);
//test si la lettre qu'on veut enlever n'a pas deja ete enlever

void recherche_lettre_impossible(char* clavier, char* lettres_impossible,int* nb_lettres_impossible,char* lettre_sur,int* pointeur_nb_lettre_sur,char* lettre_mal_place, int* pointeur_nb_lettre_mal_place);
//recherche dans le clavier les lettres qui sont impossibles

void recherche_lettre_sur(char* mot_a_deviner, char* mot_utilisateur, char* lettre_sur,int* pointeur_nb_lettre_sur,int* position_lettre_sur);
//recherche les lettres qui sont bien placees et les renvoie ainsi que le nombre de lettres bien placees

void enlever_mot_lettre_impossible(char* dico_5_lettres, char* dico_lettre_impossible, char* lettre_impossible, int* pointeur_nb_lettre_impossible);
//enleve tous les mots qui possèdent des lettres dont on sait qu'elles ne sont pas présente dans le mot

void enlever_mot_lettre_mal_place(char* dico_sans_lettres_impossible, char* dico_lettres_possible, char* lettre_sur, int* position_lettre_sur, int* pointeur_nb_lettre_sur);
//enlève tous les mots dont à une une position donnée du mot, le lettre présente est differente que la lettre sure à cette même position

void enlever_mot_sans_lettre_mal_place(char* dico_ancien, char* dico_nouveau, char* lettre_mal_place,int* pointeur_nb_lettre_mal_place);
//enlève tous les mots qui ne possède pas les lettres mal placées

void nouveau_mot(char* dico_lettres_possible,char* nouveau_mot);
//renvoie un mot qui pourrait convenir, de manière aléatoire

void enlever_mot(char* dico_ancien, char* dico_nouveau, char* mot_a_enlever);
//enlève un mot du fichier texte

#endif