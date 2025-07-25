yacc -d <file>.y generates a header y.tab.h
which needs to be included in 

<file>.l , this is done as token declarations are done in <file>.y but is used in <file>.l

yyerror, yylex and main are mandatory functions in <file>.y

