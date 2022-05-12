#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE -1
#define LONGUEUR 5

#include "affichage.c"

#include "dico.c"

struct clavier_t {
    char a;
    char z;
    char e;
    char r;
    char t;
    char y;
    char u;
    char i;
    char o;
    char p;
    char q;
    char s;
    char d;
    char f;
    char g;
    char h;
    char j;
    char k;
    char l;
    char m;
    char w;
    char x;
    char c;
    char v;
    char b;
    char n;
};

struct clavier_t initialisation_clavier(struct clavier_t clavier){
    //initialise le clavier avec leur valeur//
    clavier.a='a';
    clavier.z='z';
    clavier.e='e';
    clavier.r='r';
    clavier.t='t';
    clavier.y='y';
    clavier.u='u';
    clavier.i='i';
    clavier.o='o';
    clavier.p='p';
    clavier.q='q';
    clavier.s='s';
    clavier.d='d';
    clavier.f='f';
    clavier.g='g';
    clavier.h='h';
    clavier.j='j';
    clavier.k='k';
    clavier.l='l';
    clavier.m='m';
    clavier.w='w';
    clavier.x='x';
    clavier.c='c';
    clavier.v='v';
    clavier.b='b';
    clavier.n='n';

    return(clavier);
}

void affichage_clavier(struct clavier_t clavier) {
    if (clavier.a == 'a') {printf("a ");}
    if (clavier.b == 'b') {printf("b ");}
    if (clavier.c == 'c') {printf("c ");}
    if (clavier.d == 'd') {printf("d ");}
    if (clavier.e == 'e') {printf("e ");}
    if (clavier.f == 'f') {printf("f ");}
    if (clavier.g == 'g') {printf("g ");}
    if (clavier.h == 'h') {printf("h ");}
    if (clavier.i == 'i') {printf("i ");}
    if (clavier.j == 'j') {printf("j ");}
    if (clavier.k == 'k') {printf("k ");}
    if (clavier.l == 'l') {printf("l ");}
    if (clavier.m == 'm') {printf("m ");}
    if (clavier.n == 'n') {printf("n ");}
    if (clavier.o == 'o') {printf("o ");}
    if (clavier.p == 'p') {printf("p ");}
    if (clavier.q == 'q') {printf("q ");}
    if (clavier.r == 'r') {printf("r ");}
    if (clavier.s == 's') {printf("s ");}
    if (clavier.t == 't') {printf("t ");}
    if (clavier.u == 'u') {printf("u ");}
    if (clavier.v == 'v') {printf("v ");}
    if (clavier.w == 'w') {printf("w ");}
    if (clavier.x == 'x') {printf("x ");}
    if (clavier.y == 'y') {printf("y ");}
    if (clavier.z == 'z') {printf("z ");}
    printf("\n");
}