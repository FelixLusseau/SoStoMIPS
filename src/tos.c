#include "tos.h"

extern struct tos_entry **tos[MAX_TOS_SIZE];
extern int depth;

unsigned int hash(unsigned char *str) {
    unsigned hash = 6961;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    hash %= HT_SIZE;
    return hash;
}

struct tos_entry **create_table() {
    struct tos_entry **table = calloc(HT_SIZE, sizeof(struct tos_entry));
    if (table == NULL) {
        return NULL;
    }
    return table;
}

int add_to_table(struct tos_entry **table, char *str, int var_kind, int tab_length, char *string) {
    // printf("Adding %s to table as %d", str, var_kind);
    unsigned int hash1 = hash((unsigned char *)str);

    if (table[hash1] == NULL) { // Créé une entrée si elle n'existe pas
        CHKP((table[hash1] = calloc(1, sizeof(struct tos_entry))));
        CHKP((table[hash1]->str = malloc(sizeof(char) * MAX_LENGTH)));
    } else // Empêche d'écraser une entrée existante
        return hash1;
    sprintf(table[hash1]->str, "%s", str);
    if (depth == 0) { // Vérifie si le symbole actuel est global ou local
        table[hash1]->used = 1;
        table[hash1]->depth = depth;
        table[hash1]->var_kind = var_kind;
        table[hash1]->tab_length = tab_length;
        table[hash1]->fn_args_counter = 0;
        table[hash1]->type = UNDEFINED;
        if (string != NULL) {
            CHKP((table[hash1]->string = malloc(sizeof(char) * MAX_LENGTH)));
            sprintf(table[hash1]->string, "%s", string);
        } else
            table[hash1]->string = NULL;
        /* if (table[hash1]->next_lvl == NULL) // bizarre
            table[hash1]->next_lvl = NULL; */
    } else {
        if (!table[hash1]->used) // conditional jump or move depends on uninitialised value(s) // Ok ?
            table[hash1]->used = 0;
        for (int d = 0; d < depth; d++) {
            if (table[hash1]->next_lvl == NULL) {
                CHKP((table[hash1]->next_lvl = calloc(1, sizeof(struct tos_entry))));
                CHKP((table[hash1]->next_lvl->str = malloc(sizeof(char) * MAX_LENGTH)));
            }
            sprintf(table[hash1]->next_lvl->str, "%s", str);
            if (d == depth - 1) {
                table[hash1]->next_lvl->used = 1;
                table[hash1]->next_lvl->depth = depth;
                table[hash1]->next_lvl->var_kind = var_kind;
                table[hash1]->next_lvl->tab_length = tab_length;
                table[hash1]->next_lvl->fn_args_counter = 0;
                table[hash1]->next_lvl->type = UNDEFINED;
                if (string != NULL) {
                    CHKP((table[hash1]->next_lvl->string = malloc(sizeof(char) * MAX_LENGTH)));
                    sprintf(table[hash1]->next_lvl->string, "%s", string);
                } else
                    table[hash1]->next_lvl->string = NULL;
                table[hash1]->next_lvl->next_lvl = NULL;
            } else
                table[hash1]->next_lvl->used = 0;
        }
    }
    return hash1;
}

int update_type(struct tos_entry **table, char *str, int type) {
    unsigned int hash1 = hash((unsigned char *)str);
    if (table[hash1] == NULL)
        return -1;
    if (table[hash1]->used) {
        if (table[hash1]->type == INT) // Évite de remodifier le type d'un INT
            return 0;
        else {
            table[hash1]->type = type;
            printf("\033[91mUpdating type of %s to %d\033[0m\n", str, type);
        }
    } else {
        if (table[hash1]->next_lvl->type == INT) // Évite de remodifier le type d'un INT
            return 0;
        else {
            table[hash1]->next_lvl->type = type;
            printf("\033[91mUpdating type of %s to %d\033[0m\n", str, type);
        }
    }
    return 0;
}

int update_args_count(struct tos_entry **table, char *str, int fn_args_counter) {
    unsigned int hash1 = hash((unsigned char *)str);
    if (table[hash1] == NULL)
        return -1;
    if (table[hash1]->used)
        table[hash1]->fn_args_counter = fn_args_counter;
    else
        table[hash1]->next_lvl->fn_args_counter = fn_args_counter;
    return 0;
}

struct tos_entry *get_from_table(struct tos_entry **table, char *str) {
    unsigned int hash1 = hash((unsigned char *)str);
    if (table[hash1] == NULL)
        return NULL;
    if (depth == 1 && table[hash1]->used == 0 && table[hash1]->next_lvl != NULL)
        return table[hash1]->next_lvl;
    else
        return table[hash1];
}

void show_table(struct tos_entry **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL) {
            struct tos_entry *entry = table[i];
            while (entry != NULL) {
                if (entry->used == 1) {
                    printf("n°%d : ", i);
                    switch (entry->var_kind) {
                    case IDENTIFIER:
                        printf("ID\t\t\t");
                        switch (entry->type) {
                        case UNDEFINED:
                            printf("Type : undefined");
                            break;
                        case INT:
                            printf("Type : int      ");
                            break;
                        case FLOAT:
                            printf("Type : float      ");
                            break;
                        case STRING:
                            printf("Type : string      ");
                            break;
                        case BOOL:
                            printf("Type : bool      ");
                            break;
                        }
                        printf("\t");
                        break;
                    case FUNCTION:
                        printf("Function of %d argument(s)\t\t\t", entry->fn_args_counter);
                        break;
                    case ARRAY:
                        printf("Array of %d elements\t\t\t\t", entry->tab_length);
                        break;
                    }
                    printf("%s", entry->str);
                    if (entry->depth)
                        printf(" (local variable)");
                    if (entry->type == STRING && entry->string != NULL)
                        printf(" : %s", entry->string);
                    printf("\n");
                }
                entry = entry->next_lvl;
            }
        }
    }
}

void free_table(struct tos_entry **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) { // Parcours de toute la table
        if (table[i] != NULL) {                  // Teste la présence d'un symbole
            if (table[i]->next_lvl != NULL) {    // Libère l'entrée locale si elle existe
                if (table[i]->next_lvl->string != NULL)
                    free(table[i]->next_lvl->string);
                free(table[i]->next_lvl->str);
                free(table[i]->next_lvl);
            }
            // printf("Freeing %s\n", table[i]->str);
            if (table[i]->string != NULL)
                free(table[i]->string);
            free(table[i]->str);
            free(table[i]);
        }
    }
    free(table);
}