#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "../types.h"

/*
1 我们把任意节点X的零路径长(Null Path Length, NPL)Npl(X)定义为从X到一个没有两个儿子的节点的最短路径的长。
	因此，具有0个或1个儿子的节点的Npl为0，而Npl(NULL)=-1.
2 注意，任意节点的零路径长比它的诸儿子节点的零路径长的最小值多1。这个结论也适用少于两个儿子的节点，因为NULL的零路径长是-1。
3 对于堆中的每一个节点X，左儿子的零路径长至少与右儿子的零路径长一样大。
4 在右路径上有r个节点的左氏树必然至少有2^r-1个节点。
5 唯一的棘手部分在于，对右路径的Insert和Merge可能会破坏左式堆性质。
*/

#define Insert(X, H) (H = Insert1((X), H))

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

// PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
PriorityQueue SwapChildren(PriorityQueue H);

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);
struct TreeNode {
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

#endif
