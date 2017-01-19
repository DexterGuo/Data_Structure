
#include "OpenAddressHash.h"

int main()
{
    HashTable Ha;
    Ha = InitializeTable(9);
    Insert(321,Ha);
    Insert(678,Ha);
    Insert(871,Ha);
    Insert(679,Ha);
    printf("================\n");
    printf("%d NextPrime is %d \n",9,NextPrime(9));
    printf("================\n");
    Print(Ha);
    printf("================\n");
    return 0;
}
