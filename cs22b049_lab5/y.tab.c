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
#line 1 "prob3.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYDEBUG 1
extern int yylex();
extern int yydebug;
int yyerror(char*);
int eflag=0;
extern FILE* yyin;
typedef struct Node{

    char* type;
    char* lexeme;
    int IntVal;
    float FloatVal;
    struct Node* left;
    struct Node* right;

} node;
node* Nodemaker(char* operator, char* var , int IntVal, float FloatVal , node* left , node* right);
void printPostOrder(node* root);

#line 95 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FLOATs = 258,                  /* FLOATs  */
    INTs = 259,                    /* INTs  */
    DIV = 260,                     /* DIV  */
    MULT = 261,                    /* MULT  */
    MOD = 262,                     /* MOD  */
    ADD = 263,                     /* ADD  */
    SUB = 264,                     /* SUB  */
    OPENBRACK = 265,               /* OPENBRACK  */
    CLOSEBRACK = 266,              /* CLOSEBRACK  */
    ASSIGN = 267,                  /* ASSIGN  */
    VAR = 268,                     /* VAR  */
    MUL = 269,                     /* MUL  */
    UMINUS = 270                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "prob3.y"

    int INT;
    float FLOAT;
    char Oprtr;
    char* variable;
    struct Node* nodee;

