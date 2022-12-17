/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

#line 85 "compilateur.tab.c"

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

#include "compilateur.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_THEN = 4,                       /* THEN  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_DO = 6,                         /* DO  */
  YYSYMBOL_DONE = 7,                       /* DONE  */
  YYSYMBOL_IN = 8,                         /* IN  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_UNTIL = 10,                     /* UNTIL  */
  YYSYMBOL_CASE = 11,                      /* CASE  */
  YYSYMBOL_ESAC = 12,                      /* ESAC  */
  YYSYMBOL_MYECHO = 13,                    /* MYECHO  */
  YYSYMBOL_READ = 14,                      /* READ  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_EXIT = 16,                      /* EXIT  */
  YYSYMBOL_LOCAL = 17,                     /* LOCAL  */
  YYSYMBOL_ELIF = 18,                      /* ELIF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_FI = 20,                        /* FI  */
  YYSYMBOL_DECLARE = 21,                   /* DECLARE  */
  YYSYMBOL_TEST = 22,                      /* TEST  */
  YYSYMBOL_EXPR = 23,                      /* EXPR  */
  YYSYMBOL_O = 24,                         /* O  */
  YYSYMBOL_A = 25,                         /* A  */
  YYSYMBOL_N = 26,                         /* N  */
  YYSYMBOL_Z = 27,                         /* Z  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_GT = 30,                        /* GT  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_LE = 33,                        /* LE  */
  YYSYMBOL_ID = 34,                        /* ID  */
  YYSYMBOL_CHAINE = 35,                    /* CHAINE  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '|'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '$'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* '!'  */
  YYSYMBOL_48_ = 48,                       /* '?'  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '/'  */
  YYSYMBOL_52_ = 52,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_M = 54,                         /* M  */
  YYSYMBOL_programme = 55,                 /* programme  */
  YYSYMBOL_liste_instructions = 56,        /* liste_instructions  */
  YYSYMBOL_instruction = 57,               /* instruction  */
  YYSYMBOL_else_part = 58,                 /* else_part  */
  YYSYMBOL_liste_cas = 59,                 /* liste_cas  */
  YYSYMBOL_filtre = 60,                    /* filtre  */
  YYSYMBOL_liste_operandes = 61,           /* liste_operandes  */
  YYSYMBOL_concatenation = 62,             /* concatenation  */
  YYSYMBOL_test_bloc = 63,                 /* test_bloc  */
  YYSYMBOL_test_expr = 64,                 /* test_expr  */
  YYSYMBOL_test_expr2 = 65,                /* test_expr2  */
  YYSYMBOL_test_expr3 = 66,                /* test_expr3  */
  YYSYMBOL_test_instruction = 67,          /* test_instruction  */
  YYSYMBOL_operateur1 = 68,                /* operateur1  */
  YYSYMBOL_operateur2 = 69,                /* operateur2  */
  YYSYMBOL_operande = 70,                  /* operande  */
  YYSYMBOL_somme_entiere = 71,             /* somme_entiere  */
  YYSYMBOL_produit_entier = 72,            /* produit_entier  */
  YYSYMBOL_operande_entier = 73,           /* operande_entier  */
  YYSYMBOL_plus_ou_moin = 74,              /* plus_ou_moin  */
  YYSYMBOL_fois_div_mod = 75,              /* fois_div_mod  */
  YYSYMBOL_declaration_de_fonction = 76,   /* declaration_de_fonction  */
  YYSYMBOL_decl_loc = 77,                  /* decl_loc  */
  YYSYMBOL_appel_de_fonction = 78          /* appel_de_fonction  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,    52,    52,    55,    63,    71,    82,    88,    89,    90,
     100,   101,   103,   116,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   142,   147,   159,   160,   163,   164,   167,
     168,   169,   170,   171,   174,   175,   176,   179,   188,   194,
     201,   210,   213,   231,   247,   248,   255,   256,   265,   272,
     279,   296,   326,   327,   330,   331,   332,   333,   334,   335,
     338,   343,   353,   358,   376,   380,   384,   389,   393,   396,
     411,   417,   436,   443,   449,   458,   476,   490,   508,   534,
     542,   556,   561,   561,   563,   563,   563,   566,   569,   570,
     573,   574
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "THEN", "FOR",
  "DO", "DONE", "IN", "WHILE", "UNTIL", "CASE", "ESAC", "MYECHO", "READ",
  "RETURN", "EXIT", "LOCAL", "ELIF", "ELSE", "FI", "DECLARE", "TEST",
  "EXPR", "O", "A", "N", "Z", "EQ", "NE", "GT", "GE", "LT", "LE", "ID",
  "CHAINE", "';'", "'='", "'['", "']'", "')'", "'|'", "'*'", "'$'", "'{'",
  "'}'", "'('", "'!'", "'?'", "'+'", "'-'", "'/'", "'%'", "$accept", "M",
  "programme", "liste_instructions", "instruction", "else_part",
  "liste_cas", "filtre", "liste_operandes", "concatenation", "test_bloc",
  "test_expr", "test_expr2", "test_expr3", "test_instruction",
  "operateur1", "operateur2", "operande", "somme_entiere",
  "produit_entier", "operande_entier", "plus_ou_moin", "fois_div_mod",
  "declaration_de_fonction", "decl_loc", "appel_de_fonction", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      68,    -5,     1,   -77,   -77,   172,   205,     6,   188,   188,
      14,   198,    53,    23,   -77,   -77,   -77,    71,   -77,   101,
      -5,    -5,   -77,   -77,   109,    62,   122,   172,   -77,    63,
     -77,     2,   188,   -77,   -77,   -77,    79,   -77,    74,   172,
     188,    75,   172,   -77,    68,   -77,   -77,    71,   183,    56,
     102,   111,   -77,   -77,   172,   232,   134,   136,   205,   -77,
     -77,   -77,   -77,   133,    -1,   -77,   208,   142,   -77,   188,
     -77,   146,   -20,    -8,   -77,   -77,    66,   152,   172,   -77,
     149,   150,   -77,   -14,    71,   -77,   172,   153,   -77,   -77,
     -77,   172,   -77,   -77,   -77,   -77,   -77,   -77,   172,    68,
      68,     7,   194,   199,    27,   188,   205,   171,   -77,   -77,
     -77,    -3,    47,   185,   174,   213,   -77,   188,   -77,   -77,
     -77,   188,   -77,   191,   180,   212,   -77,   -77,   -12,   172,
     172,    71,    71,   -77,    23,    11,    68,    68,    68,   188,
     -77,    26,   -77,   -77,    84,    68,   128,   178,   -77,   188,
     -77,    -8,   -77,   214,   -77,   172,   182,   -77,   172,   111,
     -77,   130,   -77,    18,    23,    23,   216,   -77,    68,   217,
     -77,   -77,   218,   227,   188,   -77,   172,   222,   114,   -77,
      68,   247,   -77,   261,   262,   225,   235,   118,   228,   229,
     233,   238,   -77,    -5,    23,   -77,   -77,   -77,   -77,   168,
     -77,   -77,   -77,   231,   172,   -77,   -77,   -77,   211,   273,
     -77,    68,    23,   130,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     2,     0,     0,     0,    20,    22,
       0,    91,     0,     3,     5,    18,    19,     0,     2,     0,
       0,     0,    62,    66,     0,     0,     0,    15,    35,    16,
      79,     0,     0,    82,    83,    21,     0,    23,     0,     0,
       0,     0,    90,     1,     0,    52,    53,     0,     0,     0,
      39,    41,    43,    46,     0,    38,     0,     0,     0,     2,
       2,    63,    64,     0,     0,    65,     0,     0,    34,     0,
      75,     0,     0,    70,    72,    80,     0,     0,     6,    38,
       0,     0,     4,     0,     0,    47,     0,     0,    37,     2,
       2,    50,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,    29,    30,
      33,     0,     0,     0,     0,     0,    81,     0,    84,    85,
      86,     0,    78,     0,     0,     0,    89,    44,     0,    48,
       0,     0,     0,    51,     2,     0,     0,     0,     0,     0,
      60,     0,    68,    14,     0,     0,     0,     0,    17,     0,
      73,    69,    71,     0,     8,     0,     0,    45,    49,    40,
      42,    26,    10,     0,     2,     2,     0,    67,     0,     0,
      31,    32,     0,     0,     0,    76,     7,     0,     0,     2,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,    25,     9,    12,    13,    61,     0,
      28,    36,    74,     0,     0,     2,    27,    77,     0,     0,
      88,     0,     2,    26,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,    -4,   -77,   -76,   -41,    65,   -77,   169,     5,   -35,
     -19,   -39,   148,   151,   234,   -77,   -77,    10,   176,   167,
      -2,   -67,   -77,   -77,   -77,   221
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    12,    13,    14,   181,   111,   112,    42,    49,
      18,    50,    51,    52,    53,    54,    98,    88,    72,    73,
      74,    36,   121,    15,   156,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      21,    59,    60,    82,    78,   117,    35,    37,    83,   143,
      89,    27,    89,   136,    56,    25,    28,    17,   162,    91,
     116,    28,   105,   134,   135,   182,   127,    55,   157,    33,
      34,   108,   109,   106,   118,    19,    70,    68,    80,   110,
      29,    22,    23,   119,   120,   128,    71,    44,    38,    79,
      24,   129,    68,    43,    44,   102,   103,    55,    55,    44,
     163,   164,   165,   101,    79,   139,   167,   114,    28,   169,
      66,     1,   140,     2,   117,    33,    34,     3,     4,     5,
     178,     6,     7,     8,     9,   131,   132,   145,   146,    10,
      22,    23,   186,    86,    55,   158,    79,    45,    46,    24,
     122,    69,    11,    87,   194,    22,    23,    57,   133,    58,
     123,    68,    77,    75,    24,    81,    28,    47,    48,   152,
     176,     1,    76,     2,   168,   146,    89,     3,     4,     5,
     161,     6,     7,     8,     9,   212,    90,   166,    99,    10,
      79,    55,    55,    61,   100,   166,    82,   173,   179,   180,
      44,    62,    11,    63,   200,    64,    61,    65,    82,   192,
     183,   184,   170,   171,    62,    79,    67,   104,    64,   208,
      65,     1,   190,     2,   205,   193,   113,     3,     4,     5,
     115,     6,     7,     8,     9,     1,   124,     2,   125,    10,
     130,     3,     4,     5,   126,     6,     7,     8,     9,   177,
     137,   209,    11,    10,   206,   138,    22,    23,   213,    45,
      46,   142,    30,   148,    79,    24,    11,    22,    23,   154,
     172,    31,    30,   147,    32,   153,    24,    33,    34,    84,
     140,    31,    22,    23,    32,    39,    40,    33,    34,    22,
      23,    26,   108,   109,    41,    22,    23,   210,    26,   155,
     110,   149,   174,   187,    24,   185,   191,   188,   150,   175,
      92,    93,    94,    95,    96,    97,   189,   195,   196,   197,
     198,   199,   203,   201,   202,   204,   207,   211,   214,   159,
     144,   141,    85,   160,   151,   107
};

static const yytype_uint8 yycheck[] =
{
       4,    20,    21,    44,    39,    72,     8,     9,    47,    12,
      24,     6,    24,     6,    18,     5,     6,    22,     7,    54,
      40,    11,    23,    99,   100,     7,    40,    17,    40,    49,
      50,    34,    35,    34,    42,    34,    34,    27,    40,    42,
      34,    34,    35,    51,    52,    84,    44,    36,    34,    39,
      43,    86,    42,     0,    36,    59,    60,    47,    48,    36,
     136,   137,   138,    58,    54,    38,    40,    69,    58,   145,
       8,     3,    45,     5,   141,    49,    50,     9,    10,    11,
     156,    13,    14,    15,    16,    89,    90,    40,    41,    21,
      34,    35,   168,    37,    84,   130,    86,    26,    27,    43,
      34,    38,    34,    47,   180,    34,    35,     6,    98,     8,
      44,   101,    38,    34,    43,    40,   106,    46,    47,   121,
     155,     3,    43,     5,    40,    41,    24,     9,    10,    11,
     134,    13,    14,    15,    16,   211,    25,   139,     4,    21,
     130,   131,   132,    34,     8,   147,   187,   149,    18,    19,
      36,    42,    34,    44,    36,    46,    34,    48,   199,    45,
     164,   165,    34,    35,    42,   155,    44,    34,    46,   204,
      48,     3,   174,     5,   193,   179,    34,     9,    10,    11,
      34,    13,    14,    15,    16,     3,    34,     5,    39,    21,
      37,     9,    10,    11,    44,    13,    14,    15,    16,    17,
       6,   205,    34,    21,    36,     6,    34,    35,   212,    26,
      27,    40,    34,    39,   204,    43,    34,    34,    35,    39,
      42,    43,    34,    38,    46,    34,    43,    49,    50,    46,
      45,    43,    34,    35,    46,    37,    38,    49,    50,    34,
      35,    43,    34,    35,    46,    34,    35,    36,    43,    37,
      42,    38,    38,    36,    43,    39,    34,    39,    45,    45,
      28,    29,    30,    31,    32,    33,    39,    20,     7,     7,
      45,    36,    39,    45,    45,    37,    45,     4,   213,   131,
     111,   105,    48,   132,   117,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     9,    10,    11,    13,    14,    15,    16,
      21,    34,    55,    56,    57,    76,    78,    22,    63,    34,
      54,    54,    34,    35,    43,    70,    43,    61,    70,    34,
      34,    43,    46,    49,    50,    73,    74,    73,    34,    37,
      38,    46,    61,     0,    36,    26,    27,    46,    47,    62,
      64,    65,    66,    67,    68,    70,    54,     6,     8,    63,
      63,    34,    42,    44,    46,    48,     8,    44,    70,    38,
      34,    44,    71,    72,    73,    34,    43,    38,    62,    70,
      73,    40,    57,    64,    46,    67,    37,    47,    70,    24,
      25,    62,    28,    29,    30,    31,    32,    33,    69,     4,
       8,    61,    54,    54,    34,    23,    34,    78,    34,    35,
      42,    59,    60,    34,    73,    34,    40,    74,    42,    51,
      52,    75,    34,    44,    34,    39,    44,    40,    64,    62,
      37,    54,    54,    70,    56,    56,     6,     6,     6,    38,
      45,    71,    40,    12,    60,    40,    41,    38,    39,    38,
      45,    72,    73,    34,    39,    37,    77,    40,    62,    65,
      66,    54,     7,    56,    56,    56,    73,    40,    40,    56,
      34,    35,    42,    73,    38,    45,    62,    17,    56,    18,
      19,    58,     7,    54,    54,    39,    56,    36,    39,    39,
      73,    34,    45,    54,    56,    20,     7,     7,    45,    36,
      36,    45,    45,    39,    37,    63,    36,    45,    62,    54,
      36,     4,    56,    54,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    76,    77,    77,
      78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     3,     1,     3,     6,     5,     8,
       6,     7,     8,     8,     5,     2,     2,     5,     1,     1,
       1,     2,     1,     2,     8,     2,     0,     6,     5,     1,
       1,     3,     3,     1,     2,     1,     7,     2,     1,     2,
       4,     1,     4,     1,     3,     4,     1,     2,     3,     4,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     7,     1,     2,     2,     2,     1,     5,     4,     3,
       1,     3,     1,     4,     7,     2,     5,     8,     3,     1,
       2,     3,     1,     1,     1,     1,     1,     7,     6,     0,
       2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* M: %empty  */
