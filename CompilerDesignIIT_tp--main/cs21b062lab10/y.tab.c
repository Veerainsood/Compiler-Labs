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
    NUMBER = 286,                  /* NUMBER  */
    IDENTIFIER = 287               /* IDENTIFIER  */
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
#define NUMBER 286
#define IDENTIFIER 287

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

#line 221 "y.tab.c"

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
  YYSYMBOL_NUMBER = 31,                    /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 32,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_StatementList = 34,             /* StatementList  */
  YYSYMBOL_35_1 = 35,                      /* $@1  */
  YYSYMBOL_36_2 = 36,                      /* $@2  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_SwitchStatement = 38,           /* SwitchStatement  */
  YYSYMBOL_39_4 = 39,                      /* $@4  */
  YYSYMBOL_40_5 = 40,                      /* $@5  */
  YYSYMBOL_CaseStatements = 41,            /* CaseStatements  */
  YYSYMBOL_42_6 = 42,                      /* $@6  */
  YYSYMBOL_43_7 = 43,                      /* $@7  */
  YYSYMBOL_BreakStmt = 44,                 /* BreakStmt  */
  YYSYMBOL_IfStatement = 45,               /* IfStatement  */
  YYSYMBOL_46_8 = 46,                      /* $@8  */
  YYSYMBOL_47_9 = 47,                      /* $@9  */
  YYSYMBOL_ElseStmt = 48,                  /* ElseStmt  */
  YYSYMBOL_dummyLabels = 49,               /* dummyLabels  */
  YYSYMBOL_begin = 50,                     /* begin  */
  YYSYMBOL_Statement = 51,                 /* Statement  */
  YYSYMBOL_ComRelExp = 52,                 /* ComRelExp  */
  YYSYMBOL_Relexp = 53,                    /* Relexp  */
  YYSYMBOL_Term = 54,                      /* Term  */
  YYSYMBOL_Factor = 55,                    /* Factor  */
  YYSYMBOL_SIGNVal = 56,                   /* SIGNVal  */
  YYSYMBOL_CaseVal = 57,                   /* CaseVal  */
  YYSYMBOL_Val = 58                        /* Val  */
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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    68,    69,    70,    70,    69,    71,    72,
      76,    77,    76,    81,    82,    81,    83,    84,    88,    91,
      92,    91,    96,    97,    98,   102,   105,   109,   115,   119,
     128,   137,   141,   150,   159,   168,   177,   186,   195,   205,
     213,   217,   226,   235,   239,   249,   259,   263,   267,   271,
     276,   280,   289,   292,   298,   306,   314,   322,   330
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
  "NUMBER", "IDENTIFIER", "$accept", "StatementList", "$@1", "$@2", "$@3",
  "SwitchStatement", "$@4", "$@5", "CaseStatements", "$@6", "$@7",
  "BreakStmt", "IfStatement", "$@8", "$@9", "ElseStmt", "dummyLabels",
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
static const yytype_int8 yypact[] =
{
       0,     2,    57,    57,   -18,    -9,    31,    14,    58,   -83,
      -5,    85,   -83,     0,    64,     5,    32,   -83,   -83,    24,
      27,   -83,   -83,   -83,   -83,    41,    24,    20,    65,   -83,
     -83,   -83,   -83,     0,    31,    31,    31,    31,    24,    24,
      49,   -83,   106,   -83,   107,   -83,   -83,   -83,   -83,   -83,
      32,    32,   -83,   -83,   -83,    73,    94,    24,    24,   -83,
     100,    31,    31,    31,    31,   101,    92,   104,   -83,   -83,
     -83,   105,    31,     5,     5,     5,     5,    31,   -83,   108,
     -83,     5,     5,   -83,    37,     0,   -83,    96,    20,   103,
     109,     0,     0,   110,   -83,   -83,   111,   -83,   -83,     0,
     124,   -83,   -83,   -83,     4,     0,   -83,     0,     0,   -83,
     -83,     0,   112,   114,   -83,   115,   -83,   -83,   -83,    37,
     -83
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       9,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      52,     0,     8,     9,     0,    28,    43,    46,    49,    40,
      52,    47,    48,    54,    55,     0,    40,     0,     0,    56,
      57,     1,     3,     9,     0,     0,     0,     0,    40,    40,
       0,    31,     0,    58,     0,    51,    50,    10,    27,     2,
      41,    42,    44,    45,    39,     0,     0,    40,    40,    25,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    29,
      30,     0,     0,    32,    33,    34,    35,     0,    26,     0,
      19,    36,    37,    25,    17,     9,     4,     0,     0,     0,
       0,     9,     9,     0,    11,    20,     0,    16,    25,     9,
      24,     5,    13,    12,     0,     9,     6,     9,     9,    23,
      21,     9,     0,     0,     7,     0,    14,    22,    18,    17,
      15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -13,   -83,   -83,   -83,   -83,   -83,   -83,    11,   -83,
     -83,   -83,    28,   -83,   -83,   -83,   -82,   -83,   113,   116,
     -30,    -4,    46,    54,    52,    99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    91,   106,   111,    12,    67,    99,    89,   107,
     119,   116,    13,    85,   100,   105,    71,    83,    14,    40,
      41,    15,    16,    17,    47,    18
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    86,    25,     1,    28,     2,     3,     1,    54,    55,
      34,    35,    29,    30,    23,    42,   102,     4,     5,     6,
      49,    19,    42,    24,     7,   108,     8,    69,    70,     2,
       3,     9,    10,    26,    42,    56,     2,     3,    38,    36,
      37,     4,     5,    39,    29,    30,    34,    35,     4,     5,
       6,    45,    46,    42,    42,     9,    20,    73,    74,    75,
      76,    43,     9,    20,    57,    58,    87,    88,    81,    59,
       2,     3,    90,    82,     4,     5,     6,    27,    96,    97,
      50,    51,     4,     5,     6,    31,   103,    33,     9,    20,
      52,    53,   110,    68,   112,   113,     9,    10,   114,    34,
      35,    21,    22,    60,    61,    62,    63,    64,    65,    72,
      77,    34,    35,    78,    43,    60,    61,    62,    63,    64,
      65,    92,    57,    58,    79,    94,    80,    66,   104,    84,
     120,    95,   109,   101,     0,    98,   117,     0,   118,   115,
      93,    48,    44
};

