#ifndef _yy_defines_h_
#define _yy_defines_h_

#define SEMICOLON 257
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define ASSIGN 262
#define LEFT_PAREN 263
#define RIGHT_PAREN 264
#define INC 265
#define DEC 266
#define IDENTIFIER 267
#define INT_CONST 268
#define FLOAT_CONST 269
#define UMINUS 270
#define UPLUS 271
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int dval;
    float fval;
    char lexeme[100];
    struct node *node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
