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

void mips(void) {
    printf("\n### MIPS: ###\n\n");
    listQ *liste = Lglobal;

    int file = open("mips.asm", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    CHK(file);

    int N = 1000;
    char buffer[N];
    int Woctet;
    int taille_chaine = 0;

    /*************************** Déclaration des variables ***************************************/

    taille_chaine = sprintf(buffer, ".data\n");
    Woctet = write(file, &buffer, taille_chaine);
    CHK(Woctet);

    for (unsigned int i = 0; i < HT_SIZE; i++) { // table des symboles
        if (tos[i] != NULL) {
            struct tos_entry *entry = tos[i];
            while (entry != NULL) {
                if (entry->used == 1) {
                    switch (entry->var_kind) {
                    case IDENTIFIER:
                        taille_chaine = sprintf(buffer, "%s:   .space 4\n", entry->str);
                        break;
                    case FUNCTION:
                        break;
                    case ARRAY:
                        taille_chaine = sprintf(buffer, "%s:   .space %d\n", entry->str, entry->tab_length);
                        break;
                    }

                    Woctet = write(file, &buffer, taille_chaine);
                    CHK(Woctet);
                }
                entry = entry->next_lvl[0];
            }
        }
    }

    /********************************* Traduction des quads en MIPS ****************************************/
    taille_chaine = sprintf(buffer, "\n.text\n\nmain:\n");
    Woctet = write(file, &buffer, taille_chaine);
    CHK(Woctet);

    while (liste != NULL) {

        QuadToMips(file, liste, buffer);

        Woctet = write(file, &buffer, strlen(buffer)); // ???
        CHK(Woctet);
        buffer[0] = '\0'; // ???
        liste = liste->next;
    }

    close(file);
}

/* returns a number from 0 to 7
if it is 0 that means false, otherwise
it's true and the number returned is the
index of the temporary variable
*/

int charToInt(char c) {
    int num = 0;

    num = c - '0';

    return num;
}

int isTemporaryVariable(const char * varName) {
    if(varName == NULL || strlen(varName) < 9 )
        return 0;
    if(!strncmp(varName,"__TEMP__", 8))
        return charToInt(varName[8]);
    return 0;
}

void QuadToMips(int file, listQ *liste, char *buffer) {
    (void)file;

    int idx, idx2;

    switch (liste->quad->kind) {
    case Q_ADD:
        printf(" ADD ");
        if ((idx = isTemporaryVariable(liste->quad->res->u.name))) {

            // load the op1 in a temporary variable
            sprintf(buffer, "lw $t%d, %s\n", idx + 1, liste->quad->op1->u.name);

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer + strlen(buffer), "addi $t%d, $t%d, %d\n", idx, idx + 1, liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", idx + 2, liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "add $t%d, $t%d, $t%d\n", idx, idx + 1, idx + 2);
            }
        } else {
            // if the res var is not a temporary variable
        }

        break;
    case Q_LESS:
        printf(" LESS ");

        if((idx=isTemporaryVariable(liste->quad->res->u.name))){
            
            // load the op1 in a temporary variable
            sprintf(buffer,"lw $t%d, %s\n",idx+1,liste->quad->op1->u.name);

            // concatenation
            
            if(liste->quad->op2->kind==QO_CST)
                sprintf(buffer + strlen(buffer), "subi $t%d, $t%d, %d\n",idx,idx+1,liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer),"lw $t%d, %s\n",idx+2,liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "sub $t%d, $t%d, $t%d\n",idx,idx+1,idx+2);
            }  
        }
        else {
            // if the res var is not a temporary variable
        }

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

        if (!(idx = isTemporaryVariable(liste->quad->op1->u.name))) {

            // load the value of in a temporary variable
            sprintf(buffer, "li $t7, %s\n", liste->quad->op1->u.name);

            if (!(idx2 = isTemporaryVariable(liste->quad->res->u.name))) {

                sprintf(buffer + strlen(buffer), "sw $t7, %s\n",
                        liste->quad->res->u.name); // flottants et entiers? à chaque fois qu'on déclare une nouvelle variable on appelle .data
            } else {

                sprintf(buffer, "la $t7, $t%d\n", idx2);
            }
        } else {

            // assign what is in this temporary variable to the res variable:

            if (!(idx2 = isTemporaryVariable(liste->quad->res->u.name))) {
                sprintf(buffer, "sw $t%d, %s\n", idx, liste->quad->res->u.name);
            } else
                sprintf(buffer, "la $t%d, $t%d\n", idx, idx2);
        }

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
