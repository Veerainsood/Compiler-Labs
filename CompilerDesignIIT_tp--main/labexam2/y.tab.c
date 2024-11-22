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
#line 1 "prob1.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char*);
int yylex();
extern FILE* yyin;

char str[1000];
char* genLabel();
char* genBlockLabel();
char* genOutLabel();
char* genBeginLabel();
char* OutLabel(int Ocount);
int t = 0;
int l = 0;
int w = 0;
int z = 0 ; 
int count = 1;
// stack for storing the labels
char* stack[1000] ;
int Ocount = 0;

#line 96 "y.tab.c"

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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    ADD = 260,                     /* ADD  */
    SUB = 261,                     /* SUB  */
    MUL = 262,                     /* MUL  */
    DIV = 263,                     /* DIV  */
    EQ = 264,                      /* EQ  */
    LT = 265,                      /* LT  */
    LTE = 266,                     /* LTE  */
    GT = 267,                      /* GT  */
    GTE = 268,                     /* GTE  */
    NOT = 269,                     /* NOT  */
    AND = 270,                     /* AND  */
    OR = 271,                      /* OR  */
    PADD = 272,                    /* PADD  */
    PSUB = 273,                    /* PSUB  */
    LPAREN = 274,                  /* LPAREN  */
    RPAREN = 275,                  /* RPAREN  */
    LCURL = 276,                   /* LCURL  */
    RCURL = 277,                   /* RCURL  */
    SEMICOLON = 278,               /* SEMICOLON  */
    WHILE = 279,                   /* WHILE  */
    COLON = 280,                   /* COLON  */
    SWITCH = 281,                  /* SWITCH  */
    BREAK = 282,                   /* BREAK  */
    CONTINUE = 283,                /* CONTINUE  */
    DEFAULT = 284,                 /* DEFAULT  */
    CASE = 285,                    /* CASE  */
    FOR = 286,                     /* FOR  */
    INT = 287,                     /* INT  */
    NUMBER = 288,                  /* NUMBER  */
    IDENTIFIER = 289               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define ADD 260
#define SUB 261
#define MUL 262
#define DIV 263
#define EQ 264
#define LT 265
#define LTE 266
#define GT 267
#define GTE 268
#define NOT 269
#define AND 270
#define OR 271
#define PADD 272
#define PSUB 273
#define LPAREN 274
#define RPAREN 275
#define LCURL 276
#define RCURL 277
#define SEMICOLON 278
#define WHILE 279
#define COLON 280
#define SWITCH 281
#define BREAK 282
#define CONTINUE 283
#define DEFAULT 284
#define CASE 285
#define FOR 286
#define INT 287
#define NUMBER 288
#define IDENTIFIER 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "prob1.y"

    char lexeme[100];
    char addr[200];
    char addCase[200];
    char* lab;
    int dval;