#line 52 "compilateur.y"
          {(yyval.intval)=Lglobal->taille;}
#line 1300 "compilateur.tab.c"
    break;

  case 3: /* programme: liste_instructions  */
#line 55 "compilateur.y"
                   {
  printf("programme->liste_instruction\n\nAffichage Lglobal:\n");
  Laffiche(Lglobal);
  printf("\nFree Lglobal:\n");
  Lfree(Lglobal);
  }
#line 1311 "compilateur.tab.c"
    break;

  case 4: /* liste_instructions: liste_instructions ';' instruction  */
#line 63 "compilateur.y"
                                   {
  printf("liste_instruction->liste_instructions ; instruction\n");

  quadOP *addr=QOcreat(QO_ADDR,NULL,0);
  quads *nextQuad=Qcreat(Q_GOTO,addr,NULL,NULL);
  addr->u.cst=Lglobal->taille+1;
  (yyval.operateur)=addr;
}
#line 1324 "compilateur.tab.c"
    break;

  case 5: /* liste_instructions: instruction  */
#line 71 "compilateur.y"
             {
  printf("liste_instruction->instruction\n");

  quadOP *addr=QOcreat(QO_ADDR,NULL,0);
  quads *nextQuad=Qcreat(Q_GOTO,addr,NULL,NULL);
  addr->u.cst=Lglobal->taille+1;
  (yyval.operateur)=addr;

}
#line 1338 "compilateur.tab.c"
    break;

  case 6: /* instruction: ID '=' concatenation  */
