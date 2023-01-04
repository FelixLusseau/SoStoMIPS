%{
#ifdef YYDEBUG
  yydebug = 1;
#endif

#include "quads.h"
#include "tos.h"
#include <stdio.h>

extern int yylex(); 
extern char* text;
extern void yyerror(const char *msg);
extern listQ *Lglobal;
extern struct tos_entry **tos;
extern int depth;
extern int taille_parametres;
extern int width[MAX_TOS_SIZE];
%}

%union{char *strval; 
       int intval; 
       listQ* listQ; 
       quads *quad; 
       quadOP *operateur;
       embranchment *branchement;
       case_test *Case;
       for_brnch *For;
       }

%token IF THEN FOR DO DONE IN WHILE UNTIL CASE ESAC MYECHO READ RETURN EXIT LOCAL ELIF ELSE FI DECLARE TEST EXPR O A N Z EQ NE GT GE LT LE

%token <strval> ID 
%token <strval> CHAINE 

%type <operateur> test_instruction
%type <operateur> concatenation 
%type <operateur> operande
%type <operateur> operande_entier
%type <operateur> somme_entiere
%type <operateur> produit_entier

%type <listQ> instruction

%type <operateur> liste_instructions
%type <branchement> test_bloc
%type <branchement> test_expr
%type <branchement> test_expr2
%type <branchement> test_expr3_0
%type <operateur> test_expr3

%type <Case> filtre
%type <Case> liste_cas

%type <For> for_id_liste_branchement

%type <intval> plus_ou_moin
%type <intval> fois_div_mod
%type <intval> operateur1
%type <intval> operateur2
%type <intval> M
%type <intval> liste_operandes

%start programme

%%

M: %empty {printf("M->empty\n");$$=Lglobal->taille;}

for_id_liste_branchement: %empty{
  
  $$=FBcreat();

  // index=0;
  quadOP *index=QOcreat_temp();
  quadOP *num=QOcreat(QO_CST,NULL,0);
  quads *q1=Qcreat(Q_EQUAL,index,num,NULL);
  Lappend(Lglobal,q1);

  // index+=1;
  quads *q2=Qcreat(Q_ADD,index,index,QOcreat(QO_CST,NULL,1));
  Lappend(Lglobal,q2);

  $$->addr_goback=Lglobal->taille;

  // temp= if index > ?;
  quadOP *temp=QOcreat_temp();
  quads *q3=Qcreat(Q_IF_GT,temp,index,NULL); // la taille est encore inconnue
  Lappend(Lglobal,q3);
  
  $$->Max=q3;

  // if temp goto ?;
  quads *q4=Qcreat(Q_IF,NULL,temp,NULL); // le saut est encore inconnue
  Lappend(Lglobal,q4);

  $$->GoTo=q4;

  // id = $[index];
  quadOP *tab=QOcreat(QO_TAB,"$",0);
  quads *q5=Qcreat(Q_TAB_GIVE,NULL,tab,index);
  Lappend(Lglobal,q5);

  $$->Id=q5;

};

programme: 
liste_instructions {
  printf("programme->liste_instruction\n\nAffichage Lglobal:\n");
  Laffiche(Lglobal);
  };

liste_instructions: 
liste_instructions ';' instruction {
  printf("liste_instruction->liste_instructions ; instruction\n");

  quadOP *addr=QOcreat(QO_ADDR,NULL,0);
  quads *nextQuad=Qcreat(Q_GOTO,addr,NULL,NULL);
  Lappend(Lglobal,nextQuad);
  addr->u.cst=Lglobal->taille+1;
  $$=addr;
}
|instruction {
  printf("liste_instruction->instruction\n");

  quadOP *addr=QOcreat(QO_ADDR,NULL,0);
  quads *nextQuad=Qcreat(Q_GOTO,addr,NULL,NULL);
  Lappend(Lglobal,nextQuad);
  addr->u.cst=Lglobal->taille+1;
  $$=addr;
  };

instruction: 
ID '=' concatenation { 
  printf("instruction-> ID = concatenation\n");
  add_to_table(tos, $1, IDENTIFIER, 0);
  update_type(tos, $1, STRING);

  quadOP* res= QOcreat(QO_ID,$1,0);
  quads *q=Qcreat(Q_EQUAL,res,$3,NULL);
  Lappend(Lglobal,q);
  }

