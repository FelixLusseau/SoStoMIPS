#include "mips.h"

int curr_temp_reg = 2;

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

                    CHK(Woctet = write(file, &buffer, taille_chaine));
                }
                entry = entry->next_lvl[0];
            }
        }
    }
    taille_chaine = sprintf(buffer, "buffer:   .space 100");
    CHK(Woctet = write(file, &buffer, taille_chaine));

    /********************************* Traduction des quads en MIPS ****************************************/
    taille_chaine = sprintf(buffer, "\n.text\n\nmain:\n");
    Woctet = write(file, &buffer, taille_chaine);
    CHK(Woctet);

    while (liste != NULL) {

        QuadToMips(liste, buffer); // ici aussi j'ai enlevé l'argument file

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

void QuadToMips(listQ *liste, char *buffer) {
    // (void)file; // j'ai enlevé l'argument file car je vois pas vraiment d'utilité à le passer en argument
    // on pourrait l'ajouter plus tard, corrigez moi si je me trompe

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

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer, "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer + strlen(buffer), "mul $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "mul $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        } else {
            // if the res var is not a temporary variable
        }

        break;
    case Q_DIV:
        printf(" DIV ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer, "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer + strlen(buffer), "div $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "div $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        } else {
            // if the res var is not a temporary variable
        }
        break;
    case Q_MOD:
        printf(" MOD ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {
            // load the op1 in a temporary variable
            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer, "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // load the op2 in a temporary variable
            if (liste->quad->op2->kind == QO_CST) {
                sprintf(buffer + strlen(buffer), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
            } else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
            }

            // store the division result in a temporary register
            sprintf(buffer + strlen(buffer), "div $t%d, $t%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);

            // store the remainder in the destination register
            sprintf(buffer + strlen(buffer), "mfhi $s%d\n", idx % 7);
        } else {
            // if the res var is not a temporary variable
        }

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
        sprintf(buffer, "li $v1, %d\n", (liste->quad->res) ? liste->quad->res->u.cst : 0);
        sprintf(buffer + strlen(buffer), "li $v0, 10\n");
        sprintf(buffer + strlen(buffer), "syscall\n");
        break;
    case Q_RETURN:
        printf(" RETURN ");
        // Load the return value into $v0
        if (liste->quad->res->kind == QO_CST) {
            sprintf(buffer, "li $v0, %d\n", liste->quad->res->u.cst);
        } else {
            sprintf(buffer, "lw $v0, %s\n", liste->quad->res->u.name);
        }

        /* // Jump to the end of the function
        sprintf(buffer + strlen(buffer), "j end\n"); */
        // Return from the function
        sprintf(buffer + strlen(buffer), "jr $ra\n");
        break;
    case Q_READ:
        printf(" READ ");

        // Buffer
        sprintf(buffer, "move $t%d, $a0\n", (curr_temp_reg++) % 7);
        sprintf(buffer + strlen(buffer), "li $v0, 8\n");
        sprintf(buffer + strlen(buffer), "la $a0, buffer\n");
        sprintf(buffer + strlen(buffer), "li $a1, 100\n");
        sprintf(buffer + strlen(buffer), "syscall\n");
        sprintf(buffer + strlen(buffer), "move $t%d,$a0\n", (curr_temp_reg++) % 7);

        break;
    case Q_ECHO:
        printf(" ECHO ");
        break;
    case Q_FCT:
        printf(" FCT: ");

        // Write the label of the function
        sprintf(buffer, "%s:\n", liste->quad->res->u.name);

        break;
    case Q_FCT_CALL:
        printf(" CALL FCT () ");
        // Load the arguments into the registers
        // Done by TAB[]EQUAL before the call

        // Save the registers into the stack
        sprintf(buffer, "subi $sp,$sp,%d", 10 * 4);
        sprintf(buffer + strlen(buffer), "sw $s0,0($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $s1,4($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $s2,8($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $s3,12($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $s4,16($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $s5,20($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $s6,24($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $s7,28($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $ra,32($sp)\n");
        sprintf(buffer + strlen(buffer), "sw $fp,36($sp)\n");

        // Jump to the function
        sprintf(buffer + strlen(buffer), "jal %s\n", liste->quad->res->u.name);

        // Restore the registers from the stack
        sprintf(buffer + strlen(buffer), "lw $s0,0($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $s1,4($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $s2,8($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $s3,12($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $s4,16($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $s5,20($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $s6,24($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $s7,28($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $ra,32($sp)\n");
        sprintf(buffer + strlen(buffer), "lw $fp,36($sp)\n");
        sprintf(buffer + strlen(buffer), "addi $sp,$sp,%d", 10 * 4);
        break;
    case Q_TAB_CREAT:
        printf(" TAB[]CREAT ");

        // Get the size of the array, the size is stored in the op1 field
        int size = liste->quad->op1->u.cst;

        // Calculate the total size of the array in bytes
        int total_size = size * 4; // assuming each element is 4 bytes

        // Allocate memory for the array on the heap
        sprintf(buffer, "li $a0, %d\n", total_size);
        sprintf(buffer + strlen(buffer), "li $v0, 9\n");
        sprintf(buffer + strlen(buffer), "syscall\n");

        // Store the base address of the array in the result variable
        sprintf(buffer + strlen(buffer), "sw $v0, %s\n", liste->quad->res->u.name);

        break;
    case Q_TAB_EQUAL:
        printf(" TAB[]EQUAL ");

        if (liste->quad->op1->kind == QO_CST)
            sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst * 4); // indice
        else {                                                                                    // indice

            sprintf(buffer, "li $t7, 4\n");
            sprintf(buffer + strlen(buffer), "lw $t8, %s\n", liste->quad->op1->u.name);

            sprintf(buffer + strlen(buffer), "mul $t%d, $t8, $t7\n", (curr_temp_reg++) % 7);
        }

        if (liste->quad->op2->kind == QO_CST)
            sprintf(buffer + strlen(buffer), "li $t%d, %d\n ", (curr_temp_reg++) % 7, liste->quad->op2->u.cst); // valeur
        else
            sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name); // valeur

        sprintf(buffer + strlen(buffer), "sw $t%d, %s($t%d)\n", (curr_temp_reg - 1) % 7, liste->quad->res->u.name, (curr_temp_reg - 2) % 7);

        break;
    case Q_TAB_GIVE:
        printf(" TAB[]GIVE ");

        // Load the base address of the array into a temporary register
        sprintf(buffer, "lw $t0, %s\n", liste->quad->op1->u.name);

        // Calculate the offset of the element in the array
        if (liste->quad->op2->kind == QO_CST) {
            sprintf(buffer + strlen(buffer), "li $t1, %d\n", liste->quad->op2->u.cst * 4); // assuming each element is 4 bytes
        } else {
            sprintf(buffer + strlen(buffer), "lw $t1, %s\n", liste->quad->op2->u.name);
            sprintf(buffer + strlen(buffer), "li $t2, 4\n"); // assuming each element is 4 bytes
            sprintf(buffer + strlen(buffer), "mul $t1, $t1, $t2\n");
        }

        // Add the offset to the base address to get the address of the element
        sprintf(buffer + strlen(buffer), "add $t0, $t0, $t1\n");

        // Load the value of the element into a temporary register
        sprintf(buffer + strlen(buffer), "lw $t1, 0($t0)\n");

        // Store the value in the result variable
        sprintf(buffer + strlen(buffer), "sw $t1, %s\n", liste->quad->res->u.name);
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
        // début du not
        sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
        sprintf(buffer + strlen(buffer), "xori $t%d, $t%d, 1\n", (curr_temp_reg - 1) % 7, (curr_temp_reg - 1) % 7);
        break;
    case Q_AND:
        printf(" AND ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer, "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer + strlen(buffer), "andi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "andi $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        } else {
            // if the res var is not a temporary variable
        }
        break;
    case Q_OR:
        printf(" OR");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer, "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer, "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer + strlen(buffer), "ori $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer + strlen(buffer), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer + strlen(buffer), "ori $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        } else {
            // if the res var is not a temporary variable
        }
        break;
    }

    printf("\n");
}
