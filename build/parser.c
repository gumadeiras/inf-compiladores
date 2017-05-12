/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include "cc_misc.h"
#include "cc_tree.h"
#include "cc_ast.h"
extern comp_tree_t* ASTRoot;
comp_dict_t* dict;
comp_tree_t* treeAux;
comp_tree_t* treeAux2;
bool isFArgs = false;
int  nFArgs  = 0;
int  FRteurnType;
dictEntry* IDReference;
TList* ArgsListType = NULL;
int nDimension = 0; //numero de dimensoes de um vetor
int dim[20];


#line 85 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_MEDIA_PSF_DROPBOX_DOCUMENTS_UFRGS_MATERIAS_62_COMPILADORES_TRABALHO_BUILD_PARSER_H_INCLUDED
# define YY_YY_MEDIA_PSF_DROPBOX_DOCUMENTS_UFRGS_MATERIAS_62_COMPILADORES_TRABALHO_BUILD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_CONST = 271,
    TK_PR_STATIC = 272,
    TK_PR_FOREACH = 273,
    TK_PR_FOR = 274,
    TK_PR_SWITCH = 275,
    TK_PR_CASE = 276,
    TK_PR_BREAK = 277,
    TK_PR_CONTINUE = 278,
    TK_PR_CLASS = 279,
    TK_PR_PRIVATE = 280,
    TK_PR_PUBLIC = 281,
    TK_PR_PROTECTED = 282,
    TK_OC_LE = 283,
    TK_OC_GE = 284,
    TK_OC_EQ = 285,
    TK_OC_NE = 286,
    TK_OC_AND = 287,
    TK_OC_OR = 288,
    TK_OC_SL = 289,
    TK_OC_SR = 290,
    TK_LIT_INT = 291,
    TK_LIT_FLOAT = 292,
    TK_LIT_FALSE = 293,
    TK_LIT_TRUE = 294,
    TK_LIT_CHAR = 295,
    TK_LIT_STRING = 296,
    TK_IDENTIFICADOR = 297,
    TOKEN_ERRO = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "parser.y" /* yacc.c:355  */

  int IKSType;
  comp_tree_t* ast;
  struct dict_entry* valor_simbolico_lexico;

