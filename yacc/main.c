#include <stdio.h>
#include "quads.h"

extern int yyparse(void);

void testQuad(){
    listQ *L=Lcreat();
    quadOP *op1=QOcreat_cst(5);
    quadOP *op2=QOcreat_cst(7);
    quadOP *res=QOcreat_name("id");
    quads *q=Qcreat(Q_ADD,op1,op2,res);
    quads *q2=Qcreat(Q_ADD,op2,op1,res);
    Lappend(L,q);
    Lappend(L,q2);
    Laffiche(L);
    Lfree(L);
}

int main(void){

    int r=yyparse();

    printf("->%d\n",r);
    
    return r;
}