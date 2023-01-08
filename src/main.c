#include "errors.h"
#include "mips.h"
#include "quads.h"
#include "tos.h"
#include <getopt.h>
#include <stdio.h>

extern int yyparse();
extern int yylex();
extern char *yytext;
struct tos_entry **tos;
int depth = 0;
int output_file;

int nb_temp = 1;           // nombre de variables temporaires créées, permet d'incrémenter leur nom à leur création
listQ *Lglobal;            // liste des quads
int taille_parametres = 0; // taille de la table des variables '$'

int main(int argc, char **argv) {
    if (argc < 1) {
        printf("Usage: %s [--version | -v] [--tos | -t] [(--output | -o) <name>] [--help | -h] < \"SoS_program\"\n", argv[0]);
        return 1;
    }

    int c;
    char *output = NULL;

    static struct option long_options[] = {{"output", required_argument, 0, 'o'},
                                           {"version", no_argument, 0, 'v'},
                                           {"tos", no_argument, 0, 't'},
                                           {"help", no_argument, 0, 'h'},
                                           {0, 0, 0, 0}};
    int option_index = 0;

    while ((c = getopt_long(argc, argv, "o:vth", long_options, &option_index)) != -1) {
        switch (c) {
        case 'o':
            output = optarg;
            break;
        case 'v':
            printf("COUTURE Louise - ELMAHI Aymane - LUSSEAU Félix - TAKI AMRANI Oussama\n");
            return 0;
        case 't':
            printf("TOS\n");
            return 0;
        case 'h':
            printf("Usage: %s [--version | -v] [--tos | -t] [(--output | -o) <name>] [--help | -h] < \"SoS_program\"\n", argv[0]);
            return 0;
        default:
            printf("Usage: %s [--version | -v] [--tos | -t] [(--output | -o) <name>] [--help | -h] < \"SoS_program\"\n", argv[0]);
            return 1;
        }
    }

    if (output != NULL) { // Permet de modifier le fichier assembleur de sortie si demandé sinon "mips.asm"
        printf("Output file: %s\n", output);
        CHK(output_file = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0666));
    }

    if ((tos = create_table()) == NULL) {
        return 1;
    }

    Lglobal = Lcreat();

    int r = yyparse(); // Lancement de l'analyse syntaxique

    printf("Yacc return : ->%d\n", r);

    if (r != 0) {
        printf("Erreur de syntaxe\n");
        return r;
    }

    mips();

    printf("\n### Table of symbols : ###\n\n");
    show_table(tos);
    free_table(tos);

    printf("\nFree Lglobal:\n");
    Lfree();
    printf("\n");

    if (output_file)
        CHK(close(output_file));
    return 0;
}
