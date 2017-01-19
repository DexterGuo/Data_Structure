//impl.h
#ifndef _IMPL_H
#define _IMPL_H

#include <stdio.h>
#include <malloc.h>

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void ListAnd(List L1,List L2,List L);

void ListOr(List L1,List L2,List L);

List CreatList();

void DeleteList(List L);

List MakeEmpty(List L);

int IsEmpty(List L);

void Insert(int x,List L,Position P);

Position Find(int x,List L);

Position FindPrevious(int x,List L);

int IsLast(Position p,List L);

void Delete(int x,List L);

void print(List L);

List ReverseList(List L1);

#endif //impl.h
