#ifndef __DICO_H__
#define __DICO_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

/* lecture d'un dictionnaire francais et réecriture dans le bon format (sans accents) et avec seulement les mots de 5 lettres */

#include "dico.c"




int test_longueur(char* mot,int longueur) ;
    /*prend en argument un mot et une longueur et renvoie True si le mot fait une longueur longueur et false 
    sinon. convention :  True = +1; False = -1 */
    

void mot_de_cinq_lettres(char* fichier, char* fichier_lettre, int longueur) ;
    /*prend en argument nom du fichier associé au dictionnaire de la langue francais et le nom du fichier dans
    lequel on réecrit le dictionnaire en enlevant les mots de longueur autre que longueur. renvoie le nom du fichier
    dans lequel on ecrit le nouveau dico
    */




int trouver_nombre_de_mots(char* fichier) ;
    /* prend en argument le fichier correspondand au dictionnaire avec que les mots d'une certaine longueur, la pluspart du temps 5
    lettres et renvoie la taille de ce fichier, c'est à dire le nombre de mots*/





struct dico_en_tableau transformation_dico_tableau(char* fichier, int taille, struct dico_en_tableau t) ;
    /*prend en argument le nom du fichier associé au dictionnaire contenant que les mots d'une certaine longueur et le nombre de mots associés et
    renvoie une strcuture contenant la taille du tableau et le tableau de mots*/



void tirage_mot(char* fichier, int taille, char* mot) ;
    /* renvoie le mot à deviner par passage de pointeur en prenant en argument le nom du fichier, la taille ie le nombre de ligne, et le pointeur
    */

#endif