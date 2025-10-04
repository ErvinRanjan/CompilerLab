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
#line 1 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"

    #include "tree.h"
    #include "codegen.h"
    #include "constants.h"
    #include "symbol.h"
    #include "type.h"
    #include "label.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include "typeTable.h"
    #include "param.h"
    extern FILE* yyin;
    extern char* yytext;
    FILE* out;
    struct symbol* gsymbolTable = NULL;
    extern int lines;

#line 89 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_BLOCK_BEGIN = 5,                /* BLOCK_BEGIN  */
  YYSYMBOL_BLOCK_END = 6,                  /* BLOCK_END  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_ENDIF = 12,                     /* ENDIF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_ENDWHILE = 15,                  /* ENDWHILE  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 21,                  /* CONTINUE  */
  YYSYMBOL_DECL = 22,                      /* DECL  */
  YYSYMBOL_ENDDECL = 23,                   /* ENDDECL  */
  YYSYMBOL_INT = 24,                       /* INT  */
  YYSYMBOL_STR = 25,                       /* STR  */
  YYSYMBOL_CSTR = 26,                      /* CSTR  */
  YYSYMBOL_REPEAT = 27,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 28,                     /* UNTIL  */
  YYSYMBOL_MAIN = 29,                      /* MAIN  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_TYPEDECL = 31,                  /* TYPEDECL  */
  YYSYMBOL_ENDTYPEDECL = 32,               /* ENDTYPEDECL  */
  YYSYMBOL_TUPLE = 33,                     /* TUPLE  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '%'  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '>'  */
  YYSYMBOL_48_ = 48,                       /* '&'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_Program = 53,                   /* Program  */
  YYSYMBOL_TypeDeclBlock = 54,             /* TypeDeclBlock  */
  YYSYMBOL_TypeDeclList = 55,              /* TypeDeclList  */
  YYSYMBOL_TypeDecl = 56,                  /* TypeDecl  */
  YYSYMBOL_PartialTypeDecl = 57,           /* PartialTypeDecl  */
  YYSYMBOL_MainBlock = 58,                 /* MainBlock  */
  YYSYMBOL_Body = 59,                      /* Body  */
  YYSYMBOL_GDeclBlock = 60,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 61,                 /* GDeclList  */
  YYSYMBOL_GDecl = 62,                     /* GDecl  */
  YYSYMBOL_Type = 63,                      /* Type  */
  YYSYMBOL_GidList = 64,                   /* GidList  */
  YYSYMBOL_Gid = 65,                       /* Gid  */
  YYSYMBOL_ParamList = 66,                 /* ParamList  */
  YYSYMBOL_Param = 67,                     /* Param  */
  YYSYMBOL_Pid = 68,                       /* Pid  */
  YYSYMBOL_LDeclBlock = 69,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 70,                 /* LDeclList  */
  YYSYMBOL_LDecl = 71,                     /* LDecl  */
  YYSYMBOL_LidList = 72,                   /* LidList  */
  YYSYMBOL_Lid = 73,                       /* Lid  */
  YYSYMBOL_FDefBlock = 74,                 /* FDefBlock  */
  YYSYMBOL_FDef = 75,                      /* FDef  */
  YYSYMBOL_Slist = 76,                     /* Slist  */
  YYSYMBOL_Stmt = 77,                      /* Stmt  */
  YYSYMBOL_RetStmt = 78,                   /* RetStmt  */
  YYSYMBOL_Ifstmt = 79,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 80,                 /* Whilestmt  */
  YYSYMBOL_InputStmt = 81,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 82,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 83,                   /* AsgStmt  */
  YYSYMBOL_BreakStmt = 84,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 85,              /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 86,           /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 87,               /* DoWhileStmt  */
  YYSYMBOL_B = 88,                         /* B  */
  YYSYMBOL_E = 89,                         /* E  */
  YYSYMBOL_ArgList = 90,                   /* ArgList  */
  YYSYMBOL_DeclArray = 91,                 /* DeclArray  */
  YYSYMBOL_DeclBraceList = 92,             /* DeclBraceList  */
  YYSYMBOL_Array = 93,                     /* Array  */
  YYSYMBOL_BraceList = 94,                 /* BraceList  */
  YYSYMBOL_Identifier = 95                 /* Identifier  */
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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   433

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,     2,     2,     2,     2,    35,    48,     2,
      40,    41,    38,    36,    45,    37,    51,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      46,    34,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    34,    35,    36,    37,    38,    41,    42,
      45,    46,    49,    56,    62,    74,    78,    83,    88,    91,
      94,    99,   104,   105,   109,   121,   124,   129,   130,   134,
     139,   144,   150,   153,   158,   164,   167,   174,   177,   180,
     183,   188,   193,   196,   201,   202,   206,   212,   213,   217,
     229,   242,   246,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   265,   271,   275,   282,   288,   294,   300,   306,
     307,   313,   319,   325,   328,   331,   334,   337,   340,   345,
     348,   351,   354,   357,   360,   363,   366,   369,   372,   373,
     374,   380,   383,   388,   394,   397,   402,   407,   410,   415,
     416,   420,   423
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID",
  "BLOCK_BEGIN", "BLOCK_END", "READ", "WRITE", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "GE", "LE", "NE", "EQ", "BREAK",
  "CONTINUE", "DECL", "ENDDECL", "INT", "STR", "CSTR", "REPEAT", "UNTIL",
  "MAIN", "RETURN", "TYPEDECL", "ENDTYPEDECL", "TUPLE", "'='", "'%'",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "';'", "'{'", "'}'", "','",
  "'<'", "'>'", "'&'", "'['", "']'", "'.'", "$accept", "Program",
  "TypeDeclBlock", "TypeDeclList", "TypeDecl", "PartialTypeDecl",
  "MainBlock", "Body", "GDeclBlock", "GDeclList", "GDecl", "Type",
  "GidList", "Gid", "ParamList", "Param", "Pid", "LDeclBlock", "LDeclList",
  "LDecl", "LidList", "Lid", "FDefBlock", "FDef", "Slist", "Stmt",
  "RetStmt", "Ifstmt", "Whilestmt", "InputStmt", "OutputStmt", "AsgStmt",
  "BreakStmt", "ContinueStmt", "RepeatUntilStmt", "DoWhileStmt", "B", "E",
  "ArgList", "DeclArray", "DeclBraceList", "Array", "BraceList",
  "Identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     140,    66,    22,   150,    36,   136,  -135,    93,  -135,  -135,
    -135,  -135,    75,  -135,     7,    45,  -135,   106,   100,   130,
     112,  -135,  -135,    93,    22,  -135,    21,    93,  -135,  -135,
    -135,   126,     7,    39,  -135,  -135,   124,  -135,  -135,  -135,
     103,  -135,    93,  -135,    21,   148,  -135,  -135,     6,   167,
     153,  -135,  -135,     7,   146,    21,    24,  -135,  -135,  -135,
      16,  -135,    42,   149,   201,  -135,   186,  -135,   172,   103,
     175,    70,  -135,  -135,   169,    97,   210,  -135,  -135,   186,
     177,  -135,  -135,    29,   119,  -135,   203,   184,   210,   186,
     193,    29,    89,  -135,  -135,  -135,  -135,  -135,   141,  -135,
     206,   207,   217,   221,   347,   208,   220,  -135,   347,    40,
      40,   264,   218,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,   365,  -135,   244,  -135,   235,   210,  -135,
    -135,    29,    20,    40,   231,    40,    40,    40,    40,   385,
    -135,  -135,   256,   230,  -135,   110,  -135,    40,  -135,   279,
      40,    40,    40,    40,    40,   284,    40,  -135,   255,  -135,
    -135,   365,   139,   236,    40,   259,   254,   265,    57,   269,
     271,   272,  -135,   198,  -135,   216,    86,    86,   230,   230,
    -135,   287,  -135,  -135,    40,  -135,   327,   274,   275,   303,
      40,    40,    40,    40,    40,    40,   304,    40,    40,  -135,
    -135,   365,  -135,  -135,  -135,   347,   365,   365,   365,   365,
     365,   365,   347,   278,   286,   165,   294,    -8,   288,   347,
     289,   291,  -135,  -135,   332,  -135,  -135,   295,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     7,     0,    24,    18,
      22,    23,     0,    20,     0,     0,     8,     0,     0,    11,
       0,     1,     4,     0,    22,     6,     0,     0,    48,    17,
      19,    27,     0,     0,    26,    28,     0,    13,     9,    10,
       0,     3,     0,    35,     0,     0,     5,    47,     0,     0,
      93,    31,    21,     0,     0,     0,     0,    33,     2,    36,
       0,    30,     0,     0,     0,    25,     0,    34,     0,     0,
       0,     0,    29,    95,     0,     0,     0,    12,    32,     0,
       0,    94,    38,     0,     0,    40,     0,     0,     0,     0,
      44,     0,     0,    43,    45,    37,    39,    88,    99,    16,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,    52,    56,    57,    53,    54,    55,    58,
      59,    60,    61,     0,   100,    89,    14,     0,     0,    46,
      41,     0,     0,     0,    96,     0,     0,     0,     0,     0,
      69,    70,     0,   101,    89,     0,    84,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,    42,
      86,    92,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,    85,     0,    15,    83,    79,    81,    80,    82,
     102,     0,    49,    87,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      68,    91,    97,    66,    67,     0,    75,    76,    77,    78,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    71,     0,    64,    65,     0,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   309,  -135,  -135,    12,   -80,   338,  -135,
     335,     2,  -135,   -16,   -39,   280,   -17,    -7,  -135,   273,
    -135,   -79,   325,   -14,  -103,  -110,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -134,     3,  -135,   -76,
    -135,  -135,  -135,   -86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    18,    19,    20,     6,    87,     7,    12,
      13,    26,    33,    34,    56,    57,    45,    76,    84,    85,
      92,    93,    27,    28,   112,   113,   149,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   167,   123,   162,    35,
      50,   124,   134,   144
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     125,   139,   148,    14,   169,   142,   212,    94,   127,    62,
       8,    31,   129,    47,    14,    94,    51,    22,   125,    25,
       8,    71,   125,    97,    98,    43,   125,    59,    47,   148,
      10,    11,   148,    90,   222,    41,    21,    65,    67,    46,
      10,    11,    55,    97,    98,    32,   107,    61,   158,   165,
      55,    15,   159,   125,    58,    94,   125,    70,   109,    44,
     110,   160,    55,   213,   214,    68,   107,    91,   111,    69,
       8,    55,    88,   190,   191,   192,   193,    83,   109,     8,
     110,    52,   128,    72,    53,    36,    83,    69,   111,     9,
      10,    11,   150,   151,   152,   153,   154,     8,    29,    10,
      11,     8,   215,   194,   195,   148,   148,     8,   155,   216,
      37,    80,   143,   145,   148,    69,   224,    24,    11,   125,
      82,    10,    11,     8,   153,   154,   125,    10,    11,   125,
     125,   130,    38,   125,   131,   161,   163,   155,   125,   166,
     168,   168,    95,    10,    11,   150,   151,   152,   153,   154,
     173,   172,    40,   175,   176,   177,   178,   179,     1,   181,
       2,   155,     1,    17,     2,    54,    48,   186,    97,    98,
      63,     3,   100,   101,   102,    49,   219,   220,   103,   104,
     183,   132,    16,    17,   184,   105,   106,   201,    60,    66,
     133,   107,   108,   206,   207,   208,   209,   210,   211,    73,
     168,   168,    64,   109,    74,   110,    97,    98,    75,    99,
     100,   101,   102,   111,    77,    86,   103,   104,    79,    81,
      89,    97,    98,   105,   106,   100,   101,   102,   126,   107,
     108,   103,   104,   150,   151,   152,   153,   154,   105,   106,
     199,   109,    49,   110,   107,   108,   135,   136,   147,   155,
     140,   111,   151,   152,   153,   154,   109,   137,   110,    97,
      98,   138,   141,   100,   101,   102,   111,   155,   146,   103,
     104,   150,   151,   152,   153,   154,   105,   106,   156,   157,
     164,   155,   107,   108,   171,   174,   185,   155,   180,   150,
     151,   152,   153,   154,   109,   188,   110,    97,    98,   182,
     187,   100,   101,   102,   111,   155,   189,   103,   104,   221,
     196,   197,   198,   205,   105,   106,   203,   204,   212,   217,
     107,   108,   150,   151,   152,   153,   154,   218,    39,   200,
     223,   225,   109,   226,   110,    97,    98,   228,   155,   100,
     101,   102,   111,    23,   227,   103,   104,    30,    42,    78,
      97,    98,   105,   106,   100,   101,   102,    96,   107,   108,
     103,   104,   150,   151,   152,   153,   154,   105,   106,     0,
     109,     0,   110,   107,   108,     0,     0,   202,   155,     0,
     111,     0,     0,     0,     0,   109,     0,   110,    97,    98,
       0,     0,   100,   101,   102,   111,     0,     0,   170,   104,
     150,   151,   152,   153,   154,   105,   106,     0,     0,     0,
       0,   107,   108,     0,     0,     0,   155,     0,     0,     0,
       0,     0,     0,   109,     0,   110,     0,     0,     0,     0,
       0,     0,     0,   111
};

