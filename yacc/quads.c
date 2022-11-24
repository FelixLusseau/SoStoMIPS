#include "quads.h"
#include <math.h>
extern int nb_temp;

int ToInt( int *i, char * str){
    *i=atoi(str); // atoi renvoit 0 si str n'est pas un entier
    int isInt=1;
    if(*i==0 && str[1]=='\0' && str[0]=='0'){ // cas str='0'
        return isInt;
    }else{
        isInt=0;
    }
    return isInt;
}

/******************************** QUADOP ********************************************/
quadOP* QOcreat_cst(int v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_CST;
    qo->u.cst=v;
    return qo;
}
quadOP *QOcreat_name(char* v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_NAME;
    qo->u.name=v;
    return qo;
}
quadOP  *QOcreat_addrs(int v){
    quadOP * qo=malloc(sizeof(quadOP));
    qo->kind=QO_ADDR;
    qo->u.cst=v;
    return qo;
}

quadOP * QOcreat_temp(){
    int taille=(int)((ceil(log10(nb_temp))+1)*sizeof(char));
    char temp[taille+10];
    temp[taille+10]='\0';

    sprintf(temp,"__temp__%d",nb_temp);
    quadOP *Qtemp=QOcreat_name(temp);

    nb_temp++;
    return Qtemp;
}


void QOaffiche(quadOP *op){
    switch(op->kind){
        case QO_CST:
            printf("cst:%i ",op->u.cst);
            break;
        case QO_NAME:
            printf("name:%s ",op->u.name);
            break;
        case QO_ADDR:
            printf("addr:%i ",op->u.cst);
            break;
    }
}

/******************************** QUADS ********************************************/
quads * Qcreat(int type,quadOP* op1, quadOP* op2, quadOP *res){
    quads *q=malloc(sizeof(quads));
    q->op1=op1;
    q->op2=op2;
    q->res=res;
    q->kind=type;
    return q;
}

void Qfree(quads *q){
    if(q->op1!=NULL){
        free(q->op1);
    }
    if(q->op2!=NULL){
        free(q->op2);
    }
    if(q->res!=NULL){
        free(q->res);
    }
}


void Qaffiche(quads *q){
    switch(q->kind){
        case Q_ADD:
            printf(" ADD ");
            break;
        case Q_ASS:
            printf(" ASS ");
            break;
        case Q_GOTO:
            printf(" GOTO ");
            break;
        case Q_MUL:
            printf(" MUL ");
            break;
    }
    if(q->op1!=NULL){
        QOaffiche(q->op1);
    }
    if(q->op2!=NULL){
        QOaffiche(q->op2);
    }
    if(q->res!=NULL){
        QOaffiche(q->res);
    }
    printf("\n");
}

/******************************** LISTE ********************************************/
listQ * Lcreat(void) {
    listQ * list = malloc(sizeof(listQ));
    if(list==NULL)
        return NULL;
    list->first = NULL;
    list->taille=0;
    return list;
}

void Lappend(listQ *list, quads * new_element) {
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    new_element->next = NULL;
    list->taille+=1;

    if(list->first == NULL) {
        list->first = new_element;
        return;
    }

    quads *it = list->first;
    while(it->next != NULL) {
        it = it->next;
    }
    it->next = new_element;
}

quads* Lget(listQ *list, unsigned int value_idx) {

    quads *it = list->first;

    for(unsigned int i = 0; i < value_idx; i++) {
        it = it->next;
    }
    return it;
}

listQ * Lconcat(listQ *list, listQ *list2){
    quads *last=Llast(list);
    last->next=Lfirst(list2);
    list->taille+=list2->taille;
    free(list2);
    return list;
}

void Lfree(listQ *list) {
    if (list==NULL)
        return ;
    if (list->first==NULL){
        free(list);
        return ;
    }
    else{
        quads *noeud = list->first;
        quads *noeud2;
        while(noeud->next != NULL) {
            noeud2=noeud;
            noeud = noeud->next;
            Qfree(noeud2);
            free(noeud2);
        }
        Qfree(noeud);
        free(noeud);
        free(list);
        return ;
    }
}

size_t Lsize(listQ*list){
    return list->taille;
}

void Laffiche (listQ* list){
    quads *it = list->first;
    int i=1;
    if(it!=NULL){
        while(it->next != NULL) {
            printf("add %i: ",i);
            Qaffiche(it);
            it = it->next;
            i++;
        }
        printf("add %i: ",i);
        Qaffiche(it);
    }
}

quads* Lfirst(listQ *list){
    return Lget(list,0);
}

quads* Llast(listQ *list){
    int taille = Lsize(list);
    return Lget(list,taille-1);
}


