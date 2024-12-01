#include "algorithm_analysis.h"

int IsEven(unsigned int N) {return N%2==0;}
//最大子序列和问题.
/*给定整数A1,A2,...,AN(可能有负数),求Ak,从k=i,到k=j的和的最大值(为方便期间,如果所有整数均为负数,则最大子序列和为0)*/
int MaxSubsequenceSum(const int A[], int N)
{
    int ThisSum, MaxSum, j;
    ThisSum = MaxSum = 0;
    for(j=0; j<N; j++) {
        ThisSum+=A[j];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum<0)
            ThisSum = 0;
    }
    return MaxSum;
}
//对分查找,O(log N)
/*给定一个整数X和整数A0,A1,...,AN-1,后者已经预先排序并在内存中,求使得Ai=X的下标i,如果X不在数据中,则返回i=-1.*/
int BinarySearch(const ElementType A[], ElementType X, int N)
{
    int Low, Mid, High;
    Low = 0; High = N-1;
    while(Low <= High) {
        Mid = (Low + High)/2;
        if(A[Mid]<X)
            Low = Mid+1;
        else
        if(A[Mid]>X)
            High = Mid-1;
        else
            return Mid;
    }
    return NotFound;
}
//欧几里得算法
//计算最大公因数的欧几里得算法.两个整数的最大公因数是同时整除二者的最大整数
unsigned int Gcd(unsigned int M, unsigned int N)
{
    unsigned int Rem;
    while(N>0) {
        Rem = M%N;
        M=N;
        N=Rem;
    }
    return M;
}
//处理一个整数的幂(它还是一个整数).
long int Pow(long int X, unsigned int N)
{
    if(N==0)
        return 1;
    if(N==1)
        return X;
    if(IsEven(N))
        return Pow(X*X, N/2);
    else
        return Pow(X*X, N/2)*X;
}
