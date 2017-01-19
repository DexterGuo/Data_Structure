
#include <stdio.h>
#include "impl.h"

int main()
{
    List list=CreatList();
    List L1=CreatList();
    List L2=CreatList();
    Position p=list;
    Insert(4,list,p);
    Insert(5,list,p);
    Insert(6,list,p);
    Insert(7,list,p);
    Insert(8,list,p);
    print(list);
    printf("==================\n");

    Delete(7,list);
    print(list);
    printf("==================\n");

    p=Find(6,list);
    Insert(9,list,p);
    print(list);
    printf("==================\n");

    list=MakeEmpty(list);
    print(list);
    printf("==================\n");
    DeleteList(list);

    p=L1;
    Insert(8,L1,p);
    Insert(7,L1,p);
    Insert(6,L1,p);
    Insert(5,L1,p);
    Insert(4,L1,p);
    print(L1);
    printf("==================\n");

    List reverseL1=ReverseList(L1);
    print(reverseL1);
    printf("==================\n");

    p=L2;
    Insert(9,L2,p);
    Insert(7,L2,p);
    Insert(4,L2,p);
    print(L2);
    printf("==================\n");

    List L=CreatList();
    ListAnd(L1,L2,L);
    print(L);
    printf("==================\n");
    
    List LL=CreatList();
    ListOr(L1,L2,LL);
    print(LL);
    printf("==================\n");
    DeleteList(L);
    DeleteList(LL);
    DeleteList(L1);
    DeleteList(L2);
    DeleteList(reverseL1);
    
    return 0;
}
