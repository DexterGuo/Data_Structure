//:PostFixSymbol.c
//
#include "PostFixSymbol.h"



void SeparateSymbol(ElemType S)
{
    //ElemType = char *
    ElemType Data[DATANUM];
    char * delim=",";
    ElemType p=NULL;
    int i=0;
    p=strtok(S,delim);
    while(p=strtok(NULL,delim))
    {
	i++;
	Data[i]=p;
	printf("the %d element is %s\n",i,Data[i]);
    }
    Data[++i]=";";
}
