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
    #include "out.h"
    #include "utils.h"
    extern FILE* yyin;
    extern char* yytext;
    FILE* out;
    struct symbol* gsymbolTable = NULL;
    int latestClassIndex = 0;

#line 91 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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
  YYSYMBOL_EXTENDS = 42,                   /* EXTENDS  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_49_ = 49,                       /* '.'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '<'  */
  YYSYMBOL_57_ = 57,                       /* '>'  */
  YYSYMBOL_58_ = 58,                       /* '&'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_Program = 62,                   /* Program  */
  YYSYMBOL_ClassDeclBlock = 63,            /* ClassDeclBlock  */
  YYSYMBOL_ClassDeclList = 64,             /* ClassDeclList  */
  YYSYMBOL_ClassDecl = 65,                 /* ClassDecl  */
  YYSYMBOL_LeftClassDecl = 66,             /* LeftClassDecl  */
  YYSYMBOL_PartialLeftClassDecl = 67,      /* PartialLeftClassDecl  */
  YYSYMBOL_ClassGDeclBlock = 68,           /* ClassGDeclBlock  */
  YYSYMBOL_MethodDefBlock = 69,            /* MethodDefBlock  */
  YYSYMBOL_MethodDef = 70,                 /* MethodDef  */
  YYSYMBOL_TypeDeclBlock = 71,             /* TypeDeclBlock  */
  YYSYMBOL_TypeDeclList = 72,              /* TypeDeclList  */
  YYSYMBOL_TypeDecl = 73,                  /* TypeDecl  */
  YYSYMBOL_PartialTypeDecl = 74,           /* PartialTypeDecl  */
  YYSYMBOL_MainBlock = 75,                 /* MainBlock  */
  YYSYMBOL_Body = 76,                      /* Body  */
  YYSYMBOL_GDeclBlock = 77,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 78,                 /* GDeclList  */
  YYSYMBOL_GDecl = 79,                     /* GDecl  */
  YYSYMBOL_Type = 80,                      /* Type  */
  YYSYMBOL_GidList = 81,                   /* GidList  */
  YYSYMBOL_Gid = 82,                       /* Gid  */
  YYSYMBOL_ParamList = 83,                 /* ParamList  */
  YYSYMBOL_Param = 84,                     /* Param  */
  YYSYMBOL_Pid = 85,                       /* Pid  */
  YYSYMBOL_LDeclBlock = 86,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 87,                 /* LDeclList  */
  YYSYMBOL_LDecl = 88,                     /* LDecl  */
  YYSYMBOL_LidList = 89,                   /* LidList  */
  YYSYMBOL_Lid = 90,                       /* Lid  */
  YYSYMBOL_FDefBlock = 91,                 /* FDefBlock  */
  YYSYMBOL_FDef = 92,                      /* FDef  */
  YYSYMBOL_Slist = 93,                     /* Slist  */
  YYSYMBOL_Stmt = 94,                      /* Stmt  */
  YYSYMBOL_AllocStmt = 95,                 /* AllocStmt  */
  YYSYMBOL_NewStmt = 96,                   /* NewStmt  */
  YYSYMBOL_InitialiseStmt = 97,            /* InitialiseStmt  */
  YYSYMBOL_FreeStmt = 98,                  /* FreeStmt  */
  YYSYMBOL_RetStmt = 99,                   /* RetStmt  */
  YYSYMBOL_Ifstmt = 100,                   /* Ifstmt  */
  YYSYMBOL_Whilestmt = 101,                /* Whilestmt  */
  YYSYMBOL_InputStmt = 102,                /* InputStmt  */
  YYSYMBOL_OutputStmt = 103,               /* OutputStmt  */
  YYSYMBOL_AsgStmt = 104,                  /* AsgStmt  */
  YYSYMBOL_BreakStmt = 105,                /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 106,             /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 107,          /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 108,              /* DoWhileStmt  */
  YYSYMBOL_B = 109,                        /* B  */
  YYSYMBOL_E = 110,                        /* E  */
  YYSYMBOL_ArgList = 111,                  /* ArgList  */
  YYSYMBOL_DeclArray = 112,                /* DeclArray  */
  YYSYMBOL_DeclBraceList = 113,            /* DeclBraceList  */
  YYSYMBOL_Array = 114,                    /* Array  */
  YYSYMBOL_BraceList = 115,                /* BraceList  */
  YYSYMBOL_Identifier = 116                /* Identifier  */
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
#define YYLAST   596

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  312

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,     2,     2,     2,     2,    44,    58,     2,
      52,    53,    47,    45,    55,    46,    49,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
      56,    43,    57,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    36,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    50,    53,    54,    57,    58,    61,
      67,    82,    88,    89,    94,    95,    98,   112,   127,   128,
     133,   134,   137,   143,   149,   161,   166,   169,   172,   178,
     181,   184,   189,   194,   195,   199,   211,   214,   219,   220,
     224,   228,   232,   238,   241,   246,   252,   255,   262,   265,
     268,   271,   276,   281,   284,   289,   290,   294,   300,   301,
     305,   317,   330,   334,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   357,   363,   369,
     375,   381,   387,   391,   398,   404,   410,   416,   422,   423,
     429,   435,   441,   444,   447,   450,   453,   456,   461,   464,
     467,   470,   473,   476,   479,   482,   485,   488,   491,   494,
     498,   502,   503,   504,   510,   513,   518,   524,   527,   532,
     537,   540,   545,   546,   547,   551,   554,   557
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
  "INITIALISE", "FREE", "ALLOC", "ARROW", "CLASS", "SELF", "NEW",
  "EXTENDS", "'='", "'%'", "'+'", "'-'", "'*'", "'/'", "'.'", "'}'", "'{'",
  "'('", "')'", "';'", "','", "'<'", "'>'", "'&'", "'['", "']'", "$accept",
  "Program", "ClassDeclBlock", "ClassDeclList", "ClassDecl",
  "LeftClassDecl", "PartialLeftClassDecl", "ClassGDeclBlock",
  "MethodDefBlock", "MethodDef", "TypeDeclBlock", "TypeDeclList",
  "TypeDecl", "PartialTypeDecl", "MainBlock", "Body", "GDeclBlock",
  "GDeclList", "GDecl", "Type", "GidList", "Gid", "ParamList", "Param",
  "Pid", "LDeclBlock", "LDeclList", "LDecl", "LidList", "Lid", "FDefBlock",
  "FDef", "Slist", "Stmt", "AllocStmt", "NewStmt", "InitialiseStmt",
  "FreeStmt", "RetStmt", "Ifstmt", "Whilestmt", "InputStmt", "OutputStmt",
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