static const yytype_int16 yycheck[] =
{
      86,   104,   112,     1,   138,   108,    14,    83,    88,    48,
       4,     4,    91,    27,    12,    91,    32,     5,   104,     7,
       4,    60,   108,     3,     4,     4,   112,    44,    42,   139,
      24,    25,   142,     4,    42,    23,     0,    53,    55,    27,
      24,    25,    40,     3,     4,    38,    26,    41,   128,   135,
      48,    29,   131,   139,    42,   131,   142,    41,    38,    38,
      40,    41,    60,   197,   198,    41,    26,    38,    48,    45,
       4,    69,    79,    16,    17,    18,    19,    75,    38,     4,
      40,    42,    89,    41,    45,    40,    84,    45,    48,    23,
      24,    25,    35,    36,    37,    38,    39,     4,    23,    24,
      25,     4,   205,    46,    47,   215,   216,     4,    51,   212,
       4,    41,   109,   110,   224,    45,   219,    24,    25,   205,
      23,    24,    25,     4,    38,    39,   212,    24,    25,   215,
     216,    42,    32,   219,    45,   132,   133,    51,   224,   136,
     137,   138,    23,    24,    25,    35,    36,    37,    38,    39,
     147,    41,    40,   150,   151,   152,   153,   154,    22,   156,
      24,    51,    22,    33,    24,    41,    40,   164,     3,     4,
       3,    31,     7,     8,     9,    49,    11,    12,    13,    14,
      41,    40,    32,    33,    45,    20,    21,   184,    40,    43,
      49,    26,    27,   190,   191,   192,   193,   194,   195,    50,
     197,   198,    49,    38,     3,    40,     3,     4,    22,     6,
       7,     8,     9,    48,    42,     5,    13,    14,    43,    50,
      43,     3,     4,    20,    21,     7,     8,     9,    44,    26,
      27,    13,    14,    35,    36,    37,    38,    39,    20,    21,
      42,    38,    49,    40,    26,    27,    40,    40,    30,    51,
      42,    48,    36,    37,    38,    39,    38,    40,    40,     3,
       4,    40,    42,     7,     8,     9,    48,    51,     4,    13,
      14,    35,    36,    37,    38,    39,    20,    21,    34,    44,
      49,    51,    26,    27,    28,     6,    50,    51,     4,    35,
      36,    37,    38,    39,    38,    41,    40,     3,     4,    44,
      41,     7,     8,     9,    48,    51,    41,    13,    14,    15,
      41,    40,    40,    10,    20,    21,    42,    42,    14,    41,
      26,    27,    35,    36,    37,    38,    39,    41,    19,    42,
      42,    42,    38,    42,    40,     3,     4,    42,    51,     7,
       8,     9,    48,     5,    12,    13,    14,    12,    23,    69,
       3,     4,    20,    21,     7,     8,     9,    84,    26,    27,
      13,    14,    35,    36,    37,    38,    39,    20,    21,    -1,
      38,    -1,    40,    26,    27,    -1,    -1,    50,    51,    -1,
      48,    -1,    -1,    -1,    -1,    38,    -1,    40,     3,     4,
      -1,    -1,     7,     8,     9,    48,    -1,    -1,    13,    14,
      35,    36,    37,    38,    39,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    24,    31,    53,    54,    58,    60,     4,    23,
      24,    25,    61,    62,    63,    29,    32,    33,    55,    56,
      57,     0,    58,    60,    24,    58,    63,    74,    75,    23,
      62,     4,    38,    64,    65,    91,    40,     4,    32,    55,
      40,    58,    74,     4,    38,    68,    58,    75,    40,    49,
      92,    65,    42,    45,    41,    63,    66,    67,    58,    68,
      40,    41,    66,     3,    49,    65,    43,    68,    41,    45,
      41,    66,    41,    50,     3,    22,    69,    42,    67,    43,
      41,    50,    23,    63,    70,    71,     5,    59,    69,    43,
       4,    38,    72,    73,    91,    23,    71,     3,     4,     6,
       7,     8,     9,    13,    14,    20,    21,    26,    27,    38,
      40,    48,    76,    77,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    89,    93,    95,    44,    59,    69,    73,
      42,    45,    40,    49,    94,    40,    40,    40,    40,    76,
      42,    42,    76,    89,    95,    89,     4,    30,    77,    78,
      35,    36,    37,    38,    39,    51,    34,    44,    59,    73,
      41,    89,    90,    89,    49,    95,    89,    88,    89,    88,
      13,    28,    41,    89,     6,    89,    89,    89,    89,    89,
       4,    89,    44,    41,    45,    50,    89,    41,    41,    41,
      16,    17,    18,    19,    46,    47,    41,    40,    40,    42,
      42,    89,    50,    42,    42,    10,    89,    89,    89,    89,
      89,    89,    14,    88,    88,    76,    76,    41,    41,    11,
      12,    15,    42,    42,    76,    42,    42,    12,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    56,    57,    58,    59,    59,    60,    60,    61,
      61,    62,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    66,    66,    67,    68,    68,    69,    69,    70,
      70,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    79,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    88,    88,    88,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    92,    92,    93,    94,    94,    95,
      95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     1,     2,     3,
       2,     1,     5,     2,     8,     4,     2,     3,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       3,     2,     3,     1,     2,     1,     2,     3,     2,     2,
       1,     3,     3,     1,     1,     1,     2,     2,     1,     9,
       8,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,    10,     8,     8,     5,     5,     4,     2,
       2,     7,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     4,     1,     1,
       1,     3,     1,     2,     4,     3,     2,     4,     3,     1,
       1,     2,     3
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
  case 8: /* TypeDeclBlock: TYPEDECL ENDTYPEDECL  */
#line 41 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                     {}
#line 1363 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 9: /* TypeDeclBlock: TYPEDECL TypeDeclList ENDTYPEDECL  */
#line 42 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                  {}
#line 1369 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 10: /* TypeDeclList: TypeDecl TypeDeclList  */
#line 45 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                     {}
#line 1375 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 11: /* TypeDeclList: TypeDecl  */
#line 46 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {}
#line 1381 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 12: /* TypeDecl: PartialTypeDecl '(' ParamList ')' ';'  */
#line 49 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {
                int numberOfParam = 0;
                updateTypeTable((yyvsp[-4].node)->varName,convertTreeToParamList((yyvsp[-2].node),&numberOfParam,NULL));
                printTypeTable();
            }
