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
         QO_ID,    // identificateur (string)
         QO_FCT,   // fonctions (string)
         QO_ADDR,  // addresse (goto) (int)
         QO_BOOL,  // booléens 
         QO_TAB    // tableau (string)
         }kind;
    int id_type;
    union{int cst;char *name;}u;
} quadOP;

quadOP* QOcreat(int Type, char* str,int val,int ID_type);

/* créer quadOP de type addresse, si l'adresse<0 alors elle inconnue pour l'instant */
quadOP* QOcreat_addrs(int v);

/* creer un variable temporaire pour le code 3 adresses */
quadOP * QOcreat_temp(int ID_type);

void QOaffiche(quadOP *op);

/* quad / instruction à 3 addresse*/
typedef struct quads {
    enum{Q_ADD=100,   // +
         Q_LESS,      // -
         Q_CONCAT,    // concaténation
         Q_CONCAT_OP, // concaténation d'opérande ( appel de fonction ) pas utilisé pour l'instant
         Q_MUL,       // *
         Q_DIV,       // ./.
         Q_MOD,       // %
         Q_EQUAL,     // a = val
         Q_GOTO,      // goto addresse
         Q_EXIT,      // exit
         Q_RETURN,    // return
         Q_READ,      // var = read
         Q_ECHO,      // echo tab[i] où tab=$
         Q_FCT,       // declaration fonction
         Q_FCT_CALL,  // appel de fonction
         Q_TAB_CREAT, // créer []
         Q_TAB_EQUAL, // tab[i]=val
         Q_TAB_GIVE,  // tab[i]
         Q_IF,        // if (booléen) goto ... res=addr, op1=bool
         Q_IF_EQ,     // if equal           res=bool
         Q_IF_NE,     // if not equal       res=bool
         Q_IF_GT,     // if (>)             res=bool
         Q_IF_GE,     // if (>=)            res=bool
         Q_IF_LT,     // if (<)             res=bool
         Q_IF_LE ,    // if (<=)            res=bool
         Q_IF_N ,     // if CHAINE non vide res=bool
         Q_IF_Z,      // if CHAINE vide     res=bool
         Q_IF_NOT,    // if !(...)          res=bool
         Q_AND,       // if ... and ...  inutilisé normalement
         Q_OR         // if ... or ...   inutilisé normalement
         }kind;
    quadOP *op1,*op2,*res; // res=resultat -> rarement égale à NULL, op1 et op2 les 2 opérateur de l'opérations
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

/* remplie les quadOP vide des tests */
void CTcomplete(case_test *Case, quadOP *id_test);


/* utilisé pour CFOR contient les test + les branchements */
typedef struct for_brnch {
    int addr_goback;
    quads *Max;
    quads *GoTo;
    quads *Id;
} for_brnch;

for_brnch *FBcreat(void);

/* utilisé pour CFOR contient les test + les branchements */
typedef struct lt_op {
    int taille;
    int tab;
} lt_op;

lt_op *LTOPcreat(void);




#endif