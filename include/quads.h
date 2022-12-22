#ifndef QUADS_H
#define QUADS_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>


/* vérifie que str est un entier et stocke ça valeur dans i, renvoit 1 ou 0 */
int ToInt( int *i, char * str);


/* opérande d'une instruction à 3 addresse: entier/variable/addresse goto*/
typedef struct quadOP {
    enum{QO_CST=1, // constante (int)
         QO_STR,   // chaine/mot (string)
         QO_ID,    // identificateur
         QO_ADDR,  // addresse (goto)
         QO_BOOL,  // booléens
         QO_TAB    // tableau
         }kind;
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
    enum{Q_ADD=100,   // +
         Q_LESS,      // -
         Q_CONCAT,    // concaténation
         Q_MUL,       // *
         Q_DIV,       // ./.
         Q_MOD,       // %
         Q_EQUAL,     // a = val
         Q_GOTO,      // goto addresse
         Q_EXIT,      // exit
         Q_TAB_CREAT, // créer []
         Q_TAB_EQUAL, // tab[i]=val
         Q_TAB_GIVE,  // tab[i]
         Q_IF,        // if (booléen) goto ... res=addr, op1=bool
         Q_IF_EQ,     // if equal
         Q_IF_NE,     // if not equal
         Q_IF_GT,     // if (>)
         Q_IF_GE,     // if (>=)
         Q_IF_LT,     // if (<)
         Q_IF_LE ,    // if (<=)
         Q_IF_N ,     // if CHAINE non vide
         Q_IF_Z,      // if CHAINE vide
         Q_IF_NOT,    // if !(...)
         Q_AND,       // if ... and ...
         Q_OR         // if ... or ...
         }kind;
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

quads* LgetQuad(listQ *list, int value_idx) ;

listQ * Lconcat(listQ *list, listQ *list2) ;

void Laffiche (listQ* list);

void Lfree(void);

/* renvoit le dernier node de la liste */
listQ* Llast(listQ *list);

/* brachement des if bool: contient le cas true et le cas false */
typedef struct embranchment {
    listQ *True; // goto dans le cas ou le bool=true
    listQ *False; // goto dans le cas ou le bool=false
} embranchment;

embranchment *EMcreat(void);

/* remplie les goto vide de la liste */
void complete(listQ *listGT, int addresse);

/* utilisé pour CASE ESAC: contient les test + les branchements */
typedef struct case_test {
    listQ *test;
    embranchment *branch;
} case_test;

case_test *CTcreat(void);

/* remplie les goto vide des liste et des tests */
void CTcomplete(case_test *Case, quadOP *id_test ,int addresse);

#endif