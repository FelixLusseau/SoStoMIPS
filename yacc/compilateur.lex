%{
#include "compilateur.tab.h" 
#include <stdio.h>
%}
%option noyywrap

FORBIDENNCHAR ([\'\"!;\[\]\|\(\)=(!=)(\\|[^n\'\"t])])
AUTORISERUNO ([[:alnum:]ëËàéçèùêÊ&#~-_^€@°$£µ§:.?,/*-+])

SPECIAUX (\\[tn\'\"\^\\])
AUTORISER ([[:alnum:]ëËàéçèùêÊ&#~_^€@°$£µ§:\.?,/*+\-]*)

%%
[0-9]+ {printf("    entier:%s\n",yytext); return(ENTIER);}

"(" { printf("    (\n"); return yytext[0];}
")" { printf("    )\n"); return yytext[0];}
"{" { printf("    {\n"); return yytext[0];}
"}" { printf("    }\n"); return yytext[0];}
"[" { printf("    [\n"); return yytext[0];}
"]" { printf("    ]\n"); return yytext[0];}
"," { printf("    ,\n"); return yytext[0];}
"'" { printf("    '\n"); return yytext[0];}
"=" { printf("    =\n"); return yytext[0];}
"+" { printf("    +\n"); return yytext[0];}
"*" { printf("    *\n"); return yytext[0];}
"-" { printf("    -\n"); return yytext[0];}
"/" { printf("    /\n"); return yytext[0];}
"%" { printf("    %%\n"); return yytext[0];}
";" { printf("    ;\n"); return yytext[0];}
"$" { printf("    $\n"); return yytext[0];}
"?" { printf("    ?\n"); return yytext[0];}
"|" { printf("    |\n"); return yytext[0];}


"if" {printf("    if\n"); return(IF);}
"then" {printf("    then\n"); return(THEN);}
"for" {printf("    for\n"); return(FOR);}
"do" {printf("    do\n"); return(DO);}
"done" {printf("    done\n"); return(DONE);}
"in" {printf("    in\n"); return(IN);}
"while" {printf("    while\n"); return(WHILE);}
"until" {printf("    until\n"); return(UNTIL);}
"case" {printf("    case\n"); return(CASE);}
"esac" {printf("    esac\n"); return(ESAC);}
"echo" {printf("    echo\n"); return(MYECHO);}
"read" {printf("    read\n"); return(READ);}
"return" {printf("    return\n"); return(RETURN);}
"exit" {printf("    exit\n"); return(EXIT);}
"local" {printf("    local\n"); return(LOCAL);}
"elif" {printf("    elif\n"); return(ELIF);}
"else" {printf("    else\n"); return(ELSE);}
"fi" {printf("    fi\n"); return(FI);}
"declare" { printf("    declare\n"); return(DECLARE);}
"test" {printf("    test\n"); return(TEST);}
"expr" {printf("    expr\n"); return(EXPR);}
"-a" {printf("    -a\n"); return(A);}
"-o" {printf("    -o\n"); return(O);}
"-eq" {printf("    -eq\n"); return(EQ);}
"-ne" {printf("    -ne\n"); return(NE);}
"-gt" {printf("    -gt\n"); return(GT);}
"-ge" {printf("    -ge\n"); return(GE);}
"-lt" {printf("    -lt\n"); return(LT);}
"-le" {printf("    -le\n"); return(LE);}
"-n" {printf("    -n\n"); return(N);}
"-z" {printf("    -z\n"); return(Z);}

[a-zA-Z]+[_a-zA-Z0-9]* {printf("    id:%s\n",yytext); return(ID);}

#.*\n {    printf("    commentaire\n");};

[[:space:]\n]* {/*printf("    tabulation\n");*/};

\"({AUTORISER}|{SPECIAUX})*\"|\'({AUTORISER}|{SPECIAUX})*\' {printf("    mot:%s\n",yytext);return MOT;}
\"({AUTORISER}|{SPECIAUX}|[[:space:]])*\"|\'({AUTORISER}|{SPECIAUX}|[[:space:]])*\' {printf("    chaine:%s\n",yytext);return CHAINE;}


. { fprintf(stderr, "Erreur lexicale (%s)\n", yytext);}

%%