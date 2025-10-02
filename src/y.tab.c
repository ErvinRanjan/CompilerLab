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
    extern FILE* yyin;
    extern char* yytext;
    FILE* out;
    struct symbol* gsymbolTable = NULL;
    extern int lines;

#line 87 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '<'  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Program = 49,                   /* Program  */
  YYSYMBOL_MainBlock = 50,                 /* MainBlock  */
  YYSYMBOL_Body = 51,                      /* Body  */
  YYSYMBOL_GDeclBlock = 52,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 53,                 /* GDeclList  */
  YYSYMBOL_GDecl = 54,                     /* GDecl  */
  YYSYMBOL_Type = 55,                      /* Type  */
  YYSYMBOL_GidList = 56,                   /* GidList  */
  YYSYMBOL_Gid = 57,                       /* Gid  */
  YYSYMBOL_ParamList = 58,                 /* ParamList  */
  YYSYMBOL_Param = 59,                     /* Param  */
  YYSYMBOL_Pid = 60,                       /* Pid  */
  YYSYMBOL_LDeclBlock = 61,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 62,                 /* LDeclList  */
  YYSYMBOL_LDecl = 63,                     /* LDecl  */
  YYSYMBOL_LidList = 64,                   /* LidList  */
  YYSYMBOL_Lid = 65,                       /* Lid  */
  YYSYMBOL_FDefBlock = 66,                 /* FDefBlock  */
  YYSYMBOL_FDef = 67,                      /* FDef  */
  YYSYMBOL_Slist = 68,                     /* Slist  */
  YYSYMBOL_Stmt = 69,                      /* Stmt  */
  YYSYMBOL_RetStmt = 70,                   /* RetStmt  */
  YYSYMBOL_Ifstmt = 71,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 72,                 /* Whilestmt  */
  YYSYMBOL_InputStmt = 73,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 74,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 75,                   /* AsgStmt  */
  YYSYMBOL_BreakStmt = 76,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 77,              /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 78,           /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 79,               /* DoWhileStmt  */
  YYSYMBOL_B = 80,                         /* B  */
  YYSYMBOL_E = 81,                         /* E  */
  YYSYMBOL_ArgList = 82,                   /* ArgList  */
  YYSYMBOL_DeclArray = 83,                 /* DeclArray  */
  YYSYMBOL_DeclBraceList = 84,             /* DeclBraceList  */
  YYSYMBOL_Array = 85,                     /* Array  */
  YYSYMBOL_BraceList = 86,                 /* BraceList  */
  YYSYMBOL_Identifier = 87                 /* Identifier  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,    32,    45,     2,
      37,    38,    35,    33,    42,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      43,    31,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    32,    33,    36,    48,    52,    57,    62,
      65,    68,    73,    78,    79,    85,    88,    93,    94,    98,
     103,   108,   114,   117,   122,   128,   131,   138,   141,   144,
     147,   152,   157,   160,   165,   166,   170,   176,   177,   181,
     192,   205,   209,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   228,   234,   238,   245,   251,   257,   263,   269,
     270,   276,   282,   288,   291,   294,   297,   300,   303,   308,
     311,   314,   317,   320,   323,   326,   329,   332,   335,   338,
     339,   340,   346,   349,   354,   359,   362,   367,   371,   374,
     379,   380,   384
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
  "MAIN", "RETURN", "'='", "'%'", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'{'", "'}'", "';'", "','", "'<'", "'>'", "'&'", "'['", "']'", "$accept",
  "Program", "MainBlock", "Body", "GDeclBlock", "GDeclList", "GDecl",
  "Type", "GidList", "Gid", "ParamList", "Param", "Pid", "LDeclBlock",
  "LDeclList", "LDecl", "LidList", "Lid", "FDefBlock", "FDef", "Slist",
  "Stmt", "RetStmt", "Ifstmt", "Whilestmt", "InputStmt", "OutputStmt",
  "AsgStmt", "BreakStmt", "ContinueStmt", "RepeatUntilStmt", "DoWhileStmt",
  "B", "E", "ArgList", "DeclArray", "DeclBraceList", "Array", "BraceList",
  "Identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,   194,     8,    35,  -111,    97,  -111,  -111,  -111,   213,
    -111,     3,    14,  -111,     8,  -111,    10,    97,  -111,  -111,
    -111,   -21,     3,    58,  -111,  -111,    26,  -111,    10,    49,
    -111,  -111,    73,    55,    50,  -111,  -111,     3,    79,  -111,
     101,  -111,    10,    -8,  -111,    93,   139,  -111,   135,   120,
      21,  -111,  -111,   145,  -111,   134,   219,   178,   135,   155,
    -111,  -111,  -111,    17,   236,  -111,   147,   153,   178,   135,
     150,    17,   131,  -111,  -111,  -111,  -111,   151,  -111,   163,
     168,   170,   183,   268,   173,   180,   268,    75,   171,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
     200,  -111,   185,   178,  -111,  -111,    17,    75,   186,    20,
      75,    75,    75,   292,  -111,  -111,   195,  -111,    78,  -111,
      75,    75,   222,   113,  -111,    75,  -111,   233,    75,  -111,
     205,  -111,    41,    75,   208,   288,   211,   298,   212,   217,
     225,    68,  -111,   311,  -111,    75,    75,    75,    75,    75,
     130,  -111,   154,  -111,  -111,    57,   226,   227,   253,    75,
      75,    75,    75,    75,    75,   252,    75,    75,  -111,   113,
      23,  -111,   177,   141,   141,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,   268,   113,   113,   113,   113,   113,   113,   268,
     231,   232,  -111,    75,   123,   220,    19,   237,   113,   268,
    -111,  -111,  -111,  -111,   244,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     9,    13,    14,     0,
      11,     0,     0,     1,    13,     3,     0,     0,    38,     8,
      10,    17,     0,     0,    16,    18,     0,    25,     0,     0,
       2,    37,     0,     0,    84,    21,    12,     0,     0,    26,
       0,    20,     0,     0,    23,     0,     0,    15,     0,     0,
       0,    24,    19,     0,    86,     0,     0,     0,     0,     0,
      22,    85,    28,     0,     0,    30,     0,     0,     0,     0,
      34,     0,     0,    33,    35,    27,    29,    90,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      46,    47,    43,    44,    45,    48,    49,    50,    51,    91,
       0,     5,     0,     0,    36,    31,     0,     0,    87,     0,
       0,     0,     0,     0,    59,    60,     0,    79,    90,    81,
       0,     0,     0,    92,    80,     0,    41,     0,     0,    40,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,    74,     0,     0,     0,     0,     0,
       0,     6,     0,    39,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    83,
       0,    76,    73,    69,    71,    70,    72,    52,    58,    88,
      56,    57,     0,    65,    66,    67,    68,    63,    64,     0,
       0,     0,    78,     0,     0,     0,     0,     0,    82,     0,
      54,    55,    62,    61,     0,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,     6,   -64,  -111,  -111,   264,    31,  -111,   -10,
     234,   230,   -23,    83,  -111,   216,  -111,   -62,  -111,   267,
     -80,   -87,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -110,   -79,  -111,   -53,  -111,  -111,  -111,   -66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    67,     5,     9,    10,    42,    23,    24,
      43,    44,    29,    57,    64,    65,    72,    73,    17,    18,
      88,    89,   127,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   136,   137,   170,    25,    34,    99,   108,   124
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     100,   126,   138,   113,   102,    39,   116,    21,   123,   104,
      74,    15,    35,     1,    27,     2,    32,   100,    74,    51,
     100,    70,   100,    30,    77,    33,   126,    47,   132,   126,
      52,   135,    11,   189,    53,    13,    16,    12,    22,   130,
      11,   142,   143,   134,   131,    28,   150,   100,    16,   152,
     100,    26,    71,    74,   155,    87,   190,   191,    45,    59,
     202,   192,   169,    53,    38,   193,   172,   173,   174,   175,
     176,   117,   118,   145,   146,   147,   148,   149,   117,   118,
     183,   184,   185,   186,   187,   188,    40,    63,   154,   145,
     146,   147,   148,   149,   119,    63,    46,     7,     8,    36,
      37,   119,   194,   120,   179,   121,   168,   126,   126,   195,
     120,    41,   121,   122,   198,   141,   100,   126,    48,   204,
     122,    14,     8,   100,   107,     7,     8,    77,   100,   100,
      79,    80,    81,   100,   199,   200,    82,    83,   100,    49,
      54,    68,    55,    84,    85,   145,   146,   147,   148,   149,
      86,    77,   103,    78,    79,    80,    81,    56,    87,    58,
      82,    83,   145,   146,   147,   148,   149,    84,    85,     7,
       8,   177,   105,   106,    86,    77,   148,   149,    79,    80,
      81,    61,    87,    66,    82,    83,   145,   146,   147,   148,
     149,    84,    85,   101,    69,   178,    33,   107,    86,    77,
     109,   125,    79,    80,    81,   110,    87,   111,    82,    83,
     146,   147,   148,   149,   114,    84,    85,     6,     7,     8,
     112,   115,    86,   140,    77,   129,   144,    79,    80,    81,
      87,   128,   133,    82,    83,   201,    19,     7,     8,   151,
      84,    85,    62,     7,     8,   153,   156,    86,    77,   158,
     165,    79,    80,    81,   166,    87,   205,    82,    83,    75,
       7,     8,   167,   182,    84,    85,   189,   180,   181,   196,
     197,    86,    77,    20,    50,    79,    80,    81,   203,    87,
      76,    82,    83,    60,    31,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,    86,    77,     0,     0,    79,
      80,    81,     0,    87,     0,   139,    83,     0,     0,     0,
       0,     0,    84,    85,   159,   160,   161,   162,     0,    86,
     145,   146,   147,   148,   149,     0,   157,    87,     0,     0,
     145,   146,   147,   148,   149,     0,     0,     0,     0,     0,
       0,   163,   164,   145,   146,   147,   148,   149,     0,   171
};

static const yytype_int16 yycheck[] =
{
      66,    88,   112,    83,    68,    28,    86,     4,    87,    71,
      63,     5,    22,    22,     4,    24,    37,    83,    71,    42,
      86,     4,    88,    17,     4,    46,   113,    37,   107,   116,
      38,   110,     1,    14,    42,     0,     5,    29,    35,   103,
       9,   120,   121,   109,   106,    35,   125,   113,    17,   128,
     116,    37,    35,   106,   133,    35,   166,   167,     3,    38,
      41,    38,   141,    42,    38,    42,   145,   146,   147,   148,
     149,     3,     4,    32,    33,    34,    35,    36,     3,     4,
     159,   160,   161,   162,   163,   164,    37,    56,    47,    32,
      33,    34,    35,    36,    26,    64,    46,    24,    25,    41,
      42,    26,   182,    35,    47,    37,    38,   194,   195,   189,
      35,    38,    37,    45,   193,    37,   182,   204,    39,   199,
      45,    24,    25,   189,    46,    24,    25,     4,   194,   195,
       7,     8,     9,   199,    11,    12,    13,    14,   204,    38,
      47,    58,     3,    20,    21,    32,    33,    34,    35,    36,
      27,     4,    69,     6,     7,     8,     9,    22,    35,    39,
      13,    14,    32,    33,    34,    35,    36,    20,    21,    24,
      25,    41,    41,    42,    27,     4,    35,    36,     7,     8,
       9,    47,    35,     5,    13,    14,    32,    33,    34,    35,
      36,    20,    21,    40,    39,    41,    46,    46,    27,     4,
      37,    30,     7,     8,     9,    37,    35,    37,    13,    14,
      33,    34,    35,    36,    41,    20,    21,    23,    24,    25,
      37,    41,    27,    28,     4,    40,     4,     7,     8,     9,
      35,    31,    46,    13,    14,    15,    23,    24,    25,     6,
      20,    21,    23,    24,    25,    40,    38,    27,     4,    38,
      38,     7,     8,     9,    37,    35,    12,    13,    14,    23,
      24,    25,    37,    10,    20,    21,    14,    41,    41,    38,
      38,    27,     4,     9,    40,     7,     8,     9,    41,    35,
      64,    13,    14,    53,    17,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    27,     4,    -1,    -1,     7,
       8,     9,    -1,    35,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    21,    16,    17,    18,    19,    -1,    27,
      32,    33,    34,    35,    36,    -1,    38,    35,    -1,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    32,    33,    34,    35,    36,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    24,    49,    50,    52,    23,    24,    25,    53,
      54,    55,    29,     0,    24,    50,    55,    66,    67,    23,
      54,     4,    35,    56,    57,    83,    37,     4,    35,    60,
      50,    67,    37,    46,    84,    57,    41,    42,    38,    60,
      37,    38,    55,    58,    59,     3,    46,    57,    39,    38,
      58,    60,    38,    42,    47,     3,    22,    61,    39,    38,
      59,    47,    23,    55,    62,    63,     5,    51,    61,    39,
       4,    35,    64,    65,    83,    23,    63,     4,     6,     7,
       8,     9,    13,    14,    20,    21,    27,    35,    68,    69,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    85,
      87,    40,    51,    61,    65,    41,    42,    46,    86,    37,
      37,    37,    37,    68,    41,    41,    68,     3,     4,    26,
      35,    37,    45,    81,    87,    30,    69,    70,    31,    40,
      51,    65,    81,    46,    87,    81,    80,    81,    80,    13,
      28,    37,    81,    81,     4,    32,    33,    34,    35,    36,
      81,     6,    81,    40,    47,    81,    38,    38,    38,    16,
      17,    18,    19,    43,    44,    38,    37,    37,    38,    81,
      82,    38,    81,    81,    81,    81,    81,    41,    41,    47,
      41,    41,    10,    81,    81,    81,    81,    81,    81,    14,
      80,    80,    38,    42,    68,    68,    38,    38,    81,    11,
      12,    15,    41,    41,    68,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    58,    58,    59,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    83,    84,    84,    85,    86,    86,
      87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     8,     4,     2,     3,     2,
       2,     1,     3,     1,     1,     3,     1,     1,     1,     4,
       3,     2,     3,     1,     2,     1,     2,     3,     2,     2,
       1,     3,     3,     1,     1,     1,     2,     2,     1,     9,
       8,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     9,     7,     7,     5,     5,     4,     2,
       2,     7,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     4,     1,
       1,     1,     3,     1,     2,     4,     3,     2,     4,     3,
       1,     1,     2
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
  case 5: /* MainBlock: INT MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 36 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                      { 
                                                            struct symbol* symbolTable = NULL;
                                                            symbolTable = populateSymbolTable((yyvsp[-2].node),symbolTable,0);
                                                            printSymbolTable(symbolTable);
                                                            symbolTable = appendSymbolTable(symbolTable,gsymbolTable);
                                                            typeCheck((yyvsp[-1].node),symbolTable);
                                                            fprintf(out,"L0:\n"); 
                                                            populateParent((yyvsp[-1].node));
                                                            codeGen(out,(yyvsp[-1].node),symbolTable);
                                                        }
#line 1331 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 6: /* Body: BLOCK_BEGIN Slist RetStmt BLOCK_END  */
#line 48 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {
                               (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                               (yyval.node)->label = (yyvsp[-2].node)->label;
                           }
