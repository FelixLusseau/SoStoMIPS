#include "quads.h"
#include <math.h>
extern int nb_temp;

#define GC_TAILLE 2000

int I_quad = 0;
int I_quadOP = 0;
int I_liste = 0;
int I_embranchment = 0;
int I_case_test = 0;

quads *GC_quad[GC_TAILLE];
quadOP *GC_quadOP[GC_TAILLE];
listQ *GC_liste[GC_TAILLE];
embranchment *GC_embranchment[GC_TAILLE];
case_test *GC_case_test[GC_TAILLE];

int ToInt(int *i, char *str) {
    *i = atoi(str); // atoi renvoit 0 si str n'est pas un entier
    printf("ToInt: %i\n", *i);

    if (*i == 0 && str[1] == '\0' && str[0] == '0') { // cas str='0'
        return 1;
    }
    if (*i == 0) {
        return 0;
    }
    return 1;
}

/******************************** QUADOP ********************************************/

quadOP *QOcreat(int Type, char *str, int val) {
    quadOP *qo = malloc(sizeof(quadOP));

    GC_quadOP[I_quadOP] = qo;
    printf("        créer quadOP:%i", I_quadOP);
    I_quadOP++;

    qo->kind = Type;
    if (!(Type == QO_ID || Type == QO_STR || Type == QO_TAB || Type == QO_FCT)) {
        printf("  cst:%i\n", val);
        qo->u.cst = val;
    } else {
        printf("  str:%s\n", str);
        qo->u.name = strdup(str);
    }

    return qo;
}

quadOP *QOcreat_temp(void) {
    int taille = (int)((ceil(log10(nb_temp)) + 1) * sizeof(char)); // nombre de char necessaire pour écrire nb_temp
    char temp[taille + 10];
    temp[taille + 9] = '\0';

    sprintf(temp, "__TEMP__%d", nb_temp);

    quadOP *Qtemp = QOcreat(QO_ID, temp, 0);

    nb_temp++;
    return Qtemp;
}

void QOfree(quadOP *op) {
    if (op == NULL) {
        return;
    }
    if ((op->kind == QO_ID || op->kind == QO_STR || op->kind == QO_TAB)) {
        // printf("    QOfree ID/STR: %s\n", op->u.name);
        free(op->u.name);
    } else {
        // printf("    QOfree CST: %i\n", op->u.cst);
    }
    free(op);
}

void QOaffiche(quadOP *op) {
    switch (op->kind) {
    case QO_CST:
        printf("cst:%i ", op->u.cst);
        break;
    case QO_STR:
        printf("string:%s ", op->u.name);
        break;
    case QO_ID:
        printf("id:%s ", op->u.name);
        break;
    case QO_FCT:
        printf("fct:%s ", op->u.name);
        break;
    case QO_ADDR:
        printf("addr:%i ", op->u.cst);
        break;
    case QO_BOOL:
        printf("bool:%i ", op->u.cst);
        break;
    case QO_TAB:
        printf("tab:%s ", op->u.name);
        break;
    }
}

/******************************** QUADS ********************************************/

quads *Qcreat(int type, quadOP *res, quadOP *op1, quadOP *op2) {
    quads *q = malloc(sizeof(quads));

    GC_quad[I_quad] = q;
    I_quad++;

    q->op1 = op1;
    q->op2 = op2;
    q->res = res;
    q->kind = type;
    return q;
}

void Qfree(quads *q) {
    if (q == NULL) {
        return;
    }

    free(q);
}

void Qaffiche(quads *q) {

    printf(" res: ");
    if (q->res != NULL) {
        QOaffiche(q->res);
    } else {
        printf("NULL ");
    }

    switch (q->kind) {
    case Q_ADD:
        printf(" ADD ");
        break;
    case Q_LESS:
        printf(" LESS ");
        break;
    case Q_MUL:
        printf(" MUL ");
        break;
    case Q_DIV:
        printf(" DIV ");
        break;
    case Q_MOD:
        printf(" MOD ");
        break;
    case Q_CONCAT:
        printf(" CONCAT OPERANDE ");
        break;
    case Q_CONCAT_OP:
        printf(" CONCAT ");
        break;
    case Q_EQUAL:
        printf(" EQUAL ");
        break;
    case Q_GOTO:
        printf(" GOTO ");
        break;
    case Q_EXIT:
        printf(" EXIT ");
        break;
    case Q_RETURN:
        printf(" RETURN ");
        break;
    case Q_READ:
        printf(" READ ");
        break;
    case Q_ECHO:
        printf(" ECHO ");
        break;
    case Q_FCT:
        printf(" FCT: ");
        break;
    case Q_FCT_CALL:
        printf(" CALL FCT () ");
        break;
    case Q_TAB_CREAT:
        printf(" TAB[]CREAT ");
        break;
    case Q_TAB_EQUAL:
        printf(" TAB[]EQUAL ");
        break;
    case Q_TAB_GIVE:
        printf(" TAB[]GIVE ");
        break;
    case Q_IF:
        printf(" IF _ GOTO ");
        break;
    case Q_IF_EQ:
        printf(" IF == ");
        break;
    case Q_IF_NE:
        printf(" IF != ");
        break;
    case Q_IF_GT:
        printf(" IF > ");
        break;
    case Q_IF_GE:
        printf(" IF >= ");
        break;
    case Q_IF_LT:
        printf(" IF < ");
        break;
    case Q_IF_LE:
        printf(" IF <= ");
        break;
    case Q_IF_N:
        printf(" IF NOT EMPTY");
        break;
    case Q_IF_Z:
        printf(" IF EMPTY ");
        break;
    case Q_IF_NOT:
        printf(" NOT ");
        break;
    case Q_AND:
        printf(" AND ");
        break;
    case Q_OR:
        printf(" OR");
        break;
    }

    printf(" op1: ");
    if (q->op1 != NULL) {
        QOaffiche(q->op1);
    } else {
        printf("NULL ");
    }

    printf(" op2: ");
    if (q->op2 != NULL) {
        QOaffiche(q->op2);
    } else {
        printf("NULL ");
    }

    printf("\n");
}

