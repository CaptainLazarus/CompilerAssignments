#include<stack.h>

void init(stack *s){
    s->tos = -1;
}

int push(stack * s, int a){
    s->tos += 1;
    s->data[s->tos] = a;
}

int pop(stack *s){
    s->tos -= 1;
}

int top(stack *s, int *a){
    return s->data[s->tos];
}

int isEmpty(stack *s){
    if(s->tos == -1) 
        return OK;
    else 
        return ERROR;
}

int isFull(stack *s){
    if(s->tos == 999)
        return OK;
    else 
        return ERROR;
}