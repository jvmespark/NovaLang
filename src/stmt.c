#include "../headers/defs.h"
#include "../headers/data.h"
#include "../headers/decl.h"

void assignment_statement() {
    struct ASTnode *left, *right, *tree;
    int id;

    ident();
    
    if ((id = findglob(Text)) == -1) {
      fatals("Undeclared Variable", Text);
    }
    right = mkastleaf(A_LVIDENT, id);
    
    match(T_ASSIGN, "=");

    left = binexpr(0);
    
    tree = mkastnode(A_ASSIGN, left, right, 0);

    genAST(tree, -1);
    genfreeregs();
    
    semi();
}

void print_statement(void) {
  struct ASTnode *tree;
  int reg;

  match(T_PRINT, "print");

  tree = binexpr(0);
  reg = genAST(tree, -1);
  genprintint(reg);
  genfreeregs();

  semi();
}

void statements(void) {
  while (1) {
    switch (Token.token) {
      case T_PRINT:
        print_statement();
        break;
      case T_INT:
        var_declaration();
        break;
      case T_IDENT:
        assignment_statement();
        break;
      case T_EOF:
        return;
      default:
        fatald("Syntax error, token", Token.token);
    }
  }
}