#line 1340 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 7: /* Body: BLOCK_BEGIN BLOCK_END  */
#line 52 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            
                                }
#line 1348 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 8: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 57 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        gsymbolTable = populateSymbolTable((yyvsp[-1].node),gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable(gsymbolTable);
                                    }
#line 1358 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 9: /* GDeclBlock: DECL ENDDECL  */
#line 62 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1364 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 10: /* GDeclList: GDeclList GDecl  */
#line 65 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1372 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 11: /* GDeclList: GDecl  */
#line 68 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1380 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 12: /* GDecl: Type GidList ';'  */
#line 73 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1388 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 14: /* Type: STR  */
#line 80 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {
        (yyval.node) = (yyvsp[0].node);
       }
#line 1396 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* GidList: GidList ',' Gid  */
#line 85 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1404 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 16: /* GidList: Gid  */
#line 88 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1412 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 18: /* Gid: DeclArray  */
#line 95 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1420 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 19: /* Gid: ID '(' ParamList ')'  */
#line 98 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                                (yyval.node)->type = (yyvsp[-3].node)->type;
                            }
#line 1430 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 20: /* Gid: ID '(' ')'  */
#line 103 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {  
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-2].node),NULL,NULL,label);
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1440 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 21: /* Gid: '*' Gid  */
#line 108 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                    (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1449 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 22: /* ParamList: ParamList ',' Param  */
#line 114 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            (yyval.node) = createOperatorNode(OP_PARAMLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1457 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 23: /* ParamList: Param  */
#line 117 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1465 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* Param: Type Pid  */
#line 122 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = createOperatorNode(OP_PARAM,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    (yyval.node)->type = (yyvsp[0].node)->type;
                }