#line 1391 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 13: /* PartialTypeDecl: TUPLE ID  */
#line 56 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                        populateTypeTable((yyvsp[0].node)->varName,NULL);
                        (yyval.node) = (yyvsp[0].node);
                }
#line 1400 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 14: /* MainBlock: INT MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 62 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                      { 
                                                            struct symbol* symbolTable = NULL;
                                                            symbolTable = populateSymbolTable((yyvsp[-2].node),symbolTable,0);
                                                            printSymbolTable("main",symbolTable);
                                                            symbolTable = appendSymbolTable(symbolTable,gsymbolTable);
                                                            typeCheck((yyvsp[-1].node),symbolTable);
                                                            fprintf(out,"L0:\n"); 
                                                            populateParent((yyvsp[-1].node));
                                                            codeGen(out,(yyvsp[-1].node),symbolTable);
                                                        }
#line 1415 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* Body: BLOCK_BEGIN Slist RetStmt BLOCK_END  */
#line 74 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {
                               (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                               (yyval.node)->label = (yyvsp[-2].node)->label;
                           }
#line 1424 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 16: /* Body: BLOCK_BEGIN BLOCK_END  */
#line 78 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            
                                }
#line 1432 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 17: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 83 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        gsymbolTable = populateSymbolTable((yyvsp[-1].node),gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable("global",gsymbolTable);
                                    }
