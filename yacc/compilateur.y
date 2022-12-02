%{
#ifdef YYDEBUG
  yydebug = 1;
#endif

#include "quads.h"
#include <stdio.h>

extern int yylex(); 
extern char* text;
extern void yyerror(const char * msg);
extern listQ *Lglobal;
%}
%union{char *strval; int intval; listQ* listeQ; quads *quad; quadOP *operateur;}

%token IF THEN FOR DO DONE IN WHILE UNTIL CASE ESAC MYECHO READ RETURN EXIT LOCAL ELIF ELSE FI DECLARE TEST EXPR O A N Z EQ NE GT GE LT LE
%token <strval> ID 
%token <strval> CHAINE 

%type <operateur> concatenation 
%type <operateur> operande

%type <listeQ> instruction
%type <listeQ> liste_instructions
%type <listeQ> programme

%type <quad> somme_entiere
%type <quad> produit_entier

%type <intval> plus_ou_moin
%type <intval> fois_div_mod
%start programme

%%

programme: 
liste_instructions {
  printf("programme->liste_instruction\n\nAffichage Lglobal:\n");
  Laffiche(Lglobal);
  printf("\nFree Lglobal:\n");
  Lfree(Lglobal);
  };

liste_instructions: 
liste_instructions ';' instruction {
  printf("liste_instruction->liste_instructions ; instruction\n");
}
|instruction {
  printf("liste_instruction->instruction\n");
};

instruction: 
ID '=' concatenation                                   { printf("instruction-> ID = concatenation\n");
  quadOP* op1=QOcreat($3->kind,$3->u.name,0);
  quadOP* res= QOcreat(QO_ID,$1,0);
  quads *q=Qcreat(Q_EQUAL,res,op1,NULL);
  free($1);
  Lappend(Lglobal,q);
}
| ID '[' operande_entier ']' '=' concatenation         { printf("instruction-> ID [ operande_entier ] = concatenation\n");}
| DECLARE ID '[' ID ']'                                { printf("instruction-> DECLARE ID [ ENTIER ] \n");}
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
| EXIT { 
  printf("instruction->EXIT\n");
  quads *q=Qcreat(Q_EXIT,NULL,NULL,NULL);
  Lappend(Lglobal,q);
 }
| EXIT operande_entier { 
  printf("instruction->EXIT operande_entier\n");
  }; 

else_part:
ELIF test_bloc THEN liste_instructions else_part  { printf("else_part->ELIF test_bloc THEN liste_instructions else_part\n");}
| ELSE liste_instructions                         { printf("else_part->ELSE liste_instructions\n");}
| %empty                                          { printf("else_part->empty\n");};

liste_cas:
liste_cas filtre ')' liste_instructions ';' ';'  { printf("liste_cas->liste_cas filtre ) liste_instructions ; ; \n");}
| filtre ')' liste_instructions ';' ';'          { printf("liste_cas->filtre ) liste_instructions ; ; \n");};

filtre:
ID                   { printf("filtre->MOT\n");}
| CHAINE             { printf("filtre->CHAINE\n");}
| filtre '|' ID      { printf("filtre->filtre | MOT\n");}
| filtre '|' CHAINE  { printf("filtre->filtre | CHAINE\n");}
| '*'                { printf("filtre-> *\n");};

liste_operandes:
liste_operandes operande      { printf("liste_operandes-> liste_operandes operande \n");}
| operande                    { printf("liste_operandes-> operande \n");}
| '$' '{' ID '[' '*' ']' '}'  { printf("liste_operandes-> $ { ID [ * ] } \n");} ;

concatenation:
concatenation operande { 
  printf("concatenation-> concatenation operande \n");
  /**/
  quadOP *temp=QOcreat_temp();

  quadOP* op1=$1;
  if($1->kind==QO_ID){
    op1=QOcreat($1->kind,$1->u.name,0);
  }

  quads *q=Qcreat(Q_CONCAT,temp,$1,$2);

  Lappend(Lglobal,q);
  $$=temp;
}
| operande { 
  printf("concatenation-> operande \n");  
  $$=$1;
} ;

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
EQ  { printf("operateur2-> -eq\n");}
|NE { printf("operateur2-> -ne\n");}
|GT { printf("operateur2-> -gt\n");}
|GE { printf("operateur2-> -ge\n");}
|LT { printf("operateur2-> -lt\n");}
|LE { printf("operateur2-> -le\n");};