#line 168 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FLOATs = 3,                     /* FLOATs  */
  YYSYMBOL_INTs = 4,                       /* INTs  */
  YYSYMBOL_DIV = 5,                        /* DIV  */
  YYSYMBOL_MULT = 6,                       /* MULT  */
  YYSYMBOL_MOD = 7,                        /* MOD  */
  YYSYMBOL_ADD = 8,                        /* ADD  */
  YYSYMBOL_SUB = 9,                        /* SUB  */
  YYSYMBOL_OPENBRACK = 10,                 /* OPENBRACK  */
  YYSYMBOL_CLOSEBRACK = 11,                /* CLOSEBRACK  */
  YYSYMBOL_ASSIGN = 12,                    /* ASSIGN  */
  YYSYMBOL_VAR = 13,                       /* VAR  */
  YYSYMBOL_MUL = 14,                       /* MUL  */
  YYSYMBOL_UMINUS = 15,                    /* UMINUS  */
  YYSYMBOL_16_ = 16,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 17,                  /* $accept  */
  YYSYMBOL_EXPRESSION = 18,                /* EXPRESSION  */
  YYSYMBOL_19_1 = 19,                      /* $@1  */
  YYSYMBOL_20_2 = 20,                      /* $@2  */
  YYSYMBOL_21_3 = 21,                      /* $@3  */
  YYSYMBOL_AssignExpr = 22,                /* AssignExpr  */
  YYSYMBOL_ArithExpr = 23,                 /* ArithExpr  */
  YYSYMBOL_TERM = 24,                      /* TERM  */
  YYSYMBOL_INTEGER_EXP = 25,               /* INTEGER_EXP  */
  YYSYMBOL_INTEGER_TERM = 26,              /* INTEGER_TERM  */
  YYSYMBOL_INT_FACTOR = 27,                /* INT_FACTOR  */
  YYSYMBOL_FACTOR = 28                     /* FACTOR  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  69

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    16,
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
      15
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    46,    53,    53,    60,    60,    65,    67,
      72,    76,    80,    84,    89,    90,    92,    96,   100,   104,
     110,   114,   118,   122,   123,   125,   129,   133,   137,   141,
     142,   148,   152,   156,   160,   161,   162,   165,   169,   173,
     177,   181,   182
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
  "\"end of file\"", "error", "\"invalid token\"", "FLOATs", "INTs",
  "DIV", "MULT", "MOD", "ADD", "SUB", "OPENBRACK", "CLOSEBRACK", "ASSIGN",
  "VAR", "MUL", "UMINUS", "';'", "$accept", "EXPRESSION", "$@1", "$@2",
  "$@3", "AssignExpr", "ArithExpr", "TERM", "INTEGER_EXP", "INTEGER_TERM",
  "INT_FACTOR", "FACTOR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      20,   -14,   -46,   -46,    97,    31,   -46,    14,     6,   116,
      21,   -46,   -46,    21,   -46,   103,   -46,   -46,    35,    46,
      85,   -46,    97,    97,   105,    20,   -46,   -46,    20,   -46,
      21,   -46,    21,     0,    20,   -46,   -46,    24,   -46,    50,
     -46,   -46,    80,   -46,   -46,   -46,   -46,   -46,   -46,   112,
      54,    65,   105,    69,   105,    15,    26,   -46,   -46,    93,
     -46,    93,   -46,   -46,   -46,   -46,    36,   -46,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    38,    40,     0,     0,    39,     0,     0,     0,
      12,    19,     6,    13,    42,     0,     1,     4,     0,     0,
       0,     2,     0,     0,     0,     0,    41,    37,     0,    14,
      10,    15,    11,     9,     0,    17,    16,     0,    32,     0,
      33,    18,    22,    28,     7,     5,     3,    34,    36,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    23,    20,
      24,    21,    26,    30,    25,    27,     0,    35,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -21,   -46,   -46,   -46,   -46,    -2,    -3,     4,   -45,
     -42,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,    34,    28,    25,     8,     9,    10,    41,    42,
      43,    11
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,    13,    12,    15,    44,    59,    61,    45,    18,    19,
      62,    64,    65,    46,    16,    30,    32,    55,    33,    55,
      -8,     1,    17,     2,     3,    47,    22,    23,    24,     4,
       5,    66,    14,     6,     2,     3,    29,    68,     2,     3,
       4,     5,    67,    49,     6,     5,     0,    31,     6,     2,
       3,    48,     0,    37,    38,    58,     5,    37,    38,     6,
      39,    35,    36,    40,    39,     0,    60,    40,    37,    38,
      63,     0,    37,    38,     0,    39,     0,     0,    40,    39,
       0,     0,    40,    37,    38,    52,    53,    54,     2,     3,
      39,     0,     0,    40,     4,     5,    37,    38,     6,    53,
       2,     3,     0,    39,    26,     0,    40,     5,    37,    38,
       6,    18,    19,    56,    27,    39,     0,     0,    40,     0,
      50,    51,     0,    57,    18,    19,     0,     0,    20,     0,
       0,     0,    21
};

static const yytype_int8 yycheck[] =
{
      42,     4,    16,     5,    25,    50,    51,    28,     8,     9,
      52,    53,    54,    34,     0,    18,    19,    59,    20,    61,
       0,     1,    16,     3,     4,     1,     5,     6,     7,     9,
      10,    16,     1,    13,     3,     4,     1,     1,     3,     4,
       9,    10,    16,    39,    13,    10,    -1,     1,    13,     3,
       4,     1,    -1,     3,     4,     1,    10,     3,     4,    13,
      10,    22,    23,    13,    10,    -1,     1,    13,     3,     4,
       1,    -1,     3,     4,    -1,    10,    -1,    -1,    13,    10,
      -1,    -1,    13,     3,     4,     5,     6,     7,     3,     4,
      10,    -1,    -1,    13,     9,    10,     3,     4,    13,     6,
       3,     4,    -1,    10,     1,    -1,    13,    10,     3,     4,
      13,     8,     9,     1,    11,    10,    -1,    -1,    13,    -1,
       8,     9,    -1,    11,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     9,    10,    13,    18,    22,    23,
      24,    28,    16,    24,     1,    23,     0,    16,     8,     9,
      12,    16,     5,     6,     7,    21,     1,    11,    20,     1,
      24,     1,    24,    23,    19,    28,    28,     3,     4,    10,
      13,    25,    26,    27,    18,    18,    18,     1,     1,    25,
       8,     9,     5,     6,     7,    27,     1,    11,     1,    26,
       1,    26,    27,     1,    27,    27,    16,    16,     1
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    17,    19,    18,    20,    18,    21,    18,    18,    22,
      23,    23,    23,    23,    23,    23,    24,    24,    24,    24,
      25,    25,    25,    25,    25,    26,    26,    26,    26,    26,
      26,    27,    27,    27,    27,    27,    27,    28,    28,    28,
      28,    28,    28
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     4,     0,     4,     0,     3,
       3,     3,     1,     2,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     4,
       3,     3,     1,     1,     2,     4,     2,     3,     1,     1,
       1,     3,     2
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
  case 2: /* $@1: %empty  */
