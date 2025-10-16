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
#line 1 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"

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
    int latestClassIndex = 0;

#line 90 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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
  YYSYMBOL_CLASS = 39,                     /* CLASS  */
  YYSYMBOL_SELF = 40,                      /* SELF  */
  YYSYMBOL_NEW = 41,                       /* NEW  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* '%'  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_48_ = 48,                       /* '.'  */
  YYSYMBOL_49_ = 49,                       /* '}'  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '<'  */
  YYSYMBOL_56_ = 56,                       /* '>'  */
  YYSYMBOL_57_ = 57,                       /* '&'  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_ClassDeclBlock = 62,            /* ClassDeclBlock  */
  YYSYMBOL_ClassDeclList = 63,             /* ClassDeclList  */
  YYSYMBOL_ClassDecl = 64,                 /* ClassDecl  */
  YYSYMBOL_LeftClassDecl = 65,             /* LeftClassDecl  */
  YYSYMBOL_PartialLeftClassDecl = 66,      /* PartialLeftClassDecl  */
  YYSYMBOL_ClassGDeclBlock = 67,           /* ClassGDeclBlock  */
  YYSYMBOL_MethodDefBlock = 68,            /* MethodDefBlock  */
  YYSYMBOL_MethodDef = 69,                 /* MethodDef  */
  YYSYMBOL_TypeDeclBlock = 70,             /* TypeDeclBlock  */
  YYSYMBOL_TypeDeclList = 71,              /* TypeDeclList  */
  YYSYMBOL_TypeDecl = 72,                  /* TypeDecl  */
  YYSYMBOL_PartialTypeDecl = 73,           /* PartialTypeDecl  */
  YYSYMBOL_MainBlock = 74,                 /* MainBlock  */
  YYSYMBOL_Body = 75,                      /* Body  */
  YYSYMBOL_GDeclBlock = 76,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 77,                 /* GDeclList  */
  YYSYMBOL_GDecl = 78,                     /* GDecl  */
  YYSYMBOL_Type = 79,                      /* Type  */
  YYSYMBOL_GidList = 80,                   /* GidList  */
  YYSYMBOL_Gid = 81,                       /* Gid  */
  YYSYMBOL_ParamList = 82,                 /* ParamList  */
  YYSYMBOL_Param = 83,                     /* Param  */
  YYSYMBOL_Pid = 84,                       /* Pid  */
  YYSYMBOL_LDeclBlock = 85,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 86,                 /* LDeclList  */
  YYSYMBOL_LDecl = 87,                     /* LDecl  */
  YYSYMBOL_LidList = 88,                   /* LidList  */
  YYSYMBOL_Lid = 89,                       /* Lid  */
  YYSYMBOL_FDefBlock = 90,                 /* FDefBlock  */
  YYSYMBOL_FDef = 91,                      /* FDef  */
  YYSYMBOL_Slist = 92,                     /* Slist  */
  YYSYMBOL_Stmt = 93,                      /* Stmt  */
  YYSYMBOL_AllocStmt = 94,                 /* AllocStmt  */
  YYSYMBOL_NewStmt = 95,                   /* NewStmt  */
  YYSYMBOL_InitialiseStmt = 96,            /* InitialiseStmt  */
  YYSYMBOL_FreeStmt = 97,                  /* FreeStmt  */
  YYSYMBOL_RetStmt = 98,                   /* RetStmt  */
  YYSYMBOL_Ifstmt = 99,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 100,                /* Whilestmt  */
  YYSYMBOL_InputStmt = 101,                /* InputStmt  */
  YYSYMBOL_OutputStmt = 102,               /* OutputStmt  */
  YYSYMBOL_AsgStmt = 103,                  /* AsgStmt  */
  YYSYMBOL_BreakStmt = 104,                /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 105,             /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 106,          /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 107,              /* DoWhileStmt  */
  YYSYMBOL_B = 108,                        /* B  */
  YYSYMBOL_E = 109,                        /* E  */
  YYSYMBOL_ArgList = 110,                  /* ArgList  */
  YYSYMBOL_DeclArray = 111,                /* DeclArray  */
  YYSYMBOL_DeclBraceList = 112,            /* DeclBraceList  */
  YYSYMBOL_Array = 113,                    /* Array  */
  YYSYMBOL_BraceList = 114,                /* BraceList  */
  YYSYMBOL_Identifier = 115                /* Identifier  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

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
       2,     2,     2,     2,     2,     2,     2,    43,    57,     2,
      51,    52,    46,    44,    54,    45,    48,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
      55,    42,    56,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    49,     2,     2,     2,     2,
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
       0,    35,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    49,    52,    53,    56,    57,    60,
      67,    73,    74,    79,    80,    83,    97,   112,   113,   118,
     119,   122,   128,   134,   146,   151,   154,   157,   163,   166,
     169,   174,   179,   180,   184,   196,   199,   204,   205,   209,
     214,   219,   225,   228,   233,   239,   242,   249,   252,   255,
     258,   263,   268,   271,   276,   277,   281,   287,   288,   292,
     304,   317,   321,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   344,   350,   356,   362,
     368,   374,   378,   385,   391,   397,   403,   409,   410,   416,
     422,   428,   431,   434,   437,   440,   443,   448,   451,   454,
     457,   460,   463,   466,   469,   472,   475,   478,   481,   485,
     489,   490,   491,   497,   500,   505,   511,   514,   519,   524,
     527,   532,   533,   534,   538,   541,   544
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
  "INITIALISE", "FREE", "ALLOC", "ARROW", "CLASS", "SELF", "NEW", "'='",
  "'%'", "'+'", "'-'", "'*'", "'/'", "'.'", "'}'", "'{'", "'('", "')'",
  "';'", "','", "'<'", "'>'", "'&'", "'['", "']'", "$accept", "Program",
  "ClassDeclBlock", "ClassDeclList", "ClassDecl", "LeftClassDecl",
  "PartialLeftClassDecl", "ClassGDeclBlock", "MethodDefBlock", "MethodDef",
  "TypeDeclBlock", "TypeDeclList", "TypeDecl", "PartialTypeDecl",
  "MainBlock", "Body", "GDeclBlock", "GDeclList", "GDecl", "Type",
  "GidList", "Gid", "ParamList", "Param", "Pid", "LDeclBlock", "LDeclList",
  "LDecl", "LidList", "Lid", "FDefBlock", "FDef", "Slist", "Stmt",
  "AllocStmt", "NewStmt", "InitialiseStmt", "FreeStmt", "RetStmt",
  "Ifstmt", "Whilestmt", "InputStmt", "OutputStmt", "AsgStmt", "BreakStmt",
  "ContinueStmt", "RepeatUntilStmt", "DoWhileStmt", "B", "E", "ArgList",
  "DeclArray", "DeclBraceList", "Array", "BraceList", "Identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-180)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     268,   217,   -12,   -21,    27,    87,    15,   -25,  -180,     2,
      66,    82,  -180,   144,  -180,  -180,  -180,  -180,   348,  -180,
      25,    57,  -180,   130,   127,   117,   135,  -180,  -180,  -180,
     144,  -180,  -180,   213,  -180,    29,   166,    15,  -180,   144,
     -12,  -180,    29,   144,  -180,  -180,  -180,    33,    25,   119,
    -180,  -180,   143,  -180,  -180,  -180,   154,  -180,   144,  -180,
    -180,  -180,    29,   148,   371,  -180,  -180,   144,  -180,   144,
     172,  -180,  -180,    18,   224,   175,  -180,  -180,    25,   186,
      29,   133,  -180,  -180,  -180,   111,  -180,   383,  -180,   144,
    -180,   207,  -180,    58,   187,   255,  -180,   252,  -180,   226,
     154,   235,    79,  -180,  -180,   239,   170,  -180,  -180,   234,
     417,   297,  -180,  -180,   252,   256,   252,   258,  -180,  -180,
      32,   459,  -180,   199,   264,   297,   252,   297,   252,   265,
      32,   211,  -180,  -180,  -180,  -180,  -180,    95,  -180,   273,
     275,   276,   279,   411,   280,   305,  -180,   411,   114,   296,
     309,  -180,   114,   114,   357,   274,  -180,  -180,  -180,  -180,
    -180,   358,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,   518,  -180,   324,  -180,   318,   297,   321,   297,  -180,
    -180,    32,     4,   114,   316,   114,   114,   114,   114,   445,
    -180,  -180,   308,   474,  -180,   327,   114,    -3,   496,  -180,
    -180,   370,  -180,   379,   114,   114,   114,   114,   114,   401,
      56,  -180,   360,  -180,   361,  -180,  -180,   518,   203,   225,
     114,   359,   507,   364,   460,   374,   376,   378,  -180,   369,
     381,  -180,  -180,   384,   529,   354,   354,    -3,    -3,   385,
     388,   392,   485,  -180,  -180,  -180,   114,  -180,   294,   391,
     397,   420,   114,   114,   114,   114,   114,   114,   431,   114,
     114,  -180,   402,   124,   158,   404,   456,  -180,   518,  -180,
    -180,  -180,   411,   518,   518,   518,   518,   518,   518,   411,
     409,   412,  -180,  -180,   244,  -180,   251,   414,   418,   240,
     342,    14,   416,  -180,  -180,  -180,   421,   411,   422,   433,
    -180,  -180,  -180,   377,  -180,  -180,   434,  -180
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    14,    16,     0,
       0,     0,    13,     0,    44,    38,    42,    43,     0,    40,
       0,     0,    27,     0,     0,    30,     0,    20,     1,     7,
       0,    15,    18,     0,    24,     0,     0,     0,    10,     0,
      42,    12,     0,     0,    68,    37,    39,    47,     0,     0,
      46,    48,     0,    32,    28,    29,     0,     6,     0,    17,
      23,    55,     0,     0,     0,    19,     4,     0,     9,     0,
       0,    11,    67,     0,     0,   125,    51,    41,     0,     0,
       0,     0,    53,     5,    56,     0,    21,     0,     3,     0,
       8,     0,    50,     0,     0,     0,    45,     0,    54,     0,
       0,     0,     0,    22,     2,     0,     0,    49,   127,     0,
       0,     0,    31,    52,     0,     0,     0,     0,   126,    58,
       0,     0,    60,     0,     0,     0,     0,     0,     0,    64,
       0,     0,    63,    65,    57,    59,   120,   131,    36,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,     0,
       0,   133,     0,     0,     0,     0,    72,    84,    85,    82,
      83,     0,    76,    77,    73,    74,    75,    78,    79,    80,
      81,     0,   132,   121,    33,     0,     0,     0,     0,    66,
      61,     0,     0,     0,   128,     0,     0,     0,     0,     0,
      97,    98,     0,     0,   121,     0,     0,   134,     0,   112,
      71,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    70,     0,    62,   114,   124,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,    90,     0,
     121,   113,    34,   136,   111,   107,   109,   108,   110,   135,
       0,     0,     0,    25,    69,   115,     0,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,    96,   123,   129,
      94,    95,     0,   103,   104,   105,   106,   101,   102,     0,
       0,     0,    89,   118,     0,   116,     0,     0,     0,     0,
       0,     0,     0,   119,   117,    86,     0,     0,     0,     0,
     100,    99,    87,     0,    92,    93,     0,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,   462,  -180,   481,  -180,  -180,  -180,  -180,   457,
    -180,   464,  -180,  -180,    10,   -73,    89,   428,   -15,     1,
    -180,   -30,   -27,   393,    52,   102,  -180,   373,  -180,  -118,
     147,    40,  -142,  -151,  -180,  -180,  -180,  -180,   340,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -179,   -63,
      55,  -105,  -180,  -180,  -180,  -123
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    10,    65,    33,    34,
      11,    24,    25,    26,    12,   124,    13,    18,    19,    42,
      49,    50,    81,    82,    63,   111,   121,   122,   131,   132,
      43,    44,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   223,   171,
     218,    51,    75,   172,   184,   194
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     173,   189,    20,    46,   200,   192,    14,   136,   137,   225,
      35,    22,   179,    23,     4,   133,    29,    21,    76,    20,
     173,    38,    14,    41,   173,   133,    16,    17,   279,    47,
     146,    27,   173,    61,    35,   203,   129,     1,   200,     2,
      57,   200,    16,    17,   151,   209,    93,    66,    96,    68,
     152,    32,   175,    71,   177,   153,   216,    80,   102,   136,
     137,   154,   221,   215,   106,    20,   173,   300,    83,   173,
      92,    48,    46,   230,    80,    62,   133,    88,   130,    90,
     280,   281,   146,    72,    73,   193,    80,    28,    20,   197,
     198,    74,    80,   240,    70,    30,   151,   241,    72,   104,
      39,    80,   152,   212,     1,   214,     2,   153,    52,    72,
     107,   120,   100,   154,    84,    14,    36,   136,   137,   217,
     219,     4,   120,   222,   224,   224,    67,   136,   137,    72,
     289,   115,    98,   100,    53,    16,    17,   290,   200,   200,
     146,   234,   235,   236,   237,   238,   182,   242,    14,   173,
     146,    23,   200,   183,   151,   303,   173,   248,    14,    54,
     152,   136,   137,   101,   151,   153,   173,   173,    40,    17,
     152,   154,    77,    78,   173,   153,   283,    58,    16,    17,
     173,   154,    99,   268,   146,    56,    69,   100,    64,   273,
     274,   275,   276,   277,   278,    79,   224,   224,   151,    85,
     217,   217,   136,   137,   152,   138,   139,   140,   141,   153,
     285,    14,   142,   143,    89,   154,   125,    14,   127,   144,
     145,    14,   117,    91,   100,   146,   147,    94,   176,   148,
     178,    16,    17,    95,   149,   150,    97,    16,    17,   151,
      15,    16,    17,   136,   137,   152,   108,   139,   140,   141,
     153,   297,   298,   142,   143,   245,   154,   246,   109,   105,
     144,   145,    59,   203,   180,   181,   146,   147,   204,   205,
     206,   207,   208,   209,   110,   149,   150,   136,   137,   112,
     151,   139,   140,   141,   247,   114,   152,   142,   143,   116,
       1,   153,     2,   118,   144,   145,   293,   154,   246,     3,
     146,   147,   123,   294,   148,   246,   126,     4,   128,   149,
     150,   136,   137,   174,   151,   139,   140,   141,   284,   286,
     152,   142,   143,    74,   185,   153,   186,   187,   144,   145,
     188,   154,   203,   190,   146,   147,   227,   204,   205,   206,
     207,   208,   209,   149,   150,   136,   137,   195,   151,   139,
     140,   141,    14,   269,   152,   142,   143,   299,   191,   153,
     196,   199,   144,   145,   202,   154,   210,   211,   146,   147,
     213,    45,    16,    17,   220,    14,   232,   149,   150,   229,
     136,   137,   151,   233,   139,   140,   141,    14,   152,   306,
     142,   143,   203,   153,    86,    16,    17,   144,   145,   154,
     207,   208,   209,   146,   147,   239,   103,    16,    17,   243,
     244,   249,   149,   150,   136,   137,   251,   151,   139,   140,
     141,    14,   261,   152,   142,   143,   258,   259,   153,   260,
     272,   144,   145,   262,   154,   263,   264,   146,   147,   265,
     119,    16,    17,   266,   270,   279,   149,   150,   136,   137,
     271,   151,   139,   140,   141,   282,   287,   152,   226,   143,
     288,   291,   153,    14,   292,   144,   145,   295,   154,   301,
     296,   146,   147,    37,   302,   304,   252,   253,   254,   255,
     149,   150,   134,    16,    17,   151,   305,   307,    31,    55,
      60,   152,    87,   113,   135,   201,   153,     0,   203,     0,
       0,     0,   154,   204,   205,   206,   207,   208,   209,     0,
       0,     0,   203,     0,     0,   256,   257,   204,   205,   206,
     207,   208,   209,   203,     0,     0,     0,   228,   204,   205,
     206,   207,   208,   209,   203,     0,     0,     0,   267,   204,
     205,   206,   207,   208,   209,   203,     0,     0,   231,     0,
     204,   205,   206,   207,   208,   209,   203,     0,     0,   250,
       0,   204,   205,   206,   207,   208,   209,   203,     0,     0,
       0,     0,     0,   205,   206,   207,   208,   209
};

static const yytype_int16 yycheck[] =
{
     123,   143,     1,    18,   155,   147,     4,     3,     4,   188,
       9,    32,   130,    34,    39,   120,     6,    29,    48,    18,
     143,    11,     4,    13,   147,   130,    24,    25,    14,     4,
      26,     4,   155,     4,    33,    38,     4,    22,   189,    24,
      30,   192,    24,    25,    40,    48,    73,    37,    78,    39,
      46,    49,   125,    43,   127,    51,    52,    56,    85,     3,
       4,    57,   185,   181,    91,    64,   189,    53,    58,   192,
      52,    46,    87,   196,    73,    46,   181,    67,    46,    69,
     259,   260,    26,    43,    51,   148,    85,     0,    87,   152,
     153,    58,    91,    37,    42,     6,    40,    41,    58,    89,
      11,   100,    46,   176,    22,   178,    24,    51,    51,    69,
      52,   110,    54,    57,    62,     4,    50,     3,     4,   182,
     183,    39,   121,   186,   187,   188,    37,     3,     4,    89,
     272,    52,    80,    54,     4,    24,    25,   279,   289,   290,
      26,   204,   205,   206,   207,   208,    51,   210,     4,   272,
      26,    34,   303,    58,    40,   297,   279,   220,     4,    32,
      46,     3,     4,    52,    40,    51,   289,   290,    24,    25,
      46,    57,    53,    54,   297,    51,    52,    30,    24,    25,
     303,    57,    49,   246,    26,    50,    39,    54,    22,   252,
     253,   254,   255,   256,   257,    52,   259,   260,    40,    51,
     263,   264,     3,     4,    46,     6,     7,     8,     9,    51,
      52,     4,    13,    14,    67,    57,   114,     4,   116,    20,
      21,     4,    52,    51,    54,    26,    27,     3,   126,    30,
     128,    24,    25,    58,    35,    36,    50,    24,    25,    40,
      23,    24,    25,     3,     4,    46,    59,     7,     8,     9,
      51,    11,    12,    13,    14,    52,    57,    54,     3,    52,
      20,    21,    49,    38,    53,    54,    26,    27,    43,    44,
      45,    46,    47,    48,    22,    35,    36,     3,     4,    53,
      40,     7,     8,     9,    59,    50,    46,    13,    14,    50,
      22,    51,    24,    59,    20,    21,    52,    57,    54,    31,
      26,    27,     5,    52,    30,    54,    50,    39,    50,    35,
      36,     3,     4,    49,    40,     7,     8,     9,   263,   264,
      46,    13,    14,    58,    51,    51,    51,    51,    20,    21,
      51,    57,    38,    53,    26,    27,    28,    43,    44,    45,
      46,    47,    48,    35,    36,     3,     4,    51,    40,     7,
       8,     9,     4,    59,    46,    13,    14,    15,    53,    51,
      51,     4,    20,    21,     6,    57,    42,    49,    26,    27,
      49,    23,    24,    25,    58,     4,     6,    35,    36,    52,
       3,     4,    40,     4,     7,     8,     9,     4,    46,    12,
      13,    14,    38,    51,    23,    24,    25,    20,    21,    57,
      46,    47,    48,    26,    27,     4,    23,    24,    25,    49,
      49,    52,    35,    36,     3,     4,    52,    40,     7,     8,
       9,     4,    53,    46,    13,    14,    52,    51,    51,    51,
      10,    20,    21,    52,    57,    51,    51,    26,    27,    51,
      23,    24,    25,    51,    53,    14,    35,    36,     3,     4,
      53,    40,     7,     8,     9,    53,    52,    46,    13,    14,
       4,    52,    51,     4,    52,    20,    21,    53,    57,    53,
      52,    26,    27,    11,    53,    53,    16,    17,    18,    19,
      35,    36,    23,    24,    25,    40,    53,    53,     7,    25,
      33,    46,    64,   100,   121,   155,    51,    -1,    38,    -1,
      -1,    -1,    57,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    38,    -1,    -1,    55,    56,    43,    44,    45,
      46,    47,    48,    38,    -1,    -1,    -1,    53,    43,    44,
      45,    46,    47,    48,    38,    -1,    -1,    -1,    53,    43,
      44,    45,    46,    47,    48,    38,    -1,    -1,    52,    -1,
      43,    44,    45,    46,    47,    48,    38,    -1,    -1,    52,
      -1,    43,    44,    45,    46,    47,    48,    38,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    24,    31,    39,    61,    62,    63,    64,    65,
      66,    70,    74,    76,     4,    23,    24,    25,    77,    78,
      79,    29,    32,    34,    71,    72,    73,     4,     0,    74,
      76,    64,    49,    68,    69,    79,    50,    62,    74,    76,
      24,    74,    79,    90,    91,    23,    78,     4,    46,    80,
      81,   111,    51,     4,    32,    71,    50,    74,    90,    49,
      69,     4,    46,    84,    22,    67,    74,    76,    74,    90,
      84,    74,    91,    51,    58,   112,    81,    53,    54,    52,
      79,    82,    83,    74,    84,    51,    23,    77,    74,    90,
      74,    51,    52,    82,     3,    58,    81,    50,    84,    49,
      54,    52,    82,    23,    74,    52,    82,    52,    59,     3,
      22,    85,    53,    83,    50,    52,    50,    52,    59,    23,
      79,    86,    87,     5,    75,    85,    50,    85,    50,     4,
      46,    88,    89,   111,    23,    87,     3,     4,     6,     7,
       8,     9,    13,    14,    20,    21,    26,    27,    30,    35,
      36,    40,    46,    51,    57,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   109,   113,   115,    49,    75,    85,    75,    85,    89,
      53,    54,    51,    58,   114,    51,    51,    51,    51,    92,
      53,    53,    92,   109,   115,    51,    51,   109,   109,     4,
      93,    98,     6,    38,    43,    44,    45,    46,    47,    48,
      42,    49,    75,    49,    75,    89,    52,   109,   110,   109,
      58,   115,   109,   108,   109,   108,    13,    28,    53,    52,
     115,    52,     6,     4,   109,   109,   109,   109,   109,     4,
      37,    41,   109,    49,    49,    52,    54,    59,   109,    52,
      52,    52,    16,    17,    18,    19,    55,    56,    52,    51,
      51,    53,    52,    51,    51,    51,    51,    53,   109,    59,
      53,    53,    10,   109,   109,   109,   109,   109,   109,    14,
     108,   108,    53,    52,   110,    52,   110,    52,     4,    92,
      92,    52,    52,    52,    52,    53,    52,    11,    12,    15,
      53,    53,    53,    92,    53,    53,    12,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    64,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    73,    74,    75,    75,    75,    76,    76,    77,
      77,    78,    79,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    83,    84,    84,    85,    85,    86,
      86,    87,    88,    88,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    95,    96,    97,
      98,    99,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   112,   112,   113,   114,
     114,   115,   115,   115,   115,   115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     4,     3,     2,     4,     3,
       2,     3,     2,     1,     1,     2,     1,     3,     2,     3,
       2,     2,     3,     2,     1,     9,     8,     2,     3,     2,
       1,     5,     2,     8,     4,     3,     2,     3,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       3,     2,     3,     1,     2,     1,     2,     3,     2,     2,
       1,     3,     3,     1,     1,     1,     2,     2,     1,     9,
       8,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     7,     4,     5,
       3,    10,     8,     8,     5,     5,     4,     2,     2,     7,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     4,     5,     6,     5,     6,
       1,     1,     1,     3,     1,     2,     4,     3,     2,     4,
       3,     1,     1,     1,     2,     3,     3
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
  case 14: /* ClassDeclBlock: ClassDeclList  */
