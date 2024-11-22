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
void add_symbol(char* name, char* type, int val , char* addr);


int t = 0;
int l = 0;
int w = 0;
int z = 0 ; 
int count = 1;
int stackCount = 1;
// stack for storing the labels
char* stack[1000] ;
int Ocount = 0;


typedef struct {
    char* name;
     char* type;
    union {
        int intval;
        double doubleval;
        float floatval;
        char charval;
    } val;
    char addr[200];
} Symbol;

Symbol* symtab[10000];
void HandleSymTble(char* identifier, char* number, char* symtype, int* symcount, int* addrCount, Symbol** symtab) ;
char* symtype;
char* locationforIfelse;
void verify(char * id );
int addrCount= 0; 
int symcount = 0;
int symcount_stack[1000];
// char  *store = (char*)malloc(sizeof(char)*1000);

#line 123 "y.tab.c"

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
    COMMA = 286,                   /* COMMA  */
    LBRACK = 287,                  /* LBRACK  */
    RBRACK = 288,                  /* RBRACK  */
    INT = 289,                     /* INT  */
    DOUBLE = 290,                  /* DOUBLE  */
    FLOAT = 291,                   /* FLOAT  */
    CHAR = 292,                    /* CHAR  */
    CHARCONST = 293,               /* CHARCONST  */
    NUMBER = 294,                  /* NUMBER  */
    STRINGCONST = 295,             /* STRINGCONST  */
    IDENTIFIER = 296               /* IDENTIFIER  */
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
#define COMMA 286
#define LBRACK 287
#define RBRACK 288
#define INT 289
#define DOUBLE 290
#define FLOAT 291
#define CHAR 292
#define CHARCONST 293
#define NUMBER 294
#define STRINGCONST 295
#define IDENTIFIER 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "prob1.y"

    char lexeme[100];
    char addr[200];   // trying to achieve inherent variable without defining a struct
    char addCase[200];
    char* lab;
    int dval;
    char cval;

