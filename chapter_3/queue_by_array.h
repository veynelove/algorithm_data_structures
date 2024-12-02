#ifndef QUEUE_BY_ARRAY_H
#define QUEUE_BY_ARRAY_H
//队列的数组实现.插入在一端进行,而删除则在另一端进行.从后端入队,从前端出队
#include "../types.h"

#define MinQueueSize 5

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

#endif
