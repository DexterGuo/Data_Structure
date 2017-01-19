#include "graph.h"

int main()
{
    Graph G;
    G = CreateGraph(G);
    //TopsortWithQueue(G);
    UnweightedWithQueue(1,G);
    return 0;
}