#line 225 "y.tab.c"

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
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_ADD = 5,                        /* ADD  */
  YYSYMBOL_SUB = 6,                        /* SUB  */
  YYSYMBOL_MUL = 7,                        /* MUL  */
  YYSYMBOL_DIV = 8,                        /* DIV  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_LT = 10,                        /* LT  */
  YYSYMBOL_LTE = 11,                       /* LTE  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_GTE = 13,                       /* GTE  */
  YYSYMBOL_NOT = 14,                       /* NOT  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_PADD = 17,                      /* PADD  */
  YYSYMBOL_PSUB = 18,                      /* PSUB  */
  YYSYMBOL_LPAREN = 19,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 20,                    /* RPAREN  */
  YYSYMBOL_LCURL = 21,                     /* LCURL  */
  YYSYMBOL_RCURL = 22,                     /* RCURL  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_COLON = 25,                     /* COLON  */
  YYSYMBOL_SWITCH = 26,                    /* SWITCH  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 28,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 29,                   /* DEFAULT  */
  YYSYMBOL_CASE = 30,                      /* CASE  */
  YYSYMBOL_FOR = 31,                       /* FOR  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_NUMBER = 33,                    /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 34,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_StatementList = 36,             /* StatementList  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_38_2 = 38,                      /* $@2  */
  YYSYMBOL_39_3 = 39,                      /* $@3  */
  YYSYMBOL_ForStatement = 40,              /* ForStatement  */
  YYSYMBOL_41_4 = 41,                      /* $@4  */
  YYSYMBOL_42_5 = 42,                      /* $@5  */
  YYSYMBOL_43_6 = 43,                      /* $@6  */
  YYSYMBOL_Type = 44,                      /* Type  */
  YYSYMBOL_SwitchStatement = 45,           /* SwitchStatement  */
  YYSYMBOL_46_7 = 46,                      /* $@7  */
  YYSYMBOL_47_8 = 47,                      /* $@8  */
  YYSYMBOL_CaseStatements = 48,            /* CaseStatements  */
  YYSYMBOL_49_9 = 49,                      /* $@9  */
  YYSYMBOL_50_10 = 50,                     /* $@10  */
  YYSYMBOL_BreakStmt = 51,                 /* BreakStmt  */
  YYSYMBOL_IfStatement = 52,               /* IfStatement  */
  YYSYMBOL_53_11 = 53,                     /* $@11  */
  YYSYMBOL_54_12 = 54,                     /* $@12  */
  YYSYMBOL_ElseStmt = 55,                  /* ElseStmt  */
  YYSYMBOL_dummyLabels = 56,               /* dummyLabels  */
  YYSYMBOL_begin = 57,                     /* begin  */
  YYSYMBOL_Statement = 58,                 /* Statement  */
  YYSYMBOL_ComRelExp = 59,                 /* ComRelExp  */
  YYSYMBOL_Relexp = 60,                    /* Relexp  */
  YYSYMBOL_Term = 61,                      /* Term  */
  YYSYMBOL_Factor = 62,                    /* Factor  */
  YYSYMBOL_SIGNVal = 63,                   /* SIGNVal  */
  YYSYMBOL_CaseVal = 64,                   /* CaseVal  */
  YYSYMBOL_Val = 65                        /* Val  */
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    70,    71,    72,    72,    71,    73,    74,
      75,    80,    80,    80,    79,    84,    85,    90,    91,    90,
      95,    96,    95,    97,    98,   102,   105,   106,   105,   110,
     111,   112,   116,   120,   125,   131,   135,   145,   154,   158,
     167,   176,   185,   194,   203,   212,   222,   230,   234,   243,
     252,   256,   266,   276,   280,   284,   288,   293,   297,   306,
     309,   315,   323,   331,   339,   347
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "ADD",
  "SUB", "MUL", "DIV", "EQ", "LT", "LTE", "GT", "GTE", "NOT", "AND", "OR",
  "PADD", "PSUB", "LPAREN", "RPAREN", "LCURL", "RCURL", "SEMICOLON",
  "WHILE", "COLON", "SWITCH", "BREAK", "CONTINUE", "DEFAULT", "CASE",
  "FOR", "INT", "NUMBER", "IDENTIFIER", "$accept", "StatementList", "$@1",
  "$@2", "$@3", "ForStatement", "$@4", "$@5", "$@6", "Type",
  "SwitchStatement", "$@7", "$@8", "CaseStatements", "$@9", "$@10",
  "BreakStmt", "IfStatement", "$@11", "$@12", "ElseStmt", "dummyLabels",
  "begin", "Statement", "ComRelExp", "Relexp", "Term", "Factor", "SIGNVal",
  "CaseVal", "Val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    -9,    67,    67,   -19,   -12,    12,    15,    25,    28,
     -83,    32,     6,     2,   -83,     2,    43,     7,    53,   -83,
     -83,    34,    55,   -83,   -83,   -83,   -83,    86,    34,    49,
      44,    37,   -83,   -83,   -83,   -83,   -83,     2,    12,    12,
      12,    12,    34,    34,    88,   -83,   121,   -83,   122,   -83,
     -83,   -83,   -83,    37,   -83,   -83,    53,    53,   -83,   -83,
     -83,    60,   105,    34,    34,   -83,    48,    12,    12,    12,
      12,    78,    69,    82,    46,   -83,   -83,   -83,    92,    12,
       7,     7,     7,     7,    12,   -83,   103,   -83,   -83,     7,
       7,   -83,    66,   -83,     2,   -83,    95,    49,   114,    34,
     119,     2,     2,   120,   -83,   106,   -83,   124,   -83,   -83,
       2,   125,   143,   -83,   -83,   -83,   -83,    11,     2,   -83,
       2,    37,     2,   -83,   -83,     2,   123,   129,   130,   -83,
     128,   -83,   132,   -83,   -83,    66,     2,   -83,   -83,   133,
     -83
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    59,     0,    10,     8,    10,     0,    35,    50,    53,
      56,    47,    59,    54,    55,    61,    62,     0,    47,     0,
      16,     0,    63,    64,     1,     9,     3,    10,     0,     0,
       0,     0,    47,    47,     0,    38,     0,    65,     0,    58,
      57,    17,    15,     0,    34,     2,    48,    49,    51,    52,
      46,     0,     0,    47,    47,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,    36,    37,     0,     0,
      39,    40,    41,    42,     0,    33,     0,    33,    26,    43,
      44,    32,    24,    32,    10,     4,     0,     0,     0,    47,
       0,    10,    10,     0,    18,    11,    27,     0,    23,    32,
      10,     0,    31,     5,    20,    19,    12,     0,    10,     6,
      10,     0,    10,    30,    28,    10,     0,     0,     0,     7,
       0,    21,     0,    29,    25,    24,    10,    22,    13,     0,
      14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -13,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,    19,   -83,   -83,   -83,    39,   -83,   -83,
     -83,   -82,    70,   -28,   -24,    35,    -5,    90,    99,    61,
     141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,   101,   119,   125,    13,   111,   121,   139,    53,
      14,    73,   110,    98,   120,   135,   131,    15,    94,   112,
     118,    78,    91,    16,    44,    45,    17,    18,    19,    51,
      20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    27,    36,    54,    48,     1,    34,     2,     3,    95,
      21,    99,    38,    39,     1,    25,    46,     2,     3,     4,
       5,     6,    26,    46,    55,    74,     7,   114,     8,     4,
       5,     6,   122,     9,    28,    10,    11,    46,    62,     2,
       3,    31,     2,     3,    29,    10,    22,    30,    42,    32,
      33,     4,     5,    43,     4,     5,     6,    79,    46,    46,
      40,    41,    80,    81,    82,    83,    37,    10,    22,    87,
      10,    11,    32,    33,    89,   105,    52,    60,    61,    90,
      75,   100,    49,    50,     4,     5,     6,    84,   107,   108,
      85,    38,    39,   127,    46,    96,    97,   115,    76,    77,
      10,    22,    86,    63,    64,   124,    47,   126,    65,   128,
      38,    39,   129,    88,    66,    67,    68,    69,    70,    71,
     102,    63,    64,   138,    92,    47,    38,    39,    56,    57,
      66,    67,    68,    69,    70,    71,   104,    63,    64,    58,
      59,   106,    72,    23,    24,   109,   113,   117,   116,   132,
     130,   134,   133,   136,   137,   140,   123,    93,   103
};

