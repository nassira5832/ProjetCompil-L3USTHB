
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "bisony.y"

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
int end_if=0, begin_else=0;



/* Line 189 of yacc.c  */
#line 95 "bisony.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 22 "bisony.y"

#include<stdbool.h>
    int INTEGER;
    float Real;
	char* strVal;
	bool Logical ; 
	
	



/* Line 214 of yacc.c  */
#line 182 "bisony.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 194 "bisony.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    42,    40,     2,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,    10,    13,    14,    26,    30,
      32,    34,    36,    38,    40,    44,    49,    53,    55,    57,
      59,    61,    69,    75,    81,    83,    86,    88,    90,    92,
      94,    96,    98,   100,   105,   110,   115,   120,   125,   130,
     135,   140,   145,   150,   155,   160,   165,   170,   175,   176,
     178,   180,   182,   184,   189,   196,   202,   208,   211,   214,
     218,   221,   222,   227,   230,   236,   239,   242,   243,   248,
     253,   258,   263,   268,   273,   278,   283,   288,   293,   295,
     302,   311,   320
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,    47,    57,    46,    -1,    48,    -1,
      47,    48,    -1,    -1,    51,    13,     3,    30,    50,    31,
      52,    58,    60,    14,    49,    -1,    54,    34,    50,    -1,
      54,    -1,    16,    -1,    17,    -1,    18,    -1,    15,    -1,
      51,    54,    53,    -1,    51,    54,    53,    52,    -1,    34,
      54,    53,    -1,    35,    -1,     3,    -1,    55,    -1,    56,
      -1,     3,    29,    30,     4,    34,     4,    31,    -1,     3,
      29,    30,     4,    31,    -1,    10,     3,    52,    58,    12,
      -1,    59,    -1,    58,    59,    -1,    60,    -1,    64,    -1,
      65,    -1,    68,    -1,    73,    -1,    74,    -1,    75,    -1,
      63,    36,    61,    35,    -1,     3,    36,    61,    35,    -1,
      63,    36,     4,    35,    -1,     3,    36,     4,    35,    -1,
      63,    36,     5,    35,    -1,     3,    36,     5,    35,    -1,
      63,    36,    63,    35,    -1,     3,    36,     3,    35,    -1,
       3,    36,    63,    35,    -1,    63,    36,     7,    35,    -1,
       3,    36,     7,    35,    -1,    62,     8,    63,    61,    -1,
      62,     8,     3,    61,    -1,    62,     8,     4,    61,    -1,
      62,     8,     5,    61,    -1,    -1,    63,    -1,     3,    -1,
       5,    -1,     4,    -1,     3,    30,     4,    31,    -1,     3,
      30,     4,    34,     4,    31,    -1,    25,    30,     3,    31,
      35,    -1,    26,    30,    66,    31,    35,    -1,     7,    67,
      -1,     3,    67,    -1,    34,     3,    67,    -1,     7,    67,
      -1,    -1,    69,    21,    58,    37,    -1,    70,    58,    -1,
      19,    30,    72,    31,    20,    -1,    38,    72,    -1,    39,
      72,    -1,    -1,    63,     9,    63,    71,    -1,    61,     9,
      61,    71,    -1,    63,     9,    61,    71,    -1,    61,     9,
      63,    71,    -1,     3,     9,     3,    71,    -1,     3,     9,
       4,    71,    -1,     3,     9,    63,    71,    -1,     3,     9,
      61,    71,    -1,    61,     9,     3,    71,    -1,    63,     9,
       3,    71,    -1,     6,    -1,    22,    30,    72,    31,    58,
      24,    -1,    63,    36,    27,     3,    30,    50,    31,    35,
      -1,     3,    36,    27,     3,    30,    50,    31,    35,    -1,
      28,    30,    50,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    51,    60,    61,    63,    63,    69,    70,
      72,    73,    74,    75,    77,    77,    79,    80,    81,    82,
      83,    85,    95,   106,   107,   108,   111,   112,   113,   114,
     115,   116,   117,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   138,   139,   141,   143,   145,   147,
     147,   147,   147,   155,   156,   163,   174,   176,   177,   179,
     180,   181,   188,   190,   194,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   214,   215,   216,   217,   218,   221,
     227,   228,   236
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "Real",
  "Logical", "CHARACTER", "OPERATOR", "COMPARISON", "Kw_Program",
  "Kw_Begin", "Kw_End", "Kw_Routine", "Kw_ENDR", "Kw_Integer", "Kw_Real",
  "Kw_Logical", "Kw_Character", "Kw_If", "Kw_Then", "Kw_Else",
  "Kw_Dowhile", "Kw_For", "Kw_EndDo", "Kw_READ", "Kw_WRITE", "Kw_CALL",
  "Kw_EQUIVALENCE", "Kw_DIMENSION", "PO", "PF", "AO", "AF", "V", "PV",
  "AFF", "Kw_EndIf", "or", "and", "'+'", "'-'", "'*'", "'/'", "$accept",
  "S", "$@1", "fonctions", "fonction", "$@2", "parameter_list", "TYPE",
  "declarations", "declaration_2", "var", "mat", "tab", "main_program",
  "inst_list", "instruction", "affectation", "expression", "a", "var1",
  "Entrees", "Sorties", "message", "message_suffix", "Condition", "B", "A",
  "CND", "CNDs", "Boucle", "Appelf", "Equivalence", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      43,    45,    42,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    47,    47,    49,    48,    50,    50,
      51,    51,    51,    51,    52,    52,    53,    53,    54,    54,
      54,    55,    56,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    63,    63,    64,    65,    66,    66,    67,
      67,    67,    68,    69,    70,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    74,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     2,     0,    11,     3,     1,
       1,     1,     1,     1,     3,     4,     3,     1,     1,     1,
       1,     7,     5,     5,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     1,
       1,     1,     1,     4,     6,     5,     5,     2,     2,     3,
       2,     0,     4,     2,     5,     2,     2,     0,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     1,     6,
       8,     8,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    10,    11,    12,     0,     0,     4,     0,     1,
       0,     5,     2,     0,     0,     3,     0,     0,     0,     0,
      18,     0,    19,    20,     0,     0,     0,     0,     0,     0,
       0,    24,    26,     0,    27,    28,    29,     0,     0,    30,
      31,    32,     0,     9,     0,     0,    17,    14,     0,    48,
      48,    48,     0,     0,     0,    23,    25,    48,     0,    63,
       0,     0,     0,     0,    15,     0,    50,    52,    51,     0,
       0,     0,     0,    49,    50,    52,    51,    78,     0,    49,
       0,     0,     0,    61,    61,     0,     0,    50,    52,    51,
       0,     0,     0,    49,     0,     0,     8,     0,    16,    53,
       0,    40,    36,    38,    43,     0,    34,     0,    41,    48,
      48,    48,     0,     0,     0,    61,     0,    58,    57,     0,
      82,    35,    37,    42,     0,    33,    39,    62,     0,    22,
       0,     0,     0,    48,    48,    48,    48,    50,    52,    67,
      49,    50,    67,    49,    50,    67,    49,    64,     0,    55,
      60,    61,    56,     0,    26,     0,    54,     0,    45,    49,
      46,    47,    44,    48,    48,    72,    73,    75,    74,    76,
      69,    71,    77,    70,    68,    79,    59,     0,     6,    21,
       0,    65,    66,     0,     7,    81,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    15,     6,     7,   184,    42,    17,    18,    47,
      43,    22,    23,    12,    30,    31,    32,    78,    72,    33,
      34,    35,    85,   117,    36,    37,    38,   165,    80,    39,
      40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     110,   -80,   -80,   -80,   -80,    12,   129,   -80,     8,   -80,
      34,   -80,   -80,    72,   110,   -80,    23,    76,    52,    76,
      54,   126,   -80,   -80,   -10,    59,    67,    78,    87,    93,
      22,   -80,   -80,   128,   -80,   -80,   -80,    74,    52,   -80,
     -80,   -80,   134,   132,   138,    76,   -80,   110,   163,    97,
     137,   137,   166,    66,    76,   -80,   -80,   102,    52,    52,
     110,    76,   167,   126,   -80,    50,    35,   135,   139,   140,
     169,   141,   165,   142,    19,   -80,   -80,   -80,   170,   171,
     147,   150,   152,     6,     6,   153,   155,   157,   156,   158,
     159,   179,   160,   161,     5,    52,   -80,    65,   -80,   -80,
     181,   -80,   -80,   -80,   -80,   162,   -80,   107,   -80,   145,
     148,   151,   168,    52,   164,     6,   186,   -80,   -80,   172,
     -80,   -80,   -80,   -80,   173,   -80,   -80,   -80,    52,   -80,
     193,   174,    76,    13,   154,   154,   154,    83,   -16,   124,
     -16,    83,   124,   -16,    83,   124,   -16,   -80,    32,   -80,
     -80,     6,   -80,    76,   176,   175,   -80,   177,   -80,   -80,
     -80,   -80,   -80,   137,   137,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   178,   -80,   -80,
     180,   -80,   -80,   182,   -80,   -80,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   192,   -80,   -50,    46,   -15,   149,
      -7,   -80,   -80,   -80,   -19,   -30,    73,   -43,   -80,   -48,
     -80,   -80,   -80,   -79,   -80,   -80,   -80,    -8,   -44,   -80,
     -80,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -68