#line 175 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MEDIA_PSF_DROPBOX_DOCUMENTS_UFRGS_MATERIAS_62_COMPILADORES_TRABALHO_BUILD_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    48,    52,     2,
      53,    54,    46,    44,    60,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    59,
      49,    55,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   137,   138,   139,   147,   148,   151,   152,
     155,   161,   176,   179,   189,   192,   195,   198,   201,   202,
     203,   206,   207,   208,   209,   210,   213,   214,   223,   224,
     227,   236,   227,   249,   250,   253,   254,   257,   262,   282,
     283,   284,   285,   286,   287,   288,   289,   295,   296,   297,
     298,   300,   305,   321,   339,   344,   352,   368,   396,   413,
     414,   417,   427,   437,   437,   459,   460,   466,   474,   491,
     492,   493,   494,   498,   508,   511,   515,   516,   529,   530,
     531,   532,   533,   534,   539,   540,   544,   548,   551,   552,
     555,   559,   563,   569,   569,   577,   578,   581,   582,   593,
     603,   612,   621,   630,   639,   648,   657,   666,   675,   684,
     693,   702,   711,   712,   713,   717,   725,   726,   730,   736,
     746,   749,   754,   763,   770,   779,   784,   790,   791,   796,
     801,   806
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_CONST", "TK_PR_STATIC", "TK_PR_FOREACH", "TK_PR_FOR",
  "TK_PR_SWITCH", "TK_PR_CASE", "TK_PR_BREAK", "TK_PR_CONTINUE",
  "TK_PR_CLASS", "TK_PR_PRIVATE", "TK_PR_PUBLIC", "TK_PR_PROTECTED",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_OC_SL", "TK_OC_SR", "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE",
  "TK_LIT_TRUE", "TK_LIT_CHAR", "TK_LIT_STRING", "TK_IDENTIFICADOR",
  "TOKEN_ERRO", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'!'",
  "'&'", "'('", "')'", "'='", "':'", "'['", "']'", "';'", "','", "'{'",
  "'}'", "$accept", "programa", "declist", "varglobal", "newvar",
  "vardecl", "IntList", "newtype", "newtypedecl", "newtypevar", "fields",
  "fieldencap", "vartype", "fieldid", "funcao", "funcdecl", "$@1", "$@2",
  "arg", "arglist", "argsdecl", "comsimples", "comdecl", "comvar",
  "initvar", "comatr", "comio", "comin", "comout", "callfunc", "$@3",
  "calldecl", "comshift", "RBCC", "comreturn", "combreak", "comcontinue",
  "comcase", "comflux", "comif", "comfore", "comfor", "listcomfor",
  "comwhile", "comdo", "comshitch", "combloco", "$@4", "listcom",
  "comandoCV", "exp", "folha", "Vexplist", "listexp", "litnumber",
  "literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    43,    45,    42,    47,    37,    60,
      62,    33,    38,    40,    41,    61,    58,    91,    93,    59,
      44,   123,   125
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -94

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,  -136,  -136,  -136,  -136,  -136,   188,     0,    57,  -136,
     -55,  -136,  -136,  -136,  -136,    30,    90,  -136,  -136,  -136,
      20,  -136,  -136,    90,   -13,  -136,    62,  -136,    47,    32,
    -136,  -136,  -136,    51,   188,    69,    78,   170,  -136,   101,
      47,  -136,   188,   111,    83,  -136,    97,    99,  -136,  -136,
     121,  -136,  -136,   170,    62,  -136,   103,  -136,  -136,     3,
     369,   112,   206,   369,   369,   369,   188,   229,   126,   128,
     132,   151,  -136,  -136,     4,   146,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   154,   127,
     157,  -136,  -136,  -136,  -136,  -136,  -136,     1,   369,   369,
     369,   369,  -136,    72,  -136,  -136,  -136,   369,   171,   348,
       2,  -136,   348,  -136,   188,  -136,   189,   206,   369,   181,
      55,    55,   196,   369,   369,   193,    -1,     3,  -136,     3,
     369,   354,   354,  -136,   240,   206,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   267,
     236,   369,  -136,   194,  -136,     7,   294,   206,  -136,  -136,
     197,   348,   102,   204,   369,   239,    47,   201,  -136,   207,
    -136,   192,    66,    66,    66,    66,  -136,  -136,   354,   354,
      95,    95,    95,    66,    66,   252,   230,  -136,   369,   369,
     206,   206,   223,   369,   369,   237,   247,  -136,  -136,  -136,
    -136,   233,  -136,  -136,   283,   206,   369,   248,   211,  -136,
    -136,   281,   348,  -136,   369,  -136,  -136,   206,   245,   321,
     206,   206,   284,   348,  -136,  -136,   249,  -136,    22,  -136,
    -136,   206,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    21,    22,    25,    23,    24,     0,     0,     0,     2,
       0,     7,     9,     6,    14,     0,     5,    29,     8,    28,
       0,    15,     1,     5,    10,     3,     0,     4,     0,     0,
      19,    20,    18,     0,     0,    13,     0,    33,    16,     0,
       0,    11,     0,     0,     0,    34,    35,    26,    17,    12,
       0,    38,    31,     0,     0,    37,     0,    36,    27,    98,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    63,     0,    97,    39,    50,    40,
      41,    59,    60,    42,    43,    44,    69,    70,    71,    72,
      45,    78,    80,    81,    82,    83,    79,    46,     0,     0,
      96,   125,   126,   131,   130,   129,   128,   118,     0,     0,
       0,     0,   116,     0,   117,   127,   120,     0,     0,    61,
     124,    62,    73,    49,     0,    47,     0,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    98,    32,    98,
       0,   113,   114,   115,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,    89,     0,     0,    93,    67,    68,
       0,    56,   122,     0,    66,     0,     0,     0,    95,     0,
     112,     0,   106,   107,   108,   109,   110,   111,    99,   100,
     101,   102,   103,   104,   105,     0,     0,   123,     0,     0,
      93,    93,     0,     0,     0,     0,     0,    65,    54,    53,
      55,     0,    94,   119,    84,    93,     0,     0,     0,    88,
      92,     0,    58,   121,     0,    64,    52,    93,     0,     0,
      93,    93,    76,    57,    85,    90,     0,    86,     0,    77,
      91,    93,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,    13,  -136,  -136,   300,   -38,  -136,  -136,  -136,
     253,  -136,    37,  -136,  -136,   303,  -136,  -136,  -136,   257,
    -136,   -61,  -136,   -54,  -136,  -136,  -136,  -136,  -136,   -59,
    -136,  -136,  -136,  -136,  -136,    98,  -136,    86,  -136,  -136,
    -136,  -136,    89,  -136,  -136,  -136,  -136,  -136,   -64,  -136,
      50,  -136,  -135,  -133,   -19,   153
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    36,    13,    14,    21,
      33,    34,    75,    48,    16,    17,    29,    56,    44,    45,
      46,    76,    77,    78,   209,    79,    80,    81,    82,   112,
     135,   206,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   165,    94,    95,    96,    97,    98,    99,   100,
     120,   114,   173,   121,   115,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,   118,    49,    83,    23,   179,     1,     2,     3,     4,
       5,    60,   123,   125,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,   175,   197,    25,
     146,   147,   148,   149,   150,   151,    27,    15,   130,   131,
     -30,   207,    20,    15,    28,    74,   152,   153,   154,   155,
     156,   157,   158,    15,   -63,   132,   176,    22,   140,   133,
      15,   134,   161,   199,   -93,   217,   164,   200,    83,   223,
     162,    39,    24,   177,    43,   178,   241,    26,    83,    50,
      83,   145,   200,    35,   181,    37,    83,    30,    31,    32,
      43,   101,   102,     1,     2,     3,     4,     5,   150,   151,
     146,   147,   148,   149,   150,   151,   202,     6,    83,    38,
     113,   168,   169,   119,     7,   122,   152,   153,   154,   155,
     156,   157,   158,   146,   147,   148,   149,   150,   151,    40,
     146,   147,   148,   149,   150,   151,    41,    52,   211,   219,
     220,    83,    83,    47,   157,   158,   152,   153,   154,   155,
     156,   157,   158,    51,   228,    54,    83,    53,   141,   142,
     143,   144,   204,    55,    59,   117,   234,   159,    83,   237,
     164,    83,    83,     1,     2,     3,     4,     5,   166,   126,
     242,   127,    83,   171,   172,   128,    42,   129,   136,   138,
     172,     1,     2,     3,     4,     5,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     1,
       2,     3,     4,     5,    60,   137,   139,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
     160,   163,     1,     2,     3,     4,     5,   167,   170,   146,
     147,   148,   149,   150,   151,   124,   174,   196,    74,   218,
     198,   214,   203,   222,   172,   152,   153,   154,   155,   156,
     157,   158,   205,   212,   215,   213,   229,   231,   146,   147,
     148,   149,   150,   151,   233,   101,   102,   103,   104,   105,
     106,   208,   221,   216,   152,   153,   154,   155,   156,   157,
     158,   226,   224,   227,   180,   146,   147,   148,   149,   150,
     151,   225,   230,    72,   235,    71,    18,    58,   240,    19,
      57,   152,   153,   154,   155,   156,   157,   158,   239,   232,
     238,   195,   146,   147,   148,   149,   150,   151,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,   201,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   236,   146,   147,   148,   149,
     150,   151,   146,   147,   148,   149,   150,   151,     0,     0,
       0,     0,   152,   153,   154,   155,   156,   157,   158,     0,
     154,   155,   156,   157,   158,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,     0,     0,
     110,     0,   111
};

