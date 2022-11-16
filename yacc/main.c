#include <stdio.h>

extern int yyparse(void);

int main(void){

    int r=yyparse();

    printf("->%d\n",r);
    
    return r;
}