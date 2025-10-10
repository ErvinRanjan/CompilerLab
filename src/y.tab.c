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
  YYSYMBOL_STRUCT = 34,                    /* STRUCT  */
  YYSYMBOL_INITIALISE = 35,                /* INITIALISE  */
  YYSYMBOL_FREE = 36,                      /* FREE  */
  YYSYMBOL_ALLOC = 37,                     /* ALLOC  */
  YYSYMBOL_ARROW = 38,                     /* ARROW  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '<'  */
  YYSYMBOL_53_ = 53,                       /* '>'  */
  YYSYMBOL_54_ = 54,                       /* '&'  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_Program = 58,                   /* Program  */
  YYSYMBOL_TypeDeclBlock = 59,             /* TypeDeclBlock  */
  YYSYMBOL_TypeDeclList = 60,              /* TypeDeclList  */
  YYSYMBOL_TypeDecl = 61,                  /* TypeDecl  */
  YYSYMBOL_PartialTypeDecl = 62,           /* PartialTypeDecl  */
  YYSYMBOL_MainBlock = 63,                 /* MainBlock  */
  YYSYMBOL_Body = 64,                      /* Body  */
  YYSYMBOL_GDeclBlock = 65,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 66,                 /* GDeclList  */
  YYSYMBOL_GDecl = 67,                     /* GDecl  */
  YYSYMBOL_Type = 68,                      /* Type  */
  YYSYMBOL_GidList = 69,                   /* GidList  */
  YYSYMBOL_Gid = 70,                       /* Gid  */
  YYSYMBOL_ParamList = 71,                 /* ParamList  */
  YYSYMBOL_Param = 72,                     /* Param  */
  YYSYMBOL_Pid = 73,                       /* Pid  */
  YYSYMBOL_LDeclBlock = 74,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 75,                 /* LDeclList  */
  YYSYMBOL_LDecl = 76,                     /* LDecl  */
  YYSYMBOL_LidList = 77,                   /* LidList  */
  YYSYMBOL_Lid = 78,                       /* Lid  */
  YYSYMBOL_FDefBlock = 79,                 /* FDefBlock  */
  YYSYMBOL_FDef = 80,                      /* FDef  */
  YYSYMBOL_Slist = 81,                     /* Slist  */
  YYSYMBOL_Stmt = 82,                      /* Stmt  */
  YYSYMBOL_AllocStmt = 83,                 /* AllocStmt  */
  YYSYMBOL_InitialiseStmt = 84,            /* InitialiseStmt  */
  YYSYMBOL_FreeStmt = 85,                  /* FreeStmt  */
  YYSYMBOL_RetStmt = 86,                   /* RetStmt  */
  YYSYMBOL_Ifstmt = 87,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 88,                 /* Whilestmt  */
  YYSYMBOL_InputStmt = 89,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 90,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 91,                   /* AsgStmt  */
  YYSYMBOL_BreakStmt = 92,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 93,              /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 94,           /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 95,               /* DoWhileStmt  */
  YYSYMBOL_B = 96,                         /* B  */
  YYSYMBOL_E = 97,                         /* E  */
  YYSYMBOL_ArgList = 98,                   /* ArgList  */
  YYSYMBOL_DeclArray = 99,                 /* DeclArray  */
  YYSYMBOL_DeclBraceList = 100,            /* DeclBraceList  */
  YYSYMBOL_Array = 101,                    /* Array  */
  YYSYMBOL_BraceList = 102,                /* BraceList  */
  YYSYMBOL_Identifier = 103                /* Identifier  */
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
#define YYLAST   525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
       2,     2,     2,     2,     2,     2,     2,    40,    54,     2,
      49,    50,    43,    41,    51,    42,    45,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
      52,    39,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    34,    34,    35,    36,    37,    38,    39,    42,    43,
      48,    49,    52,    58,    64,    76,    80,    85,    90,    93,
      96,   101,   106,   107,   111,   123,   126,   131,   132,   136,
     141,   146,   152,   155,   160,   166,   169,   176,   179,   182,
     185,   190,   195,   198,   203,   204,   208,   214,   215,   219,
     231,   244,   248,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   270,   276,   282,   288,   294,
     298,   305,   311,   317,   323,   329,   330,   336,   342,   348,
     351,   354,   357,   360,   363,   368,   371,   374,   377,   380,
     383,   386,   389,   392,   395,   396,   397,   403,   406,   411,
     417,   420,   425,   430,   433,   438,   439,   443,   446,   449
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
  "MAIN", "RETURN", "TYPEDECL", "ENDTYPEDECL", "TUPLE", "STRUCT",
  "INITIALISE", "FREE", "ALLOC", "ARROW", "'='", "'%'", "'+'", "'-'",
  "'*'", "'/'", "'.'", "'{'", "'}'", "';'", "'('", "')'", "','", "'<'",
  "'>'", "'&'", "'['", "']'", "$accept", "Program", "TypeDeclBlock",
  "TypeDeclList", "TypeDecl", "PartialTypeDecl", "MainBlock", "Body",
  "GDeclBlock", "GDeclList", "GDecl", "Type", "GidList", "Gid",
  "ParamList", "Param", "Pid", "LDeclBlock", "LDeclList", "LDecl",
  "LidList", "Lid", "FDefBlock", "FDef", "Slist", "Stmt", "AllocStmt",
  "InitialiseStmt", "FreeStmt", "RetStmt", "Ifstmt", "Whilestmt",
  "InputStmt", "OutputStmt", "AsgStmt", "BreakStmt", "ContinueStmt",
  "RepeatUntilStmt", "DoWhileStmt", "B", "E", "ArgList", "DeclArray",
  "DeclBraceList", "Array", "BraceList", "Identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,    81,    -5,   -21,    35,   102,  -137,    90,  -137,  -137,
    -137,  -137,    84,  -137,    21,    -1,  -137,    91,    46,    69,
      64,  -137,  -137,    90,    -5,  -137,    40,    90,  -137,  -137,
    -137,    78,    21,    42,  -137,  -137,    86,  -137,  -137,  -137,
     124,  -137,    90,  -137,    40,    68,  -137,  -137,    15,   142,
      95,  -137,  -137,    21,   108,    40,    49,  -137,  -137,  -137,
      22,  -137,    17,    97,   154,  -137,   158,  -137,   146,   124,
     150,   141,  -137,  -137,   133,    98,   204,  -137,  -137,   158,
     182,  -137,  -137,    41,   107,  -137,   234,   180,   204,   158,
     176,    41,    89,  -137,  -137,  -137,  -137,  -137,   103,  -137,
     183,   184,   185,   190,   395,   198,   201,  -137,   395,   202,
     207,    26,    26,   246,   271,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,   480,  -137,
     214,  -137,   210,   204,  -137,  -137,    41,     6,    26,   211,
      26,    26,    26,    26,   420,  -137,  -137,   296,   212,    26,
      54,  -137,   143,  -137,    26,  -137,   253,   260,    26,    26,
      26,    26,    26,   261,    33,  -137,   220,  -137,  -137,   480,
     164,   126,    26,   218,   451,   221,   435,   222,   224,   227,
     233,   232,  -137,   462,  -137,  -137,   157,   181,   181,    54,
      54,  -137,   237,   471,  -137,  -137,    26,  -137,   134,   239,
     241,   280,    26,    26,    26,    26,    26,    26,   279,    26,
      26,  -137,   247,  -137,   244,  -137,   480,  -137,  -137,  -137,
     395,   480,   480,   480,   480,   480,   480,   395,   252,   258,
    -137,   248,   209,   333,     3,   263,  -137,   395,   264,   265,
    -137,  -137,   358,  -137,  -137,   267,  -137
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
      99,    31,    21,     0,     0,     0,     0,    33,     2,    36,
       0,    30,     0,     0,     0,    25,     0,    34,     0,     0,
       0,     0,    29,   101,     0,     0,     0,    12,    32,     0,
       0,   100,    38,     0,     0,    40,     0,     0,     0,     0,
      44,     0,     0,    43,    45,    37,    39,    94,   105,    16,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,    52,    64,    62,    63,    56,
      57,    53,    54,    55,    58,    59,    60,    61,     0,   106,
      95,    14,     0,     0,    46,    41,     0,     0,     0,   102,
       0,     0,     0,     0,     0,    75,    76,     0,     0,     0,
     107,    95,     0,    90,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,    42,    92,    98,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,    95,    91,     0,    15,   109,    89,    85,    87,    86,
      88,   108,     0,     0,    49,    93,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,    68,     0,    74,    97,   103,    72,    73,
       0,    81,    82,    83,    84,    79,    80,     0,     0,     0,
      67,     0,     0,     0,     0,     0,    65,     0,     0,     0,
      78,    77,     0,    70,    71,     0,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,   299,  -137,  -137,    74,   -80,   314,  -137,
     309,     2,  -137,   -12,   -33,   257,   -39,   -46,  -137,   243,
    -137,   -70,   305,    -4,  -102,  -113,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -136,
       1,  -137,   -79,  -137,  -137,  -137,   -86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    18,    19,    20,     6,    87,     7,    12,
      13,    26,    33,    34,    56,    57,    45,    76,    84,    85,
      92,    93,    27,    28,   114,   115,   116,   117,   118,   156,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   175,
     128,   170,    35,    50,   129,   139,   151
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     130,   155,   144,    14,    94,    59,   147,   177,   132,    97,
      98,    16,    94,    17,    14,    62,    67,   227,   130,     8,
      51,   134,   130,    47,    15,    31,     8,    71,   130,    97,
      98,   155,   107,    88,   155,    21,    97,    98,    47,    10,
      11,    65,    55,   133,    43,    90,    10,    11,    36,   111,
      55,   240,   107,   166,   173,   112,   168,    94,   130,   107,
     113,   130,    55,   181,    32,    61,   167,    72,    69,   111,
     192,    55,    70,   228,   229,   112,   111,    83,    38,    22,
     113,    25,   112,    44,    91,     8,    83,   113,     8,     1,
      52,     2,   157,    53,     8,    37,    68,    41,     3,   163,
      69,    46,     8,    17,     9,    10,    11,    29,    10,    11,
      40,     8,   150,   152,    24,    11,    58,    60,   232,   155,
     155,    82,    10,    11,     1,   233,     2,    48,     8,   155,
      95,    10,    11,    49,   130,   242,    54,   135,   169,   171,
     136,   130,   174,   176,   176,    63,   130,   130,    10,    11,
      64,   130,   137,    73,    66,   183,   130,    74,   138,   186,
     187,   188,   189,   190,   157,   193,   158,   159,   160,   161,
     162,   163,   157,   198,   158,   159,   160,   161,   162,   163,
      75,   157,   197,   158,   159,   160,   161,   162,   163,    81,
     217,    80,    69,   182,    77,   157,    79,   216,   159,   160,
     161,   162,   163,   221,   222,   223,   224,   225,   226,    86,
     176,   176,    97,    98,   195,   196,   100,   101,   102,   157,
     237,   238,   103,   104,   161,   162,   163,   131,    89,   105,
     106,    49,   140,   141,   142,   107,   108,    97,    98,   143,
      99,   100,   101,   102,   109,   110,   145,   103,   104,   146,
     153,   148,   111,   164,   105,   106,   149,   165,   112,   184,
     107,   108,   180,   113,   185,   191,   172,   194,   199,   109,
     110,   201,   208,   209,    97,    98,   210,   111,   100,   101,
     102,   211,   212,   112,   103,   104,   214,   218,   113,   219,
     220,   105,   106,   227,   231,   230,   236,   107,   108,    97,
      98,   154,   234,   100,   101,   102,   109,   110,   235,   103,
     104,   241,   243,   244,   111,   246,   105,   106,    39,    23,
     112,    30,   107,   108,   179,   113,    78,    96,    42,     0,
       0,   109,   110,     0,     0,     0,    97,    98,     0,   111,
     100,   101,   102,     0,     0,   112,   103,   104,   239,     0,
     113,     0,     0,   105,   106,     0,     0,     0,     0,   107,
     108,    97,    98,     0,     0,   100,   101,   102,   109,   110,
     245,   103,   104,     0,     0,     0,   111,     0,   105,   106,
       0,     0,   112,     0,   107,   108,     0,   113,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,    97,    98,
       0,   111,   100,   101,   102,     0,     0,   112,   103,   104,
       0,     0,   113,     0,     0,   105,   106,     0,     0,     0,
       0,   107,   108,    97,    98,     0,     0,   100,   101,   102,
     109,   110,     0,   178,   104,     0,     0,     0,   111,     0,
     105,   106,     0,     0,   112,     0,   107,   108,     0,   113,
       0,   202,   203,   204,   205,   109,   110,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,     0,   112,
       0,     0,     0,   157,   113,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,   206,   207,   157,
       0,   158,   159,   160,   161,   162,   163,     0,     0,     0,
     157,   200,   158,   159,   160,   161,   162,   163,     0,   157,
     213,   158,   159,   160,   161,   162,   163,     0,   157,   215,
     158,   159,   160,   161,   162,   163
};

