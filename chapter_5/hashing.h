#ifndef HASHING_H
#define HASHING_H

/*
6 我们寻找一个散列函数，该函数要在单元之间均匀地分配关键字
7 这就是散列的基本想法。剩下的问题则是要选择一个函数，决定当两个关键字散列到同一个值的时候(称为冲突)应该做什么以及如何确定散列表的大小。
*/
#include "../types.h"

#define MinTableSize 10
typedef unsigned int Index;

Index Hash0(const char *Key, int TableSize);
Index Hash1(const char *Key, int TableSize);
Index Hash2(const char *Key, int TableSize);
Index Hash3(int Key, int TableSize);

int isPrime(int num);
int NextPrime(int n);
#endif
