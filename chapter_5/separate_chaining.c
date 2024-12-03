#include "separate_chaining.h"
#include "hashing.h"

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;
    if(TableSize < MinTableSize) {
        Error("Table size too small.");
        return NULL;
    }
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        FatalError("out of space.");
    H->TableSize = NextPrime(TableSize);
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if(H->TheLists == NULL)
        FatalError("Out of space.");
    for(i=0;i<H->TableSize;i++) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL)
            FatalError("Out of space.");
        else 
            H->TheLists[i]->Next = NULL;
    }
    return H;
}

Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;
    L = H->TheLists[Hash3(Key, H->TableSize)];
    P = L->Next;
    while(P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}

void ScInsert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;
    Pos = Find(Key, H);
    if(Pos == NULL) {
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL) {
            Error("Out of space.");
            return;
        }
        else {
            L = H->TheLists[Hash3(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}
