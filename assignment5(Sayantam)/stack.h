#ifndef STACK_H
#define STACK_H
#define SIZE 1000
#define ERROR 0
#define OK 1

typedef struct{
    int data[SIZE];
    int tos;
}stack;

void init(stack*);          // Initializes the stack
int push(stack*, int);
int pop(stack*);
int top(stack*, int*);
int isEmpty(stack*);
int isFull(stack*);
#endif