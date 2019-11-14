#include "stack.h"

void init(stack* stk)
{
    stk->tos = -1;
}
int push(stack* stk, int n)
{
    if(stk->tos>=SIZE-1)
        return ERROR;
    stk->tos++;
    stk->data[stk->tos] = n;
    return OK;
}
int pop(stack* stk)
{
    if(stk->tos < 0)
        return ERROR;
    stk->data[stk->tos]=0;
    stk->tos--;
    return OK;
}
int top(stack* stk, int* n)
{
    if(stk->tos < 0)
        return ERROR;        
    (*n) = stk->data[stk->tos];
    return OK;
}
int isEmpty(stack* stk)
{
    if(stk->tos < 0)
        return OK;
    return ERROR;
}
int isFull(stack* stk)
{
    if(stk->tos >= SIZE-1)
        return OK;
    return ERROR;
}