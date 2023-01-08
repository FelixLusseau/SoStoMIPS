#ifndef TOS_H
#define TOS_H

#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 100000
#define MAX_LENGTH 200
#define MAX_TOS_SIZE 100

struct tos_entry {
    char *str;
    int used; // Permet de savoir si l'entrée globale est utilisée ou non
    int depth;
    enum { IDENTIFIER, FUNCTION, ARRAY } var_kind;
    int tab_length;
    enum { UNDEFINED, INT, FLOAT, STRING, BOOL } type;
    struct tos_entry *next_lvl;
};

/**
 * @brief Fonction de hachage simple
 *
 * @param str
 * @return unsigned int
 */
unsigned int hash(unsigned char *str);

/**
 * @brief Fonction de création de la table des symboles
 *
 * @return struct tos_entry**
 */
struct tos_entry **create_table();

/**
 * @brief Fonction d'ajout d'une entrée dans la table des symboles
 *
 * @param table
 * @param str
 * @param var_kind
 * @param tab_length
 * @return int
 */
int add_to_table(struct tos_entry **table, char *str, int var_kind, int tab_length);

/**
 * @brief Fonction de mise à jour du type d'une entrée dans la table des symboles
 *
 * @param table
 * @param str
 * @param type
 * @return int
 */
int update_type(struct tos_entry **table, char *str, int type);

/**
 * @brief Fonction récupérant la structure d'une entrée dans la table des symboles,
 * correspondant à la profondeur actuelle (globale ou locale)
 *
 * @param table
 * @param str
 * @return struct tos_entry*
 */
struct tos_entry *get_from_table(struct tos_entry **table, char *str);

/**
 * @brief Fonction affichant la table des symboles
 *
 * @param table
 */
void show_table(struct tos_entry **table);

/**
 * @brief Fonction de libération de la table des symboles
 *
 * @param table
 */
void free_table(struct tos_entry **table);

#endif