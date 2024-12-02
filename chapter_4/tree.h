#ifndef TREE_H
#define TREE_H

#include "../types.h"

//树的第一儿子/下一兄弟表示法
typedef struct TreeNode *PtrToNode;

struct TreeNode {
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibing;
};

//二叉树节点声明
typedef struct BinaryTreeNode *PtrToBinaryNode;
typedef PtrToBinaryNode Tree;

struct BinaryTreeNode {
    ElementType Element;
    Tree Left;
    Tree Right;
};
#endif
