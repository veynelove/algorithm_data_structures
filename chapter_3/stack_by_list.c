#include "stack_by_list.h"

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S == NULL)
        printf("out of space.");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)
{

}

void MakeEmpty(Stack S)
{
    if(S == NULL) 
        printf("Must use CreateStack first.");
    else
        while(!IsEmpty(S))
            Pop(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Out of space.");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    printf("Empty stack.");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        printf("stack is empty.");
    else
    {
        PtrToNode TmpCell;
        TmpCell = S->Next;
        S->Next = TmpCell->Next;
        free(TmpCell);
    }
}
