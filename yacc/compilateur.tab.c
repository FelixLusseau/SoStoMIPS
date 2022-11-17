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

#include <stdio.h>

extern int yylex(); 
extern void yyerror(const char * msg);

#line 82 "compilateur.tab.c"

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
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_CHAINE = 25,                    /* CHAINE  */
  YYSYMBOL_O = 26,                         /* O  */
  YYSYMBOL_A = 27,                         /* A  */
  YYSYMBOL_N = 28,                         /* N  */
  YYSYMBOL_Z = 29,                         /* Z  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_LT = 34,                        /* LT  */
  YYSYMBOL_LE = 35,                        /* LE  */
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
  YYSYMBOL_programme = 54,                 /* programme  */
  YYSYMBOL_liste_instructions = 55,        /* liste_instructions  */
  YYSYMBOL_instruction = 56,               /* instruction  */
  YYSYMBOL_else_part = 57,                 /* else_part  */
  YYSYMBOL_liste_cas = 58,                 /* liste_cas  */
  YYSYMBOL_filtre = 59,                    /* filtre  */
  YYSYMBOL_liste_operandes = 60,           /* liste_operandes  */
  YYSYMBOL_concatenation = 61,             /* concatenation  */
  YYSYMBOL_test_bloc = 62,                 /* test_bloc  */
  YYSYMBOL_test_expr = 63,                 /* test_expr  */
  YYSYMBOL_test_expr2 = 64,                /* test_expr2  */
  YYSYMBOL_test_expr3 = 65,                /* test_expr3  */
  YYSYMBOL_test_instruction = 66,          /* test_instruction  */
  YYSYMBOL_operateur1 = 67,                /* operateur1  */
  YYSYMBOL_operateur2 = 68,                /* operateur2  */
  YYSYMBOL_operande = 69,                  /* operande  */
  YYSYMBOL_somme_entiere = 70,             /* somme_entiere  */
  YYSYMBOL_produit_entier = 71,            /* produit_entier  */
  YYSYMBOL_operande_entier = 72,           /* operande_entier  */
  YYSYMBOL_plus_ou_moin = 73,              /* plus_ou_moin  */
  YYSYMBOL_fois_div_mod = 74,              /* fois_div_mod  */
  YYSYMBOL_declaration_de_fonction = 75,   /* declaration_de_fonction  */
  YYSYMBOL_decl_loc = 76,                  /* decl_loc  */
  YYSYMBOL_appel_de_fonction = 77          /* appel_de_fonction  */
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
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

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
static const yytype_uint8 yyrline[] =
{
       0,    18,    18,    21,    22,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    45,    46,    47,    50,    51,    54,    55,
      56,    57,    58,    61,    62,    63,    66,    67,    70,    73,
      74,    77,    78,    81,    82,    83,    84,    87,    88,    89,
      90,    93,    94,    97,    98,    99,   100,   101,   102,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   116,   117,
     120,   121,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   135,   135,   137,   137,   137,   140,   143,   144,   147,
     148
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
  "EXPR", "ID", "CHAINE", "O", "A", "N", "Z", "EQ", "NE", "GT", "GE", "LT",
  "LE", "';'", "'='", "'['", "']'", "')'", "'|'", "'*'", "'$'", "'{'",
  "'}'", "'('", "'!'", "'?'", "'+'", "'-'", "'/'", "'%'", "$accept",
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
     230,    -9,    11,    -9,    -9,    15,    63,    37,    40,    40,
      45,   171,    82,    61,   -64,   -64,   -64,   157,    96,    97,
     105,   110,   -64,   -64,    98,   135,   131,    15,   -64,    86,
     -64,    -3,    40,   -64,   -64,   -64,    35,   -64,   133,    15,
      40,   134,    15,   -64,   230,   -64,   -64,   157,   169,   164,
     128,   149,   -64,   -64,    15,   225,   230,   170,    63,   230,
     230,   -64,   -64,   156,     7,   -64,   106,   159,   -64,    40,
     -64,   163,   116,   168,   -64,   -64,     0,   166,    15,   -64,
     153,   155,   -64,    36,   157,   -64,    15,   165,   -64,   157,
     157,    15,   -64,   -64,   -64,   -64,   -64,   -64,    15,   114,
     230,     8,    10,    16,    54,    40,    63,   173,   -64,   -64,
     -64,     3,    31,    81,   182,    89,   -64,    40,   -64,   -64,
     -64,    40,   -64,   201,   192,   195,   -64,   -64,    51,    15,
      15,   149,   -64,   -64,    -9,   230,   216,    18,   230,   -64,
     -64,    40,   -64,   198,   -64,   -64,   127,   230,   181,    24,
     -64,    40,   -64,   168,   -64,    91,   -64,    15,   213,   -64,
      15,   238,    61,   -64,   -64,    19,   210,   -64,   230,   214,
     -64,   -64,   222,   223,    40,   -64,    15,   228,    -7,   230,
     -64,   208,   227,    99,   219,   220,   229,   232,   -64,   114,
     -64,   148,   -64,   -64,   -64,   221,    15,   -64,   -64,   -64,
      32,   -64
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
     -64,   -64,   -40,   -42,    78,   -64,   160,     5,   -36,     4,
     -37,   183,   180,   226,   -64,   -64,    -5,   172,   158,    -4,
     -63,   -64,   -64,   -64,   209
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,   136,   111,   112,    42,    49,    18,
      50,    51,    52,    53,    54,    98,    88,    72,    73,    74,
      36,   121,    15,   158,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    28,    82,    78,    35,    37,    28,    20,    21,   117,
      83,    27,    55,    17,   138,   145,    99,   139,    91,   102,
     103,    70,    68,   140,   122,   164,   180,   108,   109,    44,
     105,   106,    22,    23,    79,    19,    80,    68,   188,    22,
      23,    71,    55,    55,   123,   110,    44,   128,    30,    79,
     129,    24,    44,    28,    44,    44,    22,    23,    24,    75,
     137,    29,    89,   101,    30,   114,   172,    31,   201,    38,
      32,   147,   148,    33,    34,    24,   127,    89,    76,    55,
     117,    79,    43,    31,    55,    55,    32,    22,    23,    33,
      34,   159,   141,   133,   160,   162,    68,    44,   165,   142,
      56,    28,     1,    57,     2,    58,    26,   169,     3,     4,
       5,    59,     6,     7,     8,     9,    60,   154,   178,   149,
      10,   176,    61,    11,    69,    79,   142,   151,   182,   174,
     108,   109,   134,   135,   152,   192,   175,   166,   161,   189,
      62,    82,    63,    66,    64,   166,    65,   173,   110,    82,
      44,     1,    79,     2,    89,    61,   116,     3,     4,     5,
     200,     6,     7,     8,     9,    33,    34,   168,   148,    10,
     186,    77,    11,    62,    81,    67,    90,    64,   100,    65,
     104,    22,    23,   113,   198,    45,    46,   115,    22,    23,
     124,    79,   125,    22,    23,    22,    23,    45,    46,   126,
      24,    86,   130,    47,    48,   170,   171,    24,    39,    40,
     118,    87,    24,   144,    26,    84,     1,    41,     2,   119,
     120,   150,     3,     4,     5,   155,     6,     7,     8,     9,
     177,   156,   157,     1,    10,     2,   163,    11,   167,     3,
       4,     5,   179,     6,     7,     8,     9,    33,    34,   181,
     183,    10,   187,   190,    11,    92,    93,    94,    95,    96,
      97,   184,   185,   191,   193,   194,   199,   197,   195,   196,
     132,   146,   131,   107,    85,   153,     0,   143
};