#line 1474 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* Pid: ID  */
#line 128 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
         {
            (yyval.node) = (yyvsp[0].node);
            }
#line 1482 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* Pid: '*' Pid  */
#line 131 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
            (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
            (yyval.node) = (yyvsp[0].node); 
        }
#line 1491 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 27: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 138 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1499 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* LDeclBlock: DECL ENDDECL  */
#line 141 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1505 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* LDeclList: LDeclList LDecl  */
#line 144 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1513 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* LDeclList: LDecl  */
#line 147 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1521 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 31: /* LDecl: Type LidList ';'  */
#line 152 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1529 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* LidList: LidList ',' Lid  */
#line 157 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1537 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 33: /* LidList: Lid  */
#line 160 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1545 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* Lid: DeclArray  */
#line 167 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1553 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* Lid: '*' Lid  */
#line 170 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
        (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1562 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* FDefBlock: FDef  */
#line 178 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {}
#line 1568 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 39: /* FDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 181 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                          {
                                                                (yyvsp[-8].node)->type->depth += (yyvsp[-7].node)->type->depth;
                                                                typeCheckFunctionParam((yyvsp[-8].node)->type,(yyvsp[-7].node)->varName,(yyvsp[-5].node),gsymbolTable);
                                                                struct symbol* symbolTable1 = NULL;
                                                                symbolTable1 = addParamAsSymbol((yyvsp[-7].node)->varName,gsymbolTable,symbolTable1);
                                                                symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
                                                                typeCheck((yyvsp[-1].node),symbolTable1);
                                                                populateParent((yyvsp[-1].node));
                                                                funcCodeGen(out,(yyvsp[-7].node)->varName,(yyvsp[-1].node),symbolTable1);
                                                        }
