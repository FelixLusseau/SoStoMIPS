#include "quads.h"
#include <stdio.h>

extern int yyparse();
extern int yylex();
extern char *yytext;

int nb_temp = 1; // nombre de variable temporaire céer, permet d'incrémenter leurs nom à leur création
listQ *Lglobal;  // liste des quads

int main(void) {

    Lglobal = Lcreat();

    int r = yyparse();

    printf("->%d\n", r);

    return r;
}