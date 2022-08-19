//��������
#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

int TopNum[MAX] = {0};          //�������
void TopSort(Graph &G);
Vertex FindNewVertexOfIndegreeZero(int Indegree[], int n);

int main(void)
{
    Graph G;

    //������׼��ͼ
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

    //����ͼ���õ����н������
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

        //��ӡ����������Ľ��
        cout << G.adjacentTable[V].elem << " ";
        TopNum[V] = Counter;        //�����������
        //���������ڽӵĽ�㣬����ȼ�һ
        temp = G.adjacentTable[V].edgeList;
        while (temp != nullptr)
        {
            Indegree[temp->vertex]--;
            temp = temp->nextPtr;
        }
        Indegree[V]--;          //ʹ�ýڵ����ȼ���Ϊ-1��ʹ�䲻�ᱻʶ��Ϊ���Ϊ0�Ľ��
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

