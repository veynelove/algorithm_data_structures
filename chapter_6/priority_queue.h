#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../types.h"

/*
1 优先队列是允许至少下列两种操作的数据结构：Insert,它的工作是显而易见的；以及DeleteMin,它的工作是找出，返回和删除优先队列中最小的元素。
Insert操作等价于Enqueue(入队)，而DeleteMin则是队列中Dequeue(出列)在优先队列中的等价操作。
2 有几种明显的方法实现优先队列。我们可以使用一个简单链表在表头以O(1)执行插入操作，并遍历该链表以删除最小元，这又需要O(N)时间。
3 还有一种实现优先队列的方法是使用二叉查找树，它对这两种操作的平均运行时间都是O(logN)
4 我们将要使用的这种工具叫做二叉堆(binary heap)，常用其实现优先队列，当不加修饰地使用堆(heap)这个词时一般都是指该数据结构的实现。
同二叉查找树一样，堆也有两个性质，即结构性和堆序性。正如AVL树一样，对堆的一次操作可能破坏这两个性质中的一个，因此，堆的操作必须要到堆的所有性质都被满足时才能终止。
5 堆是一颗被完全填满的二叉树，有可能的例外是在底层，底层上的元素从左到右填入。这样的树称为完全二叉树。
6 因为完全二叉树很有规律，所以它可以用一个数组表示而不需要指针。
	对于数组中的任意位置i上的元素，其左儿子在位置2i上，右儿子在左儿子后的单元(2i+1)中，它的父亲则在位置[i/2]上。这种实现方法的唯一问题在于，最大的堆大小需要事先估计。
	因此，一个堆数据结构将由一个数组（不管关键字是什么类型），一个代表最大值的整数以及当前的堆大小组成。
*/

#define MinPQSize 10
#define MinData 0

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
// void Destroy(PriorityQueue H);
// void MakeEmpty(PriorityQueue H);
void PQInsert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

struct HeapStruct {
    int Capacity;
    int Size;
    ElementType *Elements;
};

#endif