#line 49 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                               { printClassTable(); }
#line 1451 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* ClassDeclList: ClassDeclList ClassDecl  */
#line 52 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                        {}
#line 1457 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 16: /* ClassDeclList: ClassDecl  */
#line 53 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                            {}
#line 1463 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 17: /* ClassDecl: LeftClassDecl MethodDefBlock '}'  */
#line 56 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                             {}
#line 1469 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 18: /* ClassDecl: LeftClassDecl '}'  */
#line 57 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                              {}
#line 1475 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 19: /* LeftClassDecl: PartialLeftClassDecl '{' ClassGDeclBlock  */
#line 60 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                         {
                                            struct symbol* symbolTable = NULL;
                                            symbolTable = populateSymbolTable((yyvsp[0].node),symbolTable,1); // setting isLocal flag to not allocate mem
                                            updateTypeTable((yyvsp[-2].node)->varName,NULL,symbolTable);
                                        }
#line 1485 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 20: /* PartialLeftClassDecl: CLASS ID  */
#line 67 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                {
                        latestClassIndex =  populateTypeTable((yyvsp[0].node)->varName,1);
                        (yyval.node) = (yyvsp[0].node);
                     }
#line 1494 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 21: /* ClassGDeclBlock: DECL ENDDECL  */
#line 73 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                               {}
#line 1500 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 22: /* ClassGDeclBlock: DECL GDeclList ENDDECL  */
#line 74 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                         {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1508 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 23: /* MethodDefBlock: MethodDefBlock MethodDef  */
#line 79 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                          {}
#line 1514 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* MethodDefBlock: MethodDef  */
#line 80 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                            {}
#line 1520 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* MethodDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 83 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                               {
                                                                (yyvsp[-8].node)->type->depth += (yyvsp[-7].node)->type->depth;
                                                                struct symbol* symbolTable2 = getClassTableWithIndex(latestClassIndex)->symbolList;
                                                                symbolTable2->isGlobal = 1;
                                                                typeCheckFunctionParam((yyvsp[-8].node)->type,(yyvsp[-7].node)->varName,(yyvsp[-5].node),symbolTable2);
                                                                struct symbol* symbolTable1 = NULL;
                                                                symbolTable1 = addParamAsSymbol((yyvsp[-7].node)->varName,symbolTable2,symbolTable1);
                                                                symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
                                                                printSymbolTable((yyvsp[-7].node)->varName,symbolTable1);
                                                                typeCheck((yyvsp[-1].node),symbolTable1,latestClassIndex);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,symbolTable2);
                                                                populateParent((yyvsp[-1].node));
                                                                funcCodeGen(out,(yyvsp[-7].node)->varName,(yyvsp[-1].node),symbolTable1,latestClassIndex);
                                                        }