/******************************** LISTE ********************************************/

listQ *Lcreat(void) {
    listQ *list = malloc(sizeof(listQ));
    GC_liste[I_liste] = list;
    I_liste++;

    if (list == NULL)
        return NULL;
    list->quad = NULL;
    list->next = NULL;
    list->taille = 0;
    return list;
}

listQ *Llast(listQ *list) {

    if (list->next == NULL) {
        return list;
    }

    listQ *it = list->next;
    while (it->next != NULL) {
        it = it->next;
    }
    return it;
}

void Lappend(listQ *list, quads *new_element) {
    list->taille += 1;
    if (list->quad == NULL) {
        list->quad = new_element;
        return;
    }

    listQ *new_list = Lcreat();
    new_list->quad = new_element;

    listQ *last = Llast(list);
    last->next = new_list;
}

quads *LgetQuad(listQ *list, int value_idx) {

    if (list->next == NULL) {
        return list->quad;
    }

    int index = 0;
    listQ *it = list->next;
    while (it->next != NULL && index < value_idx) {
        it = it->next;
        index += 1;
    }
    return it->quad;
}

listQ *Lconcat(listQ *list, listQ *list2) {
    listQ *last = Llast(list);
    last->next = list2;
    list->taille += list2->taille;
    return list;
}

void Lfree() {
    for (int i = 0; i <= I_quadOP; i++) {
        // printf("QOfree %i/%i", i, I_quadOP);
        QOfree(GC_quadOP[i]);
    }
    printf("\n");
    for (int j = 0; j <= I_quad; j++) {
        // printf("Qfree %i/%i\n", j, I_quad);
        Qfree(GC_quad[j]);
    }
    for (int k = 0; k <= I_liste; k++) {
        // printf("Lfree %i/%i\n", k, I_liste);
        free(GC_liste[k]);
    }
    for (int k = 0; k <= I_embranchment; k++) {
        free(GC_embranchment[k]);
    }
    for (int k = 0; k <= I_case_test; k++) {
        free(GC_case_test[k]);
    }
}

void Laffiche(listQ *list) {
    listQ *it = list;
    int i = 1;
    if (it != NULL) {
        while (it->next != NULL) {
            printf("ligne %i: ", i);
            Qaffiche(it->quad);
            it = it->next;
            i++;
        }
        if (it->quad != NULL) {
            printf("ligne %i: ", i);
            Qaffiche(it->quad);
        }
    }
}

embranchment *EMcreat(void) {
    embranchment *embr = malloc(sizeof(embranchment));
    GC_embranchment[I_embranchment] = embr;
    I_embranchment++;

    embr->False = Lcreat();
    embr->True = Lcreat();
    return embr;
}

void complete(listQ *listGT, int addresse) {
    listQ *it = listGT;

    while (it != NULL) {
        if (it->quad->kind != Q_GOTO && it->quad->kind != Q_IF) {
            printf("ERREUR COMPLETION D'UN GOTO: %i/%i/%i \n", it->quad->kind, Q_IF, Q_GOTO);
        } else if (it->quad->res == NULL) {
            quadOP *add = QOcreat(QO_ADDR, NULL, addresse);
            it->quad->res = add;
        }
        it = it->next;
    }
}

/******************************** CASE ********************************************/

case_test *CTcreat(void) {
    case_test *Case = malloc(sizeof(case_test));
    GC_case_test[I_case_test] = Case;
    I_case_test++;

    Case->branch = EMcreat();
    Case->test = Lcreat();
    return Case;
}

void CTcomplete(case_test *Case, quadOP *id_test) {
    listQ *it = Case->test;

    while (it != NULL) {
        if (it->quad->op1 == NULL) {
            it->quad->op1 = id_test;
        }
        it = it->next;
    }
}

/******************************** FOR ********************************************/

for_brnch *FBcreat(void){

    for_brnch *For = malloc(sizeof(for_brnch));

    return For;
}
