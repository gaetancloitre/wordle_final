#ifndef __IA_H__
#define __IA_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5

#include "IA.c"

char* creation_mot_IA(char* mot_a_deviner, char* mot_utilisateur, char* fichier, int taille,char* clavier);
    // cette fonction crée l'IA qui permet de trouvr le prochain mot le plus optimal possible 

#endif

    
    