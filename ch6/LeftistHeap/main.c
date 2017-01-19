#include "LeftistHeap.h"

int main()
{
    LeftistHeap H1 = NULL,H2 = NULL;
    Insert(3,H1);
    Insert(10,H1);
    Insert(8,H1);
    Insert(21,H1);
    Insert(14,H1);
    Insert(17,H1);
    Insert(23,H1);
    Insert(26,H1);
    Insert(6,H2);
    Insert(12,H2);
    Insert(7,H2);
    Insert(18,H2);
    Insert(24,H2);
    Insert(37,H2);
    Insert(18,H2);
    Insert(33,H2);
    printf("=================\n");
    Print(H1);
    printf("=================\n");
    Print(H2);
    printf("=================\n");
    LeftistHeap H = Merge(H1,H2);
    Print(H);
    printf("=================\n");
    Delete(H1);
    Delete(H2);
    Delete(H);
    return 0;
}
