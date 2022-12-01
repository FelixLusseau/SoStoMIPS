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
    quadOP *op3=QOcreat_id("identi");
    quadOP *op4=QOcreat_temp();
    quadOP *res=QOcreat_str("hello");

    quads *q=Qcreat(Q_ADD,res,op1,op2);
    quads *q1=Qcreat(Q_GOTO,op4,op3,NULL);

    Lappend(L,q);
    Laffiche(L);
    Lappend(L1,q1);
    Laffiche(L1);

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