| ID '[' operande_entier ']' '=' concatenation { 
  add_to_table(tos, $1, ARRAY, atoi((char*)$3));

  printf("instruction-> ID [ operande_entier ] = concatenation\n");


  quadOP *tab=QOcreat(QO_TAB,$1,0);
  quads *q=Qcreat(Q_TAB_EQUAL,tab,$3,$6);
  Lappend(Lglobal,q);

  }

| DECLARE ID '[' ID ']' { 
  printf("instruction-> DECLARE ID [ ENTIER ] \n");
  add_to_table(tos, $2, ARRAY, atoi((char*)$4));

  int index=0;
  if(!ToInt(&index,$4)){
    printf("ERROR: ToInt MOT N'EST PAS ENTIER\n");
  }

  quadOP *tab=QOcreat(QO_TAB,$2,0);
  quadOP *idx=QOcreat(QO_CST,NULL,index);
  quads *q=Qcreat(Q_TAB_CREAT,tab,idx,NULL);
  Lappend(Lglobal,q);
  }

| IF test_bloc M THEN liste_instructions M else_part FI    { 
  printf("instruction-> IF test_bloc THEN liste_instructions else_part FI \n");

  int addrM1=$3;
  int addrM2=$6;

  complete($2->True,addrM1+1);
  complete($2->False,addrM2+1);
 
}
| FOR for_id_liste_branchement ID  DO  liste_instructions DONE  { 
  printf("instruction->FOR ID DO IN liste_instructions DONE \n");
  add_to_table(tos, $3, IDENTIFIER, 0);

  int addrM0=$2->addr_goback;
  int addrM1=Lglobal->taille;

  // complètes les instructions au début de la boucle (for_id_liste_branchement)
  $2->Max->op2=QOcreat(QO_CST,NULL,taille_parametres);
  $2->GoTo->res=QOcreat(QO_ADDR,NULL,addrM1+1);
  char * id=strdup($3);
  $2->Id->res=QOcreat(QO_ID,id,0);

  $5->u.cst=addrM0; // boucle
  }
| FOR ID IN liste_operandes DO for_id_liste_branchement liste_instructions DONE { 
  printf("instruction-> FOR ID IN liste_operandes DO liste_instructions DONE  \n");
  add_to_table(tos, $2, IDENTIFIER, 0);

  if( $4 > taille_parametres ){
    taille_parametres=$4;
  }

  int addrM0=$6->addr_goback;
  int addrM1=Lglobal->taille;

  // complètes les instructions au début de la boucle (for_id_liste_branchement)
  $6->Max->op2=QOcreat(QO_CST,NULL,$4);
  $6->GoTo->res=QOcreat(QO_ADDR,NULL,addrM1+1);
  char * id=strdup($2);
  $6->Id->res=QOcreat(QO_ID,id,0);

  $7->u.cst=addrM0; // boucle

}
| WHILE M test_bloc M DO liste_instructions M DONE { 
  printf("instruction-> WHILE test_bloc DO liste_instructions DONE \n");

  int addrM0=$2;
  int addrM1=$4;
  int addrM2=$7;

  complete($3->True,addrM1+1);
  complete($3->False,addrM2+1);

  $6->u.cst=addrM0+1;
  }
| UNTIL M test_bloc M DO liste_instructions M DONE { 
  printf("instruction-> UNTIL test_bloc DO liste_instructions DONE \n");

  int addrM0=$2;
  int addrM1=$4;
  int addrM2=$7;

  complete($3->True,addrM2+1);
  complete($3->False,addrM1+1);

  $6->u.cst=addrM0+1;
  }

| CASE operande IN liste_cas ESAC { 
  printf("instruction-> CASE operande IN liste_cas ESAC \n");

  CTcomplete($4,$2);
  }

