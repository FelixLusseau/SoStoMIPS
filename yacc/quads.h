#include <stdio.h>
#include <stdlib.h>

typedef struct quadOP {
    enum{QO_CST=1,QO_NAME}kind;
    union{int cst;char *name;}u;
} quadOP;
quadOP  QOcreat_cst(int v);
quadOP  QOcreat_name(char* v);

typedef struct quads {
    enum{Q_ADD=100,Q_MUL,Q_ASS,Q_GOTO}kind;
    quadOP op1,op2,res;
    struct quads *next;
} quads;
quads * Qcreat(int type,quadOP op1, quadOP op2, quadOP res);


typedef struct listQ {
    struct quads *first;
    int taille;
}listQ;

listQ * Lcreat(void);

void Lappend(listQ *list,  quads * new_element);

quads* Lget(listQ *list, unsigned int value_idx) ;

void Lconcat(listQ *list, listQ *list2) ;

void Lfree(listQ *list);

void Qfree(quads *q);

size_t Lsize(listQ*list);

quads* Lfirst(listQ *list);

quads* Llast(listQ *list);