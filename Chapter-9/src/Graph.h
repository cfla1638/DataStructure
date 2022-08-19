#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_IMCLUDE
#define inf 0x3f3f3f3f
#include <string>
using namespace std;

#define MAX 1000

typedef string ElementType;                //ͼ��ÿһ�������ֵ������
typedef int Vertex;                     //ͼ�Ķ��������
const ElementType defaultVal("0");       //��ʼ��ͼʱ��Ĭ��ֵ
const Vertex NotAVertex = -1;           //�����Ҳ������ı�־Ϊ-1

typedef struct Edge *EdgeNode;
typedef struct Edge
{
    Vertex vertex;     //ָ��ı�
    int weight;     //Ȩ��
    EdgeNode nextPtr;
}Edge;

typedef struct
{
    ElementType elem;
    EdgeNode edgeList;
    bool existFlag;         //ɾ���ı��
}AdjTableNode;      //�ڽӱ�Ľ��

typedef struct
{
    AdjTableNode adjacentTable[MAX];    //�ڽӱ�
    int volume;         //��ʹ�ÿռ�
    int vertexNum;      //�������
}Graph;

void InitializeGraph(Graph &G);                 //��ʼ������ͼͼ
void AddVertex(Graph &G, ElementType elem);     //���Ԫ��
void AddEdgeByIndex(Graph &G, int weight, Vertex u, Vertex v);    //����һ����u��v�ı�
void AddEdge(Graph &G, int weight, ElementType u, ElementType v);
void DeleteNode(Graph &G, Vertex v);
void DeleteEdge(Graph &G, Vertex u, Vertex v);
Vertex FindVertex(const Graph &G, ElementType elem);
int GetIndegree(const Graph &G, Vertex v);


void DebugShowAll(const Graph &G);

#endif