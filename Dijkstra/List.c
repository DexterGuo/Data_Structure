//impl.c
#include "List.h"
//#include <stdio.h>
//#include <malloc.h>

//typedef struct Node *PtrToNode;
//typedef PtrToNode List;
//typedef PtrToNode Position;


List CreatList()
{
    List Head=malloc(sizeof(struct Node));
    if(Head == NULL) printf("Out of space!");
    Head->Element=0;
    Head->Weighted=0;
    Head->Next=NULL;
    return Head;
}

void DeleteList(List L)
{   
    Position p=L,tmp;
    while(p != NULL)
    {
    	tmp=p;
	p=p->Next;
	free(tmp);
    }
}

List MakeEmpty(List L)
{   
    Position p=L->Next,tmp;
    //L->Next=NULL;
    while(p != NULL)
    {
    	p->Element=0;
	p=p->Next;
    }
    return L;
}

int IsEmpty(List L)
{
    return (L->Next == NULL);
}

void Insert(int x,int w,List L)
{
    Position tmp=malloc(sizeof(struct Node));
    if(tmp == NULL) printf("Out of space!");
    tmp->Element=x;
    tmp->Next=L->Next;
    L->Next=tmp;
}

Position Find(int x,List L)
{
    Position p=L->Next;
    while(p != NULL)
    {
	if(p->Element == x)return p;
	p=p->Next;
    }
    return p;
}

Position FindPrevious(int x,List L)
{
    Position p=L;
    while(p->Next !=NULL)
    {
	if(p->Next->Element == x)return p;
	p=p->Next;
    }
    return p;
}

int IsLast(Position p,List L)
{
    return p->Next==NULL;
}

void Delete(int x,List L)
{
    Position p,tmp;
    p=FindPrevious(x,L);
    if(!IsLast(p,L))
    {
	tmp=p->Next;
	p->Next=tmp->Next;
	free(tmp);
    }
}

void print(List L)
{
    Position p=L;
    while(p->Next != NULL)
    {
	p=p->Next;
    	printf("the node element is %d\n",p->Element);
    }

}
/*
void ListAnd(List L1,List L2,List L)
{
    Position l1=L1->Next,l2=L2->Next,l=L;
    while(l1 != NULL && l2 != NULL)
    {
	if(l1->Element < l2->Element)
	{
	    l1=l1->Next;
	}
	else if(l1->Element > l2->Element)
	{
	    l2=l2->Next;
	}
	else
	{
	    Insert(l1->Element,L,l);
	    l=l->Next;
	    l1=l1->Next;
	    l2=l2->Next;
	}
    }
}

void ListOr(List L1,List L2,List L)
{
    Position l1=L1->Next,l2=L2->Next,l=L;
    while(l1 != NULL && l2 != NULL)
    {
	if(l1->Element < l2->Element)
	{
	    Insert(l1->Element,L,l);
	    l=l->Next;
	    l1=l1->Next;
	}
	else if(l1->Element > l2->Element)
	{
	    Insert(l2->Element,L,l);
	    l=l->Next;
	    l2=l2->Next;
	}
	else
	{
	    Insert(l1->Element,L,l);
	    l=l->Next;
	    l1=l1->Next;
	    l2=l2->Next;
	}
    }
    while(l1 != NULL)
    {
	    Insert(l1->Element,L,l);
	    l=l->Next;
	    l1=l1->Next;
    }
    while(l2 != NULL)
    {
	    Insert(l2->Element,L,l);
	    l=l->Next;
	    l2=l2->Next;
    }
}

List ReverseList(List L1)
{
    List L=CreatList();
    List l1=L1->Next;
    Position l=L; 
    while(l1 != NULL)
    {
	Insert(l1->Element,L,l);
	l1=l1->Next;
    }
    return L;
}
*/
