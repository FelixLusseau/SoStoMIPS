/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilateur.y"

#ifdef YYDEBUG
  yydebug = 1;
#endif

#include "quads.h"
#include <stdio.h>

extern int yylex(); 
extern char* text;
extern void yyerror(const char * msg);
extern listQ *Lglobal;

#line 84 "compilateur.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_COMPILATEUR_TAB_H_INCLUDED
# define YY_YY_COMPILATEUR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    THEN = 259,
    FOR = 260,
    DO = 261,
    DONE = 262,
    IN = 263,
    WHILE = 264,
    UNTIL = 265,
    CASE = 266,
    ESAC = 267,
    MYECHO = 268,
    READ = 269,
    RETURN = 270,
    EXIT = 271,
    LOCAL = 272,
    ELIF = 273,
    ELSE = 274,
    FI = 275,
    DECLARE = 276,
    TEST = 277,
    EXPR = 278,
    O = 279,
    A = 280,
    N = 281,
    Z = 282,
    EQ = 283,
    NE = 284,
    GT = 285,
    GE = 286,
    LT = 287,
    LE = 288,
    ID = 289,
    CHAINE = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "compilateur.y"
char *strval; int intval; listQ* listeQ; quads *quad; quadOP *operateur;

#line 175 "compilateur.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILATEUR_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,    43,    52,     2,     2,
      46,    40,    42,    49,     2,    50,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    37,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,    41,    45,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    37,    37,    45,    48,    53,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    78,    83,    84,    85,    88,    89,    92,    93,
      94,    95,    96,    99,   100,   101,   104,   113,   119,   122,
     123,   126,   127,   130,   131,   132,   133,   136,   137,   138,
     139,   142,   143,   146,   147,   148,   149,   150,   151,   154,
     159,   160,   165,   183,   187,   191,   196,   200,   203,   218,
     224,   242,   249,   255,   256,   274,   288,   289,   315,   323,
     337,   342,   342,   344,   344,   344,   347,   350,   351,   354,
     355
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "FOR", "DO", "DONE", "IN",
  "WHILE", "UNTIL", "CASE", "ESAC", "MYECHO", "READ", "RETURN", "EXIT",
  "LOCAL", "ELIF", "ELSE", "FI", "DECLARE", "TEST", "EXPR", "O", "A", "N",
  "Z", "EQ", "NE", "GT", "GE", "LT", "LE", "ID", "CHAINE", "';'", "'='",
  "'['", "']'", "')'", "'|'", "'*'", "'$'", "'{'", "'}'", "'('", "'!'",
  "'?'", "'+'", "'-'", "'/'", "'%'", "$accept", "programme",
  "liste_instructions", "instruction", "else_part", "liste_cas", "filtre",
  "liste_operandes", "concatenation", "test_bloc", "test_expr",
  "test_expr2", "test_expr3", "test_instruction", "operateur1",
  "operateur2", "operande", "somme_entiere", "produit_entier",
  "operande_entier", "plus_ou_moin", "fois_div_mod",
  "declaration_de_fonction", "decl_loc", "appel_de_fonction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    59,    61,    91,    93,
      41,   124,    42,    36,   123,   125,    40,    33,    63,    43,
      45,    47,    37
};
# endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     184,    42,    -1,    42,    42,   197,   199,    44,   -11,   -11,
      69,    54,   111,    80,   -64,   -64,   -64,    40,   126,   160,
     144,   150,   -64,   -64,   100,   178,   167,   197,   -64,   142,
     -64,    24,   -11,   -64,   -64,   -64,    56,   -64,   152,   197,
     -11,   181,   197,   -64,   184,   -64,   -64,    40,    97,   169,
     164,   200,   -64,   -64,   197,   215,   184,   214,   199,   184,
     184,   -64,   -64,   168,    48,   -64,   -21,   201,   -64,   -11,
     -64,   202,   170,   172,   -64,   -64,    28,   204,   197,   -64,
     210,   195,   -64,     0,    40,   -64,   197,   213,   -64,    40,
      40,   197,   -64,   -64,   -64,   -64,   -64,   -64,   197,    12,
     184,    11,     8,    19,    81,   -11,   199,   211,   -64,   -64,
     -64,    17,    65,    84,   216,   136,   -64,   -11,   -64,   -64,
     -64,   -11,   -64,   207,   217,   220,   -64,   -64,     1,   197,
     197,   200,   -64,   -64,    42,   184,   232,    20,   184,   -64,
     -64,   -11,   -64,   177,   -64,   -64,   114,   184,   173,    27,
     -64,   -11,   -64,   172,   -64,   147,   -64,   197,   162,   -64,
     197,   249,    80,   -64,   -64,    21,   219,   -64,   184,   218,
     -64,   -64,   221,   222,   -11,   -64,   197,   225,    91,   184,
     -64,   223,   226,    99,   224,   227,   228,   229,   -64,    12,
     -64,   148,   -64,   -64,   -64,   230,   197,   -64,   -64,   -64,
     194,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    19,    21,
       0,    90,     0,     2,     4,    17,    18,     0,     0,     0,
       0,     0,    61,    65,     0,     0,     0,    14,    34,    15,
      78,     0,     0,    81,    82,    20,     0,    22,     0,     0,
       0,     0,    89,     1,     0,    51,    52,     0,     0,     0,
      38,    40,    42,    45,     0,    37,     0,     0,     0,     0,
       0,    62,    63,     0,     0,    64,     0,     0,    33,     0,
      74,     0,     0,    69,    71,    79,     0,     0,     5,    37,
       0,     0,     3,     0,     0,    46,     0,     0,    36,     0,
       0,    49,    53,    54,    55,    56,    57,    58,     0,    25,
       0,     0,     0,     0,     0,     0,    90,     0,    28,    29,
      32,     0,     0,     0,     0,     0,    80,     0,    83,    84,
      85,     0,    77,     0,     0,     0,    88,    43,     0,    47,
       0,    39,    41,    50,     0,     0,     0,     0,     0,    11,
      12,     0,    59,     0,    67,    13,     0,     0,     0,     0,
      16,     0,    72,    68,    70,     0,     7,     0,     0,    44,
      48,     0,    24,     8,     9,     0,     0,    66,     0,     0,
      30,    31,     0,     0,     0,    75,     6,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,    86,    25,
      60,     0,    27,    35,    73,     0,     0,    23,    26,    76,
       0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -40,   -42,    74,   -64,   153,     5,   -36,     4,
     -37,   176,   180,   231,   -64,   -64,    -5,   166,   156,    -4,
     -63,   -64,   -64,   -64,   212
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,   136,   111,   112,    42,    49,    18,
      50,    51,    52,    53,    54,    98,    88,    72,    73,    74,
      36,   121,    15,   158,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    28,    82,    78,    35,    37,    28,    20,    21,   117,
      83,    27,    55,   108,   109,   139,    99,   138,    91,   102,
     103,   110,    68,    30,    89,    89,   140,   164,   180,   145,
     134,   135,    31,    19,    79,    32,    80,    68,    33,    34,
     127,   159,    55,    55,    44,    22,    23,   128,    44,    79,
     129,   108,   109,    28,    24,    44,    44,    44,    70,   110,
     137,    30,   122,   101,    17,   114,    45,    46,    71,   172,
      31,   105,   123,    32,    22,    23,    33,    34,    29,    55,
     117,    79,   106,    24,    55,    55,    47,    48,    22,    23,
      75,    39,    40,   133,   160,   162,    68,    26,   165,    76,
      41,    28,     1,    38,     2,   147,   148,   169,     3,     4,
       5,    43,     6,     7,     8,     9,    44,   154,   178,   141,
      10,   176,   149,    45,    46,    79,   142,    44,   182,   142,
      56,    22,    23,    11,    61,   192,   188,   166,   161,   189,
      24,    82,    62,    84,    63,   166,    64,   173,    65,    82,
      59,     1,    79,     2,   168,   148,    60,     3,     4,     5,
     200,     6,     7,     8,     9,     1,    57,     2,    58,    10,
     186,     3,     4,     5,   151,     6,     7,     8,     9,   177,
      69,   152,    11,    10,   198,   174,    66,     1,    89,     2,
      77,    79,   175,     3,     4,     5,    11,     6,     7,     8,
       9,    61,   104,    22,    23,    10,    86,   170,   171,    62,
     116,    67,    24,    64,   118,    65,    87,   167,    11,    33,
      34,    81,   100,   119,   120,    90,    33,    34,    22,    23,
     201,    22,    23,    22,    23,   113,   115,    24,   124,   126,
      24,   155,    26,    92,    93,    94,    95,    96,    97,   125,
     130,   144,   163,   179,   183,   150,   156,   157,   181,   187,
     184,   185,   191,   197,   146,   131,   196,   195,   190,   193,
     132,   143,   194,   153,     0,   199,   107,     0,     0,    85
};

