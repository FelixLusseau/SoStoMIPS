#include "mips.h"

#define CHK(op)            \
    do {                   \
        if ((op) == -1)    \
            raler(1, #op); \
    } while (0)

int curr_temp_reg = 2;

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

int isTemporaryVariable(const char *varName) {
    if (varName == NULL)
        return -1;
    if ((strlen(varName) < 9))
        return -1;
    if (!strncmp(varName, "__TEMP__", 8)) {
        return atoi(varName + 8);
    }
    return -1;
}

void QuadToMips(int file, listQ *liste, char *buffer) {
    (void)file;

    int idx, idx2;

    switch (liste->quad->kind) {
    case Q_ADD:
        printf(" ADD ");
        if (liste->quad->res->kind == QO_ID && (idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            // check if op1 is temp???

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer, "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer + strlen(buffer), "addi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "add $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }

        } else {
            // if the res var is not a temporary variable
        }

        break;
    case Q_LESS:
        printf(" LESS ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer, "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer + strlen(buffer), "subi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "sub $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        } else {
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

        if (liste->quad->op1->kind == QO_CST) {
            sprintf(buffer, "li $t7, %d\n", liste->quad->op1->u.cst);
            sprintf(buffer + strlen(buffer), "sw $t7, %s\n", liste->quad->res->u.name);
        } else {
            if ((idx = isTemporaryVariable(liste->quad->op1->u.name)) < 0) {

                // load the value of in a temporary variable
                sprintf(buffer, "li $t7, %s\n", liste->quad->op1->u.name);

                if ((idx2 = isTemporaryVariable(liste->quad->res->u.name)) < 0) {

                    sprintf(buffer + strlen(buffer), "sw $t7, %s\n",
                            liste->quad->res->u.name); // flottants et entiers? à chaque fois qu'on déclare une nouvelle variable on appelle .data
                } else {

                    sprintf(buffer + strlen(buffer), "la $t7, $t%d\n", idx2 % 7);
                }
            } else {

                // assign what is in this temporary variable to the res variable:

                if ((idx2 = isTemporaryVariable(liste->quad->res->u.name)) < 0) {

                    sprintf(buffer, "sw $s%d, %s\n", (idx) % 7, liste->quad->res->u.name);
                } else
                    sprintf(buffer, "la $t%d, $t%d\n", idx % 7, idx2 % 7);
            }
        }
        break;
    case Q_GOTO:
        printf(" GOTO ");
        break;
    case Q_EXIT:
        printf(" EXIT ");
        printf("%p\n", liste->quad->res);
        sprintf(buffer, "li $a0, %d\n", (liste->quad->res) ? liste->quad->res->u.cst : 0);
        sprintf(buffer + strlen(buffer), "li $v0, 10\n");
        sprintf(buffer + strlen(buffer), "syscall\n");
        break;
    case Q_RETURN:
        printf(" RETURN ");
        break;
    case Q_READ:
        printf(" READ ");
        break;
    case Q_ECHO:
        printf(" ECHO ");
        

        break;
    case Q_FCT:
        printf(" FCT: ");
        break;
    case Q_FCT_CALL:
        printf(" CALL FCT () ");
        break;
    case Q_TAB_CREAT:
        printf(" TAB[]CREAT ");

        break;
    case Q_TAB_EQUAL:
        printf(" TAB[]EQUAL ");

        if(liste->quad->op1->kind == QO_CST)
            sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++)%7, liste->quad->op1->u.cst*4); // indice
        else {  // indice
            
            sprintf(buffer, "li $t7, 4\n");
            sprintf(buffer + strlen(buffer), "lw $t8, %s\n", liste->quad->op1->u.name); 

             
            sprintf(buffer + strlen(buffer), "mul $t%d, $t8, $t7\n", (curr_temp_reg++)%7); 

        }


        if(liste->quad->op2->kind == QO_CST)
            sprintf(buffer + strlen(buffer), "li $t%d, %d\n ",(curr_temp_reg++)%7, liste->quad->op2->u.cst); // valeur
        else
            sprintf(buffer + strlen(buffer), "lw $t%d, %s\n",(curr_temp_reg++)%7, liste->quad->op2->u.name); // valeur


        

        sprintf(buffer + strlen(buffer), "sw $t%d, %s($t%d)\n", (curr_temp_reg-1)%7,liste->quad->res->u.name, (curr_temp_reg-2)%7);

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