#line 1539 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* MethodDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 97 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                     {
                        (yyvsp[-7].node)->type->depth += (yyvsp[-6].node)->type->depth;
                        struct symbol* symbolTable2 = getClassTableWithIndex(latestClassIndex)->symbolList;
                        symbolTable2->isGlobal = 1;
                        typeCheckFunctionParam((yyvsp[-7].node)->type,(yyvsp[-6].node)->varName,NULL,symbolTable2);
                        struct symbol* symbolTable1 = NULL;
                        symbolTable1 = addParamAsSymbol((yyvsp[-6].node)->varName,symbolTable2,symbolTable1);
                        symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
                        typeCheck((yyvsp[-1].node),symbolTable1,latestClassIndex);
                        symbolTable1 = appendSymbolTable(symbolTable1,symbolTable2);
                        populateParent((yyvsp[-1].node));
                        funcCodeGen(out,(yyvsp[-6].node)->varName,(yyvsp[-1].node),symbolTable1,latestClassIndex);
          }
#line 1557 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 27: /* TypeDeclBlock: TYPEDECL ENDTYPEDECL  */
#line 112 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                     {}
#line 1563 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* TypeDeclBlock: TYPEDECL TypeDeclList ENDTYPEDECL  */
#line 113 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                  {
                printTypeTable();
              }