static const yytype_int16 yycheck[] =
{
       5,     6,    44,    39,     8,     9,    11,     3,     4,    72,
      47,     6,    17,    34,    35,     7,    56,     6,    54,    59,
      60,    42,    27,    34,    24,    24,     7,     7,     7,    12,
      18,    19,    43,    34,    39,    46,    40,    42,    49,    50,
      40,    40,    47,    48,    36,    34,    35,    84,    36,    54,
      86,    34,    35,    58,    43,    36,    36,    36,    34,    42,
     100,    34,    34,    58,    22,    69,    26,    27,    44,    42,
      43,    23,    44,    46,    34,    35,    49,    50,    34,    84,
     143,    86,    34,    43,    89,    90,    46,    47,    34,    35,
      34,    37,    38,    98,   130,   135,   101,    43,   138,    43,
      46,   106,     3,    34,     5,    40,    41,   147,     9,    10,
      11,     0,    13,    14,    15,    16,    36,   121,   158,    38,
      21,   157,    38,    26,    27,   130,    45,    36,   168,    45,
       4,    34,    35,    34,    34,    36,    45,   141,   134,   179,
      43,   183,    42,    46,    44,   149,    46,   151,    48,   191,
       6,     3,   157,     5,    40,    41,     6,     9,    10,    11,
     196,    13,    14,    15,    16,     3,     6,     5,     8,    21,
     174,     9,    10,    11,    38,    13,    14,    15,    16,    17,
      38,    45,    34,    21,    36,    38,     8,     3,    24,     5,
      38,   196,    45,     9,    10,    11,    34,    13,    14,    15,
      16,    34,    34,    34,    35,    21,    37,    34,    35,    42,
      40,    44,    43,    46,    42,    48,    47,    40,    34,    49,
      50,    40,     8,    51,    52,    25,    49,    50,    34,    35,
      36,    34,    35,    34,    35,    34,    34,    43,    34,    44,
      43,    34,    43,    28,    29,    30,    31,    32,    33,    39,
      37,    40,    20,     4,    36,    39,    39,    37,    39,    34,
      39,    39,    36,   189,   111,    89,    37,    39,    45,    45,
      90,   105,    45,   117,    -1,    45,    64,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     9,    10,    11,    13,    14,    15,    16,
      21,    34,    54,    55,    56,    75,    77,    22,    62,    34,
      62,    62,    34,    35,    43,    69,    43,    60,    69,    34,
      34,    43,    46,    49,    50,    72,    73,    72,    34,    37,
      38,    46,    60,     0,    36,    26,    27,    46,    47,    61,
      63,    64,    65,    66,    67,    69,     4,     6,     8,     6,
       6,    34,    42,    44,    46,    48,     8,    44,    69,    38,
      34,    44,    70,    71,    72,    34,    43,    38,    61,    69,
      72,    40,    56,    63,    46,    66,    37,    47,    69,    24,
      25,    61,    28,    29,    30,    31,    32,    33,    68,    55,
       8,    60,    55,    55,    34,    23,    34,    77,    34,    35,
      42,    58,    59,    34,    72,    34,    40,    73,    42,    51,
      52,    74,    34,    44,    34,    39,    44,    40,    63,    61,
      37,    64,    65,    69,    18,    19,    57,    55,     6,     7,
       7,    38,    45,    70,    40,    12,    59,    40,    41,    38,
      39,    38,    45,    71,    72,    34,    39,    37,    76,    40,
      61,    62,    55,    20,     7,    55,    72,    40,    40,    55,
      34,    35,    42,    72,    38,    45,    61,    17,    55,     4,
       7,    39,    55,    36,    39,    39,    72,    34,    45,    55,
      45,    36,    36,    45,    45,    39,    37,    57,    36,    45,
      61,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    75,    76,    76,    77,
      77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     6,     5,     6,     6,
       7,     5,     5,     5,     2,     2,     5,     1,     1,     1,
       2,     1,     2,     5,     2,     0,     6,     5,     1,     1,
       3,     3,     1,     2,     1,     7,     2,     1,     2,     3,
       1,     3,     1,     3,     4,     1,     2,     3,     4,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       7,     1,     2,     2,     2,     1,     5,     4,     3,     1,
       3,     1,     4,     7,     2,     5,     8,     3,     1,     2,
       3,     1,     1,     1,     1,     1,     7,     6,     0,     2,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 37 "compilateur.y"
                   {
  printf("programme->liste_instruction\n\nAffichage Lglobal:\n");
  Laffiche(Lglobal);
  printf("\nFree Lglobal:\n");
  Lfree(Lglobal);
  }
#line 1506 "compilateur.tab.c"
    break;

  case 3:
#line 45 "compilateur.y"
                                   {
  printf("liste_instruction->liste_instructions ; instruction\n");
}
#line 1514 "compilateur.tab.c"
    break;

  case 4:
#line 48 "compilateur.y"
             {
  printf("liste_instruction->instruction\n");
}
#line 1522 "compilateur.tab.c"
    break;

  case 5:
#line 53 "compilateur.y"
                                                       { printf("instruction-> ID = concatenation\n");
  quadOP* res= QOcreat(QO_ID,(yyvsp[-2].strval),0);
  quads *q=Qcreat(Q_EQUAL,res,(yyvsp[0].operateur),NULL);
  Lappend(Lglobal,q);
}
#line 1532 "compilateur.tab.c"
    break;

  case 6:
#line 58 "compilateur.y"
                                                       { printf("instruction-> ID [ operande_entier ] = concatenation\n");}
#line 1538 "compilateur.tab.c"
    break;

  case 7:
#line 59 "compilateur.y"
                                                       { printf("instruction-> DECLARE ID [ ENTIER ] \n");}
#line 1544 "compilateur.tab.c"
    break;

  case 8:
#line 60 "compilateur.y"
                                                       { printf("instruction-> IF test_bloc THEN liste_instructions else_part FI \n");}
#line 1550 "compilateur.tab.c"
    break;

  case 9:
#line 61 "compilateur.y"
                                                       { printf("instruction->FOR ID DO IN liste_instructions DONE \n");}
#line 1556 "compilateur.tab.c"
    break;

  case 10:
#line 62 "compilateur.y"
                                                       { printf("instruction-> FOR ID IN liste_operandes DO liste_instructions DONE  \n");}
#line 1562 "compilateur.tab.c"
    break;

  case 11:
#line 63 "compilateur.y"
                                                       { printf("instruction-> WHILE test_bloc DO liste_instructions DONE \n");}
#line 1568 "compilateur.tab.c"
    break;

  case 12:
#line 64 "compilateur.y"
                                                       { printf("instruction-> UNTIL test_bloc DO liste_instructions DONE \n");}
#line 1574 "compilateur.tab.c"
    break;

  case 13:
#line 65 "compilateur.y"
                                                       { printf("instruction-> CASE operande IN liste_cas ESAC \n");}
#line 1580 "compilateur.tab.c"
    break;

  case 14:
#line 66 "compilateur.y"
                                                       { printf("instruction-> MYECHO liste_operandes \n");}
#line 1586 "compilateur.tab.c"
    break;

  case 15:
#line 67 "compilateur.y"
                                                       { printf("instruction-> READ ID \n");}
#line 1592 "compilateur.tab.c"
    break;

  case 16:
#line 68 "compilateur.y"
                                                       { printf("instruction-> READ ID [ operande_entier ] \n");}
#line 1598 "compilateur.tab.c"
    break;

  case 17:
#line 69 "compilateur.y"
                                                       { printf("instruction-> declaration_de_fonction \n");}
#line 1604 "compilateur.tab.c"
    break;

  case 18:
#line 70 "compilateur.y"
                                                       { printf("instruction-> appel_de_fonction \n");}
#line 1610 "compilateur.tab.c"
    break;

  case 19:
#line 71 "compilateur.y"
                                                       { printf("instruction-> RETURN \n");}
#line 1616 "compilateur.tab.c"
    break;

  case 20:
#line 72 "compilateur.y"
                                                       { printf("instruction-> RETURN operande_entier \n");}
#line 1622 "compilateur.tab.c"
    break;

  case 21:
#line 73 "compilateur.y"
       { 
  printf("instruction->EXIT\n");
  quads *q=Qcreat(Q_EXIT,NULL,NULL,NULL);
  Lappend(Lglobal,q);
 }
#line 1632 "compilateur.tab.c"
    break;

  case 22:
#line 78 "compilateur.y"
                       { 
  printf("instruction->EXIT operande_entier\n");
  }
#line 1640 "compilateur.tab.c"
    break;

  case 23:
#line 83 "compilateur.y"
                                                  { printf("else_part->ELIF test_bloc THEN liste_instructions else_part\n");}
#line 1646 "compilateur.tab.c"
    break;

  case 24:
#line 84 "compilateur.y"
                                                  { printf("else_part->ELSE liste_instructions\n");}
#line 1652 "compilateur.tab.c"
    break;

  case 25:
#line 85 "compilateur.y"
                                                  { printf("else_part->empty\n");}
#line 1658 "compilateur.tab.c"
    break;

  case 26:
#line 88 "compilateur.y"
                                                 { printf("liste_cas->liste_cas filtre ) liste_instructions ; ; \n");}
#line 1664 "compilateur.tab.c"
    break;

  case 27:
#line 89 "compilateur.y"
                                                 { printf("liste_cas->filtre ) liste_instructions ; ; \n");}
#line 1670 "compilateur.tab.c"
    break;

  case 28:
#line 92 "compilateur.y"
                     { printf("filtre->MOT\n");}
#line 1676 "compilateur.tab.c"
    break;

  case 29:
#line 93 "compilateur.y"
                     { printf("filtre->CHAINE\n");}
#line 1682 "compilateur.tab.c"
    break;

  case 30:
#line 94 "compilateur.y"
                     { printf("filtre->filtre | MOT\n");}
#line 1688 "compilateur.tab.c"
    break;

  case 31:
#line 95 "compilateur.y"
                     { printf("filtre->filtre | CHAINE\n");}
#line 1694 "compilateur.tab.c"
    break;

  case 32:
#line 96 "compilateur.y"
                     { printf("filtre-> *\n");}
#line 1700 "compilateur.tab.c"
    break;

  case 33:
#line 99 "compilateur.y"
                              { printf("liste_operandes-> liste_operandes operande \n");}
#line 1706 "compilateur.tab.c"
    break;

  case 34:
#line 100 "compilateur.y"
                              { printf("liste_operandes-> operande \n");}
#line 1712 "compilateur.tab.c"
    break;

  case 35:
#line 101 "compilateur.y"
                              { printf("liste_operandes-> $ { ID [ * ] } \n");}
#line 1718 "compilateur.tab.c"
    break;

  case 36:
#line 104 "compilateur.y"
                       { 
  printf("concatenation-> concatenation operande \n");

  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_CONCAT,temp,(yyvsp[-1].operateur),(yyvsp[0].operateur));

  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
}
#line 1732 "compilateur.tab.c"
    break;

  case 37:
#line 113 "compilateur.y"
           { 
  printf("concatenation-> operande \n");  
  (yyval.operateur)=(yyvsp[0].operateur);
}
#line 1741 "compilateur.tab.c"
    break;

  case 38:
#line 119 "compilateur.y"
                { printf("test_bloc-> TEST test_exp \n");}
#line 1747 "compilateur.tab.c"
    break;

  case 39:
#line 122 "compilateur.y"
                       { printf("test_expr-> test_expr O test_expr2 \n");}
#line 1753 "compilateur.tab.c"
    break;

  case 40:
#line 123 "compilateur.y"
                       { printf("test_expr-> test_expr2 \n");}
#line 1759 "compilateur.tab.c"
    break;

  case 41:
#line 126 "compilateur.y"
                        { printf("test_expr2-> test_expr2 A test_expr3 \n");}
#line 1765 "compilateur.tab.c"
    break;

  case 42:
#line 127 "compilateur.y"
                        { printf("test_expr2-> test_expr3 \n");}
#line 1771 "compilateur.tab.c"
    break;

  case 43:
#line 130 "compilateur.y"
                        { printf("test_expr3-> ( test_expr ) \n");}
#line 1777 "compilateur.tab.c"
    break;

  case 44:
#line 131 "compilateur.y"
                        { printf("test_expr3-> ! ( test_expr ) \n");}
