#include "binomial_queue.h"

BinTree CombineTrees(BinTree T1, BinTree T2)
{
    if(T1->Element > T2->Element)
        return CombineTrees(T2, T1);
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

BinQueue BqMerge(BinQueue H1, BinQueue H2)
{
    BinTree T1, T2, Carry = NULL;
    int i, j;
    if(H1->CurrentSize + H2->CurrentSize > Capacity)
        Error("Merge would exceed capacity.");
    H1->CurrentSize += H2->CurrentSize;
    for(i=0, j=1;j<=H1->CurrentSize;i++, j*=2)
    {
        T1 = H1->TheTrees[i]; T2 = H2->TheTrees[i];
        switch(!!T1 + 2*!!T2 + 4*!!Carry)
        {
            case 0:
            case 1:
                break;
            case 2:
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 4:
                H1->TheTrees[i] = Carry;
                Carry = NULL;
                break;
            case 3:
                Carry = CombineTrees(T1, T2);
                H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                break;
            case 5:
                Carry = CombineTrees(T1, Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6:
                Carry = CombineTrees(T2, Carry);
                H2->TheTrees[i] = NULL;
                break;
            case 7: 
                H1->TheTrees[i] = Carry;
                Carry = CombineTrees(T1, T2);
                H2->TheTrees[i] = NULL;
                break;
        }
    }
    return H1;
}

float DeleteMin(BinQueue H)
{
    int i, j;
    int MinTree;
    BinQueue DeletedQueue;
    Position DeletedTree, OldRoot;
    float MinItem;
    if(BqIsEmpty(H)) {
        Error("Empty binomial queue.");
        return -INFINITY;
    }
    MinItem = INFINITY;
    for(i=0; i<MaxTrees; i++) {
        if(H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
        {
            MinItem = H->TheTrees[i]->Element;
            MinTree = i;
        }
    }
    DeletedTree = H->TheTrees[MinTree];
    OldRoot = DeletedTree;
    DeletedTree = DeletedTree->LeftChild;
    free(OldRoot);
    DeletedQueue = Initialize();
    DeletedQueue->CurrentSize = (1 << MinTree) -1;
    for(j = MinTree -1; j>=0; j--) {
        DeletedQueue->TheTrees[j] = DeletedTree;
        DeletedTree = DeletedTree->NextSibling;
        DeletedQueue->TheTrees[j]->NextSibling = NULL;
    }
    H->TheTrees[MinTree] = NULL;
    H->CurrentSize -=DeletedQueue->CurrentSize + 1;
    BqMerge(H, DeletedQueue);
    return MinItem;
}

int BqIsEmpty(BinQueue H)
{
    return H->CurrentSize == 0;
}

BinQueue Initialize(void)
{
    BinQueue B = malloc(sizeof(struct Collection));
    if(B == NULL)
        FatalError("out of space.");
    BinTree bt = malloc(sizeof(struct BinNode) * MaxTrees);
    if(bt == NULL)
        FatalError("out of space.");
    B->CurrentSize = 0;
    memcpy(B->TheTrees, bt, sizeof(struct BinNode)*MaxTrees);
    return B;
}
