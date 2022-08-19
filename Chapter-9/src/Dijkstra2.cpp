#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

typedef struct
{
    bool known = false;
    int dist = inf;
    Vertex path = 0;
}AppendexInfo;
AppendexInfo T[MAX];          //储存额外信息

typedef struct
{
    Vertex V = NotAVertex;
    int dist = inf;
}VAndDist;
VAndDist VD[MAX];

struct cmp
{
    bool operator()(VAndDist a, VAndDist b)
    {
        return a.dist > b.dist;     //升序队列，小顶堆
    }
};


void Dijkstra(Graph G);

int main(void)
{
    Graph G;
    InitializeGraph(G);

    AddVertex(G, "v1");
    AddVertex(G, "v2");
    AddVertex(G, "v3");
    AddVertex(G, "v4");
    AddVertex(G, "v5");
    AddVertex(G, "v6");
    AddVertex(G, "v7");

    AddEdge(G, 2, "v1", "v2");
    AddEdge(G, 1, "v1", "v4");
    AddEdge(G, 3, "v2", "v4");
    AddEdge(G, 10, "v2", "v5");
    AddEdge(G, 4, "v3", "v1");
    AddEdge(G, 5, "v3", "v6");
    AddEdge(G, 2, "v4", "v3");
    AddEdge(G, 2, "v4", "v5");
    AddEdge(G, 8, "v4", "v6");
    AddEdge(G, 4, "v4", "v7");
    AddEdge(G, 6, "v5", "v7");
    AddEdge(G, 1, "v7", "v6");

    T[FindVertex(G, "v1")].dist = 0;      //从第一个结点开始搜索
    Dijkstra(G);

    for (int i = 0; i < G.volume; i++)
    {
        if (G.adjacentTable[i].existFlag)
        {
            cout << G.adjacentTable[i].elem << " path: " << G.adjacentTable[T[i].path].elem << endl;
        }
    }
    return 0;
}

void Dijkstra(Graph G)
{
    Vertex V;
    EdgeNode temp;
    Vertex minVertex;
    priority_queue<VAndDist, vector<VAndDist>, cmp> q;    

    VAndDist tmp;
    for (int i = 0; i < G.volume; i++)
    {
        if (G.adjacentTable[i].existFlag && T[i].dist == 0)
        {
            tmp.dist = 0;
            tmp.V = i;
            q.push(tmp);
        }
    }

    for (;;)
    {
        minVertex = NotAVertex;
        while (!q.empty())
        {
            if (!T[q.top().V].known)
            {
                minVertex = q.top().V;
                q.pop();
                break;
            }
            else
                q.pop();
        }
        
        if (minVertex == NotAVertex)
            break;

        T[minVertex].known = true;

        temp = G.adjacentTable[minVertex].edgeList;
        while (temp != nullptr)
        {
            if (!T[temp->vertex].known)
                if (T[minVertex].dist + temp->weight < T[temp->vertex].dist)
                {
                    tmp.V = temp->vertex;
                    tmp.dist = T[minVertex].dist + temp->weight;
                    T[temp->vertex].dist = T[minVertex].dist + temp->weight;
                    q.push(tmp);
                    T[temp->vertex].path = minVertex;
                }

            temp = temp->nextPtr;
        }

    }
}