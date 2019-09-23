#include<stdio.h>
#include"lex.h"
#include"parser.h"
#include"backend.h"

void printTree(ASTnode_t *a){
    if(a!=NULL){
        printTree(a->left);
        printf("%d %c %c\n" , a->val , a->op , a->type);
        printTree(a->right); 
    }
}

int main()
{
    ASTnode_t *a;
    int flag = parser(&a);
    if(flag == 1){
        int ans = inorderOnAST(a);
        if(ans >= 0){
            printf("\nAns: %d\n" , ans);
        }
        else{
            printf("Check Variable Assignment\n");
        }
    }
    else{
        printf("Something is wrong in the syntax.\n");
    }
}