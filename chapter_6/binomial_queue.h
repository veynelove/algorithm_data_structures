#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H

#include "../types.h"

/*
1 二项队列(binomial queue)不同于我们已经看到的所有优先队列的实现之处在于，一个二项队列不是一颗堆序的树，而是堆序树的集合，称为森林(forest)。
    堆序树中的每一颗都是有约束的形式，叫做二项树(binomial tree)。
	每一个高度上至多存在一颗二项树。高度为0的二项树是一颗单节点树；高度为k的二项树Bk通过将一颗二项树Bk-1附接到另一颗二项树Bk-1的根上而构成。
2 二项树Bk由一个带有儿子B0,B1,...,Bk-1的根组成。高度为k的二项树恰好有2^k个节点，而在深度d处的节点数是二项系数{k d}。
    如果我们把堆序施加到二项树上并允许任意高度上最多有一颗二项树，那么我们能够用二项树的集合唯一地表示任意大小的优先队列。
*/

#define MaxTrees 100
#define Capacity 200

typedef struct BinNode *Position;
typedef struct Collection *BinQueue;
typedef struct BinNode *BinTree;

BinQueue Initialize(void);
BinTree CombineTrees(BinTree T1, BinTree T2); //合并同样大小的两颗二项树
BinQueue BqMerge(BinQueue H1, BinQueue H2);
float DeleteMin(BinQueue H);
int BqIsEmpty(BinQueue H);

struct BinNode
{
    float Element;
    Position LeftChild;
    Position NextSibling;
};
struct Collection {
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};

#endif