static const yytype_int16 yycheck[] =
{
      59,    62,    40,    62,    59,   140,     3,     4,     5,     6,
       7,     8,    66,    67,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    28,   161,    16,
      28,    29,    30,    31,    32,    33,    23,     0,    34,    35,
      53,   174,    42,     6,    57,    42,    44,    45,    46,    47,
      48,    49,    50,    16,    53,    51,    57,     0,    57,    55,
      23,    57,    60,    56,    61,   198,   127,    60,   127,   204,
     124,    34,    42,   137,    37,   139,    54,    57,   137,    42,
     139,     9,    60,    36,   145,    53,   145,    25,    26,    27,
      53,    36,    37,     3,     4,     5,     6,     7,    32,    33,
      28,    29,    30,    31,    32,    33,   167,    17,   167,    58,
      60,   130,   131,    63,    24,    65,    44,    45,    46,    47,
      48,    49,    50,    28,    29,    30,    31,    32,    33,    60,
      28,    29,    30,    31,    32,    33,    58,    54,   176,   200,
     201,   200,   201,    42,    49,    50,    44,    45,    46,    47,
      48,    49,    50,    42,   215,    56,   215,    60,   108,   109,
     110,   111,    60,    42,    61,    53,   227,   117,   227,   230,
     231,   230,   231,     3,     4,     5,     6,     7,   128,    53,
     241,    53,   241,   133,   134,    53,    16,    36,    42,    62,
     140,     3,     4,     5,     6,     7,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,     3,
       4,     5,     6,     7,     8,    61,    59,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      59,    42,     3,     4,     5,     6,     7,    56,    42,    28,
      29,    30,    31,    32,    33,    16,    53,    11,    42,   199,
      56,    59,    55,   203,   204,    44,    45,    46,    47,    48,
      49,    50,    58,    62,    12,    58,   216,    56,    28,    29,
      30,    31,    32,    33,   224,    36,    37,    38,    39,    40,
      41,    42,    59,    53,    44,    45,    46,    47,    48,    49,
      50,    58,    55,    10,    54,    28,    29,    30,    31,    32,
      33,    54,    54,    22,    59,    21,     6,    54,    59,     6,
      53,    44,    45,    46,    47,    48,    49,    50,   232,   221,
     231,    54,    28,    29,    30,    31,    32,    33,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    54,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    28,    29,    30,    31,
      32,    33,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    -1,
      46,    47,    48,    49,    50,    36,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    24,    64,    65,
      66,    67,    68,    70,    71,    75,    77,    78,    68,    78,
      42,    72,     0,    59,    42,    65,    57,    65,    57,    79,
      25,    26,    27,    73,    74,    36,    69,    53,    58,    75,
      60,    58,    16,    75,    81,    82,    83,    42,    76,    69,
      75,    42,    54,    60,    56,    42,    80,    82,    73,    61,
       8,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    42,    75,    84,    85,    86,    88,
      89,    90,    91,    92,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   106,   107,   108,   109,   110,   111,
     112,    36,    37,    38,    39,    40,    41,    42,    44,    45,
      51,    53,    92,   113,   114,   117,   118,    53,    84,   113,
     113,   116,   113,    86,    16,    86,    53,    53,    53,    36,
      34,    35,    51,    55,    57,    93,    42,    61,    62,    59,
      57,   113,   113,   113,   113,     9,    28,    29,    30,    31,
      32,    33,    44,    45,    46,    47,    48,    49,    50,   113,
      59,    60,    86,    42,    84,   105,   113,    56,   117,   117,
      42,   113,   113,   115,    53,    28,    57,   111,   111,   115,
      54,    84,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,    54,    11,   116,    56,    56,
      60,    54,    84,    55,    60,    58,    94,   116,    42,    87,
     118,    69,    62,    58,    59,    12,    53,   116,   113,    84,
      84,    59,   113,   115,    55,    54,    58,    10,    84,   113,
      54,    56,    98,   113,    84,    59,    54,    84,   105,   100,
      59,    54,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    72,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    76,    76,    77,    77,
      79,    80,    78,    81,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    86,    86,    86,    87,    87,    88,    88,    88,    89,
      89,    90,    91,    93,    92,    94,    94,    95,    95,    96,
      96,    96,    96,    97,    98,    99,   100,   100,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   104,   105,   105,
     106,   107,   108,   110,   109,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     0,     1,     1,     2,     1,
       2,     5,     3,     1,     1,     2,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       0,     0,    10,     0,     1,     1,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       1,     2,     5,     4,     1,     1,     3,     6,     5,     1,
       1,     2,     2,     0,     5,     1,     0,     3,     3,     1,
       1,     1,     1,     2,     1,     1,     6,     7,     1,     1,
       1,     1,     1,     1,     5,     7,     7,     9,     3,     1,
       7,     8,     5,     0,     4,     3,     1,     1,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     1,     1,     1,     4,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 134 "parser.y" /* yacc.c:1646  */
    { ASTGraphvizDeclare(AST_PROGRAMA, ASTRoot, NULL); ASTRoot->value = ASTNewNode(AST_PROGRAMA,NULL); ASTInsertNode(ASTRoot, (yyvsp[0].ast)); }
#line 1489 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast);  ASTInsertNode((yyval.ast),(yyvsp[0].ast)); }
#line 1495 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1501 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 1507 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 155 "parser.y" /* yacc.c:1646  */
    {  declare(dict ,(dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                            setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                            isASet((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), VARIAVEL);

                                         }
#line 1517 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 161 "parser.y" /* yacc.c:1646  */
    { //declare(dict ,(dictEntry**)&$2, $1);
                                                           //setIKSType((dictEntry**)&$2, $1);

                                                           if(nDimension != 0)
                                                             {
                                                               declarevector(dict, (dictEntry**)&(yyvsp[-3].valor_simbolico_lexico), (yyvsp[-4].IKSType), nDimension, dim);
                                                               isASet((dictEntry**)&(yyvsp[-3].valor_simbolico_lexico), VETOR);
                                                               //setDimensionV((dictEntry**)&$2, nDimension, dim);
                                                               nDimension = 0;
                                                               int i =0;
                                                               for(i = 0; i<20; i++)
                                                                 dim[20] = 0;
                                                             }
                                                         }
#line 1536 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                                                           dim[nDimension] = dimensionSize((dictEntry*) (yyvsp[-2].valor_simbolico_lexico)); nDimension++;
                                                         }
#line 1544 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 179 "parser.y" /* yacc.c:1646  */
    {
                                                           dim[nDimension] = dimensionSize((dictEntry*) (yyvsp[0].valor_simbolico_lexico)); nDimension++;
                                                         }
#line 1552 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 195 "parser.y" /* yacc.c:1646  */
    { (dictEntry*)(yyvsp[-3].valor_simbolico_lexico);}
#line 1558 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.IKSType) = IKS_INT;}
#line 1564 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.IKSType) = IKS_FLOAT;}
#line 1570 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.IKSType) = IKS_CHAR;}
#line 1576 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.IKSType) = IKS_STRING;}
#line 1582 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.IKSType) = IKS_BOOL;}
#line 1588 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1594 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1600 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 227 "parser.y" /* yacc.c:1646  */
    { declare(dict ,(dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                           setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                           isASet((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), FUNCAO);
                                           IDReference = (yyvsp[0].valor_simbolico_lexico);
                                           FRteurnType = (yyvsp[-1].IKSType);
                                           stackPush(&dict);

                                         }
#line 1613 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 236 "parser.y" /* yacc.c:1646  */
    {

                                         }
#line 1621 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 240 "parser.y" /* yacc.c:1646  */
    { stackPop(&dict);
                                           FRteurnType = 0;
                                           (yyval.ast) = tree_make_node(NULL);
                                           ASTGraphvizDeclare(AST_FUNCAO, (yyval.ast),ASTGetLiteral((dictEntry*)(yyvsp[-8].valor_simbolico_lexico)));
                                           ASTInsertNode((yyval.ast), (yyvsp[-1].ast));
                                           (yyval.ast)->value = ASTNewNode(AST_FUNCAO,NULL);
                                         }
#line 1633 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 257 "parser.y" /* yacc.c:1646  */
    { setArgs((dictEntry**)&IDReference, (yyvsp[-1].IKSType));
                                                       declare(dict ,(dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                                       setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                                       isASet((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), VARIAVEL);
                                                     }
#line 1643 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 262 "parser.y" /* yacc.c:1646  */
    { setArgs((dictEntry**)&IDReference, (yyvsp[-1].IKSType));
                                           declare(dict ,(dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                           setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                           isASet((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), VARIAVEL);
                                          }
#line 1653 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1659 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1665 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1671 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1677 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1683 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1689 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1695 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1701 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1707 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1713 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1719 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1725 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL;
                                                             declare(dict ,(dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                                             setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), (yyvsp[-1].IKSType));
                                                             isASet((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), VARIAVEL);
                                                           }
#line 1735 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL;
                                                             if(nDimension != 0)
                                                             {
                                                               declarevector(dict, (dictEntry**)&(yyvsp[-3].valor_simbolico_lexico), (yyvsp[-4].IKSType), nDimension, dim);
                                                               isASet((dictEntry**)&(yyvsp[-3].valor_simbolico_lexico), VETOR);
                                                               //setDimensionV((dictEntry**)&$2, nDimension, dim);
                                                               nDimension = 0;
                                                               int i =0;
                                                               for(i = 0; i<20; i++)
                                                                 dim[20] = 0;
                                                             }
                                                            }
#line 1752 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 321 "parser.y" /* yacc.c:1646  */
    { declare(dict ,(dictEntry**)&(yyvsp[-2].valor_simbolico_lexico), (yyvsp[-3].IKSType));
                                                             setIKSType((dictEntry**)&(yyvsp[-2].valor_simbolico_lexico), (yyvsp[-3].IKSType));
                                                             isASet((dictEntry**)&(yyvsp[-2].valor_simbolico_lexico), VARIAVEL);
                                                             dictEntry* destino = (dictEntry*)(yyvsp[-2].valor_simbolico_lexico);
                                                             dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                                             int IKSType = cohersionChecker(destino, origem);
                                                             setIKSType((dictEntry**)&destino, IKSType);

                                                             (yyval.ast) = tree_make_node(NULL);
                                                             treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-2].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                             ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-2].valor_simbolico_lexico)));
                                                             ASTGraphvizDeclare(AST_ATRIBUICAO, (yyval.ast), NULL);
                                                             (yyval.ast)->value = ASTNewNode(AST_ATRIBUICAO,NULL);
                                                             ASTInsertNode((yyval.ast), treeAux);
                                                             ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                                           }
#line 1773 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                      ASTGraphvizDeclare(AST_IDENTIFICADOR, (yyval.ast),  ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                      (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                      isDeclared(dict,(dictEntry**)&(yyvsp[0].valor_simbolico_lexico));
                                    }
