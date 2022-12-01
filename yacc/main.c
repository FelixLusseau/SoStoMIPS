#include <stdio.h>
#include "quads.h"

extern int yyparse(void);
int nb_temp=1; // nombre de variable temporaire céer, permet d'incrémenter leurs nom à leur création
listQ *Lglobal; // liste des quads

void testQuad(){
    listQ *L=Lcreat();
    listQ *L1=Lcreat();

    quadOP *op1=QOcreat_cst(5);
    quadOP *op2=QOcreat_cst(7);
    quadOP *op3=QOcreat_addrs(1);
    quadOP *res=QOcreat_str("id");

    quads *q=Qcreat(Q_ADD,op1,op2,res);
    quads *q1=Qcreat(Q_GOTO,NULL,op3,NULL);

    Lappend(L,q);
    Lappend(L1,q1);

    listQ* concat=Lconcat(L,L1);

    Laffiche(L);
    Lfree(L);
}

int main(void){
    Lglobal=Lcreat();
    
    int r=yyparse();

    printf("->%d\n",r);
    
    return r;
}