#line 1571 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* TypeDeclList: TypeDecl TypeDeclList  */
#line 118 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                     {}
#line 1577 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* TypeDeclList: TypeDecl  */
#line 119 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                       {}
#line 1583 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 31: /* TypeDecl: PartialTypeDecl '{' ParamList '}' ';'  */
#line 122 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                 {
                int numberOfParam = 0;
                updateTypeTable((yyvsp[-4].node)->varName,convertTreeToParamList((yyvsp[-2].node),&numberOfParam,NULL),NULL);
            }
#line 1592 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* PartialTypeDecl: STRUCT ID  */
#line 128 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                            {
                        populateTypeTable((yyvsp[0].node)->varName,0);
                        (yyval.node) = (yyvsp[0].node);
            }
#line 1601 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 33: /* MainBlock: INT MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 134 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                      { 
                                                            struct symbol* symbolTable = NULL;
                                                            symbolTable = populateSymbolTable((yyvsp[-2].node),symbolTable,0);
                                                            printSymbolTable("main",symbolTable);
                                                            symbolTable = appendSymbolTable(symbolTable,gsymbolTable);
                                                            typeCheck((yyvsp[-1].node),symbolTable,-1);
                                                            fprintf(out,"L0:\n"); 
                                                            populateParent((yyvsp[-1].node));
                                                            codeGen(out,(yyvsp[-1].node),symbolTable);
                                                        }
