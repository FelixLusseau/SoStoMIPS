#include "mips.h"

int curr_temp_reg = 2;

char *TABLE_$ = "";
char args_tab[100][100];
int args_pointer = 0;
int arg_number = 0;

int count_goto = 1;

int addr_first_instruction_else = 0;
int else_number = 0;

extern int output_file;

void mips(void) {
    printf("\n### MIPS: ###\n\n");
    listQ *liste = Lglobal;

    int file;
    if (output_file == 0) {
        CHK(file = open("mips.asm", O_WRONLY | O_CREAT | O_TRUNC, 0666));
    } else
        file = output_file;

    char buffer_text[BUFSIZ];
    char buffer_data[BUFSIZ];
    // int Woctet;
    //  int taille_chaine = 0;

    /*************************** Déclaration des variables ***************************************/

    sprintf(buffer_data, ".data\n");
    // write(file, &buffer_data, taille_chaine);
    // CHK(Woctet);

    for (unsigned int i = 0; i < HT_SIZE; i++) { // table des symboles
        if (tos[i] != NULL) {
            struct tos_entry *entry = tos[i];
            while (entry != NULL) {
                if (entry->used == 1) {
                    switch (entry->var_kind) {
                    case IDENTIFIER:
                        if (entry->type == INT)
                            sprintf(buffer_data + strlen(buffer_data), "%s:   .word 0\n", entry->str);
                        else if (entry->type == STRING && entry->string != NULL)
                            sprintf(buffer_data + strlen(buffer_data), "%s: .asciiz %s\n", entry->str, entry->string);
                        break;
                    case FUNCTION:
                        break;
                    case ARRAY:
                        sprintf(buffer_data + strlen(buffer_data), "%s:   .space %d\n", entry->str, entry->tab_length);
                        break;
                    }

                    // CHK(write(file, &buffer_text, taille_chaine));
                }
                entry = entry->next_lvl;
            }
        }
    }

    /********************************* Traduction des quads en MIPS ****************************************/
    sprintf(buffer_text, "\n.text\nmain:\n");
    // write(file, &buffer_text, taille_chaine);
    // CHK(Woctet);
    // buffer_text[0] = '\0';

    while (liste != NULL) {

        QuadToMips(liste, buffer_text, buffer_data);

        liste = liste->next;
    }
    CHK(write(file, &buffer_data, strlen(buffer_data)));
    buffer_data[0] = '\0';
    CHK(write(file, &buffer_text, strlen(buffer_text)));
    buffer_text[0] = '\0';

    for (int i = 0; i < args_pointer; i++) {
        printf("%s", args_tab[i]);
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

void QuadToMips(listQ *liste, char *buffer_text, char *buffer_data) {

    int idx, idx2;

    switch (liste->quad->kind) {
    case Q_ADD:
        printf(" ADD ");
        if (liste->quad->res->kind == QO_ID && (idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "addi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "add $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }

        break;
    case Q_LESS:
        printf(" LESS ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "subi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "sub $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }

        break;
    case Q_MUL:
        printf(" MUL ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "mul $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "mul $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }

        break;
    case Q_DIV:
        printf(" DIV ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "div $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "div $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }
        break;
    case Q_MOD:
        printf(" MOD ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {
            // load the op1 in a temporary variable
            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // load the op2 in a temporary variable
            if (liste->quad->op2->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
            }

            // store the division result in a temporary register
            sprintf(buffer_text + strlen(buffer_text), "div $t%d, $t%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);

            // store the remainder in the destination register
            sprintf(buffer_text + strlen(buffer_text), "mfhi $s%d\n", idx % 7);
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

        if (liste->quad->res->u.name && get_from_table(tos, liste->quad->res->u.name) != NULL &&
            get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
            sprintf(buffer_data + strlen(buffer_data), "%s: .asciiz %s\n", liste->quad->res->u.name, liste->quad->op1->u.name);
            break;
        }

        /* if (liste->quad->res->u.name != NULL && !strncmp(liste->quad->res->u.name, "$", 1)) {
            TABLE_$ = liste->quad->res->u.name;

            break;
        } */

        if (liste->quad->op1->kind == QO_CST)

        {
            sprintf(buffer_text + strlen(buffer_text), "li $t7, %d\n", liste->quad->op1->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "sw $t7, %s\n", liste->quad->res->u.name);
        } else {
            if ((idx = isTemporaryVariable(liste->quad->op1->u.name)) < 0) {

                // load the value of in a temporary variable
                sprintf(buffer_text + strlen(buffer_text), "li $t7, %s\n", liste->quad->op1->u.name);

                if ((idx2 = isTemporaryVariable(liste->quad->res->u.name)) < 0) {

                    sprintf(buffer_text + strlen(buffer_text), "sw $t7, %s\n",
                            liste->quad->res->u.name); // flottants et entiers? à chaque fois qu'on déclare une nouvelle variable on appelle .data
                } else {

                    sprintf(buffer_text + strlen(buffer_text), "la $t7, $t%d\n", idx2 % 7);
                }
            } else {

                // assign what is in this temporary variable to the res variable:

                if ((idx2 = isTemporaryVariable(liste->quad->res->u.name)) < 0) {

                    sprintf(buffer_text + strlen(buffer_text), "sw $s%d, %s\n", (idx) % 7, liste->quad->res->u.name);
                } else
                    sprintf(buffer_text + strlen(buffer_text), "la $t%d, $t%d\n", idx % 7, idx2 % 7);
            }
        }
        break;
    case Q_GOTO:
        printf(" GOTO ");

        if (count_goto + 1 == addr_first_instruction_else) {
            sprintf(buffer_text + strlen(buffer_text), "j EXIT%d\n", else_number);
            sprintf(buffer_text + strlen(buffer_text), "ELSE%d :\n", else_number);
        }

        if (liste->next != NULL && liste->next->quad->kind == Q_GOTO)
            sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", else_number);

        break;
    case Q_EXIT:
        printf(" EXIT ");
        sprintf(buffer_text + strlen(buffer_text), "li $v1, %d\n", (liste->quad->res) ? liste->quad->res->u.cst : 0);
        sprintf(buffer_text + strlen(buffer_text), "li $v0, 10\n");
        sprintf(buffer_text + strlen(buffer_text), "syscall\n");
        break;
    case Q_RETURN:
        printf(" RETURN ");
        // Load the return value into $v0
        if (liste->quad->res->kind == QO_CST) {
            sprintf(buffer_text + strlen(buffer_text), "li $v0, %d\n", liste->quad->res->u.cst);
        } else {
            sprintf(buffer_text + strlen(buffer_text), "lw $v0, %s\n", liste->quad->res->u.name);
        }

        // Return from the function
        sprintf(buffer_text + strlen(buffer_text), "jr $ra\n");
        break;
    case Q_READ:
        printf(" READ ");

        // Buffer_text
        // int
        /* sprintf(buffer_text + strlen(buffer_text), "li $v0, 5\n");
        sprintf(buffer_text + strlen(buffer_text), "syscall\n"); */

        // string
        sprintf(buffer_text + strlen(buffer_text), "move $t%d, $a0\n", (curr_temp_reg++) % 7);
        sprintf(buffer_text + strlen(buffer_text), "li $v0, 8\n");
        sprintf(buffer_text + strlen(buffer_text), "la $a0, buffer_text\n");
        sprintf(buffer_text + strlen(buffer_text), "li $a1, 100\n");
        sprintf(buffer_text + strlen(buffer_text), "syscall\n");
        sprintf(buffer_text + strlen(buffer_text), "move $t%d,$a0\n", (curr_temp_reg++) % 7);
        // il y a un pb dans la copie du buffer_text (manque le malloc)

        break;
    case Q_ECHO:
        printf(" ECHO ");

        /* int index = liste->quad->op1->u.cst;

        sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, index * 4 - 4);

        sprintf(buffer_text + strlen(buffer_text), "li $v0, 1\n");

        sprintf(buffer_text + strlen(buffer_text), "lw $a0, %s($t%d)\nsyscall\n", TABLE_$, curr_temp_reg - 1); */
        printf("%d----------", args_pointer);
        for (int i = 0; i < args_pointer; i++) {
            printf(" ||%s|| ", args_tab[i]);
            if (get_from_table(tos, args_tab[i]) && get_from_table(tos, args_tab[i])->type == STRING) {
                sprintf(buffer_text + strlen(buffer_text), "la $a0, %s\n", args_tab[i]);
                sprintf(buffer_text + strlen(buffer_text), "li $v0, 4\n");
                sprintf(buffer_text + strlen(buffer_text), "syscall\n");
            } else if (get_from_table(tos, args_tab[i]) && get_from_table(tos, args_tab[i])->type == INT) {
                sprintf(buffer_text + strlen(buffer_text), "lw $a0, %s\n", args_tab[i]);
                sprintf(buffer_text + strlen(buffer_text), "li $v0, 1\n");
                sprintf(buffer_text + strlen(buffer_text), "syscall\n");
            } else {
                sprintf(buffer_text + strlen(buffer_text), "la $a0, %s\n", args_tab[i]);
                sprintf(buffer_text + strlen(buffer_text), "li $v0, 4\n");
                sprintf(buffer_text + strlen(buffer_text), "syscall\n");
            }
        }
        args_pointer = 0;

        break;
    case Q_FCT:
        printf(" FCT: ");

        // Write the label of the function
        sprintf(buffer_text + strlen(buffer_text), "%s:\n", liste->quad->res->u.name);

        break;
    case Q_FCT_CALL:
        printf(" CALL FCT () ");
        // Load the arguments into the registers
        // Done by TAB[]EQUAL before the call

        // Save the registers into the stack
        sprintf(buffer_text + strlen(buffer_text), "subi $sp,$sp,%d", 10 * 4);
        sprintf(buffer_text + strlen(buffer_text), "sw $s0,0($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $s1,4($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $s2,8($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $s3,12($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $s4,16($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $s5,20($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $s6,24($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $s7,28($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $ra,32($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "sw $fp,36($sp)\n");

        // Jump to the function
        sprintf(buffer_text + strlen(buffer_text), "jal %s\n", liste->quad->res->u.name);

        // Restore the registers from the stack
        sprintf(buffer_text + strlen(buffer_text), "lw $s0,0($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $s1,4($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $s2,8($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $s3,12($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $s4,16($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $s5,20($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $s6,24($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $s7,28($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $ra,32($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "lw $fp,36($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "addi $sp,$sp,%d", 10 * 4);
        break;
    case Q_TAB_CREAT:
        printf(" TAB[]CREAT ");

        // Get the size of the array, the size is stored in the op1 field
        int size = liste->quad->op1->u.cst;

        // Calculate the total size of the array in bytes
        int total_size = size * 4; // assuming each element is 4 bytes

        // Allocate memory for the array on the heap
        sprintf(buffer_text + strlen(buffer_text), "li $a0, %d\n", total_size);
        sprintf(buffer_text + strlen(buffer_text), "li $v0, 9\n");
        sprintf(buffer_text + strlen(buffer_text), "syscall\n");

        // Store the base address of the array in the result variable
        sprintf(buffer_text + strlen(buffer_text), "sw $v0, %s\n", liste->quad->res->u.name);

        break;
    case Q_TAB_EQUAL:
        printf(" TAB[]EQUAL ");

        if (liste->quad->op2->kind == QO_STR && !strncmp(liste->quad->res->u.name, "$", 1)) {
            sprintf(args_tab[args_pointer], "str%d", arg_number);
            if (get_from_table(tos, args_tab[args_pointer]) == NULL)
                sprintf(buffer_data + strlen(buffer_data), "str%d: .asciiz %s\n", arg_number, liste->quad->op2->u.name);
            arg_number++;
            args_pointer++;
        } else if (liste->quad->op2->kind == QO_ID && !strncmp(liste->quad->res->u.name, "$", 1)) {
            sprintf(args_tab[args_pointer], "%s", liste->quad->op2->u.name);
            // printf(" %s ", args_tab[args_pointer]);
            args_pointer++;
        }

        break;
    case Q_TAB_GIVE:
        printf(" TAB[]GIVE ");

        // Load the base address of the array into a temporary register
        sprintf(buffer_text + strlen(buffer_text), "lw $t0, %s\n", liste->quad->op1->u.name);

        // Calculate the offset of the element in the array
        if (liste->quad->op2->kind == QO_CST) {
            sprintf(buffer_text + strlen(buffer_text), "li $t1, %d\n", liste->quad->op2->u.cst * 4); // assuming each element is 4 bytes
        } else {
            sprintf(buffer_text + strlen(buffer_text), "lw $t1, %s\n", liste->quad->op2->u.name);
            sprintf(buffer_text + strlen(buffer_text), "li $t2, 4\n"); // assuming each element is 4 bytes
            sprintf(buffer_text + strlen(buffer_text), "mul $t1, $t1, $t2\n");
        }

        // Add the offset to the base address to get the address of the element
        sprintf(buffer_text + strlen(buffer_text), "add $t0, $t0, $t1\n");

        // Load the value of the element into a temporary register
        sprintf(buffer_text + strlen(buffer_text), "lw $t1, 0($t0)\n");

        // Store the value in the result variable
        sprintf(buffer_text + strlen(buffer_text), "sw $t1, %s\n", liste->quad->res->u.name);
        break;
    case Q_IF:
        printf(" IF _ GOTO ");

        addr_first_instruction_else = liste->next->quad->res->u.cst;

        else_number = isTemporaryVariable(liste->quad->op1->u.name);

        sprintf(buffer_text + strlen(buffer_text), "li $t%d, 1\n", (curr_temp_reg++) % 7);

        sprintf(buffer_text + strlen(buffer_text), "bne $s%d, $t%d, ELSE%d\n", (else_number) % 7, (curr_temp_reg - 1) % 7, else_number);

        break;
    case Q_IF_EQ:
        printf(" IF == ");

        idx = isTemporaryVariable(liste->quad->res->u.name) % 7;

        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);

        sprintf(buffer_text + strlen(buffer_text), "beq $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2), (curr_temp_reg - 1), idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "j EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        break;

    case Q_IF_NE:
        printf(" IF != ");

        idx = isTemporaryVariable(liste->quad->res->u.name) % 7;

        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);

        sprintf(buffer_text + strlen(buffer_text), "bne $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2), (curr_temp_reg - 1), idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "j EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        break;
    case Q_IF_GT:
        printf(" IF > ");

        idx = isTemporaryVariable(liste->quad->res->u.name) % 7;

        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);

        sprintf(buffer_text + strlen(buffer_text), "bgt $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2), (curr_temp_reg - 1), idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "j EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        break;
    case Q_IF_GE:
        printf(" IF >= ");

        idx = isTemporaryVariable(liste->quad->res->u.name) % 7;

        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);

        sprintf(buffer_text + strlen(buffer_text), "bge $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2), (curr_temp_reg - 1), idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "j EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        break;
    case Q_IF_LT:
        printf(" IF < ");

        idx = isTemporaryVariable(liste->quad->res->u.name) % 7;

        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);

        sprintf(buffer_text + strlen(buffer_text), "blt $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2), (curr_temp_reg - 1), idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "j EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        break;
    case Q_IF_LE:
        printf(" IF <= ");

        idx = isTemporaryVariable(liste->quad->res->u.name) % 7;

        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);

        sprintf(buffer_text + strlen(buffer_text), "ble $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2), (curr_temp_reg - 1), idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "j EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

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

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "andi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "andi $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }
        break;
    case Q_OR:
        printf(" OR");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "li $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "ori $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "lw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "ori $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }
        break;
    }

    count_goto++;

    printf("\n");
}
