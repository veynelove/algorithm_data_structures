#ifndef AVL_TREE_H
#define AVL_TREE_H

/*
1 AVL树是带有平衡条件的二叉查找树。这个平衡条件必须要容易保持，而且必须保证树的深度是O(logN)
2 一颗AVL树是其每个节点的左子树和右子树的高度最多差1的二叉树查找树。(空树的高度定义为-1)。
*/

#include "../types.h"

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

// AvlTree MakeEmpty(AvlTree T);
// Position Find(ElementType X, AvlTree T);
// Position FindMin(AvlTree T);
// Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
// AvlTree Delete(ElementType X, AvlTree T);
// ElementType Retrieve(Position P);

static int Height(Position P);
static Position SingleRotateWithLeft(Position K2);
static Position DoubleRotateWithLeft(Position K3);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithRight(Position K3);

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

#endif