static const yytype_int16 yycheck[] =
{
      86,   114,   104,     1,    83,    44,   108,   143,    88,     3,
       4,    32,    91,    34,    12,    48,    55,    14,   104,     4,
      32,    91,   108,    27,    29,     4,     4,    60,   114,     3,
       4,   144,    26,    79,   147,     0,     3,     4,    42,    24,
      25,    53,    40,    89,     4,     4,    24,    25,    49,    43,
      48,    48,    26,   133,   140,    49,    50,   136,   144,    26,
      54,   147,    60,   149,    43,    50,   136,    50,    51,    43,
      37,    69,    50,   209,   210,    49,    43,    75,    32,     5,
      54,     7,    49,    43,    43,     4,    84,    54,     4,    22,
      48,    24,    38,    51,     4,     4,    47,    23,    31,    45,
      51,    27,     4,    34,    23,    24,    25,    23,    24,    25,
      46,     4,   111,   112,    24,    25,    42,    49,   220,   232,
     233,    23,    24,    25,    22,   227,    24,    49,     4,   242,
      23,    24,    25,    55,   220,   237,    50,    48,   137,   138,
      51,   227,   141,   142,   143,     3,   232,   233,    24,    25,
      55,   237,    49,    56,    46,   154,   242,     3,    55,   158,
     159,   160,   161,   162,    38,   164,    40,    41,    42,    43,
      44,    45,    38,   172,    40,    41,    42,    43,    44,    45,
      22,    38,    56,    40,    41,    42,    43,    44,    45,    56,
      56,    50,    51,    50,    48,    38,    46,   196,    41,    42,
      43,    44,    45,   202,   203,   204,   205,   206,   207,     5,
     209,   210,     3,     4,    50,    51,     7,     8,     9,    38,
      11,    12,    13,    14,    43,    44,    45,    47,    46,    20,
      21,    55,    49,    49,    49,    26,    27,     3,     4,    49,
       6,     7,     8,     9,    35,    36,    48,    13,    14,    48,
       4,    49,    43,    39,    20,    21,    49,    47,    49,     6,
      26,    27,    50,    54,     4,     4,    55,    47,    50,    35,
      36,    50,    50,    49,     3,     4,    49,    43,     7,     8,
       9,    48,    50,    49,    13,    14,    49,    48,    54,    48,
      10,    20,    21,    14,    50,    48,    48,    26,    27,     3,
       4,    30,    50,     7,     8,     9,    35,    36,    50,    13,
      14,    48,    48,    48,    43,    48,    20,    21,    19,     5,
      49,    12,    26,    27,    28,    54,    69,    84,    23,    -1,
      -1,    35,    36,    -1,    -1,    -1,     3,     4,    -1,    43,
       7,     8,     9,    -1,    -1,    49,    13,    14,    15,    -1,
      54,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,
      27,     3,     4,    -1,    -1,     7,     8,     9,    35,    36,
      12,    13,    14,    -1,    -1,    -1,    43,    -1,    20,    21,
      -1,    -1,    49,    -1,    26,    27,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,     3,     4,
      -1,    43,     7,     8,     9,    -1,    -1,    49,    13,    14,
      -1,    -1,    54,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    26,    27,     3,     4,    -1,    -1,     7,     8,     9,
      35,    36,    -1,    13,    14,    -1,    -1,    -1,    43,    -1,
      20,    21,    -1,    -1,    49,    -1,    26,    27,    -1,    54,
      -1,    16,    17,    18,    19,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    38,    54,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    38,
      -1,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      38,    50,    40,    41,    42,    43,    44,    45,    -1,    38,
      48,    40,    41,    42,    43,    44,    45,    -1,    38,    48,
      40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    24,    31,    58,    59,    63,    65,     4,    23,
      24,    25,    66,    67,    68,    29,    32,    34,    60,    61,
      62,     0,    63,    65,    24,    63,    68,    79,    80,    23,
      67,     4,    43,    69,    70,    99,    49,     4,    32,    60,
      46,    63,    79,     4,    43,    73,    63,    80,    49,    55,
     100,    70,    48,    51,    50,    68,    71,    72,    63,    73,
      49,    50,    71,     3,    55,    70,    46,    73,    47,    51,
      50,    71,    50,    56,     3,    22,    74,    48,    72,    46,
      50,    56,    23,    68,    75,    76,     5,    64,    74,    46,
       4,    43,    77,    78,    99,    23,    76,     3,     4,     6,
       7,     8,     9,    13,    14,    20,    21,    26,    27,    35,
      36,    43,    49,    54,    81,    82,    83,    84,    85,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    97,   101,
     103,    47,    64,    74,    78,    48,    51,    49,    55,   102,
      49,    49,    49,    49,    81,    48,    48,    81,    49,    49,
      97,   103,    97,     4,    30,    82,    86,    38,    40,    41,
      42,    43,    44,    45,    39,    47,    64,    78,    50,    97,
      98,    97,    55,   103,    97,    96,    97,    96,    13,    28,
      50,   103,    50,    97,     6,     4,    97,    97,    97,    97,
      97,     4,    37,    97,    47,    50,    51,    56,    97,    50,
      50,    50,    16,    17,    18,    19,    52,    53,    50,    49,
      49,    48,    50,    48,    49,    48,    97,    56,    48,    48,
      10,    97,    97,    97,    97,    97,    97,    14,    96,    96,
      48,    50,    81,    81,    50,    50,    48,    11,    12,    15,
      48,    48,    81,    48,    48,    12,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    63,    64,    64,    65,    65,    66,
      66,    67,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    71,    71,    72,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    84,    85,    86,    87,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
     100,   100,   101,   102,   102,   103,   103,   103,   103,   103
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
       1,     1,     1,     1,     1,     6,     4,     5,     3,    10,
       8,     8,     5,     5,     4,     2,     2,     7,     7,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     4,     1,     1,     1,     3,     1,     2,
       4,     3,     2,     4,     3,     1,     1,     2,     3,     3
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
#line 42 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                     {}
#line 1397 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 9: /* TypeDeclBlock: TYPEDECL TypeDeclList ENDTYPEDECL  */
#line 43 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                  {
                printTypeTable();
              }