#line 82 "compilateur.y"
                                                       { printf("instruction-> ID = concatenation\n");
  quadOP* res= QOcreat(QO_ID,(yyvsp[-2].strval),0);
  quads *q=Qcreat(Q_EQUAL,res,(yyvsp[0].operateur),NULL);
  Lappend(Lglobal,q);
  free((yyvsp[-2].strval));
}
#line 1349 "compilateur.tab.c"
    break;

  case 7: /* instruction: ID '[' operande_entier ']' '=' concatenation  */
#line 88 "compilateur.y"
                                                       { printf("instruction-> ID [ operande_entier ] = concatenation\n");}
#line 1355 "compilateur.tab.c"
    break;

  case 8: /* instruction: DECLARE ID '[' ID ']'  */
#line 89 "compilateur.y"
                                                       { printf("instruction-> DECLARE ID [ ENTIER ] \n");}
#line 1361 "compilateur.tab.c"
    break;

  case 9: /* instruction: IF test_bloc M THEN liste_instructions M else_part FI  */
#line 90 "compilateur.y"
                                                           { 
  printf("instruction-> IF test_bloc THEN liste_instructions else_part FI \n");

  int addrM1=(yyvsp[-5].intval);
  int addrM2=(yyvsp[-2].intval);

  complete((yyvsp[-6].branchement)->True,addrM1+1);
  complete((yyvsp[-6].branchement)->False,addrM2+1);
 
}
#line 1376 "compilateur.tab.c"
    break;

  case 10: /* instruction: FOR ID DO IN liste_instructions DONE  */
