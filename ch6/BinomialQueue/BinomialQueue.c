#include "BinomialQueue.h"

BinQueue CreateBinQueue()
{
    BinQueue F=malloc(sizeof(struct Collection));
    F->CurrentSize = 0;
    int i;
    for(i=0;i<MaxTrees;i++)
    	F->TheTrees[i] = NULL;
    return F;
}

BinQueue InsertBinQueue(ElemType x,BinQueue F)
{
    BinTree T = malloc(sizeof(struct BinNode));
    T->Element = x;
    T->LeftChild = T->NextSibling = NULL;
    BinQueue F2 = CreateBinQueue();
    F2->CurrentSize = 1;
    F2->TheTrees[0] = T;

    return Merge(F,F2);
}

BinQueue InsertBinQueueWithoutMerge(ElemType x,BinQueue F)
{
    BinTree T = malloc(sizeof(struct BinNode));
    T->Element = x;
    T->LeftChild = T->NextSibling = NULL;
    int i;
    for(i=0;i<MaxTrees;i++)
    {
	if(F->TheTrees[i] == NULL)
	{
	    F->CurrentSize++;
	    F->TheTrees[i] = T;
	    break;
	}
	else
	{
	    T = CombineTrees(F->TheTrees[i],T);
	    F->TheTrees[i] = NULL;
	}
    }
    return F;
}

BinTree CombineTrees(BinTree T1,BinTree T2)
{
    if(T1 == NULL)
	return T2;
    if(T2 == NULL)
	return T1;
    if(T1->Element > T2->Element)
	return CombineTrees(T2,T1);
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

BinQueue Merge(BinQueue F1,BinQueue F2)
{
    if(F1 == F2) return F1;
    BinTree T1,T2,Carry = NULL;
    int i,j;
    if(F1->CurrentSize + F2->CurrentSize > Capacity)
	printf("some wrong in function Mergr!!!\n");
    F1->CurrentSize += F2->CurrentSize;
    for(i=0,j=1;j<=F1->CurrentSize;i++,j*=2)
    {
	T1 = F1->TheTrees[i];
	T2 = F2->TheTrees[i];
	switch(!!T1 + 2 * !!T2 + 4 * !!Carry)
	{
	    case 0:
	    case 1:
		break;
	    case 2:
		F1->TheTrees[i] = T2;
		F2->TheTrees[i] = NULL;
		break;
	    case 4:
		F1->TheTrees[i] = Carry;
		Carry = NULL;
		break;
	    case 3:
		Carry = CombineTrees(T1,T2);
		F1->TheTrees[i] = NULL;
		F2->TheTrees[i] = NULL;
		break;
	    case 5:
		Carry = CombineTrees(T1,Carry);
		F1->TheTrees[i] = NULL;
		break;
	    case 6:
		Carry = CombineTrees(T2,Carry);
		F2->TheTrees[i] = NULL;
		break;
	    case 7:
		F1->TheTrees[i] = Carry;
		Carry = CombineTrees(T1,T2);
		F2->TheTrees[i] = NULL;
		break;
	    default: break;
	}
    }
    free(F2); 
    return F1;
}

int FindMin(BinQueue F)
{
    int i,j,x = 1000;//x=infinity
    for(i=0;i<MaxTrees;i++)
    {
	if(F->TheTrees[i] && F->TheTrees[i]->Element < x)
	{
	    j=i;x=F->TheTrees[i]->Element;
	}
    }
    return j;
}

ElemType DeleteMin(BinQueue F)
{
    int Pos = FindMin(F),j=1;
    ElemType Value = F->TheTrees[Pos]->Element;
    BinQueue F2 = CreateBinQueue();
    BinTree T = F->TheTrees[Pos]->LeftChild,tmp=F->TheTrees[Pos];
    free(tmp); 
    while(T != NULL)
    {
	j *= 2;
	tmp = T;
	T = T->NextSibling;
	tmp->NextSibling = NULL;
	F2->TheTrees[--Pos] = tmp;
    }
    F2->CurrentSize = j-1;
    F->TheTrees[Pos] = NULL;
    F->CurrentSize -= j;
    F = Merge(F,F2);
    return Value;
}

void PrintBinQueue(BinQueue F)
{
    int i,j;
    for(i=0,j=1;j<=F->CurrentSize;i++,j *= 2)
    	PrintBinTree(i,F->TheTrees[i]);
}

void PrintBinTree(int i,BinTree T)
{
    if(T != NULL)
    {
	printf("the %d element is: %d\n",i,T->Element);
	PrintBinTree(i,T->LeftChild);
	PrintBinTree(i,T->NextSibling);
    }
}
