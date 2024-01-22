
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER = 259,
     Real = 260,
     Logical = 261,
     CHARACTER = 262,
     Kw_Program = 263,
     Kw_Begin = 264,
     Kw_End = 265,
     Kw_Routine = 266,
     Kw_ENDR = 267,
     Kw_Integer = 268,
     Kw_Real = 269,
     Kw_Logical = 270,
     Kw_Character = 271,
     Kw_If = 272,
     Kw_Then = 273,
     Kw_Else = 274,
     Kw_Dowhile = 275,
     Kw_For = 276,
     Kw_EndDo = 277,
     Kw_READ = 278,
     Kw_WRITE = 279,
     Kw_CALL = 280,
     Kw_EQUIVALENCE = 281,
     Kw_DIMENSION = 282,
     PO = 283,
     PF = 284,
     AO = 285,
     AF = 286,
     V = 287,
     PV = 288,
     AFF = 289,
     ADD = 290,
     DIV = 291,
     MUL = 292,
     SOUS = 293,
     Kw_EndIf = 294,
     or = 295,
     and = 296,
     EQ = 297,
     NE = 298,
     LT = 299,
     LE = 300,
     GE = 301,
     GL = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 22 "bisony.y"

#include<stdbool.h>
    int INTEGER;
    float Real;
	char* strVal;
	bool Logical ; 
	
	



/* Line 1676 of yacc.c  */
#line 111 "bisony.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