#line 267 "y.tab.c"

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
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_LBRACK = 32,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 33,                    /* RBRACK  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_DOUBLE = 35,                    /* DOUBLE  */
  YYSYMBOL_FLOAT = 36,                     /* FLOAT  */
  YYSYMBOL_CHAR = 37,                      /* CHAR  */
  YYSYMBOL_CHARCONST = 38,                 /* CHARCONST  */
  YYSYMBOL_NUMBER = 39,                    /* NUMBER  */
  YYSYMBOL_STRINGCONST = 40,               /* STRINGCONST  */
  YYSYMBOL_IDENTIFIER = 41,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_StatementList = 43,             /* StatementList  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_DeclarationList = 47,           /* DeclarationList  */
  YYSYMBOL_Declaration = 48,               /* Declaration  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_type = 50,                      /* type  */
  YYSYMBOL_variablelist = 51,              /* variablelist  */
  YYSYMBOL_Bracket = 52,                   /* Bracket  */
  YYSYMBOL_ConstIden = 53,                 /* ConstIden  */
  YYSYMBOL_SwitchStatement = 54,           /* SwitchStatement  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_CaseStatements = 57,            /* CaseStatements  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_BreakStmt = 60,                 /* BreakStmt  */
  YYSYMBOL_IfStatement = 61,               /* IfStatement  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_63_10 = 63,                     /* $@10  */
  YYSYMBOL_64_11 = 64,                     /* $@11  */
  YYSYMBOL_65_12 = 65,                     /* $@12  */
  YYSYMBOL_ElseIfStatement = 66,           /* ElseIfStatement  */
  YYSYMBOL_67_13 = 67,                     /* $@13  */
  YYSYMBOL_68_14 = 68,                     /* $@14  */
  YYSYMBOL_69_15 = 69,                     /* $@15  */
  YYSYMBOL_70_16 = 70,                     /* $@16  */
  YYSYMBOL_ElseStmt = 71,                  /* ElseStmt  */
  YYSYMBOL_CmpStm = 72,                    /* CmpStm  */
  YYSYMBOL_dummyLabels = 73,               /* dummyLabels  */
  YYSYMBOL_begin = 74,                     /* begin  */
  YYSYMBOL_Statement = 75,                 /* Statement  */
  YYSYMBOL_ComRelExp = 76,                 /* ComRelExp  */
  YYSYMBOL_Relexp = 77,                    /* Relexp  */
  YYSYMBOL_Term = 78,                      /* Term  */
  YYSYMBOL_Factor = 79,                    /* Factor  */
  YYSYMBOL_SIGNVal = 80,                   /* SIGNVal  */
  YYSYMBOL_CaseVal = 81,                   /* CaseVal  */
  YYSYMBOL_Val = 82                        /* Val  */
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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   105,   106,   107,   108,   108,   107,   109,
     110,   115,   116,   120,   120,   121,   125,   130,   135,   139,
     145,   149,   153,   158,   163,   170,   172,   180,   187,   191,
     197,   208,   209,   208,   213,   214,   213,   215,   216,   220,
     223,   224,   225,   225,   223,   230,   231,   231,   231,   230,
     232,   235,   236,   239,   239,   243,   246,   250,   258,   262,
     271,   280,   284,   293,   302,   311,   320,   329,   338,   348,
     356,   360,   369,   378,   382,   392,   402,   406,   410,   414,
     419,   423,   432,   436,   442,   451,   460,   469,   478
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
  "COMMA", "LBRACK", "RBRACK", "INT", "DOUBLE", "FLOAT", "CHAR",
  "CHARCONST", "NUMBER", "STRINGCONST", "IDENTIFIER", "$accept",
  "StatementList", "$@1", "$@2", "$@3", "DeclarationList", "Declaration",
  "$@4", "type", "variablelist", "Bracket", "ConstIden", "SwitchStatement",
  "$@5", "$@6", "CaseStatements", "$@7", "$@8", "BreakStmt", "IfStatement",
  "$@9", "$@10", "$@11", "$@12", "ElseIfStatement", "$@13", "$@14", "$@15",
  "$@16", "ElseStmt", "CmpStm", "dummyLabels", "begin", "Statement",
  "ComRelExp", "Relexp", "Term", "Factor", "SIGNVal", "CaseVal", "Val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     125,    -3,    78,    78,   -32,   -16,    15,  -112,    12,    18,
    -112,  -112,  -112,  -112,  -112,     1,    55,   125,    86,    19,
     125,  -112,    44,    59,    75,  -112,  -112,    22,    96,  -112,
    -112,  -112,  -112,    39,    86,    52,    11,    67,  -112,  -112,
    -112,  -112,  -112,    17,    51,  -112,   125,    15,    15,    15,
      15,    52,    52,    42,  -112,   111,  -112,   174,  -112,    65,
      85,   174,  -112,  -112,  -112,  -112,    71,    19,    38,    61,
    -112,  -112,    75,    75,  -112,  -112,  -112,    74,   162,  -112,
      52,    52,    90,    15,    15,    15,    15,    93,  -112,    95,
     104,  -112,   109,    96,   110,  -112,  -112,   112,    19,  -112,
     108,  -112,  -112,    15,    59,    59,    59,    59,    15,  -112,
     131,    19,   122,  -112,  -112,    59,    59,  -112,   105,  -112,
    -112,   125,  -112,   130,    11,   134,  -112,  -112,   125,   133,
    -112,  -112,   125,  -112,  -112,   125,   141,   143,  -112,  -112,
    -112,  -112,   125,   165,  -112,   150,    14,  -112,  -112,   125,
     147,  -112,   159,   125,   125,  -112,  -112,   105,    22,   167,
    -112,  -112,   161,  -112,  -112,   169,  -112,   125,  -112,   170,
    -112,   187,   172,  -112,   125,  -112
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      10,     0,     0,     0,     0,     0,     0,    13,     0,     0,
      16,    17,    18,    19,    83,    82,     0,    10,    12,     0,
      10,     4,     0,    58,    73,    76,    79,    70,    82,    77,
      78,    84,    85,     0,     0,    70,     0,     0,    86,    87,
       1,     2,    11,    26,     0,     9,    10,     0,     0,     0,
       0,    70,    70,     0,    54,    53,    61,    58,    88,     0,
       0,     0,    81,    80,    31,    57,     0,     0,     0,    24,
      15,     3,    71,    72,    74,    75,    69,     0,     0,    55,
      70,    70,     0,     0,     0,     0,     0,     0,    14,     0,
       0,    23,    22,    30,     0,    29,    20,     0,     0,    68,
       0,    59,    60,     0,    62,    63,    64,    65,     0,    56,
       0,     0,    27,    21,    40,    66,    67,    55,    38,    25,
      28,    10,    55,     0,     0,     0,    55,     5,    10,     0,
      32,    41,    10,    37,    55,    10,     0,     0,    34,    33,
      42,     6,    10,    52,     7,     0,     0,    43,    50,    10,
       0,    35,     0,    10,    10,     8,    39,    38,    70,     0,
      44,    36,     0,    51,    55,     0,    45,    10,    46,     0,
      47,    52,     0,    48,    10,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,   -17,  -112,  -112,  -112,   -10,  -112,  -112,  -112,   -60,
      82,  -112,  -112,  -112,  -112,    40,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,    24,
      41,  -111,  -112,   -25,   163,   -38,    -5,    91,    98,    72,
       2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    16,   132,   144,   149,    17,    18,    34,    19,    44,
      69,    94,    20,    90,   135,   125,   142,   157,   151,    21,
     121,   136,   143,   154,   147,   167,   169,   171,   174,   148,
      53,   100,   117,    22,    55,    56,    23,    24,    25,    64,
      26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    33,    54,    45,    29,    30,   122,    96,    42,    31,
      37,   127,    65,    76,    77,   131,    27,   152,    38,    39,
       2,     3,    57,   138,    59,    32,    66,     2,     3,    71,
      61,    35,     4,     5,     6,   153,    51,    36,   113,     4,
       5,    52,   101,   102,    47,    48,    61,    78,    67,    68,
      62,   119,    63,   165,    14,    40,    28,     2,     3,    58,
      43,    14,    79,    15,    47,    48,    51,    46,    95,     4,
       5,    52,     2,     3,    70,    61,    61,    97,   104,   105,
     106,   107,    49,    50,     4,     5,     6,    88,     4,     5,
       6,    14,    98,    28,    99,     4,     5,     6,   115,   103,
      80,    81,   108,   116,   126,    89,    14,     7,    15,    91,
      92,   133,    93,    38,    39,   137,   109,    14,   139,    28,
      10,    11,    12,    13,   110,   145,    80,    81,     1,   114,
       2,     3,   155,    54,   123,   124,   159,   160,    72,    73,
     -83,   111,     4,     5,     6,   112,     7,    74,    75,     8,
     168,     9,   118,    57,    68,   128,   130,   175,   134,    10,
      11,    12,    13,   140,    14,   141,    15,    47,    48,   146,
     156,    82,    83,    84,    85,    86,    87,   150,   158,    47,
      48,   164,    58,    82,    83,    84,    85,    86,    87,   163,
     166,   172,   170,   153,   120,   173,   129,   161,    60,   162
};

