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
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '&'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_Program = 54,                   /* Program  */
  YYSYMBOL_TypeDeclBlock = 55,             /* TypeDeclBlock  */
  YYSYMBOL_TypeDeclList = 56,              /* TypeDeclList  */
  YYSYMBOL_TypeDecl = 57,                  /* TypeDecl  */
  YYSYMBOL_PartialTypeDecl = 58,           /* PartialTypeDecl  */
  YYSYMBOL_MainBlock = 59,                 /* MainBlock  */
  YYSYMBOL_Body = 60,                      /* Body  */
  YYSYMBOL_GDeclBlock = 61,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 62,                 /* GDeclList  */
  YYSYMBOL_GDecl = 63,                     /* GDecl  */
  YYSYMBOL_Type = 64,                      /* Type  */
  YYSYMBOL_GidList = 65,                   /* GidList  */
  YYSYMBOL_Gid = 66,                       /* Gid  */
  YYSYMBOL_ParamList = 67,                 /* ParamList  */
  YYSYMBOL_Param = 68,                     /* Param  */
  YYSYMBOL_Pid = 69,                       /* Pid  */
  YYSYMBOL_LDeclBlock = 70,                /* LDeclBlock  */
  YYSYMBOL_LDeclList = 71,                 /* LDeclList  */
  YYSYMBOL_LDecl = 72,                     /* LDecl  */
  YYSYMBOL_LidList = 73,                   /* LidList  */
  YYSYMBOL_Lid = 74,                       /* Lid  */
  YYSYMBOL_FDefBlock = 75,                 /* FDefBlock  */
  YYSYMBOL_FDef = 76,                      /* FDef  */
  YYSYMBOL_Slist = 77,                     /* Slist  */
  YYSYMBOL_Stmt = 78,                      /* Stmt  */
  YYSYMBOL_RetStmt = 79,                   /* RetStmt  */
  YYSYMBOL_Ifstmt = 80,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 81,                 /* Whilestmt  */
  YYSYMBOL_InputStmt = 82,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 83,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 84,                   /* AsgStmt  */
  YYSYMBOL_BreakStmt = 85,                 /* BreakStmt  */
  YYSYMBOL_ContinueStmt = 86,              /* ContinueStmt  */
  YYSYMBOL_RepeatUntilStmt = 87,           /* RepeatUntilStmt  */
  YYSYMBOL_DoWhileStmt = 88,               /* DoWhileStmt  */
  YYSYMBOL_B = 89,                         /* B  */
  YYSYMBOL_E = 90,                         /* E  */
  YYSYMBOL_ArgList = 91,                   /* ArgList  */
  YYSYMBOL_DeclArray = 92,                 /* DeclArray  */
  YYSYMBOL_DeclBraceList = 93,             /* DeclBraceList  */
  YYSYMBOL_Array = 94,                     /* Array  */
  YYSYMBOL_BraceList = 95,                 /* BraceList  */
  YYSYMBOL_Identifier = 96                 /* Identifier  */
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
#define YYLAST   453

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
       2,     2,     2,     2,     2,     2,     2,    36,    49,     2,
      44,    45,    39,    37,    46,    38,    52,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      47,    35,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    33,    33,    34,    35,    36,    37,    38,    41,    42,
      47,    48,    51,    57,    63,    75,    79,    84,    89,    92,
      95,   100,   105,   106,   110,   122,   125,   130,   131,   135,
     140,   145,   151,   154,   159,   165,   168,   175,   178,   181,
     184,   189,   194,   197,   202,   203,   207,   213,   214,   218,
     230,   243,   247,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   266,   272,   276,   283,   289,   295,   301,   307,
     308,   314,   320,   326,   329,   332,   335,   338,   341,   346,
     349,   352,   355,   358,   361,   364,   367,   370,   373,   374,
     375,   381,   384,   389,   395,   398,   403,   408,   411,   416,
     417,   421,   424,   427
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
  "MAIN", "RETURN", "TYPEDECL", "ENDTYPEDECL", "TUPLE", "STRUCT", "'='",
  "'%'", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'<'", "'>'", "'&'", "'['", "']'", "'.'", "$accept", "Program",
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
      53,   320,     1,    88,    87,   131,  -135,    11,  -135,  -135,
    -135,  -135,   334,  -135,    27,    46,  -135,    93,    80,    83,
      95,  -135,  -135,    11,     1,  -135,    29,    11,  -135,  -135,
    -135,    36,    27,   -23,  -135,  -135,   102,  -135,  -135,  -135,
     121,  -135,    11,  -135,    29,   104,  -135,  -135,     3,   149,
     108,  -135,  -135,    27,   113,    29,    43,  -135,  -135,  -135,
      17,  -135,    33,   117,   156,  -135,   151,  -135,   132,   121,
     135,    78,  -135,  -135,   129,   349,   183,  -135,  -135,   151,
     148,  -135,  -135,    30,   357,  -135,   157,   152,   183,   151,
     140,    30,    67,  -135,  -135,  -135,  -135,  -135,    44,  -135,
     153,   158,   159,   163,   286,   150,   166,  -135,   286,   123,
     123,   191,   178,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,   401,  -135,   165,  -135,   168,   183,  -135,
    -135,    30,    70,   123,   162,   123,   123,   123,   123,   307,
    -135,  -135,   211,   164,  -135,   348,  -135,   123,  -135,   215,
     123,   123,   293,   123,   123,   219,   123,  -135,   184,  -135,
    -135,   401,    84,   358,   123,   185,   366,   189,   331,   190,
     192,   196,  -135,   376,  -135,   325,   -27,   224,   -27,   164,
     164,  -135,   384,  -135,  -135,   123,  -135,   393,   200,   201,
     239,   123,   123,   123,   123,   123,   123,   240,   123,   123,
    -135,  -135,  -135,   401,  -135,  -135,  -135,   286,   401,   401,
     401,   401,   401,   401,   286,   212,   216,   130,   238,    -5,
     213,   286,   226,   227,  -135,  -135,   259,  -135,  -135,   231,
    -135
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
       0,     0,    85,     0,    15,    83,    79,     0,    81,    80,
      82,   102,     0,    49,    87,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,   103,    68,    91,    97,    66,    67,     0,    75,    76,
      77,    78,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    71,     0,    64,    65,     0,
      63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   256,  -135,  -135,   206,   -82,   271,  -135,
     266,     7,  -135,    40,    35,   214,    26,   -65,  -135,   197,
    -135,   -81,   261,    10,  -103,  -110,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -134,   -93,  -135,   -80,
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
     125,   139,   148,    94,   169,   142,   127,     8,    14,   214,
     129,    94,   153,   154,    88,     8,   143,   145,   125,    14,
      52,     8,   125,    53,   128,   155,   125,    10,    11,   148,
      15,    31,   148,    43,    90,    24,    11,    47,   224,   161,
     163,    10,    11,   166,   168,   168,   158,    55,    61,   165,
     159,    94,    47,   125,   173,    55,   125,   175,   176,   178,
     179,   180,    70,   182,   215,   216,    32,    55,    44,    91,
      59,   187,    51,    97,    98,     1,    55,     2,    72,    69,
      48,    67,    83,    62,     3,    68,    49,    21,   132,    69,
      36,    83,   203,    65,   133,    71,   107,    37,   208,   209,
     210,   211,   212,   213,   217,   168,   168,   148,   148,   109,
     130,   218,    38,   131,   110,   160,   148,    17,   226,   111,
      16,   125,    17,    80,    69,     8,    97,    98,   125,   184,
     185,   125,   125,    97,    98,   125,    40,   100,   101,   102,
     125,   221,   222,   103,   104,    10,    11,    54,    60,   107,
     105,   106,    63,     1,    66,     2,   107,   108,    64,    74,
      97,    98,   109,    99,   100,   101,   102,   110,    73,   109,
     103,   104,   111,    75,   110,    77,    79,   105,   106,   111,
      81,    97,    98,   107,   108,   100,   101,   102,    86,    89,
      49,   103,   104,   140,   126,   146,   109,   135,   105,   106,
     156,   110,   136,   137,   107,   108,   111,   138,   147,   141,
     157,    22,   164,    25,    97,    98,   155,   109,   100,   101,
     102,   174,   110,   181,   103,   104,   183,   111,   201,    41,
     188,   105,   106,    46,   190,   197,   198,   107,   108,   171,
     199,    97,    98,   205,   206,   100,   101,   102,    58,   207,
     109,   103,   104,   223,   214,   110,   225,   219,   105,   106,
     111,   220,    97,    98,   107,   108,   100,   101,   102,   227,
     228,   229,   103,   104,   230,    39,    23,   109,    30,   105,
     106,    96,   110,    78,    42,   107,   108,   111,     0,    97,
      98,     0,     0,   100,   101,   102,    97,    98,   109,   103,
     104,     0,     0,   110,     0,     0,   105,   106,   111,     0,
      97,    98,   107,   108,   100,   101,   102,     0,     0,   107,
     170,   104,     0,     0,     8,   109,     0,   105,   106,     0,
     110,     0,   109,   107,   108,   111,     0,   110,     8,     0,
       0,   177,   111,     9,    10,    11,   109,   191,   192,   193,
     194,   110,     0,     8,     0,     0,   111,    29,    10,    11,
       0,     8,   151,   152,   153,   154,     0,   150,   151,   152,
     153,   154,    82,    10,    11,     0,     0,   155,   195,   196,
      95,    10,    11,   155,   150,   151,   152,   153,   154,     0,
       0,     0,     0,   172,   150,   151,   152,   153,   154,     0,
     155,     0,   150,   151,   152,   153,   154,     0,     0,   186,
     155,   189,   150,   151,   152,   153,   154,     0,   155,   200,
     150,   151,   152,   153,   154,     0,     0,   202,   155,   150,
     151,   152,   153,   154,     0,     0,   155,   150,   151,   152,
     153,   154,     0,     0,   204,   155,     0,     0,     0,     0,
       0,     0,     0,   155
};

