
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
     OPERATOR = 263,
     COMPARISON = 264,
     Kw_Program = 265,
     Kw_Begin = 266,
     Kw_End = 267,
     Kw_Routine = 268,
     Kw_ENDR = 269,
     Kw_Integer = 270,
     Kw_Real = 271,
     Kw_Logical = 272,
     Kw_Character = 273,
     Kw_If = 274,
     Kw_Then = 275,
     Kw_Else = 276,
     Kw_Dowhile = 277,
     Kw_For = 278,
     Kw_EndDo = 279,
     Kw_READ = 280,
     Kw_WRITE = 281,
     Kw_CALL = 282,
     Kw_EQUIVALENCE = 283,
     Kw_DIMENSION = 284,
     PO = 285,
     PF = 286,
     AO = 287,
     AF = 288,
     V = 289,
     PV = 290,
     AFF = 291,
     Kw_EndIf = 292,
     or = 293,
     and = 294
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
#line 103 "bisony.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


