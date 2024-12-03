#include "algorithm_design_skills.h"

void MatrixMultiply(Matrix A, Matrix B, Matrix C, int N)
{
    int i, j, k;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            C[i][j] = 0.0;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            for(k=0; k<N; k++)
                C[i][j] += A[i][k] * B[k][j];
}

int Fib(int N){
    if(N <= 1)
        return 1;
    else
        return Fib(N-1) + Fib(N-2);
}

int Fibonacci(int N)
{
    int i, Last, NextToLast, Answer;
    if(N<=1)
        return 1;
    Last = NextToLast = 1;
    for(i=2; i<=N; i++) {
        Answer = Last + NextToLast;
        NextToLast = Last;
        Last = Answer;
    }
    return Answer;
}

double Eval(int N)
{
    int i;
    double Sum;
    if(N == 0)
        return 1.0;
    else 
    {
        Sum = 0.0;
        for(i=0; i<N; i++) 
            Sum += Eval(i);
        return 2.0 * Sum/N + N;
    }
}
//使用一个表来计算C(N) = (2/N)Σ[i=0; N-1]C(i) + N的值
double Table_Eval(int N)
{
    int i, j;
    double Sum, Answer;
    double *C;
    C = malloc(sizeof(double)*(N+1));
    if(C == NULL)
        FatalError("out of space.");
    C[0] = 1.0;
    for(i=1; i<=N; i++) {
        Sum = 0.0;
        for(j=0; j<i; j++)
            Sum += C[j];
        C[i] = 2.0 * Sum/i + i;
    }
    Answer = C[N];
    free(C);
    return Answer;
}

void OptMatrix(const long C[], int N, TwoDimArray M, TwoDimArray LastChange)
{
    int i, k, Left, Right;
    long ThisM;
    for(Left=1; Left<=N; Left++)
        M[Left][Left] = 0;
    for(k=1; k<N; k++)
        for(Left=1; Left<=N-k; Left++) 
        {
            Right = Left +k;
            M[Left][Right] = INFINITY;
            for(i=Left; i<Right; i++)
            {
                ThisM = M[Left][i] + M[i+1][Right] + C[Left-1]*C[i]*C[Right];
                if(ThisM < M[Left][Right]) {
                    M[Left][Right] = ThisM;
                    LastChange[Left][Right] = i;
                }
            }
        }
}

void AllPairs(TwoDimArray A, TwoDimArray D, TwoDimArray Path, int N)
{
    int i, j, k;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            D[i][j] = A[i][j];
            Path[i][j] = NotAVertex;
        }
    for(k=0; k<N; k++)
        for(i=0; i<N; i++)
            for(j=0; j<N; j++)
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    Path[i][k] = k;
                }
}

double Random(void)
{
    long TmpSeed;
    TmpSeed = R_A*(Seed%R_Q) - R_R*(Seed/R_Q);
    if(TmpSeed >= 0)
        Seed = TmpSeed;
    else
        Seed = TmpSeed + R_M;
    return (double)(Seed/R_M);
}

void Random_Initialize(unsigned long InitVal)
{
    Seed = InitVal;
}

HugeInt Witness(HugeInt A, HugeInt i, HugeInt N)
{
    HugeInt X, Y;
    if(i == 0)
        return 1;
    X = Witness(A, i/2, N);
    if(X == 0)
        return 0;
    Y = (X * X)%N;
    if(Y==1 && X!=1 && X!=N-1)
        return 0;
    if(i%2 != 0)
        Y = (A*Y)%N;
    return Y;
}

// int IsPrime(HugeInt N)
// {
//     return Witness(RandInt(2, N-2), N-1, N) == 1;
// }
