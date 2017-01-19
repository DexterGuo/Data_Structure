#include "sorting.h"

void swap(ElemType * a,ElemType * b)
{
    ElemType tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void InsertionSort(ElemType A[], int N)
{
    int i,j;
    ElemType tmp;
    for(i=1;i<N;i++)
    {
	for(j=i;j>0 && A[j]<A[j-1];j--)
	    swap(&A[j],&A[j-1]);
    }
}

//Median of three partitioning
ElemType Median3(ElemType A[],int Left,int Right)
{
    int Center = (Left+Right)/2;
    if(A[Left] > A[Center])
	swap(&A[Left],&A[Center]);
    if(A[Left] > A[Right])
	swap(&A[Left],&A[Right]);
    if(A[Center] > A[Right])
	swap(&A[Right],&A[Center]);
    swap(&A[Center],&A[Right-1]);
    return A[Right-1];
}

void QSort(ElemType A[],int Left,int Right)
{
    int i,j;
    ElemType Pivot;
    if(Left + Cutoff <= Right)
    {
	Pivot = Median3(A,Left,Right);
	i = Left;j=Right-1;
	while(1)
	{
	    while(A[++i]<Pivot);
	    while(j>Left && A[--j]>Pivot);
	    if(i<j)
		swap(&A[i],&A[j]);
	    else
		break;
	}
	swap(&A[i],&A[Right-1]);
	QSort(A,Left,i-1);
	QSort(A,i+1,Right);
    }
    else
	InsertionSort(A+Left,Right-Left+1);
}

void QSelect(ElemType A[],int k,int Left,int Right)
{
    int i,j;
    ElemType Pivot;
    if(Left + Cutoff <= Right)
    {
	Pivot = Median3(A,Left,Right);
	i = Left;j=Right-1;
	while(1)
	{
	    while(A[++i]<Pivot);
	    while(j>Left && A[--j]>Pivot);
	    if(i<j)
		swap(&A[i],&A[j]);
	    else
		break;
	}
	swap(&A[i],&A[Right-1]);
	if(k<=i)
	    QSelect(A,k,Left,i-1);
	else if(k>i+1)
	    QSelect(A,k-i-1,i+1,Right);
    }
    else
	InsertionSort(A+Left,Right-Left+1);
}

void QuickSort(ElemType A[],int N)
{
    QSort(A,0,N-1);
}

void ShellSort(ElemType A[], int N)
{
    int M = 3,i,j;
    ElemType tmp;
    int Increment[3] = {1,3,5};
    while(--M+1)//while(M--)
    {
	for(i=Increment[M];i<N;i++)
	{
	    tmp = A[i];
	    for(j=i;j>=Increment[M];j-=Increment[M])
	    {
		if(tmp < A[j-Increment[M]])
		    A[j] = A[j-Increment[M]];
		else
		    break;
 	    }
	    A[j] = tmp;
	}
    }
}

void PercDown(ElemType A[],int i,int N)
{
    int Child = 0;
    ElemType tmp;
    for(tmp = A[i];LeftChild(i)<N;i=Child)
    {
	Child = LeftChild(i);
	if(Child != N-1 && A[Child]<A[Child+1])
	    Child++;
	if(tmp < A[Child])
	    A[i] = A[Child];
	else 
	    break;
    }
    A[i] = tmp;
}

void HeapSort(ElemType A[],int N)
{
    int i;
    for(i=N/2;i>=0;i--)
	PercDown(A,i,N);
    for(i=N-1;i>0;i--)
    {
	swap(&A[0],&A[i]);
	PercDown(A,0,i);
    }
}

void Merge(ElemType A[],ElemType TmpArray[],int Lpos,int Rpos,int RightEnd)
{
    int i,LeftEnd,NumElements,TmpPos;
    LeftEnd = Rpos-1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;
    while(Lpos <= LeftEnd && Rpos <= RightEnd)
	if(A[Lpos] <= A[Rpos])
	    TmpArray[TmpPos++] = A[Lpos++];
	else
	    TmpArray[TmpPos++] = A[Rpos++];
    while(Lpos <= LeftEnd)
	TmpArray[TmpPos++] = A[Lpos++];
    while(Rpos <= RightEnd)
	TmpArray[TmpPos++] = A[Rpos++];
    for(i=0;i<NumElements;i++,RightEnd--)
     	A[RightEnd] = TmpArray[RightEnd];	
}

void MSort(ElemType A[],ElemType TmpArray[],int Left,int Right)
{
    int Center;
    if(Left < Right)
    {
	Center = (Left + Right)/2;
	MSort(A,TmpArray,Left,Center);
	MSort(A,TmpArray,Center+1,Right);
	Merge(A,TmpArray,Left,Center+1,Right);
    }
}

void MergeSort(ElemType A[],int N)
{
    ElemType *TmpArray = malloc(N*sizeof(ElemType));
    if(TmpArray != NULL)
    {
	MSort(A,TmpArray,0,N-1);
    }
}


void PrintArray(ElemType A[],int N)
{
    int i=0;
    printf("=================\n");
    for(i=0;i<N;i++)
    {
	printf("the %d element is %d\n",i,A[i]);
    }
}