#line 1405 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 10: /* TypeDeclList: TypeDecl TypeDeclList  */
#line 48 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                     {}
#line 1411 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 11: /* TypeDeclList: TypeDecl  */
#line 49 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {}
#line 1417 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 12: /* TypeDecl: PartialTypeDecl '{' ParamList '}' ';'  */
#line 52 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {
                int numberOfParam = 0;
                updateTypeTable((yyvsp[-4].node)->varName,convertTreeToParamList((yyvsp[-2].node),&numberOfParam,NULL));
            }
#line 1426 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 13: /* PartialTypeDecl: STRUCT ID  */
#line 58 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                        populateTypeTable((yyvsp[0].node)->varName,NULL);
                        (yyval.node) = (yyvsp[0].node);
            }
#line 1435 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 14: /* MainBlock: INT MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 64 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1450 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* Body: BLOCK_BEGIN Slist RetStmt BLOCK_END  */
#line 76 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {
                               (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                               (yyval.node)->label = (yyvsp[-2].node)->label;
                           }
#line 1459 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 16: /* Body: BLOCK_BEGIN BLOCK_END  */
#line 80 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            
                                }
#line 1467 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 17: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 85 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        gsymbolTable = populateSymbolTable((yyvsp[-1].node),gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable("global",gsymbolTable);
                                    }
