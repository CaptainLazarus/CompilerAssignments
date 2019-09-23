// #include <stdio.h>
// #include<stdlib.h>
// #define END 256
// #define NUM 257
// #include<stdio.h>

// typedef struct { 
//     int tokenClass; 
//     int val; 
// } token_t;


// typedef struct ASTnode_t ASTnode_t;

// struct ASTnode_t{
//     char type;                  // I: internal, D: data, R: read
//     unsigned int val;           // for a node of type D
//     ASTnode_t *left, *right;  // pointers to left and right
//                                 //subtrees for a node of type I
//     char op;                    // the operator in node type I
// };

// token_t token;
// int currentNum;
// int x;
// int ans;
// int flag;


// void getNextToken(void){
//     char c;
//     c = getchar();
//     token.val=0;
//     if( c!=32 && c!=10 && c!=9){
//         if(c == EOF){
//             token.tokenClass = END;
//             // printf("END\n");
//         }
//         else if(c>=48 && c<=57){
//             token.tokenClass = NUM;
//             ungetc(c , stdin);
//             scanf("%d", &token.val);
//             // printf("%d " , token.val);
//         }
//         else{
//             token.tokenClass = c;
//             token.val = c;
//             // printf("%c",c);
//         }
//     }
    
// }

// void newNode(ASTnode_t ** a)
// {
//     *a = (ASTnode_t *)malloc(sizeof(ASTnode_t));
//     (*a)->left = NULL;
//     (*a)->right = NULL;
//     (*a)->val = 0;
//     (*a)->op = 'n';
//     (*a)->type = '0';
// }


// int track[4];

// void printTrack(){
//     printf("%d %d %d\n" , track[0] , track[1]  , track[2]);
// }

// int insert(ASTnode_t **a)
// {
//     if(a != NULL){ 
//         getNextToken();
//         if(token.tokenClass == '(')
//         {
//             track[2] += 1;
//             // printf("Created I node\n");
//             (*a)->type = 'I';
//             // printf("Assigned Type\n");
//             newNode( &((*a)->left) );
//             newNode( &((*a)->right) );
//             insert( &((*a)->left));
//             insert(a);
//             insert( &((*a)->right) );
//             getNextToken();
//             if (token.tokenClass == ')')
//             {
//                 track[2] -= 1;
//             }
//             if(track[2] == 0){
//                 return 1;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//         else if(token.tokenClass == NUM)
//         {
//             // printf("Created D node\n");
//             (*a)->type = 'D';
//             (*a)->val = token.val;
//             track[0]+=1;
//             return 1;
//         }
//         else if(token.tokenClass == 'r'){
//             //printf("Created R Node\n");
//             (*a)->type = 'R';
//         }
//         if(token.tokenClass == '+' || token.tokenClass == '*')
//         {   
//             if((*a)->type == 'I'){
//                 (*a)->op = token.tokenClass;
//                 track[1]+=1;
//             }
//             else{
//                 printf("Somethings wrong\n");
//             }
//         }
//         return 0;
//     }
//     return 0;
// }

// void debugLex(){
//     while(token.tokenClass != END){
//         getNextToken();
//         printf("%d " , token.val);
//     }
// }

// void printTree(ASTnode_t *a){
//     if(a!=NULL){
//         printTree(a->left);
//         printf("%d %c\n" , a->val , a->op);
//         printTree(a->right); 
//     }
// }

// int inorderOnAST(ASTnode_t * a){
//     if(a != NULL){
//         int temp1 = inorderOnAST(a->left);
//         int temp2 = inorderOnAST(a->right);

//         if(a->type == 'D'){
//             return a->val;
//         }
//         else if(a->type == 'R'){
//             int temp;
//             printf("R: ");
//             scanf("%d" , &temp);
//             return temp;
//         }
//         else if(a->type == 'I'){
//             if(a->op == '+')
//                 flag = 0;
//             else
//                 flag = 1;
//         }
        
//         if(flag == 0){
//             return temp1+temp2;
//         }
//         else{
//             return temp1*temp2;
//         }
//     }
// }

#include<stdio.h>
#include"lex.h"
#include"parser.h"
#include"backend.h"

int main()
{
    ASTnode_t *a;
    int flag = parser(&a);
    if(flag == 1){
        int ans = inorderOnAST(a);
        printf("\nAns: %d\n" , ans);
    }
    else{
        printf("Something is wrong in the syntax.\n");
    }
}