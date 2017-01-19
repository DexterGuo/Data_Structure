//:the program is a Josephus problem 
//
#include <stdio.h>
#include <malloc.h>

typedef struct Node * Position;
typedef Position List;

struct Node
{
    int number;
    struct Node * Next;
};

List CreatList(int N)
{
    int i=0;
    List L=malloc(sizeof(struct Node));
    L->number=1;
    L->Next=L;
    Position P=L;
    Position tmp;
    for(i=1;i<N;i++)
    {
    	tmp=malloc(sizeof(struct Node));
    	tmp->number=i+1;
    	tmp->Next=L;
	P->Next=tmp;
	P=P->Next;
    }
    return L;
}

void print(List L)
{
    printf("the element is %d\n",L->number);
    Position P=L->Next;
    while(P != L)
    {
	printf("the element is %d\n",P->number);
	P=P->Next;
    }
}

List DeletePosition(List L,int N,int M)
{
    List l=L;
    int m=0;
    while(m++ != M-1)
    {
	l=l->Next;
    }
    L=l->Next;
    l->Next=L->Next;
    free(L);
    return l->Next;
}

int Josephus(int N,int M)
{
    List L=CreatList(N);
    print(L);
    printf("=====================\n");
    int m=M,n=N;
    while(n != 1)
    {
   	m = (m%n == 0 ? n : m%n);
    	L=DeletePosition(L,n,m); 
	n--;
    	print(L);
    	printf("=====================\n");
    }
    int r=L->number;
    free(L);
    return r;
}

int main()
{
    int r=Josephus(5,2);
    printf("the last number is %d\n",r);
    return 0;
}

