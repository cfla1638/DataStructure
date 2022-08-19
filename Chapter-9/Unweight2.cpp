//使用队列实现的无权图BFS
#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

typedef struct
{
    bool known = false;
    int dist = inf;
    Vertex path = 0;
}AppendexInfo;
AppendexInfo appinfo[MAX];          //储存额外信息
void Unweighted(Graph G);

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

    AddEdge(G, 0, "v1", "v2");
    AddEdge(G, 0, "v1", "v4");
    AddEdge(G, 0, "v2", "v4");
    AddEdge(G, 0, "v2", "v5");
    AddEdge(G, 0, "v3", "v1");
    AddEdge(G, 0, "v3", "v6");
    AddEdge(G, 0, "v4", "v3");
    AddEdge(G, 0, "v4", "v5");
    AddEdge(G, 0, "v4", "v6");
    AddEdge(G, 0, "v4", "v7");
    AddEdge(G, 0, "v5", "v7");
    AddEdge(G, 0, "v7", "v6");

    appinfo[FindVertex(G, "v3")].dist = 0;      //从第一个结点开始搜索
    Unweighted(G);

    for (int i = 0; i < G.volume; i++)
    {
        if (G.adjacentTable[i].existFlag)
        {
            cout << G.adjacentTable[i].elem << " " << appinfo[i].path << endl;
        }
    }
    return 0;
}

void Unweighted(Graph G)
{
    queue<Vertex> q;
    Vertex V;
    EdgeNode temp;

    for (int i = 0; i < G.volume; i++)
        if (appinfo[i].dist == 0 && G.adjacentTable[i].existFlag)
            q.push(i);

    while (!q.empty())
    {
        V = q.front();
        q.pop();

        appinfo[V].known = true;

        temp = G.adjacentTable[V].edgeList;
        while(temp != nullptr)
        {
            if (appinfo[temp->vertex].dist == inf)
            {
                appinfo[temp->vertex].dist = appinfo[temp->vertex].dist + 1;
                appinfo[temp->vertex].path = V;
                q.push(temp->vertex);
            }
            temp = temp->nextPtr;
        }
    }

}