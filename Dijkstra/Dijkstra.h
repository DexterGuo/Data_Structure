//:Dijkstra.h
//function:
//	realize Dijkstra algorithm
//program:
//	guo 2017/1/15 first released
//
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <malloc.h>
#include "List.h"

typedef int Vertex;
typedef int DistType;

#define NumVertex 20
#define NotAVertex (-1)
#define True 1
#define False 0
#define Infinity 999

struct TableEntry;

typedef struct TableEntry * Table;

Table CreateTable();

List ReadGraphList(int i);

void ReadGraph(Table T);

void InitTable(Vertex Start, Table T);

void PrintPath(Vertex V, Table T);

Vertex FindSmallestUnknownDistanceVertex(Table T);

void Dijkstra(Table T);

#endif //Dijkstra.h

struct TableEntry
{
    List Header;
    int Known;
    DistType Dist;
    Vertex Path;
};