#line 1477 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 18: /* GDeclBlock: DECL ENDDECL  */
#line 90 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1483 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 19: /* GDeclList: GDeclList GDecl  */
#line 93 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1491 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 20: /* GDeclList: GDecl  */
#line 96 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1499 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 21: /* GDecl: Type GidList ';'  */
#line 101 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1507 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 23: /* Type: STR  */
#line 108 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
     {
        (yyval.node) = (yyvsp[0].node);
     }
#line 1515 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* Type: ID  */
#line 112 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {
        struct typeTable* type = getTypeTableWithName((yyvsp[0].node)->varName);
        if(type == NULL){
            printf("Error: type is used but not declared: %s\n",(yyvsp[0].node)->varName);
            exit(EXIT_FAILURE);
        }
        (yyvsp[0].node)->type = createUserDefinedTypeWithName((yyvsp[0].node)->varName);
        (yyval.node) = (yyvsp[0].node);
       }
#line 1529 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* GidList: GidList ',' Gid  */
#line 123 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1537 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* GidList: Gid  */
#line 126 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1545 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* Gid: DeclArray  */
#line 133 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1553 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* Gid: ID '(' ParamList ')'  */
#line 136 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                                (yyval.node)->type = (yyvsp[-3].node)->type;
                            }
#line 1563 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* Gid: ID '(' ')'  */
#line 141 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {  
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-2].node),NULL,NULL,label);
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1573 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 31: /* Gid: '*' Gid  */
#line 146 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                    (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1582 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* ParamList: ParamList ',' Param  */
#line 152 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            (yyval.node) = createOperatorNode(OP_PARAMLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1590 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 33: /* ParamList: Param  */
#line 155 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1598 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 34: /* Param: Type Pid  */
#line 160 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = createOperatorNode(OP_PARAM,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    (yyval.node)->type = (yyvsp[0].node)->type;
                }
