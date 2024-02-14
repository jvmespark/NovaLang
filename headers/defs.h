#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXTLEN		512	


enum {
  T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT, T_SEMI, T_PRINT, T_EQUALS, T_INT, T_IDENT,
};


struct token {
  int token;			
  int intvalue;			
};


enum {
  A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT, A_LVIDENT, A_ASSIGN, A_IDENT, 
};


struct ASTnode {
  int op;			
  struct ASTnode *left;		
  struct ASTnode *right;
  union {
    int intvalue;
    int id; // symbol slot id
  } v;	
};


struct symTable {
  char *name;
};