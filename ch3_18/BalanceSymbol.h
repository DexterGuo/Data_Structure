//:BalanceSymbol.h
//
#ifndef BALANCESYMBOL_H
#define BALANCESYMBOL_H

#include <string.h>
#include "Stack.h"
#define EXPRSIZE 50
#define DATANUM 50

int BalanceFunction(ElemType Pascal[DATANUM]);
int CheckLeft(ElemType x);
ElemType CheckRight(ElemType x);

#endif


