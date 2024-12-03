#include "disjoint_set.h"

void Initilialize(DisjSet S)
{
    int i;
    for(i=NumSets; i>0; i--)
        S[i] = 0;
}
//按高度求并
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    if(S[Root2] < S[Root1])
        S[Root1] = Root2;
    else
    {
        if(S[Root1] == S[Root2])
            S[Root1]--;
        S[Root2] = Root1;
    }
}
//用路径压缩进行不相交集的Find操作
SetType Dj_Find(ElementType X, DisjSet S)
{
    if(S[X] <= 0)
        return X;
    else
        //return Find(S[X], S);
        return S[X] = Dj_Find(S[X], S);
}
