#ifndef STACK_BY_LIST_H
#define STACK_BY_LIST_H
//栈ADT链表实现
#include "../types.h"

struct Node;
typedef struct Node *PtrToNode;
typedef struct Node *Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

struct Node
{
    ElementType Element;
    PtrToNode Next;
};
#endif
