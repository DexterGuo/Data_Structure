#include "LeftistHeap.h"

LeftistHeap Initialize()
{
    LeftistHeap H;
    return H;
}

ElemType FindMin(LeftistHeap H)
{
    if(H != NULL)
	return H->Element;
}

int IsEmpty(LeftistHeap H)
{
    return H == NULL ? 1 : 0;
}

LeftistHeap Merge(LeftistHeap H1,LeftistHeap H2)
{
    if(H1 == NULL)
	return H2;
    if(H2 == NULL)
	return H1;
    if(H1->Element < H2->Element)
	return Merge1(H1,H2);
    else
	return Merge1(H2,H1);
}

LeftistHeap Merge1(LeftistHeap H1,LeftistHeap H2)
{
    if(H1->Left == NULL)
	H1->Left = H2;
    else
    {
	H1->Right = Merge(H1->Right,H2);
	if(H1->Left->Npl < H1->Right->Npl)
	    H1 = SwapChildren(H1);
    	H1->Npl = H1->Right->Npl+1;
    }
    return H1;
}

LeftistHeap SwapChildren(LeftistHeap H1)
{
    LeftistHeap P = H1->Left;
    H1->Left = H1->Right;
    H1->Right = P;
    return H1;
}

LeftistHeap Insert1(ElemType x,LeftistHeap H)
{
    LeftistHeap SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode));
    if(SingleNode != NULL)
    {
	SingleNode->Element = x;
	SingleNode->Left = SingleNode->Right = NULL;
	H = Merge(SingleNode,H);
    }
    return H;
}

LeftistHeap DeleteMin1(LeftistHeap H)
{
    LeftistHeap LeftHeap,RightHeap;
    if(IsEmpty(H) != 1)
    {
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap,RightHeap);
    }
}

LeftistHeap Delete(LeftistHeap H)
{
    LeftistHeap P=H;
    if(H->Left != NULL)
    	Delete(H->Left);
    if(H->Right != NULL)
	Delete(H->Right);
    free(P);
}

void Print(LeftistHeap H)
{
    if(H != NULL)
    {
	printf("the element is %d,%d\n",H->Element,H->Npl);
	Print(H->Left);
	Print(H->Right);
    }
}
