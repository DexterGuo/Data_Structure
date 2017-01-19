//:PolynomialMult.c
#include "PolynomialMult.h"


void print(List L)
{
    PositionL p=L;
    while(p->Next != NULL)
    {
	p=p->Next;
    	printf("the node element is %d,%d\n",p->Coeff,p->Power);
    }
}

int IsEmpty(List L)
{
    return (L->Next == NULL);
}
int Insert(int coeff,int power,const List L)
{
    List l=L;
    PositionL tmp=malloc(sizeof(struct Node));
    if(tmp == NULL) printf("Out of space!");
    tmp->Coeff=coeff;
    tmp->Power=power;

    while(l->Next != NULL)
    {
	if(power > l->Next->Power) 
	{    	
	     tmp->Next=l->Next;
    	     l->Next=tmp;
	     return 1;
	}
	else if(power == l->Next->Power) 
	{
	    l->Next->Coeff += coeff;
	    free(tmp);
	    return 1;
	}
	else
	     l=l->Next;
    } 
    tmp->Next=NULL;
    l->Next = tmp;
    return 1;
}

List CreatList()
{
    List Head=malloc(sizeof(struct Node));
    if(Head == NULL) printf("Out of space!");
    Head->Coeff=0;
    Head->Power=0;
    Head->Next=NULL;
    return Head;
}

List MultifyPolynomial(const List L1,const List L2)
{
    List L=CreatList();
    PositionL l1=L1->Next,l2=L2->Next;
    while(l1 != NULL)
    {
	l2=L2->Next;
	while(l2 != NULL)
	{
	    Insert(l1->Coeff*l2->Coeff,l1->Power+l2->Power,L);
	    l2=l2->Next;
	}
	l1=l1->Next;
    }
    return L;
}

void DeleteList(List L)
{   
    PositionL p=L,tmp;
    while(p != NULL)
    {
    	tmp=p;
	p=p->Next;
	free(tmp);
    }
}

void MakeEmpty(List L)
{
    PositionL p=L->Next,tmp;
    while(p != NULL)
    {
    	tmp=p;
	p=p->Next;
	free(tmp);
    }
    L->Next=NULL;
}

List CopyList(List L1)
{
    List L=CreatList();
    List l=L1->Next;
    while(l != NULL)
    {
	Insert(l->Coeff,l->Power,L);
	l=l->Next;
    }
    return L;
}

