#include "leftist_heap.h"

ElementType FindMin(PriorityQueue H)
{
    return H->Element;
}

int IsEmpty(PriorityQueue H)
{
    return H == NULL;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if(H1 == NULL)
        return H2;
    if(H2 == NULL)
        return H1;
    if(H1->Element < H2->Element)
        return Merge1(H1, H2);
    else 
        return Merge1(H2, H1);

}

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode));
    if(SingleNode == NULL)
        FatalError("Out of space.");
    else
    {
        SingleNode->Element = X;
        SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode, H);
    }
    return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;
    if(IsEmpty(H)) {
        Error("Priority queue is empty.");
        return H;
    }
    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if(H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if(H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

PriorityQueue SwapChildren(PriorityQueue H)
{
    PriorityQueue TmpQueue;
    TmpQueue = H->Left;
    H->Left = H->Right;
    H->Right = TmpQueue;
    return H;
}