static const yytype_int16 yycheck[] =
{
      86,   104,   112,    83,   138,   108,    88,     4,     1,    14,
      91,    91,    39,    40,    79,     4,   109,   110,   104,    12,
      43,     4,   108,    46,    89,    52,   112,    24,    25,   139,
      29,     4,   142,     4,     4,    24,    25,    27,    43,   132,
     133,    24,    25,   136,   137,   138,   128,    40,    45,   135,
     131,   131,    42,   139,   147,    48,   142,   150,   151,   152,
     153,   154,    45,   156,   198,   199,    39,    60,    39,    39,
      44,   164,    32,     3,     4,    22,    69,    24,    45,    46,
      44,    55,    75,    48,    31,    42,    50,     0,    44,    46,
      44,    84,   185,    53,    50,    60,    26,     4,   191,   192,
     193,   194,   195,   196,   207,   198,   199,   217,   218,    39,
      43,   214,    32,    46,    44,    45,   226,    34,   221,    49,
      32,   207,    34,    45,    46,     4,     3,     4,   214,    45,
      46,   217,   218,     3,     4,   221,    41,     7,     8,     9,
     226,    11,    12,    13,    14,    24,    25,    45,    44,    26,
      20,    21,     3,    22,    41,    24,    26,    27,    50,     3,
       3,     4,    39,     6,     7,     8,     9,    44,    51,    39,
      13,    14,    49,    22,    44,    43,    41,    20,    21,    49,
      51,     3,     4,    26,    27,     7,     8,     9,     5,    41,
      50,    13,    14,    43,    42,     4,    39,    44,    20,    21,
      35,    44,    44,    44,    26,    27,    49,    44,    30,    43,
      42,     5,    50,     7,     3,     4,    52,    39,     7,     8,
       9,     6,    44,     4,    13,    14,    42,    49,     4,    23,
      45,    20,    21,    27,    45,    45,    44,    26,    27,    28,
      44,     3,     4,    43,    43,     7,     8,     9,    42,    10,
      39,    13,    14,    15,    14,    44,    43,    45,    20,    21,
      49,    45,     3,     4,    26,    27,     7,     8,     9,    43,
      43,    12,    13,    14,    43,    19,     5,    39,    12,    20,
      21,    84,    44,    69,    23,    26,    27,    49,    -1,     3,
       4,    -1,    -1,     7,     8,     9,     3,     4,    39,    13,
      14,    -1,    -1,    44,    -1,    -1,    20,    21,    49,    -1,
       3,     4,    26,    27,     7,     8,     9,    -1,    -1,    26,
      13,    14,    -1,    -1,     4,    39,    -1,    20,    21,    -1,
      44,    -1,    39,    26,    27,    49,    -1,    44,     4,    -1,
      -1,    48,    49,    23,    24,    25,    39,    16,    17,    18,
      19,    44,    -1,     4,    -1,    -1,    49,    23,    24,    25,
      -1,     4,    37,    38,    39,    40,    -1,    36,    37,    38,
      39,    40,    23,    24,    25,    -1,    -1,    52,    47,    48,
      23,    24,    25,    52,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    36,    37,    38,    39,    40,    -1,
      52,    -1,    36,    37,    38,    39,    40,    -1,    -1,    51,
      52,    45,    36,    37,    38,    39,    40,    -1,    52,    43,
      36,    37,    38,    39,    40,    -1,    -1,    43,    52,    36,
      37,    38,    39,    40,    -1,    -1,    52,    36,    37,    38,
      39,    40,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    24,    31,    54,    55,    59,    61,     4,    23,
      24,    25,    62,    63,    64,    29,    32,    34,    56,    57,
      58,     0,    59,    61,    24,    59,    64,    75,    76,    23,
      63,     4,    39,    65,    66,    92,    44,     4,    32,    56,
      41,    59,    75,     4,    39,    69,    59,    76,    44,    50,
      93,    66,    43,    46,    45,    64,    67,    68,    59,    69,
      44,    45,    67,     3,    50,    66,    41,    69,    42,    46,
      45,    67,    45,    51,     3,    22,    70,    43,    68,    41,
      45,    51,    23,    64,    71,    72,     5,    60,    70,    41,
       4,    39,    73,    74,    92,    23,    72,     3,     4,     6,
       7,     8,     9,    13,    14,    20,    21,    26,    27,    39,
      44,    49,    77,    78,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    90,    94,    96,    42,    60,    70,    74,
      43,    46,    44,    50,    95,    44,    44,    44,    44,    77,
      43,    43,    77,    90,    96,    90,     4,    30,    78,    79,
      36,    37,    38,    39,    40,    52,    35,    42,    60,    74,
      45,    90,    91,    90,    50,    96,    90,    89,    90,    89,
      13,    28,    45,    90,     6,    90,    90,    48,    90,    90,
      90,     4,    90,    42,    45,    46,    51,    90,    45,    45,
      45,    16,    17,    18,    19,    47,    48,    45,    44,    44,
      43,     4,    43,    90,    51,    43,    43,    10,    90,    90,
      90,    90,    90,    90,    14,    89,    89,    77,    77,    45,
      45,    11,    12,    15,    43,    43,    77,    43,    43,    12,
      43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    57,    58,    59,    60,    60,    61,    61,    62,
      62,    63,    64,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    73,    73,    74,    74,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    80,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    93,    93,    94,    95,    95,    96,
      96,    96,    96,    96
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
       1,     2,     3,     4
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
#line 1371 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 9: /* TypeDeclBlock: TYPEDECL TypeDeclList ENDTYPEDECL  */
#line 42 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                  {
                printTypeTable();
              }
