#include "quads.h"
#include <stdio.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
// kill -9 `ps eaux | grep ordonnanceur | tr -s ' ' | cut -d ' ' -f2`
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

extern int yyparse();
extern int yylex();
extern char *yytext;

#define CHK(op)            \
    do {                   \
        if ((op) == -1)    \
            raler(1, #op); \
    } while (0)

int nb_temp = 1; // nombre de variable temporaire céer, permet d'incrémenter leurs nom à leur création
listQ *Lglobal;  // liste des quads

int main(void) {

    Lglobal = Lcreat();

    int r = yyparse();

    printf("->%d\n", r);

    return r;
}

void mips(void){

    listQ *liste=Lglobal;

    int file = open("mips.asm", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    CHK(file);

    int N = 1000;
    char buffer[N];
    int Woctet;

    while (liste != NULL ) {
        Woctet = write(copy, &buffer, Roctet);
        CHK(Woctet);

        liste = liste->next;
    }

    close(file);
    return 0;
}

void QuadToMips(listeQ *liste, char * buffer){

    switch (liste->kind) {
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

    printf("\n");
}

}