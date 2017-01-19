//:OpenAddressHash.c
//
#include "OpenAddressHash.h"

HashTable InitializeTable(int TableSize)
{
    HashTable Ha = NULL;
    int i=0;
    Ha = malloc(sizeof(struct HashTbl));
    if(Ha != NULL)
    {
	Ha->TableSize = NextPrime( TableSize );
	Ha->TheCells = malloc(sizeof(Cell) * Ha->TableSize);
	if(Ha->TheCells != NULL)
	    for(i=0;i<Ha->TableSize;i++)
		Ha->TheCells[i].Info = Empty;
	else printf("wrong in function InitializeTable()\n");
    }
    else printf("wrong in function InitializeTable()\n");
    return Ha;
}

Position FindWithLinearDetec(ElemType x,HashTable Ha)
{
    Position CurrentPos;
    //int CollisionNum;
    //CollisionNum = 0;
    CurrentPos = Hash(x,Ha->TableSize);
    while(Ha->TheCells[CurrentPos].Info != Empty && Ha->TheCells[CurrentPos].Element != x)
    {
	++CurrentPos;
	if(CurrentPos >= Ha->TableSize)
	    CurrentPos -= Ha->TableSize;
    }
    return CurrentPos;
}

Position FindWithSquareDetec(ElemType x,HashTable Ha)
{
    Position CurrentPos;
    int CollisionNum;
    CollisionNum = 0;
    CurrentPos = Hash(x,Ha->TableSize);
    while(Ha->TheCells[CurrentPos].Info != Empty && Ha->TheCells[CurrentPos].Element != x)
    {
	CurrentPos +=2 * ++CollisionNum -1;
	if(CurrentPos >= Ha->TableSize)
	    CurrentPos -= Ha->TableSize;
    }
    return CurrentPos;
}

Position FindWithDoubleHash(ElemType x,HashTable Ha)
{
    int HashVal = 7;
    Position CurrentPos;
    CurrentPos = Hash(x,Ha->TableSize);
    HashVal -= Ha->TheCells[CurrentPos].Element%HashVal;
    while(Ha->TheCells[CurrentPos].Info != Empty && Ha->TheCells[CurrentPos].Element != x)
    {
	CurrentPos += HashVal;
	if(CurrentPos >= Ha->TableSize)
	    CurrentPos -= Ha->TableSize;
    }
    return CurrentPos;
}
/*
void Insert(ElemType x,HashTable Ha)
{
    Position Pos;
    //Pos = FindWithLinearDetec(x,Ha);
    //Pos = FindWithSquareDetec(x,Ha);
    Pos = FindWithDoubleHash(x,Ha);
    if(Ha->TheCells[Pos].Info != Legitimate)
    {
	Ha->TheCells[Pos].Info = Legitimate;
	Ha->TheCells[Pos].Element = x;
    }
}
*/
int Hash(int x,int TableSize)
{
    return x%TableSize;
}

void PrintHash(HashTable Ha)
{
    int i=0;
    for(i=Ha->TableSize-1;i>=0;i--)
    {
	if(Ha->TheCells[i].Info == Legitimate)
	    printf("the element is %d,%d\n",Ha->TheCells[i].Element,i);
    }
}

int NextPrime(int a)
{
    int i,k,m=a-1;
    while(1)
    {
	m++;
    	k = sqrt(m);
	for(i=2;i<=k;i++)
	    if(m%i == 0) break;
	if(i>k) return m;
    }
}

HashTable PolyMultHash(List L1,List L2)
{
    HashTable Ha = InitializeTable(9);
    PositionL P2 = L2->Next;
    while(P2 != NULL)
    {
    	PositionL P1 = L1->Next;
	while(P1 != NULL)
	{
	    Ha = InsertHash(P1,P2,Ha);
	    P1 = P1->Next;
	}
	P2 = P2->Next;
    }
    return Ha;
}

HashTable InsertHash(PositionL P1,PositionL P2, HashTable Ha)
{
    Position Pos;
    int Power = P1->Power + P2->Power;
    int Coeff = P1->Coeff * P2->Coeff;
    Pos = Power;//FindWithDoubleHash(Power,Ha);
    if(Ha->TheCells[Pos].Info != Legitimate)
    {
	Ha->TheCells[Pos].Info = Legitimate;
	Ha->TheCells[Pos].Element = Coeff;
    }
    else
    //if(Ha->TheCells[Pos].Info == Legitimate)
    {
	Ha->TheCells[Pos].Info = Legitimate;
	Ha->TheCells[Pos].Element += Coeff;
    }
    return Ha;
}