#line 1379 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 10: /* TypeDeclList: TypeDecl TypeDeclList  */
#line 47 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                     {}
#line 1385 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 11: /* TypeDeclList: TypeDecl  */
#line 48 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {}
#line 1391 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 12: /* TypeDecl: PartialTypeDecl '{' ParamList '}' ';'  */
#line 51 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {
                int numberOfParam = 0;
                updateTypeTable((yyvsp[-4].node)->varName,convertTreeToParamList((yyvsp[-2].node),&numberOfParam,NULL));
            }
#line 1400 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 13: /* PartialTypeDecl: STRUCT ID  */
#line 57 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                        populateTypeTable((yyvsp[0].node)->varName,NULL);
                        (yyval.node) = (yyvsp[0].node);
            }
#line 1409 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 14: /* MainBlock: INT MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 63 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1424 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 15: /* Body: BLOCK_BEGIN Slist RetStmt BLOCK_END  */
#line 75 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {
                               (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                               (yyval.node)->label = (yyvsp[-2].node)->label;
                           }
#line 1433 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 16: /* Body: BLOCK_BEGIN BLOCK_END  */
#line 79 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            
                                }
#line 1441 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 17: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 84 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        gsymbolTable = populateSymbolTable((yyvsp[-1].node),gsymbolTable,0); 
                                        gsymbolTable->isGlobal = 1;
                                        printSymbolTable("global",gsymbolTable);
                                    }
