#ifndef PARSER_H
#define PARSER_H
#define LEN 50

typedef struct node {
    char type;                  // I: internal, D: data, R: read
    unsigned int val;           // for a node of type D
    struct node *left, *right;  // pointers to left and right
                                //subtrees for a node of type I
    char op;                    // the operator in node type I
} ASTnode_t;

typedef struct{
    int len;
    int rule[LEN];
} rule_t;

void defineGrammar();

extern rule_t lang[LEN];

extern int parser(stack *);

// returns 1 on success,
// returns 0 on failure.

#endif