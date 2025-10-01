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

#line 86 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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
  YYSYMBOL_LDeclBlock = 60,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 61,                 /* LDeclList  */
  YYSYMBOL_LDecl = 62,                     /* LDecl  */
  YYSYMBOL_LidList = 63,                   /* LidList  */
  YYSYMBOL_Lid = 64,                       /* Lid  */
  YYSYMBOL_FDefBlock = 65,                 /* FDefBlock  */
  YYSYMBOL_FDef = 66,                      /* FDef  */
  YYSYMBOL_Slist = 67,                     /* Slist  */
  YYSYMBOL_Stmt = 68,                      /* Stmt  */
  YYSYMBOL_RetStmt = 69,                   /* RetStmt  */
  YYSYMBOL_Ifstmt = 70,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 71,                 /* Whilestmt  */
  YYSYMBOL_InputStmt = 72,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 73,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 74,                   /* AsgStmt  */
  YYSYMBOL_BreakStmt = 75,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 76,              /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 77,           /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 78,               /* DoWhileStmt  */
  YYSYMBOL_B = 79,                         /* B  */
  YYSYMBOL_E = 80,                         /* E  */
  YYSYMBOL_ArgList = 81,                   /* ArgList  */
  YYSYMBOL_DeclArray = 82,                 /* DeclArray  */
  YYSYMBOL_DeclBraceList = 83,             /* DeclBraceList  */
  YYSYMBOL_Array = 84,                     /* Array  */
  YYSYMBOL_BraceList = 85,                 /* BraceList  */
  YYSYMBOL_Identifier = 86                 /* Identifier  */
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
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

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
       0,    30,    30,    31,    32,    35,    46,    50,    55,    60,
      63,    66,    71,    76,    77,    83,    86,    91,    92,    96,
     100,   106,   109,   114,   120,   123,   126,   129,   134,   139,
     142,   147,   148,   154,   155,   159,   169,   181,   185,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   204,   210,
     214,   221,   227,   233,   239,   245,   246,   252,   258,   264,
     267,   270,   273,   276,   279,   284,   287,   290,   293,   296,
     299,   302,   305,   308,   311,   314,   315,   316,   322,   325,
     330,   334,   337,   342,   346,   349,   354,   355,   359
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
  "Type", "GidList", "Gid", "ParamList", "Param", "LDeclBlock",
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

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,   115,   -15,    33,  -104,     6,  -104,  -104,  -104,   120,
    -104,    34,    16,  -104,   -15,  -104,    76,     6,  -104,  -104,
    -104,    67,    57,  -104,  -104,    23,    68,  -104,  -104,    -2,
     107,    66,  -104,    34,    78,    41,  -104,   143,    -3,  -104,
     103,   154,  -104,   133,   136,    22,  -104,  -104,    98,  -104,
     127,   185,   174,   133,   142,  -104,  -104,  -104,   191,   192,
    -104,   145,   163,   174,   133,   159,   126,  -104,  -104,  -104,
    -104,   165,  -104,   161,   175,   181,   182,   266,   183,   188,
     266,    74,   169,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,   199,  -104,   194,   174,  -104,   191,
      74,   177,     9,    74,    74,    74,   290,  -104,  -104,   193,
    -104,   100,  -104,    74,    74,   231,   152,  -104,    74,  -104,
     230,    74,  -104,   197,  -104,    40,    74,   202,   286,   203,
     296,   204,   206,   207,    14,  -104,   309,  -104,    74,    74,
      74,    74,    74,    61,  -104,   128,  -104,  -104,    56,   211,
     216,   237,    74,    74,    74,    74,    74,    74,   234,    74,
      74,  -104,   152,    82,  -104,   158,   135,   135,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,   266,   152,   152,   152,   152,
     152,   152,   266,   220,   221,  -104,    74,   121,   218,    -7,
     219,   152,   266,  -104,  -104,  -104,  -104,   242,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     9,    13,    14,     0,
      11,     0,     0,     1,    13,     3,     0,     0,    34,     8,
      10,    17,     0,    16,    18,     0,     0,     2,    33,     0,
       0,    80,    12,     0,     0,     0,    20,     0,     0,    22,
       0,     0,    15,     0,     0,     0,    23,    19,     0,    82,
       0,     0,     0,     0,     0,    21,    81,    25,     0,     0,
      27,     0,     0,     0,     0,    31,     0,    30,    32,    24,
      26,    86,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    42,    43,    39,    40,    41,    44,
      45,    46,    47,    87,     0,     5,     0,     0,    28,     0,
       0,    83,     0,     0,     0,     0,     0,    55,    56,     0,
      75,    86,    77,     0,     0,     0,    88,    76,     0,    37,
       0,     0,    36,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,    70,     0,     0,
       0,     0,     0,     0,     6,     0,    35,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    79,     0,    72,    69,    65,    67,    66,    68,
      48,    54,    84,    52,    53,     0,    61,    62,    63,    64,
      59,    60,     0,     0,     0,    74,     0,     0,     0,     0,
       0,    78,     0,    50,    51,    58,    57,     0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,    10,   -39,  -104,  -104,   252,     3,  -104,   232,
     229,   223,   -27,  -104,   208,  -104,   167,  -104,   251,   -74,
     -81,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -103,   -71,  -104,   -53,  -104,  -104,  -104,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    62,     5,     9,    10,    37,    22,    23,
      38,    39,    52,    59,    60,    66,    67,    17,    18,    82,
      83,   120,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   129,   130,   163,    24,    31,    93,   101,   117
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      94,   119,   131,   106,    11,    68,   109,   182,    16,     1,
     116,     2,    11,    71,    12,    15,    94,   110,   111,    94,
      16,    94,     7,     8,    96,   119,    63,    27,   119,   125,
      14,     8,   128,    13,   195,    47,    36,    97,    21,    48,
     112,   127,   135,   136,    81,    94,    68,   143,    94,   113,
     145,   114,   161,    25,    58,   148,   183,   184,   123,   115,
      54,    34,    58,   162,    48,     7,     8,   165,   166,   167,
     168,   169,   138,   139,   140,   141,   142,   110,   111,    44,
      26,   176,   177,   178,   179,   180,   181,   147,   138,   139,
     140,   141,   142,   138,   139,   140,   141,   142,    32,    33,
     112,   187,   170,   172,    29,    35,   119,   119,   188,   113,
      40,   114,    41,    30,    94,   191,   119,    43,   197,   115,
     185,    94,     7,     8,   186,    71,    94,    94,    73,    74,
      75,    94,   192,   193,    76,    77,    94,   134,     6,     7,
       8,    78,    79,    19,     7,     8,   100,    46,    80,    71,
      49,    72,    73,    74,    75,    51,    81,    50,    76,    77,
     138,   139,   140,   141,   142,    78,    79,    98,    99,   171,
     141,   142,    80,    71,    56,    53,    73,    74,    75,    61,
      81,    64,    76,    77,   138,   139,   140,   141,   142,    78,
      79,   139,   140,   141,   142,    65,    80,    71,   102,   118,
      73,    74,    75,    95,    81,    30,    76,    77,    57,     7,
       8,   100,   103,    78,    79,    69,     7,     8,   104,   105,
      80,   133,    71,   126,   107,    73,    74,    75,    81,   108,
     121,    76,    77,   194,   122,   137,   144,   146,    78,    79,
     149,   151,   158,   159,   160,    80,    71,   175,   182,    73,
      74,    75,   173,    81,   198,    76,    77,   174,   189,   190,
     196,    20,    78,    79,    45,    42,   124,    70,    28,    80,
      71,    55,     0,    73,    74,    75,     0,    81,     0,    76,
      77,     0,     0,     0,     0,     0,    78,    79,     0,     0,
       0,     0,     0,    80,    71,     0,     0,    73,    74,    75,
       0,    81,     0,   132,    77,     0,     0,     0,     0,     0,
      78,    79,   152,   153,   154,   155,     0,    80,   138,   139,
     140,   141,   142,     0,   150,    81,     0,     0,   138,   139,
     140,   141,   142,     0,     0,     0,     0,     0,     0,   156,
     157,   138,   139,   140,   141,   142,     0,   164
};

