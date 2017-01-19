//:LeftistHeap.h
//function:
//	realize LeftistHeap Initialize FindMin Merge and so on
//program:
//	guo 2017/1/5 guo first released

#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
struct TreeNode;
typedef struct TreeNode * LeftistHeap;

LeftistHeap Initialize();
ElemType FindMin(LeftistHeap H);
int IsEmpty(LeftistHeap H);
LeftistHeap Merge(LeftistHeap H1,LeftistHeap H2);
LeftistHeap Merge1(LeftistHeap H1,LeftistHeap H2);
LeftistHeap SwapChildren(LeftistHeap H1);

#define Insert(x,H) (H = Insert1( (x),H) )
LeftistHeap Insert1(ElemType x,LeftistHeap );
#define DeleteMin(H) (H = DeleteMin1( H ))
LeftistHeap DeleteMin1(LeftistHeap H);

LeftistHeap Delete(LeftistHeap H);
void Print(LeftistHeap H);

#endif //:LeftistHeap.h

struct TreeNode
{
    ElemType Element;
    LeftistHeap Left;
    LeftistHeap Right;
    int Npl;
};
