#ifndef QUADS_H
#define QUADS_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief vérifie que str est un entier et stocke sa valeur dans i, renvoit 1 ou 0
 *
 * @param i
 * @param str
 * @return int
 */
int ToInt(int *i, char *str);

/* opérande d'une instruction à 3 addresse: entier/variable/addresse goto*/
typedef struct quadOP {
    enum {
        QO_CST = 1, // constante (int)
        QO_STR,     // chaine/mot (string)
        QO_ID,      // identificateur (string)
        QO_FCT,     // fonctions (string)
        QO_ADDR,    // addresse (goto) (int)
        QO_BOOL,    // booléens
        QO_TAB      // tableau (string)
    } kind;
    int id_type;
    union {
        int cst;
        char *name;
    } u;
} quadOP;

quadOP *QOcreat(int Type, char *str, int val, int ID_type);

/**
 * @brief créer quadOP de type addresse, si l'adresse<0 alors elle inconnue pour l'instant
 *
 * @param v
 * @return quadOP*
 */
quadOP *QOcreat_addrs(int v);

/**
 * @brief créer un variable temporaire pour le code 3 adresses
 *
 * @param ID_type
 * @return quadOP*
 */
quadOP *QOcreat_temp(int ID_type);

/**
 * @brief affiche un quadOP
 *
 * @param op
 */
void QOaffiche(quadOP *op);

/* quad / instruction à 3 addresses */
typedef struct quads {
    enum {
        Q_ADD = 100, // +
        Q_LESS,      // -
        Q_CONCAT,    // concaténation
        Q_CONCAT_OP, // concaténation d'opérande ( appel de fonction ) non utilisé pour l'instant
        Q_MUL,       // *
        Q_DIV,       // ./.
        Q_MOD,       // %
        Q_EQUAL,     // a = val
        Q_GOTO,      // goto addresse
        Q_EXIT,      // exit
        Q_RETURN,    // return
        Q_READ,      // var = read
        Q_ECHO,      // echo tab[i] où tab=$
        Q_FCT,       // déclaration fonction
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
        Q_IF_LE,     // if (<=)            res=bool
        Q_IF_N,      // if CHAINE non vide res=bool
        Q_IF_Z,      // if CHAINE vide     res=bool
        Q_IF_NOT,    // if !(...)          res=bool
        Q_AND,       // if ... and ...  inutilisé normalement
        Q_OR         // if ... or ...   inutilisé normalement
    } kind;
    quadOP *op1, *op2, *res; // res=resultat -> rarement égal à NULL, op1 et op2 les 2 opérateurs de l'opérations
} quads;

void Qfree(quads *q);

/**
 * @brief créer un quad
 *
 * @param type
 * @param res
 * @param op1
 * @param op2
 * @return quads*
 */
quads *Qcreat(int type, quadOP *res, quadOP *op1, quadOP *op2);

/**
 * @brief affiche un quad
 *
 * @param q
 */
void Qaffiche(quads *q);

/* liste stockant les quads */
typedef struct listQ {
    struct listQ *next;
    struct quads *quad;
    int taille;
} listQ;

/**
 * @brief créer une listQ
 *
 * @return listQ*
 */
listQ *Lcreat(void);

/**
 * @brief agrandit un listQ
 *
 * @param list
 * @param new_element
 */
void Lappend(listQ *list, quads *new_element);

/**
 * @brief envoie le quad n°value_idx d'une listQ
 *
 * @param list
 * @param value_idx
 * @return quads*
 */
quads *LgetQuad(listQ *list, int value_idx);

/**
 * @brief concatène 2 listQ, renvoie leur concaténation
 *
 * @param list
 * @param list2
 * @return listQ*
 */
listQ *Lconcat(listQ *list, listQ *list2);

/**
 * @brief affiche une listQ
 *
 * @param list
 */
void Laffiche(listQ *list);

/**
 * @brief libère tous les garbages collector du programme
 *
 */
void Lfree(void);

/**
 * @brief renvoie le dernier node de la liste
 *
 * @param list
 * @return listQ*
 */
listQ *Llast(listQ *list);

/**
 * @brief branchement des if bool: contient le cas true et le cas false
 *
 */
typedef struct embranchment {
    listQ *True;  // goto dans le cas où le bool=true
    listQ *False; // goto dans le cas où le bool=false
} embranchment;

/**
 * @brief créer un embranchment
 *
 */
embranchment *EMcreat(void);

/**
 * @brief remplit les goto vides de la liste
 *
 * @param listGT
 * @param addresse
 */
void complete(listQ *listGT, int addresse);

/* utilisé pour CASE ESAC: contient les test + les branchements */
typedef struct case_test {
    listQ *test;
    embranchment *branch;
} case_test;

/**
 * @brief créer un case_test
 *
 * @return case_test*
 */
case_test *CTcreat(void);

/**
 * @brief remplit les quadOP vides des tests
 *
 * @param Case
 * @param id_test
 */
void CTcomplete(case_test *Case, quadOP *id_test);

/* utilisé pour CFOR contient les tests + les branchements */
typedef struct for_brnch {
    int addr_goback;
    quads *Max;
    quads *GoTo;
    quads *Id;
} for_brnch;

/* créer un for_brnch */
for_brnch *FBcreat(void);

/* utilisé pour CFOR contient les tests + les branchements */
typedef struct lt_op {
    int taille;
    int tab;
} lt_op;

/**
 * @brief créer un lt_op
 *
 * @return lt_op*
 */
lt_op *LTOPcreat(void);

#endif