#ifndef OPEN_ADDRESSING_HASHING_H
#define OPEN_ADDRESSING_HASHING_H

/*
分离链接散列算法的缺点是需要指针，由于给新单元分配地址需要时间，因此这就导致算法的速度多少有些减慢，同时算法实际上还要求实现另一种数据结构。
2 开放定址散列法是另外一种用链表解决冲突的方法。在开放定址散列算法系统中，如果有冲突发生，那么就要尝试选择另外的单元，直到找出空的单元为止。
更一般的，单元h0(X),h1(X),h2(X),...,相继试选，其中hi(X)=(Hash(X)+F(i))mod TableSize,且F(0)=0。函数F是冲突解决方法。
因为所有的数据都要置入表内，所以开放定址散列法所需要的表要比分离链接散列用的表大。一般说来，对开放定址散列算法来说，装填因子应该低于λ=0.5
*/
#include "../types.h"

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
// void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void OdInsert(ElementType Key, HashTable H);
// ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H); //再散列

enum KindOfEntry {
    Legitimate, //正当的,合理合法的
    Empty,
    Deleted
};
struct HashEntry {
    ElementType Element;
    enum KindOfEntry Info;
};
typedef struct HashEntry Cell;
struct HashTbl {
    int TableSize;
    Cell *TheCells;
};

#endif
