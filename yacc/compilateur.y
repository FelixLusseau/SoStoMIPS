%{
#ifdef YYDEBUG
  yydebug = 1;
#endif

#include "quads.h"
#include "tos.h"
#include <stdio.h>

extern int yylex(); 
extern char* text;
extern void yyerror(const char * msg);
extern listQ *Lglobal;
%}
%union{char *strval; 
       int intval; 
       listQ* listeQ; 
       quads *quad; 
       quadOP *operateur;}

%token IF THEN FOR DO DONE IN WHILE UNTIL CASE ESAC MYECHO READ RETURN EXIT LOCAL ELIF ELSE FI DECLARE TEST EXPR O A N Z EQ NE GT GE LT LE
%token <strval> ID 
%token <strval> CHAINE 

%type <operateur> test_expr3
%type <operateur> test_expr2
%type <operateur> test_expr
%type <operateur> test_bloc
%type <operateur> test_instruction
%type <operateur> concatenation 
%type <operateur> operande
%type <operateur> operande_entier
%type <operateur> somme_entiere
%type <operateur> produit_entier

%type <listeQ> instruction
%type <listeQ> liste_instructions
%type <listeQ> programme

%type <intval> plus_ou_moin
%type <intval> fois_div_mod
%type <intval> operateur1
%type <intval> operateur2
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
  quadOP* res= QOcreat(QO_ID,$1,0);
  quads *q=Qcreat(Q_EQUAL,res,$3,NULL);
  Lappend(Lglobal,q);
  free($1);
}
| ID '[' operande_entier ']' '=' concatenation         { printf("instruction-> ID [ operande_entier ] = concatenation\n");}
| DECLARE ID '[' ID ']'                                { printf("instruction-> DECLARE ID [ ENTIER ] \n");}
| IF test_bloc THEN liste_instructions else_part FI    { printf("instruction-> IF test_bloc THEN liste_instructions else_part FI \n");
 
}
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

  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_CONCAT,temp,$1,$2);

  Lappend(Lglobal,q);
  $$=temp;
}
| operande { 
  printf("concatenation-> operande \n");  
  $$=$1;
} ;

test_bloc:
TEST test_expr  { printf("test_bloc-> TEST test_expr \n"); $$=$2;};

test_expr:
test_expr O test_expr2 { 
  printf("test_expr-> test_expr O test_expr2 \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_OR,temp,$1,$3);
  $$=temp;
  }
| test_expr2 {  printf("test_expr-> test_expr2 \n"); $$=$1;} ;

test_expr2:
test_expr2 A test_expr3 { 
  printf("test_expr2-> test_expr2 A test_expr3 \n");

  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_AND,temp,$1,$3);
  $$=temp;
  } 
| test_expr3            { printf("test_expr2-> test_expr3 \n"); $$=$1;} ;

