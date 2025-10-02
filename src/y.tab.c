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
#line 1 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"

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

#line 85 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '%'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '<'  */
  YYSYMBOL_40_ = 40,                       /* '>'  */
  YYSYMBOL_41_ = 41,                       /* '&'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_Program = 45,                   /* Program  */
  YYSYMBOL_Declarations = 46,              /* Declarations  */
  YYSYMBOL_DeclList = 47,                  /* DeclList  */
  YYSYMBOL_Decl = 48,                      /* Decl  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_VarList = 50,                   /* VarList  */
  YYSYMBOL_Slist = 51,                     /* Slist  */
  YYSYMBOL_Stmt = 52,                      /* Stmt  */
  YYSYMBOL_Ifstmt = 53,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 54,                 /* Whilestmt  */
  YYSYMBOL_InputStmt = 55,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 56,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 57,                   /* AsgStmt  */
  YYSYMBOL_BreakStmt = 58,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 59,              /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 60,           /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 61,               /* DoWhileStmt  */
  YYSYMBOL_B = 62,                         /* B  */
  YYSYMBOL_E = 63,                         /* E  */
  YYSYMBOL_DeclArray = 64,                 /* DeclArray  */
  YYSYMBOL_DeclBraceList = 65,             /* DeclBraceList  */
  YYSYMBOL_Array = 66,                     /* Array  */
  YYSYMBOL_BraceList = 67,                 /* BraceList  */
  YYSYMBOL_Identifier = 68                 /* Identifier  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
       2,     2,     2,     2,     2,     2,     2,    30,    41,     2,
      37,    38,    33,    31,    36,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      39,    29,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    29,    29,    40,    43,    46,    49,    54,    59,    60,
      66,    69,    72,    75,    80,    84,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   103,   107,   114,   120,   126,
     132,   138,   139,   145,   151,   157,   160,   163,   166,   169,
     172,   177,   180,   183,   186,   189,   192,   195,   198,   201,
     202,   203,   209,   213,   216,   221,   225,   228,   233,   234,
     238
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
  "'='", "'%'", "'+'", "'-'", "'*'", "'/'", "';'", "','", "'('", "')'",
  "'<'", "'>'", "'&'", "'['", "']'", "$accept", "Program", "Declarations",
  "DeclList", "Decl", "Type", "VarList", "Slist", "Stmt", "Ifstmt",
  "Whilestmt", "InputStmt", "OutputStmt", "AsgStmt", "BreakStmt",
  "ContinueStmt", "RepeatUntilStmt", "DoWhileStmt", "B", "E", "DeclArray",
  "DeclBraceList", "Array", "BraceList", "Identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,     6,     9,   175,   -42,   -42,   -42,    57,   -42,     8,
     -42,   -25,   -13,    -5,     2,    12,   175,    -1,    11,   175,
       7,   175,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,    14,   -42,   -42,    15,   -21,   -42,     7,
      29,     4,     7,     7,     7,   190,   -42,   -42,   116,   -42,
     -42,     7,     7,    68,   188,   -42,   -42,     7,    81,    43,
     -42,    85,    20,     7,    56,   101,    59,   196,    60,    58,
      67,   -42,   207,   -42,     7,     7,     7,     7,     7,   216,
      62,   105,    15,   -42,   -42,    36,    74,    78,   106,     7,
       7,     7,     7,     7,     7,   103,     7,     7,   -42,   -12,
      31,    31,   -42,   -42,   -42,   -42,    72,   -42,   -42,   -42,
     175,   188,   188,   188,   188,   188,   188,   175,    83,    88,
     -42,    79,   138,    -8,    93,   175,   113,   115,   -42,   -42,
     160,   -42,   -42,   119,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     8,     9,     0,     6,     0,
       1,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,    15,    19,    20,    16,    17,    18,    21,    22,
      23,    24,    59,     0,     3,     5,    11,     0,    13,     0,
      55,     0,     0,     0,     0,     0,    31,    32,     0,    49,
      51,     0,     0,     0,    60,    50,    14,     0,     0,    52,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    12,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    45,
      41,    43,    42,    44,    30,    54,     0,    56,    28,    29,
       0,    37,    38,    39,    40,    35,    36,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,    34,    33,
       0,    26,    27,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   -42,   -42,   131,   -42,   -42,   -14,   -20,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -41,   -16,
      80,   -42,   -42,   -42,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     7,     8,     9,    37,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    66,    67,
      38,    59,    32,    40,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    56,    45,    68,    54,    48,   117,     1,    11,    10,
      49,    11,    36,    33,    60,    61,    33,    39,    33,    75,
      76,    77,    78,    62,    41,    56,    65,   128,    56,     4,
       5,     6,    42,    50,    46,    71,    72,    20,    64,    43,
      51,    79,    33,    57,    52,    33,    47,    85,    53,    44,
      74,    75,    76,    77,    78,   118,   119,    58,    99,   100,
     101,   102,   103,    84,    77,    78,    74,    75,    76,    77,
      78,    63,    73,   111,   112,   113,   114,   115,   116,   107,
      34,     5,     6,    11,    80,    81,    12,    13,    14,    82,
     125,   126,    15,    16,    86,    96,   121,    88,    95,    17,
      18,    56,    56,   122,    97,   105,    19,    33,   106,   108,
      56,   130,    20,   109,    33,   120,   110,   117,    33,    33,
      11,   123,    33,    12,    13,    14,   124,    33,   129,    15,
      16,    74,    75,    76,    77,    78,    17,    18,    35,    87,
       0,    83,    11,    19,    70,    12,    13,    14,   131,    20,
     132,    15,    16,   127,   134,     0,     0,     0,    17,    18,
       0,     0,     0,     0,    11,    19,     0,    12,    13,    14,
       0,    20,   133,    15,    16,     0,     0,     0,     0,    11,
      17,    18,    12,    13,    14,     0,     0,    19,    15,    16,
       0,     0,     0,    20,    11,    17,    18,    12,    13,    14,
       0,     0,    19,    69,    16,     0,     0,     0,    20,     0,
      17,    18,    89,    90,    91,    92,     0,    19,    74,    75,
      76,    77,    78,    20,     0,     0,    74,    75,    76,    77,
      78,     0,     0,     0,     0,    93,    94,    74,    75,    76,
      77,    78,     0,     0,     0,    98,    74,    75,    76,    77,
      78,   104
};

static const yytype_int16 yycheck[] =
{
       3,    21,    16,    44,    20,    19,    14,    22,     4,     0,
       3,     4,     4,    16,    35,    36,    19,    42,    21,    31,
      32,    33,    34,    39,    37,    45,    42,    35,    48,    23,
      24,    25,    37,    26,    35,    51,    52,    33,    41,    37,
      33,    57,    45,    29,    37,    48,    35,    63,    41,    37,
      30,    31,    32,    33,    34,    96,    97,    42,    74,    75,
      76,    77,    78,    43,    33,    34,    30,    31,    32,    33,
      34,    42,     4,    89,    90,    91,    92,    93,    94,    43,
      23,    24,    25,     4,     3,    42,     7,     8,     9,     4,
      11,    12,    13,    14,    38,    37,   110,    38,    38,    20,
      21,   121,   122,   117,    37,    43,    27,   110,     3,    35,
     130,   125,    33,    35,   117,    43,    10,    14,   121,   122,
       4,    38,   125,     7,     8,     9,    38,   130,    35,    13,
      14,    30,    31,    32,    33,    34,    20,    21,     7,    38,
      -1,    61,     4,    27,    28,     7,     8,     9,    35,    33,
      35,    13,    14,    15,    35,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,     4,    27,    -1,     7,     8,     9,
      -1,    33,    12,    13,    14,    -1,    -1,    -1,    -1,     4,
      20,    21,     7,     8,     9,    -1,    -1,    27,    13,    14,
      -1,    -1,    -1,    33,     4,    20,    21,     7,     8,     9,
      -1,    -1,    27,    13,    14,    -1,    -1,    -1,    33,    -1,
      20,    21,    16,    17,    18,    19,    -1,    27,    30,    31,
      32,    33,    34,    33,    -1,    -1,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    30,    31,    32,    33,
      34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    45,    46,    23,    24,    25,    47,    48,    49,
       0,     4,     7,     8,     9,    13,    14,    20,    21,    27,
      33,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    66,    68,    23,    48,     4,    50,    64,    42,
      67,    37,    37,    37,    37,    51,    35,    35,    51,     3,
      26,    33,    37,    41,    63,    68,    52,    29,    42,    65,
      35,    36,    63,    42,    68,    63,    62,    63,    62,    13,
      28,    63,    63,     4,    30,    31,    32,    33,    34,    63,
       3,    42,     4,    64,    43,    63,    38,    38,    38,    16,
      17,    18,    19,    39,    40,    38,    37,    37,    38,    63,
      63,    63,    63,    63,    35,    43,     3,    43,    35,    35,
      10,    63,    63,    63,    63,    63,    63,    14,    62,    62,
      43,    51,    51,    38,    38,    11,    12,    15,    35,    35,
      51,    35,    35,    12,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    65,    66,    67,    67,    68,    68,
      68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     3,     1,     1,
       3,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,    10,     8,     8,     5,     5,
       4,     2,     2,     7,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     1,     2,     4,     3,     2,     4,     3,     1,     1,
       2
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
  case 2: /* Program: Declarations Slist  */
