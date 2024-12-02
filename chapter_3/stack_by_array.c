#include "stack_by_array.h"

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S);
Stack CreateStack(int MaxElements)
{
    Stack S;
    if(MaxElements < MinStackSize)
        Error("Stack size is too small.");
    S = malloc(sizeof(struct StackRecode));
    if(S == NULL) 
        FatalError("Out of space.");
    S->Array = malloc(sizeof(ElementType)*MaxElements);
    if(S->Array == NULL)
        FatalError("Out of Space.");
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)
{
    if(S != NULL) {
        free(S->Array);
        free(S);
    }
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        Error("Full Stack.");
    else 
        S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty stack.");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty stack.");
    else
        S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    Error("Empty stack.");
    return 0;
}