#line 1451 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 18: /* GDeclBlock: DECL ENDDECL  */
#line 89 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1457 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 19: /* GDeclList: GDeclList GDecl  */
#line 92 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1465 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 20: /* GDeclList: GDecl  */
#line 95 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1473 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 21: /* GDecl: Type GidList ';'  */
#line 100 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1481 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 23: /* Type: STR  */
#line 107 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
     {
        (yyval.node) = (yyvsp[0].node);
     }
#line 1489 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 24: /* Type: ID  */
#line 111 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {
        struct typeTable* type = getTypeTableWithName((yyvsp[0].node)->varName);
        if(type == NULL){
            printf("Error: type is used but not declared: %s\n",(yyvsp[0].node)->varName);
            exit(EXIT_FAILURE);
        }
        (yyvsp[0].node)->type = createUserDefinedTypeWithName((yyvsp[0].node)->varName);
        (yyval.node) = (yyvsp[0].node);
       }
#line 1503 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 25: /* GidList: GidList ',' Gid  */
#line 122 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1511 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 26: /* GidList: Gid  */
#line 125 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1519 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 28: /* Gid: DeclArray  */
#line 132 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1527 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 29: /* Gid: ID '(' ParamList ')'  */
#line 135 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                                (yyval.node)->type = (yyvsp[-3].node)->type;
                            }
