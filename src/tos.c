#include "tos.h"

extern struct tos **tos[MAX_DEPTH];
extern int depth;

unsigned int hash(unsigned char *str) {
    unsigned hash = 6961;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    hash %= HT_SIZE;
    return hash;
}

struct tos **create_table() {
    struct tos **table = calloc(HT_SIZE, sizeof(struct tos));
    if (table == NULL) {
        return NULL;
    }
    return table;
}

int add_to_table(struct tos **table, char *str, int type, int tab_length) {
    unsigned int hash1 = hash((unsigned char *)str);
    int i = 0;
    while (tos[i] != NULL) {
        if (tos[i][hash1] != NULL && table == tos[0]) {
            printf("Error: %s already exists in the table\n", str);
            return -1;
        }
        i++;
    }
    if (table[hash1] == NULL) {
        if ((table[hash1] = malloc(sizeof(struct tos))) == NULL)
            return -1;
        if ((table[hash1]->str = malloc(sizeof(char) * MAX_LENGTH)) == NULL)
            return -1;
    }
    sprintf(table[hash1]->str, "%s", str);
    table[hash1]->type = type;
    table[hash1]->tab_length = tab_length;
    return hash1;
}

struct tos *get_from_table(struct tos **table, char *str) {
    unsigned int hash1 = hash((unsigned char *)str);
    if (table[hash1] == NULL) {
        return NULL;
    }
    return table[hash1];
}

void free_table(struct tos **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL) {
            free(table[i]->str);
            free(table[i]);
        }
    }
    free(table);
}

void show_table(struct tos **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL) {
            printf("n°%d : ", i);
            switch (table[i]->type) {
            case IDENTIFIER:
                printf("ID\t\t\t");
                break;
            case FUNCTION:
                printf("Function\t\t");
                break;
            case ARRAY:
                printf("Array of %d elements\t", table[i]->tab_length);
                break;
            }
            printf("%s\n", table[i]->str);
        }
    }
}