#line 1783 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1789 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 352 "parser.y" /* yacc.c:1646  */
    { isDeclared(dict, (dictEntry**)&(yyvsp[-2].valor_simbolico_lexico));
                                                                 isACheck(dict,(dictEntry*)(yyvsp[-2].valor_simbolico_lexico), VARIAVEL);
                                                                 dictEntry* destino = (dictEntry*)(yyvsp[-2].valor_simbolico_lexico);
                                                                 dictEntry* origem = (dictEntry*)((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                                                 int IKSType = cohersionChecker(destino, origem);
                                                                 setIKSType((dictEntry**)&destino, IKSType);

                                                                 (yyval.ast) = tree_make_node(NULL);
                                                                 treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-2].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-2].valor_simbolico_lexico)));
                                                                 ASTGraphvizDeclare(AST_ATRIBUICAO, (yyval.ast), NULL);
                                                                 (yyval.ast)->value = ASTNewNode(AST_ATRIBUICAO,NULL);
                                                                 ASTInsertNode((yyval.ast), treeAux);
                                                                 ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                                               }
#line 1809 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 368 "parser.y" /* yacc.c:1646  */
    {
                                                                 isDeclared(dict, (dictEntry**)&(yyvsp[-5].valor_simbolico_lexico));
                                                                 isACheck(dict,(dictEntry*)(yyvsp[-5].valor_simbolico_lexico), VETOR);

                                                                 dictEntry* destino = (dictEntry*)(yyvsp[-5].valor_simbolico_lexico);
                                                                 dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                                                 int IKSType = cohersionChecker(destino, origem);
                                                                 setIKSType((dictEntry**)&destino, IKSType);


                                                                 (yyval.ast) = tree_make_node(ASTNewNode(AST_ATRIBUICAO,NULL));
                                                                 ASTGraphvizDeclare(AST_ATRIBUICAO, (yyval.ast), NULL);
                                                                 treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-5].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-5].valor_simbolico_lexico)));



                                                                 treeAux2 = tree_make_node(ASTNewNode(AST_VETOR_INDEXADO,NULL));
                                                                 ASTGraphvizDeclare(AST_VETOR_INDEXADO, treeAux2, NULL);
                                                                 ASTInsertNode(treeAux2, treeAux);
                                                                 ASTInsertNode(treeAux2, (yyvsp[-3].ast));

                                                                 ASTInsertNode((yyval.ast), treeAux2);
                                                                 ASTInsertNode((yyval.ast), (yyvsp[0].ast));

                                                               }