static const yytype_int16 yycheck[] =
{
       5,     6,    44,    39,     8,     9,    11,     3,     4,    72,
      47,     6,    17,    22,     6,    12,    56,     7,    54,    59,
      60,    24,    27,     7,    24,     7,     7,    24,    25,    36,
      23,    24,    24,    25,    39,    24,    40,    42,    45,    24,
      25,    44,    47,    48,    44,    42,    36,    84,    24,    54,
      86,    43,    36,    58,    36,    36,    24,    25,    43,    24,
     100,    24,    26,    58,    24,    69,    42,    43,    36,    24,
      46,    40,    41,    49,    50,    43,    40,    26,    43,    84,
     143,    86,     0,    43,    89,    90,    46,    24,    25,    49,
      50,    40,    38,    98,   130,   135,   101,    36,   138,    45,
       4,   106,     3,     6,     5,     8,    43,   147,     9,    10,
      11,     6,    13,    14,    15,    16,     6,   121,   158,    38,
      21,   157,    24,    24,    38,   130,    45,    38,   168,    38,
      24,    25,    18,    19,    45,    36,    45,   141,   134,   179,
      42,   183,    44,     8,    46,   149,    48,   151,    42,   191,
      36,     3,   157,     5,    26,    24,    40,     9,    10,    11,
     196,    13,    14,    15,    16,    49,    50,    40,    41,    21,
     174,    38,    24,    42,    40,    44,    27,    46,     8,    48,
      24,    24,    25,    24,    36,    28,    29,    24,    24,    25,
      24,   196,    39,    24,    25,    24,    25,    28,    29,    44,
      43,    37,    37,    46,    47,    24,    25,    43,    37,    38,
      42,    47,    43,    40,    43,    46,     3,    46,     5,    51,
      52,    39,     9,    10,    11,    24,    13,    14,    15,    16,
      17,    39,    37,     3,    21,     5,    20,    24,    40,     9,
      10,    11,     4,    13,    14,    15,    16,    49,    50,    39,
      36,    21,    24,    45,    24,    30,    31,    32,    33,    34,
      35,    39,    39,    36,    45,    45,    45,   189,    39,    37,
      90,   111,    89,    64,    48,   117,    -1,   105
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     9,    10,    11,    13,    14,    15,    16,
      21,    24,    54,    55,    56,    75,    77,    22,    62,    24,
      62,    62,    24,    25,    43,    69,    43,    60,    69,    24,
      24,    43,    46,    49,    50,    72,    73,    72,    24,    37,
      38,    46,    60,     0,    36,    28,    29,    46,    47,    61,
      63,    64,    65,    66,    67,    69,     4,     6,     8,     6,
       6,    24,    42,    44,    46,    48,     8,    44,    69,    38,
      24,    44,    70,    71,    72,    24,    43,    38,    61,    69,
      72,    40,    56,    63,    46,    66,    37,    47,    69,    26,
      27,    61,    30,    31,    32,    33,    34,    35,    68,    55,
       8,    60,    55,    55,    24,    23,    24,    77,    24,    25,
      42,    58,    59,    24,    72,    24,    40,    73,    42,    51,
      52,    74,    24,    44,    24,    39,    44,    40,    63,    61,
      37,    64,    65,    69,    18,    19,    57,    55,     6,     7,
       7,    38,    45,    70,    40,    12,    59,    40,    41,    38,
      39,    38,    45,    71,    72,    24,    39,    37,    76,    40,
      61,    62,    55,    20,     7,    55,    72,    40,    40,    55,
      24,    25,    42,    72,    38,    45,    61,    17,    55,     4,
       7,    39,    55,    36,    39,    39,    72,    24,    45,    55,
      45,    36,    36,    45,    45,    39,    37,    57,    36,    45,
      61,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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
  case 2: /* programme: liste_instructions  */
#line 18 "compilateur.y"
                   {printf("programme->liste_instruction\n");}
#line 1291 "compilateur.tab.c"
    break;

  case 3: /* liste_instructions: liste_instructions ';' instruction  */
#line 21 "compilateur.y"
                                   {printf("liste_instruction->liste_instructions ; instruction\n");}
#line 1297 "compilateur.tab.c"
    break;

  case 4: /* liste_instructions: instruction  */
#line 22 "compilateur.y"
                                   {printf("liste_instruction->instruction\n");}
#line 1303 "compilateur.tab.c"
    break;

  case 5: /* instruction: ID '=' concatenation  */
#line 25 "compilateur.y"
                                                       { printf("instruction-> ID = concatenation\n");}
#line 1309 "compilateur.tab.c"
    break;

  case 6: /* instruction: ID '[' operande_entier ']' '=' concatenation  */
#line 26 "compilateur.y"
                                                       { printf("instruction-> ID [ operande_entier ] = concatenation\n");}
#line 1315 "compilateur.tab.c"
    break;

  case 7: /* instruction: DECLARE ID '[' ID ']'  */
#line 27 "compilateur.y"
                                                       { printf("instruction-> DECLARE ID [ ENTIER ] \n");}
#line 1321 "compilateur.tab.c"
    break;

  case 8: /* instruction: IF test_bloc THEN liste_instructions else_part FI  */
#line 28 "compilateur.y"
                                                       { printf("instruction-> IF test_bloc THEN liste_instructions else_part FI \n");}
#line 1327 "compilateur.tab.c"
    break;

  case 9: /* instruction: FOR ID DO IN liste_instructions DONE  */
#line 29 "compilateur.y"
                                                       { printf("instruction->FOR ID DO IN liste_instructions DONE \n");}
#line 1333 "compilateur.tab.c"
    break;

  case 10: /* instruction: FOR ID IN liste_operandes DO liste_instructions DONE  */
#line 30 "compilateur.y"
                                                       { printf("instruction-> FOR ID IN liste_operandes DO liste_instructions DONE  \n");}
#line 1339 "compilateur.tab.c"
    break;

  case 11: /* instruction: WHILE test_bloc DO liste_instructions DONE  */
#line 31 "compilateur.y"
                                                       { printf("instruction-> WHILE test_bloc DO liste_instructions DONE \n");}
#line 1345 "compilateur.tab.c"
    break;

  case 12: /* instruction: UNTIL test_bloc DO liste_instructions DONE  */
#line 32 "compilateur.y"
                                                       { printf("instruction-> UNTIL test_bloc DO liste_instructions DONE \n");}
#line 1351 "compilateur.tab.c"
    break;

  case 13: /* instruction: CASE operande IN liste_cas ESAC  */
#line 33 "compilateur.y"
                                                       { printf("instruction-> CASE operande IN liste_cas ESAC \n");}
#line 1357 "compilateur.tab.c"
    break;

  case 14: /* instruction: MYECHO liste_operandes  */
#line 34 "compilateur.y"
                                                       { printf("instruction-> MYECHO liste_operandes \n");}
#line 1363 "compilateur.tab.c"
    break;

  case 15: /* instruction: READ ID  */
#line 35 "compilateur.y"
                                                       { printf("instruction-> READ ID \n");}
#line 1369 "compilateur.tab.c"
    break;

  case 16: /* instruction: READ ID '[' operande_entier ']'  */
#line 36 "compilateur.y"
                                                       { printf("instruction-> READ ID [ operande_entier ] \n");}
#line 1375 "compilateur.tab.c"
    break;

  case 17: /* instruction: declaration_de_fonction  */
#line 37 "compilateur.y"
                                                       { printf("instruction-> declaration_de_fonction \n");}
#line 1381 "compilateur.tab.c"
    break;

  case 18: /* instruction: appel_de_fonction  */
#line 38 "compilateur.y"
                                                       { printf("instruction-> appel_de_fonction \n");}
#line 1387 "compilateur.tab.c"
    break;

  case 19: /* instruction: RETURN  */
#line 39 "compilateur.y"
                                                       { printf("instruction-> RETURN \n");}
#line 1393 "compilateur.tab.c"
    break;

  case 20: /* instruction: RETURN operande_entier  */
#line 40 "compilateur.y"
                                                       { printf("instruction-> RETURN operande_entier \n");}
#line 1399 "compilateur.tab.c"
    break;

  case 21: /* instruction: EXIT  */
#line 41 "compilateur.y"
                                                       { printf("instruction->EXIT\n");}
#line 1405 "compilateur.tab.c"
    break;

  case 22: /* instruction: EXIT operande_entier  */
#line 42 "compilateur.y"
                                                       { printf("instruction->EXIT operande_entier\n");}
#line 1411 "compilateur.tab.c"
    break;

  case 23: /* else_part: ELIF test_bloc THEN liste_instructions else_part  */
#line 45 "compilateur.y"
                                                  { printf("else_part->ELIF test_bloc THEN liste_instructions else_part\n");}
#line 1417 "compilateur.tab.c"
    break;

  case 24: /* else_part: ELSE liste_instructions  */
#line 46 "compilateur.y"
                                                  { printf("else_part->ELSE liste_instructions\n");}
#line 1423 "compilateur.tab.c"
    break;

  case 25: /* else_part: %empty  */
#line 47 "compilateur.y"
                                                  { printf("else_part->empty\n");}
#line 1429 "compilateur.tab.c"
    break;

  case 26: /* liste_cas: liste_cas filtre ')' liste_instructions ';' ';'  */
#line 50 "compilateur.y"
                                                 { printf("liste_cas->liste_cas filtre ) liste_instructions ; ; \n");}
#line 1435 "compilateur.tab.c"
    break;

  case 27: /* liste_cas: filtre ')' liste_instructions ';' ';'  */
#line 51 "compilateur.y"
                                                 { printf("liste_cas->filtre ) liste_instructions ; ; \n");}
#line 1441 "compilateur.tab.c"
    break;

  case 28: /* filtre: ID  */
#line 54 "compilateur.y"
                     { printf("filtre->MOT\n");}
#line 1447 "compilateur.tab.c"
    break;

  case 29: /* filtre: CHAINE  */
#line 55 "compilateur.y"
                     { printf("filtre->CHAINE\n");}
#line 1453 "compilateur.tab.c"
    break;

  case 30: /* filtre: filtre '|' ID  */
#line 56 "compilateur.y"
                     { printf("filtre->filtre | MOT\n");}
#line 1459 "compilateur.tab.c"
    break;

  case 31: /* filtre: filtre '|' CHAINE  */
#line 57 "compilateur.y"
                     { printf("filtre->filtre | CHAINE\n");}
#line 1465 "compilateur.tab.c"
    break;

  case 32: /* filtre: '*'  */
#line 58 "compilateur.y"
                     { printf("filtre-> *\n");}
#line 1471 "compilateur.tab.c"
    break;

  case 33: /* liste_operandes: liste_operandes operande  */
#line 61 "compilateur.y"
                              { printf("liste_operandes-> liste_operandes operande \n");}
#line 1477 "compilateur.tab.c"
    break;

  case 34: /* liste_operandes: operande  */
#line 62 "compilateur.y"
                              { printf("liste_operandes-> operande \n");}
#line 1483 "compilateur.tab.c"
    break;

  case 35: /* liste_operandes: '$' '{' ID '[' '*' ']' '}'  */
#line 63 "compilateur.y"
                              { printf("liste_operandes-> $ { ID [ * ] } \n");}
#line 1489 "compilateur.tab.c"
    break;

  case 36: /* concatenation: concatenation operande  */
#line 66 "compilateur.y"
                       { printf("concatenation-> concatenation operande \n");}
#line 1495 "compilateur.tab.c"
    break;

  case 37: /* concatenation: operande  */
#line 67 "compilateur.y"
                       { printf("concatenation-> operande \n");}
#line 1501 "compilateur.tab.c"
    break;

  case 38: /* test_bloc: TEST test_expr  */
#line 70 "compilateur.y"
                { printf("test_bloc-> TEST test_exp \n");}
#line 1507 "compilateur.tab.c"
    break;

  case 39: /* test_expr: test_expr O test_expr2  */
#line 73 "compilateur.y"
                       { printf("test_expr-> test_expr O test_expr2 \n");}
#line 1513 "compilateur.tab.c"
    break;

  case 40: /* test_expr: test_expr2  */
#line 74 "compilateur.y"
                       { printf("test_expr-> test_expr2 \n");}
#line 1519 "compilateur.tab.c"
    break;

  case 41: /* test_expr2: test_expr2 A test_expr3  */
#line 77 "compilateur.y"
                        { printf("test_expr2-> test_expr2 A test_expr3 \n");}
#line 1525 "compilateur.tab.c"
    break;

  case 42: /* test_expr2: test_expr3  */
#line 78 "compilateur.y"
                        { printf("test_expr2-> test_expr3 \n");}
#line 1531 "compilateur.tab.c"
    break;

  case 43: /* test_expr3: '(' test_expr ')'  */
#line 81 "compilateur.y"
                        { printf("test_expr3-> ( test_expr ) \n");}
#line 1537 "compilateur.tab.c"
    break;

  case 44: /* test_expr3: '!' '(' test_expr ')'  */
#line 82 "compilateur.y"
                        { printf("test_expr3-> ! ( test_expr ) \n");}
#line 1543 "compilateur.tab.c"
    break;

  case 45: /* test_expr3: test_instruction  */
#line 83 "compilateur.y"
                        { printf("test_expr3-> test_instruction \n");}
#line 1549 "compilateur.tab.c"
    break;

  case 46: /* test_expr3: '!' test_instruction  */
#line 84 "compilateur.y"
                        { printf("test_expr3-> ! test_instruction \n");}
#line 1555 "compilateur.tab.c"
    break;

  case 47: /* test_instruction: concatenation '=' concatenation  */
#line 87 "compilateur.y"
                                      { printf("test_instruction-> concatenation = concatenation \n");}
#line 1561 "compilateur.tab.c"
    break;

  case 48: /* test_instruction: concatenation '!' '=' concatenation  */
#line 88 "compilateur.y"
                                      { printf("test_instruction-> concatenation != concatenation \n");}
#line 1567 "compilateur.tab.c"
    break;

  case 49: /* test_instruction: operateur1 concatenation  */
#line 89 "compilateur.y"
                                      { printf("test_instruction-> operateur1 concatenation \n");}
#line 1573 "compilateur.tab.c"
    break;

  case 50: /* test_instruction: operande operateur2 operande  */
#line 90 "compilateur.y"
                                      { printf("test_instruction-> operande operateur2 operande \n");}
#line 1579 "compilateur.tab.c"
    break;

  case 53: /* operateur2: EQ  */
#line 97 "compilateur.y"
    { printf("operateur2-> -eq\n");}
#line 1585 "compilateur.tab.c"
    break;

  case 54: /* operateur2: NE  */
#line 98 "compilateur.y"
    { printf("operateur2-> -ne\n");}
#line 1591 "compilateur.tab.c"
    break;

  case 55: /* operateur2: GT  */
#line 99 "compilateur.y"
    { printf("operateur2-> -gt\n");}
#line 1597 "compilateur.tab.c"
    break;

  case 56: /* operateur2: GE  */
#line 100 "compilateur.y"
    { printf("operateur2-> -ge\n");}
#line 1603 "compilateur.tab.c"
    break;

  case 57: /* operateur2: LT  */
#line 101 "compilateur.y"
    { printf("operateur2-> -lt\n");}
#line 1609 "compilateur.tab.c"
    break;

  case 58: /* operateur2: LE  */
#line 102 "compilateur.y"
    { printf("operateur2-> -le\n");}
#line 1615 "compilateur.tab.c"
    break;

  case 59: /* operande: '$' '{' ID '}'  */
#line 105 "compilateur.y"
                                         { printf("operande-> $ { ID }\n");}
#line 1621 "compilateur.tab.c"
    break;

  case 60: /* operande: '$' '{' ID '[' operande_entier ']' '}'  */
#line 106 "compilateur.y"
                                         { printf("operande-> $ { ID [ operande_entier ] }\n");}
#line 1627 "compilateur.tab.c"
    break;

  case 61: /* operande: ID  */
#line 107 "compilateur.y"
                                         { printf("operande-> MOT\n");}
#line 1633 "compilateur.tab.c"
    break;

  case 62: /* operande: '$' ID  */
#line 108 "compilateur.y"
                                         { printf("operande-> $ ENTIER\n");}
#line 1639 "compilateur.tab.c"
    break;

  case 63: /* operande: '$' '*'  */
#line 109 "compilateur.y"
                                         { printf("operande-> $ *\n");}
#line 1645 "compilateur.tab.c"
    break;

  case 64: /* operande: '$' '?'  */
#line 110 "compilateur.y"
                                         { printf("operande-> $ ?\n");}
#line 1651 "compilateur.tab.c"
    break;

  case 65: /* operande: CHAINE  */
#line 111 "compilateur.y"
                                         { printf("operande-> CHAINE\n");}
#line 1657 "compilateur.tab.c"
    break;

  case 66: /* operande: '$' '(' EXPR somme_entiere ')'  */
#line 112 "compilateur.y"
                                         { printf("operande-> $ ( EXPR somme_entiere )\n");}
#line 1663 "compilateur.tab.c"
    break;

  case 67: /* operande: '$' '(' appel_de_fonction ')'  */
#line 113 "compilateur.y"
                                         { printf("operande-> $ ( appel_de_fonction )\n");}
#line 1669 "compilateur.tab.c"
    break;

  case 68: /* somme_entiere: somme_entiere plus_ou_moin produit_entier  */
#line 116 "compilateur.y"
                                          { printf("somme_entiere-> somme_entiere plus_ou_moin produit_entier \n");}
#line 1675 "compilateur.tab.c"
    break;

  case 69: /* somme_entiere: produit_entier  */
#line 117 "compilateur.y"
                                          { printf("somme_entiere-> produit_entier \n");}
#line 1681 "compilateur.tab.c"
    break;

  case 70: /* produit_entier: produit_entier fois_div_mod operande_entier  */
#line 120 "compilateur.y"
                                            { printf("produit_entier-> produit_entier fois_div_mod operande_entier\n");}
#line 1687 "compilateur.tab.c"
    break;

  case 71: /* produit_entier: operande_entier  */
#line 121 "compilateur.y"
                                            { printf("produit_entier-> operande_entier \n");}
#line 1693 "compilateur.tab.c"
    break;

  case 72: /* operande_entier: '$' '{' ID '}'  */
#line 125 "compilateur.y"
                                                      { printf("operande_entier-> $ { ID } \n");}
#line 1699 "compilateur.tab.c"
    break;

  case 73: /* operande_entier: '$' '{' ID '[' operande_entier ']' '}'  */
#line 126 "compilateur.y"
                                                      { printf("operande_entier-> $ { ID [ operande_entier ] } \n");}
#line 1705 "compilateur.tab.c"
    break;

  case 74: /* operande_entier: '$' ID  */
#line 127 "compilateur.y"
                                                      { printf("operande_entier-> $ ENTIER \n");}
#line 1711 "compilateur.tab.c"
    break;

  case 75: /* operande_entier: plus_ou_moin '$' '{' ID '}'  */
#line 128 "compilateur.y"
                                                      { printf("operande_entier-> plus_ou_moin $ { ID } \n");}
#line 1717 "compilateur.tab.c"
    break;

  case 76: /* operande_entier: plus_ou_moin '$' '{' ID '[' operande_entier ']' '}'  */
#line 129 "compilateur.y"
                                                      { printf("operande_entier-> plus_ou_moin $ { ID [ operande_entier ] }\n");}
#line 1723 "compilateur.tab.c"
    break;

  case 77: /* operande_entier: plus_ou_moin '$' ID  */
#line 130 "compilateur.y"
                                                      { printf("operande_entier-> plus_ou_moin $ ENTIER\n");}
#line 1729 "compilateur.tab.c"
    break;

  case 78: /* operande_entier: ID  */
#line 131 "compilateur.y"
                                                      { printf("operande_entier-> ENTIER \n");}
#line 1735 "compilateur.tab.c"
    break;

  case 79: /* operande_entier: plus_ou_moin ID  */
#line 132 "compilateur.y"
                                                      { printf("operande_entier-> plus_ou_moin ENTIER\n");}
#line 1741 "compilateur.tab.c"
    break;

  case 80: /* operande_entier: '(' somme_entiere ')'  */
#line 133 "compilateur.y"
                                                      { printf("operande_entier-> ( somme_entiere ) \n");}
#line 1747 "compilateur.tab.c"
    break;

  case 86: /* declaration_de_fonction: ID '(' ')' '{' decl_loc liste_instructions '}'  */
#line 140 "compilateur.y"
                                               { printf("declaration_de_fonction-> ID ( ) { decl_loc liste_instructions }\n");}
#line 1753 "compilateur.tab.c"
    break;

  case 87: /* decl_loc: decl_loc LOCAL ID '=' concatenation ';'  */
#line 143 "compilateur.y"
                                        { printf("decl_loc-> decl_loc LOCAL ID = concatenation \n");}
#line 1759 "compilateur.tab.c"
    break;

  case 88: /* decl_loc: %empty  */
#line 144 "compilateur.y"
                                        { printf("decl_loc-> empty \n");}
#line 1765 "compilateur.tab.c"
    break;

  case 89: /* appel_de_fonction: ID liste_operandes  */
#line 147 "compilateur.y"
                    { printf("appel_de_fonction-> ID liste_operandes \n");}
#line 1771 "compilateur.tab.c"
    break;

  case 90: /* appel_de_fonction: ID  */
#line 148 "compilateur.y"
                    { printf("appel_de_fonction-> ID \n");}
#line 1777 "compilateur.tab.c"
    break;


#line 1781 "compilateur.tab.c"

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

#line 150 "compilateur.y"


void yyerror(const char * msg){
    fprintf(stderr, "Erreur syntaxique: %s\n",msg);
}
