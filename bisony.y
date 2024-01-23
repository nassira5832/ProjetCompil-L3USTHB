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
%token <Logical> Logical <strVal> CHARACTER <strVal>OPERATOR <strVal>COMPARISON
%token Kw_Program Kw_Begin Kw_End Kw_Routine Kw_ENDR Kw_Integer Kw_Real Kw_Logical Kw_Character 
%token Kw_If Kw_Then Kw_Else Kw_Dowhile Kw_For Kw_EndDo Kw_READ Kw_WRITE Kw_CALL Kw_EQUIVALENCE Kw_DIMENSION 
%token  PO PF AO AF V PV AFF   
%token Kw_EndIf 
%token  or and
 


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
var: IDENTIFIER 
     | mat 
	 | tab ;

mat: IDENTIFIER  Kw_DIMENSION PO INTEGER V INTEGER PF { if($4<=0 || $6<=0) printf("File \"%s\" , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);}
			
tab: IDENTIFIER Kw_DIMENSION PO INTEGER PF  { if($4<=0) printf("File \"%s\" , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);}
    

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
             |IDENTIFIER AFF expression PV  { if(check_declaration($1) != 0){printf("Variable %s non declaree(utilisee a la ligne %d).\n",$1,nb_line-1);YYABORT;} else {/* if(strcmp(get_type($1),"Real")!=0 && !(strcmp(get_type($1),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d . La variable: %s declare commme %s  \n ",nb_line,$1,get_type($1));} else*/ {quadr(":=",tmp3," ",$1);t++;}}}
             |var1 AFF INTEGER PV     { sprintf(buffer, "%d", $3);printf(buffer) }     
			 |IDENTIFIER AFF INTEGER PV { sprintf(buffer, "%d", $3);printf(buffer); if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else {  if(strcmp(get_type($1),"Real")!=0 && !(strcmp(get_type($1),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",buffer," ",$1);t++;}}} 
             |var1 AFF Real PV { sprintf(buffer, "%f", $3);printf(buffer); } 
             |IDENTIFIER AFF Real PV { sprintf(buffer, "%f", $3);printf(buffer); if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else {  if(strcmp(get_type($1),"Real")!=0 && !(strcmp(get_type($1),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",""," ",$1);t++;}}} 
             |var1 AFF var1 PV 
			 |IDENTIFIER AFF IDENTIFIER PV{ if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else {if (check_declaration($3) == 0) {printf("Erreur : identificateur %s non declarer. \n", $3); } else {if(strcmp(get_type($1),get_type($3))==0) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",$3," ",$1);t++;}}}}
             |IDENTIFIER AFF var1 PV
             |var1 AFF CHARACTER PV {strcpy(buffer,$3);  }
             |IDENTIFIER AFF CHARACTER PV{strcpy(buffer,$3); if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else {  if(strcmp(get_type($1),"Real")!=0 && !(strcmp(get_type($1),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",""," ",$1);t++;}}}


 expression:  a OPERATOR var1 expression 
			|a OPERATOR IDENTIFIER expression {if( $3==0 && strcmp("DIV",$2)==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d colonne %d \n ",nb_line);YYABORT;} 
			else {sprintf(tmp,"%s",$3);sprintf(tmp3,"T%d",t);quadr($2,tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;}}
            |a OPERATOR INTEGER expression {if( $3==0 && strcmp("DIV",$2)==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d colonne %d \n ",nb_line);YYABORT;} 
			else {sprintf(tmp,"%d",$3);sprintf(tmp3,"T%d",t);quadr($2,tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;}}
            |a OPERATOR Real expression {if( $3==0.0 && strcmp("DIV",$2)==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d colonne %d \n ",nb_line);YYABORT;} 
			else {sprintf(tmp,"%f",$3);sprintf(tmp3,"T%d",t);quadr($2,tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;}}
            |/*vide*/;
a: var1 | IDENTIFIER{sprintf(tmp2,"%s",$1);} | Real{sprintf(tmp2,"%.2f",$1);sprintf(tmp3,"T%.2f",$1);} |INTEGER {sprintf(tmp2,"%d",$1);sprintf(tmp3,"T%d",$1);}
            
            

			

// pour utiliser les vars

var1: mat1 
	 |tab1;
	
		
mat1: IDENTIFIER  PO INTEGER V INTEGER PF { 
    if (check_declaration($1) == 0) {
        printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", $1);
    }
}
tab1: IDENTIFIER  PO INTEGER PF { 
    
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




/****************************Boucle********************************************/
Boucle: Kw_Dowhile PO CNDs PF inst_list Kw_EndDo;

/**********************l'appel************************************************/
Appelf: var1 AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 
	   |IDENTIFIER AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 


/********************Equivalence*********************************************/
Equivalence: Kw_EQUIVALENCE PO parameter_list PF;




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