#line 100 "compilateur.y"
                                                       { printf("instruction->FOR ID DO IN liste_instructions DONE \n");}
#line 1382 "compilateur.tab.c"
    break;

  case 11: /* instruction: FOR ID IN liste_operandes DO liste_instructions DONE  */
#line 101 "compilateur.y"
                                                       { printf("instruction-> FOR ID IN liste_operandes DO liste_instructions DONE  \n");}
#line 1388 "compilateur.tab.c"
    break;

  case 12: /* instruction: WHILE M test_bloc M DO liste_instructions M DONE  */
#line 103 "compilateur.y"
                                                   { 
  printf("instruction-> WHILE test_bloc DO liste_instructions DONE \n");

  int addrM0=(yyvsp[-6].intval);
  int addrM1=(yyvsp[-4].intval);
  int addrM2=(yyvsp[-1].intval);

  complete((yyvsp[-5].branchement)->True,addrM1+1);
  complete((yyvsp[-5].branchement)->False,addrM2+1);

  (yyvsp[-2].operateur)->u.cst=addrM0+1;

  }
#line 1406 "compilateur.tab.c"
    break;

  case 13: /* instruction: UNTIL M test_bloc M DO liste_instructions M DONE  */
#line 116 "compilateur.y"
                                                   { 
  printf("instruction-> UNTIL test_bloc DO liste_instructions DONE \n");

  int addrM0=(yyvsp[-6].intval);
  int addrM1=(yyvsp[-4].intval);
  int addrM2=(yyvsp[-1].intval);

  complete((yyvsp[-5].branchement)->True,addrM2+1);
  complete((yyvsp[-5].branchement)->False,addrM1+1);

  (yyvsp[-2].operateur)->u.cst=addrM0+1;
  
  }
#line 1424 "compilateur.tab.c"
    break;

  case 14: /* instruction: CASE operande IN liste_cas ESAC  */
#line 129 "compilateur.y"
                                                       { printf("instruction-> CASE operande IN liste_cas ESAC \n");}
#line 1430 "compilateur.tab.c"
    break;

  case 15: /* instruction: MYECHO liste_operandes  */
#line 130 "compilateur.y"
                                                       { printf("instruction-> MYECHO liste_operandes \n");}
#line 1436 "compilateur.tab.c"
    break;

  case 16: /* instruction: READ ID  */
#line 131 "compilateur.y"
                                                       { printf("instruction-> READ ID \n");}
#line 1442 "compilateur.tab.c"
    break;

  case 17: /* instruction: READ ID '[' operande_entier ']'  */
#line 132 "compilateur.y"
                                                       { printf("instruction-> READ ID [ operande_entier ] \n");}
#line 1448 "compilateur.tab.c"
    break;

  case 18: /* instruction: declaration_de_fonction  */
#line 133 "compilateur.y"
                                                       { printf("instruction-> declaration_de_fonction \n");}
#line 1454 "compilateur.tab.c"
    break;

  case 19: /* instruction: appel_de_fonction  */
#line 134 "compilateur.y"
                                                       { printf("instruction-> appel_de_fonction \n");}