#line 1840 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 396 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                                                 treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-4].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-4].valor_simbolico_lexico)));
                                                                 treeAux2 = ASTSymbolEntry((dictEntry*)(yyvsp[-2].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                                 ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux2, ASTGetLiteral((dictEntry*)(yyvsp[-2].valor_simbolico_lexico)));
                                                                 (yyval.ast)->value = ASTNewNode(AST_ATRIBUICAO,NULL);
                                                                 ASTGraphvizDeclare(AST_ATRIBUICAO, (yyval.ast), NULL);
                                                                 ASTInsertNode((yyval.ast), treeAux);
                                                                 ASTInsertNode((yyval.ast), treeAux2);
                                                                 ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                                               }
#line 1856 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 413 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1862 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 414 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1868 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 417 "parser.y" /* yacc.c:1646  */
    { dictEntry* input = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                         isDeclared(dict, (dictEntry**)&input);
                                         checkInput(input);
                                         (yyval.ast) = tree_make_node(NULL);
                                         ASTGraphvizDeclare(AST_INPUT, (yyval.ast), NULL);
                                         ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                         (yyval.ast)->value = ASTNewNode(AST_INPUT,NULL);
                                       }
#line 1881 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 427 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                         ASTGraphvizDeclare(AST_OUTPUT, (yyval.ast), NULL);
                                         ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                         (yyval.ast)->value = ASTNewNode(AST_OUTPUT,NULL); }
