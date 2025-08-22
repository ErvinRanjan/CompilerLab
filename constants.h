/**
 * @brief header file to store constants
 */

#ifndef CONSTANTS_H 
#define CONSTANTS_H 

 // constants for operators

#define OP_ADD 1 
#define OP_SUB 2
#define OP_MUL 3 
#define OP_DIV 4 
#define OP_READ 5 
#define OP_WRITE 6 
#define OP_ASSIGN 7
#define OP_STMTLIST 8
#define OP_IF 9
#define OP_WHILE 10
#define OP_GT 11 
#define OP_LT 12 
#define OP_GE 13 
#define OP_LE 14
#define OP_NE 15
#define OP_EQ 16
#define OP_END 17
#define LEAF_ID 18
#define LEAF_NUM 19
#define LEAF_BREAK 20 
#define LEAF_CONTINUE 21
#define OP_VARLIST 22 
#define OP_DECL 23
#define OP_DECLLIST 24 
#define LEAF_STR 27

// constants for types

#define LEAF_TYPE_INT 25
#define LEAF_TYPE_STR 26 

// limits 

#define MAX_VARNAME_LEN 1001
#define MAX_ARR_LEN 1001

// general constants

#define ENTRY_POINT 2056 
#define INIT_SP 4608
#define MEM_START 4096
#define MAX_STACK_SPACE 512
#define MAX_CSTR_LEN 1001

// file descriptors 

#define XSM_STDOUT -2
#define XSM_STDIN -1

#endif 


