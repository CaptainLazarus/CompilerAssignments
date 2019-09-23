#include"lex.h"
#include "parser.h"
#include<stdio.h>
#include<stdlib.h>

int track[3];

void newNode(ASTnode_t ** a)
{
    *a = (ASTnode_t *)malloc(sizeof(ASTnode_t));
    (*a)->left = NULL;
    (*a)->right = NULL;
    (*a)->val = 0;
    (*a)->op = 'n';
    (*a)->type = '0';
}


int track[3];

void printTrack(){
    printf("%d %d %d\n" , track[0] , track[1]  , track[2]);
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
            // printTrack();
            parser( &((*a)->left));
            parser(a);
            parser( &((*a)->right) );
            getNextToken();
            if (token.tokenClass == ')')
            {
                track[2] -= 1;
            }
            if(track[2] == 0){
                printTrack();
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
            //printf("Created R Node\n");
            (*a)->type = 'R';
        }
        if(token.tokenClass == '+' || token.tokenClass == '*')
        {   
            if((*a)->type == 'I'){
                (*a)->op = token.tokenClass;
                track[1]+=1;
            }
            else{
                printf("Somethings wrong\n");
            }
        }
        return 0;
    }
    return 0;
}

void printTree(ASTnode_t *a){
    if(a!=NULL){
        printTree(a->left);
        printf("%d %c\n" , a->val , a->op);
        printTree(a->right); 
    }
}
