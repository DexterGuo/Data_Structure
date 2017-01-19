
#include <stdio.h>
#include "impl.h"

int main()
{
    int array[ARRAY],i;
    CreatArray(array);
    for(i=0;i<ARRAY;i++)
    {printf("the %d is %d\n",i,array[i]);}
    printf("=======================\n");

    List tub[TUB];
    CreatTub(tub);
    TubSort(array,tub);
    for(i=0;i<ARRAY;i++)
    {printf("the %d is %d\n",i,array[i]);}
    printf("=======================\n");
    DeleteTub(tub);
    return 0;

}
