%{
#ifdef YYDEBUG
  yydebug = 1;
#endif

#include <stdio.h>

extern int yylex(); 
extern void yyerror(const char * msg);
%}

%token IF THEN FOR DO DONE IN WHILE UNTIL CASE ESAC MYECHO READ RETURN EXIT LOCAL ELIF ELSE FI DECLARE TEST EXPR ID ENTIER MOT CHAINE O A N Z EQ NE GT GE LT LE
%start programme

%%

programme: 
liste_instructions {printf("programme->liste_instruction\n");};

liste_instructions: 
liste_instructions ';' instruction {printf("liste_instruction->liste_instructions ; instruction\n");}
|instruction                       {printf("liste_instruction->instruction\n");};

instruction: 
ID '=' concatenation                                   { printf("instruction-> ID = concatenation\n");}
| ID '[' operande_entier ']' '=' concatenation         { printf("instruction-> ID [ operande_entier ] = concatenation\n");}
| DECLARE ID '[' ENTIER ']'                            { printf("instruction-> DECLARE ID [ ENTIER ] \n");}
| IF test_bloc THEN liste_instructions else_part FI    { printf("instruction-> IF test_bloc THEN liste_instructions else_part FI \n");}
| FOR ID DO IN liste_instructions DONE                 { printf("instruction->FOR ID DO IN liste_instructions DONE \n");}
| FOR ID IN liste_operandes DO liste_instructions DONE { printf("instruction-> FOR ID IN liste_operandes DO liste_instructions DONE  \n");}
| WHILE test_bloc DO liste_instructions DONE           { printf("instruction-> WHILE test_bloc DO liste_instructions DONE \n");}
| UNTIL test_bloc DO liste_instructions DONE           { printf("instruction-> UNTIL test_bloc DO liste_instructions DONE \n");}
| CASE operande IN liste_cas ESAC                      { printf("instruction-> CASE operande IN liste_cas ESAC \n");}
| MYECHO liste_operandes                               { printf("instruction-> MYECHO liste_operandes \n");}
| READ ID                                              { printf("instruction-> READ ID \n");}
| READ ID '[' operande_entier ']'                      { printf("instruction-> READ ID [ operande_entier ] \n");}
| declaration_de_fonction                              { printf("instruction-> declaration_de_fonction \n");}
| appel_de_fonction                                    { printf("instruction-> appel_de_fonction \n");}
| RETURN                                               { printf("instruction-> RETURN \n");}
| RETURN operande_entier                               { printf("instruction-> RETURN operande_entier \n");}
| EXIT                                                 { printf("instruction->EXIT\n");}
| EXIT operande_entier                                 { printf("instruction->EXIT operande_entier\n");}; 

else_part:
ELIF test_bloc THEN liste_instructions else_part  { printf("else_part->ELIF test_bloc THEN liste_instructions else_part\n");}
| ELSE liste_instructions                         { printf("else_part->ELSE liste_instructions\n");}
| %empty                                          { printf("else_part->empty\n");};

liste_cas:
liste_cas filtre ')' liste_instructions ';' ';'  { printf("liste_cas->liste_cas filtre ) liste_instructions ; ; \n");}
| filtre ')' liste_instructions ';' ';'          { printf("liste_cas->filtre ) liste_instructions ; ; \n");};

filtre:
MOT                  { printf("filtre->MOT\n");}
| CHAINE             { printf("filtre->CHAINE\n");}
| filtre '|' MOT     { printf("filtre->filtre | MOT\n");}
| filtre '|' CHAINE  { printf("filtre->filtre | CHAINE\n");}
| '*'                { printf("filtre-> *\n");};

liste_operandes:
liste_operandes operande      { printf("liste_operandes-> liste_operandes operande \n");}
| operande                    { printf("liste_operandes-> operande \n");}
| '$' '{' ID '[' '*' ']' '}'  { printf("liste_operandes-> $ { ID [ * ] } \n");} ;

concatenation:
concatenation operande { printf("concatenation-> concatenation operande \n");}
| operande             { printf("concatenation-> operande \n");} ;

test_bloc:
TEST test_expr  { printf("test_bloc-> TEST test_exp \n");};

test_expr:
test_expr O test_expr2 { printf("test_expr-> test_expr O test_expr2 \n");}
| test_expr2           { printf("test_expr-> test_expr2 \n");} ;

