#include "tos.h"

extern struct tos_entry **tos[MAX_TOS_SIZE];
extern int depth;
extern int width[MAX_TOS_SIZE]; // width of the current depth

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

int add_to_table(struct tos_entry **table, char *str, int var_kind, int tab_length) {
    unsigned int hash1 = hash((unsigned char *)str);

    if (table[hash1] == NULL) {
        if ((table[hash1] = malloc(sizeof(struct tos_entry))) == NULL)
            return -1;
        if ((table[hash1]->str = malloc(sizeof(char) * MAX_LENGTH)) == NULL)
            return -1;
    }
    sprintf(table[hash1]->str, "%s", str);
    if (depth == 0) {
        table[hash1]->used = 1;
        table[hash1]->depth = depth;
        table[hash1]->var_kind = var_kind;
        table[hash1]->tab_length = tab_length;
        table[hash1]->type = UNDEFINED;
        if (table[hash1]->next_lvl[0] == NULL)
            memset(table[hash1]->next_lvl, 0, sizeof(table[hash1]->next_lvl));
    } else {
        if (!table[hash1]->used)
            table[hash1]->used = 0;
        for (int d = 0; d < depth; d++) {
            if (table[hash1]->next_lvl[0] == NULL) {
                if ((table[hash1]->next_lvl[0] = malloc(sizeof(struct tos_entry))) == NULL)
                    return -1;
                if ((table[hash1]->next_lvl[0]->str = malloc(sizeof(char) * MAX_LENGTH)) == NULL)
                    return -1;
            }
            sprintf(table[hash1]->next_lvl[0]->str, "%s", str);
            if (d == depth - 1) {
                table[hash1]->next_lvl[0]->used = 1;
                table[hash1]->next_lvl[0]->depth = depth;
                table[hash1]->next_lvl[0]->var_kind = var_kind;
                table[hash1]->next_lvl[0]->tab_length = tab_length;
                table[hash1]->next_lvl[0]->type = UNDEFINED;
                memset(table[hash1]->next_lvl[0]->next_lvl, 0, sizeof(table[hash1]->next_lvl[0]->next_lvl));
            } else
                table[hash1]->next_lvl[0]->used = 0;
        }
    }

    return hash1;
}

struct tos_entry *get_from_table(struct tos_entry **table, char *str) {
    unsigned int hash1 = hash((unsigned char *)str);
    if (table[hash1] == NULL) {
        return NULL;
    }
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
                        printf("Function\t\t\t\t\t");
                        break;
                    case ARRAY:
                        printf("Array of %d elements\t\t\t\t", entry->tab_length);
                        break;
                    }
                    printf("%s", entry->str);
                    if (entry->depth)
                        // printf("\t\t\t (depth %d)", entry->depth);
                        printf(" (local variable)");
                    printf("\n");
                }
                entry = entry->next_lvl[0];
                // printf("next : %p\n", entry);
            }
            // printf("\n");
        }
    }
}

void free_table(struct tos_entry **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL) {
            if (table[i]->next_lvl[0] != NULL) {
                free(table[i]->next_lvl[0]->str);
                free(table[i]->next_lvl[0]);
            }
            free(table[i]->str);
            free(table[i]);
        }
    }
    free(table);
}