//:OpenAddressHash.h
//function:
//	realize open addressing hash, INITIALIZE and three FINDs INSERTs
//program:
//	guo 2017/1/4 first released

#ifndef OPENADDRESSHASH_H
#define OPENADDRESSHASH_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "PolynomialMult.h"

typedef unsigned int Index;
typedef Index Position;
typedef int ElemType;

struct HashTbl;
typedef struct HashTbl * HashTable;

HashTable InitializeTable(int TableSize);

Position FindWithLinearDetec(ElemType x,HashTable Ha);

Position FindWithSquareDetec(ElemType x,HashTable Ha);

Position FindWithDoubleHash(ElemType x,HashTable Ha);

//void Insert(ElemType x,HashTable Ha);

void PrintHash(HashTable Ha);

int Hash(int x,int TableSize);

int NextPrime(int a);
HashTable InsertHash(PositionL P1,PositionL P2, HashTable Ha);
HashTable PolyMultHash(List L1,List l2);

#endif //:OpenAddressHash.h

enum KindOfEntry{Legitimate, Empty, Delete};

struct HashEntry
{
    ElemType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};