#define YYPACT_NINF (-187)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     146,    23,   -13,   147,    19,    65,   162,    59,  -187,   108,
     -12,    48,  -187,    97,  -187,  -187,  -187,  -187,   267,  -187,
       4,    42,  -187,    33,    71,    79,    89,  -187,  -187,  -187,
      97,  -187,  -187,   110,  -187,     7,   112,   132,   162,  -187,
      97,   -13,  -187,     7,    97,  -187,  -187,  -187,   -19,     4,
      -5,  -187,  -187,   109,  -187,  -187,  -187,   206,  -187,    97,
    -187,  -187,  -187,     7,    99,   127,   300,  -187,  -187,    97,
    -187,    97,   123,  -187,  -187,    11,   196,   145,  -187,  -187,
       4,   160,     7,    98,  -187,  -187,  -187,    18,   132,  -187,
     331,  -187,    97,  -187,    93,  -187,   192,   154,   212,  -187,
     195,  -187,   164,   206,   172,   257,  -187,  -187,  -187,   173,
     263,  -187,  -187,   168,   361,   239,  -187,  -187,   195,   197,
     195,   201,  -187,  -187,    14,   391,  -187,   199,   203,   239,
     195,   239,   195,   200,    14,    55,  -187,  -187,  -187,  -187,
    -187,    40,  -187,   202,   208,   209,   222,   384,   221,   224,
    -187,   384,   429,   230,   231,  -187,   429,   429,   280,   259,
    -187,  -187,  -187,  -187,  -187,   282,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,   542,  -187,   250,  -187,   246,
     239,   255,   239,  -187,  -187,    14,    53,   429,   241,   429,
     429,   429,   429,   414,  -187,  -187,   294,   494,  -187,   256,
     429,   -24,   518,  -187,  -187,   307,  -187,   315,   429,   429,
     429,   429,   429,   322,   124,  -187,   286,  -187,   293,  -187,
    -187,   542,   287,   460,   429,   295,   530,   296,   446,   316,
     301,   321,  -187,   323,   325,  -187,  -187,   327,   547,   463,
     463,   -24,   -24,   344,   347,   348,   506,  -187,  -187,  -187,
     429,  -187,   477,   329,   353,   337,   429,   429,   429,   429,
     429,   429,   394,   429,   429,  -187,   355,   169,   399,   360,
     422,  -187,   542,  -187,  -187,  -187,   384,   542,   542,   542,
     542,   542,   542,   384,   376,   377,  -187,  -187,   317,  -187,
     390,   383,   385,   229,   324,    -2,   393,  -187,  -187,  -187,
     405,   384,   406,   413,  -187,  -187,  -187,   354,  -187,  -187,
     417,  -187
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    14,    16,     0,
       0,     0,    13,     0,    45,    39,    43,    44,     0,    41,
       0,     0,    28,     0,     0,    31,     0,    21,     1,     7,
       0,    15,    18,     0,    25,     0,     0,     0,     0,    10,
       0,    43,    12,     0,     0,    69,    38,    40,    48,     0,
       0,    47,    49,     0,    33,    29,    30,     0,     6,     0,
      17,    24,    56,     0,     0,     0,     0,    19,     4,     0,
       9,     0,     0,    11,    68,     0,     0,   126,    52,    42,
       0,     0,     0,     0,    54,     5,    57,     0,     0,    22,
       0,     3,     0,     8,     0,    51,     0,     0,     0,    46,
       0,    55,     0,     0,     0,     0,    20,    23,     2,     0,
       0,    50,   128,     0,     0,     0,    32,    53,     0,     0,
       0,     0,   127,    59,     0,     0,    61,     0,     0,     0,
       0,     0,     0,    65,     0,     0,    64,    66,    58,    60,
     121,   132,    37,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,   134,     0,     0,     0,     0,
      73,    85,    86,    83,    84,     0,    77,    78,    74,    75,
      76,    79,    80,    81,    82,     0,   133,   122,    34,     0,
       0,     0,     0,    67,    62,     0,     0,     0,   129,     0,
       0,     0,     0,     0,    98,    99,     0,     0,   122,     0,
       0,   135,     0,   113,    72,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    71,     0,    63,
     115,   125,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,    91,     0,   122,   114,    35,   137,   112,   108,
     110,   109,   111,   136,     0,     0,     0,    26,    70,   116,
       0,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,    97,   124,   130,    95,    96,     0,   104,   105,   106,
     107,   102,   103,     0,     0,     0,    90,   119,     0,   117,
       0,     0,     0,     0,     0,     0,     0,   120,   118,    87,
       0,     0,     0,     0,   101,   100,    88,     0,    93,    94,
       0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,   433,  -187,   441,  -187,  -187,   365,  -187,   440,
    -187,   449,  -187,  -187,    15,  -100,   125,   409,   -15,     1,
    -187,   -36,   183,   374,    20,   338,  -187,   357,  -187,  -125,
     129,    37,  -146,  -155,  -187,  -187,  -187,  -187,   319,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -186,   -67,
     -80,  -117,  -187,  -187,  -187,  -127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    10,    67,    33,    34,
      11,    24,    25,    26,    12,   128,    13,    18,    19,    43,
      50,    51,    83,    84,    64,   115,   125,   126,   135,   136,
      44,    45,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   227,   175,
     222,    52,    77,   176,   188,   198
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     177,   193,    20,    47,   204,   196,   229,   137,    48,   183,
      35,    62,   283,    78,   207,    14,    21,   137,   133,    20,
     177,    29,    14,    27,   177,   213,    39,    14,    42,   179,
      36,   181,   177,    75,    35,    16,    17,    54,   204,    37,
      76,   204,    16,    17,    99,    58,    15,    16,    17,    79,
      80,    49,   304,    68,    63,    70,   140,   141,    82,    73,
     219,   134,   225,    72,    95,    28,   177,    20,   137,   177,
       1,   104,     2,   234,    85,    47,    82,   284,   285,   150,
     216,    74,   218,    86,    91,   197,    93,     4,    82,   201,
     202,    20,   186,   155,    53,    82,    74,    14,     4,   187,
     156,    14,   101,    55,    82,   157,   220,   108,    74,   184,
     185,   158,    14,    23,    14,   124,    65,    16,    17,   221,
     223,    41,    17,   226,   228,   228,   124,   140,   141,    74,
     293,    30,    16,    17,    16,    17,    40,   294,   204,   204,
      57,   238,   239,   240,   241,   242,   109,   246,   102,   177,
     150,    87,   204,   103,    66,   307,   177,   252,    32,    59,
      60,   244,    81,    69,   155,   245,   177,   177,     1,    71,
       2,   156,   140,   141,   177,    94,   157,     3,    88,    22,
     177,    23,   158,   272,     1,     4,     2,   288,   290,   277,
     278,   279,   280,   281,   282,   150,   228,   228,    92,    97,
     221,   221,   140,   141,    98,   142,   143,   144,   145,   155,
      14,   100,   146,   147,   112,   113,   156,   114,   116,   148,
     149,   157,   287,   118,   120,   150,   151,   158,   122,   152,
      16,    17,   140,   141,   153,   154,   143,   144,   145,   155,
     301,   302,   146,   147,   127,   111,   156,   103,   130,   148,
     149,   157,   132,   178,   189,   150,   151,   158,    96,    76,
     190,   191,   140,   141,   153,   154,   143,   144,   145,   155,
     105,    14,   146,   147,   192,   194,   156,   110,   195,   148,
     149,   157,   199,   200,   203,   150,   151,   158,   206,   152,
      46,    16,    17,   214,   153,   154,   215,   140,   141,   155,
     224,   143,   144,   145,    14,   217,   156,   146,   147,   233,
     119,   157,   103,   236,   148,   149,   121,   158,   103,   237,
     150,   151,   231,    89,    16,    17,   243,   140,   141,   153,
     154,   143,   144,   145,   155,    14,   247,   146,   147,   303,
     249,   156,   250,   248,   148,   149,   157,   276,   253,   255,
     150,   151,   158,   263,   107,    16,    17,   140,   141,   153,
     154,   143,   144,   145,   155,    14,   310,   146,   147,   262,
     297,   156,   250,   264,   148,   149,   157,   265,   266,   267,
     150,   151,   158,   274,   123,    16,    17,   140,   141,   153,
     154,   143,   144,   145,   155,    14,   268,   146,   147,   269,
     270,   156,   140,   141,   148,   149,   157,   275,   283,   286,
     150,   151,   158,   291,   138,    16,    17,   140,   141,   153,
     154,   143,   144,   145,   155,   150,   292,   230,   147,   295,
     296,   156,   140,   141,   148,   149,   157,   299,   300,   155,
     150,   151,   158,   298,    38,   250,   156,   305,    31,   153,
     154,   157,   289,   106,   155,   150,   129,   158,   131,   306,
     308,   156,   256,   257,   258,   259,   157,   309,   180,   155,
     182,   311,   158,    61,    56,    90,   156,   117,   205,     0,
       0,   157,   139,     0,   207,     0,     0,   158,     0,     0,
     208,   209,   210,   211,   212,   213,     0,     0,   207,     0,
       0,   207,   260,   261,   208,   209,   210,   211,   212,   213,
     211,   212,   213,     0,     0,   207,     0,     0,     0,     0,
     251,   208,   209,   210,   211,   212,   213,     0,     0,     0,
       0,     0,   207,     0,     0,     0,     0,   273,   208,   209,
     210,   211,   212,   213,   207,     0,     0,     0,   232,     0,
     208,   209,   210,   211,   212,   213,   207,     0,     0,     0,
     271,     0,   208,   209,   210,   211,   212,   213,   207,     0,
       0,   235,     0,     0,   208,   209,   210,   211,   212,   213,
     207,     0,     0,   254,     0,   207,   208,   209,   210,   211,
     212,   213,   209,   210,   211,   212,   213
};