static const yytype_uint8 yycheck[] =
{
      17,     6,    27,    20,     2,     3,   117,    67,    18,    41,
       9,   122,    37,    51,    52,   126,    19,     3,    17,    18,
       5,     6,    27,   134,    34,    41,     9,     5,     6,    46,
      35,    19,    17,    18,    19,    21,    14,    19,    98,    17,
      18,    19,    80,    81,     5,     6,    51,    52,    31,    32,
      39,   111,    41,   164,    39,     0,    41,     5,     6,    20,
      41,    39,    20,    41,     5,     6,    14,    23,    66,    17,
      18,    19,     5,     6,    23,    80,    81,    39,    83,    84,
      85,    86,     7,     8,    17,    18,    19,    22,    17,    18,
      19,    39,    31,    41,    20,    17,    18,    19,   103,     9,
      15,    16,     9,   108,   121,    20,    39,    21,    41,    38,
      39,   128,    41,    17,    18,   132,    21,    39,   135,    41,
      34,    35,    36,    37,    20,   142,    15,    16,     3,    21,
       5,     6,   149,   158,    29,    30,   153,   154,    47,    48,
      31,    31,    17,    18,    19,    33,    21,    49,    50,    24,
     167,    26,    21,   158,    32,    25,    22,   174,    25,    34,
      35,    36,    37,    22,    39,    22,    41,     5,     6,     4,
      23,     9,    10,    11,    12,    13,    14,    27,    19,     5,
       6,    20,    20,     9,    10,    11,    12,    13,    14,    22,
      21,     4,    22,    21,   112,   171,   124,   157,    35,   158
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,    17,    18,    19,    21,    24,    26,
      34,    35,    36,    37,    39,    41,    43,    47,    48,    50,
      54,    61,    75,    78,    79,    80,    82,    19,    41,    82,
      82,    41,    41,    78,    49,    19,    19,     9,    17,    18,
       0,    43,    47,    41,    51,    43,    23,     5,     6,     7,
       8,    14,    19,    72,    75,    76,    77,    78,    20,    47,
      76,    78,    39,    41,    81,    75,     9,    31,    32,    52,
      23,    43,    79,    79,    80,    80,    77,    77,    78,    20,
      15,    16,     9,    10,    11,    12,    13,    14,    22,    20,
      55,    38,    39,    41,    53,    82,    51,    39,    31,    20,
      73,    77,    77,     9,    78,    78,    78,    78,     9,    21,
      20,    31,    33,    51,    21,    78,    78,    74,    21,    51,
      52,    62,    73,    29,    30,    57,    43,    73,    25,    81,
      22,    73,    44,    43,    25,    56,    63,    43,    73,    43,
      22,    22,    58,    64,    45,    43,     4,    66,    71,    46,
      27,    60,     3,    21,    65,    43,    23,    59,    19,    43,
      43,    57,    72,    22,    20,    73,    21,    67,    43,    68,
      22,    69,     4,    71,    70,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    45,    46,    43,    43,
      43,    47,    47,    49,    48,    48,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    55,    56,    54,    58,    59,    57,    57,    57,    60,
      62,    63,    64,    65,    61,    67,    68,    69,    70,    66,
      66,    71,    71,    72,    72,    73,    74,    75,    75,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    79,    80,    80,    80,
      81,    81,    82,    82,    82,    82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     1,     0,     0,     0,    14,     2,
       0,     2,     1,     0,     4,     3,     1,     1,     1,     1,
       3,     4,     3,     3,     2,     5,     1,     3,     4,     1,
       1,     0,     0,    10,     0,     0,     9,     3,     0,     2,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    15,
       1,     4,     0,     1,     1,     0,     0,     3,     1,     3,
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
  case 2: /* StatementList: DeclarationList StatementList  */
#line 104 "prob1.y"
                                  { printf("\n"); }
#line 1449 "y.tab.c"
    break;

  case 3: /* StatementList: Statement SEMICOLON StatementList  */
#line 105 "prob1.y"
                                        { printf("\n"); }
#line 1455 "y.tab.c"
    break;

  case 5: /* $@1: %empty  */
#line 107 "prob1.y"
                                                                        { printf("\n%s\nif %s goto %s:\ngoto %s: \n%s:",(yyvsp[-2].lab) ,(yyvsp[-5].addr), (yyvsp[0].lab), (yyvsp[-1].lab), (yyvsp[0].lab)); }
#line 1461 "y.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 108 "prob1.y"
                          { printf("\ngoto %s:", (yyvsp[-5].lab)); }
#line 1467 "y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 108 "prob1.y"
                                                        { printf("\n%s:", (yyvsp[-5].lab)); }
#line 1473 "y.tab.c"
    break;

  case 8: /* StatementList: WHILE LPAREN ComRelExp RPAREN LCURL begin dummyLabels dummyLabels $@1 StatementList RCURL $@2 $@3 StatementList  */
#line 108 "prob1.y"
                                                                                               { printf("\n"); }
#line 1479 "y.tab.c"
    break;

  case 9: /* StatementList: SwitchStatement StatementList  */
#line 109 "prob1.y"
                                    { printf("\n"); }
#line 1485 "y.tab.c"
    break;

  case 10: /* StatementList: %empty  */
#line 110 "prob1.y"
     {}
#line 1491 "y.tab.c"
    break;

  case 11: /* DeclarationList: Declaration DeclarationList  */
#line 115 "prob1.y"
                                { printf("\n"); }
#line 1497 "y.tab.c"
    break;

  case 12: /* DeclarationList: Declaration  */
#line 116 "prob1.y"
                  {}
#line 1503 "y.tab.c"
    break;

  case 13: /* $@4: %empty  */
#line 120 "prob1.y"
          { /* save state */ symcount_stack[++stackCount] = addrCount; /* set base addr to 0 */ addrCount = 0; }
#line 1509 "y.tab.c"
    break;

  case 14: /* Declaration: LCURL $@4 DeclarationList RCURL  */
#line 120 "prob1.y"
                                                                                                                                       { /* restore state */ addrCount = symcount_stack[stackCount--]; }
#line 1515 "y.tab.c"
    break;

  case 16: /* type: INT  */
#line 125 "prob1.y"
        { 
       strcpy((yyval.addr), "INT"); 
       symtype = (char*)malloc(sizeof(char)*10);
       strcpy(symtype, "INT");
       }
#line 1525 "y.tab.c"
    break;

  case 17: /* type: DOUBLE  */
#line 130 "prob1.y"
             { printf("\n"); 
        strcpy((yyval.addr), "DOUBLE");
        symtype = (char*)malloc(sizeof(char)*10);
        strcpy(symtype, "DOUBLE");
         }
#line 1535 "y.tab.c"
    break;

  case 18: /* type: FLOAT  */
#line 135 "prob1.y"
            { printf("\n"); 
        strcpy((yyval.addr), "FLOAT"); 
        symtype = (char*)malloc(sizeof(char)*10);
        strcpy(symtype, "FLOAT");}
#line 1544 "y.tab.c"
    break;

  case 19: /* type: CHAR  */
#line 139 "prob1.y"
           { printf("\n"); 
        strcpy((yyval.addr), "CHAR"); 
        symtype = (char*)malloc(sizeof(char)*10);
        strcpy(symtype, "CHAR");}
#line 1553 "y.tab.c"
    break;

  case 20: /* variablelist: IDENTIFIER COMMA variablelist  */
#line 145 "prob1.y"
                                              { 
    HandleSymTble((yyvsp[-2].addr), "0" , symtype, &symcount, &addrCount, symtab);
    }
#line 1561 "y.tab.c"
    break;

  case 21: /* variablelist: IDENTIFIER Bracket COMMA variablelist  */
#line 150 "prob1.y"
        {  
        HandleSymTble((yyvsp[-3].addr), "0" , symtype, &symcount, &addrCount, symtab);
        }
#line 1569 "y.tab.c"
    break;

  case 22: /* variablelist: IDENTIFIER EQ NUMBER  */
#line 154 "prob1.y"
      {      
        HandleSymTble((yyvsp[-2].addr), (yyvsp[0].dval), symtype, &symcount, &addrCount, symtab);
      }
#line 1577 "y.tab.c"
    break;

  case 23: /* variablelist: IDENTIFIER EQ CHARCONST  */
#line 159 "prob1.y"
      {
        // printf("\n%s",$3);
         HandleSymTble((yyvsp[-2].addr), (yyvsp[0].cval), symtype, &symcount, &addrCount, symtab);
      }
#line 1586 "y.tab.c"
    break;

  case 24: /* variablelist: IDENTIFIER Bracket  */
#line 164 "prob1.y"
    {
        int i = atoi((yyvsp[0].addr));
        int result = i * addrCount;
        
        HandleSymTble((yyvsp[-1].addr), "0" , symtype, &symcount, &result, symtab);
    }
#line 1597 "y.tab.c"
    break;

  case 25: /* variablelist: IDENTIFIER EQ ConstIden COMMA variablelist  */
#line 171 "prob1.y"
    { printf("\n"); }
#line 1603 "y.tab.c"
    break;

  case 26: /* variablelist: IDENTIFIER  */
#line 173 "prob1.y"
    {
        HandleSymTble((yyvsp[0].addr), "0" , symtype, &symcount, &addrCount, symtab);
    }
#line 1611 "y.tab.c"
    break;

  case 27: /* Bracket: LBRACK NUMBER RBRACK  */
#line 181 "prob1.y"
       {
         char* buf = (char*)malloc(sizeof(char) * 1000);
             int dummyLabels = (yyvsp[-1].dval);
        sprintf(buf, "%d", dummyLabels);
        strcpy((yyval.addr), buf);
      }
#line 1622 "y.tab.c"
    break;

  case 28: /* Bracket: LBRACK NUMBER RBRACK Bracket  */
#line 187 "prob1.y"
                                   { printf("\n"); }
#line 1628 "y.tab.c"
    break;

  case 29: /* ConstIden: Val  */
#line 192 "prob1.y"
{  
    printf("\n");
    strcpy((yyval.addr), (yyvsp[0].addr));
}
#line 1637 "y.tab.c"
    break;

  case 30: /* ConstIden: IDENTIFIER  */
#line 197 "prob1.y"
             { 
    //$$ = (char*)malloc(100 * sizeof(char));
    printf("\n");
    strcpy((yyval.addr), (yyvsp[0].addr));

 }
#line 1648 "y.tab.c"
    break;

  case 31: /* $@5: %empty  */
#line 208 "prob1.y"
                           {count++; stack[count] = (char*)malloc(sizeof(char) * 1000); strcpy(stack[count], (yyvsp[0].addCase)); }
#line 1654 "y.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 209 "prob1.y"
                           {printf("\n%s:" , genOutLabel()); Ocount++ ;count --; }
#line 1660 "y.tab.c"
    break;

  case 33: /* SwitchStatement: SWITCH LPAREN CaseVal $@5 RPAREN LCURL CaseStatements RCURL $@6 StatementList  */
#line 209 "prob1.y"
                                                                                                 { printf("\n"); }
#line 1666 "y.tab.c"
    break;

  case 34: /* $@7: %empty  */
#line 213 "prob1.y"
                                   { printf("\nifFalse (%s == %s) goto %s", stack[count], (yyvsp[-2].addCase), (yyvsp[0].lab));}
#line 1672 "y.tab.c"
    break;

  case 35: /* $@8: %empty  */
#line 214 "prob1.y"
                             { printf("\n%s:",(yyvsp[-3].lab));}
#line 1678 "y.tab.c"
    break;

  case 37: /* CaseStatements: DEFAULT COLON StatementList  */
#line 215 "prob1.y"
                                  { printf("\n"); }
#line 1684 "y.tab.c"
    break;

  case 38: /* CaseStatements: %empty  */
#line 216 "prob1.y"
      {}
#line 1690 "y.tab.c"
    break;

  case 39: /* BreakStmt: BREAK SEMICOLON  */
#line 220 "prob1.y"
                    { printf("goto %s\n", OutLabel(Ocount)); }
#line 1696 "y.tab.c"
    break;

  case 40: /* $@9: %empty  */
#line 223 "prob1.y"
                                              { printf("\nifFalse %s goto %s ", (yyvsp[-3].addr), (yyvsp[-1].lab)); }
#line 1702 "y.tab.c"
    break;

  case 41: /* $@10: %empty  */
#line 224 "prob1.y"
                              { locationforIfelse = (char*)malloc(100 * sizeof(char));   ;strcpy(locationforIfelse, (yyvsp[0].lab)); 
     printf("\ngoto %s :", (yyvsp[0].lab)); }
#line 1709 "y.tab.c"
    break;

  case 42: /* $@11: %empty  */
#line 225 "prob1.y"
                                       { printf("\n%s:", (yyvsp[-6].lab)); }
#line 1715 "y.tab.c"
    break;

  case 43: /* $@12: %empty  */
#line 225 "prob1.y"
                                                                                { printf("\n%s:", (yyvsp[-4].lab));}
#line 1721 "y.tab.c"
    break;

  case 44: /* IfStatement: IF LPAREN CmpStm RPAREN dummyLabels LCURL $@9 StatementList dummyLabels $@10 RCURL $@11 ElseIfStatement $@12 StatementList  */
#line 225 "prob1.y"
                                                                                                                       {printf("\n");}
#line 1727 "y.tab.c"
    break;

  case 45: /* $@13: %empty  */
#line 230 "prob1.y"
                                                   { printf("\nifFalse %s goto %s ", (yyvsp[-3].addr), (yyvsp[-1].lab)); }
#line 1733 "y.tab.c"
    break;

  case 46: /* $@14: %empty  */
#line 231 "prob1.y"
                   { printf("\ngoto %s :", locationforIfelse); }
#line 1739 "y.tab.c"
    break;

  case 47: /* $@15: %empty  */
#line 231 "prob1.y"
                                                                      { printf("\n%s:", (yyvsp[-5].lab)); }
#line 1745 "y.tab.c"
    break;

  case 48: /* $@16: %empty  */
#line 231 "prob1.y"
                                                                                                        { printf("\n%s:", locationforIfelse);}
#line 1751 "y.tab.c"
    break;

  case 49: /* ElseIfStatement: ELSE IF LPAREN CmpStm RPAREN dummyLabels LCURL $@13 StatementList $@14 RCURL $@15 ElseStmt $@16 StatementList  */
#line 231 "prob1.y"
                                                                                                                                                              {printf("\n");}
#line 1757 "y.tab.c"
    break;

  case 50: /* ElseIfStatement: ElseStmt  */
#line 232 "prob1.y"
                { printf("\n"); }
#line 1763 "y.tab.c"
    break;

  case 51: /* ElseStmt: ELSE LCURL StatementList RCURL  */
#line 235 "prob1.y"
                                   {}
#line 1769 "y.tab.c"
    break;

  case 52: /* ElseStmt: %empty  */
#line 236 "prob1.y"
      {}
#line 1775 "y.tab.c"
    break;

  case 55: /* dummyLabels: %empty  */
#line 243 "prob1.y"
    { (yyval.lab) = (char*)malloc(100 * sizeof(char)); (yyval.lab) = genBlockLabel(); }
#line 1781 "y.tab.c"
    break;

  case 56: /* begin: %empty  */
#line 246 "prob1.y"
    { (yyval.lab) = (char*)malloc(100 * sizeof(char)); (yyval.lab) = genBeginLabel(); }
#line 1787 "y.tab.c"
    break;

  case 57: /* Statement: IDENTIFIER EQ Statement  */
#line 250 "prob1.y"
                            {
        verify((yyvsp[-2].addr));
        strcpy((yyval.addr), (yyvsp[-2].addr));
        strcat((yyval.addr), "=");
        strcat((yyval.addr), (yyvsp[0].addr));
        printf("\n%s", (yyval.addr));
    }
#line 1799 "y.tab.c"
    break;

  case 58: /* Statement: Term  */
#line 258 "prob1.y"
         { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1805 "y.tab.c"
    break;

  case 59: /* ComRelExp: ComRelExp AND Relexp  */
#line 262 "prob1.y"
                         {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "&&");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1819 "y.tab.c"
    break;

  case 60: /* ComRelExp: ComRelExp OR Relexp  */
#line 271 "prob1.y"
                          {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "||");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1833 "y.tab.c"
    break;

  case 61: /* ComRelExp: Relexp  */
#line 280 "prob1.y"
             { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1839 "y.tab.c"
    break;

  case 62: /* Relexp: Term LT Term  */
#line 284 "prob1.y"
                 {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "<");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1853 "y.tab.c"
    break;

  case 63: /* Relexp: Term LTE Term  */
#line 293 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "<=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1867 "y.tab.c"
    break;

  case 64: /* Relexp: Term GT Term  */
#line 302 "prob1.y"
                   {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, ">");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1881 "y.tab.c"
    break;

  case 65: /* Relexp: Term GTE Term  */
#line 311 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, ">=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1895 "y.tab.c"
    break;

  case 66: /* Relexp: Term EQ EQ Term  */
#line 320 "prob1.y"
                      {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-3].addr));
        strcat(str, "==");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1909 "y.tab.c"
    break;

  case 67: /* Relexp: Term NOT EQ Term  */
#line 329 "prob1.y"
                       {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-3].addr));
        strcat(str, "!=");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1923 "y.tab.c"
    break;

  case 68: /* Relexp: LPAREN Relexp RPAREN  */