#line 1890 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 437 "parser.y" /* yacc.c:1646  */
    {
                                   isDeclared(dict, (dictEntry**)&(yyvsp[0].valor_simbolico_lexico));
                                   isACheck(dict,(dictEntry*)(yyvsp[0].valor_simbolico_lexico), FUNCAO);
                                   isFArgs = true;
                                   nFArgs = 0;
                                   IDReference = (dictEntry*)(yyvsp[0].valor_simbolico_lexico);
                                   ArgsListType = getListArgs(IDReference);
                                 }
#line 1903 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 446 "parser.y" /* yacc.c:1646  */
    { checkNArgs(dict, IDReference, nFArgs);
                                   nFArgs = 0;
                                   isFArgs = false;
                                   (yyval.ast) = tree_make_node(NULL);
                                   treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-4].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                   ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-4].valor_simbolico_lexico)));
                                   ASTGraphvizDeclare(AST_CHAMADA_DE_FUNCAO, (yyval.ast), NULL);
                                   (yyval.ast)->value = ASTNewNode(AST_CHAMADA_DE_FUNCAO,(dictEntry*)(yyvsp[-4].valor_simbolico_lexico));
                                   ASTInsertNode((yyval.ast), treeAux);
                                   ASTInsertNode((yyval.ast), (yyvsp[-1].ast));
                                 }
#line 1919 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 459 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1925 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 460 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 1931 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 466 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                                    treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-2].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                    ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-2].valor_simbolico_lexico)));
                                                    ASTGraphvizDeclare(AST_SHIFT_LEFT, (yyval.ast), NULL);
                                                    (yyval.ast)->value = ASTNewNode(AST_SHIFT_LEFT,NULL);
                                                    ASTInsertNode((yyval.ast), treeAux);
                                                    ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                                    }
#line 1944 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 474 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                                    treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-2].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                    ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-2].valor_simbolico_lexico)));
                                                    ASTGraphvizDeclare(AST_SHIFT_RIGHT, (yyval.ast), NULL);
                                                    (yyval.ast)->value = ASTNewNode(AST_SHIFT_RIGHT,NULL);
                                                    ASTInsertNode((yyval.ast), treeAux);
                                                    ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                                    }
