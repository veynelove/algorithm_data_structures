#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "../types.h"

//二叉查找树: 对于树中的每个节点X,它的左子树中所有关键字值小于X的关键字值，而它的右子树中所有的关键字值大于X的关键字值。
//这意味着，该树所有的元素可以用某种统一的方式排序

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

void PrintTree(SearchTree T); //中序遍历
int Height(SearchTree T); //后序遍历

struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

#endif
