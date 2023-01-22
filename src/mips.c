#include "mips.h"

int curr_temp_reg = 2;

char *TABLE_$ = "";
char args_tab[100][100];
int args_pointer = 0;
int arg_number = 0;

int count_goto = 1;

liste_else *list_of_else;

extern int output_file;
int function = 0;

void mips(void) {

    list_of_else = malloc(sizeof(liste_else));

    list_of_else->number_of_else = 0;
    for (int i = 0; i < 5000; i++) {
        list_of_else->else_number[i] = -1;
        list_of_else->addr_first_instruction_else[i] = -1;
    }

    printf("\n### MIPS: ###\n\n");
    listQ *liste = Lglobal;

    int file;
    if (output_file == 0) {
        CHK(file = open("mips.asm", O_WRONLY | O_CREAT | O_TRUNC, 0666));
    } else
        file = output_file;

    char buffer_text[BUFSIZ];
    char buffer_data[BUFSIZ];
    char buffer_function[BUFSIZ];
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
                            sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", entry->str);
                        else if (entry->type == STRING && entry->string != NULL)
                            sprintf(buffer_data + strlen(buffer_data), "%s:\t.asciiz\t%s\n", entry->str, entry->string);
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

        if (liste->quad->kind == Q_FCT || function == 1)
            QuadToMips(liste, buffer_function, buffer_data);
        else
            QuadToMips(liste, buffer_text, buffer_data);

        liste = liste->next;
    }
    CHK(write(file, &buffer_data, strlen(buffer_data)));
    buffer_data[0] = '\0';
    CHK(write(file, &buffer_text, strlen(buffer_text)));
    buffer_text[0] = '\0';
    CHK(write(file, &buffer_function, strlen(buffer_function)));
    buffer_function[0] = '\0';

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
/*
int isNumber(char* s)
{
    for (int i = 0; s[i]!= '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
              return 0;
    }
    return 1;
}*/

int isAnum(char *Char) {
    int len = strlen(Char);
    if (len < 3)
        return 0;
    if (Char[0] != '\"' || Char[len - 1] != '\"')
        return 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(Char[i]))
            return 0;
    }
    return 1;
}

int convert_string_to_int(char *str) {
    int len = strlen(str);

    char *temp = malloc(len - 1);
    for (int i = 0; i < len - 2; i++) {
        temp[i] = str[i + 1];
    }
    temp[len - 1] = '\0';
    int res = atoi(temp);
    free(temp);
    return res;
}

