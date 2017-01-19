//:BalanceSymbol.c
#include "BalanceSymbol.h"

int CheckLeft(ElemType x)
{
	if(!strcmp(x,"begin")) return 1;
	if(!strcmp(x,"{")) return 1;
	if(!strcmp(x,"(")) return 1;
	if(!strcmp(x,"[")) return 1;
	return 0;
}

ElemType CheckRight(ElemType x)
{
	if(!strcmp(x,"end")) return "begin";
	if(!strcmp(x,"}")) return "{";
	if(!strcmp(x,")")) return "(";
	if(!strcmp(x,"]")) return "[";
	return "";
}

int BalanceFunction(ElemType Pascal[DATANUM])
{
    Stack S=CreatStack();
    int i=0;
    ElemType left;
    for(i=0;strcmp(Pascal[i] ,";")!=0;i++)
    {
	if(CheckLeft(Pascal[i]))
	    Push(Pascal[i],S);
	else
	{
	    left=TopPop(S);
	    if(strcmp(left,CheckRight(Pascal[i]))!=0)
		{DeleteStack(S);return 0;}
	}
    }
    DeleteStack(S);
    return 1;
}
