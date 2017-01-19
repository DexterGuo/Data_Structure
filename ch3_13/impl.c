#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "impl.h"

struct Node
{
    int Element;
    struct Node * Next;
};

List CreatList(int x)
{
    List Head=malloc(sizeof(struct Node));
    if(Head == NULL) printf("Out of space!");
    Head->Element=x;
    Head->Next=NULL;
    return Head;
}

void InsertList(int x,List L)
{
    List l=L;
    Position tmp=malloc(sizeof(struct Node));
    tmp->Element=x;
    tmp->Next=NULL;
    while(l->Next != NULL)
    {
	l=l->Next;
    }
    l->Next=tmp;
}

void CreatTub(List tub[TUB])
{
    int i=0;
    for(i=0;i<TUB;i++)
    {
	tub[i]=CreatList(i);
    }
}

void CreatArray(int array[ARRAY])
{
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<ARRAY;i++)
    { 
  	array[i]=rand()%10000;
    }
}

void TubToArray(List tub[TUB],int array[ARRAY])
{
    List tmp;
    int i=0,j=0;
    for(i=0;i<TUB;i++)
    {
	tmp=tub[i]->Next;
	while(tmp != NULL)
	{
	    array[j++]=tmp->Element;
	    tmp=tmp->Next;
	}
    }
}

void EmptyList(List L)
{
    List l=L->Next;
    Position P;
    while(l != NULL)
    {
	P=l;
	l=l->Next;
	free(P);
    }
    L->Next=NULL;
}

void EmptyTub(List tub[TUB])
{
    int i=0;
    for(i=0;i<TUB;i++)
	EmptyList(tub[i]);
}

void TubSort(int array[ARRAY],List tub[TUB])
{
    int i=0,tmp;
    int a[ARRAY];
    for(i=0;i<ARRAY;i++) 
    {
	tmp=array[i]%TUB;
	InsertList(array[i],tub[tmp]);
    }
    TubToArray(tub,array);
    EmptyTub(tub);
    for(i=0;i<ARRAY;i++) 
    {
	a[i] = array[i]/TUB;
    }
    for(i=0;i<ARRAY;i++) 
    {
	tmp=a[i]%TUB;
	InsertList(array[i],tub[tmp]);
    }
    TubToArray(tub,array);
    EmptyTub(tub);
    for(i=0;i<ARRAY;i++) 
    {
	a[i] = array[i]/TUB/TUB;
    }
    for(i=0;i<ARRAY;i++) 
    {
	tmp=a[i]%TUB;
	InsertList(array[i],tub[tmp]);
    }
    TubToArray(tub,array);
    EmptyTub(tub);
}

void PrintList(List L1)
{
    List l=L1->Next;
    while(l != NULL)
    {
	printf("the element is %d\n",l->Element);
	l=l->Next;
    }
}

void PrintTub(List tub[TUB])
{
    int i=0;
    for(i=0;i<TUB;i++)
    {
	PrintList(tub[i]);
    }
}

void DeleteList(List L)
{
    Position P;
    while(L != NULL)
    {
	P=L;
	L=L->Next;
	free(P);
    }
}

void DeleteTub(List tub[TUB])
{
    int i=0;
    for(i=0;i<TUB;i++)
    {
	DeleteList(tub[i]);
    }
}

