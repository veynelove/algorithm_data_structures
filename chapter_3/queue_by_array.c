#include "queue_by_array.h"

int IsEmpty(Queue Q)
{
    return Q->Size;
}

int IsFull(Queue Q)
{
    return Q->Capacity == Q->Size;
}

Queue CreateQueue(int MaxElements)
{
    if(MaxElements<MinQueueSize)
        Error("MaxElements too small.");
    ElementType *elements = malloc(sizeof(ElementType)*MaxElements);
    if(elements == NULL)
        FatalError("Out of Space.");
    Queue Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
        FatalError("Out of Space.");
    Q->Array = elements;
    Q->Capacity = MaxElements;
    Q->Front = 0;
    Q->Rear = 0;
    Q->Size = 0;
    return Q;
}

void DisposeQueue(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty Queue.");
    else
    {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q) 
{
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q))
        Error("Full Queue.");
    else 
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    return Q->Front;
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty Queue.");
    else
    {
        Q->Front++;
        Q->Size--;
    }
}
ElementType FrontAndDequeue(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty Queue.");
    else
    {
        printf("%d", Q->Array[Q->Front++]);
        Q->Size--;
    }
}
