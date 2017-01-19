#include "Queue.h"


int main()
{
    Queue Q = CreateQueue();
    printf("==================\n");
    Q = Enqueue(2,Q);PrintQueue(Q);
    printf("==================\n");
    Q = Enqueue(4,Q);PrintQueue(Q);
    printf("==================\n");
    Q = Enqueue(6,Q);PrintQueue(Q);
    printf("==================\n");
    Q = Dequeue(Q);PrintQueue(Q);
    printf("==================\n");
    Q = Enqueue(8,Q);PrintQueue(Q);
    printf("==================\n");
    return 0;
}