| MYECHO liste_operandes { 
  printf("instruction-> MYECHO liste_operandes \n");
  if($2>taille_parametres){
    taille_parametres=$2;
  }

  for(int i=1; i<=$2; i++){
    quadOP *index=QOcreat(QO_CST,NULL,i);
    quadOP *tab=QOcreat(QO_TAB,"$",0);
    quads *q=Qcreat(Q_ECHO,tab,index,NULL);
    Lappend(Lglobal,q);
  }
}
| READ ID { 
  printf("instruction-> READ ID \n");
  quadOP *id=QOcreat(QO_ID,$2,0);
  quads *q=Qcreat(Q_READ,id,NULL,NULL);
  Lappend(Lglobal,q);
}
| READ ID '[' operande_entier ']' { 
  printf("instruction-> READ ID [ operande_entier ] \n");
  quadOP *tab=QOcreat(QO_TAB,$2,0);
  quadOP *index=$4;
  quads *q=Qcreat(Q_READ,tab,index,NULL);
  Lappend(Lglobal,q);
}
| declaration_de_fonction { 
  printf("instruction-> declaration_de_fonction \n");
  }

| appel_de_fonction { 
  printf("instruction-> appel_de_fonction \n");
  }

| RETURN { 
  printf("instruction-> RETURN \n");
  quads *q=Qcreat(Q_RETURN,NULL,NULL,NULL);
  Lappend(Lglobal,q);
  }

| RETURN operande_entier { 
  printf("instruction-> RETURN operande_entier \n");
  quads *q=Qcreat(Q_RETURN,$2,NULL,NULL);
  Lappend(Lglobal,q);
  }

| EXIT { 
  printf("instruction->EXIT\n");
  quads *q=Qcreat(Q_EXIT,NULL,NULL,NULL);
  Lappend(Lglobal,q);
 }

| EXIT operande_entier { 
  printf("instruction->EXIT operande_entier\n");
  quads *q=Qcreat(Q_EXIT,$2,NULL,NULL);
  Lappend(Lglobal,q);
  }; 

else_part:
ELIF test_bloc M THEN liste_instructions M else_part  { 
  printf("else_part->ELIF test_bloc THEN liste_instructions else_part\n");

  int addrM1=$3;
  int addrM2=$6;

  complete($2->True,addrM1+1);
  complete($2->False,addrM2+1);
  
  $5->u.cst=addrM2+1;
  }
| ELSE liste_instructions { 
  printf("else_part->ELSE liste_instructions\n");
  }

| %empty { 
  printf("else_part->empty\n");
  };

liste_cas:
liste_cas filtre ')' M liste_instructions  ';' ';'  { 
  printf("liste_cas->liste_cas filtre ) liste_instructions ; ; \n");

  int M1=$4+1;
  int M2=Lglobal->taille+1;

  if($1!=NULL && $2!=NULL){
    $$=$1;
    $$->branch->True=Lconcat($$->branch->True,$2->branch->True);
    $$->branch->False=Lconcat($$->branch->False,$2->branch->False);
    $$->test=Lconcat($$->test,$2->test);

    complete($$->branch->True,M1);
    complete($$->branch->False,M2);
  }else if($1!=NULL){
    $$=$1;
  }else if($2!=NULL){
    $$=$2;
  }
  }

| filtre ')' M liste_instructions  ';' ';' { 
  printf("liste_cas->filtre ) liste_instructions ; ; \n");
  
  if($1!=NULL){
    $$=$1;
    int M1=$3+1;
    int M2=Lglobal->taille+1;
    complete($$->branch->True,M1);
    complete($$->branch->False,M2);
  }else{ /* $1 = "*"  */  
    $$=NULL;
  }
  };

filtre:
ID { 
  printf("filtre->MOT\n");

  quadOP *str=QOcreat(QO_STR,$1,0);
  quadOP *temp=QOcreat_temp();
  quads *test=Qcreat(Q_IF_EQ,temp,NULL,str);
  Lappend(Lglobal,test);

  quads *True=Qcreat(Q_IF,NULL,temp,NULL);
  Lappend(Lglobal,True);
  quads *False=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,False);

  $$=CTcreat();
  Lappend($$->branch->True,True);
  Lappend($$->branch->False,False);
  Lappend($$->test,test);
  }

