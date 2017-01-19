//impl.h for impl.c and RadixSort.c
#ifndef IMPL_H
#define IMPL_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

#define ARRAY 1000
#define TUB 100

void CreatArray(int array[ARRAY]);
void CreatTub(List tub[TUB]);
void InsertList(int x,List L);
List CreatList(int x);
void TubSort(int array[ARRAY],List tub[TUB]);
void PrintList(List L1);
void PrintTub(List tub[TUB]);
void DeleteList(List L1);
void DeleteTub(List tub[TUB]);
void EmptyList(List L1);
void EmptyTub(List tub[TUB]);
void TubToArray(List tub[TUB],int array[ARRAY]);

#endif //impl.h
