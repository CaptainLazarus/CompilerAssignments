#ifndef SYMTAB_H
#define SYMTAB_H
#define SIZE 60

typedef struct {
int def; // 1: defined, 0: undefined
int val; // value assigned to the identifier
} symRec;

extern symRec symTab[SIZE];
void initSymTab();

// every location is undefined

void updateSymTab(int index, int val); // updates the indexed loc.
int getVal(int index);
int isDefined(int index);
void define(int index);

// returns error (1) or OK (0)
// *vP is the value of indexed loc.

#endif