void QuadToMips(listQ *liste, char *buffer_text, char *buffer_data) {

    int idx, idx2;

    if (liste->next != NULL)
        sprintf(buffer_text + strlen(buffer_text), "LABEL%d : \n", count_goto);

    switch (liste->quad->kind) {
    case Q_ADD:
        printf(" ADD ");
        if (liste->quad->res->kind == QO_ID && (idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\taddi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
                sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, %s\n", idx % 7, liste->quad->res->u.name);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "\tadd $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }

        break;
    case Q_LESS:
        printf(" LESS ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {

                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "\tsub $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "\tsub $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }

        break;
    case Q_MUL:
        printf(" MUL ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
            } else {
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tmul $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
                sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, %s\n", idx % 7, liste->quad->res->u.name);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "\tmul $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
                sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, %s\n", idx % 7, liste->quad->res->u.name);
            }
        }

        break;
    case Q_DIV:
        printf(" DIV ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tdiv $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
                sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, %s\n", idx % 7, liste->quad->res->u.name);
            }

            else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "\tdiv $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
                sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, %s\n", idx % 7, liste->quad->res->u.name);
            }
        }
        break;
    case Q_MOD:
        printf(" MOD ");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {
            // load the op1 in a temporary variable
            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
                sprintf(buffer_data + strlen(buffer_data), "%s:  \t.word\t0\n", liste->quad->res->u.name);
            }

            // load the op2 in a temporary variable
            if (liste->quad->op2->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
            }

            // store the division result in a temporary register
            sprintf(buffer_text + strlen(buffer_text), "\tdiv $t%d, $t%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);

            // store the remainder in the destination register
            sprintf(buffer_text + strlen(buffer_text), "\tmfhi $s%d\n", idx % 7);
            sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, %s\n", idx % 7, liste->quad->res->u.name);
        }

        break;

    case Q_CONCAT:
        printf(" CONCAT OPERANDE ");
        char temp[100];
        memset(temp, 0, 100);
        // printf("type : %d\n", liste->quad->op1->kind);
        if (liste->quad->op1 && get_from_table(tos, liste->quad->op1->u.name) != NULL &&
            get_from_table(tos, liste->quad->op1->u.name)->type == STRING && get_from_table(tos, liste->quad->op1->u.name)->string != NULL) {
            sprintf(temp, "%s", get_from_table(tos, liste->quad->op1->u.name)->string);
            temp[strlen(temp) - 2] = '\0';
        } else if (liste->quad->op1 && get_from_table(tos, liste->quad->op1->u.name) != NULL &&
                   get_from_table(tos, liste->quad->op1->u.name)->type == STRING && get_from_table(tos, liste->quad->op1->u.name)->string == NULL) {
            sprintf(temp, "%s", strstr(buffer_data, liste->quad->op1->u.name) + strlen(liste->quad->op1->u.name) + 12);
            temp[strlen(temp) - 2] = '\0';
        } else if (liste->quad->op1 && liste->quad->op1->kind == QO_STR) {
            // printf("cc");
            sprintf(temp, "%s", liste->quad->op1->u.name);
            temp[strlen(temp) - 2] = '\0';
        } else if (liste->quad->op1 && liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '_' && liste->quad->op1->u.name[1] == '_') {
            // printf("cc");
            sprintf(temp, "%s", strstr(buffer_data, liste->quad->op1->u.name) + strlen(liste->quad->op1->u.name) + 12);
            temp[strlen(temp) - 2] = '\0';
        }
        // printf("temp: %s\n", temp);
        //  strcat(temp, "cccccc");
        if (liste->quad->op2 && get_from_table(tos, liste->quad->op2->u.name) != NULL &&
            get_from_table(tos, liste->quad->op2->u.name)->type == STRING) {
            printf("table: %s", &get_from_table(tos, liste->quad->op2->u.name)->string[1]);
            strcat(temp, &get_from_table(tos, liste->quad->op2->u.name)->string[1]);
        } else if (liste->quad->op2 && liste->quad->op2->kind == QO_STR) {
            printf("pastable: %s", &liste->quad->op2->u.name[1]);
            strcat(temp, &liste->quad->op2->u.name[1]);
        } else if (liste->quad->op1 && liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '_' && liste->quad->op1->u.name[1] == '_') {
            strcat(temp, strstr(buffer_data, liste->quad->op1->u.name) + strlen(liste->quad->op1->u.name) + 12 + 1);
        }
        // printf("tempfin: %s\n", temp);
        sprintf(buffer_data + strlen(buffer_data), "%s:  \t.asciiz\t%s\n", liste->quad->res->u.name, temp);
        break;
    case Q_CONCAT_OP:
        printf(" CONCAT ");
        break;
    case Q_EQUAL:
        printf(" EQUAL ");

        if (liste->quad->res->u.name && get_from_table(tos, liste->quad->res->u.name) != NULL &&
            get_from_table(tos, liste->quad->res->u.name)->type == STRING && liste->quad->op1->u.name[0] != '_' &&
            liste->quad->op1->u.name[1] != '_') {
            sprintf(buffer_data + strlen(buffer_data), "%s:  \t.asciiz\t%s\n", liste->quad->res->u.name, liste->quad->op1->u.name);
            break;
        } else if (liste->quad->res->u.name && get_from_table(tos, liste->quad->res->u.name) != NULL &&
                   get_from_table(tos, liste->quad->res->u.name)->type == STRING && liste->quad->op1->u.name[0] == '_' &&
                   liste->quad->op1->u.name[1] == '_') {
            char temp2[100];
            memset(temp2, 0, 100);
            sprintf(temp2, "%s", strstr(buffer_data, liste->quad->op1->u.name) + strlen(liste->quad->op1->u.name) + 12);
            sprintf(buffer_data + strlen(buffer_data), "%s:  \t.asciiz\t%s\n", liste->quad->res->u.name, temp2);
            break;
        }

        if (liste->quad->op1->kind == QO_CST) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t7, %d\n", liste->quad->op1->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "\tsw $t7, %s\n", liste->quad->res->u.name);
        } else if (liste->quad->op1->kind == QO_STR && liste->quad->op1->u.name[0] == '"') {
            int digit = 1;
            // printf("\033[46mcc\033[0m");
            for (size_t i = 1; i < strlen(liste->quad->op1->u.name) - 1; i++) {
                if (!isdigit(liste->quad->op1->u.name[i]))
                    digit = 0;
            }
            if (digit) {
                char tmp[100];
                strcpy(tmp, &liste->quad->op1->u.name[1]);
                tmp[strlen(tmp) - 1] = '\0';
                sprintf(buffer_text + strlen(buffer_text), "\tli $t7, %s\n", tmp);
                sprintf(buffer_text + strlen(buffer_text), "\tsw $t7, %s\n", liste->quad->res->u.name);
            }
        } else if (liste->quad->op1->kind == QO_ID) {
            // printf("\033[46mcc\033[0m");
            // printf("%c\n", liste->quad->op1->u.name[1]);
            if (liste->quad->res->u.name && get_from_table(tos, liste->quad->res->u.name) &&
                get_from_table(tos, liste->quad->res->u.name)->type == INT) {
                if (liste->quad->op1->u.name[0] == '$') {
                    // printf("\033[45mcc2\033[0m");
                    sprintf(buffer_text + strlen(buffer_text), "\tsw $a%c, %s\n", liste->quad->op1->u.name[1] - 1, liste->quad->res->u.name);
                } else {
                    sprintf(buffer_text + strlen(buffer_text), "\tlw $t7, %s\n", liste->quad->op1->u.name);
                    sprintf(buffer_text + strlen(buffer_text), "\tsw $t7, %s\n", liste->quad->res->u.name);
                }
            }
            // Et pour un string ?
        } else {
            if ((idx = isTemporaryVariable(liste->quad->op1->u.name)) < 0) {

                // load the value of in a temporary variable
                sprintf(buffer_text + strlen(buffer_text), "\tli $t7, %s\n", liste->quad->op1->u.name);

                if ((idx2 = isTemporaryVariable(liste->quad->res->u.name)) < 0) {

                    sprintf(buffer_text + strlen(buffer_text), "\tsw $t7, %s\n",
                            liste->quad->res->u.name); // flottants et entiers? à chaque fois qu'on déclare une nouvelle variable on appelle .data
                } else {

                    sprintf(buffer_text + strlen(buffer_text), "\tla $t7, $t%d\n", idx2 % 7);
                }
            } else {

                // assign what is in this temporary variable to the res variable:

                if ((idx2 = isTemporaryVariable(liste->quad->res->u.name)) < 0) {

                    sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, %s\n", (idx) % 7, liste->quad->res->u.name);
                } else
                    sprintf(buffer_text + strlen(buffer_text), "\tla $t%d, $t%d\n", idx % 7, idx2 % 7);
            }
        }
        break;
    case Q_GOTO:
        printf(" GOTO ");

        // sprintf(buffer_text + strlen(buffer_text),"%d : \n", count_goto);

        int indx = list_of_else->number_of_else - 1;

        int addr_first_instruction_else = list_of_else->addr_first_instruction_else[indx];
        int else_number = list_of_else->else_number[indx];

        // printf("FAIL : %d %d",count_goto + 1,addr_first_instruction_else);

        if (count_goto + 1 == addr_first_instruction_else) {
            sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", else_number);
            // sprintf(buffer_text + strlen(buffer_text), "ELSE%d : j LABEL%d\n", else_number, addr_first_instruction_else);
        }

        if (liste->next != NULL && liste->next->quad->kind == Q_GOTO) {

            if (list_of_else->else_number[indx] != -1)
                sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", list_of_else->else_number[indx]);

            list_of_else->addr_first_instruction_else[indx] = -1;
            list_of_else->else_number[indx] = -1;
            list_of_else->number_of_else--;
        }
        // si on doit remonter
        if (count_goto > liste->quad->res->u.cst)
            sprintf(buffer_text + strlen(buffer_text), "\tj addr%d\n", liste->quad->res->u.cst);

        break;
    case Q_EXIT:
        printf(" EXIT ");
        sprintf(buffer_text + strlen(buffer_text), "\tli $v1, %d\n", (liste->quad->res) ? liste->quad->res->u.cst : 0);
        sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 10\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
        break;
    case Q_RETURN:
        printf(" RETURN ");
        // Load the return value into $v0
        /* if (liste->quad->res->kind == QO_CST) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $v0, %d\n", liste->quad->res->u.cst);
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $v0, %s\n", liste->quad->res->u.name);
        } */
        // Return value
        if (liste->quad->res && liste->quad->res->kind == QO_STR && liste->quad->res->u.name) {
            sprintf(buffer_text + strlen(buffer_text), "\tla $a0, %s\n", liste->quad->res->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 4\n");
            sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
        } else if (liste->quad->res && liste->quad->res->kind == QO_CST && liste->quad->res->u.cst) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $a0, %d\n", liste->quad->res->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 1\n");
            sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
        } /* else {
            sprintf(buffer_text + strlen(buffer_text), "\tla $a0, %s\n", liste->quad->res->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 4\n");
            sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
        } */

        // Return from the function
        sprintf(buffer_text + strlen(buffer_text), "\tjr $ra\n");
        function = 0;
        break;
    case Q_READ:
        printf(" READ ");

        // Buffer
        // int
        if (liste->quad->res->u.name && get_from_table(tos, liste->quad->res->u.name) != NULL &&
            get_from_table(tos, liste->quad->res->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 5\n");
            sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
            sprintf(buffer_text + strlen(buffer_text), "\tsw $v0, %s\n", liste->quad->res->u.name);
        }

        // string
        /* else if (liste->quad->res->u.name && get_from_table(tos, liste->quad->res->u.name) != NULL &&
                 get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a0\n", (curr_temp_reg++) % 7);
            sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 8\n");
            sprintf(buffer_text + strlen(buffer_text), "\tla $a0, buffer_text\n");
            sprintf(buffer_text + strlen(buffer_text), "\tli $a1, 100\n");
            sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d,$a0\n", (curr_temp_reg++) % 7);
        } */
        // il y a un pb dans la copie du buffer_text (manque le malloc)

        break;
    case Q_ECHO:
        printf(" ECHO ");

        /* int index = liste->quad->op1->u.cst;

        sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, index * 4 - 4);

        sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 1\n");

        sprintf(buffer_text + strlen(buffer_text), "\tlw $a0, %s($t%d)\nsyscall\n", TABLE_$, curr_temp_reg - 1); */
        // printf("%d----------", args_pointer);
        for (int i = 0; i < args_pointer; i++) {
            // printf(" ||%s|| ", args_tab[i]);
            if (get_from_table(tos, args_tab[i]) && get_from_table(tos, args_tab[i])->type == STRING) {
                sprintf(buffer_text + strlen(buffer_text), "\tla $a0, %s\n", args_tab[i]);
                sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 4\n");
                sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
            } else if (get_from_table(tos, args_tab[i]) && get_from_table(tos, args_tab[i])->type == INT) {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $a0, %s\n", args_tab[i]);
                sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 1\n");
                sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tla $a0, %s\n", args_tab[i]);
                sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 4\n");
                sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");
            }
        }
        args_pointer = 0;

        break;
    case Q_FCT:
        printf(" FCT: ");

        function = 1;
        // Write the label of the function
        sprintf(buffer_text + strlen(buffer_text), "%s:\n", liste->quad->res->u.name);

        break;
    case Q_FCT_CALL:
        printf(" CALL FCT () ");
        // Load the arguments into the registers
        for (int k = 0; k < get_from_table(tos, liste->quad->res->u.name)->fn_args_counter; k++) {
            if (get_from_table(tos, liste->quad->res->u.name)->type == INT) {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $a%d, %s\n", k, args_tab[args_pointer - 1]);
            } else if (get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
                if (liste->quad->res->u.name[0] == '"' || liste->quad->res->u.name[0] == '\'')
                    sprintf(buffer_text + strlen(buffer_text), "\tla $a%d, %s\n", k, args_tab[args_pointer - 1]);
                else
                    sprintf(buffer_text + strlen(buffer_text), "\tli $a%d, %s\n", k, args_tab[args_pointer - 1]);
                printf("\033[47mccfct\033[0m %s", args_tab[args_pointer - 1]);
            }
            args_pointer--;
        }

        // Save the registers into the stack
        sprintf(buffer_text + strlen(buffer_text), "\taddi $t9, $zero,%d\n", 10 * 4);
        sprintf(buffer_text + strlen(buffer_text), "\tsub $sp,$sp,$t9\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s0,0($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s1,4($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s2,8($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s3,12($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s4,16($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s5,20($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s6,24($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $s7,28($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $ra,32($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsw $fp,36($sp)\n");

        // Jump to the function
        sprintf(buffer_text + strlen(buffer_text), "\tjal %s\n", liste->quad->res->u.name);

        // Restore the registers from the stack
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s0,0($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s1,4($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s2,8($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s3,12($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s4,16($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s5,20($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s6,24($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $s7,28($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $ra,32($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\tlw $fp,36($sp)\n");
        sprintf(buffer_text + strlen(buffer_text), "\taddi $sp,$sp,%d\n", 10 * 4);
        break;
    case Q_TAB_CREAT:
        printf(" TAB[]CREAT ");

        // Get the size of the array, the size is stored in the op1 field
        int size = liste->quad->op1->u.cst;

        // Calculate the total size of the array in bytes
        int total_size = size * 4; // assuming each element is 4 bytes

        // Allocate memory for the array on the heap
        sprintf(buffer_text + strlen(buffer_text), "\tli $a0, %d\n", total_size);
        sprintf(buffer_text + strlen(buffer_text), "\tli $v0, 9\n");
        sprintf(buffer_text + strlen(buffer_text), "\tsyscall\n");

        // Store the base address of the array in the result variable
        sprintf(buffer_text + strlen(buffer_text), "\tsw $v0, %s\n", liste->quad->res->u.name);

        break;
    case Q_TAB_EQUAL:
        printf(" TAB[]EQUAL ");

        if (liste->quad->op2->kind == QO_STR && !strncmp(liste->quad->res->u.name, "$", 1)) {
            /* for (size_t k = 0; k < strlen(liste->quad->op2->u.name); k++) {
                if (!isdigit(liste->quad->op2->u.name[k]))
            } */
            if (liste->quad->op2->u.name[0] != '"' && liste->quad->op2->u.name[0] != '\'') {
                sprintf(args_tab[args_pointer], "%s", liste->quad->op2->u.name);
                printf("\033[46mcc\033[0m");
                printf(" %s ", args_tab[args_pointer]);
            } else {
                sprintf(args_tab[args_pointer], "str%d", arg_number);
                if (get_from_table(tos, args_tab[args_pointer]) == NULL) {
                    // if (!isdigit(args_tab[args_pointer][0]))
                    sprintf(buffer_data + strlen(buffer_data), "str%d:  \t.asciiz\t%s\n", arg_number, liste->quad->op2->u.name);
                }
            }
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
        sprintf(buffer_text + strlen(buffer_text), "\tlw $t0, %s\n", liste->quad->op1->u.name);

        // Calculate the offset of the element in the array
        if (liste->quad->op2->kind == QO_CST) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t1, %d\n", liste->quad->op2->u.cst * 4); // assuming each element is 4 bytes
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t1, %s\n", liste->quad->op2->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tli $t2, 4\n"); // assuming each element is 4 bytes
            sprintf(buffer_text + strlen(buffer_text), "\tmul $t1, $t1, $t2\n");
        }

        // Add the offset to the base address to get the address of the element
        sprintf(buffer_text + strlen(buffer_text), "\tadd $t0, $t0, $t1\n");

        // Load the value of the element into a temporary register
        sprintf(buffer_text + strlen(buffer_text), "\tlw $t1, 0($t0)\n");

        // Store the value in the result variable
        sprintf(buffer_text + strlen(buffer_text), "\tsw $t1, %s\n", liste->quad->res->u.name);
        break;
    case Q_IF:
        printf(" IF _ GOTO ");

        int ind = list_of_else->number_of_else;

        // printf("INNNDD : %d\n",ind);

        if (liste->next != NULL && liste->next->quad->res->u.cst > count_goto + 2) {

            list_of_else->number_of_else++;

            list_of_else->addr_first_instruction_else[ind] = liste->next->quad->res->u.cst;
        }

        // printf("addr_first_instruction_else : %d\n",list_of_else->addr_first_instruction_else[ind]);

        list_of_else->else_number[ind] = isTemporaryVariable(liste->quad->op1->u.name);

        sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, 1\n", (curr_temp_reg++) % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tbne $s%d, $t%d, LABEL%d\n", (list_of_else->else_number[ind]) % 7, (curr_temp_reg - 1) % 7,
                liste->next->quad->res->u.cst);

        sprintf(buffer_text + strlen(buffer_text), "\tj LABEL%d\n", liste->quad->res->u.cst);

        break;
    case Q_IF_EQ:
        printf(" IF == ");

        idx = isTemporaryVariable(liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "addr%d : \n", count_goto);

        /*if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
        }*/

        if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == STRING) {
            /* sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, str%d\n", (curr_temp_reg++) % 7, arg_number);
            arg_number++; */
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name[1] - 1);
        } else if (liste->quad->op1->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op1->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        }

        if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_ID && liste->quad->op2->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op2->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op2->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else if (!get_from_table(tos, liste->quad->op2->u.name) && (liste->quad->op2->u.name[0] == '"' || liste->quad->op2->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, str%d\n", (curr_temp_reg++) % 7, arg_number);
            arg_number++;
            // printf("\033[45mcc %d\033[0m", arg_number);
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        }

        sprintf(buffer_data + strlen(buffer_data), "%s:   .word 0\n", liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "\tbeq $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7, idx + 3000);

        // sprintf(buffer_text + strlen(buffer_text),"LABEL%d\n",liste->next->quad->res->u.cst);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        /*sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);*/

        break;

    case Q_IF_NE:
        printf(" IF != ");

        idx = isTemporaryVariable(liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "addr%d : \n", count_goto);

        /*if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
        }*/

        if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op1->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op1->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        }

        if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_ID && liste->quad->op2->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op2->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op2->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        }

        sprintf(buffer_data + strlen(buffer_data), "%s:   .word 0\n", liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "\tbne $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7, idx + 3000);

        // sprintf(buffer_text + strlen(buffer_text),"LABEL%d\n",liste->next->quad->res->u.cst);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        break;
    case Q_IF_GT:
        printf(" IF > ");

        idx = isTemporaryVariable(liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "addr%d : \n", count_goto);

        /*if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
        }*/

        if (liste->quad->op2->kind == QO_CST) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
        } else {
            if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == STRING) {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
            } else if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == INT) {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
            } else if (liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '$') {
                sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
            } else if (liste->quad->op1->kind == QO_ID) {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            } else if (liste->quad->op1->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op1->u.name));
                sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
                arg_number++;
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
            }
        }

        if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op2->kind == QO_ID && liste->quad->op2->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op2->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op2->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        }

        sprintf(buffer_data + strlen(buffer_data), "%s:   .word 0\n", liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "\tbgt $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7, idx + 3000);

        // sprintf(buffer_text + strlen(buffer_text),"LABEL%d\n",liste->next->quad->res->u.cst);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        /*sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);*/

        break;
    case Q_IF_GE:
        printf(" IF >= ");

        idx = isTemporaryVariable(liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "addr%d : \n", count_goto);

        /*if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
        }*/

        if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op1->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op1->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        }

        if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_ID && liste->quad->op2->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op2->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op2->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        }

        sprintf(buffer_data + strlen(buffer_data), "%s:   .word 0\n", liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "\tbge $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7, idx + 3000);

        // sprintf(buffer_text + strlen(buffer_text),"LABEL%d\n",liste->next->quad->res->u.cst);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        /*sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);*/

        break;
    case Q_IF_LT:
        printf(" IF < ");

        idx = isTemporaryVariable(liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "addr%d : \n", count_goto);

        /*if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->res->u.name) && get_from_table(tos, liste->quad->res->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op2->u.cst);
        }*/

        if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op1->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op1->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        }

        if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_ID && liste->quad->op2->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op2->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op2->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        }

        sprintf(buffer_data + strlen(buffer_data), "%s:   .word 0\n", liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "\tblt $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7, idx + 3000);

        // sprintf(buffer_text + strlen(buffer_text),"LABEL%d\n",liste->next->quad->res->u.cst);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        /*sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);*/

        break;
    case Q_IF_LE:
        printf(" IF <= ");

        idx = isTemporaryVariable(liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "addr%d : \n", count_goto);

        if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (get_from_table(tos, liste->quad->op1->u.name) && get_from_table(tos, liste->quad->op1->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_ID && liste->quad->op1->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op1->kind == QO_ID) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        } else if (liste->quad->op1->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op1->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
        }

        if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == STRING) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (get_from_table(tos, liste->quad->op2->u.name) && get_from_table(tos, liste->quad->op2->u.name)->type == INT) {
            sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        } else if (liste->quad->op2->kind == QO_ID && liste->quad->op2->u.name[0] == '$') {
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $a%c\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name[1] - 1);
        } else if (liste->quad->op2->kind == QO_STR && (liste->quad->op1->u.name[0] == '"' || liste->quad->op1->u.name[0] == '\'')) {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t8, %d\n", convert_string_to_int(liste->quad->op2->u.name));
            sprintf(buffer_text + strlen(buffer_text), "\tmove $t%d, $t8\n", (curr_temp_reg++) % 7);
            arg_number++;
        } else {
            sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
        }

        sprintf(buffer_data + strlen(buffer_data), "%s:   .word 0\n", liste->quad->res->u.name);

        sprintf(buffer_text + strlen(buffer_text), "\tble $t%d, $t%d, ELSE%d\n", (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7, idx + 3000);

        // sprintf(buffer_text + strlen(buffer_text),"LABEL%d\n",liste->next->quad->res->u.cst);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "\tli $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tsw $s%d, __TEMP__%d\n", idx % 7, idx);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);

        /*sprintf(buffer_text + strlen(buffer_text), "li $s%d, 0\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "\tj EXIT%d\n", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "ELSE%d : ", idx + 3000);

        sprintf(buffer_text + strlen(buffer_text), "li $s%d, 1\n", idx % 7);

        sprintf(buffer_text + strlen(buffer_text), "EXIT%d :\n", idx + 3000);*/

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
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "\tandi $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "\tandi $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }
        break;
    case Q_OR:
        printf(" OR");

        if ((idx = isTemporaryVariable(liste->quad->res->u.name)) >= 0) {

            // load the op1 in a temporary variable

            if (liste->quad->op1->kind == QO_CST) {
                sprintf(buffer_text + strlen(buffer_text), "\tli $t%d, %d\n", (curr_temp_reg++) % 7, liste->quad->op1->u.cst);
            } else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op1->u.name);
            }

            // concatenation

            if (liste->quad->op2->kind == QO_CST)
                sprintf(buffer_text + strlen(buffer_text), "\tori $s%d, $t%d, %d\n", idx % 7, (curr_temp_reg - 1) % 7, liste->quad->op2->u.cst);
            else {
                sprintf(buffer_text + strlen(buffer_text), "\tlw $t%d, %s\n", (curr_temp_reg++) % 7, liste->quad->op2->u.name);
                sprintf(buffer_text + strlen(buffer_text), "\tori $s%d, $t%d, $t%d\n", idx % 7, (curr_temp_reg - 2) % 7, (curr_temp_reg - 1) % 7);
            }
        }
        break;
    }

    count_goto++;

    printf("\n");
}