#line 1616 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 34: /* Body: BLOCK_BEGIN Slist RetStmt BLOCK_END  */
#line 147 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                {
                                    (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                                    (yyval.node)->label = (yyvsp[-2].node)->label;
                                }
#line 1625 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* Body: BLOCK_BEGIN RetStmt BLOCK_END  */
#line 151 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1633 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* Body: BLOCK_BEGIN BLOCK_END  */
#line 154 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                {}
#line 1639 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 37: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 157 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                    {   
                                        (yyval.node) = (yyvsp[-1].node);
                                        gsymbolTable = populateSymbolTable((yyvsp[-1].node),gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable("global",gsymbolTable);
                                    }
#line 1650 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* GDeclBlock: DECL ENDDECL  */
#line 163 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                           {}
#line 1656 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 39: /* GDeclList: GDeclList GDecl  */
#line 166 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1664 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 40: /* GDeclList: GDecl  */
#line 169 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1672 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 41: /* GDecl: Type GidList ';'  */
#line 174 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1680 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 43: /* Type: STR  */
#line 181 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
     {
        (yyval.node) = (yyvsp[0].node);
     }
#line 1688 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 44: /* Type: ID  */
#line 185 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
       {
        struct typeTable* type = getTypeTableWithName((yyvsp[0].node)->varName);
        if(type == NULL){
            printf("Error: type is used but not declared: %s\n",(yyvsp[0].node)->varName);
            exit(EXIT_FAILURE);
        }
        (yyvsp[0].node)->type = createUserDefinedTypeWithName((yyvsp[0].node)->varName);
        (yyval.node) = (yyvsp[0].node);
       }
