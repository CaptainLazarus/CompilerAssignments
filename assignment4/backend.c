#include<stdio.h>
#include"backend.h"
#include"symTab.h"

int ans;
int flag;
int flag2;

int inorderOnAST(ASTnode_t * a){
    if(a != NULL){
        int temp1 = inorderOnAST(a->left);
        int temp2 = inorderOnAST(a->right);

        if(a->type == 'D'){
            return a->val;
        }
        else if(a->type == 'R'){
            if(flag2 == 0){
                int temp;
                printf("R: ");
                scanf("%d" , &temp);
                return temp;
            }
            return 0;
        }
        else if(a->type == 'V'){
            //get value from table
            //If not present return  
            //If present just return normal value
            if( isDefined( (a->op)-65 ) == 1){
                return getVal( (a->op)-65 );
            }
            else
            {
                // flag2 = 1;
                return (-1*a->op);
            }
        }
        else if(a->type == 'I'){
            if(a->op == '+')
                flag = 0;
            else if(a->op == '*')
                flag = 1;
            else if(a->op == ',')
                flag = 2;
            else if(a->op == '=')
                flag = 3;
        }
        

        //Need to check if temp 1 or temp 2 is -1 except in '=' case
        //If yes need to return an error message.
        if(flag != 3){
            if(temp1 < 0 || temp2 < 0){
                if(temp1 < 0){
                    // printf("Variable %c is not defined\n" , -temp1);
                    flag2 = 1;
                    return temp1;
                }   
                if(temp2 < 0){
                    // printf("Variable %c is not defined\n" , -temp2);
                    flag2 = 1;
                    return temp2;
                }
                
            }
            else{ 
                if(flag == 0){
                    return temp1+temp2;
                }
                else if(flag == 1){
                    return temp1*temp2;
                }
                else if(flag == 2){
                    return temp2;
                }
            }
        }
        else if(flag == 3){
            if(temp1 < 0 && temp2 >= 0){
                updateSymTab( ((-temp1)-65) , temp2);
                define(((-temp1)-65));
                return temp2;
            }
            else if(temp2 < 0){
                printf("Variable %c is not defined\n" , -temp2);
                flag2 = 1;
                return -1;
            }
            else if(temp1 >= 0 && temp2 >= 0)
            {
                printf("Variable %c already assigned value\n" , a->left->op);
                flag2 = 1;
                return -1;
            }
            
        }
    }
    return 0;
}