#line 1442 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 18: /* GDeclBlock: DECL ENDDECL  */
#line 88 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1448 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 19: /* GDeclList: GDeclList GDecl  */
#line 91 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1456 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 20: /* GDeclList: GDecl  */
#line 94 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1464 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 21: /* GDecl: Type GidList ';'  */
#line 99 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1472 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 23: /* Type: STR  */
#line 106 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
     {
        (yyval.node) = (yyvsp[0].node);
     }
#line 1480 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* Type: ID  */
#line 110 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {
        struct typeTable* type = getTypeTableWithName((yyvsp[0].node)->varName);
        if(type == NULL){
            printf("Error: type is used but not declared: %s\n",(yyvsp[0].node)->varName);
            exit(EXIT_FAILURE);
        }
        (yyvsp[0].node)->type = createUserDefinedType((yyvsp[0].node)->varName);
        (yyval.node) = (yyvsp[0].node);
       }
#line 1494 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* GidList: GidList ',' Gid  */
#line 121 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1502 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* GidList: Gid  */
#line 124 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1510 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* Gid: DeclArray  */
#line 131 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1518 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* Gid: ID '(' ParamList ')'  */
#line 134 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                                (yyval.node)->type = (yyvsp[-3].node)->type;
                            }
#line 1528 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* Gid: ID '(' ')'  */
#line 139 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {  
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-2].node),NULL,NULL,label);
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1538 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 31: /* Gid: '*' Gid  */
#line 144 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                    (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1547 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* ParamList: ParamList ',' Param  */
#line 150 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            (yyval.node) = createOperatorNode(OP_PARAMLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1555 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 33: /* ParamList: Param  */
#line 153 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1563 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 34: /* Param: Type Pid  */
#line 158 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = createOperatorNode(OP_PARAM,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    (yyval.node)->type = (yyvsp[0].node)->type;
                }