operande:
'$' '{' ID '}' { 
  printf("operande-> $ { ID }\n");
  $$=QOcreat(QO_ID,$3,0);
  free($3);
  }
| '$' '{' ID '[' operande_entier ']' '}' { printf("operande-> $ { ID [ operande_entier ] }\n");}
| ID { 
  printf("operande-> MOT\n");
  $$=QOcreat(QO_STR,$1,0);;
  free($1);
  }
| '$' ID { 
  printf("operande-> $ ENTIER\n");

  int entier;
  if(ToInt(&entier,$2)){ // on vérifie que c'est bien un entier

    int taille=(int)((ceil(log10(entier))+1)*sizeof(char));
    char id[taille+2];
    id[taille+1]='\0';
    sprintf(id,"$%d",entier);

    $$=QOcreat(QO_ID,id,0);
    free($2);

  }else{ // $a ou $1mp
      printf("error: operande->$ENTIER ne doit contenir que des chiffres\n");
  }
} 
| '$' '*' { 
  printf("operande-> $ *\n");
  $$=QOcreat(QO_STR,"$*",0);
  }
| '$' '?' { 
  printf("operande-> $ ?\n");
  $$=QOcreat(QO_STR,"$?",0);
  }
| CHAINE { 
  printf("operande-> CHAINE:%s\n",$1); 
  $$=QOcreat(QO_STR,$1,0);
  free($1);
  }
| '$' '(' EXPR somme_entiere ')'         { printf("operande-> $ ( EXPR somme_entiere )\n");}
| '$' '(' appel_de_fonction ')'          { printf("operande-> $ ( appel_de_fonction )\n");} ;

somme_entiere:
somme_entiere plus_ou_moin produit_entier { 
  printf("somme_entiere-> somme_entiere plus_ou_moin produit_entier \n");
/*
  quadOP *temp=QOcreat_temp();

  quads *q=NULL;
  if($2){
    q=Qcreat(Q_ADD,temp,$1,$3);
  }else{
    q=Qcreat(Q_LESS,temp,$1,$3);
  }
  Lappend(Lglobal,q);

  $$=q;*/
}
| produit_entier { 
  printf("somme_entiere-> produit_entier \n");
  $$=$1;
};

produit_entier:
produit_entier fois_div_mod operande_entier { 
  printf("produit_entier-> produit_entier fois_div_mod operande_entier\n");
}
|operande_entier                            { printf("produit_entier-> operande_entier \n");};


operande_entier: 
'$' '{' ID '}'                                        { printf("operande_entier-> $ { ID } \n");}
| '$' '{' ID '[' operande_entier ']' '}'              { printf("operande_entier-> $ { ID [ operande_entier ] } \n");}
| '$' ID                                              { printf("operande_entier-> $ ENTIER \n");}
| plus_ou_moin '$' '{' ID '}'                         { printf("operande_entier-> plus_ou_moin $ { ID } \n");}
| plus_ou_moin '$' '{' ID '[' operande_entier ']' '}' { printf("operande_entier-> plus_ou_moin $ { ID [ operande_entier ] }\n");}
| plus_ou_moin '$' ID                                 { printf("operande_entier-> plus_ou_moin $ ENTIER\n");}
| ID { 
  printf("operande_entier-> ENTIER \n");
}
| plus_ou_moin ID                                     { printf("operande_entier-> plus_ou_moin ENTIER\n");}
| '(' somme_entiere ')'                               { printf("operande_entier-> ( somme_entiere ) \n");};

plus_ou_moin: '+' {$$=1;} | '-' {$$=0;};

fois_div_mod: '*' {$$=1;}| '/' {$$=2;}| '%' {$$=3;};

declaration_de_fonction:
ID '(' ')' '{' decl_loc liste_instructions '}' { printf("declaration_de_fonction-> ID ( ) { decl_loc liste_instructions }\n");} ;

decl_loc:
decl_loc LOCAL ID '=' concatenation ';' { printf("decl_loc-> decl_loc LOCAL ID = concatenation \n");}
| %empty                                { printf("decl_loc-> empty \n");};

appel_de_fonction:
ID liste_operandes  { printf("appel_de_fonction-> ID liste_operandes \n");}
| ID                { printf("appel_de_fonction-> ID \n");} ;
 
%%

void yyerror(const char * msg){
    fprintf(stderr, "Erreur syntaxique: %s\n",msg);
}