#line 1957 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 491 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1963 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 492 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 1969 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 493 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 1975 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 494 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 1981 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 498 "parser.y" /* yacc.c:1646  */
    { dictEntry* destino = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                   checkReturn((dictEntry**)&destino, FRteurnType);
                                   (yyval.ast) = tree_make_node(NULL);
                                   ASTGraphvizDeclare(AST_RETURN, (yyval.ast), NULL);
                                   ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                   (yyval.ast)->value = ASTNewNode(AST_RETURN,destino);
                                 }
#line 1993 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 529 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1999 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 530 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 2005 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 531 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 2011 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 532 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 2017 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 533 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2023 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 534 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2029 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 539 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL); ASTGraphvizDeclare(AST_IF_ELSE, (yyval.ast), NULL); ASTInsertNode((yyval.ast), (yyvsp[-3].ast)); ASTInsertNode((yyval.ast), (yyvsp[-1].ast)); (yyval.ast)->value = ASTNewNode(AST_IF,NULL); }
#line 2035 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 540 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL); ASTGraphvizDeclare(AST_IF_ELSE, (yyval.ast), NULL); ASTInsertNode((yyval.ast), (yyvsp[-5].ast)); ASTInsertNode((yyval.ast), (yyvsp[-3].ast)); ASTInsertNode((yyval.ast), (yyvsp[0].ast)); (yyval.ast)->value = ASTNewNode(AST_IF_ELSE,NULL); }
#line 2041 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 555 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL); ASTGraphvizDeclare(AST_WHILE_DO, (yyval.ast), NULL); ASTInsertNode((yyval.ast), (yyvsp[-4].ast)); ASTInsertNode((yyval.ast), (yyvsp[-1].ast)); (yyval.ast)->value = ASTNewNode(AST_WHILE_DO,NULL); }
#line 2047 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 559 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL); ASTGraphvizDeclare(AST_DO_WHILE, (yyval.ast), NULL); ASTInsertNode((yyval.ast), (yyvsp[-6].ast)); ASTInsertNode((yyval.ast), (yyvsp[-2].ast)); (yyval.ast)->value = ASTNewNode(AST_DO_WHILE,NULL); }
#line 2053 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 569 "parser.y" /* yacc.c:1646  */
    {stackPush(&dict);}
#line 2059 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 569 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                                     (yyval.ast)->value = ASTNewNode(AST_BLOCO,NULL);
                                                     ASTGraphvizDeclare(AST_BLOCO, (yyval.ast), NULL);
                                                     ASTInsertNode((yyval.ast),(yyvsp[-1].ast));
                                                     stackPop(&dict);
                                                   }
#line 2070 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 577 "parser.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].ast) != NULL) {(yyval.ast) = (yyvsp[-2].ast);  ASTInsertNode((yyval.ast),(yyvsp[0].ast));} else {(yyval.ast)=(yyvsp[0].ast);} }
#line 2076 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 578 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2082 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 581 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2088 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 582 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = NULL; }
#line 2094 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 593 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_SOMA,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       (yyval.ast)->value = ASTNewNode(AST_ARIM_SOMA, destino);
                                     }
#line 2108 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 603 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_SUBTRACAO,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       (yyval.ast)->value = ASTNewNode(AST_ARIM_SUBTRACAO, destino);
                                     }
#line 2122 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 612 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_MULTIPLICACAO,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       (yyval.ast)->value = ASTNewNode(AST_ARIM_MULTIPLICACAO, destino);
                                     }
#line 2136 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 621 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_DIVISAO,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       (yyval.ast)->value = ASTNewNode(AST_ARIM_DIVISAO, destino);
                                     }
#line 2150 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 630 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_ARIM_DIVISAO,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKSType);
                                       (yyval.ast)->value = ASTNewNode(AST_ARIM_DIVISAO, destino);
                                     }
#line 2164 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 639 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_L,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_COMP_L, destino);
                                     }
#line 2178 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 648 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_G,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_COMP_G, destino);
                                     }
#line 2192 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 657 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_LE,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_COMP_LE, destino);
                                     }
#line 2206 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 666 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_GE,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_COMP_GE, destino);
                                     }
#line 2220 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 675 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_IGUAL,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_COMP_IGUAL,destino);
                                     }
#line 2234 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 684 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_DIF,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_COMP_DIF,destino);
                                     }
#line 2248 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 693 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_E,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_E,destino);
                                     }
#line 2262 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 702 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_OU,(yyval.ast), NULL);
                                       ASTInsertTwoNodes((yyval.ast),(yyvsp[-2].ast),(yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                       dictEntry* origem = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       int IKSType = cohersionChecker(destino, origem);
                                       setIKSType((dictEntry**)&destino, IKS_BOOL);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_OU,destino);
                                     }
