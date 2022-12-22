#ifndef TOS_H
#define TOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 100000
#define MAX_LENGTH 200

unsigned int hash(unsigned char *str);

char **create_table();

int add_to_table(char **table, char *str);

void free_table(char **table);

void show_table(char **table);

#endif