#line 1584 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 40: /* FDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 192 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1600 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 41: /* Slist: Slist Stmt  */
#line 205 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1609 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 42: /* Slist: Stmt  */
#line 209 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1617 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* Stmt: DoWhileStmt  */
#line 223 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1625 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* RetStmt: RETURN E ';'  */
#line 228 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_RETURN,(yyvsp[-1].node),NULL,NULL,label);
        }
#line 1634 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 53: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF  */
#line 234 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                  { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node),label);
                                                  }
#line 1643 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 54: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF  */
#line 238 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                         {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-4].node),(yyvsp[-1].node),NULL,label);
                                        }
#line 1652 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 55: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE  */
#line 245 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                              {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-4].node),(yyvsp[-1].node),NULL,label);
                                                }
#line 1661 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 56: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 251 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1670 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 57: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 257 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1679 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 58: /* AsgStmt: Identifier '=' E ';'  */
#line 263 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 1688 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 60: /* ContinueStmt: CONTINUE ';'  */
#line 271 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1696 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 61: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 276 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 1705 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 62: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 282 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 1714 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 63: /* B: E '<' E  */
#line 288 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1722 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 64: /* B: E '>' E  */
#line 291 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1730 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 65: /* B: E GE E  */
#line 294 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1738 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 66: /* B: E LE E  */
#line 297 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1746 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 67: /* B: E NE E  */
#line 300 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1754 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 68: /* B: E EQ E  */
#line 303 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1762 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 69: /* E: E '+' E  */
#line 308 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1770 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 70: /* E: E '*' E  */
#line 311 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1778 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 71: /* E: E '-' E  */
#line 314 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1786 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 72: /* E: E '/' E  */
#line 317 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1794 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 73: /* E: E '%' E  */
#line 320 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1802 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 74: /* E: '&' ID  */
#line 323 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 1810 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 75: /* E: '*' E  */
#line 326 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 1818 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 76: /* E: '(' E ')'  */
#line 329 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 1826 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 77: /* E: ID '(' ')'  */
#line 332 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-2].node),NULL,NULL,-1);
                }
#line 1834 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 78: /* E: ID '(' ArgList ')'  */
#line 335 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                            (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                        }
#line 1842 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 81: /* E: CSTR  */
#line 341 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 1850 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 82: /* ArgList: ArgList ',' E  */
#line 346 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_ARGLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1858 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 83: /* ArgList: E  */
#line 349 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1866 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 84: /* DeclArray: ID DeclBraceList  */
#line 354 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node) = (yyvsp[-1].node)->type;
                    }
#line 1875 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 85: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 359 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1883 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 86: /* DeclBraceList: '[' NUM ']'  */
#line 362 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1891 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 87: /* Array: ID BraceList  */
#line 367 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 1899 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 88: /* BraceList: BraceList '[' E ']'  */
#line 371 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1907 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 89: /* BraceList: '[' E ']'  */
#line 374 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1915 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 91: /* Identifier: Array  */
#line 381 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1923 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 92: /* Identifier: '*' E  */
#line 384 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 1931 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 1935 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 389 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"


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
