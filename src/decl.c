#include "../headers/defs.h"
#include "../headers/data.h"
#include "../headers/decl.h"

void var_declaration() {
    match(T_INT, "int");
    ident();
    addglob(Text);
    genglobsym(Text);
    semi();
}
