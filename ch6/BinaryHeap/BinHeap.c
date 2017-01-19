#include "BinHeap.h"

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H = malloc(sizeof(struct HeapStruct));
    if(H != NULL)
    {
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements = malloc(sizeof(ElemType) * (MaxElements + 1));
	if(H->Elements != NULL)
	{
	    H->Elements[0] = -1;//MinData
	    return H;
	}
	else return NULL;
    }
    else return NULL;
}

void Destroy(PriorityQueue H)
{
    if(H->Elements != NULL)
	free(H->Elements);
    if(H != NULL)
	free(H);
}

void MakeEmpty(PriorityQueue H)
{
    if(H != NULL)
	H->Size = 0;
}

void Insert(ElemType x,PriorityQueue H)
{
    int i=0;
    if(H != NULL && IsFull(H) != 1)
    {
	for(i = ++H->Size;H->Elements[i/2] > x;i /= 2)
	{
	    H->Elements[i] = H->Elements[i/2];
	}
	H->Elements[i] = x;
    }
}

ElemType DeleteMin(PriorityQueue H)
{
    int i,Child=0;
    ElemType MinElement,LastElement;
    if(H != NULL && IsEmpty(H) != 1)
    {
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	for(i=1;i*2<=H->Size;i=Child)
	{
	    Child = 2*i;
	    if(Child != H->Size && H->Elements[Child+1] < H->Elements[Child])
		Child++;
	    if(LastElement > H->Elements[Child])
		H->Elements[i] = H->Elements[Child];
	    else 
		break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
    }
}

ElemType FindMin(PriorityQueue H)
{
    if(H != NULL && IsEmpty(H) != 1)
    {
	return H->Elements[1];
    }
    else return -1;
}

int IsEmpty(PriorityQueue H)
{
    if(H != NULL)
    {
	return H->Size == 0 ? 1 : 0;
    }
}

int IsFull(PriorityQueue H)
{
    if(H != NULL)
    {
	return H->Size == H->Capacity ? 1 : 0;
    }
}

void PrintBinHeap(PriorityQueue H)
{
    int i;
    for(i=1;i<=H->Size;i++)
    {
	printf("the %d element is %d\n",i,H->Elements[i]);
    }
}