#line 1607 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* Pid: ID  */
#line 166 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
         {
            (yyval.node) = (yyvsp[0].node);
            }
#line 1615 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* Pid: '*' Pid  */
#line 169 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
            (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
            (yyval.node) = (yyvsp[0].node); 
        }
#line 1624 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 37: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 176 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1632 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* LDeclBlock: DECL ENDDECL  */
#line 179 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1638 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 39: /* LDeclList: LDeclList LDecl  */
#line 182 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1646 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 40: /* LDeclList: LDecl  */
#line 185 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1654 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 41: /* LDecl: Type LidList ';'  */
#line 190 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1662 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 42: /* LidList: LidList ',' Lid  */
#line 195 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1670 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 43: /* LidList: Lid  */
#line 198 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1678 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 45: /* Lid: DeclArray  */
#line 205 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1686 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 46: /* Lid: '*' Lid  */
#line 208 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
        (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1695 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 48: /* FDefBlock: FDef  */
#line 216 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {}
#line 1701 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 49: /* FDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 219 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1718 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 50: /* FDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 231 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1734 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* Slist: Slist Stmt  */
#line 244 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1743 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* Slist: Stmt  */
#line 248 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1751 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 64: /* Stmt: AllocStmt  */
#line 265 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1759 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 65: /* AllocStmt: Identifier '=' ALLOC '(' ')' ';'  */
#line 270 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                             {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_ALLOC,(yyvsp[-5].node),NULL,NULL,label);
}
#line 1768 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 66: /* InitialiseStmt: INITIALISE '(' ')' ';'  */
#line 276 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_INITIALISE,NULL,NULL,NULL,label);
}
#line 1777 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 67: /* FreeStmt: FREE '(' Identifier ')' ';'  */
#line 282 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                       {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_FREE,(yyvsp[-2].node),NULL,NULL,label);
}
#line 1786 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 68: /* RetStmt: RETURN E ';'  */
#line 288 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_RETURN,(yyvsp[-1].node),NULL,NULL,label);
        }