static const yytype_uint8 yycheck[] =
{
      13,     6,    15,    31,    28,     3,     0,     5,     6,    91,
      19,    93,     5,     6,     3,    34,    21,     5,     6,    17,
      18,    19,    34,    28,    37,    53,    24,   109,    26,    17,
      18,    19,    21,    31,    19,    33,    34,    42,    43,     5,
       6,     9,     5,     6,    19,    33,    34,    19,    14,    17,
      18,    17,    18,    19,    17,    18,    19,     9,    63,    64,
       7,     8,    67,    68,    69,    70,    23,    33,    34,    23,
      33,    34,    17,    18,    79,    99,    32,    42,    43,    84,
      20,    94,    33,    34,    17,    18,    19,     9,   101,   102,
      21,     5,     6,   121,    99,    29,    30,   110,    63,    64,
      33,    34,    20,    15,    16,   118,    20,   120,    20,   122,
       5,     6,   125,    21,     9,    10,    11,    12,    13,    14,
      25,    15,    16,   136,    21,    20,     5,     6,    38,    39,
       9,    10,    11,    12,    13,    14,    22,    15,    16,    40,
      41,    22,    20,     2,     3,    25,    22,     4,    23,    20,
      27,    23,    22,    21,   135,    22,   117,    87,    97
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,    17,    18,    19,    24,    26,    31,
      33,    34,    36,    40,    45,    52,    58,    61,    62,    63,
      65,    19,    34,    65,    65,    34,    34,    61,    19,    19,
      19,     9,    17,    18,     0,    36,    36,    23,     5,     6,
       7,     8,    14,    19,    59,    60,    61,    20,    59,    33,
      34,    64,    32,    44,    58,    36,    62,    62,    63,    63,
      60,    60,    61,    15,    16,    20,     9,    10,    11,    12,
      13,    14,    20,    46,    58,    20,    60,    60,    56,     9,
      61,    61,    61,    61,     9,    21,    20,    23,    21,    61,
      61,    57,    21,    57,    53,    56,    29,    30,    48,    56,
      36,    37,    25,    64,    22,    59,    22,    36,    36,    25,
      47,    41,    54,    22,    56,    36,    23,     4,    55,    38,
      49,    42,    21,    52,    36,    39,    36,    58,    36,    36,
      27,    51,    20,    22,    23,    50,    21,    48,    36,    43,
      22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    38,    39,    36,    36,    36,
      36,    41,    42,    43,    40,    44,    44,    46,    47,    45,
      49,    50,    48,    48,    48,    51,    53,    54,    52,    55,
      55,    55,    56,    57,    58,    58,    59,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     0,     0,     0,    13,     1,     2,
       0,     0,     0,     0,    17,     1,     0,     0,     0,    10,
       0,     0,     9,     3,     0,     2,     0,     0,    12,     4,
       2,     0,     0,     0,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     4,     4,     3,     2,     0,     3,     3,
       1,     3,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     3
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
  case 2: /* StatementList: Statement SEMICOLON StatementList  */
#line 69 "prob1.y"
                                      { printf("\n"); }
#line 1362 "y.tab.c"
    break;

  case 3: /* StatementList: IfStatement StatementList  */
#line 70 "prob1.y"
                                { printf("\n"); }
#line 1368 "y.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 71 "prob1.y"
                                                            { printf("\nif %s goto %s:\ngoto %s:", (yyvsp[-4].addr), (yyvsp[-1].lab), (yyvsp[0].lab)); }
#line 1374 "y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 72 "prob1.y"
                          { printf("\ngoto %s:", (yyvsp[-4].lab)); }
#line 1380 "y.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 72 "prob1.y"
                                                        { printf("\n%s:", (yyvsp[-4].lab)); }
#line 1386 "y.tab.c"
    break;

  case 7: /* StatementList: WHILE LPAREN ComRelExp RPAREN LCURL begin dummyLabels $@1 StatementList RCURL $@2 $@3 StatementList  */
#line 72 "prob1.y"
                                                                                               { printf("\n"); }
#line 1392 "y.tab.c"
    break;

  case 8: /* StatementList: SwitchStatement  */
#line 73 "prob1.y"
                       { printf("\n"); }
#line 1398 "y.tab.c"
    break;

  case 9: /* StatementList: ForStatement StatementList  */
#line 74 "prob1.y"
                                 { printf("\n");}
#line 1404 "y.tab.c"
    break;

  case 10: /* StatementList: %empty  */
#line 75 "prob1.y"
     {}
#line 1410 "y.tab.c"
    break;

  case 11: /* $@4: %empty  */
#line 80 "prob1.y"
               {printf("\n%s :" , (yyvsp[-2].lab) );}
#line 1416 "y.tab.c"
    break;

  case 12: /* $@5: %empty  */
#line 80 "prob1.y"
                                                   {printf("\nifFalse %s goto %s", (yyvsp[-2].addr) ,(yyvsp[-3].lab) ) ;}
#line 1422 "y.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 80 "prob1.y"
                                                                                                                                   {printf("\ngoto %s" , (yyvsp[-9].lab) );}
#line 1428 "y.tab.c"
    break;

  case 14: /* ForStatement: FOR LPAREN Type Statement SEMICOLON begin dummyLabels ComRelExp $@4 SEMICOLON $@5 Statement RPAREN LCURL StatementList $@6 RCURL  */
#line 80 "prob1.y"
                                                                                                                                                                       {printf("\n%s:" ,(yyvsp[-10].lab)); }
#line 1434 "y.tab.c"
    break;

  case 17: /* $@7: %empty  */
#line 90 "prob1.y"
                           {count++; stack[count] = (char*)malloc(sizeof(char) * 1000); strcpy(stack[count], (yyvsp[0].addCase)); }
#line 1440 "y.tab.c"
    break;

  case 18: /* $@8: %empty  */
#line 91 "prob1.y"
                           {printf("\n%s:" , genOutLabel()); Ocount++ ;count --; }
#line 1446 "y.tab.c"
    break;

  case 19: /* SwitchStatement: SWITCH LPAREN CaseVal $@7 RPAREN LCURL CaseStatements RCURL $@8 StatementList  */
#line 91 "prob1.y"
                                                                                                 { printf("\n"); }
#line 1452 "y.tab.c"
    break;

  case 20: /* $@9: %empty  */
#line 95 "prob1.y"
                                   { printf("\nifFalse (%s == %s) goto %s", stack[count], (yyvsp[-2].addCase), (yyvsp[0].lab));}
#line 1458 "y.tab.c"
    break;

  case 21: /* $@10: %empty  */
#line 96 "prob1.y"
                             { printf("\n%s:",(yyvsp[-3].lab));}
#line 1464 "y.tab.c"
    break;

  case 23: /* CaseStatements: DEFAULT COLON StatementList  */
#line 97 "prob1.y"
                                  { printf("\n"); }
#line 1470 "y.tab.c"
    break;

  case 24: /* CaseStatements: %empty  */
#line 98 "prob1.y"
      {}
#line 1476 "y.tab.c"
    break;

  case 25: /* BreakStmt: BREAK SEMICOLON  */
#line 102 "prob1.y"
                    { printf("goto %s\n", OutLabel(Ocount)); }
#line 1482 "y.tab.c"
    break;

  case 26: /* $@11: %empty  */
#line 105 "prob1.y"
                                                 { printf("\nifFalse %s goto %s ", (yyvsp[-3].addr), (yyvsp[-1].lab)); }
#line 1488 "y.tab.c"
    break;

  case 27: /* $@12: %empty  */
#line 106 "prob1.y"
                        { printf("\n%s:", (yyvsp[-4].lab)); }
#line 1494 "y.tab.c"
    break;

  case 28: /* IfStatement: IF LPAREN ComRelExp RPAREN dummyLabels LCURL $@11 StatementList RCURL $@12 ElseStmt StatementList  */
#line 106 "prob1.y"
                                                                        { printf("\n"); }
#line 1500 "y.tab.c"
    break;

  case 29: /* ElseStmt: ELSE LCURL StatementList RCURL  */
#line 110 "prob1.y"
                                   {}
#line 1506 "y.tab.c"
    break;

  case 30: /* ElseStmt: ELSE IfStatement  */
#line 111 "prob1.y"
                       {}
#line 1512 "y.tab.c"
    break;

  case 31: /* ElseStmt: %empty  */
#line 112 "prob1.y"
      {}
#line 1518 "y.tab.c"
    break;

  case 32: /* dummyLabels: %empty  */
#line 116 "prob1.y"
    { (yyval.lab) = (char*)malloc(100 * sizeof(char)); (yyval.lab) = genBlockLabel(); }
#line 1524 "y.tab.c"
    break;

  case 33: /* begin: %empty  */
#line 120 "prob1.y"
    { (yyval.lab) = (char*)malloc(100 * sizeof(char)); (yyval.lab) = genBeginLabel(); }
#line 1530 "y.tab.c"
    break;

  case 34: /* Statement: IDENTIFIER EQ Statement  */
#line 125 "prob1.y"
                            {
        strcpy((yyval.addr), (yyvsp[-2].addr));
        strcat((yyval.addr), "=");
        strcat((yyval.addr), (yyvsp[0].addr));
        printf("\n%s", (yyval.addr));
    }
#line 1541 "y.tab.c"
    break;

  case 35: /* Statement: Term  */
#line 131 "prob1.y"
           { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1547 "y.tab.c"
    break;

  case 36: /* ComRelExp: ComRelExp AND Relexp  */
#line 135 "prob1.y"
                         {
    
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "&&");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1562 "y.tab.c"
    break;

  case 37: /* ComRelExp: ComRelExp OR Relexp  */
#line 145 "prob1.y"
                          {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "||");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1576 "y.tab.c"
    break;

  case 38: /* ComRelExp: Relexp  */
#line 154 "prob1.y"
             { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1582 "y.tab.c"
    break;

  case 39: /* Relexp: Term LT Term  */
#line 158 "prob1.y"
                 {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "<");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1596 "y.tab.c"
    break;

  case 40: /* Relexp: Term LTE Term  */
#line 167 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "<=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1610 "y.tab.c"
    break;

  case 41: /* Relexp: Term GT Term  */
#line 176 "prob1.y"
                   {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, ">");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1624 "y.tab.c"
    break;

  case 42: /* Relexp: Term GTE Term  */
#line 185 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, ">=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1638 "y.tab.c"
    break;

  case 43: /* Relexp: Term EQ EQ Term  */
#line 194 "prob1.y"
                      {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-3].addr));
        strcat(str, "==");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1652 "y.tab.c"
    break;

  case 44: /* Relexp: Term NOT EQ Term  */
#line 203 "prob1.y"
                       {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-3].addr));
        strcat(str, "!=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1666 "y.tab.c"
    break;

  case 45: /* Relexp: LPAREN Relexp RPAREN  */
#line 212 "prob1.y"
                           {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, "!");
        strcat(str, "(");
        strcat(str, (yyvsp[-1].addr));
        strcat(str, ")");
        printf("\n%s", str);
    }
