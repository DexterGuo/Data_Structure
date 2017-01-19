//:graph.c
#include "graph.h"

Graph InitializeGraph()
{
    Graph G;
    int i;
    G = malloc(sizeof(struct GraphEntrance));
    if(G != NULL)
    {
	G->VertexNum = 0;
	for(i=0;i<VertexSize;i++)
	{
	    G->TheVertexs[i] = malloc(sizeof(struct Vertex));
	    G->TheVertexs[i]->Element = i;
	    G->TheVertexs[i]->Info = unknown;
	    G->TheVertexs[i]->Dist = Infinity;
	    G->TheVertexs[i]->Indegree = 0;
	    G->TheVertexs[i]->NextVertex = NULL;
	}
    }
    return G;
}

Graph InsertGraph(ElemType a,ElemType b,Graph G)
{
    a--;b--;
    struct Vertex * V = malloc(sizeof(struct Vertex));
    V->Element = b;
    V->Info = unknown;
    V->Dist = Infinity;
    V->NextVertex = NULL;
    struct Vertex * tmp = G->TheVertexs[a];
    
    while(tmp->NextVertex != NULL)
	tmp = tmp->NextVertex;
    tmp->NextVertex = V;
    G->VertexNum++;
    G->TheVertexs[b]->Indegree++;
    return G;
}

ElemType FindNewVertexOfIndegreeZero(Graph G)
{
    int i;
    for(i=0;i<VertexSize;i++)
    {
	if(G->TheVertexs[i]->NextVertex != NULL && G->TheVertexs[i]->Indegree == 0)
	    return G->TheVertexs[i]->Element;
    }
}

void FreeVertex(struct Vertex * V)
{
    struct Vertex * tmp ;
    while(V != NULL)
    {
	tmp = V;
	V = V->NextVertex;
    	free(tmp);
    }
}

void Topsort(Graph G)
{
    int Counter;
    ElemType V;
    struct Vertex * W;
    for(Counter=0;Counter<VertexSize;Counter++)
    {
	V = FindNewVertexOfIndegreeZero(G);
	printf("the %d element is %d\n",Counter+1,V+1);
	W = G->TheVertexs[V]->NextVertex;
	while(W != NULL)
	{
	    G->TheVertexs[W->Element]->Indegree--;
	    W = W->NextVertex;
	}
	FreeVertex(G->TheVertexs[V]->NextVertex);
	G->TheVertexs[V]->NextVertex = NULL;
	G->TheVertexs[V]->Indegree = 0;
    }
}

void TopsortWithQueue(Graph G)
{
    int Counter=0;
    ElemType V;
    struct Vertex * W;
    Queue Q =CreateQueue(); 
    V = FindNewVertexOfIndegreeZero(G);
    Q = Enqueue(V,Q);
    while(IsEmpty(Q) == 0)
    {
	V = Frontqueue(Q);
	Q = Dequeue(Q);
	printf("the %d element is %d\n",++Counter,V+1);
	W = G->TheVertexs[V]->NextVertex;
	while(W != NULL)
	{
	    if(--G->TheVertexs[W->Element]->Indegree == 0)
		Q = Enqueue(W->Element,Q);
	    W = W->NextVertex;
	}
	FreeVertex(G->TheVertexs[V]->NextVertex);
	G->TheVertexs[V]->NextVertex = NULL;
	G->TheVertexs[V]->Indegree = 0;
    }
}

void UnweightedWithQueue(ElemType x,Graph G)
{
    enum Distance CurrDist;
    int Counter = 0;
    ElemType V;
    struct Vertex * W;
    Queue Q;
    Q = CreateQueue();
    Q = Enqueue(x-1,Q);
    G->TheVertexs[x-1]->Dist = 0;
    while(IsEmpty(Q) == 0)
    {
	V = Frontqueue(Q);
	Q = Dequeue(Q);
	printf("the %d element is %d\n",++Counter,V+1);
  	G->TheVertexs[V]->Info = known;
	W = G->TheVertexs[V]->NextVertex;
	while(W != NULL)
	{
	    if(G->TheVertexs[W->Element]->Dist == Infinity)
	    {
		G->TheVertexs[W->Element]->Dist = G->TheVertexs[V]->Dist + 1;
		Q = Enqueue(W->Element,Q);
	    }
	    W = W->NextVertex;
	}
    }
}

Graph CreateGraph(Graph G)
{
    G = InitializeGraph();
    G = InsertGraph(1,2,G);
    G = InsertGraph(1,4,G);
    G = InsertGraph(1,3,G);
    G = InsertGraph(2,4,G);
    G = InsertGraph(2,5,G);
    G = InsertGraph(3,6,G);
    G = InsertGraph(4,6,G);
    G = InsertGraph(4,7,G);
    G = InsertGraph(4,3,G);
    G = InsertGraph(5,4,G);
    G = InsertGraph(5,7,G);
    G = InsertGraph(7,6,G);
    return G;
}