#line 1537 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 30: /* Gid: ID '(' ')'  */
#line 140 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {  
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(LEAF_FDECL,(yyvsp[-2].node),NULL,NULL,label);
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1547 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 31: /* Gid: '*' Gid  */
#line 145 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                    (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1556 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 32: /* ParamList: ParamList ',' Param  */
#line 151 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                            (yyval.node) = createOperatorNode(OP_PARAMLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1564 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 33: /* ParamList: Param  */
#line 154 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1572 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 34: /* Param: Type Pid  */
#line 159 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = createOperatorNode(OP_PARAM,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    (yyval.node)->type = (yyvsp[0].node)->type;
                }
#line 1581 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 35: /* Pid: ID  */
#line 165 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
         {
            (yyval.node) = (yyvsp[0].node);
            }
#line 1589 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 36: /* Pid: '*' Pid  */
#line 168 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
            (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
            (yyval.node) = (yyvsp[0].node); 
        }
#line 1598 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 37: /* LDeclBlock: DECL LDeclList ENDDECL  */
#line 175 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                    {
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1606 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 38: /* LDeclBlock: DECL ENDDECL  */
#line 178 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {}
#line 1612 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 39: /* LDeclList: LDeclList LDecl  */
#line 181 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                            {
                            (yyval.node) = createOperatorNode(OP_DECLLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1620 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 40: /* LDeclList: LDecl  */
#line 184 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                 {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1628 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 41: /* LDecl: Type LidList ';'  */
#line 189 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                        (yyval.node) = createOperatorNode(OP_DECL,(yyvsp[-2].node),(yyvsp[-1].node),NULL,-1);
                    }