static const yytype_int16 yycheck[] =
{
      61,    82,   105,    77,     1,    58,    80,    14,     5,    22,
      81,    24,     9,     4,    29,     5,    77,     3,     4,    80,
      17,    82,    24,    25,    63,   106,    53,    17,   109,   100,
      24,    25,   103,     0,    41,    38,    38,    64,     4,    42,
      26,   102,   113,   114,    35,   106,    99,   118,   109,    35,
     121,    37,    38,    37,    51,   126,   159,   160,    97,    45,
      38,    38,    59,   134,    42,    24,    25,   138,   139,   140,
     141,   142,    32,    33,    34,    35,    36,     3,     4,    38,
       4,   152,   153,   154,   155,   156,   157,    47,    32,    33,
      34,    35,    36,    32,    33,    34,    35,    36,    41,    42,
      26,   175,    41,    47,    37,    37,   187,   188,   182,    35,
       3,    37,    46,    46,   175,   186,   197,    39,   192,    45,
      38,   182,    24,    25,    42,     4,   187,   188,     7,     8,
       9,   192,    11,    12,    13,    14,   197,    37,    23,    24,
      25,    20,    21,    23,    24,    25,    46,     4,    27,     4,
      47,     6,     7,     8,     9,    22,    35,     3,    13,    14,
      32,    33,    34,    35,    36,    20,    21,    41,    42,    41,
      35,    36,    27,     4,    47,    39,     7,     8,     9,     5,
      35,    39,    13,    14,    32,    33,    34,    35,    36,    20,
      21,    33,    34,    35,    36,     4,    27,     4,    37,    30,
       7,     8,     9,    40,    35,    46,    13,    14,    23,    24,
      25,    46,    37,    20,    21,    23,    24,    25,    37,    37,
      27,    28,     4,    46,    41,     7,     8,     9,    35,    41,
      31,    13,    14,    15,    40,     4,     6,    40,    20,    21,
      38,    38,    38,    37,    37,    27,     4,    10,    14,     7,
       8,     9,    41,    35,    12,    13,    14,    41,    38,    38,
      41,     9,    20,    21,    35,    33,    99,    59,    17,    27,
       4,    48,    -1,     7,     8,     9,    -1,    35,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    27,     4,    -1,    -1,     7,     8,     9,
      -1,    35,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      20,    21,    16,    17,    18,    19,    -1,    27,    32,    33,
      34,    35,    36,    -1,    38,    35,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    32,    33,    34,    35,    36,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    24,    49,    50,    52,    23,    24,    25,    53,
      54,    55,    29,     0,    24,    50,    55,    65,    66,    23,
      54,     4,    56,    57,    82,    37,     4,    50,    66,    37,
      46,    83,    41,    42,    38,    37,    38,    55,    58,    59,
       3,    46,    57,    39,    38,    58,     4,    38,    42,    47,
       3,    22,    60,    39,    38,    59,    47,    23,    55,    61,
      62,     5,    51,    60,    39,     4,    63,    64,    82,    23,
      62,     4,     6,     7,     8,     9,    13,    14,    20,    21,
      27,    35,    67,    68,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    84,    86,    40,    51,    60,    41,    42,
      46,    85,    37,    37,    37,    37,    67,    41,    41,    67,
       3,     4,    26,    35,    37,    45,    80,    86,    30,    68,
      69,    31,    40,    51,    64,    80,    46,    86,    80,    79,
      80,    79,    13,    28,    37,    80,    80,     4,    32,    33,
      34,    35,    36,    80,     6,    80,    40,    47,    80,    38,
      38,    38,    16,    17,    18,    19,    43,    44,    38,    37,
      37,    38,    80,    81,    38,    80,    80,    80,    80,    80,
      41,    41,    47,    41,    41,    10,    80,    80,    80,    80,
      80,    80,    14,    79,    79,    38,    42,    67,    67,    38,
      38,    80,    11,    12,    15,    41,    41,    67,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    70,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      82,    83,    83,    84,    85,    85,    86,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     8,     4,     2,     3,     2,
       2,     1,     3,     1,     1,     3,     1,     1,     1,     4,
       3,     3,     1,     2,     3,     2,     2,     1,     3,     3,
       1,     1,     1,     2,     1,     9,     8,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     9,
       7,     7,     5,     5,     4,     2,     2,     7,     7,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     4,     1,     1,     1,     3,     1,
       2,     4,     3,     2,     4,     3,     1,     1,     2
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
#line 35 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                      { 
                                                            struct symbol* symbolTable = NULL;
                                                            symbolTable = populateSymbolTable((yyvsp[-2].node),symbolTable,0);
                                                            symbolTable = appendSymbolTable(symbolTable,gsymbolTable);
                                                            typeCheck((yyvsp[-1].node),symbolTable);
                                                            fprintf(out,"L0:\n"); 
                                                            populateParent((yyvsp[-1].node));
                                                            codeGen(out,(yyvsp[-1].node),symbolTable);
                                                        }
