#ifndef TOS_H
#define TOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 100000
#define MAX_LENGTH 200
#define MAX_TOS_SIZE 100

struct tos_entry {
    char *str;
    int used;
    int depth;
    enum { IDENTIFIER, FUNCTION, ARRAY } var_kind;
    int tab_length;
    enum { UNDEFINED, INT, FLOAT, STRING, BOOL } type;
    struct tos_entry *next_lvl[MAX_TOS_SIZE];
};

unsigned int hash(unsigned char *str);

struct tos_entry **create_table();

int add_to_table(struct tos_entry **table, char *str, int var_kind, int tab_length);

struct tos_entry *get_from_table(struct tos_entry **table, char *str);

void show_table(struct tos_entry **table);

void free_table(struct tos_entry **table);

#endif