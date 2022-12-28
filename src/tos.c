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
        table[hash1]->var_kind = var_kind;
        table[hash1]->tab_length = tab_length;
        table[hash1]->type = UNDEFINED;
        memset(table[hash1]->next_lvl, 0, sizeof(table[hash1]->next_lvl));
    } else
        table[hash1]->used = 0;

    return hash1;
}

struct tos_entry *get_from_table(struct tos_entry **table, char *str) {
    unsigned int hash1 = hash((unsigned char *)str);
    if (table[hash1] == NULL) {
        return NULL;
    }
    return table[hash1];
}

void free_table(struct tos_entry **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL) {
            free(table[i]->str);
            free(table[i]);
        }
    }
    free(table);
}

void show_table(struct tos_entry **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL && table[i]->used == 1) {
            printf("n°%d : ", i);
            switch (table[i]->var_kind) {
            case IDENTIFIER:
                printf("ID\t\t\t");
                switch (table[i]->type) {
                case UNDEFINED:
                    printf("Type : undefined");
                    break;
                case INT:
                    printf("Type : int      ");
                    break;
                case FLOAT:
                    printf("Type : float");
                    break;
                case STRING:
                    printf("Type : string");
                    break;
                case BOOL:
                    printf("Type : bool");
                    break;
                }
                printf("\t");
                break;
            case FUNCTION:
                printf("Function\t\t\t\t\t");
                break;
            case ARRAY:
                printf("Array of %d elements\t\t\t\t", table[i]->tab_length);
                break;
            }
            printf("%s", table[i]->str);

            printf("\n");
        }
    }
}
