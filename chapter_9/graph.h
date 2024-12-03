#ifndef GRAPH_H
#define GRAPH_H

#include "../types.h"

struct Graph;
//简单的拓扑排序伪代码
void Topsort(Graph G);
//无权最短路径的伪代码
void Unweighted(Table T);

//Dijkstra算法声明
typedef int Vertex;
struct TableEntry {
    List Header;
    int Known;
    DistType Dist;
    Vertex Path;
};
typedef struct TableEntry Table[NumVertex];

void InitTable(Vertex Start, Graph G, Table T);
void PrintPath(Vertex V, Table T);
//Dijkstra算法的伪代码
void Dijkstra(Table T);
//具有负边值的赋权最短路径算法的伪代码
void WeightedNegative(Table T);
//Kruskal算法的伪代码
void Kruskal(Graph G);
//深度优先搜索模板
void Dfs(Vertex V);
//对顶点的Num赋值(伪代码)
void AssignNum(Vertex V);
//计算Low并检验是否割点的伪代码(忽略对根的检验)
void AssignLow(Vertex V);
//在一次深度优先搜索(忽略对根的检验)中对割点的检测(伪代码)
void FindArt(Vertex V);
#endif