static const yytype_int16 yycheck[] =
{
     127,   147,     1,    18,   159,   151,   192,   124,     4,   134,
       9,     4,    14,    49,    38,     4,    29,   134,     4,    18,
     147,     6,     4,     4,   151,    49,    11,     4,    13,   129,
      42,   131,   159,    52,    33,    24,    25,     4,   193,    51,
      59,   196,    24,    25,    80,    30,    23,    24,    25,    54,
      55,    47,    54,    38,    47,    40,     3,     4,    57,    44,
     185,    47,   189,    43,    53,     0,   193,    66,   185,   196,
      22,    53,    24,   200,    59,    90,    75,   263,   264,    26,
     180,    44,   182,    63,    69,   152,    71,    39,    87,   156,
     157,    90,    52,    40,    52,    94,    59,     4,    39,    59,
      47,     4,    82,    32,   103,    52,    53,    92,    71,    54,
      55,    58,     4,    34,     4,   114,     4,    24,    25,   186,
     187,    24,    25,   190,   191,   192,   125,     3,     4,    92,
     276,     6,    24,    25,    24,    25,    11,   283,   293,   294,
      51,   208,   209,   210,   211,   212,    53,   214,    50,   276,
      26,    52,   307,    55,    22,   301,   283,   224,    50,    30,
      50,    37,    53,    38,    40,    41,   293,   294,    22,    40,
      24,    47,     3,     4,   301,    52,    52,    31,    51,    32,
     307,    34,    58,   250,    22,    39,    24,   267,   268,   256,
     257,   258,   259,   260,   261,    26,   263,   264,    69,     3,
     267,   268,     3,     4,    59,     6,     7,     8,     9,    40,
       4,    51,    13,    14,    60,     3,    47,    22,    54,    20,
      21,    52,    53,    51,    51,    26,    27,    58,    60,    30,
      24,    25,     3,     4,    35,    36,     7,     8,     9,    40,
      11,    12,    13,    14,     5,    53,    47,    55,    51,    20,
      21,    52,    51,    50,    52,    26,    27,    58,    75,    59,
      52,    52,     3,     4,    35,    36,     7,     8,     9,    40,
      87,     4,    13,    14,    52,    54,    47,    94,    54,    20,
      21,    52,    52,    52,     4,    26,    27,    58,     6,    30,
      23,    24,    25,    43,    35,    36,    50,     3,     4,    40,
      59,     7,     8,     9,     4,    50,    47,    13,    14,    53,
      53,    52,    55,     6,    20,    21,    53,    58,    55,     4,
      26,    27,    28,    23,    24,    25,     4,     3,     4,    35,
      36,     7,     8,     9,    40,     4,    50,    13,    14,    15,
      53,    47,    55,    50,    20,    21,    52,    10,    53,    53,
      26,    27,    58,    52,    23,    24,    25,     3,     4,    35,
      36,     7,     8,     9,    40,     4,    12,    13,    14,    53,
      53,    47,    55,    52,    20,    21,    52,    54,    53,    52,
      26,    27,    58,    54,    23,    24,    25,     3,     4,    35,
      36,     7,     8,     9,    40,     4,    52,    13,    14,    52,
      52,    47,     3,     4,    20,    21,    52,    54,    14,    54,
      26,    27,    58,    53,    23,    24,    25,     3,     4,    35,
      36,     7,     8,     9,    40,    26,     4,    13,    14,    53,
      53,    47,     3,     4,    20,    21,    52,    54,    53,    40,
      26,    27,    58,    53,    11,    55,    47,    54,     7,    35,
      36,    52,    53,    88,    40,    26,   118,    58,   120,    54,
      54,    47,    16,    17,    18,    19,    52,    54,   130,    40,
     132,    54,    58,    33,    25,    66,    47,   103,   159,    -1,
      -1,    52,   125,    -1,    38,    -1,    -1,    58,    -1,    -1,
      44,    45,    46,    47,    48,    49,    -1,    -1,    38,    -1,
      -1,    38,    56,    57,    44,    45,    46,    47,    48,    49,
      47,    48,    49,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      60,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    60,    44,    45,
      46,    47,    48,    49,    38,    -1,    -1,    -1,    54,    -1,
      44,    45,    46,    47,    48,    49,    38,    -1,    -1,    -1,
      54,    -1,    44,    45,    46,    47,    48,    49,    38,    -1,
      -1,    53,    -1,    -1,    44,    45,    46,    47,    48,    49,
      38,    -1,    -1,    53,    -1,    38,    44,    45,    46,    47,
      48,    49,    45,    46,    47,    48,    49
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    24,    31,    39,    62,    63,    64,    65,    66,
      67,    71,    75,    77,     4,    23,    24,    25,    78,    79,
      80,    29,    32,    34,    72,    73,    74,     4,     0,    75,
      77,    65,    50,    69,    70,    80,    42,    51,    63,    75,
      77,    24,    75,    80,    91,    92,    23,    79,     4,    47,
      81,    82,   112,    52,     4,    32,    72,    51,    75,    91,
      50,    70,     4,    47,    85,     4,    22,    68,    75,    77,
      75,    91,    85,    75,    92,    52,    59,   113,    82,    54,
      55,    53,    80,    83,    84,    75,    85,    52,    51,    23,
      78,    75,    91,    75,    52,    53,    83,     3,    59,    82,
      51,    85,    50,    55,    53,    83,    68,    23,    75,    53,
      83,    53,    60,     3,    22,    86,    54,    84,    51,    53,
      51,    53,    60,    23,    80,    87,    88,     5,    76,    86,
      51,    86,    51,     4,    47,    89,    90,   112,    23,    88,
       3,     4,     6,     7,     8,     9,    13,    14,    20,    21,
      26,    27,    30,    35,    36,    40,    47,    52,    58,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   110,   114,   116,    50,    76,
      86,    76,    86,    90,    54,    55,    52,    59,   115,    52,
      52,    52,    52,    93,    54,    54,    93,   110,   116,    52,
      52,   110,   110,     4,    94,    99,     6,    38,    44,    45,
      46,    47,    48,    49,    43,    50,    76,    50,    76,    90,
      53,   110,   111,   110,    59,   116,   110,   109,   110,   109,
      13,    28,    54,    53,   116,    53,     6,     4,   110,   110,
     110,   110,   110,     4,    37,    41,   110,    50,    50,    53,
      55,    60,   110,    53,    53,    53,    16,    17,    18,    19,
      56,    57,    53,    52,    52,    54,    53,    52,    52,    52,
      52,    54,   110,    60,    54,    54,    10,   110,   110,   110,
     110,   110,   110,    14,   109,   109,    54,    53,   111,    53,
     111,    53,     4,    93,    93,    53,    53,    53,    53,    54,
      53,    11,    12,    15,    54,    54,    54,    93,    54,    54,
      12,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    64,    64,    65,    65,    66,
      66,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    74,    75,    76,    76,    76,    77,    77,
      78,    78,    79,    80,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    83,    83,    84,    85,    85,    86,    86,
      87,    87,    88,    89,    89,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    95,    96,    97,
      98,    99,   100,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   112,   113,   113,   114,
     115,   115,   116,   116,   116,   116,   116,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     4,     3,     2,     4,     3,
       2,     3,     2,     1,     1,     2,     1,     3,     2,     3,
       5,     2,     2,     3,     2,     1,     9,     8,     2,     3,
       2,     1,     5,     2,     8,     4,     3,     2,     3,     2,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       4,     3,     2,     3,     1,     2,     1,     2,     3,     2,
       2,     1,     3,     3,     1,     1,     1,     2,     2,     1,
       9,     8,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     6,     7,     4,
       5,     3,    10,     8,     8,     5,     5,     4,     2,     2,
       7,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     4,     5,     6,     5,
       6,     1,     1,     1,     3,     1,     2,     4,     3,     2,
       4,     3,     1,     1,     1,     2,     3,     3
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
#line 50 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               { printClassTable(); }
#line 1461 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* ClassDeclList: ClassDeclList ClassDecl  */
#line 53 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {}
#line 1467 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 16: /* ClassDeclList: ClassDecl  */
#line 54 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {}
#line 1473 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 17: /* ClassDecl: LeftClassDecl MethodDefBlock '}'  */
#line 57 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                             {}
#line 1479 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 18: /* ClassDecl: LeftClassDecl '}'  */
#line 58 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                              {}
#line 1485 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 19: /* LeftClassDecl: PartialLeftClassDecl '{' ClassGDeclBlock  */
#line 62 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                    struct symbol* symbolTable = NULL;
                    symbolTable = populateSymbolTable((yyvsp[0].node),symbolTable,1); // setting isLocal flag to not allocate mem
                    updateTypeTable((yyvsp[-2].node)->varName,NULL,symbolTable);
                }
