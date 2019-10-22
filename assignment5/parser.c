#include"parser.h"
#include"lex.h"
#include"stack.h"

rule_t lang[LEN];
int table[7][10];

void defineGrammar(){
    int ruleLength[] = {11,3,3,2,2,2,3,3,3,1,1,1,0};
    
    //Defining Length for each production
    for(int i=0 ; i<=ruleLength[0] ; i++){
        lang[i].len = ruleLength[i];
    }

    //Array of all rules (In a 1d array)
    //              1   1       1   2       2   2       3   3       4   4       5   5       6       6   6       7   7       7    8      8   8     9     10   11
    int rule[] = {302 , 301 , END , ',' , 302 , 301 , 306 , 303 , '=' , 303 , 305 , 304 , '+' ,  306 , 303 , '*' , 306 , 305 , '(' , 300 , ')' , ID , NUM , 'r'};
    
    //Putting rules
    int j=0;

    for(int k=1 ; k<=ruleLength[0] ; k++){
        for(int i=0 ; i<lang[k].len ; i++){
            lang[k].rule[i] = rule[j+i];
        }
        j += lang[k].len;
        
    }

    // for(int k=1 ; k<=ruleLength[0] ; k++){
    //     for(int i=0 ; i<lang[k].len ; i++){
    //         printf("%d " , lang[k].rule[i] );
    //     }
    //     printf("\n");
    //     j += lang[k].len;
    // }

    // Predictive Parsing Table

    table[0][0] = table[0][6] = table[0][7] = table[0][8] = 1;
    table[1][1] = table[1][9] = 12; table[1][5] = 2;
    table[2][0] = table[2][6] = table[2][7] = table[2][8] = 3;
    table[3][4] = 4 ; table[3][2] = table[3][3] = table[3][1] = table[3][5] = table[3][9] = 5;

    table[4][2] = 6; table[4][1] = table[4][9] = table[4][5] = 12;
    table[5][3] = 7; table[5][1] = table[5][2] = table[5][5] = table[5][9] = 12;

    //Might get errors here
    table[6][0] = 8;
    table[6][6] = 11;
    table[6][7] = 10;
    table[6][8] = 9;
    

}

int parser(stack *s){ //Might have to change parameter to stack
    while(1){
        getNextToken();
        
    }
}

int main(){
    defineGrammar();
}