static const yytype_int16 yytable[] =
{
      56,    73,    79,    79,    86,   118,    71,    81,    24,    93,
      21,    96,     9,   115,    92,   -67,    87,    75,    76,    59,
      48,    13,   163,   164,    25,    24,    49,    26,   109,    56,
      27,    28,    64,    29,    55,    24,   150,    14,    63,    94,
     116,    25,   127,    48,    26,    95,     8,    27,    28,    48,
      29,    25,     8,    19,    26,    24,   175,    27,    28,   136,
      29,   140,   143,   146,    56,    48,   139,   142,   145,    83,
     101,    25,   176,    84,    26,    16,   128,    27,    28,    20,
      29,    99,   157,    44,   100,   159,   159,   159,   159,    50,
     158,   160,   161,   162,   148,    58,   129,    51,    56,   130,
      66,    67,    68,   177,    69,    87,    88,    89,    52,    90,
     133,   134,   135,    48,   -67,    79,    79,    53,    56,   181,
     182,   163,   164,    54,    70,     1,     2,     3,     4,    91,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    10,
      74,    75,    76,    77,     1,     2,     3,     4,   137,   138,
      76,   141,    75,    76,   144,    75,    76,    87,    75,    76,
      45,    46,   163,   164,    57,    60,    61,    65,    62,    82,
     102,    97,   105,   107,   103,   104,   106,   108,   112,   110,
     111,   113,   124,   114,   119,   131,   120,    48,   147,   151,
     178,   121,   132,   122,   123,   125,   126,   155,    11,   149,
       0,   154,     0,   153,     0,   156,   179,   152,   180,   183,
       0,     0,    98,     0,     0,   185,     0,   186
};