#line 1495 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 20: /* LeftClassDecl: PartialLeftClassDecl EXTENDS ID '{' ClassGDeclBlock  */
#line 68 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    struct symbol* symbolTable = NULL;
                    symbolTable = populateSymbolTable((yyvsp[0].node),symbolTable,1); // setting isLocal flag to not allocate mem
                    struct typeTable* typeTable = updateTypeTable((yyvsp[-4].node)->varName,NULL,symbolTable);
                    struct typeTable* parentTypeTable = getTypeTableWithName((yyvsp[-2].node)->varName);
                    if(parentTypeTable == NULL){
                        printf("Error: class %s has not been declared but is used as a parent class to %s\n",(yyvsp[-2].node)->varName,(yyvsp[-4].node)->varName);
                        exit(EXIT_FAILURE);
                    } 
                    typeTable->parent = parentTypeTable;
                    typeTable->symbolList = combineChildSymbolListWithParentSymbolList(typeTable->symbolList,parentTypeTable->symbolList);
                }
#line 1512 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 21: /* PartialLeftClassDecl: CLASS ID  */
#line 82 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                        latestClassIndex =  populateTypeTable((yyvsp[0].node)->varName,1);
                        (yyval.node) = (yyvsp[0].node);
                     }
#line 1521 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 22: /* ClassGDeclBlock: DECL ENDDECL  */
#line 88 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {}
#line 1527 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 23: /* ClassGDeclBlock: DECL GDeclList ENDDECL  */
#line 89 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                         {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1535 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* MethodDefBlock: MethodDefBlock MethodDef  */
#line 94 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                          {}
#line 1541 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* MethodDefBlock: MethodDef  */
#line 95 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {}
#line 1547 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* MethodDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 98 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1566 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 27: /* MethodDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 112 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1584 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* TypeDeclBlock: TYPEDECL ENDTYPEDECL  */
#line 127 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                     {}
#line 1590 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* TypeDeclBlock: TYPEDECL TypeDeclList ENDTYPEDECL  */
#line 128 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                  {
                printTypeTable();
              }