#line 1783 "compilateur.tab.c"
    break;

  case 45:
#line 132 "compilateur.y"
                        { printf("test_expr3-> test_instruction \n");}
#line 1789 "compilateur.tab.c"
    break;

  case 46:
#line 133 "compilateur.y"
                        { printf("test_expr3-> ! test_instruction \n");}
#line 1795 "compilateur.tab.c"
    break;

  case 47:
#line 136 "compilateur.y"
                                      { printf("test_instruction-> concatenation = concatenation \n");}
#line 1801 "compilateur.tab.c"
    break;

  case 48:
#line 137 "compilateur.y"
                                      { printf("test_instruction-> concatenation != concatenation \n");}
#line 1807 "compilateur.tab.c"
    break;

  case 49:
#line 138 "compilateur.y"
                                      { printf("test_instruction-> operateur1 concatenation \n");}
#line 1813 "compilateur.tab.c"
    break;

  case 50:
#line 139 "compilateur.y"
                                      { printf("test_instruction-> operande operateur2 operande \n");}
#line 1819 "compilateur.tab.c"
    break;

  case 53:
#line 146 "compilateur.y"
    { printf("operateur2-> -eq\n");}
#line 1825 "compilateur.tab.c"
    break;

  case 54:
#line 147 "compilateur.y"
    { printf("operateur2-> -ne\n");}