#line 29 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                {
                                struct symbol* symbolTable = NULL;
                                symbolTable = populateSymbolTable((yyvsp[-1].node),symbolTable);
                                printSymbolTable(symbolTable);
                                typeCheck((yyvsp[0].node),symbolTable);
                                populateParent((yyvsp[0].node));
                                //interpret($<node>2,symbolTable);
                                codeGen(out,(yyvsp[0].node),symbolTable);
                           }
#line 1256 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 3: /* Declarations: DECL DeclList ENDDECL  */
#line 40 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                     {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1264 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 4: /* Declarations: DECL ENDDECL  */
#line 43 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                           {}
#line 1270 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 5: /* DeclList: DeclList Decl  */
#line 46 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1278 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 6: /* DeclList: Decl  */
#line 49 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1286 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 7: /* Decl: Type VarList ';'  */
#line 54 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                        {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1294 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 9: /* Type: STR  */
#line 61 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
       {
        (yyval.node) = (yyvsp[0].node);
       }
#line 1302 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 10: /* VarList: VarList ',' ID  */
#line 66 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                            {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1310 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 11: /* VarList: ID  */
#line 69 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1318 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 12: /* VarList: VarList ',' DeclArray  */
#line 72 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                 {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1326 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 13: /* VarList: DeclArray  */
#line 75 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                     {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1334 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 14: /* Slist: Slist Stmt  */
#line 80 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1343 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* Slist: Stmt  */
#line 84 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1351 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* Stmt: DoWhileStmt  */
#line 98 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1359 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 103 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                                      { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node),label);
                                                  }
