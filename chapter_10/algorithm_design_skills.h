#ifndef ALGORITHM_DESIGN_SKILLS_H
#define ALGORITHM_DESIGN_SKILLS_H

#include "../types.h"

#define R_A 48271L
#define R_M 2147483647L
#define R_Q (R_M/R_A)
#define R_R (R_M%R_A)

typedef int Matrix[4][4];
typedef float TwoDimArray[4][4];
typedef long long int HugeInt;

static unsigned long Seed = 1;

//简单的O(N^3)矩阵乘法
void MatrixMultiply(Matrix A, Matrix B, Matrix C, int N);
//计算斐波那契数的低效算法
int Fib(int N);
//计算斐波那契数的线性算法
int Fibonacci(int N);
//计算C(N) = (2/N)Σ[i=0; N-1]C(i) + N的值的递归程序
double Eval(int N);
//使用一个表来计算C(N) = (2/N)Σ[i=0; N-1]C(i) + N的值
double Table_Eval(int N);
//找出矩阵乘法最优顺序的程序
void OptMatrix(const long C[], int N, TwoDimArray M, TwoDimArray LastChange);
//所有点对最短路径
void AllPairs(TwoDimArray A, TwoDimArray D, TwoDimArray Path, int N);
//工作于32位上的随机数发生器
double Random(void);
void Random_Initialize(unsigned long InitVal);
//一种概率素性测试算法
HugeInt Witness(HugeInt A, HugeInt i, HugeInt N);
//int IsPrime(HugeInt N);
#endif
