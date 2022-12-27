#ifndef MIPS_H
#define MIPS_H
#include "mips.h"


#define CHK(op)            \
    do {                   \
        if ((op) == -1)    \
            raler(1, #op); \
    } while (0)

noreturn void raler(int syserr, const char *msg, ...) {
    va_list ap;

    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    fprintf(stderr, "\n");
    va_end(ap);

    if (syserr == 1)
        perror("");

    exit(EXIT_FAILURE);
}

void mips(void){

    listQ *liste=Lglobal;

    int file = open("mips.asm", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    CHK(file);

    int N = 1000;
    char buffer[N];
    int Woctet;

    /*************************** Déclaration des variables ***************************************/

    sprintf(buffer, "      .data\n");
    Woctet = write(file, &buffer, 1000);
    CHK(Woctet);
    for (unsigned int i = 0; i < HT_SIZE; i++) { // table des symboles
        if (tos[i] != NULL) {
            printf("n°%d : ", i);
            switch (tos[i]->type) {
            case IDENTIFIER:
                sprintf(buffer, "%s:   .space 4\n", tos[i]->str);
                break;
            case FUNCTION:
                printf("Function\t\t");
                break;
            case ARRAY:
                sprintf(buffer, "%s:   .space %d\n", tos[i]->str,tos[i]->tab_length);
                break;
            }

            Woctet = write(file, &buffer, N);
            CHK(Woctet);
        }
    }
    /********************************* Traduction des quads en MIPS ****************************************/
    while (liste != NULL ) {
        Woctet = write(file, &buffer, 1000);
        CHK(Woctet);

        liste = liste->next;
    }

    close(file);
}

void QuadToMips( int file ,listQ *liste ,char * buffer){

    switch (liste->quad->kind) {
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

#endif