test_expr2:
test_expr2 A test_expr3 { printf("test_expr2-> test_expr2 A test_expr3 \n");} 
| test_expr3            { printf("test_expr2-> test_expr3 \n");} ;

test_expr3:
'(' test_expr ')'       { printf("test_expr3-> ( test_expr ) \n");}
| '!' '(' test_expr ')' { printf("test_expr3-> ! ( test_expr ) \n");}
| test_instruction      { printf("test_expr3-> test_instruction \n");}
| '!' test_instruction  { printf("test_expr3-> ! test_instruction \n");};

test_instruction:
concatenation '=' concatenation       { printf("test_instruction-> concatenation = concatenation \n");}
| concatenation '!' '=' concatenation { printf("test_instruction-> concatenation != concatenation \n");}
| operateur1 concatenation            { printf("test_instruction-> operateur1 concatenation \n");}
| operande operateur2 operande        { printf("test_instruction-> operande operateur2 operande \n");};

operateur1:
N
|Z ;

operateur2:
EQ
|NE
|GT
|GE
|LT
|LE ;

operande:
'$' '{' ID '}'                           { printf("operande-> $ { ID }\n");}
| '$' '{' ID '[' operande_entier ']' '}' { printf("operande-> $ { ID [ operande_entier ] }\n");}
| MOT                                    { printf("operande-> MOT\n");}
| '$' ENTIER                             { printf("operande-> $ ENTIER\n");} 
| '$' '*'                                { printf("operande-> $ *\n");}
| '$' '?'                                { printf("operande-> $ ?\n");}
| CHAINE                                 { printf("operande-> CHAINE\n");}
| '$' '(' EXPR somme_entiere ')'         { printf("operande-> $ ( EXPR somme_entiere )\n");}
| '$' '(' appel_de_fonction ')'          { printf("operande-> $ ( appel_de_fonction )\n");} ;

somme_entiere:
somme_entiere plus_ou_moin produit_entier { printf("somme_entiere-> somme_entiere plus_ou_moin produit_entier \n");}
| produit_entier                          { printf("somme_entiere-> produit_entier \n");};

produit_entier:
produit_entier fois_div_mod operande_entier { printf("produit_entier-> produit_entier fois_div_mod operande_entier\n");}
|operande_entier                            { printf("produit_entier-> operande_entier \n");};


operande_entier: 
'$' '{' ID '}'                                        { printf("operande_entier-> $ { ID } \n");}
| '$' '{' ID '[' operande_entier ']' '}'              { printf("operande_entier-> $ { ID [ operande_entier ] } \n");}
| '$' ENTIER                                          { printf("operande_entier-> $ ENTIER \n");}
| plus_ou_moin '$' '{' ID '}'                         { printf("operande_entier-> plus_ou_moin $ { ID } \n");}
| plus_ou_moin '$' '{' ID '[' operande_entier ']' '}' { printf("operande_entier-> plus_ou_moin $ { ID [ operande_entier ] }\n");}
| plus_ou_moin '$' ENTIER                             { printf("operande_entier-> plus_ou_moin $ ENTIER\n");}
| ENTIER                                              { printf("operande_entier-> ENTIER \n");}
| plus_ou_moin ENTIER                                 { printf("operande_entier-> plus_ou_moin ENTIER\n");}
| '(' somme_entiere ')'                               { printf("operande_entier-> ( somme_entiere ) \n");};

plus_ou_moin: '+' | '-' ;

fois_div_mod: '*' | '/' | '%' ;

declaration_de_fonction:
ID '(' ')' '{' decl_loc liste_instructions '}' { printf("declaration_de_fonction-> ID ( ) { decl_loc liste_instructions }\n");} ;

decl_loc:
decl_loc LOCAL ID '=' concatenation  { printf("decl_loc-> decl_loc LOCAL ID = concatenation \n");}
| %empty                             { printf("decl_loc-> empty \n");};

appel_de_fonction:
ID liste_operandes  { printf("appel_de_fonction-> ID liste_operandes \n");}
| ID                { printf("appel_de_fonction-> ID \n");} ;
 
%%

void yyerror(const char * msg){
    fprintf(stderr, "Erreur syntaxique: %s\n",msg);
}