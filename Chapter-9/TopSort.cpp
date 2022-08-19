//拓扑排序
#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int TopNum[MAX] = {0};          //拓扑序号
void TopSort(Graph &G);
Vertex FindNewVertexOfIndegreeZero(int Indegree[], int n);

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

void TopSort(Graph &G)
{
    int Indegree[MAX];

    //遍历图，得到所有结点的入度
    for (int i = 0; i < G.volume; i++)
    {
        if (G.adjacentTable[i].existFlag)
            Indegree[i] = GetIndegree(G, i);
        else
            Indegree[i] = -1;
    }

    int Counter;
    Vertex V;
    EdgeNode temp;

    for (Counter = 0; Counter < G.volume; Counter++)
    {
        V = FindNewVertexOfIndegreeZero(Indegree, G.volume);
        if (V == NotAVertex)
        {
            cout << "Graph has a cycle!" << endl;
            break;
        }

        //打印处拓扑排序的结点
        cout << G.adjacentTable[V].elem << " ";
        TopNum[V] = Counter;        //分配拓扑序号
        //所有与其邻接的结点，其入度减一
        temp = G.adjacentTable[V].edgeList;
        while (temp != nullptr)
        {
            Indegree[temp->vertex]--;
            temp = temp->nextPtr;
        }
        Indegree[V]--;          //使该节点的入度减少为-1，使其不会被识别为入度为0的结点
    }
}

Vertex FindNewVertexOfIndegreeZero(int Indegree[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (Indegree[i] == 0)
            return i;
    }

    return NotAVertex;
}

