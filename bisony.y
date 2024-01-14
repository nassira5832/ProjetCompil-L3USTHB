%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int yylex(void);

int yywrap(void);
int nb_line = 1 , col = 1 ; 
char* current_variable_name = NULL;

char* f; 
char buffer[200] ;
char save_type[20];




%}

%union {
#include<stdbool.h>
    int INTEGER;
    float Real;
	char* strVal;
	bool Logical ; 
	
	
}

%token <strVal> IDENTIFIER
%token <INTEGER> INTEGER
%token  <Real> Real
%token <Logical> Logical <strVal> CHARACTER
%token Kw_Program Kw_Begin Kw_End Kw_Routine Kw_ENDR Kw_Integer Kw_Real Kw_Logical Kw_Character
%token Kw_If Kw_Then Kw_Else Kw_Dowhile Kw_For Kw_EndDo Kw_READ Kw_WRITE Kw_CALL Kw_EQUIVALENCE Kw_DIMENSION 
%token  PO PF AO AF V PV AFF   ADD DIV MUL SOUS  
%token Kw_EndIf 
%token  OR AND
%token EQ NE LT LE GE GL 


%start S

%left '+' '-'
%left '*' '/'
%left LE GL LT GE EQ NE
%%
  
S:  fonctions main_program 
                     {printf("syntax correct\n"); 
					 YYACCEPT;
					 }
{strcpy(save_type,"CHARACTER");};
main_program: Kw_Program IDENTIFIER  declarations inst_list Kw_End {strcpy(save_type,"CHARACTER");};
fonctions: fonction 
		  |fonctions  fonction;

fonction: TYPE Kw_Routine IDENTIFIER PO parameter_list PF declarations inst_list affectation  Kw_ENDR {strcpy(save_type,"CHARACTER");}
         { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
parameter_list: var V parameter_list
				| var;

TYPE: Kw_Real  {strcpy(save_type,"Real");}
     | Kw_Logical  {strcpy(save_type,"Logical");}
	 | Kw_Character {strcpy(save_type,"CHARACTER");}
	 | Kw_Integer {strcpy(save_type,"INTEGER");};

declarations: TYPE var declaration_2 |TYPE var declaration_2 declarations
   
declaration_2: V var declaration_2 
              | PV;

inst_list: instruction
           | inst_list  instruction ;


instruction: affectation
			| Entrees
			| Sorties 
			| Condition 
			| Boucle 
			| Appelf 
			| Equivalence;

affectation: var1 AFF expression PV 
             |IDENTIFIER AFF expression PV { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
			 |var1 AFF var1 PV 
			 |IDENTIFIER AFF IDENTIFIER PV
			 { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
			 |IDENTIFIER AFF var1 PV
			 { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
			 |var1 AFF Const PV         
			 |IDENTIFIER AFF Const PV  
			 
           
          

expression: var1 OPERATOR var1
			|IDENTIFIER OPERATOR IDENTIFIER  
			{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
            |Logical
			| var1 OPERATOR IDENTIFIER
			{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
            | IDENTIFIER OPERATOR var1 
			{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
		    
//var pour declarer 
var: IDENTIFIER { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
     | mat 
	 | tab ;

mat: IDENTIFIER  Kw_DIMENSION PO INTEGER V INTEGER PF { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
			{ if($4<=0 || $6<=0) printf("File \"%s\" , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);}
			
tab: IDENTIFIER Kw_DIMENSION PO INTEGER PF { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
          
			{ if($4<=0) printf("File \"%s\" , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);}
            
               
        

// pour utiliser les vars

var1: mat1 
	 |tab1;
	
Const : INTEGER   // { sprintf(buffer, "%d", $1); printf(buffer) }
      | CHARACTER // { strcpy(buffer,$1); printf(buffer) }
      | Real      // { sprintf(buffer, "%f", $1);printf(buffer) } 


		
mat1: IDENTIFIER  PO INTEGER V INTEGER PF { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
tab1: IDENTIFIER  PO INTEGER PF { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
Entrees: Kw_READ PO IDENTIFIER PF PV { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}

Sorties: Kw_WRITE PO message PF PV ;

message: CHARACTER message_suffix 
		| IDENTIFIER message_suffix { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}

message_suffix: V IDENTIFIER message_suffix 
{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($2) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $2);
    }
}
				| CHARACTER message_suffix
				| /* vide */;

Condition: Kw_If PO CND PF Kw_Then inst_list Kw_Else inst_list Kw_EndIf;

CND: var1 COMPARISON var1
	| exp COMPARISON exp
	| var1 COMPARISON exp
	| exp COMPARISON var1 
	| IDENTIFIER COMPARISON IDENTIFIER
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
    | IDENTIFIER COMPARISON var1
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
	| IDENTIFIER COMPARISON exp
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
	|exp COMPARISON IDENTIFIER
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
    |var1 COMPARISON IDENTIFIER
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
	|Logical;
	
exp: var1 OR var1 
	|exp OR var1 
	|IDENTIFIER OR IDENTIFIER 
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
	|exp OR IDENTIFIER
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
	|var1 AND var1 
	|exp AND var1
	|IDENTIFIER AND IDENTIFIER 
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}
	|exp AND IDENTIFIER
	{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}

Boucle: Kw_Dowhile PO CND PF inst_list Kw_EndDo;

Appelf: var1 AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 
{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($4) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $4);
    }
}
		|IDENTIFIER AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 
		{ 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}

Equivalence: Kw_EQUIVALENCE PO parameter_list PF;

OPERATOR : DIV 
		  |ADD
		  |SOUS
		  |MUL;
COMPARISON: EQ
		   |NE
		   |LT
		   |LE
		   |GE
		   |GL;

%%
main () 
{
    yyparse();
    print();
}
yywrap(){}

yyerror(char* msg)
{
    printf("Erreur syntaxique a la ligne %d \n", nb_line);
}