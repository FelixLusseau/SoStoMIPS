#include "quads.h"
#include <math.h>
extern int nb_temp;

int ToInt( int *i, char * str){
    *i=atoi(str); // atoi renvoit 0 si str n'est pas un entier
    printf("ToInt: %i\n",*i);

    if(*i==0 && str[1]=='\0' && str[0]=='0'){ // cas str='0'
        return 1;
    }
    if(*i==0){
        return 0;
    }
    return 1;
}


/******************************** QUADOP ********************************************/
quadOP* QOcreat_cst(int v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_CST;
    qo->u.cst=v;
    return qo;
}
quadOP *QOcreat_str(char* v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_STR;
    qo->u.name=v;
    return qo;
}
quadOP  *QOcreat_addrs(int v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_ADDR;
    qo->u.cst=v;
    return qo;
}
quadOP  *QOcreat_bool(int v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_BOOL;
    qo->u.cst=v;
    return qo;
}
quadOP  *QOcreat_id(char* v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_ID;
    qo->u.name=strdup(v);
    return qo;
}
quadOP* CopieID( quadOP* og){
    quadOP* newOP=og;
    if(og->kind==QO_ID){
        newOP=QOcreat_id(og->u.name);
    }
    return newOP;
}

quadOP * QOcreat_temp(void){
    int taille=(int)((ceil(log10(nb_temp))+1)*sizeof(char));// nombre de char necessaire pour écrire nb_temp
    char temp[taille+10];
    temp[taille+10]='\0';

    sprintf(temp,"__TEMP__%d",nb_temp);
    printf("temp créer:%s\n\n",temp);

    quadOP *Qtemp=QOcreat_id(temp);

    nb_temp++;
    return Qtemp;
}

void QOfree(quadOP *op){
    if(op==NULL){
        return;
    }
    if(op->kind==QO_ID  && op->u.name!=NULL){
        free(op->u.name);
    }
    free(op);
}

void QOaffiche(quadOP *op){
    switch(op->kind){
        case QO_CST:
            printf("cst:%i ",op->u.cst);
            break;
        case QO_STR:
            printf("string:%s ",op->u.name);
            break;
        case QO_ID:
            printf("id:%s ",op->u.name);
            break;
        case QO_ADDR:
            printf("addr:%i ",op->u.cst);
            break;
        case QO_BOOL:
            printf("bool:%i ",op->u.cst);
            break;
    }
}

/******************************** QUADS ********************************************/
quads * Qcreat(int type, quadOP *res,quadOP* op1, quadOP* op2){
    quads *q=malloc(sizeof(quads));
    q->op1=op1;
    q->op2=op2;
    q->res=res;
    q->kind=type;
    return q;
}

void Qfree(quads *q){
    if(q==NULL){
        return;
    }

    QOfree(q->op1);
    QOfree(q->op2);
    QOfree(q->res);

    free(q);
}


void Qaffiche(quads *q){
    if(q->res!=NULL){
        QOaffiche(q->res);
    }
    switch(q->kind){
        case Q_ADD:
            printf(" ADD ");
            break;
        case Q_LESS:
            printf(" LESS ");
            break;
        case Q_MUL:
            printf(" MUL ");
            break;
        case Q_CONCAT:
            printf(" CONCAT ");
            break;
        case Q_EQUAL:
            printf(" EQUAL ");
            break;
        case Q_GOTO:
            printf(" GOTO ");
            break;
    }
    if(q->op1!=NULL){
        QOaffiche(q->op1);
    }
    if(q->op2!=NULL){
        QOaffiche(q->op2);
    }
    printf("\n");
}

/******************************** LISTE ********************************************/
listQ * Lcreat(void) {
    listQ * list = malloc(sizeof(listQ));
    if(list==NULL)
        return NULL;
    list->quad = NULL;
    list->next=NULL;
    list->taille=0;
    return list;
}

listQ* Llast(listQ *list){
        
    if(list->next == NULL) {
        return list;
    }

    listQ *it = list->next;
    while(it->next != NULL) {
        it = it->next;
    }
    return it;
}

void Lappend(listQ *list, quads * new_element) {
    list->taille=1;
    if(list->quad==NULL){
        list->quad=new_element;
        return;
    }

    listQ *new_list=Lcreat();
    new_list->quad=new_element;

    listQ *last=Llast(list);
    last->next=new_list;
}

quads* LgetQuad(listQ *list, unsigned int value_idx) {
    if(list->next == NULL) {
        return list->quad;
    }

    listQ *it = list->next;
    while(it->next != NULL) {
        it = it->next;
    }
    return it->quad;
}

listQ * Lconcat(listQ *list, listQ *list2){
    listQ *last=Llast(list);
    last->next=list2;
    list->taille+=list2->taille;
    return list;
}

void Lfree(listQ *list) {
    if (list==NULL)
        return ;
    if (list->next==NULL){
        Qfree(list->quad);
        free(list);
        return ;
    }
    else{
        listQ *noeud = list;
        listQ *noeud2;
        while(noeud->next != NULL) {
            noeud2=noeud;
            noeud = noeud->next;
            Qfree(noeud2->quad);
            free(noeud2);
        }
        Qfree(noeud->quad);
        free(noeud);
        return ;
    }
}

void Laffiche (listQ* list){
    listQ *it = list;
    int i=1;
    if(it!=NULL){
        while(it->next != NULL) {
            printf("ligne %i: ",i);
            Qaffiche(it->quad);
            it = it->next;
            i++;
        }
        if(it->quad!=NULL){
            printf("ligne %i: ",i);
            Qaffiche(it->quad);
        }
    }
}



