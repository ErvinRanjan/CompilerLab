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

#ifndef YY_YY_MNT_C_USERS_ERVIN_CODING_COMPILERLAB_SRC_Y_TAB_H_INCLUDED
# define YY_YY_MNT_C_USERS_ERVIN_CODING_COMPILERLAB_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    NUM = 258,                     /* NUM  */
    ID = 259,                      /* ID  */
    BLOCK_BEGIN = 260,             /* BLOCK_BEGIN  */
    BLOCK_END = 261,               /* BLOCK_END  */
    READ = 262,                    /* READ  */
    WRITE = 263,                   /* WRITE  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    ELSE = 266,                    /* ELSE  */
    ENDIF = 267,                   /* ENDIF  */
    WHILE = 268,                   /* WHILE  */
    DO = 269,                      /* DO  */
    ENDWHILE = 270,                /* ENDWHILE  */
    GE = 271,                      /* GE  */
    LE = 272,                      /* LE  */
    NE = 273,                      /* NE  */
    EQ = 274,                      /* EQ  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    DECL = 277,                    /* DECL  */
    ENDDECL = 278,                 /* ENDDECL  */
    INT = 279,                     /* INT  */
    STR = 280,                     /* STR  */
    CSTR = 281,                    /* CSTR  */
    REPEAT = 282,                  /* REPEAT  */
    UNTIL = 283,                   /* UNTIL  */
    MAIN = 284,                    /* MAIN  */
    RETURN = 285,                  /* RETURN  */
    TYPEDECL = 286,                /* TYPEDECL  */
    ENDTYPEDECL = 287,             /* ENDTYPEDECL  */
    TUPLE = 288,                   /* TUPLE  */
    STRUCT = 289,                  /* STRUCT  */
    INITIALISE = 290,              /* INITIALISE  */
    FREE = 291,                    /* FREE  */
    ALLOC = 292,                   /* ALLOC  */
    ARROW = 293                    /* ARROW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define ID 259
#define BLOCK_BEGIN 260
#define BLOCK_END 261
#define READ 262
#define WRITE 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define GE 271
#define LE 272
#define NE 273
#define EQ 274
#define BREAK 275
#define CONTINUE 276
#define DECL 277
#define ENDDECL 278
#define INT 279
#define STR 280
#define CSTR 281
#define REPEAT 282
#define UNTIL 283
#define MAIN 284
#define RETURN 285
#define TYPEDECL 286
#define ENDTYPEDECL 287
#define TUPLE 288
#define STRUCT 289
#define INITIALISE 290
#define FREE 291
#define ALLOC 292
#define ARROW 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"

    struct tNode* node;

#line 147 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MNT_C_USERS_ERVIN_CODING_COMPILERLAB_SRC_Y_TAB_H_INCLUDED  */
