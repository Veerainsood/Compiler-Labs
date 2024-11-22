/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 143 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
