//Stack.h
#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <malloc.h>

struct Node;
typedef struct Node * Position;
typedef Position Stack;
typedef char * ElemType;

int IsEmpty(Stack S);
void MakeEmpty(Stack S);
Stack CreatStack();
void Push(ElemType x,Stack S);
ElemType Top(Stack S);
void Pop(Stack S);
ElemType TopPop(Stack S);
void DeleteStack(Stack S);


#endif //Stack.h