#line 1460 "compilateur.tab.c"
    break;

  case 20: /* instruction: RETURN  */
#line 135 "compilateur.y"
                                                       { printf("instruction-> RETURN \n");}
#line 1466 "compilateur.tab.c"
    break;

  case 21: /* instruction: RETURN operande_entier  */
#line 136 "compilateur.y"
                                                       { printf("instruction-> RETURN operande_entier \n");}
#line 1472 "compilateur.tab.c"
    break;

  case 22: /* instruction: EXIT  */
#line 137 "compilateur.y"
       { 
  printf("instruction->EXIT\n");
  quads *q=Qcreat(Q_EXIT,NULL,NULL,NULL);
  Lappend(Lglobal,q);
 }
#line 1482 "compilateur.tab.c"
    break;

  case 23: /* instruction: EXIT operande_entier  */
#line 142 "compilateur.y"
                       { 
  printf("instruction->EXIT operande_entier\n");
  }
#line 1490 "compilateur.tab.c"
    break;

  case 24: /* else_part: ELIF M test_bloc M THEN liste_instructions M else_part  */
#line 147 "compilateur.y"
                                                        { 
  printf("else_part->ELIF test_bloc THEN liste_instructions else_part\n");

  int addrM0=(yyvsp[-6].intval);
  int addrM1=(yyvsp[-4].intval);
  int addrM2=(yyvsp[-1].intval);

  complete((yyvsp[-5].branchement)->True,addrM1+1);
  complete((yyvsp[-5].branchement)->False,addrM2+1);
  
  (yyvsp[-2].operateur)->u.cst=addrM2+1;
  }
#line 1507 "compilateur.tab.c"
    break;

  case 25: /* else_part: ELSE liste_instructions  */
#line 159 "compilateur.y"
                                                  { printf("else_part->ELSE liste_instructions\n");}
#line 1513 "compilateur.tab.c"
    break;

  case 26: /* else_part: %empty  */
#line 160 "compilateur.y"
                                                  { printf("else_part->empty\n");}
#line 1519 "compilateur.tab.c"
    break;

  case 27: /* liste_cas: liste_cas filtre ')' liste_instructions ';' ';'  */
#line 163 "compilateur.y"
                                                 { printf("liste_cas->liste_cas filtre ) liste_instructions ; ; \n");}
#line 1525 "compilateur.tab.c"
    break;

  case 28: /* liste_cas: filtre ')' liste_instructions ';' ';'  */
#line 164 "compilateur.y"
                                                 { printf("liste_cas->filtre ) liste_instructions ; ; \n");}
#line 1531 "compilateur.tab.c"
    break;

  case 29: /* filtre: ID  */
#line 167 "compilateur.y"
                     { printf("filtre->MOT\n");}
#line 1537 "compilateur.tab.c"
    break;

  case 30: /* filtre: CHAINE  */
#line 168 "compilateur.y"
                     { printf("filtre->CHAINE\n");}
#line 1543 "compilateur.tab.c"
    break;

  case 31: /* filtre: filtre '|' ID  */
#line 169 "compilateur.y"
                     { printf("filtre->filtre | MOT\n");}
#line 1549 "compilateur.tab.c"
    break;

  case 32: /* filtre: filtre '|' CHAINE  */
#line 170 "compilateur.y"
                     { printf("filtre->filtre | CHAINE\n");}
#line 1555 "compilateur.tab.c"
    break;

  case 33: /* filtre: '*'  */
#line 171 "compilateur.y"
                     { printf("filtre-> *\n");}
#line 1561 "compilateur.tab.c"
    break;

  case 34: /* liste_operandes: liste_operandes operande  */
#line 174 "compilateur.y"
                              { printf("liste_operandes-> liste_operandes operande \n");}
#line 1567 "compilateur.tab.c"
    break;

  case 35: /* liste_operandes: operande  */
#line 175 "compilateur.y"
                              { printf("liste_operandes-> operande \n");}
#line 1573 "compilateur.tab.c"
    break;

  case 36: /* liste_operandes: '$' '{' ID '[' '*' ']' '}'  */
#line 176 "compilateur.y"
                              { printf("liste_operandes-> $ { ID [ * ] } \n");}
#line 1579 "compilateur.tab.c"
    break;

  case 37: /* concatenation: concatenation operande  */
#line 179 "compilateur.y"
                       { 
  printf("concatenation-> concatenation operande \n");

  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_CONCAT,temp,(yyvsp[-1].operateur),(yyvsp[0].operateur));

  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
}
#line 1593 "compilateur.tab.c"
    break;

  case 38: /* concatenation: operande  */
#line 188 "compilateur.y"
           { 
  printf("concatenation-> operande \n");  
  (yyval.operateur)=(yyvsp[0].operateur);
}
#line 1602 "compilateur.tab.c"
    break;

  case 39: /* test_bloc: TEST test_expr  */
#line 194 "compilateur.y"
                { 
  printf("test_bloc-> TEST test_expr \n"); 
  (yyval.branchement)=(yyvsp[0].branchement);

  }
#line 1612 "compilateur.tab.c"
    break;

  case 40: /* test_expr: test_expr O M test_expr2  */
#line 201 "compilateur.y"
                         { 
  printf("test_expr-> test_expr O test_expr2 \n");

  complete((yyvsp[-3].branchement)->False,(yyvsp[-1].intval)+1);
  (yyval.branchement)=(yyvsp[0].branchement);
  listQ *T=Lconcat((yyvsp[-3].branchement)->True,(yyval.branchement)->True);
  (yyval.branchement)->True=T;

  }
