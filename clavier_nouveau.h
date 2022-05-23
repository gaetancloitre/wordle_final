#ifndef __CLAVIER_NOUVEAU_H__
#define __CLAVIER_NOUVEAU_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "clavier_nouveau.c"


char* initialisation_clavier(char* clavier) ;
//initialise la chaine de caractere associé au clavier


void affichage_clavier(char* clavier) ;
//affiche le clavier avec les lettres encore possible sur le terminal

#endif