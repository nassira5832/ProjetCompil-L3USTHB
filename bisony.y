%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int yylex(void);
int qc =0 ; 
int yywrap(void);
int nb_line = 1 , col = 1 ; 
char* current_variable_name = NULL;
char tmp[20],tmp2[20],tmp3[20],type[20],tmp4[20],tmp6[20],tmp7[20];
char* f; 
char buffer[20];
char save_type[20];
int t=0;



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
%token  or and
%token EQ NE LT LE GE GL 


%start S

%left '+' '-'
%left '*' '/'

%%
  
S:  fonctions main_program 
                     {printf("syntax correct\n"); 
					 YYACCEPT;
					 }
{strcpy(save_type,"CHARACTER");};


/*******************Fonction****************************/

fonctions: fonction 
		  |fonctions  fonction;

fonction: TYPE Kw_Routine IDENTIFIER PO parameter_list PF declarations inst_list affectation  Kw_ENDR {strcpy(save_type,"CHARACTER");}
         {  if (check_declaration($3) == 0) {
              printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3); }
         }

/////////la liste des parametres /////////////////      
parameter_list: var V parameter_list
				| var;
 /////////Les types ////////////////////////////
TYPE: Kw_Real  {strcpy(save_type,"Real");}
     | Kw_Logical  {strcpy(save_type,"Logical");}
	 | Kw_Character {strcpy(save_type,"CHARACTER");}
	 | Kw_Integer {strcpy(save_type,"INTEGER");};
///////Declarations ///////////////////////////
declarations: TYPE var declaration_2 |TYPE var declaration_2 declarations
   
declaration_2: V var declaration_2 
              | PV;


/******************************Main programme ***********************************************/
main_program: Kw_Program IDENTIFIER  declarations inst_list Kw_End {strcpy(save_type,"CHARACTER");};
inst_list: instruction
           | inst_list instruction ;


instruction: affectation
			| Entrees
			| Sorties 
			| Condition 
			| Boucle 
			| Appelf 
			| Equivalence;

///////////affecation////////////////////////
affectation: var1 AFF expression PV 
             |IDENTIFIER AFF expression PV 
			 |var1 AFF Const PV         
			 |IDENTIFIER AFF Const PV 
             |var1 AFF var1 PV 
			 |IDENTIFIER AFF IDENTIFIER PV
             |IDENTIFIER AFF var1 PV
              
			 
           
          

expression: var1 OPERATOR var1
			|IDENTIFIER OPERATOR IDENTIFIER 
            |Logical
			|var1 OPERATOR IDENTIFIER
			|IDENTIFIER OPERATOR var1 
			 
var: IDENTIFIER 
     | mat 
	 | tab ;

mat: IDENTIFIER  Kw_DIMENSION PO INTEGER V INTEGER PF { 
    
			{ if($4<=0 || $6<=0) printf("File \"%s\" , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);}}
			
tab: IDENTIFIER Kw_DIMENSION PO INTEGER PF { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
			{ if($4<=0) printf("File \"%s\" , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);}

}
            
               
        

// pour utiliser les vars

var1: mat1 
	 |tab1;
	
Const : INTEGER { sprintf(buffer, "%d", $1);printf(buffer) } 
      | CHARACTER  { sprintf(buffer,"%s",$1);printf(buffer)}
      | Real { sprintf(buffer, "%f", $1);printf(buffer) } 
		
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


/////////////////entrees//////////////////////////////////
Entrees: Kw_READ PO IDENTIFIER PF PV { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $3);
    }
}


//////////////Sortie////////////////////////////////////
Sorties: Kw_WRITE PO message PF PV ;

message: CHARACTER message_suffix 
		| IDENTIFIER message_suffix 

message_suffix: V IDENTIFIER message_suffix 
				| CHARACTER message_suffix
				| /* vide */;





/*************************************** Condition**************************/
Condition: Kw_If PO CNDs PF Kw_Then inst_list Kw_Else inst_list Kw_EndIf;
CND: or  CNDs 
    |and CNDs 
    |/*vide*/;
CNDs: var1 COMPARISON var1 CND
| expression COMPARISON expression CND
| var1 COMPARISON expression CND
| expression COMPARISON var1 CND
| IDENTIFIER COMPARISON IDENTIFIER CND
| IDENTIFIER COMPARISON var1 CND
| IDENTIFIER COMPARISON expression CND
| expression COMPARISON IDENTIFIER CND
| var1 COMPARISON IDENTIFIER CND
|Logical

COMPARISON: EQ
		   |NE
		   |LT
		   |LE
		   |GE
		   |GL;


/****************************Boucle********************************************/
Boucle: Kw_Dowhile PO CNDs PF inst_list Kw_EndDo;

/**********************l'appel************************************************/
Appelf: var1 AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 
	   |IDENTIFIER AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 


/********************Equivalence*********************************************/
Equivalence: Kw_EQUIVALENCE PO parameter_list PF;




OPERATOR : DIV 
		  |ADD
		  |SOUS
		  |MUL;

%%
main () 
{
    yyparse();
    print();
	print_quad();
}
yywrap(){}

yyerror(char* msg)
{
    printf("Erreur syntaxique a la ligne %d \n", nb_line);
}