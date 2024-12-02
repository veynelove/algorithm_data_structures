#ifndef STACK_BY_ARRAY_H
#define STACK_BY_ARRAY_H
//栈的数组实现
#include "../types.h"

#define EmptyTOS -1;
#define MinStackSize 5

struct StackRecode;
typedef struct StackRecode *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

struct StackRecode {
    int Capacity;   //数组长度
    int TopOfStack;
    ElementType *Array;
};
#endif