| CHAINE { 

  printf("filtre->CHAINE\n");

  quadOP *str=QOcreat(QO_STR,$1,0);
  quadOP *temp=QOcreat_temp();
  quads *test=Qcreat(Q_IF_EQ,temp,NULL,str);
  Lappend(Lglobal,test);

  quads *True=Qcreat(Q_IF,NULL,temp,NULL);
  Lappend(Lglobal,True);
  quads *False=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,False);

  $$=CTcreat();
  Lappend($$->branch->True,True);
  Lappend($$->branch->False,False);
  Lappend($$->test,test);
  }

| filtre '|' M ID  { 
  printf("filtre->filtre | MOT\n");

  int M=$3+1;

  complete($1->branch->False,M);

  quadOP *str=QOcreat(QO_STR,$4,0);
  quadOP *temp=QOcreat_temp();
  quads *test=Qcreat(Q_IF_EQ,temp,NULL,str);
  Lappend(Lglobal,test);

  quads *True=Qcreat(Q_IF,NULL,temp,NULL);
  Lappend(Lglobal,True);
  quads *False=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,False);

  $$=$1;
  Lappend($$->branch->True,True);
  Lappend($$->branch->False,False);
  Lappend($$->test,test);

  if($1!=NULL){
    $$=$1;
    Lappend($$->branch->True,True);
    Lappend($$->branch->False,False);
    Lappend($$->test,test);
  }else{
  $$=CTcreat();
  Lappend($$->branch->True,True);
  Lappend($$->branch->False,False);
  Lappend($$->test,test);
  }
  }

| filtre '|' M CHAINE { 
  printf("filtre->filtre | CHAINE\n");

  int M=$3+1;

  complete($1->branch->False,M);

  quadOP *str=QOcreat(QO_STR,$4,0);
  quadOP *temp=QOcreat_temp();
  quads *test=Qcreat(Q_IF_EQ,temp,NULL,str);
  Lappend(Lglobal,test);

  quads *True=Qcreat(Q_IF,NULL,temp,NULL);
  Lappend(Lglobal,True);
  quads *False=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,False);

  if($1!=NULL){
    $$=$1;
    Lappend($$->branch->True,True);
    Lappend($$->branch->False,False);
    Lappend($$->test,test);
  }else{
  $$=CTcreat();
  Lappend($$->branch->True,True);
  Lappend($$->branch->False,False);
  Lappend($$->test,test);
  }
  }
| '*' { 
  printf("filtre-> *\n"); $$=NULL;
  };

liste_operandes:
liste_operandes operande { 
  printf("liste_operandes-> liste_operandes operande \n");

  $$=$1+1;

  quadOP *index=QOcreat(QO_CST,NULL,$$);
  quadOP *tab=QOcreat(QO_TAB,"$",0);
  quads *q=Qcreat(Q_TAB_EQUAL,tab,index,$2);
  Lappend(Lglobal,q);
  }

| operande { 
  printf("liste_operandes-> operande \n");

  quadOP *index=QOcreat(QO_CST,NULL,1);
  quadOP *tab=QOcreat(QO_TAB,"$",0);
  quads *q=Qcreat(Q_TAB_EQUAL,tab,index,$1);
  Lappend(Lglobal,q);

  $$=1;
  }

| '$' '{' ID '[' '*' ']' '}'  { 
  printf("liste_operandes-> $ { ID [ * ] } \n");

  quadOP *liste=QOcreat(QO_TAB,"$",0);
  quadOP *tab=QOcreat(QO_TAB,$3,0);
  quads *q=Qcreat(Q_EQUAL,liste,tab,NULL);
  Lappend(Lglobal,q);

  struct tos_entry *tab_tos=get_from_table(tos,$3);
  if(tab==NULL || tab_tos->var_kind!=ARRAY){
    yyerror("tableau:%s appellé alors que non initialisé ou n'est pas array");
  }


  $$=tab_tos->tab_length;
  } ;


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
};


test_bloc:
TEST test_expr  { 
  printf("test_bloc-> TEST test_expr \n"); 
  $$=$2;
  };

test_expr:
test_expr O M test_expr2 { 
  printf("test_expr-> test_expr O test_expr2 \n");

  complete($1->False,$3+1);
  $$=$4;
  listQ *T=Lconcat($1->True,$$->True);
  $$->True=T;
  }