static const yytype_int8 yycheck[] =
{
      13,    83,     6,     3,     9,     5,     6,     3,    38,    39,
       5,     6,    17,    18,    32,    19,    98,    17,    18,    19,
      33,    19,    26,    32,    24,    21,    26,    57,    58,     5,
       6,    31,    32,    19,    38,    39,     5,     6,    14,     7,
       8,    17,    18,    19,    17,    18,     5,     6,    17,    18,
      19,    31,    32,    57,    58,    31,    32,    61,    62,    63,
      64,    20,    31,    32,    15,    16,    29,    30,    72,    20,
       5,     6,    85,    77,    17,    18,    19,    19,    91,    92,
      34,    35,    17,    18,    19,     0,    99,    23,    31,    32,
      36,    37,   105,    20,   107,   108,    31,    32,   111,     5,
       6,     2,     3,     9,    10,    11,    12,    13,    14,     9,
       9,     5,     6,    21,    20,     9,    10,    11,    12,    13,
      14,    25,    15,    16,    20,    22,    21,    20,     4,    21,
     119,    22,   104,    22,    -1,    25,    22,    -1,    23,    27,
      88,    28,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,    17,    18,    19,    24,    26,    31,
      32,    34,    38,    45,    51,    54,    55,    56,    58,    19,
      32,    58,    58,    32,    32,    54,    19,    19,     9,    17,
      18,     0,    34,    23,     5,     6,     7,     8,    14,    19,
      52,    53,    54,    20,    52,    31,    32,    57,    51,    34,
      55,    55,    56,    56,    53,    53,    54,    15,    16,    20,
       9,    10,    11,    12,    13,    14,    20,    39,    20,    53,
      53,    49,     9,    54,    54,    54,    54,     9,    21,    20,
      21,    54,    54,    50,    21,    46,    49,    29,    30,    41,
      34,    35,    25,    57,    22,    22,    34,    34,    25,    40,
      47,    22,    49,    34,     4,    48,    36,    42,    21,    45,
      34,    37,    34,    34,    34,    27,    44,    22,    23,    43,
      41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    36,    37,    34,    34,    34,
      39,    40,    38,    42,    43,    41,    41,    41,    44,    46,
      47,    45,    48,    48,    48,    49,    50,    51,    51,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     0,     0,     0,    13,     1,     0,
       0,     0,    10,     0,     0,     9,     3,     0,     2,     0,
       0,    12,     4,     2,     0,     0,     0,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     4,     4,     3,     2,
       0,     3,     3,     1,     3,     3,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     3
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
#line 67 "prob1.y"
                                      { printf("\n"); }
#line 1337 "y.tab.c"
    break;

  case 3: /* StatementList: IfStatement StatementList  */
#line 68 "prob1.y"
                                { printf("\n"); }
#line 1343 "y.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 69 "prob1.y"
                                                            { printf("\nif %s goto %s:\ngoto %s:", (yyvsp[-4].addr), (yyvsp[-1].lab), (yyvsp[0].lab)); }
#line 1349 "y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 70 "prob1.y"
                          { printf("\ngoto %s:", (yyvsp[-4].lab)); }
#line 1355 "y.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 70 "prob1.y"
                                                        { printf("\n%s:", (yyvsp[-4].lab)); }
#line 1361 "y.tab.c"
    break;

  case 7: /* StatementList: WHILE LPAREN ComRelExp RPAREN LCURL begin dummyLabels $@1 StatementList RCURL $@2 $@3 StatementList  */
#line 70 "prob1.y"
                                                                                               { printf("\n"); }
#line 1367 "y.tab.c"
    break;

  case 8: /* StatementList: SwitchStatement  */
#line 71 "prob1.y"
                       { printf("\n"); }
#line 1373 "y.tab.c"
    break;

  case 9: /* StatementList: %empty  */
#line 72 "prob1.y"
     {}
#line 1379 "y.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 76 "prob1.y"
                           {count++; stack[count] = (char*)malloc(sizeof(char) * 1000); strcpy(stack[count], (yyvsp[0].addCase)); }
#line 1385 "y.tab.c"
    break;

  case 11: /* $@5: %empty  */
#line 77 "prob1.y"
                           {printf("\n%s:" , genOutLabel()); Ocount++ ;count --; }
#line 1391 "y.tab.c"
    break;

  case 12: /* SwitchStatement: SWITCH LPAREN CaseVal $@4 RPAREN LCURL CaseStatements RCURL $@5 StatementList  */
#line 77 "prob1.y"
                                                                                                 { printf("\n"); }
#line 1397 "y.tab.c"
    break;

  case 13: /* $@6: %empty  */
#line 81 "prob1.y"
                                   { printf("\nifFalse (%s == %s) goto %s", stack[count], (yyvsp[-2].addCase), (yyvsp[0].lab));}
#line 1403 "y.tab.c"
    break;

  case 14: /* $@7: %empty  */
#line 82 "prob1.y"
                             { printf("\n%s:",(yyvsp[-3].lab));}
#line 1409 "y.tab.c"
    break;

  case 16: /* CaseStatements: DEFAULT COLON StatementList  */
#line 83 "prob1.y"
                                  { printf("\n"); }
#line 1415 "y.tab.c"
    break;

  case 17: /* CaseStatements: %empty  */
#line 84 "prob1.y"
      {}
#line 1421 "y.tab.c"
    break;

  case 18: /* BreakStmt: BREAK SEMICOLON  */
#line 88 "prob1.y"
                    { printf("goto %s\n", OutLabel(Ocount)); }
#line 1427 "y.tab.c"
    break;

  case 19: /* $@8: %empty  */
#line 91 "prob1.y"
                                                 { printf("\nifFalse %s goto %s ", (yyvsp[-3].addr), (yyvsp[-1].lab)); }
#line 1433 "y.tab.c"
    break;

  case 20: /* $@9: %empty  */
#line 92 "prob1.y"
                        { printf("\n%s:", (yyvsp[-4].lab)); }
#line 1439 "y.tab.c"
    break;

  case 21: /* IfStatement: IF LPAREN ComRelExp RPAREN dummyLabels LCURL $@8 StatementList RCURL $@9 ElseStmt StatementList  */
#line 92 "prob1.y"
                                                                        { printf("\n"); }
#line 1445 "y.tab.c"
    break;

  case 22: /* ElseStmt: ELSE LCURL StatementList RCURL  */
#line 96 "prob1.y"
                                   {}
#line 1451 "y.tab.c"
    break;

  case 23: /* ElseStmt: ELSE IfStatement  */
#line 97 "prob1.y"
                       {}
#line 1457 "y.tab.c"
    break;

  case 24: /* ElseStmt: %empty  */
#line 98 "prob1.y"
      {}
#line 1463 "y.tab.c"
    break;

  case 25: /* dummyLabels: %empty  */
#line 102 "prob1.y"
    { (yyval.lab) = (char*)malloc(100 * sizeof(char)); (yyval.lab) = genBlockLabel(); }
#line 1469 "y.tab.c"
    break;

  case 26: /* begin: %empty  */
#line 105 "prob1.y"
    { (yyval.lab) = (char*)malloc(100 * sizeof(char)); (yyval.lab) = genBeginLabel(); }
#line 1475 "y.tab.c"
    break;

  case 27: /* Statement: IDENTIFIER EQ Statement  */
#line 109 "prob1.y"
                            {
        strcpy((yyval.addr), (yyvsp[-2].addr));
        strcat((yyval.addr), "=");
        strcat((yyval.addr), (yyvsp[0].addr));
        printf("\n%s", (yyval.addr));
    }
#line 1486 "y.tab.c"
    break;

  case 28: /* Statement: Term  */
#line 115 "prob1.y"
           { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1492 "y.tab.c"
    break;

  case 29: /* ComRelExp: ComRelExp AND Relexp  */
#line 119 "prob1.y"
                         {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "&&");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1506 "y.tab.c"
    break;

  case 30: /* ComRelExp: ComRelExp OR Relexp  */
#line 128 "prob1.y"
                          {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "||");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1520 "y.tab.c"
    break;

  case 31: /* ComRelExp: Relexp  */
#line 137 "prob1.y"
             { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1526 "y.tab.c"
    break;

  case 32: /* Relexp: Term LT Term  */
#line 141 "prob1.y"
                 {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "<");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1540 "y.tab.c"
    break;

  case 33: /* Relexp: Term LTE Term  */
#line 150 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "<=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1554 "y.tab.c"
    break;

  case 34: /* Relexp: Term GT Term  */
#line 159 "prob1.y"
                   {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, ">");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1568 "y.tab.c"
    break;

  case 35: /* Relexp: Term GTE Term  */
#line 168 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, ">=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1582 "y.tab.c"
    break;

  case 36: /* Relexp: Term EQ EQ Term  */
#line 177 "prob1.y"
                      {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-3].addr));
        strcat(str, "==");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1596 "y.tab.c"
    break;

  case 37: /* Relexp: Term NOT EQ Term  */
#line 186 "prob1.y"
                       {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-3].addr));
        strcat(str, "!=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1610 "y.tab.c"
    break;

  case 38: /* Relexp: LPAREN Relexp RPAREN  */
#line 195 "prob1.y"
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
#line 1625 "y.tab.c"
    break;

  case 39: /* Relexp: NOT Relexp  */
#line 205 "prob1.y"
                 {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, "!");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1638 "y.tab.c"
    break;

  case 40: /* Relexp: %empty  */
#line 213 "prob1.y"
      {}
#line 1644 "y.tab.c"
    break;

  case 41: /* Term: Term ADD Factor  */
#line 217 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "+");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1658 "y.tab.c"
    break;

  case 42: /* Term: Term SUB Factor  */
#line 226 "prob1.y"
                      {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "-");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1672 "y.tab.c"
    break;

  case 43: /* Term: Factor  */
#line 235 "prob1.y"
             { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1678 "y.tab.c"
    break;

  case 44: /* Factor: Factor MUL SIGNVal  */
#line 239 "prob1.y"
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
#line 1693 "y.tab.c"
    break;

  case 45: /* Factor: Factor DIV SIGNVal  */
#line 249 "prob1.y"
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
#line 1708 "y.tab.c"
    break;

  case 46: /* Factor: SIGNVal  */
#line 259 "prob1.y"
              { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1714 "y.tab.c"
    break;

  case 47: /* SIGNVal: ADD Val  */
#line 263 "prob1.y"
            {
        strcpy((yyval.addr), "+");
        strcat((yyval.addr), (yyvsp[0].addr));
    }
#line 1723 "y.tab.c"
    break;

  case 48: /* SIGNVal: SUB Val  */
#line 267 "prob1.y"
              {
        strcpy((yyval.addr), "-");
        strcat((yyval.addr), (yyvsp[0].addr));
    }
#line 1732 "y.tab.c"
    break;

  case 49: /* SIGNVal: Val  */
#line 271 "prob1.y"
          { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1738 "y.tab.c"
    break;

  case 50: /* CaseVal: IDENTIFIER  */
#line 276 "prob1.y"
                {
        
        strcpy((yyval.addCase), (yyvsp[0].addr));
    }
#line 1747 "y.tab.c"
    break;

  case 51: /* CaseVal: NUMBER  */
#line 280 "prob1.y"
             {
        char* buf = (char*)malloc(sizeof(char) * 1000);
        int dummyLabels = (yyvsp[0].dval);
        sprintf(buf, "%d", dummyLabels);
        strcpy((yyval.addCase), buf);
    }
#line 1758 "y.tab.c"
    break;

  case 52: /* Val: IDENTIFIER  */
#line 289 "prob1.y"
               {
        strcpy((yyval.addr), (yyvsp[0].addr));
    }
#line 1766 "y.tab.c"
    break;

  case 53: /* Val: NUMBER  */
#line 292 "prob1.y"
             {
        char* buf = (char*)malloc(sizeof(char) * 1000);
        int dummyLabels = (yyvsp[0].dval);
        sprintf(buf, "%d", dummyLabels);
        strcpy((yyval.addr), buf);
    }
#line 1777 "y.tab.c"
    break;

  case 54: /* Val: PADD IDENTIFIER  */
#line 298 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[0].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[0].addr));
        strcat(str, "+1");
        printf("\n%s", str);
    }
#line 1790 "y.tab.c"
    break;

  case 55: /* Val: PSUB IDENTIFIER  */
#line 306 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[0].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[0].addr));
        strcat(str, "-1");
        printf("\n%s", str);
    }
#line 1803 "y.tab.c"
    break;

  case 56: /* Val: IDENTIFIER PADD  */
#line 314 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[-1].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-1].addr));
        strcat(str, "+1");
        printf("\n%s", str);
    }
#line 1816 "y.tab.c"
    break;

  case 57: /* Val: IDENTIFIER PSUB  */
#line 322 "prob1.y"
                      {
        strcpy((yyval.addr), (yyvsp[-1].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-1].addr));
        strcat(str, "-1");
        printf("\n%s", str);
    }
#line 1829 "y.tab.c"
    break;

  case 58: /* Val: LPAREN Term RPAREN  */
#line 330 "prob1.y"
                         { strcpy((yyval.addr), (yyvsp[-1].addr)); }
#line 1835 "y.tab.c"
    break;


#line 1839 "y.tab.c"

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

#line 333 "prob1.y"


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
