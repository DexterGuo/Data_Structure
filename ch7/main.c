#include "sorting.h"

int main()
{
    int N = 10;
    ElemType A[10] = {4,2,5,9,6,8,4,7,1,0};
    PrintArray(A,N); 
    //InsertionSort(A,N);
    //ShellSort(A,N);
    //HeapSort(A,N);
    //MergeSort(A,N);
    QSelect(A,2,0,N-1);
    PrintArray(A,N); 
    QuickSort(A,N);
    PrintArray(A,N); 
    printf("=================\n");
    return 0;
}
