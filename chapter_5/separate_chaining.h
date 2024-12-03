#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include "../types.h"

/*
1 解决冲突的第一种方法通常叫做分离链接法，其做法是将散列到同一个值的所有元素保留在一个表中。
*/
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef Position List;
typedef struct HashTbl *HashTable;

#define MinTableSize 10

HashTable InitializeTable(int TableSize);
//void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void ScInsert(ElementType Key, HashTable H);

//ElementType Retrieve(Position P);

struct ListNode {
    ElementType Element;
    Position Next;
};
struct HashTbl {
    int TableSize;
    List *TheLists;
};
#endif