#line 1636 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 42: /* LidList: LidList ',' Lid  */
#line 194 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                                (yyval.node) = createOperatorNode(OP_VARLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                            }
#line 1644 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 43: /* LidList: Lid  */
#line 197 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1652 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 45: /* Lid: DeclArray  */
#line 204 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1660 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 46: /* Lid: '*' Lid  */
#line 207 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
        (yyvsp[0].node)->type->depth = (yyvsp[0].node)->type->depth + 1;
        (yyval.node) = (yyvsp[0].node);
    }
#line 1669 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 48: /* FDefBlock: FDef  */
#line 215 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
          {}
#line 1675 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 49: /* FDef: Type Pid '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 218 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1692 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 50: /* FDef: Type Pid '(' ')' '{' LDeclBlock Body '}'  */
#line 230 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
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
#line 1708 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 51: /* Slist: Slist Stmt  */
#line 243 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                   {    
                        (yyval.node) = createOperatorNode(OP_STMTLIST,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                        (yyval.node)->label = (yyvsp[-1].node)->label;
                    }
#line 1717 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 52: /* Slist: Stmt  */
#line 247 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
             { 
                (yyval.node) = (yyvsp[0].node);
             }
#line 1725 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 61: /* Stmt: DoWhileStmt  */
#line 261 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
       {   
        (yyval.node) = (yyvsp[0].node);
       }
#line 1733 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 62: /* RetStmt: RETURN E ';'  */
#line 266 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_RETURN,(yyvsp[-1].node),NULL,NULL,label);
        }
#line 1742 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 63: /* Ifstmt: IF '(' B ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 272 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                     { 
                                                        int label = getLabel();
                                                        (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node),label);
                                                  }
#line 1751 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 64: /* Ifstmt: IF '(' B ')' THEN Slist ENDIF ';'  */
#line 276 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                            {     
                                            int label = getLabel();
                                            (yyval.node) = createOperatorNode(OP_IF,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                        }
#line 1760 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 65: /* Whilestmt: WHILE '(' B ')' DO Slist ENDWHILE ';'  */
#line 283 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                 {   
                                                    int label = getLabel();
                                                    (yyval.node) = createOperatorNode(OP_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                                                }
#line 1769 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 66: /* InputStmt: READ '(' Identifier ')' ';'  */
#line 289 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                        {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_READ,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1778 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 67: /* OutputStmt: WRITE '(' E ')' ';'  */
#line 295 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                 {
                                int label = getLabel();
                                (yyval.node) = createOperatorNode(OP_WRITE,(yyvsp[-2].node),NULL,NULL,label);
                            }
#line 1787 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 68: /* AsgStmt: Identifier '=' E ';'  */
#line 301 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                               {
                      int label = getLabel();
                      (yyval.node) = createOperatorNode(OP_ASSIGN,(yyvsp[-3].node),(yyvsp[-1].node),NULL,label);
                    }
#line 1796 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 70: /* ContinueStmt: CONTINUE ';'  */
#line 309 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
        {
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1804 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 71: /* RepeatUntilStmt: REPEAT Slist UNTIL '(' B ')' ';'  */
#line 314 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                                    {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_REPEAT_UNTIL,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
                }
#line 1813 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 72: /* DoWhileStmt: DO Slist WHILE '(' B ')' ';'  */
#line 320 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                           {
                    int label = getLabel();
                    (yyval.node) = createOperatorNode(OP_DO_WHILE,(yyvsp[-5].node),(yyvsp[-2].node),NULL,label);
            }
