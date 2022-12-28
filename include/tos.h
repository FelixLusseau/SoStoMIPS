#ifndef TOS_H
#define TOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 100000
#define MAX_LENGTH 200
#define MAX_DEPTH 100

struct tos {
    char *str;
    enum { IDENTIFIER, FUNCTION, ARRAY } var_kind;
    int tab_length;
};

unsigned int hash(unsigned char *str);

struct tos **create_table();

int add_to_table(struct tos **table, char *str, int var_kind, int tab_length);

struct tos *get_from_table(struct tos **table, char *str);

void free_table(struct tos **table);

void show_table(struct tos **table);

#endif