#line 1598 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* TypeDeclList: TypeDecl TypeDeclList  */
#line 133 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                     {}
#line 1604 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 31: /* TypeDeclList: TypeDecl  */
#line 134 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {}
#line 1610 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* TypeDecl: PartialTypeDecl '{' ParamList '}' ';'  */
#line 137 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {
                int numberOfParam = 0;
                updateTypeTable((yyvsp[-4].node)->varName,convertTreeToParamList((yyvsp[-2].node),&numberOfParam,NULL),NULL);
            }
#line 1619 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 33: /* PartialTypeDecl: STRUCT ID  */
#line 143 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                        populateTypeTable((yyvsp[0].node)->varName,0);
                        (yyval.node) = (yyvsp[0].node);
            }
#line 1628 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 34: /* MainBlock: INT MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 149 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                      { 
                                                            struct symbol* symbolTable = NULL;
                                                            symbolTable = populateSymbolTable((yyvsp[-2].node),symbolTable,0);
                                                            printSymbolTable("main",symbolTable);
                                                            symbolTable = appendSymbolTable(symbolTable,gsymbolTable);
                                                            typeCheck((yyvsp[-1].node),symbolTable,-1);
                                                            cprintf(out,"L0:\n"); 
                                                            populateParent((yyvsp[-1].node));
                                                            codeGen(out,(yyvsp[-1].node),symbolTable);
                                                        }
