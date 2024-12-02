#include "search_tree.h"

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if(T==NULL)
        return NULL;
    if(X<T->Element)
        return Find(X, T->Left);
    else
    if(X>T->Element)
        return Find(X, T->Right);
    else
        return T;
}

Position FindMin(SearchTree T)
{
    if(T==NULL)
        return NULL;
    else
    if(T->Left==NULL)
        return T;
    else 
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
    if(T!=NULL)
        while(T->Right!=NULL)
            T=T->Right;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T==NULL) {
        T=malloc(sizeof(struct TreeNode));
        if(T==NULL)
            FatalError("Out of space.");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else
    if(X<T->Element)
        T->Left =Insert(X, T->Left);
    else
    if(X>T->Element)
        T->Right = Insert(X, T->Right);
    /*else X is in the tree already; we'll do nothing.*/
    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if(T==NULL)
        Error("Element not found.");
    else
    if(X<T->Element)
        T->Left = Delete(X, T->Left);
    else
    if(X>T->Element)
        T->Right=Delete(X, T->Right);
    else
    if(T->Left && T->Right) {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else {
        TmpCell = T;
        if(T->Left == NULL)
            T=T->Right;
        else if(T->Right == NULL)
            T=T->Left;
        free(TmpCell);
    }
    return T;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void PrintTree(SearchTree T)
{
    if(T != NULL) {
        PrintTree(T->Left);
        printf("%d", T->Element);
        PrintTree(T->Right);
    }
}

int Height(SearchTree T)
{
    if(T == NULL)
        return -1;
    else
        return 1 + Max(Height(T->Left), Height(T->Right));
}