#line 1626 "compilateur.tab.c"
    break;

  case 41: /* test_expr: test_expr2  */
#line 210 "compilateur.y"
             {  printf("test_expr-> test_expr2 \n"); (yyval.branchement)=(yyvsp[0].branchement); }
#line 1632 "compilateur.tab.c"
    break;

  case 42: /* test_expr2: test_expr2 A M test_expr3  */
#line 213 "compilateur.y"
                          { 
  printf("test_expr2-> test_expr2 A test_expr3 \n");

 // test_expr3
  quads *if_true3=Qcreat(Q_IF,NULL,(yyvsp[0].operateur),NULL);
  Lappend(Lglobal,if_true3);

  quads *if_false3=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,if_false3);

  complete((yyvsp[-3].branchement)->True,(yyvsp[-1].intval)+1);
  Lappend((yyvsp[-3].branchement)->False,if_false3);

  (yyval.branchement)=EMcreat();
  Lappend((yyval.branchement)->True,if_true3);
  (yyval.branchement)->False=(yyvsp[-3].branchement)->False;

  }
#line 1655 "compilateur.tab.c"
    break;

  case 43: /* test_expr2: test_expr3  */
#line 231 "compilateur.y"
             { 
  printf("test_expr2-> test_expr3 \n"); 
  
 // test_expr3
  quads *if_true3=Qcreat(Q_IF,NULL,(yyvsp[0].operateur),NULL);
  Lappend(Lglobal,if_true3);

  quads *if_false3=Qcreat(Q_GOTO,NULL,NULL,NULL);
  Lappend(Lglobal,if_false3);

  (yyval.branchement)=EMcreat();
  Lappend((yyval.branchement)->True,if_true3);
  Lappend((yyval.branchement)->False,if_false3);
  }
#line 1674 "compilateur.tab.c"
    break;

  case 44: /* test_expr3: '(' test_expr ')'  */
#line 247 "compilateur.y"
                        { printf("test_expr3-> ( test_expr ) \n"); (yyval.operateur)=(yyvsp[-1].branchement);}
#line 1680 "compilateur.tab.c"
    break;

  case 45: /* test_expr3: '!' '(' test_expr ')'  */
