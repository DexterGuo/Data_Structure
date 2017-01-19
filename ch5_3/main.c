
#include "OpenAddressHash.h"

int main()
{
     List L1=CreatList();
     List L2=CreatList();
     Insert(10,2,L1);
     Insert(11,6,L1);
     Insert(12,4,L1);
     Insert(13,5,L1);
     Insert(1,2,L2);
     Insert(3,3,L2);
     printf("========================\n");
     print(L1);
     printf("========================\n");
     print(L2);
     printf("========================\n");
     List LL=MultifyPolynomial(L1,L2);
     print(LL);
     printf("========================\n");
     HashTable Ha = PolyMultHash(L1,L2);
     PrintHash(Ha);
     printf("========================\n");
     DeleteList(L1);
     DeleteList(L2);
     DeleteList(LL);
     return 1;
}
