#include "tos.h"

unsigned int hash(unsigned char *str) {
    unsigned hash = 6961;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    hash %= HT_SIZE;
    return hash;
}

char **create_table() {
    char **table = calloc(HT_SIZE, sizeof(char *));
    if (table == NULL) {
        return NULL;
    }
    return table;
}

int add_to_table(char **table, char *str) {
    unsigned int hash1 = hash((unsigned char *)str);
    if (table[hash1] == NULL) {
        if ((table[hash1] = malloc(MAX_LENGTH)) == NULL)
            return -1;
    }
    sprintf(table[hash1], "%s", str);
    return hash1;
}

void free_table(char **table) {
    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL) {
            free(table[i]);
        }
    }
    free(table);
}

void show_table(char **table) {
    printf("\n### Table of symboles : ###\n\n");

    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (table[i] != NULL) {
            printf("%d : %s\n", i, table[i]);
        }
    }
}

/* int main() {
    int t;
    char **hashTable = calloc(HT_SIZE, sizeof(char *));
    if (hashTable == NULL) {
        return 1;
    }

    unsigned int hash1 = 0;
    while ((t = yylex()) != 0) {
        if (t == IDENTIFICATEUR || t == CSTE_ENT || t == CSTE_REEL || t == CSTE_CAR ||
            t == CSTE_CHAINE || t == CSTE_LIB) {
            hash1 = hash((unsigned char *)yytext);
            if (hashTable[hash1] == NULL) {
                if ((hashTable[hash1] = malloc(MAX_LENGTH)) == NULL)
                    return 1;
            }
            sprintf(hashTable[hash1], "%s", yytext);
            printf("%d %u ", t, hash1);
        } else
            printf("%d ", t);
    }
    printf("\n");

    printf("\n### Table des symboles : ###\n\n");

    for (unsigned int i = 0; i < HT_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("%d : %s\n", i, hashTable[i]);
            free(hashTable[i]);
        }
    }

    free(hashTable);
    return 0;
} */