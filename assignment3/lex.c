//All comments are debugging statements

#include<stdio.h>
#include"lex.h"

token_t token;
int currentNum;
int x;

void getNextToken(void){
    char c;
    c = getchar();
    token.val=0;
    if( c!=32 && c!=10 && c!=9 ){
        if(c == EOF){
            token.tokenClass = END;
            printf("END\n");
        }
        else if(c>=48 && c<=57){
            token.tokenClass = NUM;
            ungetc(c , stdin);
            scanf("%d", &token.val);
            // printf("%d " , token.val);
        }
        else{
            token.tokenClass = c;
            token.val = c;
            // printf("%c",c);
        }
    }
    
}

// int main(){
//     while(token.tokenClass != END){
//         getNextToken();
//     }
// }