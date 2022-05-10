#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5

struct etude_mot {
    char pos1;
    char pos2;
    char pos3;
    char pos4;
    char pos5;
};


struct file {
    unsigned int max_nb ; /* Nombre max d ’ éléments . */
    unsigned int cur_nb ; /* Nombre actuel d ’ éléments . */
    unsigned int first ; /* Indice du premier élément . */
    char data ;
};

struct file file_IA {
    max_nb = 5;
    cur_nb = 1;
    first = 0;
    data = "-";
}; 


int take ( struct file *file_IA) {
    int res ;
    if (file_IA -> cur_nb == 0) {
        /* File vide . */
        error () ;
    }
    res = file_IA -> data [file_IA -> first ] ;
    file_IA -> first = (file_IA -> first + 1) % file_IA -> max_nb ;
    file_IA -> cur_nb -- ;
    return ( res ) ;
}


void enqueue (struct  *file_IA , char val ) {
    if (file_IA -> cur_nb == file_IA -> max_nb ) {
    /* File pleine . */
    error () ;
    }
    file_IA -> data [(file_IA -> first + file_IA -> cur_nb ) % file_IA −> max_nb] = val ;
    file_IA -> cur_nb ++ ;
}

/*
void creation_file (struct file file_IA) {
    for (int i=0; i=4; i++) {
        enqueue("-");
}
*/






void affichage_IA (char* mot_a_deviner, char* mot_utilisateur, char* fichier, int taille) {
/* prend en argument le mot rentré par l'utilisateur et le mot à deviner et affiche les informartions à l'utilisateur selon si 
les lettres sont bien placées (x), présente mais au mauvais endroit (o) ou non présente dans le mot à deviner (-) */
    
    // vérification de la longueur du mot donnée par l'utilisateur et vérification de la présence dans le dictionnaire 

    char mot[LONGUEUR];
    if (recherche(mot_utilisateur,fichier,taille,mot) == FALSE) {
           printf("le mot n'est pas dans le dictionnaire, merci d'en tenter un autre /n");
           exit(0);
       }

    int cpt=0;
    int tableau1[LONGUEUR];
    int tableau2[LONGUEUR];

    for (int j=0; j<LONGUEUR;j++){
      tableau2[j]=0;           // marquage de chaque lettre du mot à deviner
    }
    printf("test \n");
    for (int i=0; i<LONGUEUR; i++) {
         tableau1[i]=0; 
        for (int j=0; j<LONGUEUR;j++){
            if ((mot_utilisateur[i]==mot_a_deviner[j])&&(cpt==0)&&(tableau2[j]==0)){
                if (i==j) {
                    printf("x");
                    enqueue (file_IA , "x" );
                    tableau1[i]=1;  //marquage du mot utilisateur pour savoir si la lettre a été trouvée dans le mot mystère 
                    tableau2[j]=1;  //marquage du mot mystère pour savoir que la lettre a déjà été utilisée
                    cpt=1;
                } else {
                    printf("o");
                    enqueue (file_IA , "o" );
                    tableau1[i]=1;   //marquage du mot utilisateur pour savoir si la lettre a été trouvée dans le mot mystère 
                    tableau2[j]=1;  //marquage du mot mystère pour savoir que la lettre a déjà été utilisée
                    cpt=1;
                }
            }
        }
        cpt=0;    
        if (tableau1[i]==0) {
           printf("-");
           enqueue (file_IA , "-" );
        }
    }
}


char* creation_mot_IA (char* mot_a_deviner, char* mot_utilisateur, struct file file_IA) {
    char* nouveau_mot_utilisateur = mot_utilisateur;
    for (int i=0; i=5; i++) {
        if i-ème mot de la file <=> "x";
            nouveau_mot_utilisateur[i]=mot_utilisateur[i];
    for (int i=0; i=5; i++) {
        if i-ème mot de la file <=> "o";
            for (int j=0; j=5; j++) {
                if i-ème mot de la file != "o";
                    A MODIFIER nouveau_mot_utilisateur[i]=mot_utilisateur[i];
    }
}