#line 1572 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* Pid: ID  */
#line 164 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
         {
            (yyval.node) = (yyvsp[0].node);
            }
#line 1580 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* Pid: '*' Pid  */
#line 167 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
            (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
            (yyval.node) = (yyvsp[0].node); 
        }
#line 1589 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 37: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 174 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1597 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* LDeclBlock: DECL ENDDECL  */
#line 177 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1603 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 39: /* LDeclList: LDeclList LDecl  */
#line 180 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1611 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 40: /* LDeclList: LDecl  */
#line 183 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1619 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 41: /* LDecl: Type LidList ';'  */
#line 188 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1627 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 42: /* LidList: LidList ',' Lid  */
#line 193 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1635 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 43: /* LidList: Lid  */
#line 196 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1643 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 45: /* Lid: DeclArray  */
#line 203 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1651 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 46: /* Lid: '*' Lid  */
#line 206 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
        (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1660 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 48: /* FDefBlock: FDef  */
#line 214 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {}
#line 1666 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 49: /* FDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 217 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                          {
                                                                (yyvsp[-8].node)->type->depth += (yyvsp[-7].node)->type->depth;
                                                                typeCheckFunctionParam((yyvsp[-8].node)->type,(yyvsp[-7].node)->varName,(yyvsp[-5].node),gsymbolTable);
                                                                struct symbol* symbolTable1 = NULL;
                                                                symbolTable1 = addParamAsSymbol((yyvsp[-7].node)->varName,gsymbolTable,symbolTable1);
                                                                symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
                                                                printSymbolTable((yyvsp[-7].node)->varName,symbolTable1);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
                                                                typeCheck((yyvsp[-1].node),symbolTable1);
                                                                populateParent((yyvsp[-1].node));
                                                                funcCodeGen(out,(yyvsp[-7].node)->varName,(yyvsp[-1].node),symbolTable1);
                                                        }
