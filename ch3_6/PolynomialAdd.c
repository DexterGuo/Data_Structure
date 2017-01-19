#include <stdio.h>
#include <malloc.h>


typedef struct Node * Position;
typedef Position List;

struct Node
{
    int Coeff;
    int Power;
    Position Next;
};

void print(List L)
{
    Position p=L;
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
    Position tmp=malloc(sizeof(struct Node));
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

List AddPolynomial(const List L1, const List L2)
{
    List L=CreatList();
    Position l1=L1->Next,l2=L2->Next;
    while(l1 != NULL && l2 != NULL)
    {
	if(l1->Power > l2->Power)
	{
	    Insert(l1->Coeff,l1->Power,L);
	    l1=l1->Next;
	}
	else if(l1->Power < l2->Power)
	{
	    Insert(l2->Coeff,l2->Power,L);
	    l2=l2->Next;
	}
	else
	{
	    Insert(l1->Coeff+l2->Coeff,l1->Power,L);
	    l1=l1->Next;
	    l2=l2->Next;
	}
    }
    if(l1 != NULL)
    {
	    Insert(l1->Coeff,l1->Power,L);
	    l1=l1->Next;
    }
    else if (l2 != NULL)
    {
	    Insert(l2->Coeff,l2->Power,L);
	    l2=l2->Next;
    }
    return L;
}

List MultifyPolynomial(const List L1,const List L2)
{
    List L=CreatList();
    Position l1=L1->Next,l2=L2->Next;
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
    Position p=L,tmp;
    while(p != NULL)
    {
    	tmp=p;
	p=p->Next;
	free(tmp);
    }
}

void MakeEmpty(List L)
{
    Position p=L->Next,tmp;
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

int MultifyPoly(List L1,List L2,List L)
{
    Position l1=L1->Next,l2=L2->Next;
    if(l1 == NULL) {DeleteList(L);L=CopyList(L2);return 0;}
    if(l2 == NULL) {DeleteList(L);L=CopyList(L1);return 0;}
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
    return 1;
}

List ExponentPolynomial(const List L1,int x)
{
    List L=CreatList();
    List Ltmp=CreatList();
    List tmp=CopyList(L1);
    List l=CreatList();
    while(x>0) 
    { 
	DeleteList(l);
	l=CopyList(tmp);
	if(x%2 == 1) 
	{
	    DeleteList(Ltmp);
	    Ltmp=CopyList(L);
	    MakeEmpty(L);
	    MultifyPoly(Ltmp,l,L);
	}
	MakeEmpty(tmp);
	MultifyPoly(l,l,tmp);
	x /= 2;
    }
    DeleteList(tmp);
    return L;
}

int main()
{
     List L1=CreatList();
     List L2=CreatList();
     Insert(10,2,L1);
     Insert(11,6,L1);
     Insert(12,4,L1);
     Insert(13,5,L1);
     Insert(1,2,L2);
     Insert(3,3,L2);
     print(L2);
     printf("========================\n");
//     List L=AddPolynomial(L1,L2);
//     print(L);
//     printf("========================\n");
//     List LL=MultifyPolynomial(L1,L2);
//     print(LL);
//     printf("========================\n");
     List LLL=ExponentPolynomial(L2,4);
     print(LLL);
     printf("========================\n");
     DeleteList(L1);
     DeleteList(L2);
//     DeleteList(L);
//     DeleteList(LL);
     DeleteList(LLL);
     return 1;
}

