//多项式ADT

#ifndef POLYNOMIAL_ADT_H
#define POLYNOMIAL_ADT_H

#include "../types.h"
#define MaxDegree 10000

typedef struct Node *PtrToNode;

struct Node 
{
    int Coefficient; //系数
    int Exponent; //指数
    PtrToNode Next;
};

typedef struct 
{
    int CoeffArray[MaxDegree+1];
    int HighPower; //最高次幂指数
} *Polynomial;

void ZeroPolynomial(Polynomial Poly); //多项式初始化为0
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, 
    Polynomial PolySum);   //多项式相加
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, 
    Polynomial PolyProd);  //多项式相乘

# endif