#line 1322 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 6: /* Body: BLOCK_BEGIN Slist RetStmt BLOCK_END  */
#line 46 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {
                               (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                               (yyval.node)->label = (yyvsp[-2].node)->label;
                           }
#line 1331 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 7: /* Body: BLOCK_BEGIN BLOCK_END  */
#line 50 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            
                                }
#line 1339 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 8: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 55 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        gsymbolTable = populateSymbolTable((yyvsp[-1].node),gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable(gsymbolTable);
                                    }
#line 1349 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 9: /* GDeclBlock: DECL ENDDECL  */
#line 60 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1355 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 10: /* GDeclList: GDeclList GDecl  */
#line 63 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1363 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 11: /* GDeclList: GDecl  */
#line 66 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1371 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 12: /* GDecl: Type GidList ';'  */
#line 71 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1379 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 14: /* Type: STR  */
#line 78 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {
        (yyval.node) = (yyvsp[0].node);
       }
#line 1387 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* GidList: GidList ',' Gid  */
#line 83 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1395 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 16: /* GidList: Gid  */
#line 86 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1403 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 18: /* Gid: DeclArray  */
#line 93 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1411 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 19: /* Gid: ID '(' ParamList ')'  */
#line 96 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                            }
#line 1420 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 20: /* Gid: ID '(' ')'  */
#line 100 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {  
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-2].node),NULL,NULL,label);
                }
