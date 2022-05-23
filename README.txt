Bienvenue dans le jeu Wordle developpé par Gaëtan Cloitre et Augustin Descourvieres.

Pour jouer, executez dans le terminal la commande suivante : "gcc -Wall -Werror -Wfatal-errors jeu.c"
puis, au moment d'executer le programme avec la commande "./a.out x", il faut donner en argument le mode de 
jeu que vous souhaitez :
-executez "./a.out 0" pour jouer à la version classique du jeu Wordle
-executez "./a.out 1" pour faire jouer l'IA developpée par Gaëtan
-executez "./a.out 2" pour faire jouer l'IA developpée par Augustin

Dans le mode de jeu classique (ie ./a.out 0), il est obligatoire de rentrer les mots lus clavier en français 
et en MAJUSCULE.
Attention, ne pas supprimer le fichier "dico_scabble.txt", car sinon, on ne peut plus construire les dictionnaires 
(ie des fichiers textes avec les mots considérés) utilisés dans nos fonctions.