static const yytype_int16 yycheck[] =
{
      30,    49,    50,    51,    54,    84,    49,    51,     3,    57,
      17,    61,     0,     7,    57,    31,     3,     4,     5,    38,
      30,    13,    38,    39,    19,     3,    36,    22,     9,    59,
      25,    26,    47,    28,    12,     3,   115,     3,    45,    58,
      34,    19,    37,    30,    22,    60,     0,    25,    26,    30,
      28,    19,     6,    30,    22,     3,    24,    25,    26,   107,
      28,   109,   110,   111,    94,    30,   109,   110,   111,     3,
      35,    19,   151,     7,    22,     3,    95,    25,    26,     3,
      28,    31,   132,    29,    34,   133,   134,   135,   136,    30,
     133,   134,   135,   136,   113,    21,    31,    30,   128,    34,
       3,     4,     5,   153,     7,     3,     4,     5,    30,     7,
       3,     4,     5,    30,    31,   163,   164,    30,   148,   163,
     164,    38,    39,    30,    27,    15,    16,    17,    18,    27,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    10,
       3,     4,     5,     6,    15,    16,    17,    18,     3,     4,
       5,     3,     4,     5,     3,     4,     5,     3,     4,     5,
      34,    35,    38,    39,    36,    31,    34,     4,    30,     3,
      35,     4,     3,     8,    35,    35,    35,    35,    31,     9,
       9,    31,     3,    31,    31,     4,    31,    30,    20,     3,
      14,    35,    30,    35,    35,    35,    35,     4,     6,    35,
      -1,   128,    -1,    30,    -1,    31,    31,    35,    31,    31,
      -1,    -1,    63,    -1,    -1,    35,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    18,    45,    47,    48,    51,     0,
      10,    48,    57,    13,     3,    46,     3,    51,    52,    30,
       3,    54,    55,    56,     3,    19,    22,    25,    26,    28,
      58,    59,    60,    63,    64,    65,    68,    69,    70,    73,
      74,    75,    50,    54,    29,    34,    35,    53,    30,    36,
      30,    30,    30,    30,    30,    12,    59,    36,    21,    58,
      31,    34,    30,    54,    52,     4,     3,     4,     5,     7,
      27,    61,    62,    63,     3,     4,     5,     6,    61,    63,
      72,    72,     3,     3,     7,    66,    50,     3,     4,     5,
       7,    27,    61,    63,    58,    52,    50,     4,    53,    31,
      34,    35,    35,    35,    35,     3,    35,     8,    35,     9,
       9,     9,    31,    31,    31,     7,    34,    67,    67,    31,
      31,    35,    35,    35,     3,    35,    35,    37,    58,    31,
      34,     4,    30,     3,     4,     5,    63,     3,     4,    61,
      63,     3,    61,    63,     3,    61,    63,    20,    58,    35,
      67,     3,    35,    30,    60,     4,    31,    50,    61,    63,
      61,    61,    61,    38,    39,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    24,    67,    50,    14,    31,
      31,    72,    72,    31,    49,    35,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 52 "bisony.y"
    {printf("syntax correct\n"); 
					 YYACCEPT;
					 ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 55 "bisony.y"
    {strcpy(save_type,"CHARACTER");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 63 "bisony.y"
    {strcpy(save_type,"CHARACTER");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 64 "bisony.y"
    {  if (check_declaration((yyvsp[(3) - (11)].strVal)) == 0) {
              printf("Erreur : L'identificateur %s n'a pas été déclaré.\n", (yyvsp[(3) - (11)].strVal)); }
         ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 72 "bisony.y"
    {strcpy(save_type,"Real");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 73 "bisony.y"
    {strcpy(save_type,"Logical");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 74 "bisony.y"
    {strcpy(save_type,"CHARACTER");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 75 "bisony.y"
    {strcpy(save_type,"INTEGER");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 85 "bisony.y"
    { 
    if((yyvsp[(4) - (7)].INTEGER)<=0 || (yyvsp[(6) - (7)].INTEGER)<=0) printf("File %s , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);
         else {sprintf(Tailleun,"%d",(yyvsp[(4) - (7)].INTEGER));sprintf(Tailledeux,"%d",(yyvsp[(6) - (7)].INTEGER));
         sprintf(tmp7,"%d",(yyvsp[(4) - (7)].INTEGER));
         sprintf(tmp6,"%d",(yyvsp[(4) - (7)].INTEGER));
          quadr("BOUNDS",tmp7,tmp6,"");
          quadr("ADEC",(yyvsp[(1) - (7)].strVal),"","");
         t++;
        };}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 95 "bisony.y"
    { 
    if((yyvsp[(4) - (5)].INTEGER)<=0) printf("File %s , line %d , CHARACTER %d :semantic error ( La taille de tableau ne doit pas etre inferieur ou égale à null ) \n",f,nb_line,col);
         else {sprintf(Tailletab,"%d",(yyvsp[(4) - (5)].INTEGER));
               sprintf(tmp7,"%d",(yyvsp[(4) - (5)].INTEGER));
               quadr("BOUNDS",tmp7,"","");
               quadr("ADEC",(yyvsp[(1) - (5)].strVal),"","");
               t++;
            };}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 106 "bisony.y"
    {strcpy(save_type,"CHARACTER");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 125 "bisony.y"
    { if(!(strcmp(type,"INTEGER")==0) && !(strcmp(type,"Real")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",tmp3," ",tmp8);t++;};}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 126 "bisony.y"
    { if(check_declaration((yyvsp[(1) - (4)].strVal)) == 0){printf("Variable %s non declaree(utilisee a la ligne %d).\n",(yyvsp[(1) - (4)].strVal),nb_line-1);YYABORT;} else {if(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"Real")!=0 && !(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d . La variable: %s declare commme %s  \n ",nb_line,(yyvsp[(1) - (4)].strVal),get_type((yyvsp[(1) - (4)].strVal)));} else {quadr(":=",tmp3," ",(yyvsp[(1) - (4)].strVal));t++;}};}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 127 "bisony.y"
    { sprintf(buffer, "%d", (yyvsp[(3) - (4)].INTEGER));printf(buffer); if(!(strcmp(type,"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",buffer," ",tmp8);t++;};}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 128 "bisony.y"
    { sprintf(buffer, "%d", (yyvsp[(3) - (4)].INTEGER));printf(buffer); if (check_declaration((yyvsp[(1) - (4)].strVal)) == 0) {printf("Erreur : identificateur %s non declarer. \n", (yyvsp[(1) - (4)].strVal)); } else {  if(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"Real")!=0 && !(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",buffer," ",(yyvsp[(1) - (4)].strVal));t++;}};}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 129 "bisony.y"
    { sprintf(buffer, "%f", (yyvsp[(3) - (4)].Real));printf(buffer); if(!(strcmp(type,"Real")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",buffer," ",tmp8);t++;};}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 130 "bisony.y"
    { sprintf(buffer, "%f", (yyvsp[(3) - (4)].Real));printf(buffer); if (check_declaration((yyvsp[(1) - (4)].strVal)) == 0) {printf("Erreur : identificateur %s non declarer. \n", (yyvsp[(1) - (4)].strVal)); } else {  if(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"Real")!=0 && !(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",buffer," ",(yyvsp[(1) - (4)].strVal));t++;}};}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 131 "bisony.y"
    { quadr(":=",tmp8," ",tmp8);t++;;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 132 "bisony.y"
    { if (check_declaration((yyvsp[(1) - (4)].strVal)) == 0) {printf("Erreur : identificateur %s non declarer. \n", (yyvsp[(1) - (4)].strVal)); } else {if (check_declaration((yyvsp[(3) - (4)].strVal)) == 0) {printf("Erreur : identificateur %s non declarer. \n", (yyvsp[(3) - (4)].strVal)); } else {if(strcmp(get_type((yyvsp[(1) - (4)].strVal)),get_type((yyvsp[(3) - (4)].strVal)))==0) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",(yyvsp[(3) - (4)].strVal)," ",(yyvsp[(1) - (4)].strVal));t++;}}};}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 133 "bisony.y"
    { if (check_declaration((yyvsp[(1) - (4)].strVal)) == 0) {printf("Erreur : identificateur %s non declarer. \n", (yyvsp[(1) - (4)].strVal)); } else {  if(strcmp(get_type((yyvsp[(1) - (4)].strVal)),type)!=0 ) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",tmp8," ",(yyvsp[(1) - (4)].strVal));t++;}};}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 134 "bisony.y"
    { sprintf(buffer, "%s", (yyvsp[(3) - (4)].strVal)); if(!(strcmp(type,"CHARACTER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",buffer," ",tmp8);t++;};}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 135 "bisony.y"
    {strcpy(buffer,(yyvsp[(3) - (4)].strVal)); if (check_declaration((yyvsp[(1) - (4)].strVal)) == 0) {printf("Erreur : identificateur %s non declarer. \n", (yyvsp[(1) - (4)].strVal)); } else {  if(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"Real")!=0 && !(strcmp(get_type((yyvsp[(1) - (4)].strVal)),"INTEGER")==0)) {printf("-----------ERREUR SEMANTIQUE de type d'affectation ! LIGNE : %d \n ",nb_line);} else { quadr(":=",""," ",(yyvsp[(1) - (4)].strVal));t++;}};}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 139 "bisony.y"
    {if( (yyvsp[(3) - (4)].strVal)==0 && strcmp("DIV",(yyvsp[(2) - (4)].strVal))==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d colonne %d \n ",nb_line);YYABORT;} 
			else {sprintf(tmp,"%s",(yyvsp[(3) - (4)].strVal));sprintf(tmp3,"T%d",t);quadr((yyvsp[(2) - (4)].strVal),tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;};}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 141 "bisony.y"
    {if( (yyvsp[(3) - (4)].INTEGER)==0 && strcmp("DIV",(yyvsp[(2) - (4)].strVal))==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d colonne %d \n ",nb_line);YYABORT;} 
			else {sprintf(tmp,"%d",(yyvsp[(3) - (4)].INTEGER));sprintf(tmp3,"T%d",t);quadr((yyvsp[(2) - (4)].strVal),tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;};}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 143 "bisony.y"
    {if( (yyvsp[(3) - (4)].Real)==0.0 && strcmp("DIV",(yyvsp[(2) - (4)].strVal))==0) {printf("ERREUR SEMANTIQUE : division par zero ligne %d colonne %d \n ",nb_line);YYABORT;} 
			else {sprintf(tmp,"%f",(yyvsp[(3) - (4)].Real));sprintf(tmp3,"T%d",t);quadr((yyvsp[(2) - (4)].strVal),tmp2,tmp,tmp3);sprintf(tmp2,"T%d",t);t=t+1;};}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 147 "bisony.y"
    {sprintf(tmp2,"%s",(yyvsp[(1) - (1)].strVal));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 147 "bisony.y"
    {sprintf(tmp2,"%.2f",(yyvsp[(1) - (1)].Real));sprintf(tmp3,"T%.2f",(yyvsp[(1) - (1)].Real));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 147 "bisony.y"
    {sprintf(tmp2,"%d",(yyvsp[(1) - (1)].INTEGER));sprintf(tmp3,"T%d",(yyvsp[(1) - (1)].INTEGER));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 155 "bisony.y"
    { if (check_declaration((yyvsp[(1) - (4)].strVal)) != 0) { printf("Erreur : L'identificateur %s non declaree.\n", (yyvsp[(1) - (4)].strVal));}else {if ((yyvsp[(3) - (4)].INTEGER)>=atoi(Tailletab)){printf("Dépassement de la taille du tableau %s",(yyvsp[(1) - (4)].strVal));} else {strcpy(type,get_type((yyvsp[(1) - (4)].strVal))),sprintf(tmp8,"%s",(yyvsp[(1) - (4)].strVal));}};}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 156 "bisony.y"
    {  if (check_declaration((yyvsp[(1) - (6)].strVal)) != 0) {printf("Erreur : L'identificateur %s non declaree.\n", (yyvsp[(1) - (6)].strVal));}else {if ((yyvsp[(3) - (6)].INTEGER)>=atoi(Tailleun) || (yyvsp[(5) - (6)].INTEGER)>=atoi(Tailledeux)){printf("Dépassement de la taille du matrice %s",(yyvsp[(1) - (6)].strVal));}else {strcpy(type,get_type((yyvsp[(1) - (6)].strVal)));sprintf(tmp8,"%s",(yyvsp[(1) - (6)].strVal));}};}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 163 "bisony.y"
    { 
    // Vérifier la déclaration dans la table des identificateurs
    if (check_declaration((yyvsp[(3) - (5)].strVal)) == 0) {
        printf("Erreur : L'identificateur %s non declaree.\n", (yyvsp[(3) - (5)].strVal));
    }
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 188 "bisony.y"
    {  sprintf(tmp,"%d",t+1);  
                              update_quad(end_if,1,tmp); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 190 "bisony.y"
    { end_if=t;
                   quadr("BR", "","empty", "empty"); 
				   sprintf(tmp,"%d",t+1);
                   update_quad(begin_else,1,tmp);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 205 "bisony.y"
    {sprintf(tmp,"%d",(yyvsp[(3) - (4)].INTEGER));begin_else=t;
if (strcmp((yyvsp[(2) - (4)].strVal),".EQ.")==0) strcpy(tmp5,"BNE");
if (strcmp((yyvsp[(2) - (4)].strVal),".LT.")==0) strcpy(tmp5,"BGE");
if (strcmp((yyvsp[(2) - (4)].strVal),".GT.")==0) strcpy(tmp5,"BLE");
if (strcmp((yyvsp[(2) - (4)].strVal),".LE.")==0) strcpy(tmp5,"BG");
if (strcmp((yyvsp[(2) - (4)].strVal),".GE.")==0) strcpy(tmp5,"BL");
if (strcmp((yyvsp[(2) - (4)].strVal),".NE.")==0) strcpy(tmp5,"BE");
 sprintf(tmp9,"%d",end_if);
 quadr(tmp5,"",(yyvsp[(1) - (4)].strVal),tmp);t++;;}
    break;



/* Line 1455 of yacc.c  */
#line 1832 "bisony.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 241 "bisony.y"

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