#line 46 "prob3.y"
                                {
                                    printf("%-40s\n" , "accepted\n");
                                    printf("Printing Post order\n\n");
                                    printPostOrder((yyvsp[-1].nodee)); 
                                    printf("\n\n");
                                    yyclearin;
                                }
#line 1230 "y.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 53 "prob3.y"
                                {
                                    printf("%-40s\n" , "accepted\n");
                                    printf("Printing Post order\n\n");
                                    printPostOrder((yyvsp[-1].nodee)); 
                                    printf("\n\n");
                                    yyclearin;
                                }
#line 1242 "y.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 60 "prob3.y"
                        { 
                    printf("\t\t\t%-40s\n","Rejected Due to invalid syntax\n"); 
                    eflag = 1; 
                    yyerrok;
                    }
#line 1252 "y.tab.c"
    break;

  case 8: /* EXPRESSION: %empty  */
#line 65 "prob3.y"
              {printf("Done!!\n");}
#line 1258 "y.tab.c"
    break;

  case 9: /* AssignExpr: ArithExpr ASSIGN ArithExpr  */
#line 67 "prob3.y"
                                       {
                        (yyval.nodee) = Nodemaker("ASSIGN", "=", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
                    }
#line 1266 "y.tab.c"
    break;

  case 10: /* ArithExpr: ArithExpr ADD TERM  */
#line 73 "prob3.y"
            {
                (yyval.nodee) = Nodemaker("ADD", "+", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
            }
#line 1274 "y.tab.c"
    break;

  case 11: /* ArithExpr: ArithExpr SUB TERM  */
#line 77 "prob3.y"
            {
                (yyval.nodee) = Nodemaker("SUB", "-", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
            }
#line 1282 "y.tab.c"
    break;

  case 12: /* ArithExpr: TERM  */
#line 81 "prob3.y"
            {
                (yyval.nodee) = (yyvsp[0].nodee);
            }
#line 1290 "y.tab.c"
    break;

  case 13: /* ArithExpr: SUB TERM  */
#line 85 "prob3.y"
            {
            
                (yyval.nodee) = Nodemaker("UMINUS", "-", 0, 0, (yyvsp[0].nodee),NULL); //right node NULL as unary operator
            }
#line 1299 "y.tab.c"
    break;

  case 14: /* ArithExpr: ArithExpr ADD error  */
#line 89 "prob3.y"
                                  {  printf("\t\t\t%-40s\n", "Rejected Due to Nothing on RHS of +\n"); eflag = 1; yyerrok;yyclearin;}
#line 1305 "y.tab.c"
    break;

  case 15: /* ArithExpr: ArithExpr SUB error  */
#line 90 "prob3.y"
                                  {  printf("\t\t\t%-40s\n", "Rejected Due to Nothing on RHS of -\n"); eflag = 1; yyerrok;yyclearin;}
#line 1311 "y.tab.c"
    break;

  case 16: /* TERM: TERM MULT FACTOR  */
#line 93 "prob3.y"
        {
            (yyval.nodee) = Nodemaker("MULT", "*", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
        }
#line 1319 "y.tab.c"
    break;

  case 17: /* TERM: TERM DIV FACTOR  */
#line 97 "prob3.y"
        {
            (yyval.nodee) = Nodemaker("DIV","/", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
        }
#line 1327 "y.tab.c"
    break;

  case 18: /* TERM: TERM MOD INTEGER_EXP  */
#line 101 "prob3.y"
        {
            (yyval.nodee) = Nodemaker("MOD", "\%", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
        }
#line 1335 "y.tab.c"
    break;

  case 19: /* TERM: FACTOR  */
#line 105 "prob3.y"
        {
            (yyval.nodee) = (yyvsp[0].nodee);
        }
#line 1343 "y.tab.c"
    break;

  case 20: /* INTEGER_EXP: INTEGER_EXP ADD INTEGER_TERM  */
#line 111 "prob3.y"
                {
                    (yyval.nodee) = Nodemaker("ADD", "+", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
                }
#line 1351 "y.tab.c"
    break;

  case 21: /* INTEGER_EXP: INTEGER_EXP SUB INTEGER_TERM  */
#line 115 "prob3.y"
                {
                    (yyval.nodee) = Nodemaker("SUB", "-", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
                }
#line 1359 "y.tab.c"
    break;

  case 22: /* INTEGER_EXP: INTEGER_TERM  */
#line 119 "prob3.y"
                {
                    (yyval.nodee) = (yyvsp[0].nodee);
                }
#line 1367 "y.tab.c"
    break;

  case 23: /* INTEGER_EXP: INTEGER_EXP ADD error  */
#line 122 "prob3.y"
                                       { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of +\n"); eflag = 1; yyerrok;yyclearin;}
#line 1373 "y.tab.c"
    break;

  case 24: /* INTEGER_EXP: INTEGER_EXP SUB error  */
#line 123 "prob3.y"
                                       { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of -\n"); eflag = 1; yyerrok;yyclearin;}
#line 1379 "y.tab.c"
    break;

  case 25: /* INTEGER_TERM: INTEGER_TERM MULT INT_FACTOR  */
#line 126 "prob3.y"
                {
                    (yyval.nodee) = Nodemaker("MULT", "*", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
                }
#line 1387 "y.tab.c"
    break;

  case 26: /* INTEGER_TERM: INTEGER_TERM DIV INT_FACTOR  */
#line 130 "prob3.y"
                {
                    (yyval.nodee) = Nodemaker("DIV","/", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
                }
#line 1395 "y.tab.c"
    break;

  case 27: /* INTEGER_TERM: INTEGER_TERM MOD INT_FACTOR  */
#line 134 "prob3.y"
                {
                    (yyval.nodee) = Nodemaker("MOD", "\%", 0, 0, (yyvsp[-2].nodee), (yyvsp[0].nodee));
                }
#line 1403 "y.tab.c"
    break;

  case 28: /* INTEGER_TERM: INT_FACTOR  */
#line 138 "prob3.y"
                {
                    (yyval.nodee) = (yyvsp[0].nodee);
                }
#line 1411 "y.tab.c"
    break;

  case 29: /* INTEGER_TERM: INTEGER_TERM INT_FACTOR ';' error  */
#line 141 "prob3.y"
                                                   { printf("\t\t\t%-40s" ,"Rejected Due to no operator present *\n"); eflag = 1; yyerrok;yyclearin;}
#line 1417 "y.tab.c"
    break;

  case 30: /* INTEGER_TERM: INTEGER_TERM MULT error  */
#line 142 "prob3.y"
                                         { printf("\t\t\t%-40s","Rejected Due to Nothing on RHS of *\n"); eflag = 1; yyerrok;yyclearin;}
#line 1423 "y.tab.c"
    break;

  case 31: /* INT_FACTOR: OPENBRACK INTEGER_EXP CLOSEBRACK  */
#line 149 "prob3.y"
            {
                (yyval.nodee) = (yyvsp[-1].nodee);
            }
#line 1431 "y.tab.c"
    break;

  case 32: /* INT_FACTOR: INTs  */
#line 153 "prob3.y"
            {
                (yyval.nodee) = Nodemaker("INT", "INT" , (yyvsp[0].INT), 0, NULL, NULL); //leaf node
            }
#line 1439 "y.tab.c"
    break;

  case 33: /* INT_FACTOR: VAR  */
#line 157 "prob3.y"
            {
                (yyval.nodee) = Nodemaker("VAR", (yyvsp[0].variable) , 0, 0, NULL, NULL); //leaf node
            }
#line 1447 "y.tab.c"
    break;

  case 34: /* INT_FACTOR: FLOATs error  */
#line 160 "prob3.y"
                           { printf("\t\t\t%-40s\n","Rejected Due to Float cannot be used for modulus operator \n"); eflag = 1; yyerrok;yyclearin;}
#line 1453 "y.tab.c"
    break;

  case 35: /* INT_FACTOR: OPENBRACK INTEGER_EXP error ';'  */
#line 161 "prob3.y"
                                              { printf("\t\t\t%-40s\n","Rejected Due to Closing Bracket not found"); eflag = 1; yyerrok;yyclearin;}
#line 1459 "y.tab.c"
    break;

  case 36: /* INT_FACTOR: OPENBRACK error  */
#line 162 "prob3.y"
                              { printf("\t\t\t%-40s\n" ,"Rejected Due to NO Integer found after opening bracket \n"); eflag = 1; yyerrok;yyclearin;}
#line 1465 "y.tab.c"
    break;

  case 37: /* FACTOR: OPENBRACK ArithExpr CLOSEBRACK  */
#line 166 "prob3.y"
        {
            (yyval.nodee) = (yyvsp[-1].nodee);
        }
#line 1473 "y.tab.c"
    break;

  case 38: /* FACTOR: FLOATs  */
#line 170 "prob3.y"
        {
            (yyval.nodee) = Nodemaker("FLOAT", "FLOAT" , 0, (yyvsp[0].FLOAT), NULL, NULL); //leaf node
        }
#line 1481 "y.tab.c"
    break;

  case 39: /* FACTOR: VAR  */
#line 174 "prob3.y"
        {
            (yyval.nodee) = Nodemaker("VAR", (yyvsp[0].variable) , 0, 0, NULL, NULL); //leaf node
        }
#line 1489 "y.tab.c"
    break;

  case 40: /* FACTOR: INTs  */
#line 178 "prob3.y"
        {
            (yyval.nodee) = Nodemaker("INT", "INT" , (yyvsp[0].INT), 0, NULL, NULL); //leaf node
        }
#line 1497 "y.tab.c"
    break;

  case 41: /* FACTOR: OPENBRACK ArithExpr error  */
#line 181 "prob3.y"
                                    { printf("\t\t\t%-40s\n","Rejected Due to Closing Bracket not found \n"); eflag = 1; yyerrok;yyclearin;}
#line 1503 "y.tab.c"
    break;

  case 42: /* FACTOR: OPENBRACK error  */
#line 182 "prob3.y"
                          { printf("\t\t\t%-40s\n"," Rejected Due to NO Integer found after opening bracket \n"); eflag = 1; yyerrok;yyclearin;}
#line 1509 "y.tab.c"
    break;


#line 1513 "y.tab.c"

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

#line 186 "prob3.y"

int yyerror(char* s) {
    return 0;
}
void printPostOrder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    if(strcmp("INT",root->lexeme)==0)
    {
        printf(" %d ",root->IntVal);
    }
    else if(strcmp("FLOAT",root->lexeme)==0)
    {
        printf(" %g ",root->FloatVal);
    }
    else
    {
        printf(" %s ",root->lexeme);
    }
}
node* Nodemaker(char* type, char* lexeme , int IntVal, float FloatVal , node* left , node* right)
{
    node* newNode = (node*)malloc(1*sizeof(node));
    newNode->type = type;
    newNode->lexeme = lexeme;
    newNode->IntVal = IntVal;
    newNode->FloatVal = FloatVal;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}
int main(int arg, char* argc[])
{
    FILE* inpt;
    if(arg>1)
    {
        inpt = fopen(argc[1],"r");
        if(inpt)
        {
            yyin = inpt;
        }
    }
    // yydebug = 1;
    yyparse();
    if (inpt) {
        fclose(inpt);
    }
    
    return 0;
}