#line 1683 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 50: /* FDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 229 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                  {
        (yyvsp[-7].node)->type->depth += (yyvsp[-6].node)->type->depth;
        typeCheckFunctionParam((yyvsp[-7].node)->type,(yyvsp[-6].node)->varName,NULL,gsymbolTable);
        struct symbol* symbolTable1 = NULL;
        symbolTable1 = addParamAsSymbol((yyvsp[-6].node)->varName,gsymbolTable,symbolTable1);
        symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
        symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
        typeCheck((yyvsp[-1].node),symbolTable1);
        populateParent((yyvsp[-1].node));
        funcCodeGen(out,(yyvsp[-6].node)->varName,(yyvsp[-1].node),symbolTable1);
     }
#line 1699 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* Slist: Slist Stmt  */
#line 242 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1708 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* Slist: Stmt  */
#line 246 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1716 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 61: /* Stmt: DoWhileStmt  */
#line 260 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1724 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 62: /* RetStmt: RETURN E ';'  */
#line 265 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_RETURN,(yyvsp[-1].node),NULL,NULL,label);
        }
#line 1733 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 63: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 271 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                     { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node),label);
                                                  }
#line 1742 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 64: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF ';'  */
#line 275 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                        }
#line 1751 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 65: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE ';'  */
#line 282 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                                }
#line 1760 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 66: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 288 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1769 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 67: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 294 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1778 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 68: /* AsgStmt: Identifier '=' E ';'  */
#line 300 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 1787 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 70: /* ContinueStmt: CONTINUE ';'  */
#line 308 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1795 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 71: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 313 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 1804 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 72: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 319 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 1813 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 73: /* B: E '<' E  */
#line 325 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1821 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 74: /* B: E '>' E  */
#line 328 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1829 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 75: /* B: E GE E  */
#line 331 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1837 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 76: /* B: E LE E  */
#line 334 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1845 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 77: /* B: E NE E  */
#line 337 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1853 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 78: /* B: E EQ E  */
#line 340 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1861 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 79: /* E: E '+' E  */
#line 345 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1869 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 80: /* E: E '*' E  */
#line 348 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1877 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 81: /* E: E '-' E  */
#line 351 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1885 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 82: /* E: E '/' E  */
#line 354 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1893 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 83: /* E: E '%' E  */
#line 357 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1901 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 84: /* E: '&' ID  */
#line 360 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 1909 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 85: /* E: '(' E ')'  */
#line 363 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 1917 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 86: /* E: ID '(' ')'  */
#line 366 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-2].node),NULL,NULL,-1);
                }