#line 1643 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* Body: BLOCK_BEGIN Slist RetStmt BLOCK_END  */
#line 162 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                                    (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                                    (yyval.node)->label = (yyvsp[-2].node)->label;
                                }
#line 1652 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* Body: BLOCK_BEGIN RetStmt BLOCK_END  */
#line 166 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1660 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 37: /* Body: BLOCK_BEGIN BLOCK_END  */
#line 169 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {}
#line 1666 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 172 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {   
                                        (yyval.node) = (yyvsp[-1].node);
                                        gsymbolTable = populateSymbolTable((yyvsp[-1].node),gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable("global",gsymbolTable);
                                    }
#line 1677 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 39: /* GDeclBlock: DECL ENDDECL  */
#line 178 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1683 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 40: /* GDeclList: GDeclList GDecl  */
#line 181 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1691 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 41: /* GDeclList: GDecl  */
#line 184 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1699 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 42: /* GDecl: Type GidList ';'  */
#line 189 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1707 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 44: /* Type: STR  */
#line 196 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
     {
        (yyval.node) = (yyvsp[0].node);
     }
#line 1715 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 45: /* Type: ID  */
#line 200 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {
        struct typeTable* type = getTypeTableWithName((yyvsp[0].node)->varName);
        if(type == NULL){
            printf("Error: type is used but not declared: %s\n",(yyvsp[0].node)->varName);
            exit(EXIT_FAILURE);
        }
        (yyvsp[0].node)->type = createUserDefinedTypeWithName((yyvsp[0].node)->varName);
        (yyval.node) = (yyvsp[0].node);
       }
