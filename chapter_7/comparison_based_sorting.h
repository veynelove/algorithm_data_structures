#ifndef COMPARISON_BASED_SORTING_H
#define COMPARISON_BASED_SORTING_H

#include "../types.h"

#define Swap(a, b) ({ \
    int tmp = *a;\
    *a = *b;\
    *b = tmp;\
})

#define Cutoff 10

/*
1 插入排序由N-1趟排序组成。对于P=1趟到P=N-1趟，插入排序保证从位置0到位置P上的元素为已排序状态。插入排序利用了这样的事实：位置0到位置P-1上的元素是已派过序的。
2 将位置P上的元素存于Tmp中，而(在位置P之前)所有更大的元素都向右移动一个位置。然后将Tmp置于正确的位置上。这种方法与实现二叉堆时所用到的技巧相同。
3 由于嵌套循环每趟花费N次迭代，因此插入排序为O(N^2)，而且这个界是精确的，因为以反序输入可以达到该界。
    另一方面，如果输入数据已预先排序，那么运行时间为O(N),因为内层for循环的检测总是立即判定不成立而终止。
*/
void InsertionSort(ElementType A[], int N);

/*
1 它通过比较相距一定间隔的元素来工作，各趟比较所用的距离随着算法的进行而减小，直到只比较相邻元素的最后一趟排序为止。由于这个原因，希尔排序有时也叫做缩小增量排序。
2 希尔排序使用一个序列h1,h2,...,ht,叫做增量序列。只要h1=1,任何增量序列都是可行的，不过，有些增量序列比另外一些增量序列更好(后面我们将讨论这个问题)。
在使用增量hk的一趟排序之后，对于每一个i，我们有A[i]<=A[i+hk](这里它是有意义的),所有相隔hk的元素都被排序。此时称文件是hk-排序的。
3 希尔排序的一个重要性质(我们只叙述不证明)是一个hk-排序的文件(此后将是hk-1排序的)保持它的hk-排序性。
4 hk-排序的一般做法是，对于hk,hk+1,...,N-1中的每一个位置i,把其上的元素放到i,i-hk,i-2hk...中间的正确位置上。
一趟hk-排序的作用就是对hk个独立的子数组执行一次插入排序。
5 增量排序的一种流行(但是不好)的选择是使用Shell建议的序列：ht=[N/2]和hk=[hk+1/2]。
6 即使是一个小的改变都可能剧烈地影响算法的性能
*/
void Shellsort(ElementType A[], int N);

/*
1 优先队列可以用于花费O(NlogN)时间的排序。基于该想法的算法叫做堆排序，它给出我们至今所见到的最佳的大O运行时间。然而，在实践中它却慢于使用Sedgewick增量序列的希尔排序。
2 该算法的主要问题在于它使用了一个附加的数组。因此，存储需求增加一倍。避免使用第二个数组的聪明做法是利用这样的事实：
在每次DeleteMin之后，堆缩小了1。因此，位于堆中最后的单元可以用来存放刚刚删去的元素。
3 使用这种策略，在最后一次DeleteMin后，该数组将以递减的顺序包含这些元素。
4 照通常的习惯，每一件事都是在数组中完成的。第一步以线性时间建立一个堆。然后通过将堆中的最后元素与第一个元素交换，缩减堆的大小并进行下滤，来执行N-1次DeleteMax操作。
    当算法终止时，数组则以所排的顺序包含这些元素。
*/
#define LeftChild(i) (2 * (i) + 1)

void PercDown(ElementType A[], int i, int N);
void Heapsort(ElementType A[], int N);

/*
1 归并排序以O(NlogN)最坏情形运行时间运行，而所使用的比较次数几乎是最优的。它是递归算法一个很好的实例。
2 这个算法中基本的操作是合并两个已排序的表。因为这两个表是已排序的，所以若将输出放到第三个表中，则该算法可以通过对输入数据一趟排序来完成。
基本的合并算法是取两个输入数组A和B，一个输出数组C，以及三个计数器Aptr,Bptr,Cptr,它们初始置于对应数组的开始端。
A[Aptr]和B[Bptr]中的较小者被拷贝到C中的下一个位置，相关的计数器向前推进一步。当两个输入表有一个用完的时候，则将另一个表中的剩余部分拷贝到C中。
*/
void Msort(ElementType A[], ElementType TmpArray[], int Left, int Right);
void Mergesort(ElementType A[], int N);
void m_Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd);

/*
1 像归并排序一样，快速排序也是一种分治的递归算法。将数组S排序的基本算法由下列简单的四步组成：
> 如果S中元素的个数为0或1，则返回。
> 取S中任意元素v,称之为枢纽元(pivot)。
> 将S-{v}(S中其余元素)分成两个不相交的集合: S1={x∈S-{v} | x<=v}和S2={x∈S-{v} | x>=v}。
> 返回{quicksort(S1)后，继而v,继而quicksort(S2)}。
2 由于对那些等于枢纽元的元素的处理，第3步分割的描述不是唯一的，因此这就成了一个设计上的决策。
    直观地看，我们希望把等于枢纽元的大约一半的关键字分到S1中，而另一半分到S2中，很像我们希望二叉查找树保持平衡一样。
3 快速排序更快的原因在于，第3步的分割实际上是在适当的位置进行并且非常高效，它的高效太大弥补了大小不等的递归调用的缺憾。
4 实现第2步和第3步有许多方法，这里介绍的方法是大量分析和经验研究的结果，它代表实现快速排序的非常有效的方法，哪怕是对该方法最微小的偏差都可能引起意想不到的不良结果。
*/
void Quicksort(ElementType A[], int N);
ElementType Median3(ElementType A[], int Left, int Right);
void Qsort(ElementType A[], int Left, int Right);

void QSelect(ElementType A[], int k, int Left, int Right);
#endif