#line 1681 "y.tab.c"
    break;

  case 46: /* Relexp: NOT Relexp  */
#line 222 "prob1.y"
                 {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, "!");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1694 "y.tab.c"
    break;

  case 47: /* Relexp: %empty  */
#line 230 "prob1.y"
      {}
#line 1700 "y.tab.c"
    break;

  case 48: /* Term: Term ADD Factor  */
#line 234 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "+");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1714 "y.tab.c"
    break;

  case 49: /* Term: Term SUB Factor  */
#line 243 "prob1.y"
                      {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "-");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1728 "y.tab.c"
    break;

  case 50: /* Term: Factor  */
#line 252 "prob1.y"
             { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1734 "y.tab.c"
    break;

  case 51: /* Factor: Factor MUL SIGNVal  */
#line 256 "prob1.y"
                       {
        char* g = genLabel();
        strcpy((yyval.addr), g);
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "*");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1749 "y.tab.c"
    break;

  case 52: /* Factor: Factor DIV SIGNVal  */
#line 266 "prob1.y"
                        {
        char* g = genLabel();
        strcpy((yyval.addr), g);
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "/");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1764 "y.tab.c"
    break;

  case 53: /* Factor: SIGNVal  */
#line 276 "prob1.y"
              { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1770 "y.tab.c"
    break;

  case 54: /* SIGNVal: ADD Val  */
#line 280 "prob1.y"
            {
        strcpy((yyval.addr), "+");
        strcat((yyval.addr), (yyvsp[0].addr));
    }
#line 1779 "y.tab.c"
    break;

  case 55: /* SIGNVal: SUB Val  */
#line 284 "prob1.y"
              {
        strcpy((yyval.addr), "-");
        strcat((yyval.addr), (yyvsp[0].addr));
    }
#line 1788 "y.tab.c"
    break;

  case 56: /* SIGNVal: Val  */
#line 288 "prob1.y"
          { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1794 "y.tab.c"
    break;

  case 57: /* CaseVal: IDENTIFIER  */
#line 293 "prob1.y"
                {
        
        strcpy((yyval.addCase), (yyvsp[0].addr));
    }
#line 1803 "y.tab.c"
    break;

  case 58: /* CaseVal: NUMBER  */
#line 297 "prob1.y"
             {
        char* buf = (char*)malloc(sizeof(char) * 1000);
        int dummyLabels = (yyvsp[0].dval);
        sprintf(buf, "%d", dummyLabels);
        strcpy((yyval.addCase), buf);
    }
#line 1814 "y.tab.c"
    break;

  case 59: /* Val: IDENTIFIER  */
#line 306 "prob1.y"
               {
        strcpy((yyval.addr), (yyvsp[0].addr));
    }
#line 1822 "y.tab.c"
    break;

  case 60: /* Val: NUMBER  */
#line 309 "prob1.y"
             {
        char* buf = (char*)malloc(sizeof(char) * 1000);
        int dummyLabels = (yyvsp[0].dval);
        sprintf(buf, "%d", dummyLabels);
        strcpy((yyval.addr), buf);
    }
#line 1833 "y.tab.c"
    break;

  case 61: /* Val: PADD IDENTIFIER  */
#line 315 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[0].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[0].addr));
        strcat(str, "+1");
        printf("\n%s", str);
    }
#line 1846 "y.tab.c"
    break;

  case 62: /* Val: PSUB IDENTIFIER  */
#line 323 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[0].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[0].addr));
        strcat(str, "-1");
        printf("\n%s", str);
    }
#line 1859 "y.tab.c"
    break;

  case 63: /* Val: IDENTIFIER PADD  */
#line 331 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[-1].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-1].addr));
        strcat(str, "+1");
        printf("\n%s", str);
    }
