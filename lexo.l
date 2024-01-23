%{
#include "bisony.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h" 
#include "quad.h"

extern int nb_line;
extern int col;
extern YYSTYPE yylval;
extern char save_type[20];
extern char buffer[20];


%}

IDENTIFIER [a-zA-Z]([a-zA-Z]|[0-9])*
INTEGER   [-]?([1-9][0-9]*|0)
Real  [-]?{INTEGER}"."([1-9][0-9]*|0)  
CHARACTER \"([^"]*)\"
Logical   (true|false)

%%

PROGRAM { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_Program; }
begin { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_Begin;}
END   { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_End;}
Routine  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_Routine;}
ENDR  {insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_ENDR;}
INTEGER  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_Integer;}
REAL  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_Real;}
Logical  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_Logical;}
CHARACTER { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_Character;}
If    { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_If; }

Then   { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_Then;}
Else   { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_Else;}
DoWhile  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_Dowhile;}
For { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext); return Kw_For;}
EndIf  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_EndIf;}
EndDo  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_EndDo;}
READ  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_READ; }
WRITE  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_WRITE ;}
CALL  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_CALL; }
EQUIVALENCE  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_EQUIVALENCE ; }
DIMENSION  { insertKw(yytext, "KW"); yylval.strVal = strdup(yytext);return Kw_DIMENSION ;}

{Logical} return Logical;

{IDENTIFIER} {
    // Vérifier la longueur de l'identificateur
    if (yyleng > 10) {
        printf("L'identificateur %s dans la ligne %d est trop grand !\n", yytext, nb_line);
    } else {
        // Insérer l'identificateur dans la table des identificateurs
        
         insertIdfCst(yytext, "idf", save_type, buffer);
        yylval.strVal = strdup(yytext);
        return IDENTIFIER;
    }
}
{INTEGER} {
    yylval.INTEGER = atoi(yytext);
    if (yylval.INTEGER < -32768 || yylval.INTEGER > 32767) {
        printf("Erreur : Valeur entière hors de la plage autorisée dans la ligne %d : %s\n", nb_line, yytext);
    } else {
        return INTEGER;
    }
}

{Real} {
    yylval.Real = atof(yytext);
    if (yylval.Real < -32768.32768 || yylval.Real > 32767.32767) {
        printf("Erreur : Valeur réelle hors de la plage autorisée dans la ligne %d : %s\n", nb_line, yytext);
    } else {
        return Real;
    }
}

{CHARACTER}  return CHARACTER ;



";" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return PV;}
"=" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return AFF;}
"," { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return V ;}
"+" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return ADD ;}
"-" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return SOUS;}
"*" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return MUL;}
"/" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return DIV;}
"(" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return PO;}
")" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return PF; }
"{" { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext);return AO;} 
.OR. { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return or; }
.AND. { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return and; }
.EQ. {insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return EQ ;}
.NE. { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return NE ;} 
.LT. { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return LT ;}
.LE. {insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return LE;}
.GE. { insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return GE;} 
.GL. {insertSepKw(yytext, "Sep"); yylval.strVal = strdup(yytext); return GL;}
"%"[^\n]*\n  /* Commentaire */ 
[ \t]

\n			nb_line++;
.			{printf ("erreur lexicale: entite non reconnue a la ligne %d\n",nb_line);}


%%