#line 1925 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 87: /* E: ID '(' ArgList ')'  */
#line 369 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                            (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                        }
#line 1933 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 90: /* E: CSTR  */
#line 375 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 1941 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 91: /* ArgList: ArgList ',' E  */
#line 380 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_ARGLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1949 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 92: /* ArgList: E  */
#line 383 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1957 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 93: /* DeclArray: ID DeclBraceList  */
#line 388 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1); 
                        (yyval.node)->type = (yyvsp[-1].node)->type;
                    }
#line 1966 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 94: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 394 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1974 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 95: /* DeclBraceList: '[' NUM ']'  */
#line 397 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1982 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 96: /* Array: ID BraceList  */
#line 402 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 1990 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 97: /* BraceList: BraceList '[' E ']'  */
#line 407 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1998 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 98: /* BraceList: '[' E ']'  */
#line 410 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2006 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 100: /* Identifier: Array  */
#line 417 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2014 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 101: /* Identifier: '*' E  */
#line 420 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 2022 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 102: /* Identifier: E '.' ID  */
#line 423 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2030 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 2034 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 428 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"


int yyerror(const char* s){
    printf("Error: %s\ntoken: %s\nline number: %d\n",s,yytext,lines); 
    return 0;
}

int main(int argc,char** argv){
    if(argc > 2){
        yyin = fopen(argv[1],"r"); 
        out = fopen(argv[2],"w");
    } else{
        printf("Insufficient Args: <exe> <input> <output>\n");
        exit(EXIT_FAILURE);
    }
    initCompiler(out);
    fprintf(out,"JMP L0\n");
    yyparse();
    return 0;
}