#line 1831 "compilateur.tab.c"
    break;

  case 55:
#line 148 "compilateur.y"
    { printf("operateur2-> -gt\n");}
#line 1837 "compilateur.tab.c"
    break;

  case 56:
#line 149 "compilateur.y"
    { printf("operateur2-> -ge\n");}
#line 1843 "compilateur.tab.c"
    break;

  case 57:
#line 150 "compilateur.y"
    { printf("operateur2-> -lt\n");}
#line 1849 "compilateur.tab.c"
    break;

  case 58:
#line 151 "compilateur.y"
    { printf("operateur2-> -le\n");}
#line 1855 "compilateur.tab.c"
    break;

  case 59:
#line 154 "compilateur.y"
               { 
  printf("operande-> $ { ID }\n");
  (yyval.operateur)=QOcreat(QO_ID,(yyvsp[-1].strval),0);
  free((yyvsp[-1].strval));
  }
#line 1865 "compilateur.tab.c"
    break;

  case 60:
#line 159 "compilateur.y"
                                         { printf("operande-> $ { ID [ operande_entier ] }\n");}
#line 1871 "compilateur.tab.c"
    break;

  case 61:
#line 160 "compilateur.y"
     { 
  printf("operande-> MOT\n");
  (yyval.operateur)=QOcreat(QO_STR,(yyvsp[0].strval),0);
  free((yyvsp[0].strval));
  }
