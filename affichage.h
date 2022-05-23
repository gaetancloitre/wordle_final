#ifndef __AFFICHAGE_H__
#define __AFFICHAGE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5

#include "affichage.c"


int recherche(char* mot_utilisateur, char* fichier, int taille, char* mot) ;
//recherche dans le dictionnaire si le mot de l'utilisateur existe ou non

int recherche_gus(char* mot_utilisateur, char* fichier);
//deuxième fonction de recherche

void affichage(char* mot_a_deviner, char* mot_utilisateur, char* fichier, int taille,char* clavier) ;
/* prend en argument le mot rentré par l'utilisateur et le mot à deviner et affiche les informartions à l'utilisateur selon si 
les lettres sont bien placées (x), présente mais au mauvais endroit (o) ou non présente dans le mot à deviner (-) */


void a_gagner(char* mot_a_deviner, char* mot_utilisateur);
//arrete le programme et renvoie felicitation au joueur si il a gagne

#endif