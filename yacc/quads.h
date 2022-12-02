#ifndef QUADS_H
#define QUADS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

/* vérifie que str est un entier et stocke ça valeur dans i */
int ToInt( int *i, char * str);


/* opérande d'une instruction à 3 addresse: entier/variable/addresse goto*/
typedef struct quadOP {
    enum{QO_CST=1,QO_STR,QO_ID,QO_ADDR,QO_BOOL}kind;
    union{int cst;char *name;}u;
} quadOP;

quadOP* QOcreat(int Type, char* str,int val);


/* créer quadOP de type addresse, si l'adresse<0 alors elle inconnue pour l'instant */
quadOP* QOcreat_addrs(int v);

/* creer un variable temporaire pour le code 3 adresses */
quadOP * QOcreat_temp(void);

void QOaffiche(quadOP *op);

/* quad / instruction à 3 addresse*/
typedef struct quads {
    enum{Q_ADD=100,Q_LESS,Q_CONCAT,Q_MUL,Q_EQUAL,Q_GOTO,Q_EXIT,Q_TAB}kind;
    quadOP *op1,*op2,*res;
} quads;

void Qfree(quads *q);

quads * Qcreat(int type, quadOP* res,quadOP *op1, quadOP *op2);

void Qaffiche(quads *q);

/* liste stockant les quads */
typedef struct listQ {
    struct listQ *next;
    struct quads *quad;
    int taille;
}listQ;

listQ * Lcreat(void);

void Lappend(listQ *list,  quads * new_element);

quads* LgetQuad(listQ *list, unsigned int value_idx) ;

listQ * Lconcat(listQ *list, listQ *list2) ;

void Laffiche (listQ* list);

void Lfree(listQ *list);


/* renvoit le dernier node de la liste */
listQ* Llast(listQ *list);

#endif