#line 1729 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 46: /* GidList: GidList ',' Gid  */
#line 211 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1737 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 47: /* GidList: Gid  */
#line 214 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1745 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 49: /* Gid: DeclArray  */
#line 221 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1753 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 50: /* Gid: ID '(' ParamList ')'  */
#line 224 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                                (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-3].node),(yyvsp[-1].node),NULL,10);
                                (yyval.node)->type = (yyvsp[-3].node)->type;
                            }
#line 1762 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* Gid: ID '(' ')'  */
#line 228 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {  
                    (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-2].node),NULL,NULL,10);
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1771 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* Gid: '*' Gid  */
#line 232 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                    (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1780 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 53: /* ParamList: ParamList ',' Param  */
#line 238 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            (yyval.node) = createOperatorNode(OP_PARAMLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1788 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 54: /* ParamList: Param  */
#line 241 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1796 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 55: /* Param: Type Pid  */
#line 246 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = createOperatorNode(OP_PARAM,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    (yyval.node)->type = (yyvsp[0].node)->type;
                }
#line 1805 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 56: /* Pid: ID  */
#line 252 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
         {
            (yyval.node) = (yyvsp[0].node);
            }
#line 1813 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 57: /* Pid: '*' Pid  */
#line 255 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
            (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
            (yyval.node) = (yyvsp[0].node); 
        }
#line 1822 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 58: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 262 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1830 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 59: /* LDeclBlock: DECL ENDDECL  */
#line 265 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1836 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 60: /* LDeclList: LDeclList LDecl  */
#line 268 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1844 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 61: /* LDeclList: LDecl  */
#line 271 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1852 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 62: /* LDecl: Type LidList ';'  */
#line 276 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1860 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 63: /* LidList: LidList ',' Lid  */
#line 281 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1868 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 64: /* LidList: Lid  */
#line 284 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1876 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 66: /* Lid: DeclArray  */
#line 291 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1884 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 67: /* Lid: '*' Lid  */
#line 294 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
        (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1893 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 69: /* FDefBlock: FDef  */
#line 302 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {}
#line 1899 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 70: /* FDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 305 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1916 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 71: /* FDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 317 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1932 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 72: /* Slist: Slist Stmt  */
#line 330 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1941 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 73: /* Slist: Stmt  */
#line 334 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1949 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 86: /* Stmt: NewStmt  */
#line 352 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1957 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 87: /* AllocStmt: Identifier '=' ALLOC '(' ')' ';'  */
#line 357 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                             {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_ALLOC,(yyvsp[-5].node),NULL,NULL,label);
}
#line 1966 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 88: /* NewStmt: Identifier '=' NEW '(' ID ')' ';'  */
#line 363 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {
    int label = getLabel();
    (yyval.node) = createOperatorNode(LEAF_NEW,(yyvsp[-6].node),(yyvsp[-2].node),NULL,label);
}
#line 1975 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 89: /* InitialiseStmt: INITIALISE '(' ')' ';'  */
#line 369 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_INITIALISE,NULL,NULL,NULL,label);
}
#line 1984 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 90: /* FreeStmt: FREE '(' Identifier ')' ';'  */
#line 375 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                       {
    int label = getLabel();
    (yyval.node) = createOperatorNode(OP_FREE,(yyvsp[-2].node),NULL,NULL,label);
}
#line 1993 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 91: /* RetStmt: RETURN E ';'  */
#line 381 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_RETURN,(yyvsp[-1].node),NULL,NULL,label);
        }