#line 1702 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 45: /* GidList: GidList ',' Gid  */
#line 196 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1710 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 46: /* GidList: Gid  */
#line 199 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1718 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 48: /* Gid: DeclArray  */
#line 206 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1726 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 49: /* Gid: ID '(' ParamList ')'  */
#line 209 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                           {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                                (yyval.node)->type = (yyvsp[-3].node)->type;
                            }
#line 1736 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 50: /* Gid: ID '(' ')'  */
#line 214 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                 {  
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-2].node),NULL,NULL,label);
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1746 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* Gid: '*' Gid  */
#line 219 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
              {
                    (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1755 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* ParamList: ParamList ',' Param  */
#line 225 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                {
                            (yyval.node) = createOperatorNode(OP_PARAMLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1763 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 53: /* ParamList: Param  */
#line 228 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1771 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 54: /* Param: Type Pid  */
#line 233 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = createOperatorNode(OP_PARAM,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    (yyval.node)->type = (yyvsp[0].node)->type;
                }
#line 1780 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 55: /* Pid: ID  */
#line 239 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
         {
            (yyval.node) = (yyvsp[0].node);
            }
#line 1788 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 56: /* Pid: '*' Pid  */
#line 242 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
              {
            (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
            (yyval.node) = (yyvsp[0].node); 
        }
#line 1797 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 57: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 249 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                    {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1805 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 58: /* LDeclBlock: DECL ENDDECL  */
#line 252 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                           {}
#line 1811 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 59: /* LDeclList: LDeclList LDecl  */
#line 255 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1819 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 60: /* LDeclList: LDecl  */
#line 258 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1827 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 61: /* LDecl: Type LidList ';'  */
#line 263 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1835 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 62: /* LidList: LidList ',' Lid  */
#line 268 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1843 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 63: /* LidList: Lid  */
#line 271 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1851 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 65: /* Lid: DeclArray  */
#line 278 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1859 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 66: /* Lid: '*' Lid  */
#line 281 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
              {
        (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1868 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 68: /* FDefBlock: FDef  */
#line 289 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
          {}
#line 1874 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 69: /* FDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 292 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                          {
                                                                (yyvsp[-8].node)->type->depth += (yyvsp[-7].node)->type->depth;
                                                                typeCheckFunctionParam((yyvsp[-8].node)->type,(yyvsp[-7].node)->varName,(yyvsp[-5].node),gsymbolTable);
                                                                struct symbol* symbolTable1 = NULL;
                                                                symbolTable1 = addParamAsSymbol((yyvsp[-7].node)->varName,gsymbolTable,symbolTable1);
                                                                symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
                                                                printSymbolTable((yyvsp[-7].node)->varName,symbolTable1);
                                                                symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
                                                                typeCheck((yyvsp[-1].node),symbolTable1,-1);
                                                                populateParent((yyvsp[-1].node));
                                                                funcCodeGen(out,(yyvsp[-7].node)->varName,(yyvsp[-1].node),symbolTable1,-1);
                                                        }
#line 1891 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 70: /* FDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 304 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                  {
        (yyvsp[-7].node)->type->depth += (yyvsp[-6].node)->type->depth;
        typeCheckFunctionParam((yyvsp[-7].node)->type,(yyvsp[-6].node)->varName,NULL,gsymbolTable);
        struct symbol* symbolTable1 = NULL;
        symbolTable1 = addParamAsSymbol((yyvsp[-6].node)->varName,gsymbolTable,symbolTable1);
        symbolTable1 = populateSymbolTable((yyvsp[-2].node),symbolTable1,1);
        symbolTable1 = appendSymbolTable(symbolTable1,gsymbolTable);
        typeCheck((yyvsp[-1].node),symbolTable1,-1);
        populateParent((yyvsp[-1].node));
        funcCodeGen(out,(yyvsp[-6].node)->varName,(yyvsp[-1].node),symbolTable1,-1);
     }
#line 1907 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 71: /* Slist: Slist Stmt  */
#line 317 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1916 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 72: /* Slist: Stmt  */
#line 321 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1924 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 85: /* Stmt: NewStmt  */
#line 339 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1932 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 86: /* AllocStmt: Identifier '=' ALLOC '(' ')' ';'  */
#line 344 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                             {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_ALLOC,(yyvsp[-5].node),NULL,NULL,label);
}
#line 1941 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 87: /* NewStmt: Identifier '=' NEW '(' ID ')' ';'  */
#line 350 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                            {
    int label = getLabel();
    (yyval.node) = createOperatorNode(LEAF_NEW,(yyvsp[-6].node),(yyvsp[-2].node),NULL,label);
}
#line 1950 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 88: /* InitialiseStmt: INITIALISE '(' ')' ';'  */
#line 356 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                        {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_INITIALISE,NULL,NULL,NULL,label);
}
#line 1959 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 89: /* FreeStmt: FREE '(' Identifier ')' ';'  */
#line 362 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                       {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_FREE,(yyvsp[-2].node),NULL,NULL,label);
}
#line 1968 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 90: /* RetStmt: RETURN E ';'  */
#line 368 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                      {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_RETURN,(yyvsp[-1].node),NULL,NULL,label);
        }