#line 248 "compilateur.y"
                        { 
  printf("test_expr3-> ! ( test_expr ) \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_NOT,temp,(yyvsp[-1].branchement),NULL);
  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
  }
#line 1692 "compilateur.tab.c"
    break;

  case 46: /* test_expr3: test_instruction  */
#line 255 "compilateur.y"
                        { printf("test_expr3-> test_instruction \n"); (yyval.operateur)=(yyvsp[0].operateur);}
#line 1698 "compilateur.tab.c"
    break;

  case 47: /* test_expr3: '!' test_instruction  */
#line 256 "compilateur.y"
                        { 
  printf("test_expr3-> ! test_instruction \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_NOT,temp,(yyvsp[0].operateur),NULL);
  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
  }
#line 1710 "compilateur.tab.c"
    break;

  case 48: /* test_instruction: concatenation '=' concatenation  */
#line 265 "compilateur.y"
                                      { 
  printf("test_instruction-> concatenation = concatenation \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_EQ,temp,(yyvsp[-2].operateur),(yyvsp[0].operateur));
  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
  }
#line 1722 "compilateur.tab.c"
    break;

  case 49: /* test_instruction: concatenation '!' '=' concatenation  */
#line 272 "compilateur.y"
                                      { 
  printf("test_instruction-> concatenation != concatenation \n");
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(Q_IF_NE,temp,(yyvsp[-3].operateur),(yyvsp[0].operateur));
  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
  }
#line 1734 "compilateur.tab.c"
    break;

  case 50: /* test_instruction: operateur1 concatenation  */
#line 279 "compilateur.y"
                           { 
  printf("test_instruction-> operateur1 concatenation \n");
  quadOP* temp=QOcreat_temp();
  
  int oper=0;
  switch((yyvsp[-1].intval)){
    case 1:
      oper=Q_IF_N;
      break;
    case 2:
      oper=Q_IF_Z;
      break;
  }
  quads *q=Qcreat(oper,temp,(yyvsp[0].operateur),NULL);
  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
  }
#line 1756 "compilateur.tab.c"
    break;

  case 51: /* test_instruction: operande operateur2 operande  */
#line 296 "compilateur.y"
                               { 
  printf("test_instruction-> operande operateur2 operande \n");
  int oper=0;
  switch((yyvsp[-1].intval)){
    case 1:
      oper=Q_IF_EQ;
      break;
    case 2:
      oper=Q_IF_NE;
      break;
    case 3:
      oper=Q_IF_GT;
      break;
    case 4:
      oper=Q_IF_GE;
      break;
    case 5:
      oper=Q_IF_LT;
      break;
    case 6:
      oper=Q_IF_LE;
      break;
  }
  quadOP *temp=QOcreat_temp();
  quads *q=Qcreat(oper,temp,(yyvsp[-2].operateur),(yyvsp[0].operateur));
  (yyval.operateur)=temp;
  Lappend(Lglobal,q);
  }
#line 1789 "compilateur.tab.c"
    break;

  case 52: /* operateur1: N  */
#line 326 "compilateur.y"
  {(yyval.intval)=1;}
#line 1795 "compilateur.tab.c"
    break;

  case 53: /* operateur1: Z  */
#line 327 "compilateur.y"
    {(yyval.intval)=2;}
#line 1801 "compilateur.tab.c"
    break;

  case 54: /* operateur2: EQ  */
#line 330 "compilateur.y"
    { printf("operateur2-> -eq\n"); (yyval.intval)=1;}
#line 1807 "compilateur.tab.c"
    break;

  case 55: /* operateur2: NE  */
#line 331 "compilateur.y"
    { printf("operateur2-> -ne\n"); (yyval.intval)=2;}
#line 1813 "compilateur.tab.c"
    break;

  case 56: /* operateur2: GT  */
#line 332 "compilateur.y"
    { printf("operateur2-> -gt\n"); (yyval.intval)=3;}
#line 1819 "compilateur.tab.c"
    break;

  case 57: /* operateur2: GE  */
#line 333 "compilateur.y"
    { printf("operateur2-> -ge\n"); (yyval.intval)=4;}
#line 1825 "compilateur.tab.c"
    break;

  case 58: /* operateur2: LT  */
#line 334 "compilateur.y"
    { printf("operateur2-> -lt\n"); (yyval.intval)=5;}
#line 1831 "compilateur.tab.c"
    break;

  case 59: /* operateur2: LE  */
#line 335 "compilateur.y"
    { printf("operateur2-> -le\n"); (yyval.intval)=6;}
#line 1837 "compilateur.tab.c"
    break;

  case 60: /* operande: '$' '{' ID '}'  */
#line 338 "compilateur.y"
               { 
  printf("operande-> $ { ID }\n");
  (yyval.operateur)=QOcreat(QO_ID,(yyvsp[-1].strval),0);
  free((yyvsp[-1].strval));
  }
#line 1847 "compilateur.tab.c"
    break;

  case 61: /* operande: '$' '{' ID '[' operande_entier ']' '}'  */
#line 343 "compilateur.y"
                                         {
   printf("operande-> $ { ID [ operande_entier ] }\n");

    printf("operande_entier-> $ { ID [ operande_entier ] } \n");
    quadOP* tab=QOcreat(QO_TAB,(yyvsp[-4].strval),0);
    quadOP* temp=QOcreat_temp();
    quads *q=Qcreat(Q_TAB_GIVE,temp,tab,(yyvsp[-2].operateur));
    Lappend(Lglobal,q);
    (yyval.operateur)=temp;
    free((yyvsp[-4].strval));
   }
#line 1863 "compilateur.tab.c"
    break;

  case 62: /* operande: ID  */
#line 353 "compilateur.y"
         { 
  printf("operande-> MOT\n");
  (yyval.operateur)=QOcreat(QO_STR,(yyvsp[0].strval),0);
  free((yyvsp[0].strval));
  }
#line 1873 "compilateur.tab.c"
    break;

  case 63: /* operande: '$' ID  */
#line 358 "compilateur.y"
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
#line 1896 "compilateur.tab.c"
    break;

  case 64: /* operande: '$' '*'  */
#line 376 "compilateur.y"
          { 
  printf("operande-> $ *\n");
  (yyval.operateur)=QOcreat(QO_STR,"$*",0);
  }
#line 1905 "compilateur.tab.c"
    break;

  case 65: /* operande: '$' '?'  */
#line 380 "compilateur.y"
          { 
  printf("operande-> $ ?\n");
  (yyval.operateur)=QOcreat(QO_STR,"$?",0);
  }
#line 1914 "compilateur.tab.c"
    break;

  case 66: /* operande: CHAINE  */
#line 384 "compilateur.y"
         { 
  printf("operande-> CHAINE:%s\n",(yyvsp[0].strval)); 
  (yyval.operateur)=QOcreat(QO_STR,(yyvsp[0].strval),0);
  free((yyvsp[0].strval));
  }
#line 1924 "compilateur.tab.c"
    break;

  case 67: /* operande: '$' '(' EXPR somme_entiere ')'  */
#line 389 "compilateur.y"
                                 { 
  printf("operande-> $ ( EXPR somme_entiere )\n");
  (yyval.operateur)=(yyvsp[-1].operateur);
  }
#line 1933 "compilateur.tab.c"
    break;

  case 68: /* operande: '$' '(' appel_de_fonction ')'  */
#line 393 "compilateur.y"
                                         { printf("operande-> $ ( appel_de_fonction )\n");}
#line 1939 "compilateur.tab.c"
    break;

  case 69: /* somme_entiere: somme_entiere plus_ou_moin produit_entier  */
#line 396 "compilateur.y"
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
#line 1959 "compilateur.tab.c"
    break;

  case 70: /* somme_entiere: produit_entier  */
#line 411 "compilateur.y"
                 { 
  printf("somme_entiere-> produit_entier \n");
  (yyval.operateur)=(yyvsp[0].operateur);
}
#line 1968 "compilateur.tab.c"
    break;

  case 71: /* produit_entier: produit_entier fois_div_mod operande_entier  */
#line 417 "compilateur.y"
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
  (yyval.operateur)=temp;
}
#line 1992 "compilateur.tab.c"
    break;

  case 72: /* produit_entier: operande_entier  */
#line 436 "compilateur.y"
                 { 
  printf("produit_entier-> operande_entier \n");
  (yyval.operateur)=(yyvsp[0].operateur);
  }
#line 2001 "compilateur.tab.c"
    break;

  case 73: /* operande_entier: '$' '{' ID '}'  */
#line 443 "compilateur.y"
              { 
  printf("operande_entier-> $ { ID } \n");
    quadOP* op=QOcreat(QO_ID,(yyvsp[-1].strval),0);
    (yyval.operateur)=op;
    free((yyvsp[-1].strval));
  }
#line 2012 "compilateur.tab.c"
    break;

  case 74: /* operande_entier: '$' '{' ID '[' operande_entier ']' '}'  */
#line 449 "compilateur.y"
                                         { 
  printf("operande_entier-> $ { ID [ operande_entier ] } \n");
  quadOP* tab=QOcreat(QO_TAB,(yyvsp[-4].strval),0);
  quadOP* temp=QOcreat_temp();
  quads *q=Qcreat(Q_TAB_GIVE,temp,tab,(yyvsp[-2].operateur));
  Lappend(Lglobal,q);
  (yyval.operateur)=temp;
  free((yyvsp[-4].strval));
  }
#line 2026 "compilateur.tab.c"
    break;

  case 75: /* operande_entier: '$' ID  */
#line 458 "compilateur.y"
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
#line 2049 "compilateur.tab.c"
    break;

  case 76: /* operande_entier: plus_ou_moin '$' '{' ID '}'  */
#line 476 "compilateur.y"
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
#line 2068 "compilateur.tab.c"
    break;

  case 77: /* operande_entier: plus_ou_moin '$' '{' ID '[' operande_entier ']' '}'  */
#line 490 "compilateur.y"
                                                      {
 printf("operande_entier-> plus_ou_moin $ { ID [ operande_entier ] }\n");

  quadOP* tab=QOcreat(QO_TAB,(yyvsp[-4].strval),0);
  quadOP* temp1=QOcreat_temp();
  quads *q=Qcreat(Q_TAB_GIVE,temp1,tab,(yyvsp[-2].operateur));
  Lappend(Lglobal,q);

  quadOP* temp2=QOcreat_temp();
  q=NULL;
  if((yyvsp[-7].intval)){
    q=Qcreat(Q_ADD,temp2,NULL,temp1);
  }else{
    q=Qcreat(Q_LESS,temp2,NULL,temp1);
  }
  Lappend(Lglobal,q);
  free((yyvsp[-4].strval));
 }
#line 2091 "compilateur.tab.c"
    break;

  case 78: /* operande_entier: plus_ou_moin '$' ID  */
#line 508 "compilateur.y"
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
#line 2122 "compilateur.tab.c"
    break;

  case 79: /* operande_entier: ID  */
#line 534 "compilateur.y"
     { 
  printf("operande_entier-> ENTIER \n");
  int entier;
  if(ToInt(&entier,(yyvsp[0].strval))){
    (yyval.operateur)=QOcreat(QO_CST,NULL,entier);
  }
  free((yyvsp[0].strval));
}
#line 2135 "compilateur.tab.c"
    break;

  case 80: /* operande_entier: plus_ou_moin ID  */
#line 542 "compilateur.y"
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
#line 2154 "compilateur.tab.c"
    break;

  case 81: /* operande_entier: '(' somme_entiere ')'  */
#line 556 "compilateur.y"
                        { 
  printf("operande_entier-> ( somme_entiere ) \n");
  (yyval.operateur)=(yyvsp[-1].operateur);
  }
#line 2163 "compilateur.tab.c"
    break;

  case 82: /* plus_ou_moin: '+'  */
#line 561 "compilateur.y"
                  {(yyval.intval)=1;}
#line 2169 "compilateur.tab.c"
    break;

  case 83: /* plus_ou_moin: '-'  */
#line 561 "compilateur.y"
                                {(yyval.intval)=0;}
#line 2175 "compilateur.tab.c"
    break;

  case 84: /* fois_div_mod: '*'  */
#line 563 "compilateur.y"
                  {(yyval.intval)=1;}
#line 2181 "compilateur.tab.c"
    break;

  case 85: /* fois_div_mod: '/'  */
#line 563 "compilateur.y"
                               {(yyval.intval)=2;}
#line 2187 "compilateur.tab.c"
    break;

  case 86: /* fois_div_mod: '%'  */
#line 563 "compilateur.y"
                                            {(yyval.intval)=3;}
#line 2193 "compilateur.tab.c"
    break;

  case 87: /* declaration_de_fonction: ID '(' ')' '{' decl_loc liste_instructions '}'  */
#line 566 "compilateur.y"
                                               { printf("declaration_de_fonction-> ID ( ) { decl_loc liste_instructions }\n");}
#line 2199 "compilateur.tab.c"
    break;

  case 88: /* decl_loc: decl_loc LOCAL ID '=' concatenation ';'  */
#line 569 "compilateur.y"
                                        { printf("decl_loc-> decl_loc LOCAL ID = concatenation \n");}
#line 2205 "compilateur.tab.c"
    break;

  case 89: /* decl_loc: %empty  */
#line 570 "compilateur.y"
                                        { printf("decl_loc-> empty \n");}
#line 2211 "compilateur.tab.c"
    break;

  case 90: /* appel_de_fonction: ID liste_operandes  */
#line 573 "compilateur.y"
                    { printf("appel_de_fonction-> ID liste_operandes \n");}
#line 2217 "compilateur.tab.c"
    break;

  case 91: /* appel_de_fonction: ID  */
#line 574 "compilateur.y"
                    { printf("appel_de_fonction-> ID \n");}
#line 2223 "compilateur.tab.c"
    break;


#line 2227 "compilateur.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 576 "compilateur.y"


void yyerror(const char * msg){
    fprintf(stderr, "Erreur syntaxique: %s\n",msg);
}