#line 1822 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 73: /* B: E '<' E  */
#line 326 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_LT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1830 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 74: /* B: E '>' E  */
#line 329 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_GT,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1838 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 75: /* B: E GE E  */
#line 332 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_GE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1846 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 76: /* B: E LE E  */
#line 335 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_LE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1854 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 77: /* B: E NE E  */
#line 338 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_NE,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1862 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 78: /* B: E EQ E  */
#line 341 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_EQ,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1870 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 79: /* E: E '+' E  */
#line 346 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_ADD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1878 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 80: /* E: E '*' E  */
#line 349 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MUL,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1886 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 81: /* E: E '-' E  */
#line 352 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_SUB,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1894 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 82: /* E: E '/' E  */
#line 355 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_DIV,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1902 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 83: /* E: E '%' E  */
#line 358 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = createOperatorNode(OP_MOD,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 1910 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 84: /* E: '&' ID  */
#line 361 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
           {
                (yyval.node) = createOperatorNode(OP_REF,(yyvsp[0].node),NULL,NULL,-1); 
            }
#line 1918 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 85: /* E: '(' E ')'  */
#line 364 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
              {
                 (yyval.node) = (yyvsp[-1].node);
              }
#line 1926 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 86: /* E: ID '(' ')'  */
#line 367 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
               {
                    (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-2].node),NULL,NULL,-1);
                }
#line 1934 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 87: /* E: ID '(' ArgList ')'  */
#line 370 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                            (yyval.node) = createOperatorNode(LEAF_FUNC,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                        }
#line 1942 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 90: /* E: CSTR  */
#line 376 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
  {
    (yyval.node) = (yyvsp[0].node);
   }
#line 1950 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 91: /* ArgList: ArgList ',' E  */
#line 381 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                         {
                            (yyval.node) = createOperatorNode(OP_ARGLIST,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
                        }
#line 1958 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 92: /* ArgList: E  */
#line 384 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1966 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 93: /* DeclArray: ID DeclBraceList  */
#line 389 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                             {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1); 
                        (yyval.node)->type = (yyvsp[-1].node)->type;
                    }
#line 1975 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 94: /* DeclBraceList: DeclBraceList '[' NUM ']'  */
#line 395 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                          {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 1983 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 95: /* DeclBraceList: '[' NUM ']'  */
#line 398 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                        {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 1991 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 96: /* Array: ID BraceList  */
#line 403 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                     {
                        (yyval.node) = createOperatorNode(LEAF_ARR,(yyvsp[-1].node),(yyvsp[0].node),NULL,-1);
                    }
#line 1999 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 97: /* BraceList: BraceList '[' E ']'  */
#line 408 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                                {
                                        (yyval.node) = createOperatorNode(OP_BRACELIST,(yyvsp[-3].node),(yyvsp[-1].node),NULL,-1);
                                    }
#line 2007 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 98: /* BraceList: '[' E ']'  */
#line 411 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                      {
                            (yyval.node) = (yyvsp[-1].node);
                        }
#line 2015 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 100: /* Identifier: Array  */
#line 418 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
            {
                (yyval.node) = (yyvsp[0].node);
            }
#line 2023 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 101: /* Identifier: '*' E  */
#line 421 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                    {
                (yyval.node) = createOperatorNode(OP_DREF,(yyvsp[0].node),NULL,NULL,-1);
            }
#line 2031 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 102: /* Identifier: E '.' ID  */
#line 424 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                       {
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,(yyvsp[-2].node),(yyvsp[0].node),NULL,-1);
            }
#line 2039 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;

  case 103: /* Identifier: E '-' '>' ID  */
#line 427 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"
                           {
                struct tNode* temp = createOperatorNode(OP_DREF,(yyvsp[-3].node),NULL,NULL,-1);
                (yyval.node) = createOperatorNode(LEAF_TUPLE_ACCESS,temp,(yyvsp[0].node),NULL,-1);
            }
#line 2048 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"
    break;


#line 2052 "/mnt/c/Users/ervin/coding/compilerLab/src/y.tab.c"

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

#line 433 "/mnt/c/Users/ervin/coding/compilerLab/src/yacc/generateExpTree.y"


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
