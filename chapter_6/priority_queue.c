#include "priority_queue.h"

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    if(MaxElements < MinPQSize)
        Error("Priority Queue size is too small.");
    H = malloc(sizeof(struct HeapStruct));
    if(H == NULL)
        FatalError("Out of space.");
    H->Elements = malloc((MaxElements + 1)*sizeof(ElementType));
    if(H->Elements == NULL)
        FatalError("out of space.");
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    return H;
}
//上滤
void PQInsert(ElementType X, PriorityQueue H)
{
    int i;
    if(IsFull(H)) {
        Error("Priority Queue is full.");
        return;
    }
    for(i=++H->Size;H->Elements[i/2]>X;i/=2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}
//下滤
ElementType DeleteMin(PriorityQueue H)
{
    int i,Child;
    ElementType MinElement, LastElement;
    if(IsEmpty(H)) {
        Error("Priority Queue is empty.");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    for(i=2;i*2<=H->Size;i = Child) {
        Child = i*2;
        if(Child != H->Size && H->Elements[Child+1] < H->Elements[Child])
            Child++;
        if(LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else
            break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

ElementType FindMin(PriorityQueue H)
{
    return H->Elements[1];
}

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}
