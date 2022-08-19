#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int TopNum[MAX] = {0};          //拓扑序号
void TopSort(Graph G);

int main(void)
{
    Graph G;

    //创建标准的图
    InitializeGraph(G);
    AddVertex(G, "v1");
    AddVertex(G, "v2");
    AddVertex(G, "v3");
    AddVertex(G, "v4");
    AddVertex(G, "v5");
    AddVertex(G, "v6");
    AddVertex(G, "v7");

    AddEdge(G, 0, "v1", "v2");
    AddEdge(G, 0, "v1", "v3");
    AddEdge(G, 0, "v1", "v4");
    AddEdge(G, 0, "v2", "v4");
    AddEdge(G, 0, "v2", "v5");
    AddEdge(G, 0, "v3", "v6");
    AddEdge(G, 0, "v4", "v3");
    AddEdge(G, 0, "v4", "v6");
    AddEdge(G, 0, "v4", "v7");
    AddEdge(G, 0, "v5", "v4");
    AddEdge(G, 0, "v5", "v7");
    AddEdge(G, 0, "v7", "v6");

    TopSort(G);
    cout << endl;
    for (int i = 0; i < G.vertexNum; i++)
        cout << TopNum[i] << " ";
    return 0;
}

void TopSort(Graph G)
{
    queue<Vertex> Q;
    int counter = 0;
    Vertex V;
    EdgeNode temp;
    int Indegree[MAX];

    for (Vertex i = 0; i < G.volume; i++)
    {
        Indegree[i] = GetIndegree(G, i);
        if (!GetIndegree(G, i) && G.adjacentTable[i].existFlag)
            Q.push(i);
    }

    while (!Q.empty())
    {
        V = Q.front();
        Q.pop();

        TopNum[V] = ++counter;
        cout << G.adjacentTable[V].elem << " ";

        temp = G.adjacentTable[V].edgeList;
        while (temp != nullptr)
        {
            Indegree[temp->vertex]--;
            if (Indegree[temp->vertex] == 0)
                Q.push(temp->vertex);
            temp = temp->nextPtr;
        }
    }
    
    if (counter != G.vertexNum)
            cout << "Graph has a cycle!" << endl;
}