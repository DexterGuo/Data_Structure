#include "BinomialQueue.h"

int main()
{
    BinQueue F1=CreateBinQueue();
    BinQueue F2=CreateBinQueue();
    F1 = InsertBinQueue(12,F1);
    F1 = InsertBinQueueWithoutMerge(24,F1);
    F1 = InsertBinQueue(21,F1);
    F1 = InsertBinQueue(65,F1);
    F2 = InsertBinQueueWithoutMerge(14,F2);
    F2 = InsertBinQueue(16,F2);
    F2 = InsertBinQueue(26,F2);
    F2 = InsertBinQueue(18,F2);
    printf("===================\n");
    PrintBinQueue(F1);
    printf("===================\n");
    PrintBinQueue(F2);
    printf("===================\n");
    BinQueue F = Merge(F1,F2);//F2
    PrintBinQueue(F);
    printf("===================\n");
    printf("the deletemin is %d\n",DeleteMin(F));
    printf("===================\n");
    PrintBinQueue(F);
    printf("===================\n");
    return 0;
}