#line 1429 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 21: /* ParamList: ParamList ',' Param  */
#line 106 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            (yyval.node) = createOperatorNode(OP_PARAMLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1437 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 22: /* ParamList: Param  */
#line 109 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1445 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 23: /* Param: Type ID  */
#line 114 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                    (yyval.node) = createOperatorNode(OP_PARAM,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                }
#line 1453 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 120 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1461 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* LDeclBlock: DECL ENDDECL  */
#line 123 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1467 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* LDeclList: LDeclList LDecl  */
#line 126 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1475 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 27: /* LDeclList: LDecl  */
#line 129 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1483 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* LDecl: Type LidList ';'  */
#line 134 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1491 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* LidList: LidList ',' Lid  */
#line 139 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1499 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* LidList: Lid  */
#line 142 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1507 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* Lid: DeclArray  */
#line 149 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1515 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 34: /* FDefBlock: FDef  */
#line 156 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {}
#line 1521 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 159 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                         {
                                                                typeCheckFunctionParam((yyvsp[-8].node)->type,(yyvsp[-7].node)->varName,(yyvsp[-5].node),gsymbolTable);
                                                                struct symbol* symbolTable1 = NULL;
                                                                symbolTable1 = addParamAsSymbol((yyvsp[-7].node)->varName,gsymbolTable,symbolTable1);
                                                                symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
                                                                typeCheck((yyvsp[-1].node),symbolTable1);
                                                                populateParent((yyvsp[-1].node));
                                                                funcCodeGen(out,(yyvsp[-7].node)->varName,(yyvsp[-1].node),symbolTable1);
                                                        }