#line 1795 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 69: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 294 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                     { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node),label);
                                                  }
#line 1804 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 70: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF ';'  */
#line 298 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                        }
#line 1813 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 71: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE ';'  */
#line 305 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                                }
#line 1822 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 72: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 311 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1831 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 73: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 317 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1840 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 74: /* AsgStmt: Identifier '=' E ';'  */
#line 323 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 1849 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 76: /* ContinueStmt: CONTINUE ';'  */
#line 331 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1857 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 77: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 336 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 1866 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 78: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 342 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 1875 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 79: /* B: E '<' E  */
#line 348 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1883 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 80: /* B: E '>' E  */
#line 351 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1891 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 81: /* B: E GE E  */
#line 354 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1899 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 82: /* B: E LE E  */
#line 357 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1907 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 83: /* B: E NE E  */
#line 360 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1915 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 84: /* B: E EQ E  */
#line 363 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1923 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 85: /* E: E '+' E  */
#line 368 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1931 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 86: /* E: E '*' E  */
#line 371 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1939 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 87: /* E: E '-' E  */
#line 374 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1947 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 88: /* E: E '/' E  */
#line 377 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1955 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 89: /* E: E '%' E  */
#line 380 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1963 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 90: /* E: '&' ID  */
#line 383 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 1971 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 91: /* E: '(' E ')'  */
#line 386 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 1979 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 92: /* E: ID '(' ')'  */
#line 389 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-2].node),NULL,NULL,-1);
                }
