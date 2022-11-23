#ifndef QUADS_H
#define QUADS_H
#include <stdio.h>
#include <stdlib.h>

/* opérande d'une instruction à 3 addresse: entier/variable/addresse goto*/
typedef struct quadOP {
    enum{QO_CST=1,QO_NAME,QO_ADDR}kind;
    union{int cst;char *name;}u;
} quadOP;

quadOP* QOcreat_cst(int v);

quadOP* QOcreat_name(char* v);

quadOP* QOcreat_addrs(int v);

void QOaffiche(quadOP *op);

/* quad / instruction à 3 addresse*/
typedef struct quads {
    enum{Q_ADD=100,Q_MUL,Q_ASS,Q_GOTO}kind;
    quadOP *op1,*op2,*res;
    struct quads *next;
} quads;

void Qfree(quads *q);

quads * Qcreat(int type,quadOP *op1, quadOP *op2, quadOP* res);

/* liste stockant les quads */
typedef struct listQ {
    struct quads *first;
    int taille;
}listQ;

listQ * Lcreat(void);

void Lappend(listQ *list,  quads * new_element);

quads* Lget(listQ *list, unsigned int value_idx) ;

listQ * Lconcat(listQ *list, listQ *list2) ;

void Laffiche (listQ* list);

void Lfree(listQ *list);

size_t Lsize(listQ*list);

quads* Lfirst(listQ *list);

quads* Llast(listQ *list);

#endif