#line 1881 "compilateur.tab.c"
    break;

  case 62:
#line 165 "compilateur.y"
         { 
  printf("operande-> $ ENTIER\n");

  int entier;
  if(ToInt(&entier,(yyvsp[0].strval))){ // on vérifie que c'est bien un entier

    int taille=(int)((ceil(log10(entier))+1)*sizeof(char));
    char id[taille+2];
    id[taille+1]='\0';
    sprintf(id,"$%d",entier);

    (yyval.operateur)=QOcreat(QO_ID,id,0);
    free((yyvsp[0].strval));

  }else{ // $a ou $1mp
      printf("error: operande->$ENTIER ne doit contenir que des chiffres\n");
  }
}
#line 1904 "compilateur.tab.c"
    break;

  case 63:
#line 183 "compilateur.y"
          { 
  printf("operande-> $ *\n");
  (yyval.operateur)=QOcreat(QO_STR,"$*",0);
  }
#line 1913 "compilateur.tab.c"
    break;

  case 64:
#line 187 "compilateur.y"
          { 
  printf("operande-> $ ?\n");
  (yyval.operateur)=QOcreat(QO_STR,"$?",0);
  }
#line 1922 "compilateur.tab.c"
    break;

  case 65:
#line 191 "compilateur.y"
         { 
  printf("operande-> CHAINE:%s\n",(yyvsp[0].strval)); 
  (yyval.operateur)=QOcreat(QO_STR,(yyvsp[0].strval),0);
  free((yyvsp[0].strval));
  }
#line 1932 "compilateur.tab.c"
    break;

  case 66:
#line 196 "compilateur.y"
                                 { 
  printf("operande-> $ ( EXPR somme_entiere )\n");
  (yyval.operateur)=(yyvsp[-1].operateur);
  }
#line 1941 "compilateur.tab.c"
    break;

  case 67:
#line 200 "compilateur.y"
                                         { printf("operande-> $ ( appel_de_fonction )\n");}
#line 1947 "compilateur.tab.c"
    break;

  case 68:
#line 203 "compilateur.y"
                                          { 
  printf("somme_entiere-> somme_entiere plus_ou_moin produit_entier \n");

  quadOP *temp=QOcreat_temp();

  quads *q=NULL;
  if((yyvsp[-1].intval)){
    q=Qcreat(Q_ADD,temp,(yyvsp[-2].operateur),(yyvsp[0].operateur));
  }else{
    q=Qcreat(Q_LESS,temp,(yyvsp[-2].operateur),(yyvsp[0].operateur));
  }
  Lappend(Lglobal,q);

  (yyval.operateur)=temp;
}
#line 1967 "compilateur.tab.c"
    break;

  case 69:
#line 218 "compilateur.y"
                 { 
  printf("somme_entiere-> produit_entier \n");
  (yyval.operateur)=(yyvsp[0].operateur);
}
#line 1976 "compilateur.tab.c"
    break;

  case 70:
#line 224 "compilateur.y"
                                            { 
  printf("produit_entier-> produit_entier fois_div_mod operande_entier\n");

  quadOP *temp=QOcreat_temp();
  quads *q=NULL;
  switch((yyvsp[-1].intval)){
    case 1:
      q=Qcreat(Q_MUL,temp,(yyvsp[-2].operateur),(yyvsp[0].operateur));
      break;
    case 2:
      q=Qcreat(Q_DIV,temp,(yyvsp[-2].operateur),(yyvsp[0].operateur));
      break;
    case 3:
      q=Qcreat(Q_MOD,temp,(yyvsp[-2].operateur),(yyvsp[0].operateur));
      break;
  }
  Lappend(Lglobal,q);
}
#line 1999 "compilateur.tab.c"
    break;

  case 71:
#line 242 "compilateur.y"
                 { 
  printf("produit_entier-> operande_entier \n");
  (yyval.operateur)=(yyvsp[0].operateur);
  }
#line 2008 "compilateur.tab.c"
    break;

  case 72:
#line 249 "compilateur.y"
              { 
  printf("operande_entier-> $ { ID } \n");
    quadOP* op=QOcreat(QO_ID,(yyvsp[-1].strval),0);
    (yyval.operateur)=op;
    free((yyvsp[-1].strval));
  }
#line 2019 "compilateur.tab.c"
    break;

  case 73:
#line 255 "compilateur.y"
                                                      { printf("operande_entier-> $ { ID [ operande_entier ] } \n");}
#line 2025 "compilateur.tab.c"
    break;

  case 74:
#line 256 "compilateur.y"
         { 
  printf("operande_entier-> $ ENTIER \n");
  int entier;
  if(ToInt(&entier,(yyvsp[0].strval))){ // on vérifie que c'est bien un entier

    int taille=(int)((ceil(log10(entier))+1)*sizeof(char));
    char id[taille+2];
    id[taille+1]='\0';
    sprintf(id,"$%d",entier);

    quadOP* op=QOcreat(QO_ID,id,0);
    (yyval.operateur)=op;
    free((yyvsp[0].strval));

  }else{ // $a ou $1mp
      printf("error: operande->$ENTIER ne doit contenir que des chiffres\n");
  }
  }
#line 2048 "compilateur.tab.c"
    break;

  case 75:
#line 274 "compilateur.y"
                              { 
  printf("operande_entier-> plus_ou_moin $ { ID } \n");

    quadOP* temp=QOcreat_temp();
    quadOP* op2=QOcreat(QO_ID,(yyvsp[-1].strval),0);
    quads* q=NULL;
    if((yyvsp[-4].intval)){
      q=Qcreat(Q_ADD,temp,NULL,op2);
    }else{
      q=Qcreat(Q_LESS,temp,NULL,op2);
    }
    Lappend(Lglobal,q);
    free((yyvsp[-1].strval));
  }
#line 2067 "compilateur.tab.c"
    break;

  case 76:
#line 288 "compilateur.y"
                                                      { printf("operande_entier-> plus_ou_moin $ { ID [ operande_entier ] }\n");}
#line 2073 "compilateur.tab.c"
    break;

  case 77:
#line 289 "compilateur.y"
                       { 
  printf("operande_entier-> plus_ou_moin $ ENTIER\n");
  int entier;
  if(ToInt(&entier,(yyvsp[0].strval))){ // on vérifie que c'est bien un entier

    int taille=(int)((ceil(log10(entier))+1)*sizeof(char));
    char id[taille+2];
    id[taille+1]='\0';
    sprintf(id,"$%d",entier);

    quadOP* temp=QOcreat_temp();
    quadOP* op2=QOcreat(QO_ID,id,0);
    quads* q=NULL;
    if((yyvsp[-2].intval)){
      q=Qcreat(Q_ADD,temp,NULL,op2);
    }else{
      q=Qcreat(Q_LESS,temp,NULL,op2);
    }
    Lappend(Lglobal,q);
    (yyval.operateur)=temp;
    free((yyvsp[0].strval));

  }else{ // $a ou $1mp
      printf("error: operande->$ENTIER ne doit contenir que des chiffres\n");
  }
  }
#line 2104 "compilateur.tab.c"
    break;

  case 78:
#line 315 "compilateur.y"
     { 
  printf("operande_entier-> ENTIER \n");
  int entier;
  if(ToInt(&entier,(yyvsp[0].strval))){
    (yyval.operateur)=QOcreat(QO_CST,NULL,entier);
    free((yyvsp[0].strval));
  }
}
#line 2117 "compilateur.tab.c"
    break;

  case 79:
#line 323 "compilateur.y"
                  { 
  printf("operande_entier-> plus_ou_moin ENTIER\n");
  int entier;
  if(ToInt(&entier,(yyvsp[0].strval))){
    if((yyvsp[-1].intval)){
      (yyval.operateur)=QOcreat(QO_CST,NULL,entier);
    }
    else{

      (yyval.operateur)=QOcreat(QO_CST,NULL,-entier);
    }
    free((yyvsp[0].strval));
  }
  }
#line 2136 "compilateur.tab.c"
    break;

  case 80:
#line 337 "compilateur.y"
                        { 
  printf("operande_entier-> ( somme_entiere ) \n");
  (yyval.operateur)=(yyvsp[-1].operateur);
  }
#line 2145 "compilateur.tab.c"
    break;

  case 81:
#line 342 "compilateur.y"
                  {(yyval.intval)=1;}
#line 2151 "compilateur.tab.c"
    break;

  case 82:
#line 342 "compilateur.y"
                                {(yyval.intval)=0;}
#line 2157 "compilateur.tab.c"
    break;

  case 83:
#line 344 "compilateur.y"
                  {(yyval.intval)=1;}
#line 2163 "compilateur.tab.c"
    break;

  case 84:
#line 344 "compilateur.y"
                               {(yyval.intval)=2;}
#line 2169 "compilateur.tab.c"
    break;

  case 85:
#line 344 "compilateur.y"
                                            {(yyval.intval)=3;}
#line 2175 "compilateur.tab.c"
    break;

  case 86:
#line 347 "compilateur.y"
                                               { printf("declaration_de_fonction-> ID ( ) { decl_loc liste_instructions }\n");}
#line 2181 "compilateur.tab.c"
    break;

  case 87:
#line 350 "compilateur.y"
                                        { printf("decl_loc-> decl_loc LOCAL ID = concatenation \n");}
#line 2187 "compilateur.tab.c"
    break;

  case 88:
#line 351 "compilateur.y"
                                        { printf("decl_loc-> empty \n");}
#line 2193 "compilateur.tab.c"
    break;

  case 89:
#line 354 "compilateur.y"
                    { printf("appel_de_fonction-> ID liste_operandes \n");}
#line 2199 "compilateur.tab.c"
    break;

  case 90:
#line 355 "compilateur.y"
                    { printf("appel_de_fonction-> ID \n");}
#line 2205 "compilateur.tab.c"
    break;


#line 2209 "compilateur.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 357 "compilateur.y"


void yyerror(const char * msg){
    fprintf(stderr, "Erreur syntaxique: %s\n",msg);
}
