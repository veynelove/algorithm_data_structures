#include "graph.h"

void Topsort(Graph G)
{
    Queue Q;
    int Counter = 0;
    Vertex V, W;
    Q = CreateQueue(NumVertex);
    MakeEmpty(Q);
    for each vertex V
        if(Indegree[V] == 0)
            Enqueue(V, Q);
    while(!IsEmpty(Q)) {
        V = Dequeue(Q);
        TopNum[V] = ++Counter;
        for each W adjacent to V
            if(--Indegree[W] == 0)
                Enqueue(W, Q);
    }
    if(Counter != NumVertex)
        Error("Graph has a cycle.");
    DisposeQueue(Q);
}

void Unweighted(Table T)
{
    
    Queue Q;
    Vertex V, W;
    Q = CreateQueue(NumVertex);
    MakeEmpty(Q);
    Enqueue(S, Q);
    while(!IsEmpty(Q)) {
        V = Dequeue(Q);
        T[V].Known = True;
        for each W adjacent to V
            if(T[W].Dist == Infinity) {
                T[W].Dist = T[V].Dist + 1;
                T[W].Path = V;
                Enqueue(W, Q);
            }
    }
    DisposeQueue(Q);
    
}

void InitTable(Vertex Start, Graph G, Table T)
{
    
    int i;
    ReadGraph(G, T);
    for(i=0;i<NumVertex; I++) {
        T[i].Known = False;
        T[i].Dist = Infinity;
        T[i].Path = NotAVertex;
    }
    T[Start].dist = 0;
    
}

void PrintPath(Vertex V, Table T)
{
    
    if(T[V].Path != NotAVertex) {
        PrintPath(T[V],.Path, T);
        printf(" to");
    }
    printf("%v", V);
    
}

void Dijkstra(Table T)
{
    
    Vertex V, W;
    for(;;) {
        V = smallest unknown distance vertex;
        if(V == NotAVertex)
            break;
        T[V].Known = True;
        for each W adjacent to V
        if(!T[W].Known)
            if(T[V].Dist + Cvw < T[W].Dist) {
                Decrease(T[W].Dist to T[V].Dist + Cvw);
                T[W].Path = V;
            }
    }
    
}

void WeightedNegative(Table T)
{
    
    Queue Q;
    Vertex V, W;
    Q = CreateQueue(NumVertex); MakeEmpty(Q);
    Enqueue(S, Q);
    while(!IsEmpty(Q)) {
        V = Dequeue(Q);
        for each W adjacent to V
            if(T[V].Dist + Cvw < T[W].Dist) {
                T[W].Dist = T[V].Dist + Cvw;
                T[W].Path = V;
                if(W is not already in Q)
                    Enqueue(W, Q);
            }
    }
    DisposeQueue(Q);
    
}

void Kruskal(Graph G)
{
    
    int EdgeAccepted;
    DisjSet S;
    PriorityQueue H;
    Vertex U, V;
    SetType Uset, Vset;
    Edge E;
    Initialize(S);
    ReadGraphIntoHeapArray(G, H);
    BuildHeap(H);
    EdgeAccepted = 0;
    while(EdgeAccepted < NumVertex-1) {
        E = DeleteMin(H);
        Uset = Find(U, S);
        Vset = Find(V, S);
        if(Uset != Vset) {
            EdgeAccepted++;
            SetUnion(S, USet, Vset);
        }
    }
    
}

void Dfs(Vertex V)
{
    
    Visited[V] = True;
    for each W adjacent to V
        if(!Visited[W])
            Dfs(W);
    
}

void AssignNum(Vertex V)
{
    
    Vertex V;
    Num[V] = Counter++;
    Visited[V] = True;
    for each w adjacent to V
        if(!Visited[W]) {
            Parent[W] = V;
            AssignNum(W); //分配序号
        }
    
}

void AssignLow(Vertex V)
{
    
    Vertex W;
    Low[V] = Num[V];
    for each W adjacent to V
    {
        if(Num[W] > Num[V]) {
            AssignLow(W);
            if(Low[W] >= Num[V])
                printf("%v is an articulation point\n", v);
            Low[V] = Min(Low[V], Low[W]);
        }
        else
        if(Parent(V) != W)
            Low[V] = Min(Low[V], Num[W]);
    }
    
}
//在一次深度优先搜索(忽略对根的检验)中对割点的检测(伪代码)
void FindArt(Vertex V)
{
    Vertex W;
    Visited[V] = True;
    Low[V] = Num[V] = Counter++;
    for each w adjacent to V
    {
        if(!Visited[W]) {
            Parent[W] = V;
            FindArt(W);
            if(Low[W] >= Num[V])
                printf("%v is an articulation point\n", v);
            Low[V] = Min(Low[V], Low[W]);
        }
        else
        if(Parent(V) != W)
            Low[V] = Min(Low[V], Num[W]);
    }
}