test_expr3:
'(' test_expr ')'       { printf("test_expr3-> ( test_expr ) \n"); $$=$2;}
| '!' '(' test_expr ')' { 
  printf("test_expr3-> ! ( test_expr ) \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_NOT,temp,$3,NULL);
  $$=temp;
  }
| test_instruction      { printf("test_expr3-> test_instruction \n"); $$=$1;}
| '!' test_instruction  { 
  printf("test_expr3-> ! test_instruction \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_NOT,temp,$2,NULL);
  $$=temp;
  };

test_instruction:
concatenation '=' concatenation       { 
  printf("test_instruction-> concatenation = concatenation \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_EQ,temp,$1,$3);
  Lappend(Lglobal,q);
  $$=temp;
  }
| concatenation '!' '=' concatenation { 
  printf("test_instruction-> concatenation != concatenation \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_NE,temp,$1,$4);
  Lappend(Lglobal,q);
  $$=temp;
  }
| operateur1 concatenation { 
  printf("test_instruction-> operateur1 concatenation \n");
  quadOP* temp=QOcreat_temp();
  
  int oper=0;
  switch($1){
    case 1:
      oper=Q_IF_N;
      break;
    case 2:
      oper=Q_IF_Z;
      break;
  }
  quads *q=Qcreat(oper,temp,$2,NULL);
  Lappend(Lglobal,q);
  $$=temp;
  }
| operande operateur2 operande { 
  printf("test_instruction-> operande operateur2 operande \n");
  int oper=0;
  switch($2){
    case 1:
      oper=Q_IF_EQ;
      break;
    case 2:
      oper=Q_IF_NE;
      break;
    case 3:
      oper=Q_IF_GT;
      break;
    case 4:
      oper=Q_IF_GE;
      break;
    case 5:
      oper=Q_IF_LT;
      break;
    case 6:
      oper=Q_IF_LE;
      break;
  }
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(oper,temp,$1,$3);
  $$=temp;
  Lappend(Lglobal,q);
  };

operateur1:
N {$$=1;}
|Z  {$$=2;};

operateur2:
EQ  { printf("operateur2-> -eq\n"); $$=1;}
|NE { printf("operateur2-> -ne\n"); $$=2;}
|GT { printf("operateur2-> -gt\n"); $$=3;}
|GE { printf("operateur2-> -ge\n"); $$=4;}
|LT { printf("operateur2-> -lt\n"); $$=5;}
|LE { printf("operateur2-> -le\n"); $$=6;};

operande:
'$' '{' ID '}' { 
  printf("operande-> $ { ID }\n");
  $$=QOcreat(QO_ID,$3,0);
  free($3);
  }
| '$' '{' ID '[' operande_entier ']' '}' {
   printf("operande-> $ { ID [ operande_entier ] }\n");

    printf("operande_entier-> $ { ID [ operande_entier ] } \n");
    quadOP* tab=QOcreat(QO_TAB,$3,0);
    quadOP* temp=QOcreat_temp();
    quads *q=Qcreat(Q_TAB_GIVE,temp,tab,$5);
    Lappend(Lglobal,q);
    $$=temp;
    free($3);
   }| ID { 
  printf("operande-> MOT\n");
  $$=QOcreat(QO_STR,$1,0);
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
| '$' '(' EXPR somme_entiere ')' { 
  printf("operande-> $ ( EXPR somme_entiere )\n");
  $$=$4;
  }
| '$' '(' appel_de_fonction ')'          { printf("operande-> $ ( appel_de_fonction )\n");} ;

somme_entiere:
somme_entiere plus_ou_moin produit_entier { 
  printf("somme_entiere-> somme_entiere plus_ou_moin produit_entier \n");

  quadOP *temp=QOcreat_temp();

  quads *q=NULL;
  if($2){
    q=Qcreat(Q_ADD,temp,$1,$3);
  }else{
    q=Qcreat(Q_LESS,temp,$1,$3);
  }
  Lappend(Lglobal,q);

  $$=temp;
}
| produit_entier { 
  printf("somme_entiere-> produit_entier \n");
  $$=$1;
};

produit_entier:
produit_entier fois_div_mod operande_entier { 
  printf("produit_entier-> produit_entier fois_div_mod operande_entier\n");

  quadOP *temp=QOcreat_temp();
  quads *q=NULL;
  switch($2){
    case 1:
      q=Qcreat(Q_MUL,temp,$1,$3);
      break;
    case 2:
      q=Qcreat(Q_DIV,temp,$1,$3);
      break;
    case 3:
      q=Qcreat(Q_MOD,temp,$1,$3);
      break;
  }
  Lappend(Lglobal,q);
  $$=temp;
}
|operande_entier { 
  printf("produit_entier-> operande_entier \n");
  $$=$1;
  };


operande_entier: 
'$' '{' ID '}'{ 
  printf("operande_entier-> $ { ID } \n");
    quadOP* op=QOcreat(QO_ID,$3,0);
    $$=op;
    free($3);
  }
| '$' '{' ID '[' operande_entier ']' '}' { 
  printf("operande_entier-> $ { ID [ operande_entier ] } \n");
  quadOP* tab=QOcreat(QO_TAB,$3,0);
  quadOP* temp=QOcreat_temp();
  quads *q=Qcreat(Q_TAB_GIVE,temp,tab,$5);
  Lappend(Lglobal,q);
  $$=temp;
  free($3);
  }
| '$' ID { 
  printf("operande_entier-> $ ENTIER \n");
  int entier;
  if(ToInt(&entier,$2)){ // on vérifie que c'est bien un entier

    int taille=(int)((ceil(log10(entier))+1)*sizeof(char));
    char id[taille+2];
    id[taille+1]='\0';
    sprintf(id,"$%d",entier);

    quadOP* op=QOcreat(QO_ID,id,0);
    $$=op;
    free($2);

  }else{ // $a ou $1mp
      printf("error: operande->$ENTIER ne doit contenir que des chiffres\n");
  }
  }
| plus_ou_moin '$' '{' ID '}' { 
  printf("operande_entier-> plus_ou_moin $ { ID } \n");

    quadOP* temp=QOcreat_temp();
    quadOP* op2=QOcreat(QO_ID,$4,0);
    quads* q=NULL;
    if($1){
      q=Qcreat(Q_ADD,temp,NULL,op2);
    }else{
      q=Qcreat(Q_LESS,temp,NULL,op2);
    }
    Lappend(Lglobal,q);
    free($4);
  }
| plus_ou_moin '$' '{' ID '[' operande_entier ']' '}' {
 printf("operande_entier-> plus_ou_moin $ { ID [ operande_entier ] }\n");

  quadOP* tab=QOcreat(QO_TAB,$4,0);
  quadOP* temp1=QOcreat_temp();
  quads *q=Qcreat(Q_TAB_GIVE,temp1,tab,$6);
  Lappend(Lglobal,q);

  quadOP* temp2=QOcreat_temp();
  q=NULL;
  if($1){
    q=Qcreat(Q_ADD,temp2,NULL,temp1);
  }else{
    q=Qcreat(Q_LESS,temp2,NULL,temp1);
  }
  Lappend(Lglobal,q);
  free($4);
 }
| plus_ou_moin '$' ID  { 
  printf("operande_entier-> plus_ou_moin $ ENTIER\n");
  int entier;
  if(ToInt(&entier,$3)){ // on vérifie que c'est bien un entier

    int taille=(int)((ceil(log10(entier))+1)*sizeof(char));
    char id[taille+2];
    id[taille+1]='\0';
    sprintf(id,"$%d",entier);

    quadOP* temp=QOcreat_temp();
    quadOP* op2=QOcreat(QO_ID,id,0);
    quads* q=NULL;
    if($1){
      q=Qcreat(Q_ADD,temp,NULL,op2);
    }else{
      q=Qcreat(Q_LESS,temp,NULL,op2);
    }
    Lappend(Lglobal,q);
    $$=temp;
    free($3);

  }else{ // $a ou $1mp
      printf("error: operande->$ENTIER ne doit contenir que des chiffres\n");
  }
  }
| ID { 
  printf("operande_entier-> ENTIER \n");
  int entier;
  if(ToInt(&entier,$1)){
    $$=QOcreat(QO_CST,NULL,entier);
  }
  free($1);
}
| plus_ou_moin ID { 
  printf("operande_entier-> plus_ou_moin ENTIER\n");
  int entier;
  if(ToInt(&entier,$2)){
    if($1){
      $$=QOcreat(QO_CST,NULL,entier);
    }
    else{

      $$=QOcreat(QO_CST,NULL,-entier);
    }
    free($2);
  }
  }
| '(' somme_entiere ')' { 
  printf("operande_entier-> ( somme_entiere ) \n");
  $$=$2;
  };

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