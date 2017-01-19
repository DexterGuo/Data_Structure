//:graph.h
//function:
//	using for chapter 9 
//program:
//	guo 2017/1/13 first released
//
#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <malloc.h>
#include "Queue.h"

#define VertexSize 10
//typedef int ElemType;
typedef int Size;

enum Flag {unknown,known};
enum Distance {zero,one,two,three,four,five,six,seven,eight,nine,Infinity};
struct Vertex ;

struct GraphEntrance;
typedef struct GraphEntrance * Graph;

Graph InitializeGraph();

Graph InsertGraph(ElemType a,ElemType b,Graph G);
Graph CreateGraph(Graph G);
void Topsort(Graph G);
void TopsortWithQueue(Graph G);
void FreeVertex(struct Vertex * V);
ElemType FindNewVertexOfIndegreeZero(Graph G);
void UnweightedWithQueue(ElemType x,Graph G);

#endif //:graph.h

struct Vertex
{
    ElemType Element;
    enum Flag Info;
    enum Distance Dist;
    Size Indegree;
    struct Vertex * NextVertex;
};

struct GraphEntrance
{
    Size VertexNum;
    struct Vertex * TheVertexs[VertexSize];
};