| test_expr2 {  
  printf("test_expr-> test_expr2 \n"); $$=$1; 
  };


test_expr2:
test_expr2 A M test_expr3 { 
  printf("test_expr2-> test_expr2 A test_expr3 \n");

 // test_expr3
  quads *if_true3=Qcreat(Q_IF,NULL,$4,NULL);
  Lappend(Lglobal,if_true3);

  quads *if_false3=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,if_false3);

  complete($1->True,$3+1);
  Lappend($1->False,if_false3);

  $$=EMcreat();
  Lappend($$->True,if_true3);
  $$->False=$1->False;
  } 

| test_expr2 A M test_expr3_0 { 
  printf("test_expr2-> test_expr2 A test_expr3 \n"); 

  complete($1->True,$3+1);

  $$=EMcreat();
  $$->True = $1->True;
  $$->False = Lconcat($1->False,$4->False);
  }
| test_expr3 { 
  printf("test_expr2-> test_expr3 \n"); 
  
 // test_expr3
  quads *if_true3=Qcreat(Q_IF,NULL,$1,NULL);
  Lappend(Lglobal,if_true3);

  quads *if_false3=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,if_false3);

  $$=EMcreat();
  printf("2\n");
  Lappend($$->True,if_true3);
  Lappend($$->False,if_false3);
  printf("3\n");
  }

| test_expr3_0 { 
  printf("test_expr2-> test_expr3_0 \n"); $$=$1;
  };

test_expr3_0:
'(' test_expr ')' { 
  printf("test_expr3_0 -> ( test_expr ) \n"); $$=$2; 
  }

| '!' '(' test_expr ')' { 
  printf("test_expr3_0 -> ! ( test_expr ) \n"); 
  $$=EMcreat(); 
  $$->True = $3->False;
  $$->False = $3->True;
  };

test_expr3:
test_instruction { 
  printf("test_expr3 -> test_instruction \n"); $$=$1;}
| '!' test_instruction  { 
  printf("test_expr3-> ! test_instruction \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_NOT,temp,$2,NULL);
  Lappend(Lglobal,q);
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
   }
| ID { 
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
  $$=QOcreat(QO_TAB,"$",0);
  }

| '$' '?' { 
  printf("operande-> $ ?\n"); // résultat d'une fonction
  $$=QOcreat(QO_ID,"$?",0);
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
ID '(' ')' '{' { depth++; 
                /* printf("deeeeeeppppppttttthhhh : %d  ", depth); */ 
                quadOP *fct=QOcreat(QO_FCT,$1,0);
                quads *q=Qcreat(Q_FCT,fct,NULL,NULL);
                Lappend(Lglobal,q);
                } 
decl_loc liste_instructions { depth--; 
                              /* printf("deeeeeeppppppttttthhhh ------ : %d   ", depth); */ } 
'}' 
  { 
  printf("declaration_de_fonction-> ID ( ) { decl_loc liste_instructions }\n");
  add_to_table(tos, $1, FUNCTION, 0);
} ;

decl_loc:
decl_loc LOCAL ID '=' concatenation ';' { 
  printf("decl_loc-> decl_loc LOCAL ID = concatenation \n");
  add_to_table(tos, $3, IDENTIFIER, 0);

  update_type(tos, $3, STRING);

  quadOP* res= QOcreat(QO_ID,$3,0);
  quads *q=Qcreat(Q_EQUAL,res,$5,NULL);
  Lappend(Lglobal,q);
}
| %empty   { printf("decl_loc-> empty \n");};


appel_de_fonction:
ID liste_operandes  { 
  printf("appel_de_fonction-> ID liste_operandes \n");

  quadOP *fct=QOcreat(QO_FCT,$1,0);
  quads *q2=Qcreat(Q_FCT,fct,NULL,NULL);
  Lappend(Lglobal,q2);

  }
| ID { 
  printf("appel_de_fonction-> ID \n");

  quadOP *fct=QOcreat(QO_FCT,$1,0);
  quads *q2=Qcreat(Q_FCT,fct,NULL,NULL);
  Lappend(Lglobal,q2);
  } ;
 
%%

void yyerror(const char * msg){
    fprintf(stderr, "Erreur syntaxique: %s\n",msg);
}