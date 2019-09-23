#include"lex.h"
#include "parser.h"
#include<stdio.h>
#include<stdlib.h>

void newNode(ASTnode_t ** a)
{
    *a = (ASTnode_t *)malloc(sizeof(ASTnode_t));
    (*a)->left = NULL;
    (*a)->right = NULL;
    (*a)->val = 0;
    (*a)->op = '0';
    (*a)->type = '0';
}


int track[4];
int flags[3];

void printTrack(){
    printf("%d %d %d %d\n" , track[0] , track[1]  , track[2] , track[3]);
}

void printFlag(){
    printf("%d %d %d\n" , flags[0] , flags[1]  , flags[2]);
}

int parser(ASTnode_t **a)
{
    if(a != NULL){ 
        getNextToken();
        if(token.tokenClass == '(')
        {
            track[2] += 1;
            // printf("Created I node\n");
            (*a)->type = 'I';
            // printf("Assigned Type\n");
            newNode( &((*a)->left) );
            newNode( &((*a)->right) );
            flags[0] = parser( &((*a)->left));
            flags[1] = parser(a);
            flags[2] = parser( &((*a)->right) );
            // printFlag();
            if(flags[0] == 0|| flags[1] == 0 || flags[2] == 0){
                return 0;
            }
            getNextToken();
            if (token.tokenClass == ')')
            {
                return 1;
            }
        }
        else if(token.tokenClass == NUM)
        {
            // printf("Created D node\n");
            (*a)->type = 'D';
            (*a)->val = token.val;
            track[0]+=1;
            return 1;
        }
        else if(token.tokenClass == 'r'){
            // printf("Created R Node\n");
            (*a)->type = 'R';
            return 1;
        }
        else if(token.tokenClass == ID)
        {
            // printf("Created V Node\n");
            (*a)->type = 'V'; 
            (*a)->op = token.val;
            track[3]+=1;
            return 1;
        }
        
        if( token.tokenClass == '+' || 
            token.tokenClass == '*' || 
            token.tokenClass == ',')
        {   
            (*a)->op = token.tokenClass;
            track[1]+=1;
            return 1;
        }
        else if (token.tokenClass == '=')
        {
            // printf("Left Type: %c\n" , (*a)->left->type);
            if( (*a)->left->type == 'V')
            {
                (*a)->op = token.tokenClass;
                track[1]+=1;
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

// void printTree(ASTnode_t *a){
//     if(a!=NULL){
//         printTree(a->left);
//         printf("%d %c\n" , a->val , a->op);
//         printTree(a->right); 
//     }
// }