#line 1872 "y.tab.c"
    break;

  case 64: /* Val: IDENTIFIER PSUB  */
#line 339 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[-1].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-1].addr));
        strcat(str, "-1");
        printf("\n%s", str);
    }
#line 1885 "y.tab.c"
    break;

  case 65: /* Val: LPAREN Term RPAREN  */
#line 347 "prob1.y"
                         { strcpy((yyval.addr), (yyvsp[-1].addr)); }
#line 1891 "y.tab.c"
    break;


#line 1895 "y.tab.c"

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

#line 350 "prob1.y"


void yyerror(char* s) {
    while (yylex() != SEMICOLON && yylex() != EOF);
    printf("Rejected EXPR\n");
    yyparse();
}

char* genLabel() {
    char* s = (char*)malloc(sizeof(char) * 1000);
    char* label = (char*)malloc(sizeof(char) * 1000);
    strcpy(s, "t");
    sprintf(label, "%d", t);
    strcat(s, label);
    t++;
    return s;
}

char* genBlockLabel() {
    char* s = (char*)malloc(sizeof(char) * 1000);
    char* label = (char*)malloc(sizeof(char) * 1000);
    strcpy(s, "L");
/*Out:
    { $$ = (char*)malloc(100 * sizeof(char)); $$ = genOutLabel(); }*/
    sprintf(label, "%d", l);
    strcat(s, label);
    l++;
    return s;
}

char* genBeginLabel() {
    char* s = (char*)malloc(sizeof(char) * 1000);
    char* label = (char*)malloc(sizeof(char) * 1000);
    strcpy(s, "BEGIN");
    sprintf(label, "%d", w);
    strcat(s, label);
    w++;
    return s;
}

char* genOutLabel() {
    char* s = (char*)malloc(sizeof(char) * 1000);
    char* label = (char*)malloc(sizeof(char) * 1000);
    strcpy(s, "OUT");
    sprintf(label, "%d", z);
    strcat(s, label);
    z++;
    return s;
}
char* OutLabel(int Ocount){
    char* s = (char*)malloc(sizeof(char) * 1000);
    char* label = (char*)malloc(sizeof(char) * 1000);
    strcpy(s, "OUT");
    sprintf(label, "%d", Ocount);
    strcat(s, label);
    Ocount++;
    return s;
}


int main(int argc, char* argv[]) {
    if (argc > 1) {
        FILE* fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
    }
    yyparse();
    return 0;
}
