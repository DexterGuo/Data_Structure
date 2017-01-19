#include "BinHeap.h"

int main()
{
    PriorityQueue H = Initialize(20);
    Insert(8,H);
    Insert(18,H);
    Insert(82,H);
    Insert(32,H);
    Insert(61,H);
    Insert(9,H);
    Insert(812,H);
    Insert(7,H);
    printf("==================\n");
    PrintBinHeap(H);
    printf("==================\n");
    printf("the min elem is %d\n",FindMin(H));
    printf("==================\n");
    DeleteMin(H);
    PrintBinHeap(H);
    printf("==================\n");
    Destroy(H);
    return 0;
}