#line 1987 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 93: /* E: ID '(' ArgList ')'  */
#line 392 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                            (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                        }
#line 1995 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 96: /* E: CSTR  */
#line 398 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 2003 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 97: /* ArgList: ArgList ',' E  */
#line 403 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_ARGLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 2011 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 98: /* ArgList: E  */
#line 406 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2019 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 99: /* DeclArray: ID DeclBraceList  */
#line 411 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1); 
                        (yyval.node)->type = (yyvsp[-1].node)->type;
                    }
#line 2028 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 100: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 417 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 2036 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 101: /* DeclBraceList: '[' NUM ']'  */
#line 420 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2044 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 102: /* Array: ID BraceList  */
#line 425 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 2052 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 103: /* BraceList: BraceList '[' E ']'  */
#line 430 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 2060 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 104: /* BraceList: '[' E ']'  */
#line 433 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2068 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 106: /* Identifier: Array  */
#line 440 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2076 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 107: /* Identifier: '*' E  */
#line 443 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 2084 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 108: /* Identifier: E '.' ID  */
#line 446 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2092 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 109: /* Identifier: E ARROW ID  */
#line 449 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-2].node),NULL,NULL,-1);
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,temp,(yyvsp[0].node),NULL,-1);
            }
#line 2101 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 2105 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 455 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"


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
