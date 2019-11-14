#ifndef PARSER_H
#define PARSER_H

#include "lex.h"
#include "stack.h"
#define LEN 10

#define S 1000
#define CE 1001
#define CEdsh 1002
#define PE 1003
#define ME 1004
#define MEdsh 1005
#define BE 1006
#define AE 1007
#define AEdsh 1008
// E = epsilon
#define E 1009


typedef struct{
		int len; 		// length of right-hand side of the rule
		int rule[LEN]; 	// code sequence of terminals and
						// non-terminals
} rule_t;


int lookup[300];

void initParser();
int parser();


#endif
