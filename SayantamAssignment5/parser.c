#include "parser.h"
#include<stdio.h>

rule_t rules[] = {
    {1, {E}},
	{2, {CE, END}},
	{2, {AE, CEdsh}},
	{3, {',', AE, CEdsh}},
	{3, {'+', ME, PE}},
	{2, {BE, MEdsh}},
	{3, {'*', BE, ME}},
	{3, {'(', CE, ')'}},
	{1, {ID}},
	{1, {NUM}},
	{1, {'r'}},
	{2, {ID, AEdsh}},
	{5, {'(', CE, ')', MEdsh, PE}},
	{3, {NUM, MEdsh, PE}},
	{3, {'r', MEdsh, PE}},
	{2, {'=', AE}},
    {2, {MEdsh, PE}}
	
};

int table[][10] = {
	{ 1,  1,  1, -1, -1, -1, -1,  1, -1, -1},
	{ 2,  2,  2, -1, -1, -1, -1,  2, -1, -1},
	{-1, -1, -1,  3, -1, -1, -1, -1,  0,  0},
	{-1, -1, -1,  0, -1,  4, -1, -1,  0,  0},
	{ 5,  5,  5, -1, -1, -1, -1,  5, -1, -1},
	{-1, -1, -1,  0, -1,  0,  6, -1,  0,  0},
	{ 8,  9, 10, -1, -1, -1, -1,  7, -1, -1},
	{11, 13, 14, -1, -1, -1, -1, 12, -1, -1},
	{-1, -1, -1,  0, 15, 16, 16, -1,  0,  0}
};


void initParser()
{
    int i;
    for(i=0;i<300;i++)
        lookup[i] = -1;

    lookup[ID] = 0;
    lookup[NUM] = 1;
    lookup['r'] = 2;
    lookup[','] = 3;
    lookup['='] = 4;
    lookup['+'] = 5;
    lookup['*'] = 6;
    lookup['('] = 7;
    lookup[')'] = 8;
    lookup[END] = 9;
}

int parser()
{
    initParser();
    stack stk;
    init(&stk);
    push(&stk, S);

    getNextToken();
    while(!isEmpty(&stk))
    {
        int x;
        top(&stk, &x);
        pop(&stk);
        if(x<1000) // terminal
        {   
            if(x != token.tokenClass)                
                return 0;             
            if(!isEmpty(&stk))
                getNextToken();  
        }
        else
        {
            if(lookup[token.tokenClass]==-1)
            {
                printf("Wrong token: %c\n", token.tokenClass);
                return 0;
            }
            int n = table[x-1000][lookup[token.tokenClass]];   
                    
            if(n==-1)
                return 0;
            if(!(rules[n].rule[0] == E))
            {
                int i;
                for(i=rules[n].len-1; i>=0; i--)
                    push(&stk, rules[n].rule[i]);
            }         
        }        
    }
    return 1;
}
