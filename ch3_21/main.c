// name: main.c
// function:
// 	A example using one array to realize two stacks
// programm:
//	2016.12.27 release guodeqiang
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define ARRAYNUM 20

int array[ARRAYNUM] = {0};

typedef int* Stack;

int S1=0;
int S2=ARRAYNUM-1;

void PushStack(int x,Stack S1,Stack S2,int flag)
{
    if(flag == 1) 
    {
	array[*S1] = x;
	(*S1)++;
	if(*S1 == *S2) printf("full!!!\n");
    }
    else if(flag == 2) 
    {
	array[*S2] = x;
	(*S2)--;
	if(*S1 == *S2) printf("full!!!\n");
    }
    else
	printf("the agument is wrong in PushStack!!!\n");
}

int main()
{

    int i=0;
//test
    printf("=====================\n");
    for(i=0;i<7;i++) PushStack(3*i-1,&S1,&S2,1);
    for(i=0;i<7;i++) 
    printf("the element is: %d\n",array[i]);

    printf("=====================\n");
    for(i=0;i<ARRAYNUM;i++)
    printf("the element is: %d\n",array[i]);

    return 0;

}
