#include "list.h"
#include <stdlib.h>

List MakeEmpty(List L)
{
    if(IsEmpty(L))
        return NULL;
    Position P, NextCell;
    P = L;
    while(P != NULL) {
        NextCell = P->Next;
        free(P);
        P = NextCell;
    }
    return NULL;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;
    while(P!=NULL && P->Element != X)
        P=P->Next;
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if(!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("out of space!");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}
void DeleteList(List L)
{
    Position P, Tmp;
    P = L->Next;
    while(P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    if(L == NULL)
        return NULL;
    return L->Next;
}

Position Advance(Position P)
{
    return P;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void PrintList(List L)
{
    top:
        if(L!= NULL) {
            printf("%d", L->Element);
            L = L->Next;
            goto top;
        }
}
