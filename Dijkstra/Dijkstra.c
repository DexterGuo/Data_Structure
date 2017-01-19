//:Dijkstra.c

#include "Dijkstra.h"

Table CreateTable()
{
    int i;
    Table T[NumVertex];
    for(i=0;i<NumVertex;i++)
    {
	T[i] = malloc(sizeof(struct TableEntry));
    }
    return T;
}

List ReadGraphList(int i)
{
    List L = CreateList();
    switch(i)
    {
    case 1:
	Insert(2,2,L);
	Insert(4,1,L);
	break;
    case 2:
	Insert(4,3,L);
	Insert(5,10,L);
	break;
    case 3:
	Insert(1,4,L);
	Insert(6,5,L);
	break;
    case 4:
	Insert(3,2,L);
	Insert(6,8,L);
	Insert(7,4,L);
	Insert(5,2,L);
	break;
    case 5:
	Insert(7,6,L);
	break;
    case 6:
	break;
    case 7:
	Insert(6,1,L);
	break;
    default:
	break;
    }
}

void ReadGraph(Table T)
{
    int i;
    for(i=0;i<NumVertex;i++)
    {
	T[i]->Header = ReadGraphList(i+1);
    }
}

void InitTable(Vertex Start,Table T)
{
    int i;
    ReadGraph(T);
    for(i=0;i<NumVertex;i++)
    {
	T[i]->Known = False;
	T[i]->Dist = Infinity;
	T[i]->Path = NotAVertex;
    }
    T[Start-1]->Dist = 0;
}

void PrintPath(Vertex V,Table T)
{
    if(T[V]->Path != NotAVertex)
    {
	PrintPath(T[V]->Path-1,T);
	printf(" to");
    }
    printf("%d",V+1);
}

Vertex FindSmallestUnknownDistanceVertex(Table T)
{
    Vertex V;
    DistType D;
    D = T[0]->Dist;
    V = 1;
    int i;
    for(i=1;i<NumVertex;i++)
    	if(T[i]->Known == False && T[i]->Dist < D)
	{
	    D = T[i]->Dist;
	    V = i+1;
	}
    return V;
}

void Dijkstra(Table T)
{
    Vertex V,W;
    List L;
    for(;;)
    {
	V = FindSmallestUnknownDistanceVertex(T);
	if(V == NotAVertex)
	    break;
	T[V-1]->Known = True;
	L = T[V-1]->Header;
	while(L->Next != NULL)
	    if(!T[L->Next->Element-1]->Known)
	    {
		if(T[V-1]->Dist + L->Next->Weighted < T[L->Next->Element-1]->Dist)
		{
		    T[L->Next->Element-1]->Dist = T[V-1]->Dist + L->Next->Weighted;
		    T[L->Next->Element-1]->Path = V;
		}
	        L = L->Next;
	    }
    }
}
