#include "mips.h"
#include "quads.h"
#include "tos.h"
#include <getopt.h>
#include <stdio.h>

extern int yyparse();
extern int yylex();
extern char *yytext;
struct tos **tos[MAX_DEPTH];
int depth = 0;

int nb_temp = 1; // nombre de variable temporaire céer, permet d'incrémenter leurs nom à leur création
listQ *Lglobal;  // liste des quads

int main(int argc, char **argv) {
    if (argc < 1) {
        printf("Usage: %s [-version | --version | -v] [-tos | --tos | -t] [(-output | --output | -o) <name>]\n", argv[0]);
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
            printf("Usage: %s [-version | --version | -v] [-tos | --tos | -t] [(-output | --output | -o) <name>]\n", argv[0]);
            return 1;
        }
    }

    if (output != NULL) {
        printf("Output file: %s\n", output); // TODO
    }

    if ((tos[0] = create_table()) == NULL) {
        return 1;
    }

    Lglobal = Lcreat();

    int r = yyparse();

    printf("->%d\n", r);

    // mips();

    int i = 0;
    while (tos[i] != NULL) {
        printf("\n### Table of symboles %d %s : ###\n\n", i, (i == 0) ? "(global)" : "(local)");
        show_table(tos[i]);
        free_table(tos[i]);
        i++;
    }
    printf("\n");

    return r;
}