#line 1977 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 91: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 374 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                     { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node),label);
                                                  }
#line 1986 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 92: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF ';'  */
#line 378 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                            {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                        }
#line 1995 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 93: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE ';'  */
#line 385 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                 {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                                }
#line 2004 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 94: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 391 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 2013 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 95: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 397 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 2022 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 96: /* AsgStmt: Identifier '=' E ';'  */
#line 403 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 2031 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 98: /* ContinueStmt: CONTINUE ';'  */
#line 411 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2039 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 99: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 416 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 2048 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 100: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 422 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 2057 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 101: /* B: E '<' E  */
#line 428 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2065 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 102: /* B: E '>' E  */
#line 431 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2073 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 103: /* B: E GE E  */
#line 434 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2081 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 104: /* B: E LE E  */
#line 437 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2089 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 105: /* B: E NE E  */
#line 440 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2097 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 106: /* B: E EQ E  */
#line 443 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2105 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 107: /* E: E '+' E  */
#line 448 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2113 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 108: /* E: E '*' E  */
#line 451 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2121 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 109: /* E: E '-' E  */
#line 454 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2129 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 110: /* E: E '/' E  */
#line 457 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2137 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 111: /* E: E '%' E  */
#line 460 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2145 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 112: /* E: '&' ID  */
#line 463 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 2153 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 113: /* E: '(' E ')'  */
#line 466 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 2161 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 114: /* E: ID '(' ')'  */
#line 469 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-2].node),NULL,NULL,-1);
                }
