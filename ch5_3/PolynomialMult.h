//:PolinomialMult.h
//function:
//	create two list
//program:
//	guo 2017/1/4 edit based on ch3-7
#ifndef POLYNOMIALMULT_H
#define POLYNOMIALMULT_H

#include <stdio.h>
#include <malloc.h>

struct Node;
typedef struct Node * PositionL;
typedef PositionL List;

void print(List L);
int IsEmpty(List L);
int Insert(int coeff,int power,const List L);
List CreatList();
List MultifyPolynomial(const List L1,const List L2);
void DeleteList(List L);
void MakeEmpty(List L);
List CopyList(List L1);
#endif //:PolynomialMult.h
struct Node
{
    int Coeff;
    int Power;
    PositionL Next;
};

