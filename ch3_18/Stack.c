
#include "Stack.h"

struct Node
{
    ElemType Element;
    struct Node * Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void MakeEmpty(Stack S)
{
    if(S==NULL) printf("Must use CreatStack() first!");
    else
	while(!IsEmpty(S))
	    Pop(S);
}

Stack CreatStack()
{
    Stack S;
    S=malloc(sizeof(struct Node));
    if(S==NULL) printf("Out of space!");
    S->Element="";
    S->Next=NULL;
    MakeEmpty(S);
    return S;
}

void DeleteStack(Stack S)
{
    Position P=S;
    while(S!=NULL)
    {
	S=S->Next;
	free(P);
	P=S;
    }
}

void Push(ElemType x,Stack S)
{
    Position tmp=malloc(sizeof(struct Node));
    if(tmp==NULL) printf("Out of space!");
    else
    {
	tmp->Element=x;
	tmp->Next=S->Next;
	S->Next=tmp;
    }
}

ElemType Top(Stack S)
{
    if(!IsEmpty(S))
	return S->Next->Element;
    else
	printf("Empty stack!");
    return "";
}

void Pop(Stack S)
{
    Position first;
    if(IsEmpty(S))
	printf("Empty stack!");
    else
    {
	first=S->Next;
   	S->Next=first->Next;
	free(first);
    }
}

ElemType TopPop(Stack S)
{
    ElemType P=Top(S);
    Pop(S);
    return P;
}