#line 2169 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 115: /* E: ID '(' ArgList ')'  */
#line 472 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                       {
                            (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                        }
#line 2177 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 116: /* E: E '.' ID '(' ')'  */
#line 475 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                     {
                            (yyval.node) = createOperatorNode(LEAF_METHOD,(yyvsp[-4].node),(yyvsp[-2].node),NULL,-1);
                        }
#line 2185 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 117: /* E: E '.' ID '(' ArgList ')'  */
#line 478 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                             {
                            (yyval.node) = createOperatorNode(LEAF_METHOD,(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node),-1);
                        }
#line 2193 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 118: /* E: E ARROW ID '(' ')'  */
#line 481 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                     {      
                            struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-4].node),NULL,NULL,-1);
                            (yyval.node) = createOperatorNode(LEAF_METHOD,temp,(yyvsp[-2].node),NULL,-1);
                        }
#line 2202 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 119: /* E: E ARROW ID '(' ArgList ')'  */
#line 485 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                               {
                            struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-5].node),NULL,NULL,-1);
                            (yyval.node) = createOperatorNode(LEAF_METHOD,temp,(yyvsp[-3].node),(yyvsp[-1].node),-1);
                        }
#line 2211 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 122: /* E: CSTR  */
#line 492 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 2219 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 123: /* ArgList: ArgList ',' E  */
#line 497 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_ARGLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 2227 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 124: /* ArgList: E  */
#line 500 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2235 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 125: /* DeclArray: ID DeclBraceList  */
#line 505 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1); 
                        (yyval.node)->type = (yyvsp[-1].node)->type;
                    }
#line 2244 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 126: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 511 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 2252 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 127: /* DeclBraceList: '[' NUM ']'  */
#line 514 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2260 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 128: /* Array: ID BraceList  */
#line 519 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 2268 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 129: /* BraceList: BraceList '[' E ']'  */
#line 524 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 2276 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 130: /* BraceList: '[' E ']'  */
#line 527 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2284 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 133: /* Identifier: SELF  */
#line 535 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2292 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 134: /* Identifier: '*' E  */
#line 538 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 2300 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 135: /* Identifier: E '.' ID  */
#line 541 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                       {
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2308 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 136: /* Identifier: E ARROW ID  */
#line 544 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"
                         {
                struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-2].node),NULL,NULL,-1);
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,temp,(yyvsp[0].node),NULL,-1);
            }
#line 2317 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 2321 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 550 "/mnt/c/Users/ervin/coding/compilerLab/exercises/stage7/exercises/src/yacc/generateExpTree.y"


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
