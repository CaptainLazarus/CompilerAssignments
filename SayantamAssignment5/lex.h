// lex.h the header file for the scanner
#ifndef LEX_H
#define LEX_H
#define END 256
#define NUM 257
#define ID 258

#include<stdio.h>

typedef struct{
	int tokenClass;
	int val;
}token_t;

extern token_t token;
void getNextToken(void);
#endif