#line 338 "prob1.y"
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
#line 1938 "y.tab.c"
    break;

  case 69: /* Relexp: NOT Relexp  */
#line 348 "prob1.y"
                 {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, "!");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1951 "y.tab.c"
    break;

  case 70: /* Relexp: %empty  */
#line 356 "prob1.y"
      {}
#line 1957 "y.tab.c"
    break;

  case 71: /* Term: Term ADD Factor  */
#line 360 "prob1.y"
                    {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "+");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1971 "y.tab.c"
    break;

  case 72: /* Term: Term SUB Factor  */
#line 369 "prob1.y"
                      {
        strcpy((yyval.addr), genLabel());
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-2].addr));
        strcat(str, "-");
        strcat(str, (yyvsp[0].addr));
        printf("\n%s", str);
    }
#line 1985 "y.tab.c"
    break;

  case 73: /* Term: Factor  */
#line 378 "prob1.y"
             { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 1991 "y.tab.c"
    break;

  case 74: /* Factor: Factor MUL SIGNVal  */
#line 382 "prob1.y"
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
#line 2006 "y.tab.c"
    break;

  case 75: /* Factor: Factor DIV SIGNVal  */
#line 392 "prob1.y"
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
#line 2021 "y.tab.c"
    break;

  case 76: /* Factor: SIGNVal  */
#line 402 "prob1.y"
              { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 2027 "y.tab.c"
    break;

  case 77: /* SIGNVal: ADD Val  */
#line 406 "prob1.y"
            {
        strcpy((yyval.addr), "+");
        strcat((yyval.addr), (yyvsp[0].addr));
    }
#line 2036 "y.tab.c"
    break;

  case 78: /* SIGNVal: SUB Val  */
#line 410 "prob1.y"
              {
        strcpy((yyval.addr), "-");
        strcat((yyval.addr), (yyvsp[0].addr));
    }
#line 2045 "y.tab.c"
    break;

  case 79: /* SIGNVal: Val  */
#line 414 "prob1.y"
          { strcpy((yyval.addr), (yyvsp[0].addr)); }
#line 2051 "y.tab.c"
    break;

  case 80: /* CaseVal: IDENTIFIER  */
#line 419 "prob1.y"
                {
        verify((yyvsp[0].addr));
        strcpy((yyval.addCase), (yyvsp[0].addr));
    }
#line 2060 "y.tab.c"
    break;

  case 81: /* CaseVal: NUMBER  */
#line 423 "prob1.y"
                {
        char* buf = (char*)malloc(sizeof(char) * 1000);
        int dummyLabels = (yyvsp[0].dval);
        sprintf(buf, "%d", dummyLabels);
        strcpy((yyval.addCase), buf);
    }
#line 2071 "y.tab.c"
    break;

  case 82: /* Val: IDENTIFIER  */
#line 432 "prob1.y"
               {
        verify((yyvsp[0].addr));
        strcpy((yyval.addr), (yyvsp[0].addr));
    }
#line 2080 "y.tab.c"
    break;

  case 83: /* Val: NUMBER  */
#line 436 "prob1.y"
             {
        char* buf = (char*)malloc(sizeof(char) * 1000);
        int dummyLabels = (yyvsp[0].dval);
        sprintf(buf, "%d", dummyLabels);
        strcpy((yyval.addr), buf);
    }
#line 2091 "y.tab.c"
    break;

  case 84: /* Val: PADD IDENTIFIER  */
#line 442 "prob1.y"
                      {
        verify((yyvsp[0].addr));
        strcpy((yyval.addr), (yyvsp[0].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[0].addr));
        strcat(str, "+1");
        printf("\n%s", str);
    }
#line 2105 "y.tab.c"
    break;

  case 85: /* Val: PSUB IDENTIFIER  */
#line 451 "prob1.y"
                      {
        verify((yyvsp[0].addr));
        strcpy((yyval.addr), (yyvsp[0].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[0].addr));
        strcat(str, "-1");
        printf("\n%s", str);
    }
#line 2119 "y.tab.c"
    break;

  case 86: /* Val: IDENTIFIER PADD  */
#line 460 "prob1.y"
                      {
        verify((yyvsp[-1].addr));
        strcpy((yyval.addr), (yyvsp[-1].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-1].addr));
        strcat(str, "+1");
        printf("\n%s", str);
    }
#line 2133 "y.tab.c"
    break;

  case 87: /* Val: IDENTIFIER PSUB  */
#line 469 "prob1.y"
                      {
        verify((yyvsp[-1].addr));
        strcpy((yyval.addr), (yyvsp[-1].addr));
        strcpy(str, (yyval.addr));
        strcat(str, "=");
        strcat(str, (yyvsp[-1].addr));
        strcat(str, "-1");
        printf("\n%s", str);
    }
#line 2147 "y.tab.c"
    break;

  case 88: /* Val: LPAREN Term RPAREN  */
#line 478 "prob1.y"
                         { strcpy((yyval.addr), (yyvsp[-1].addr)); }
#line 2153 "y.tab.c"
    break;


#line 2157 "y.tab.c"

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

#line 481 "prob1.y"


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

void verify (char *id )
{
    int i;
    for (i = 0; i < symcount; i++) {
        if (strcmp(symtab[i]->name, id) == 0) {
            return;
        }
    }
    printf("Error: Symbol %s not found\n", id);
    exit(1);
}

void HandleSymTble(char* identifier, char* number, char* symtype, int* symcount, int* addrCount, Symbol** symtab) {
    // Check if the identifier is already present in the symbol table
    if (*symcount > 1) {
        int i;
        for (i = 0; i < *symcount; i++) {
            if (strcmp(symtab[i]->name, identifier) == 0) {
                if (strcmp(symtab[i]->type, symtype) != 0) {
                    printf("Error: Symbol %s already defined with conflicting type\n", identifier);
                    exit(1);
                }
                printf("Error: Symbol %s already defined\n", identifier);
                exit(1);
            }
        }
    }

    char addrStr[10];
    sprintf(addrStr, "%X", *addrCount);

    if (strcmp(symtype,"INT") ==0) {
        add_symbol(identifier, "INT", number, addrStr);
        *addrCount = *addrCount + 4;
    }
    else if (strcmp (symtype,"DOUBLE") ==0) {
        add_symbol(identifier, "DOUBLE", number, addrStr );
        *addrCount = *addrCount + 8;
    }
    else if (strcmp (symtype ,"FLOAT") ==0) {
        add_symbol(identifier, "FLOAT", number, addrStr);
        *addrCount = *addrCount + 4;
    }
    else if (strcmp (symtype ,"CHAR") ==0) {
        add_symbol(identifier, "CHAR", number, addrStr);
        *addrCount = *addrCount + 1;

            if (strlen(number) != 3 || number[0] != '\'' || number[2] != '\'') {
            printf("Error: Invalid char constant %s\n", number);
            exit(1);
        }
        add_symbol(identifier, "CHAR", number, addrStr);
        *addrCount = *addrCount + 1;
    }
    else {
        printf("Error: Symbol %s not found\n", identifier);
        exit(1);
    }
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
    free(label);
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
    free(label);
    return s;
}

void add_symbol(char* name, char* type, int val, char* addr) {
    if (symcount >= 10000) {
        fprintf(stderr, "Error: Symbol table is full\n");
        exit(EXIT_FAILURE);
    }

    Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
    if (sym == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for Symbol\n");
        exit(EXIT_FAILURE);
    }

    sym->name = strdup(name);
    if (sym->name == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for name\n");
        exit(EXIT_FAILURE);
    }

    sym->type = strdup(type);
    if (sym->type == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for type\n");
        exit(EXIT_FAILURE);
    }

    sym->val.intval = val;
    strncpy(sym->addr, addr, sizeof(sym->addr) - 1);
    sym->addr[sizeof(sym->addr) - 1] = '\0'; // Ensure null-termination

    symtab[symcount++] = sym;

    printf("Added symbol: name=%s, type=%s, val=%d, addr=%s\n", sym->name, sym->type, sym->val.intval, sym->addr);
}


int main(int argc, char* argv[]) {
    t =0;
    l = 0;
    w = 0;
    z = 0 ;
    count = 1;
    Ocount = 0;
    
    if (argc > 1) {
        FILE* fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
    }
    yyparse();
    return 0;
}