#line 1536 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* FDef: Type ID '(' ')' '{' LDeclBlock Body '}'  */
#line 169 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {
        typeCheckFunctionParam((yyvsp[-7].node)->type,(yyvsp[-6].node)->varName,NULL,gsymbolTable);
        struct symbol* symbolTable1 = NULL;
        symbolTable1 = addParamAsSymbol((yyvsp[-6].node)->varName,gsymbolTable,symbolTable1);
        symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
        symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
        typeCheck((yyvsp[-1].node),symbolTable1);
        populateParent((yyvsp[-1].node));
        funcCodeGen(out,(yyvsp[-6].node)->varName,(yyvsp[-1].node),symbolTable1);
     }
#line 1551 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 37: /* Slist: Slist Stmt  */
#line 181 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1560 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* Slist: Stmt  */
#line 185 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1568 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 47: /* Stmt: DoWhileStmt  */
#line 199 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1576 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 48: /* RetStmt: RETURN E ';'  */
#line 204 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_RETURN,(yyvsp[-1].node),NULL,NULL,label);
        }
#line 1585 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 49: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF  */
#line 210 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                  { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node),label);
                                                  }
#line 1594 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 50: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF  */
#line 214 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                         {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-4].node),(yyvsp[-1].node),NULL,label);
                                        }
#line 1603 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE  */
#line 221 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                              {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-4].node),(yyvsp[-1].node),NULL,label);
                                                }
#line 1612 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 227 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1621 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 53: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 233 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1630 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 54: /* AsgStmt: Identifier '=' E ';'  */
#line 239 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 1639 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 56: /* ContinueStmt: CONTINUE ';'  */
#line 247 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1647 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 57: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 252 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 1656 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 58: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 258 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 1665 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 59: /* B: E '<' E  */
#line 264 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1673 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 60: /* B: E '>' E  */
#line 267 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1681 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 61: /* B: E GE E  */
#line 270 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1689 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 62: /* B: E LE E  */
#line 273 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1697 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 63: /* B: E NE E  */
#line 276 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1705 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 64: /* B: E EQ E  */
#line 279 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1713 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 65: /* E: E '+' E  */
#line 284 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1721 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 66: /* E: E '*' E  */
#line 287 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1729 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 67: /* E: E '-' E  */
#line 290 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1737 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 68: /* E: E '/' E  */
#line 293 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1745 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 69: /* E: E '%' E  */
#line 296 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1753 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 70: /* E: '&' ID  */
#line 299 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 1761 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 71: /* E: '*' E  */
#line 302 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 1769 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 72: /* E: '(' E ')'  */
#line 305 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 1777 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 73: /* E: ID '(' ')'  */
#line 308 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-2].node),NULL,NULL,-1);
                }
#line 1785 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 74: /* E: ID '(' ArgList ')'  */
#line 311 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                            (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                        }
#line 1793 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 77: /* E: CSTR  */
#line 317 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 1801 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 78: /* ArgList: ArgList ',' E  */
#line 322 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_ARGLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1809 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 79: /* ArgList: E  */
#line 325 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1817 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 80: /* DeclArray: ID DeclBraceList  */
#line 330 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 1825 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 81: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 334 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1833 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 82: /* DeclBraceList: '[' NUM ']'  */
#line 337 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1841 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 83: /* Array: ID BraceList  */
#line 342 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 1849 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 84: /* BraceList: BraceList '[' E ']'  */
#line 346 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1857 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 85: /* BraceList: '[' E ']'  */
#line 349 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1865 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 87: /* Identifier: Array  */
#line 356 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1873 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 88: /* Identifier: '*' E  */
#line 359 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 1881 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 1885 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 364 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"


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
    initCompiler(out);
    fprintf(out,"JMP L0\n");
    yyparse();
    return 0;
}
