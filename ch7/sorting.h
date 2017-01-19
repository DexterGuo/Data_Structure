//:sorting.h
//function:
//	realize popolar sorting algorithm, main including:
//		insertion sort;
//program:
//	guo 2017/1/10 first released
//
#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <malloc.h>
#define LeftChild(i) (2*(i)+1)
#define Cutoff (3)
typedef int ElemType;

void swap(ElemType * a,ElemType * b);

void MergeSort(ElemType A[],int N);
void MSort(ElemType A[],ElemType TmpArray[],int Left,int Right);
void Merge(ElemType A[],ElemType TmpArray[],int Lpos,int Rpos,int RightEnd);

void QuickSort(ElemType A[],int N);
void QSort(ElemType A[],int Left,int Right);
void QSelect(ElemType A[],int k,int Left,int Right);
ElemType Median3(ElemType A[],int Left,int Right);

void PercDown(ElemType A[],int i,int N);
void HeapSort(ElemType A[],int N);

void ShellSort(ElemType A[], int N);

void InsertionSort(ElemType A[], int N);

void PrintArray(ElemType A[],int N);


#endif //:sorting.h
