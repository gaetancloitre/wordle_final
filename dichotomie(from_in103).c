#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
#include "load_dic.c"

bool trouver_mot_dichotomie (char* mot, char** tableau, int debut, int fin) {
	int milieu; 
	if (debut > fin) {
		return (false) ;
	}
	while (debut<=fin) {
		milieu = (debut+fin)/2;
		test = strcmp(mot,tableau[milieu]);
		if (test<0) {
			b=milieu-1;
		}
		if (test>0) {
			a=milieu+1;
		}
		if (test==0) {
			printf("le mot est dans le dictionnaire/n");
			return true;
		}
	}
	printf("le mot n'est pas dans le dictionnaire/n");
	return false;
}


int main (int argc, char *argv[])
{
  char buffer[256] ;
  char **tableau ;
  unsigned int nb_mots = 0 ;

  if (argc != 2) {
    printf ("mauvais nombre d'arguments\n") ;
    return (1) ;
  }

  tableau = load_file (argv[1], &nb_mots) ;
  if (tableau == NULL) {
    printf ("impossible d ouvrir le dictionnaire : '%s'.\n", argv[1]) ;
    return (1) ;
  }

  printf ("nombre de mots : %d \n", nb_mots) ;

  while (gets(buffer)) {
    if (recherche(words, buffer, nb_mots)) {
    	printf ("trouvé \n") ;
    } else {
    printf ("pas trouvé\n") ;
    }
  }

  return (0) ;
}
*/