#line 1368 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF ';'  */
#line 107 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                             {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                        }
#line 1377 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 27: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE ';'  */
#line 114 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                                  {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                                }
#line 1386 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 120 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1395 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 126 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1404 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* AsgStmt: Identifier '=' E ';'  */
#line 132 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 1413 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* ContinueStmt: CONTINUE ';'  */
#line 140 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1421 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 33: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 145 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 1430 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 34: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 151 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 1439 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* B: E '<' E  */
#line 157 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1447 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* B: E '>' E  */
#line 160 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1455 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 37: /* B: E GE E  */
#line 163 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1463 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* B: E LE E  */
#line 166 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1471 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 39: /* B: E NE E  */
#line 169 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1479 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 40: /* B: E EQ E  */
#line 172 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1487 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 41: /* E: E '+' E  */
#line 177 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1495 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 42: /* E: E '*' E  */
#line 180 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1503 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 43: /* E: E '-' E  */
#line 183 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1511 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 44: /* E: E '/' E  */
#line 186 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1519 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 45: /* E: E '%' E  */
#line 189 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1527 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 46: /* E: '&' ID  */
#line 192 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 1535 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 47: /* E: '*' E  */
#line 195 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
          {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 1543 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 48: /* E: '(' E ')'  */
#line 198 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 1551 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* E: CSTR  */
#line 204 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 1559 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* DeclArray: ID DeclBraceList  */
#line 209 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 1567 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 53: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 213 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1575 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 54: /* DeclBraceList: '[' NUM ']'  */
#line 216 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1583 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 55: /* Array: ID BraceList  */
#line 221 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 1591 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 56: /* BraceList: BraceList '[' E ']'  */
#line 225 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1599 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 57: /* BraceList: '[' E ']'  */
#line 228 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1607 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 59: /* Identifier: Array  */
#line 235 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1615 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 60: /* Identifier: '*' E  */
#line 238 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 1623 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 1627 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 243 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage4/exercise1/src/yacc/generateExpTree.y"


int yyerror(const char* s){
    printf("Error: %s\ntoken: %s",s,yytext);
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
    yyparse();
    return 0;
}
