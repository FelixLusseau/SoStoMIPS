#ifndef TOS_H
#define TOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 100000
#define MAX_LENGTH 200

enum var_type { IDENTIFIER, FUNCTION, ARRAY };

struct tos {
    char *str;
    int type;
    int tab_length;
};

unsigned int hash(unsigned char *str);

struct tos **create_table();

int add_to_table(struct tos **table, char *str, int type, int tab_length);

void free_table(struct tos **table);

void show_table(struct tos **table);

#endif