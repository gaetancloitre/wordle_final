#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

#define LONGUEUR 5

#include "affichage.h"
#include "clavier_nouveau.h"


/* struct etude_mot {
    char pos1;
    char pos2;
    char pos3;
    char pos4;
    char pos5;
};


struct file {
    unsigned int max_nb ; // Nombre max d ’ éléments . 
    unsigned int cur_nb ; // Nombre actuel d ’ éléments . 
    unsigned int first ; // Indice du premier élément . 
    char data ;
};

struct file file_IA {
    max_nb = 5;
    cur_nb = 1;
    first = 0;
    data = '-';
}; 


int take ( struct file *file_IA) {
    int res ;
    if (file_IA -> cur_nb == 0) {
        // File vide . 
        error () ;
    }
    res = file_IA -> data [file_IA -> first ] ;
    file_IA -> first = (file_IA -> first + 1) % file_IA -> max_nb ;
    file_IA -> cur_nb -- ;
    return ( res ) ;
}


void enqueue (struct  *file_IA , char val ) {
    if (file_IA -> cur_nb == file_IA -> max_nb ) {
    // File pleine .
    error () ;
    }
    file_IA -> data [(file_IA -> first + file_IA -> cur_nb ) % file_IA −> max_nb] = val ;
    file_IA -> cur_nb ++ ;
}


void creation_file (struct file file_IA) {
    for (int i=0; i=4; i++) {
        enqueue('-');
}







void affichage_IA (char* mot_a_deviner, char* mot_utilisateur, char* fichier, int taille) {
prend en argument le mot rentré par l'utilisateur et le mot à deviner et affiche les informartions à l'utilisateur selon si 
les lettres sont bien placées (x), présente mais au mauvais endroit (o) ou non présente dans le mot à deviner (-) 
    
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
*/ 



void creation_mot_IA(char* mot_a_deviner, char* mot_utilisateur, char* fichier, int taille,char* clavier) {
    // cette fonction crée l'IA qui permet de trouvr le prochain mot le plus optimal possible 
    
    char* mu = malloc(LONGUEUR*sizeof(char));   // tableau associé au mot_utilisateur 
    char* nmu = malloc(LONGUEUR*sizeof(char));   // tableau associé au nouveau_mot_utilisateur 

    char nouveau_mot_utilisateur[LONGUEUR+1];
    strcpy(nouveau_mot_utilisateur,mot_utilisateur);


    int cpt1=0;

    for (int j=0; j<LONGUEUR;j++){
        nmu[j]='-';
              
    }

    for (int i=0; i<LONGUEUR; i++) {
        mu[i]='-'; 
        for (int j=0; j<LONGUEUR;j++){
            if ((mot_utilisateur[i]==mot_a_deviner[j])&&(cpt1==0)&&(nmu[j]=='-')){
                if (i==j) {
                    mu[i]='x';
                    nmu[i]='x';  
                    cpt1=1;
                } 
                else {
                    mu[i]='o';
                    nmu[i]='o';   
                    cpt1=1;
                }
            }
        }
        cpt1=0;
        
    }

    int cpt2=0; 
    
    for (int i=0; i<5; i++) {
        if (mu[i] == 'x') {
            nmu[i]='x';
            nouveau_mot_utilisateur[i]=mot_utilisateur[i];
        }
    }
    //printf("Avec X %s \n", nouveau_mot_utilisateur);


    do {

        for (int i=0; i<5; i++) {
            if (mu[i]=='o') {
                for (int j=0; j<5; j++) {

                    if ((nmu[j]=='-') && (cpt2==0)) {
                        nmu[j]='o';
                        nmu[i]='-';
                        mu[i]='-';
                        nouveau_mot_utilisateur[j]=mot_utilisateur[i];
                        cpt2=1;
                    }
                }
            }
            cpt2=0;
        }

        //printf("avec X et O %s , mu :%s, nmu: %s\n", nouveau_mot_utilisateur,mu, nmu);

        
        for (int i=0; i<5; i++) {
            if (nmu[i]=='-') {
                
                do {
                nouveau_mot_utilisateur[i]=clavier[rand() % 26];  
                } while (nouveau_mot_utilisateur[i]=='0');
            }
        }

        //printf("final : %s\n", nouveau_mot_utilisateur);
        //printf("%d\n",recherche_gus(nouveau_mot_utilisateur,fichier));
    } while (recherche_gus(nouveau_mot_utilisateur,fichier) == FALSE);

    //printf("nouveau mot utilisateur test 2 %s \n",nouveau_mot_utilisateur);
    free(nmu);
    free(mu);
    
    strcpy(mot_utilisateur,nouveau_mot_utilisateur);

    
}

    

    
