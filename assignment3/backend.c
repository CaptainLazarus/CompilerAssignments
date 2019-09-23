#include<stdio.h>
#include"backend.h"

int ans;
int flag;

int inorderOnAST(ASTnode_t * a){
    if(a != NULL){
        int temp1 = inorderOnAST(a->left);
        int temp2 = inorderOnAST(a->right);

        if(a->type == 'D'){
            return a->val;
        }
        else if(a->type == 'R'){
            int temp;
            printf("R: ");
            scanf("%d" , &temp);
            return temp;
        }
        else if(a->type == 'I'){
            if(a->op == '+')
                flag = 0;
            else
                flag = 1;
        }
        
        if(flag == 0){
            return temp1+temp2;
        }
        else{
            return temp1*temp2;
        }
    }
    return 0;
}