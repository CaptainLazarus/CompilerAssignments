// lex.h the header file for the scannar
#include <stdio.h>
#define END 256
#define NUM 257
#define ID 258

typedef struct {
    int tokenClass; 
    int val; 
} token_t;

extern token_t token;
extern void getNextToken(void);