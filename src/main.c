#include "quads.h"
#include "tos.h"
#include <getopt.h>
#include <stdio.h>

#define RED "\x1B[31m"
#define reset "\x1B[0m"

extern int yyparse();
extern int yylex();
extern char *yytext;
char **tos;

int nb_temp = 1; // nombre de variable temporaire céer, permet d'incrémenter leurs nom à leur création
listQ *Lglobal;  // liste des quads

int main(int argc, char **argv) {
    if (argc < 1) {
        printf(RED "Usage: %s [-version | --version | -v] [-tos | --tos | -t] [(-output | --output | -o) <name>]\n" reset, argv[0]);
        return 1;
    }

    int c;
    char *output = NULL;

    static struct option long_options[] = {
        {"output", required_argument, 0, 'o'}, {"version", no_argument, 0, 'v'}, {"tos", no_argument, 0, 't'}, {0, 0, 0, 0}};
    int option_index = 0;

    while ((c = getopt_long_only(argc, argv, "o:vt", long_options, &option_index)) != -1) {
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
        default:
            printf(RED "Usage: %s [-version | --version | -v] [-tos | --tos | -t] [(-output | --output | -o) <name>]\n" reset, argv[0]);
            return 1;
        }
    }

    if (output != NULL) {
        printf("Output file: %s\n", output); // TODO
    }

    if ((tos = create_table()) == NULL) {
        return 1;
    }
    // printf("Table of symboles created\n");
    /* if (add_to_table(tos, "toto") == -1) {
        return 1;
    }
    printf("Added to table of symboles\n"); */

    Lglobal = Lcreat();

    int r = yyparse();

    printf("->%d\n", r);

    show_table(tos);
    free_table(tos);
    // printf("Table of symboles freed\n");

    return r;
}