#line 2002 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 92: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 387 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                     { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node),label);
                                                  }
#line 2011 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 93: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF ';'  */
#line 391 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                        }
#line 2020 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 94: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE ';'  */
#line 398 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                                }
#line 2029 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 95: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 404 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 2038 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 96: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 410 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 2047 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 97: /* AsgStmt: Identifier '=' E ';'  */
#line 416 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 2056 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 99: /* ContinueStmt: CONTINUE ';'  */
#line 424 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2064 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 100: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 429 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 2073 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 101: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 435 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 2082 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 102: /* B: E '<' E  */
#line 441 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2090 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 103: /* B: E '>' E  */
#line 444 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2098 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 104: /* B: E GE E  */
#line 447 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2106 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 105: /* B: E LE E  */
#line 450 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2114 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 106: /* B: E NE E  */
#line 453 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2122 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 107: /* B: E EQ E  */
#line 456 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2130 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 108: /* E: E '+' E  */
#line 461 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2138 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 109: /* E: E '*' E  */
#line 464 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2146 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 110: /* E: E '-' E  */
#line 467 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2154 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 111: /* E: E '/' E  */
#line 470 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2162 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 112: /* E: E '%' E  */
#line 473 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2170 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 113: /* E: '&' ID  */
#line 476 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 2178 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 114: /* E: '(' E ')'  */
#line 479 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 2186 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 115: /* E: ID '(' ')'  */
#line 482 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-2].node),NULL,NULL,-1);
                }
#line 2194 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 116: /* E: ID '(' ArgList ')'  */
#line 485 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                            (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                        }
#line 2202 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 117: /* E: E '.' ID '(' ')'  */
#line 488 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {
                            (yyval.node) = createOperatorNode(LEAF_METHOD,(yyvsp[-4].node),(yyvsp[-2].node),NULL,-1);
                        }
#line 2210 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 118: /* E: E '.' ID '(' ArgList ')'  */
#line 491 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                            (yyval.node) = createOperatorNode(LEAF_METHOD,(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node),-1);
                        }
#line 2218 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 119: /* E: E ARROW ID '(' ')'  */
#line 494 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {      
                            struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-4].node),NULL,NULL,-1);
                            (yyval.node) = createOperatorNode(LEAF_METHOD,temp,(yyvsp[-2].node),NULL,-1);
                        }
#line 2227 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 120: /* E: E ARROW ID '(' ArgList ')'  */
#line 498 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {
                            struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-5].node),NULL,NULL,-1);
                            (yyval.node) = createOperatorNode(LEAF_METHOD,temp,(yyvsp[-3].node),(yyvsp[-1].node),-1);
                        }
#line 2236 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 123: /* E: CSTR  */
#line 505 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 2244 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 124: /* ArgList: ArgList ',' E  */
#line 510 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_ARGLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 2252 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 125: /* ArgList: E  */
#line 513 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2260 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 126: /* DeclArray: ID DeclBraceList  */
#line 518 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1); 
                        (yyval.node)->type = (yyvsp[-1].node)->type;
                    }
#line 2269 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 127: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 524 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 2277 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 128: /* DeclBraceList: '[' NUM ']'  */
#line 527 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2285 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 129: /* Array: ID BraceList  */
#line 532 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 2293 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 130: /* BraceList: BraceList '[' E ']'  */
#line 537 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 2301 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 131: /* BraceList: '[' E ']'  */
#line 540 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2309 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 134: /* Identifier: SELF  */
#line 548 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2317 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 135: /* Identifier: '*' E  */
#line 551 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 2325 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 136: /* Identifier: E '.' ID  */
#line 554 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2333 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 137: /* Identifier: E ARROW ID  */
#line 557 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-2].node),NULL,NULL,-1);
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,temp,(yyvsp[0].node),NULL,-1);
            }
#line 2342 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 2346 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 563 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"


int yyerror(const char* s){
    printf("Error: %s\ntoken: %s\n",s,yytext); 
    return 0;
}

int main(int argc,char** argv){
    if(argc > 2){
        yyin = fopen(argv[1],"r"); 
        out = fopen(argv[2],"w");
        setOutputStream(out);
    } else{
        printf("Insufficient Args: <exe> <input> <output>\n");
        exit(EXIT_FAILURE);
    }
    initCompiler(out);
    cprintf(out,"JMP L0\n");
    yyparse();
    return 0;
}
