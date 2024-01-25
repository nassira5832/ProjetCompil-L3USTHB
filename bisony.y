%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int yylex(void);
int qc =0 ; 
int yywrap(void);
int nb_line = 1 , col = 1 ; 
char* current_variable_name = NULL;
char tmp[20],tmp2[20],tmp3[20],tmp5[20],tmp4[20],tmp6[20],tmp7[20],tmp8[20],tmp9[20], type[20];
char* f; 
char buffer[20];
char save_type[20];
int t=0;
char Tailledeux[20], Tailletab[20], Tailleun[20]; 
int end_if=0, begin_else=0, begin;

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

mat: IDENTIFIER  Kw_DIMENSION PO INTEGER V INTEGER PF{ 
    if($4<=0 || $6<=0) printf("File %s , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);
         else {sprintf(Tailleun,"%d",$4);sprintf(Tailledeux,"%d",$6);
         sprintf(tmp7,"%d",$4);
         sprintf(tmp6,"%d",$4);
          quadr("BOUNDS",tmp7,tmp6,"");
          quadr("ADEC",$1,"","");
         t++;
        }}
			
tab: IDENTIFIER Kw_DIMENSION PO INTEGER PF { 
    if($4<=0) printf("File %s , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);
         else {sprintf(Tailletab,"%d",$4);
               sprintf(tmp7,"%d",$4);
               quadr("BOUNDS",tmp7,"","");
               quadr("ADEC",$1,"","");
               t++;
            }}
    

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


affectation: var1 AFF expression PV  {/* if(!(strcmp(type,"INTEGER")==0) && !(strcmp(type,"Real")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else */ { quadr(":=",tmp3," ",tmp8);t++;}} 
             |IDENTIFIER AFF expression PV  { if(check_declaration($1) == 0){printf("Variable %s non declaree(utilisee a la ligne %d).\n",$1,nb_line-1);YYABORT;} else /*{if(strcmp(get_type($1),"REAL")!=0 && !(strcmp(get_type($1),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d . La variable: %s declare commme %s  \n ",nb_line,$1,get_type($1));} else*/ {quadr(":=",tmp3," ",$1);t++;}}//}
             |var1 AFF INTEGER PV     { sprintf(buffer, "%d", $3); /*if(!(strcmp(type,"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else*/ { quadr(":=",buffer," ",tmp8);t++;}} 
			 |IDENTIFIER AFF INTEGER PV { sprintf(buffer, "%d", $3); if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else/* {  if( !(strcmp(get_type($1),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);printf(get_type($1));} else*/ { quadr(":=",buffer," ",$1);t++;}}//} 
             |var1 AFF Real PV  { sprintf(buffer, "%f", $3); /*if(!(strcmp(type,"Real")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else*/ { quadr(":=",buffer," ",tmp8);t++;}}  
             |IDENTIFIER AFF Real PV { sprintf(buffer, "%f", $3); if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else {  /*if(strcmp(get_type($1),"REAL")!=0 ) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d  \n ",nb_line); printf(get_type($1));} else*/ { quadr(":=",buffer," ",$1);t++;}}} 
             |var1 AFF var1 PV { quadr(":=",tmp8," ",tmp8);t++;}
			 |IDENTIFIER AFF IDENTIFIER PV{ if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else {if (check_declaration($3) == 0) {printf("Erreur : identificateur %s non declarer. \n", $3); } else {/*if(strcmp(get_type($1),get_type($3))==0) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else*/ { quadr(":=",$3," ",$1);t++;}}}}
             |IDENTIFIER AFF var1 PV { if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else { /* if(strcmp(get_type($1),type)!=0 ) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else*/ { quadr(":=",tmp8," ",$1);t++;}}} 
             |var1 AFF CHARACTER PV  { sprintf(buffer, "%s", $3); /*if(!(strcmp(type,"CHARACTER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else*/ { quadr(":=",buffer," ",tmp8);t++;}}  
             |IDENTIFIER AFF CHARACTER PV{strcpy(buffer,$3); if (check_declaration($1) == 0) {printf("Erreur : identificateur %s non declarer. \n", $1); } else {  /*if(strcmp(get_type($1),"CHARACTER")!=0) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else */{ quadr(":=",""," ",$1);t++;}}}


 expression:  a OPERATOR var1 expression 
			|a OPERATOR IDENTIFIER expression {if( $3==0 && strcmp("/",$2)==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d  \n ",nb_line);/*YYABORT;*/} 
			else {sprintf(tmp,"%s",$3);sprintf(tmp3,"T%d",t);quadr($2,tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;}}
            |a OPERATOR INTEGER expression {if( $3==0 && strcmp("/",$2)==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d  \n ",nb_line);/*YYABORT;*/} 
			else {sprintf(tmp,"%d",$3);sprintf(tmp3,"T%d",t);quadr($2,tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;}}
            |a OPERATOR Real expression {if( $3==0.0 && strcmp("/",$2)==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d  \n ",nb_line);YYABORT;} 
			else {sprintf(tmp,"%f",$3);sprintf(tmp3,"T%d",t);quadr($2,tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;}}
            |/*vide*/;

a: var1 | IDENTIFIER{sprintf(tmp2,"%s",$1);} | Real{sprintf(tmp2,"%.2f",$1);sprintf(tmp3,"T%.2f",$1);} |INTEGER {sprintf(tmp2,"%d",$1);sprintf(tmp3,"T%d",$1);}
            
            

			

// pour utiliser les vars

var1: IDENTIFIER  PO INTEGER PF { if (check_declaration($1) == 0) { printf("Erreur : L'identificateur %s non declaree.\n", $1);}else {if ($3>=atoi(Tailletab)){printf("Dépassement de la taille du tableau %s",$1);} else {/*strcpy(type,get_type($1));*/sprintf(tmp8,"%s",$1);}}}
     | IDENTIFIER  PO INTEGER V INTEGER PF {  if (check_declaration($1) == 0) {printf("Erreur : L'identificateur %s non declaree.\n", $1);}else {if ($3>=atoi(Tailleun) || $5>=atoi(Tailledeux)){printf("Dépassement de la taille du matrice %s",$1);}else {/*strcpy(type,get_type($1));*/sprintf(tmp8,"%s",$1);}}}




/////////////////entrees//////////////////////////////////

Entrees: Kw_READ PO IDENTIFIER PF PV { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration($3) == 0) {
        printf("Erreur : L'identificateur %s non declaree.\n", $3);
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
Condition:  B Kw_Else inst_list Kw_EndIf {  sprintf(tmp,"%d",t);  
                              update_quad(end_if,1,tmp);
                               };
B: A inst_list { end_if=t;
                   quadr("BR", "","empty", "empty"); 
				   sprintf(tmp,"%d",t+1);
                   update_quad(begin_else,1,tmp);
                   t++;}
A:Kw_If PO CNDs PF Kw_Then

CND: or  CNDs 
    |and CNDs 
    |/*vide*/;
CNDs: var1 COMPARISON a CND
{begin_else=t;
if (strcmp($2,".EQ.")==0) strcpy(tmp5,"BNE");
if (strcmp($2,".LT.")==0) strcpy(tmp5,"BGE");
if (strcmp($2,".GT.")==0) strcpy(tmp5,"BLE");
if (strcmp($2,".LE.")==0) strcpy(tmp5,"BG");
if (strcmp($2,".GE.")==0) strcpy(tmp5,"BL");
if (strcmp($2,".NE.")==0) strcpy(tmp5,"BE");
 sprintf(tmp9,"%d",end_if);
 quadr(tmp5,"",tmp8,tmp2);t++;}
     |IDENTIFIER COMPARISON a CND
      {begin_else=t;
if (strcmp($2,".EQ.")==0) strcpy(tmp5,"BNE");
if (strcmp($2,".LT.")==0) strcpy(tmp5,"BGE");
if (strcmp($2,".GT.")==0) strcpy(tmp5,"BLE");
if (strcmp($2,".LE.")==0) strcpy(tmp5,"BG");
if (strcmp($2,".GE.")==0) strcpy(tmp5,"BL");
if (strcmp($2,".NE.")==0) strcpy(tmp5,"BE");
 sprintf(tmp9,"%d",end_if);
 quadr(tmp5,"",$1,tmp2);t++;}

     |expression COMPARISON a CND 
     {begin_else=t;
if (strcmp($2,".EQ.")==0) strcpy(tmp5,"BNE");
if (strcmp($2,".LT.")==0) strcpy(tmp5,"BGE");
if (strcmp($2,".GT.")==0) strcpy(tmp5,"BLE");
if (strcmp($2,".LE.")==0) strcpy(tmp5,"BG");
if (strcmp($2,".GE.")==0) strcpy(tmp5,"BL");
if (strcmp($2,".NE.")==0) strcpy(tmp5,"BE");
 sprintf(tmp9,"%d",end_if);
 quadr(tmp5,"",tmp3,tmp2);t++;}
     |expression COMPARISON expression CND
     {begin_else=t;
if (strcmp($2,".EQ.")==0) strcpy(tmp5,"BNE");
if (strcmp($2,".LT.")==0) strcpy(tmp5,"BGE");
if (strcmp($2,".GT.")==0) strcpy(tmp5,"BLE");
if (strcmp($2,".LE.")==0) strcpy(tmp5,"BG");
if (strcmp($2,".GE.")==0) strcpy(tmp5,"BL");
if (strcmp($2,".NE.")==0) strcpy(tmp5,"BE");
 sprintf(tmp9,"%d",end_if);
 quadr(tmp5,"",tmp3,tmp3);t++;}
     |var1 COMPARISON expression CND
     {begin_else=t;
if (strcmp($2,".EQ.")==0) strcpy(tmp5,"BNE");
if (strcmp($2,".LT.")==0) strcpy(tmp5,"BGE");
if (strcmp($2,".GT.")==0) strcpy(tmp5,"BLE");
if (strcmp($2,".LE.")==0) strcpy(tmp5,"BG");
if (strcmp($2,".GE.")==0) strcpy(tmp5,"BL");
if (strcmp($2,".NE.")==0) strcpy(tmp5,"BE");
 sprintf(tmp9,"%d",end_if);
 quadr(tmp5,"",tmp8,tmp3);t++;}
     |IDENTIFIER COMPARISON expression CND
{begin_else=t;
if (strcmp($2,".EQ.")==0) strcpy(tmp5,"BNE");
if (strcmp($2,".LT.")==0) strcpy(tmp5,"BGE");
if (strcmp($2,".GT.")==0) strcpy(tmp5,"BLE");
if (strcmp($2,".LE.")==0) strcpy(tmp5,"BG");
if (strcmp($2,".GE.")==0) strcpy(tmp5,"BL");
if (strcmp($2,".NE.")==0) strcpy(tmp5,"BE");
 
 quadr(tmp5,"",$1,tmp3);t++;}

/****************************Boucle********************************************/
Boucle: D Kw_EndDo  
D: C inst_list { end_if=t;
                   sprintf(tmp,"%d",t-2);
                   quadr("BR", tmp,"empty", "empty"); 
				   sprintf(tmp,"%d",t+1);
                   update_quad(begin_else,1,tmp);
                   t++;}

C:  Kw_Dowhile PO CNDs PF




/**********************l'appel************************************************/
Appelf: var1 AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 
	   |IDENTIFIER AFF Kw_CALL IDENTIFIER PO parameter_list PF PV 






/********************Equivalence************************************************/
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