#line 2276 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 711 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2282 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 712 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2288 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 713 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(ASTNewNode(AST_ARIM_INVERSAO,NULL));
                                       ASTGraphvizDeclare(AST_ARIM_INVERSAO,(yyval.ast), NULL);
                                       ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                     }
#line 2297 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 717 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = tree_make_node(NULL);
                                       ASTGraphvizDeclare(AST_LOGICO_COMP_NEGACAO,(yyval.ast), NULL);
                                       ASTInsertNode((yyval.ast), (yyvsp[0].ast));
                                       dictEntry* destino = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                       if(destino->IKSType != IKS_BOOL)
                                         exit(IKS_ERROR_WRONG_TYPE);
                                       (yyval.ast)->value = ASTNewNode(AST_LOGICO_COMP_NEGACAO,destino);
                                     }
#line 2310 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 725 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2316 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 726 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2322 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 730 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                             ASTGraphvizDeclare(AST_IDENTIFICADOR, (yyval.ast), ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                             isDeclared(dict,(dictEntry**)&(yyvsp[0].valor_simbolico_lexico));
                                             isACheck(dict,(dictEntry*)(yyvsp[0].valor_simbolico_lexico), VARIAVEL);
                                           }
#line 2332 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 736 "parser.y" /* yacc.c:1646  */
    {
            	                                  isDeclared(dict,(dictEntry**)&(yyvsp[-3].valor_simbolico_lexico));
                                                  isACheck(dict,(dictEntry*)(yyvsp[-3].valor_simbolico_lexico), VETOR);
                                                  isNumber((yyvsp[-1].ast)->value);
                                                  (yyval.ast) = tree_make_node(ASTNewNode(AST_VETOR_INDEXADO,(dictEntry*)(yyvsp[-3].valor_simbolico_lexico)));
                                                  ASTGraphvizDeclare(AST_VETOR_INDEXADO, (yyval.ast), NULL);
                                                  treeAux = ASTSymbolEntry((dictEntry*)(yyvsp[-3].valor_simbolico_lexico),AST_IDENTIFICADOR);
                                                  ASTGraphvizDeclare(AST_IDENTIFICADOR, treeAux, ASTGetLiteral((dictEntry*)(yyvsp[-3].valor_simbolico_lexico)));
                                                  ASTInsertTwoNodes((yyval.ast),treeAux,(yyvsp[-1].ast));
                                                }
#line 2347 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 746 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2353 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 749 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-2].ast);
                                                                 ASTInsertNode((yyval.ast),(yyvsp[0].ast));
                                                                 dictEntry* auxEntry = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                                                 isNumber(auxEntry);
                                                               }
#line 2363 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 754 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);
                                                                 dictEntry* auxEntry = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                                                 isNumber(auxEntry);
                                                               }
#line 2372 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 763 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-2].ast);
                                   ASTInsertNode((yyval.ast),(yyvsp[0].ast));
                                   nFArgs++;
                                   dictEntry* expEntry = ((ASTNode*)(yyvsp[-2].ast)->value)->entry;
                                   TList *ListTypeUpdated = checkTypeArgs(expEntry, ArgsListType);
                                   ArgsListType = ListTypeUpdated;
                                  }
#line 2384 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 770 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast);
                                   nFArgs++;
                                   dictEntry* expEntry = ((ASTNode*)(yyvsp[0].ast)->value)->entry;
                                   TList *ListTypeUpdated = checkTypeArgs(expEntry, ArgsListType);
                                   ArgsListType = ListTypeUpdated;
                                  }
#line 2395 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 779 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,(yyval.ast), ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                    setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), IKS_INT);
                                  }
#line 2404 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 784 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,(yyval.ast), ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                    setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), IKS_FLOAT);
                                  }
#line 2413 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 790 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2419 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 791 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,(yyval.ast), ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                    setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), IKS_STRING);
                                  }
#line 2428 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 796 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,(yyval.ast), ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                    setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), IKS_CHAR);
                                  }
#line 2437 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 801 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,(yyval.ast), ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                    setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), IKS_BOOL);
                                  }
#line 2446 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 806 "parser.y" /* yacc.c:1646  */
    { (yyval.ast) = ASTSymbolEntry((dictEntry*)(yyvsp[0].valor_simbolico_lexico),AST_LITERAL);
                                    ASTGraphvizDeclare(AST_LITERAL,(yyval.ast), ASTGetLiteral((dictEntry*)(yyvsp[0].valor_simbolico_lexico)));
                                    setIKSType((dictEntry**)&(yyvsp[0].valor_simbolico_lexico), IKS_BOOL);
                                  }
#line 2455 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
    break;


#line 2459 "/media/psf/Dropbox/documents/ufrgs/materias/62/compiladores/trabalho/build/parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 812 "parser.y" /* yacc.c:1906  */

